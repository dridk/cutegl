#version 330 core
//in vec3  fragColor;
in vec2 frag_uv;
in vec3 frag_position;
in vec3 frag_normal;

uniform sampler2D fragTexture;
uniform vec3 lightPos;
uniform vec3 lightColor;


out vec4 color;
void main(void)
{
        vec3 ambient = vec3(1,1,1);



        // Compute light direction between light and vertex
        vec3 lightDir = normalize(lightPos - frag_position);

        // normalize normal
        vec3 norm = normalize(frag_normal);

        // compute diffusion
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * lightColor;


        vec3 result = (ambient + diffuse) * vec3(1.0, 0.5, 0.1) ;

        color = vec4(result,1) ;
}
