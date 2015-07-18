#version 150
in vec3  fragColor;
in vec2 fragTexCoord;

uniform sampler2D fragTexture;
uniform bool textureEnabled;

out vec4 color;
void main(void)
{
    if (textureEnabled == true)
    color = texture(fragTexture, fragTexCoord);

    else
        color = vec4(fragColor,1.0);

}

