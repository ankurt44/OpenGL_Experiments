#ifndef SHADER_H
#define SHADER_H

#include"transform.h"
#include"camera.h"

#include<string>
#include<OpenGL/gl.h>
class Shader
{
    public:
        Shader(const std::string& filename);
        
        void bind(); //set the GPU in a state so that its using the vertex/frament shader that are part of this particular shader class
        
        void update(const Transform& transform, const Camera& camera);

        virtual ~Shader();
    protected:
    private:
        static const unsigned int NUM_SHADERS = 2;
        Shader(const Shader& other){}
        void operator=(const Shader& other){}
            
        enum
        {
            TRANSFORM_U,

            NUM_UNIFORMS
        };

        GLuint m_program; //keeps track of the handle, where the program is
        GLuint m_shaders[NUM_SHADERS];
        GLuint m_uniforms[NUM_UNIFORMS];
};
//we use GLuint because we are only using these type of shaders
////we also have geometry shaders,,,,then NUM_SHADERS = 3
#endif //SHADER_H
