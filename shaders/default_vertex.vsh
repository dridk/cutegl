#version 150
in vec3 position;
in vec3 color;
in vec2 texCoord;
in vec3 normal;

out vec3 fragColor;
out vec2 fragTexCoord;
out vec3 fragPos;
out vec3 fragNormal;

uniform mat4 all;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;


void main(void)
{
    gl_Position =  all * vec4(position.xyz, 1.0);

    fragPos      = gl_Position.xyz;
    fragColor    = color;
    fragTexCoord = texCoord;
    fragNormal   = normal;

}

