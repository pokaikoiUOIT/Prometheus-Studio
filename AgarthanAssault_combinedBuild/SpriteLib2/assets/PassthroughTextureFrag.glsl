#version 330

in vData
{
	vec2 texcoord;
	vec3 color;
} frag;

uniform sampler2D mainTexture;

out vec4 outColor;

void main()
{
	outColor = texture(mainTexture, frag.texcoord) * vec4(frag.color, 1.0);
}