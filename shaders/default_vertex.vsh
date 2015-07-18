#version 150
in vec3 position;
in vec3 color;
in vec2 texCoord;

out vec3 fragColor;
out vec2 fragTexCoord;
out float depth;
uniform mat4 all;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;


void main(void)
{
    gl_Position =  all * vec4(position.xyz, 1.0);

    fragColor    = color;
    fragTexCoord = texCoord;

    depth = gl_Position.z * 0.1 ;
}

