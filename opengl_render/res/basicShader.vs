#version 120

attribute vec3 position;
attribute vec2 tex_coord;
attribute vec3 normal;

varying vec2 texCoord0;
varying vec3 normal0;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(position,1.0);
    texCoord0 = tex_coord;
    normal0 = (transform * vec4(normal, 0.0)).xyz; //no translation to normal like in position
                                           
}
