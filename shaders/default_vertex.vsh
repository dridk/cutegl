#version 330 core
in vec3 posCoord;
in vec3 color;
in vec2 texCoord;
in vec3 normal;

out vec2 fragTexCoord;

uniform mat4 all;

void main(void)
{
    gl_Position =  all * vec4(posCoord.xyz, 1.0);
    fragTexCoord = vec2(texCoord.x, texCoord.y);
}
