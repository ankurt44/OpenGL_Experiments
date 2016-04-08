#include<iostream>
#include"display.h"
#include"rotating_triangle.h"
#include<OpenGL/gl.h>
int main(){
    Display display(600,600,"window");
    
    //Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5,0)),
    //                        Vertex(glm::vec3(0,0.5,0)),
    //                        Vertex(glm::vec3(0.5,-0.5,0))};
    //Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    
    //std::string loc = "/Users/ank/Documents/learnCpp/cppProgramming/cppLearning/ProgrammingTasks/GraphicsOpenGL/example20160401";
    //Shader shader("./res/basicShader");
    RotatingTriangle rt;
    while(!display.isClosed()){
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);
        
        rt.prepare(1.5f);
        rt.render();

        //shader.bind();
        //mesh.draw();
        display.update();
    }
    return 0;
}
