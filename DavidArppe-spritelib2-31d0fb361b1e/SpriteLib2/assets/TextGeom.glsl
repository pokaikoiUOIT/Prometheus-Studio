#version 330 core

layout(points) in;
layout(triangle_strip, max_vertices = 4) out;

uniform vec4 position;
uniform vec4 uvs;

uniform mat4 modelView;
uniform mat4 projection;

out vData
{
	vec2 texcoord;
} frag;

void main()
{
	gl_Position = projection * modelView * vec4(position.z, position.w, 0.0, 1.0);
	frag.texcoord = vec2(uvs.z, uvs.w);
	EmitVertex();

	gl_Position = projection * modelView * vec4(position.x, position.w, 0.0, 1.0);
	frag.texcoord = vec2(uvs.x, uvs.w);
	EmitVertex();

	gl_Position = projection * modelView * vec4(position.z, position.y, 0.0, 1.0);
	frag.texcoord = vec2(uvs.z, uvs.y);
	EmitVertex();

	gl_Position = projection * modelView * vec4(position.x, position.y, 0.0, 1.0);
	frag.texcoord = vec2(uvs.x, uvs.y);
	EmitVertex();

	EndPrimitive();
}