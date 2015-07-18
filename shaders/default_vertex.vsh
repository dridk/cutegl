#version 150
in vec3 position;
in vec3 color;

out vec3 fragColor;
out float z;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main(void)
{
    gl_Position =  projection * view * model * vec4(position.xyz, 1.0);

    fragColor = color;
    z = position.z;
}

