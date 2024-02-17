#version 460 core
layout (location = 0) in vec2 aPos;

layout (location = 11) uniform mat4x4 objectMat;
layout (location = 12) uniform mat4x4 cameraMat;

void main()
{
    gl_Position = cameraMat * objectMat * vec4(aPos.x, aPos.y, 0.0, 1.0);
}