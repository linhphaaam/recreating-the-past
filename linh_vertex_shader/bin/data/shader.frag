#version 150

out vec4 outputColor;

uniform vec4 mouseColor;
in vec4 colorV;
 
void main()
{
    outputColor = colorV;
}
