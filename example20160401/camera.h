#ifndef CAMERA_H
#define CAMERA_H

#include<glm/glm.hpp>
#include<glm/gtx/transform.hpp>

class Camera
{
    public:
        //camera initializing
        Camera(const glm::vec3 pos, float fov, float aspect, float znear, float zfar) 
            //fov-field of view; zfar - what we can/cannot see
        {
            m_perspective = glm::perspective(fov, aspect, znear, zfar);
            m_position = pos;
            m_forward = glm::vec3(0, 0, 1); //z is forward
            m_up = glm::vec3(0, 1, 0);    //y is up
        }

        //similar to get_model in transform.h
        inline glm::mat4 get_view_projection() const
        {
            return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
        }
    protected:
    private:
        glm::mat4 m_perspective;
        glm::vec3 m_position; //camera position
        glm::vec3 m_forward; //camera forward direction
        glm::vec3 m_up;      //camera up direction
};


#endif //CAMERA_H
