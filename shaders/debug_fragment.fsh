#version 330 core
//in vec3  fragColor;
in vec2 frag_uv;

uniform sampler2D fragTexture;

in vec3 frag_color;

out vec4 color;
void main(void)
{


        color = vec4(frag_color,1);
}
