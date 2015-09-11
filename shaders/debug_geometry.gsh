#version 330 core
layout(triangles) in;
layout(line_strip, max_vertices = 12) out;
in vec3 geom_normal[];
uniform mat4 all;

out vec3 frag_color;

void main()
{

frag_color = vec3(0.4,0.4,0.4);
    for (int i=0; i<gl_in.length(); i++)
    {
     gl_Position = gl_in[i].gl_Position;
     EmitVertex();
    }
    EndPrimitive();


    frag_color = vec3(0.5,1,1);

     gl_Position = gl_in[0].gl_Position;
     EmitVertex();
     gl_Position = gl_in[0].gl_Position - vec4(geom_normal[0].xyz, 1) *2 ;
     EmitVertex();
     EndPrimitive();

     gl_Position = gl_in[1].gl_Position;
     EmitVertex();
     gl_Position = gl_in[1].gl_Position - vec4(geom_normal[1].xyz, 1) * 2;;
     EmitVertex();
     EndPrimitive();


     gl_Position = gl_in[2].gl_Position;
     EmitVertex();
     gl_Position = gl_in[2].gl_Position - vec4(geom_normal[2].xyz, 1) * 2;;
     EmitVertex();
     EndPrimitive();
}
