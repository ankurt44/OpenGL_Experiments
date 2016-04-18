/*
 *shaders are program for the GPU to do some processing on 3D data
 *read more on OpenGL wiki
 */
#include"shader.h"
#include"transform.h"

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

static string loadShader(const string& filename);
static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMsg);
static GLuint createShader(const string& text, GLenum shadertype);

Shader::Shader(const string& filename)
{
    m_program = glCreateProgram();

    //create Vertec and Fragment shaders; to distinguish use different file extension for shaders
    //cout << loadShader(filename+".vs")<<endl; //just to see the shader code
    m_shaders[0] = createShader(loadShader(filename+".vs"), GL_VERTEX_SHADER);//vertex shader
    m_shaders[1] = createShader(loadShader(filename+".fs"), GL_FRAGMENT_SHADER);//fragment shader

    for(unsigned int i=0; i<NUM_SHADERS; i++)
        glAttachShader(m_program, m_shaders[i]);//attach shaders to shader program

    glBindAttribLocation(m_program, 0, "position"); //what part of the data to read; what exactly 
    glBindAttribLocation(m_program, 1, "tex_coord"); 
    glBindAttribLocation(m_program, 2, "normal"); 
    
    //"program" = from vertex shader

    glLinkProgram(m_program); //link shaders to GPU
    //above linking can fail
    //use checkshader method
    checkShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed ");
    ///validate correctness of program creation
    glValidateProgram(m_program);     
    checkShaderError(m_program, GL_LINK_STATUS, true, "Error: Program is invalid ");

    m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");
}

Shader::~Shader()
{
    //deleting shaders
    for(unsigned int i=0; i<NUM_SHADERS;i++)
    {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }

    //
    glDeleteProgram(m_program); //delete once done, do not want it to stick around GPU 
}

void Shader::bind()
{
    glUseProgram(m_program);
}

void Shader::update(const Transform& transform, const Camera& camera)
{
    glm::mat4 model = camera.get_view_projection() * transform.get_model();

    glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0] );
}

static GLuint createShader(const string& text, GLenum shadertype)
{
    GLuint shader = glCreateShader(shadertype);
    if(shader == 0)
        cerr << "Error: Shader creation failed" << endl;

    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringsLength[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringsLength[0] = text.length();

    //now we can compile our shader
    //when sending source code to opengl
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringsLength); //implementation of this method depends on graphics cards
    glCompileShader(shader);

    checkShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed ");

    return shader;

}

static string loadShader(const string& filename)
{
    ifstream file;
    file.open(filename);//.c_str();

    string output;
    string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
            output.append(line+"\n");
        }
    }else
    {
        cerr << "Unable to load shader "<< filename << endl;
    }

    return output;
}

static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMsg)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };
    
    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
    if(isProgram)
        glGetProgramInfoLog(shader, sizeof(error), NULL, error);
    else
        glGetShaderInfoLog(shader, sizeof(error), NULL, error);

    cerr << errorMsg << ":" << error << endl;
    }
}
