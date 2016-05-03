#ifndef DISPLAY_H
#define DISPLAY_H
#include<SDL.h>
#include<string>
#include<glm/glm.hpp>

#include"camera.h"

class Display{
    public:
        Display(int width, int height, const std::string& title);
        void clear(float r, float g, float b, float a);
        void update(Camera& camera);
        bool isClosed();
        glm::vec3 getCamPos();
        virtual ~Display();
    private:
        Display(const Display& other){}
        void operator=(const Display& other){}
        
        float m_WIDTH, m_HEIGHT;

        SDL_Window* window;
        SDL_GLContext glContext;//openGL context, which will send command to GPU
            //it is used to create window using GPU
        bool m_isClosed;

        glm::vec3 m_cam_pos;
};

#endif
