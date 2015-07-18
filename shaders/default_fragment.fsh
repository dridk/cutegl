#version 150
in vec3 fragColor;
in float z;
out vec4 color;
void main(void)
{
    color = vec4(fragColor, 1.0);
}

