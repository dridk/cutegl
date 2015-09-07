#version 330 core
//in vec3  fragColor;
in vec2 frag_uv;

uniform sampler2D fragTexture;


out vec4 color;
void main(void)
{
    if (textureSize(fragTexture, 0).x > 0)
        color = texture(fragTexture, frag_uv);
    else
        color = vec4(1.0, 1, 1,1.0);
}
