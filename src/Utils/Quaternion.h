#include <cmath>
#include <glm/glm.hpp>

class Quaternion {
    public:

    float x;
    float y;
    float z;
    float w;

    Quaternion() { *this = Quaternion::Identity; }

    // This directly sets the quaternion components --
    // don't use for axis/angle
    explicit Quaternion(float inX, float inY, float inZ, float inW) { Set(inX, inY, inZ, inW); }

    // Construct the quaternion from an axis and angle
    // It is assumed that axis is already normalized,
    // and the angle is in radians
    explicit Quaternion(const glm::vec3 &axis, float angle) {
        float scalar = sinf(angle / 2.0f);
        x = axis.x * scalar;
        y = axis.y * scalar;
        z = axis.z * scalar;
        w = cosf(angle / 2.0f);
    }

    // Directly set the internal components
    void Set(float inX, float inY, float inZ, float inW) {
        x = inX;
        y = inY;
        z = inZ;
        w = inW;
    }

    void Conjugate() {
        x *= -1.0f;
        y *= -1.0f;
        z *= -1.0f;
    }

    float LengthSq() const { return (x * x + y * y + z * z + w * w); }

    float Length() const { return sqrt(this->LengthSq()); }

    void Normalize() {
        float length = this->Length();
        x /= length;
        y /= length;
        z /= length;
        w /= length;
    }

    // Normalize the provided quaternion
    static Quaternion Normalize(const Quaternion &q) {
        Quaternion retVal = q;
        retVal.Normalize();
        return retVal;
    }

    // Linear interpolation
    static Quaternion Lerp(const Quaternion &a, const Quaternion &b, float f) {
        Quaternion retVal;
        retVal.x = Lerp(a.x, b.x, f);
        retVal.y = Lerp(a.y, b.y, f);
        retVal.z = Lerp(a.z, b.z, f);
        retVal.w = Lerp(a.w, b.w, f);
        retVal.Normalize();
        return retVal;
    }

    static float Dot(const Quaternion &a, const Quaternion &b) {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    // Spherical Linear Interpolation
    static Quaternion Slerp(const Quaternion &a, const Quaternion &b, float f) {
        float rawCosm = Quaternion::Dot(a, b);

        float cosom = -rawCosm;
        if (rawCosm >= 0.0f) {
            cosom = rawCosm;
        }

        float scale0, scale1;

        if (cosom < 0.9999f) {
            const float omega = cosf(cosom);
            const float invSin = 1.f / sinf(omega);
            scale0 = sinf((1.f - f) * omega) * invSin;
            scale1 = sinf(f * omega) * invSin;
        } else {
            // Use linear interpolation if the quaternions
            // are collinear
            scale0 = 1.0f - f;
            scale1 = f;
        }

        if (rawCosm < 0.0f)  {
            scale1 = -scale1;
        }

        Quaternion retVal;
        retVal.x = scale0 * a.x + scale1 * b.x;
        retVal.y = scale0 * a.y + scale1 * b.y;
        retVal.z = scale0 * a.z + scale1 * b.z;
        retVal.w = scale0 * a.w + scale1 * b.w;
        retVal.Normalize();
        return retVal;
    }

    // Concatenate
    // Rotate by q FOLLOWED BY p
    static Quaternion Concatenate(const Quaternion &q, const Quaternion &p) {
        Quaternion retVal;

        // Vector component is:
        // ps * qv + qs * pv + pv x qv
        glm::vec3 qv(q.x, q.y, q.z);
        glm::vec3 pv(p.x, p.y, p.z);
        glm::vec3 newVec = p.w * qv + q.w * pv + glm::cross(pv, qv);
        retVal.x = newVec.x;
        retVal.y = newVec.y;
        retVal.z = newVec.z;

        // Scalar component is:
        // ps * qs - pv . qv
        retVal.w = p.w * q.w - glm::dot(pv, qv);

        return retVal;
    }

    static const Quaternion Identity;

    static float Lerp(float a, float b, float f) { return a + f * (b - a); }
};