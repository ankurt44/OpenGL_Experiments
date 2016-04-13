#include"mesh.h"
#include<vector>

using namespace std;

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
    m_drawCount = numVertices;

    //create and enable VA object
    glGenVertexArraysAPPLE(1, &m_VAO);//generate vertex array object                                                  
    glBindVertexArrayAPPLE(m_VAO);

    vector<glm::vec3> positions;
    vector<glm::vec2> tex_coords;
    positions.reserve(numVertices);
    tex_coords.reserve(numVertices);

    for(int i=0; i<numVertices;i++)
    {
        positions.push_back(*vertices[i].get_pos());
        tex_coords.push_back(*vertices[i].get_tex_coord());
    }

    //create and enable buffer object
    glGenBuffers(NUM_BUFFERS, m_VABs);
    glBindBuffer(GL_ARRAY_BUFFER, m_VABs[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

    //attacj data to buffers
    glEnableVertexAttribArray(0); //comes from shader: position
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0); //0:one attribute pos, pieces of data:3 and type:FLOAT
    
    glBindBuffer(GL_ARRAY_BUFFER, m_VABs[TEX_COORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(tex_coords[0]), &tex_coords[0], GL_STATIC_DRAW);

    //attach data to buffers
    glEnableVertexAttribArray(1); //comes from shader: texture coordinate
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,0); //0:one attribute pos, pieces of data:3 and type:FLOAT
    
    //unbind until next use of VA object
    glBindVertexArrayAPPLE(0);//after this point no operation will affect vertex array object
}

Mesh::~Mesh()
{
    glDeleteVertexArraysAPPLE(1, &m_VAO);
}

void Mesh::draw()
{
    //bind
    glBindVertexArrayAPPLE(m_VAO);
    
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount); //params: TRIANGLE, start, 

    //unbind until next use
    glBindVertexArrayAPPLE(0);

    glFlush();
}
