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
        display.clear(1.0f, 1.0f, 1.0f, 1.0f);
        
        //shader.bind();
        //mesh.draw();
        display.update();
        rt.init();
        rt.prepare(1.5f);
        rt.render();

    }
    return 0;
}
