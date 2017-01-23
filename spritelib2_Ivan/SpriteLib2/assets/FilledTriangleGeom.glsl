#version 330 core

layout(points) in;
layout(triangle_strip, max_vertices = 3) out;

uniform mat4 modelView;
uniform mat4 projection;

uniform vec3 posA;
uniform vec3 posB;
uniform vec3 posC;

uniform vec3 color;

out vData
{
	vec3 color;
} frag;

void main()
{
	gl_Position = projection * modelView * vec4(posA.x, posA.y, 0.0, 1.0);
	frag.color = color;
	EmitVertex();

	gl_Position = projection * modelView * vec4(posB.x, posB.y, 0.0, 1.0);
	frag.color = color;
	EmitVertex();

	gl_Position = projection * modelView * vec4(posC.x, posC.y, 0.0, 1.0);
	frag.color = color;
	EmitVertex();

	EndPrimitive();
}