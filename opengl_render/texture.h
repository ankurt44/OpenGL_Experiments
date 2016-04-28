#ifndef TEXTURE_H
#define TEXTURE_H

#include<OpenGL/gl.h>

#include<string>
using namespace std;

class Texture
{
    public:
        Texture(const string& filename);

        void bind(unsigned int unit); //set opengl up to use whatever texture specified
                                       ///currently we can bind 32 textures at a time
                                       //uint (0-31) parameter determines the texture
        virtual ~Texture();
    protected:
    private:
        Texture(const Texture& other){}
        void operator=(const Texture& other){}

        GLuint m_texture;//handle to refer to object
};

#endif //TEXTURE_H
