#version 330 core
//in vec3  fragColor;
in vec2 frag_uv;
in vec3 frag_position;
in vec3 frag_normal;

uniform sampler2D fragTexture;
uniform float opacity;


struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;
    vec3 ambient;
};

uniform Material material;
uniform Light light;
uniform bool has_texture;

out vec4 color;
void main(void)
{

    //============Compute Ambient============
    vec3 ambient = material.ambient * light.ambient ;
    //============Compute Diffuse============
    // normalize normal
    vec3 norm = normalize(frag_normal);
    // Compute light direction between light and vertex
    vec3 lightDir = normalize(light.position - frag_position);
    // compute diffusion
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * light.ambient;



    vec3 result = (ambient + diffuse) ;

    if (has_texture)
     color = vec4(result,opacity) *  texture(fragTexture, frag_uv);
    else
     color = vec4(result,opacity);
}
