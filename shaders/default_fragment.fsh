#version 150
in vec3  fragColor;
in vec2 fragTexCoord;
in vec3 fragNormal;
in vec3 fragPos;

uniform sampler2D fragTexture;
uniform bool textureEnabled;


vec3 lightPos   = vec3(1,1,1);
vec3 lightColor = vec3(1,1,1);

float ambientStrength = 0.4f;


out vec4 color;
void main(void)
{

    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(fragNormal);
    vec3 lightDir = normalize(lightPos - fragPos);

    float diff = max(dot(norm, lightDir),0.0);
    vec3 diffuse = diff * lightColor;



    vec3 result = (ambient + diffuse ) * fragColor;

        color = vec4(result ,1.0);


}

