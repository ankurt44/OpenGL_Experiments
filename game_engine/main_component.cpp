#include<iostream>

#include"main_component.h"
#include"display.h"

#define WIDTH 800
#define HEIGHT 800
#define TITLE "Game Engine"

MainComponent::MainComponent()
{
    m_is_running = false;   
}
void MainComponent::start()
{
    if(!m_is_running)
        run();
}

void MainComponent::stop()
{
    m_is_running = false;
    cleanUp();
}

void MainComponent::run()
{
    m_is_running = true;
    while(m_is_running)
    {
        if(Display::isClosed())
        {
            stop();
        }
        render();
    }
}

void MainComponent::render()
{
    Display::clear(1.0, 1.0, 1.0, 1.0);
    Display::render();
}

void MainComponent::cleanUp()
{
    Display::destroy();
}

