#include<iostream>
#include"display.h"
#include"shader.h"
#include"mesh.h"
#include"texture.h"
#include"transform.h"
#include"camera.h"

#include<OpenGL/gl.h>
int main(){
    Display display(600,600,"window");
    
    Vertex vertices[] = {// Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0,0.0)),
                           // Vertex(glm::vec3(0.0,0.5,0), glm::vec2(0.5,1.0)),
                           // Vertex(glm::vec3(0.5,-0.5,0), glm::vec2(1.0,0.0)),
                            //Vertex(glm::vec3(-0.90, -0.85,0), glm::vec2(0.0,0.0)),
                            //Vertex(glm::vec3(-0.90,0.90,0), glm::vec2(0.0,0.0)),
                            //Vertex(glm::vec3(0.0,-0.90,0), glm::vec2(0.0,0.0)),
                            Vertex(glm::vec3(-0.9, -0.9, -2.9), glm::vec2(0.0,0.0)),
                            Vertex(glm::vec3(0.0, 0.9, -2.9), glm::vec2(0.5,1.0)),
                            Vertex(glm::vec3(0.9,-0.9, -2.9), glm::vec2(1.0,0.0)),
                            Vertex(glm::vec3(-0.9, 0.9, 0.9), glm::vec2(0.0,0.0)),
                            Vertex(glm::vec3(0.9, 0.9, 0.9), glm::vec2(0.5,1.0)),
                            Vertex(glm::vec3(0.0,-0.9, 0.9), glm::vec2(1.0,0.0))

                        };
    
    unsigned int indices[6] = {3, 4, 5, 0, 1, 2};

    //Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
    Mesh mesh("./res/square1.obj");
    Shader shader("./res/basicShader");
    Texture texture("./res/agnes.jpg");
    Transform transform;
    Camera camera(glm::vec3(0.0,0.0,-5.0), 70.0f, 600/600, 0.01f, 1000.0f);

    float counter = 0.0f;
    while(!display.isClosed()){
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);
        
        float cosC = cosf(counter);
        float sinC = sinf(counter); 
        //transform.get_pos().x =cosC;
        //transform.get_pos().z =cosC;
        transform.get_rot().y = counter;
        //transform.get_rot().z = counter;

        shader.bind();
        texture.bind(0);
        shader.update(transform,camera);
        mesh.draw();
        
        display.update();

        counter+=0.05f;
    }
    return 0;
}
