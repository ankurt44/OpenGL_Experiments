#include"rotating_triangle.h"

#include<OpenGL/gl.h>

bool RotatingTriangle::init()
{
    return true;
}

void RotatingTriangle::prepare(float dt)
{
    const float SPEED = 15.0f;
    m_rotating_angle+=SPEED*dt;
    if(m_rotating_angle>360.0f)
    {
        m_rotating_angle -= 360.0f;
    }
}

void RotatingTriangle::render()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(m_rotating_angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(-0.5f,-0.5f,-2.0f);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(0.5f,-0.5f,-2.0f);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(0.0f,0.5f,-2.0f);
    glEnd();
}

void RotatingTriangle::shutdown()
{
}

void RotatingTriangle::on_resize(int width, int height){}
