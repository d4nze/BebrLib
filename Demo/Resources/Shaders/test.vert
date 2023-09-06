#version 330 core

layout( location = 0 ) in vec2 a_position;
layout( location = 1 ) in vec4 a_color;
out vec4 r_color;

void main()
{
	gl_Position = vec4(a_position, 0.f, 1.f);
	r_color = a_color;
}
