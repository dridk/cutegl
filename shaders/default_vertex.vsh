#version 150
in vec3 position;
uniform mat4 projection;
void main(void)
{
    gl_Position = projection * vec4(position.xyz, 1.0);
}

