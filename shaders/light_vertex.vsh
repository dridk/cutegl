#version 330 core
in vec3 position;
in vec3 color;
in vec2 uv;
in vec3 normal;

out vec2 frag_uv;
out vec3 frag_position;
out vec3 frag_normal;

uniform mat4 all;

void main(void)
{
    gl_Position   =  all * vec4(position.xyz, 1.0);
    frag_uv       = uv;
    frag_position = position;
    frag_normal   = normal;

}
