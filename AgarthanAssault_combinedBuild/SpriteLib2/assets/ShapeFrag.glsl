#version 330

in vData
{
	vec3 color;
} frag;

out vec4 outColor;

void main()
{
	outColor = vec4(frag.color, 1.0);
}