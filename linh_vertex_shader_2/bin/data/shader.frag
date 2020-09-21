#version 150

out vec4 outputColor;

uniform vec4 mouseColor;
in vec4 colorV;
 

float random (in vec2 st){
    return fract(sin(dot(st.xy ,vec2(12.9898,78.233))) * 43758.5453123);
}


void main()
{
    vec4 col = colorV;
    outputColor = col;
}
