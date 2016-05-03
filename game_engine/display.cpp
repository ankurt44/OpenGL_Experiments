#include<iostream>

#include<SDL.h>
#include<OpenGL/gl.h>

#include"display.h"

bool Display::m_is_closed = false;
SDL_Window* Display::m_window = NULL;
SDL_GLContext Display::m_glContext = NULL;

void Display::createDisplay(int width, int height, std::string title)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    m_window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glContext = SDL_GL_CreateContext(m_window);
    
    m_is_closed =false;
    
}

void Display::clear(float r, float g, float b, float a){
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::isClosed(){
    return m_is_closed;
}

void Display::render(){
    SDL_GL_SwapWindow(m_window);
    //OS event
    SDL_Event e;
    
    while(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT)
            m_is_closed = true;
        if(e.type==SDL_KEYDOWN)
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_LEFT:
                    break;
                case SDLK_RIGHT:
                    break;
                case SDLK_UP:
                    break;
                case SDLK_DOWN:
                    break;
            }
        }
        if(e.type == SDL_MOUSEMOTION)
        {
        }
    }
}

void Display::destroy()
{
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

int Display::getWidth()
{
    int w, h;
    SDL_GetWindowSize(m_window, &w, &h);
    return w;
}

int Display::getHeight()
{
    int w, h;
    SDL_GetWindowSize(m_window, &w, &h);
    return h;
}
