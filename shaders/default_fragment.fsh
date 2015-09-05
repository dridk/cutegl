#version 330 core
//in vec3  fragColor;
in vec2  fragTexCoord;

uniform sampler2D fragTexture;
uniform bool textureEnabled;

out vec4 color;
void main(void)
{

        color = vec4(1.0, 1.0, 1.0,1.0);
}
