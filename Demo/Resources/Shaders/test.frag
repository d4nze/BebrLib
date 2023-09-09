#version 330 core

in vec4 r_color;
in vec2 r_texCoords;

uniform sampler2D u_texture;

void main()
{
	gl_FragColor = texture( u_texture, r_texCoords ) * r_color;
}
