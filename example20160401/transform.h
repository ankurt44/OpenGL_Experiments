#ifndef TRANSFORM_H
#define TRANSFORM_H

#include<glm/glm.hpp> //gl mathematics library
#include<glm/gtx/transform.hpp>
//interface for  moving, transforming any object
class Transform
{
    public:     //position, rotation, scaling
        Transform(const glm::vec3& pos = glm::vec3(), 
                    const glm::vec3& rot = glm::vec3(), 
                    const glm::vec3& scale = glm::vec3( 1.0, 1.0, 1.0)): 
                    m_pos(pos), m_rot(rot), m_scale(scale){}
        
        //matrix containg transformation (pos, rot, scale) : model matrix
        //somtimes called world matrix
        inline glm::mat4 get_model() const
        {
            glm::mat4 pos_mat = glm::translate(m_pos);
            glm::mat4 rot_X_mat = glm::rotate(m_rot.x, glm::vec3(1.0, 0.0, 0.0));
            glm::mat4 rot_Y_mat = glm::rotate(m_rot.y, glm::vec3(0.0, 1.0, 0.0));
            glm::mat4 rot_Z_mat = glm::rotate(m_rot.z, glm::vec3(0.0, 0.0, 1.0));
            glm::mat4 scale_mat = glm::scale(m_scale);

            //to combine - multiply and order of multiplication matter
            glm::mat4 rot_mat = rot_X_mat * rot_Y_mat * rot_Z_mat;

            return pos_mat * rot_mat * scale_mat;
        }


        inline glm::vec3& get_pos(){return m_pos;}
        inline glm::vec3& get_rot(){return m_rot;}
        inline glm::vec3& get_scale(){return m_scale;}

        inline void set_pos(const glm::vec3& pos){m_pos = pos;}
        inline void set_rot(const glm::vec3& rot){m_rot = rot;}
        inline void set_scale(const glm::vec3& scale){m_scale = scale;}

    protected:
    private:

        glm::vec3 m_pos;
        glm::vec3 m_rot;
        glm::vec3 m_scale;
};

#endif //TRANSFORM_H
