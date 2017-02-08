#version 330 core

layout(points) in;
layout(triangle_strip, max_vertices = 4) out;

uniform vec4 position;
uniform vec4 uvs;
uniform vec3 color;

uniform mat4 modelView;
uniform mat4 projection;

out vData
{
	vec2 texcoord;
	vec3 color;
} frag;

void main()
{
	gl_Position = projection * modelView * vec4(position.z, position.w, 0.0, 1.0);
	frag.texcoord = vec2(uvs.z, uvs.w);
	frag.color = color;
	EmitVertex();

	gl_Position = projection * modelView * vec4(position.x, position.w, 0.0, 1.0);
	frag.texcoord = vec2(uvs.x, uvs.w);
	frag.color = color;
	EmitVertex();

	gl_Position = projection * modelView * vec4(position.z, position.y, 0.0, 1.0);
	frag.texcoord = vec2(uvs.z, uvs.y);
	frag.color = color;
	EmitVertex();

	gl_Position = projection * modelView * vec4(position.x, position.y, 0.0, 1.0);
	frag.texcoord = vec2(uvs.x, uvs.y);
	EmitVertex();
	frag.color = color;

	EndPrimitive();
}