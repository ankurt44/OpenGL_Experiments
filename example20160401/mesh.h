#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include<OpenGL/gl.h>
#include<string>

#include"obj_loader.h"

class Vertex
{
    //x, y, z coordinates [-1,1]
    public:
        Vertex(const glm::vec3& pos, const glm::vec2& tex_coord)
        {
            this->pos = pos;
            this->tex_coord = tex_coord;
        }
        inline glm::vec3* get_pos(){return &pos;}
        inline glm::vec2* get_tex_coord(){return &tex_coord;}
    protected:
    private:
        //vertex attributes: position, color etc
        glm::vec3 pos;
        glm::vec2 tex_coord;
};

class Mesh
{
    public:
        Mesh(const std::string& filename);
        Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int num_indices);
        void draw();
        virtual ~Mesh();
    protected:
    private:
        Mesh(const Mesh& other){}
        void operator=(const Mesh& other){}

        void init_mesh(const IndexedModel& model);

        enum
        {
            POSITION_VB,
            TEX_COORD_VB,

            INDEX_VB, //indexed vertex buffer

            NUM_BUFFERS
        };

        GLuint m_VAO;
        GLuint m_VABs[NUM_BUFFERS];
        unsigned int m_drawCount;
};

#endif //MESH_H
