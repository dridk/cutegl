#version 330 core
layout(triangles) in;
layout(line_strip, max_vertices = 6) out;
in vec3 geom_normal[];
uniform mat4 all;

void main()
{


      vec3 P = gl_in[1].gl_Position.xyz;
      vec3 N = geom_normal[1].xyz;
//       gl_Position = vec4(P,1);
//       EmitVertex();


      gl_Position = gl_in[1].gl_Position;
      EmitVertex();

       gl_Position = all * vec4(N ,1.0);
       EmitVertex();

//       gl_Position = gl_in[2].gl_Position ;
//       EmitVertex();





       EndPrimitive();
}
