#include"mesh.h"
#include<vector>
#include<string>
#include<iostream>
#include"obj_loader.h"

using namespace std;

Mesh::Mesh(const string& filename)
{
    IndexedModel model = OBJModel(filename).ToIndexedModel();
    init_mesh(model);
}

Mesh::Mesh(Vertex* vertices, unsigned int num_vertices, unsigned int* indices, unsigned int num_indices)
{
//    vector<glm::vec3> positions;
//    vector<glm::vec2> tex_coords;
//    positions.reserve(num_vertices);
//    tex_coords.reserve(num_vertices);

    IndexedModel model;

    for(int i=0; i<num_vertices;i++)
    {
        model.positions.push_back(*vertices[i].get_pos());
        model.tex_coords.push_back(*vertices[i].get_tex_coord());
    }

    for(int i=0; i<num_indices; i++)
        model.indices.push_back(indices[i]);

    //create indexed model and init mesh with that

    init_mesh(model);
}

Mesh::~Mesh()
{
    glDeleteVertexArraysAPPLE(1, &m_VAO);
}

void Mesh::init_mesh(const IndexedModel& model)
{
    //m_drawCount = num_vertices;
    m_drawCount = model.indices.size();

    //create and enable VA object
    glGenVertexArraysAPPLE(1, &m_VAO);//generate vertex array object                                                  
    glBindVertexArrayAPPLE(m_VAO);
    
    //create and enable buffer object
    glGenBuffers(NUM_BUFFERS, m_VABs);

    glBindBuffer(GL_ARRAY_BUFFER, m_VABs[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size()*sizeof(model.positions[0]), &(model.positions[0]), GL_STATIC_DRAW);
    //attacj data to buffers
    glEnableVertexAttribArray(0); //comes from shader: position
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0); //0:one attribute pos, pieces of data:3 and type:FLOAT
    
    glBindBuffer(GL_ARRAY_BUFFER, m_VABs[TEX_COORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.tex_coords.size()*sizeof(model.tex_coords[0]), &(model.tex_coords[0]), GL_STATIC_DRAW);
    //attach tex_coord data to buffers
    glEnableVertexAttribArray(1); //comes from shader: texture coordinate
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,0); //0:one attribute pos, pieces of data:3 and type:FLOAT
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_VABs[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size()*sizeof(model.indices[0]), &(model.indices[0]), GL_STATIC_DRAW);
    //unbind until next use of VA object
    glBindVertexArrayAPPLE(0);//after this point no operation will affect vertex array object

}

void Mesh::draw()
{
    //bind
    glBindVertexArrayAPPLE(m_VAO);
    
    //glDrawArrays(GL_TRIANGLES, 0, m_drawCount); //params: TRIANGLE, start, 
    glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);

    //unbind until next use
    glBindVertexArrayAPPLE(0);

//    glFlush();
}
