#include<string>
#include<cassert>
#include<iostream>


#include"texture.h"
#include"stb_image.h"


using namespace std;

Texture::Texture(const string& filename)
{

    int width, height, numComponents; //returned from  stbi_load function
    //load texture data
    unsigned char* img_data = stbi_load(filename.c_str(), &width, &height, &numComponents,4); 
    
    if(img_data == NULL)
    {
        cerr << "Texture loading failed " << filename << endl;
    }

    //generate some space for texture : use buffer
    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture); //there are other textures : 3D and volume textures
    
    //wrap texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //handling interpolating when texture has different size : GL_LINEAR - linear interpolation
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //texture has less number of pixels
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //more pixels

    //send texture to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img_data);

    //delete texture data
    stbi_image_free(img_data);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_texture);
}

void Texture::bind(unsigned int unit)
{
    assert(unit>=0 && unit<=31);

    glActiveTexture(GL_TEXTURE0 + unit); //which texture to use: 0-31
    glBindTexture(GL_TEXTURE_2D, m_texture);

}
