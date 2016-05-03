#include"display.h"
#include"shader.h"
#include"mesh.h"
#include"texture.h"
#include"transform.h"
#include"camera.h"

#include<iostream>
#include<OpenGL/gl.h>

#define WIDTH 800
#define HEIGHT 800

int main(){
    Display display(WIDTH,HEIGHT,"window");
    
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
    Shader shader("./res/basicShader");
    Texture texture("./res/bricks.jpg");
    Mesh mesh("./res/monkey3.obj");
    Transform transform;
    Mesh mesh1("./res/monkey3.obj");
    Transform transform1;
    transform1.set_pos(glm::vec3(10.0, 0.0, 0.0));
    Camera camera(glm::vec3(0.0,0.0,-10), 70.0f, WIDTH/HEIGHT, 0.01f, 1000.0f);

    //Mesh mesh1("./res/monkey3.obj");
    //Transform transform1;
    
    float counter = 0.0f;
    while(!display.isClosed()){
        display.clear(1.0f, 1.0f, 1.0f, 0.0f);

        float cosC = cosf(counter);
        float sinC = sinf(counter); 
        
        //camera.set_pos(glm::vec3(0.0,0.0,sinC*5-10));
        //camera.set_pos(display.getCamPos());
        //transform.get_pos().x =cosC;
        //transform.get_pos().z =cosC;
        //transform.get_pos().x = +0.7;
        //transform.get_rot().y = counter;
        //transform.get_rot().z = counter;
        //transform1.get_pos().x = -0.7;
        transform.get_rot().y = counter/5;
        transform.get_rot().z = counter/5;

        shader.bind();
        texture.bind(0);
        shader.update(transform,camera);
        mesh.draw();
        
        shader.update(transform1,camera);
        mesh1.draw();
        //shader.update(transform1,camera);
        //mesh1.draw();
        
        display.update(camera);

        counter+=0.05f;
    }
    return 0;
}
