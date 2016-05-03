#ifndef DISPLAY_H
#define DISPLAY_H

#include<iostream>

#include<SDL.h>
#include<OpenGL/gl.h>

class Display
{
public:
    Display(int width, int height, std::string title);
    virtual ~Display();
    static void createDisplay(int, int, std::string);
    static void clear(float, float, float, float);
    static void render();
    static void destroy();
    static bool isClosed();
    static int getWidth();
    static int getHeight();
protected:
private:
    static bool m_is_closed;
    static SDL_Window* m_window;
    static SDL_GLContext m_glContext;
};

#endif
