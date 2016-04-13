#include<iostream>
#include"display.h"
#include"shader.h"
#include"mesh.h"
#include"texture.h"
#include<OpenGL/gl.h>
int main(){
    Display display(600,600,"window");
    
    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0,0.0)),
                            Vertex(glm::vec3(0.0,0.5,0), glm::vec2(0.5,1.0)),
                            Vertex(glm::vec3(0.5,-0.5,0), glm::vec2(1.0,0.0))
                        };
                                /*,
                            Vertex(glm::vec3(0.90, -0.85,0), glm::vec2(0.0,0.0)),
                            Vertex(glm::vec3(0.90,0.90,0), glm::vec2(0.0,0.0)),
                            Vertex(glm::vec3(-0.85,0.90,0), glm::vec2(0.0,0.0))
                        };*/
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    std::string loc = "/Users/ank/Documents/learnCpp/cppProgramming/cppLearning/ProgrammingTasks/GraphicsOpenGL/example20160401";
    Shader shader("./res/basicShader");
    Texture texture("./res/agnes.jpg");
    while(!display.isClosed()){
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);

        shader.bind();
        texture.bind(0);
        mesh.draw();
        
        display.update();
    }
    return 0;
}
