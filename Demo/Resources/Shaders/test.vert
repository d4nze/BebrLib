#version 330 core

layout( location = 0 ) in vec2 a_position;
layout( location = 1 ) in vec4 a_color;
layout( location = 2 ) in vec2 a_texCoords;

out vec4 r_color;
out vec2 r_texCoords;

uniform mat4 u_camera;
uniform mat4 u_model; // transform * origin

void main()
{
	gl_Position = u_camera * u_model * vec4(a_position, 0.f, 1.f);
	r_color = a_color;
	r_texCoords = a_texCoords;
}
