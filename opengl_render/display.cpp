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

    m_isClosed =false;
    
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

void Display::update(){
    /*
     *the attribute sets double window
     *SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
     *double buffering create two entire blocks of memory
     *we can use window display for one block, and opengl uses other block
     *
     * window displays nothing, while openGL draws things
     * then we need to swap display. OpenGL draw new things in its own block, and we swap to windows block
     * windows only shows whats drawn fully by openGL
     */
    SDL_GL_SwapWindow(window);
    //OS event
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT)
            m_isClosed = true;
    }

}
