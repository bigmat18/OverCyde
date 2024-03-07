#version 330 core  

#define NR_POINT_LIGHTS 2

struct Material {
    samplerCube diffuse;
    samplerCube specular;
    float shininess;
}; 

struct PointLight {    
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;  

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct DirLight {
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  

out vec4 FragColor; 

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpaces[NR_POINT_LIGHTS];
} fs_in;

uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform DirLight dirLight;
uniform Material material;
uniform vec3 viewPos;
uniform sampler2D shadowMap1;
uniform sampler2D shadowMap2;

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
float ShadowCalculation(vec4 fragPosLightSpace, int index, sampler2D shadowMap);

void main(void) { 
    // properties
    vec3 norm = normalize(fs_in.Normal);
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);

    vec3 result = vec3(0);

    // phase 1: Directional lighting
    result += CalcDirLight(dirLight, norm, viewDir);

    // phase 2: Point lights
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcPointLight(pointLights[i], norm, fs_in.FragPos, viewDir);

    FragColor = vec4(result, 1.0);
} 

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir) {
    vec3 lightDir = normalize(-light.direction);

    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);

    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

    // combine results
    vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, fs_in.TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, fs_in.TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, fs_in.TexCoords));

    return (ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir) {
    // blinn - phong
    vec3 lightDir   = normalize(light.position - fragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);

    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);

    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

    // attenuation
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
  			                   light.quadratic * (distance * distance));

    // combine results
    vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, fs_in.TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, fs_in.TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, fs_in.TexCoords));

    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    
    float shadow = ShadowCalculation(fs_in.FragPosLightSpaces[0], 0, shadowMap1);
    shadow += ShadowCalculation(fs_in.FragPosLightSpaces[1], 1, shadowMap2);
    // for(int i = 1; i < NR_POINT_LIGHTS; i++)
    //     shadow +=  ShadowCalculation(fs_in.FragPosLightSpaces[i], i); 

    vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular));
    return lighting;
}

float ShadowCalculation(vec4 fragPosLightSpace, int index, sampler2D shadowMap) {
    // perform perspective divide
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;

    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;

    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap, projCoords.xy).r; 

    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;

    // calculate bias (based on depth map resolution and slope)
    vec3 normal = normalize(fs_in.Normal);
    vec3 lightDir = normalize(pointLights[index].position - fs_in.FragPos);
    float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);

    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for(int x = -1; x <= 1; ++x) {
        for(int y = -1; y <= 1; ++y) {
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;        
        }    
    }
    shadow /= 9.0;
    if(projCoords.z > 1.0) shadow = 0.0;
    
    return shadow;
}