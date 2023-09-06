#version 330 core

in vec4 r_color;
uniform vec4 u_color;

void main()
{
	gl_FragColor = r_color;
}
