#version 330

layout(location = 0) in vec3 positions;
layout(location = 1) in vec2 uvs;
uniform vec2 uvPos;
uniform vec2 uvScale;
uniform mat4 modelView;
uniform mat4 projection;

out vData
{
	vec2 texcoord;
	vec3 color;
} frag;

void main()
{
	frag.texcoord = uvs * uvScale + uvPos;
	frag.color = vec3(1.0, 1.0, 1.0);
	gl_Position = projection *
		modelView * vec4(positions, 1.0);
}