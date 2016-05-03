#include<iostream>
#include"display.h"
//#include<OpenGL/glext.h>    //its used to check opengl updates, not using now
#include<OpenGL/gl.h>
using namespace std;

Display::Display(int width, int height, const string& title){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);     //enable depth testing, to check pixel overriding
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    glContext = SDL_GL_CreateContext(window);

    m_WIDTH = width;
    m_HEIGHT = height;
    m_isClosed =false;

    cout << "camera is again set here in display constructor" << endl;
    m_cam_pos = glm::vec3(0.0, 0.0, -4);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnable(GL_DEPTH_TEST); //clear depth buffer in function glClearColor and using flag GL_DEPTH_BUFFER_BIT
                             //using BSP (binary space partition is another method for hidden pixel removal - more efficient than checking pixels from back to front)   
                            //BSP is not used in this example

                             //as long as the object is convex, 
    //this is an easy fix for hidden surface removal
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

Display::~Display(){
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Display::clear(float r, float g, float b, float a){
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

bool Display::isClosed(){
    return m_isClosed;
}

void Display::update(Camera& camera){
    SDL_GL_SwapWindow(window);
    //OS event
    SDL_Event e;
    
    m_cam_pos = camera.get_pos();
    
    while(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT)
            m_isClosed = true;
        if(e.type==SDL_KEYDOWN)
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_LEFT:
                    m_cam_pos = m_cam_pos+glm::vec3(0.05,0.0,0.0); 
                    break;
                case SDLK_RIGHT:
                    m_cam_pos = m_cam_pos-glm::vec3(0.05,0.0,0.0); 
                    break;
                case SDLK_UP:
                    m_cam_pos = m_cam_pos+glm::vec3(0.0,0.05,0.0); 
                    break;
                case SDLK_DOWN:
                    m_cam_pos = m_cam_pos-glm::vec3(0.0,0.05,0.0); 
                    break;
            }
        }
        if(e.type == SDL_MOUSEMOTION)
        {
            float x = ((float)e.motion.x-(float)400)/(float)400;
            float y = ((float)e.motion.y-(float)400)/(float)400;
            
            camera.set_forward(glm::vec3(-x,-y,1.0));
        }
    }
   camera.set_pos(m_cam_pos);
}

glm::vec3 Display::getCamPos()
{
    return m_cam_pos;
}
