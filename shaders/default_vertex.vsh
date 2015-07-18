#version 150
in vec3 position;
in vec3 color;

out vec3 fragColor;

uniform mat4 modelview;
uniform mat4 projection;

void main(void)
{
    gl_Position =   modelview * projection * vec4(position.xyz, 1.0);
    fragColor = color;
}

