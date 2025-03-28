#type vertex
#version 330 core

layout (location=0) in vec3 aPosition;

out vec4 fColor;

void main()
{
    gl_Position = vec4(aPosition, 1.0);
    fColor = vec4(aPosition.x + 0.5, 1.0, aPosition.y + 0.5, 1.0);
}

#type fragment
#version 330 core

in vec4 fColor;

out vec4 oColor;

void main()
{
    oColor = fColor;
}
