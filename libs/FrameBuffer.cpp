#include "FrameBuffer.h"

FrameBuffer::FrameBuffer() : m_width(1024),
                             m_height(1024) 
{
    glGenFramebuffers(1, &this->m_FBO);

    // create depth texture
    glGenTextures(1, &this->m_depth);
    glBindTexture(GL_TEXTURE_2D, this->m_depth);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, this->m_width, this->m_height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float borderColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

    glBindFramebuffer(GL_FRAMEBUFFER, this->m_FBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, this->m_depth, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

FrameBuffer::~FrameBuffer() { 
    if (this->m_FBO != 0)
        glDeleteFramebuffers(1, &this->m_FBO);

    if (this->m_depth != 0)
        glDeleteTextures(1, &this->m_depth);
}

void FrameBuffer::BindFrame(GLFWwindow *window) {
    glfwGetFramebufferSize(window, &this->m_sizeX, &this->m_sizeY);
    glViewport(0, 0, this->m_width, this->m_height);
    glBindFramebuffer(GL_FRAMEBUFFER, this->m_FBO);
    glClear(GL_DEPTH_BUFFER_BIT);
}

void FrameBuffer::UnbindFrame() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, this->m_sizeX, this->m_sizeY);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void FrameBuffer::BindTex(GLuint slot) {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, this->m_depth);
}

void FrameBuffer::UnbindTex() { glBindTexture(GL_TEXTURE_2D, 0); }