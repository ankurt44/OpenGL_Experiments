#include<iostream>

#include"main_component.h"
#include"display.h"

#define WIDTH 800
#define HEIGHT 600
#define TITLE "Game Engine"

int main()
{
    std::cout << "initialising game in main!";
    
    Display::createDisplay(WIDTH, HEIGHT, TITLE);

    MainComponent* game = new MainComponent();

    game->start();
}
