#version 120

uniform sampler2D diffuse;//variable updated by the GPU; can write from CPU and GPU can read from it

varying vec2 texCoord0;
varying vec3 normal0;
void main()
{
    gl_FragColor = texture2D(diffuse, texCoord0)
                    * clamp(dot(-vec3(0,0,1), normal0), 0.0, 1.0) ;  //brightness can be 0.0-1.0
                                                                        //clamp: to get proper brightness value 
                                                                        //vec3(0,0,1) is the light direction, (hardcoded); can be uniform to get values from opengl
    //gl_FragColor = exture2D(diffuse, vec2(0.8, 0.5)); //vec4(1.0,0.0,0.0,1.0);
}
