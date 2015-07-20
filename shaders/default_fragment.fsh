#version 150
in vec3  fragColor;
in vec2 fragTexCoord;
in float depth;

uniform sampler2D fragTexture;
uniform bool textureEnabled;


out vec4 color;
void main(void)
{

        color = vec4(fragColor,1.0) * (1-depth*0.1);


}

