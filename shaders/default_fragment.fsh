#version 150
in vec3  fragColor;
in vec2 fragTexCoord;
in float depth;

uniform sampler2D fragTexture;
uniform bool textureEnabled;


out vec4 color;
void main(void)
{
    if (textureEnabled == true)
        color = texture(fragTexture, fragTexCoord) *(0.8-depth);

    else
        color = vec4(fragColor,1.0);


}

