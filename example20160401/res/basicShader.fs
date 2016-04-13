#version 120

uniform sampler2D diffuse;//variable updated by the GPU; can write from CPU and GPU can read from it

varying vec2 texCoord0;

void main()
{
    gl_FragColor = texture2D(diffuse, texCoord0); 
    //gl_FragColor = exture2D(diffuse, vec2(0.8, 0.5)); //vec4(1.0,0.0,0.0,1.0);
}
