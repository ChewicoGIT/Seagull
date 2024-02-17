#version 460 core
out vec4 FragColor;

layout(location = 10) uniform vec4 Color;


void main()
{
    FragColor = Color;
}