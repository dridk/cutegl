#version 330 core
in vec2  fragTexCoord;
in vec3  fragNormal;

uniform sampler2D fragTexture;

 vec3 lightPos = vec3(0,0,0);

out vec4 color;
void main(void)
{



        color = vec4(1.0, 0.5, 0.1,1.0);
}
