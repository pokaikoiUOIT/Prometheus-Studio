#version 330 core

layout(points) in;
layout(triangle_strip, max_vertices = 32) out;

#define PI 3.1415926535897932384626433832795
#define SUBDIVISIONS 16.0

uniform mat4 modelView;
uniform mat4 projection;

uniform vec3 color;

out vData			
{					
	vec3 color;
} frag;			

void main() 
{
	float step = PI / SUBDIVISIONS;
	float x, y;

	gl_Position = projection * modelView * vec4(1.0, 0.0, 0.0, 1.0);
	frag.color = color;
	EmitVertex();

	for (float i = step; i < PI; i += step)
	{
		// Do a triangle-strip, because geometry shaders can't do triangle-fan (which would be easy)
		// GPU's can only handle triangle_strip after primitive assembly
		x = cos(i);
		y = sin(i);

		gl_Position = projection * modelView * vec4(x, y, 0.0, 1.0 );
		frag.color = color;
		EmitVertex();

		x = cos(-i);
		y = sin(-i);

		gl_Position = projection * modelView * vec4(x, y, 0.0, 1.0);
		frag.color = color;
		EmitVertex();
	}

	gl_Position = projection * modelView * vec4(-1.0, 0.0, 0.0, 1.0);
	frag.color = color;
	EmitVertex();

    EndPrimitive(); 
}