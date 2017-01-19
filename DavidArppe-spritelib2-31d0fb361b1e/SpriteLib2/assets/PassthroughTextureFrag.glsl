#version 330

in vData
{
	vec2 texcoord;
} frag;

uniform sampler2D mainTexture;

out vec4 outColor;

void main()
{
	outColor = texture(mainTexture, frag.texcoord);
}