#version 150

// these are for the programmable pipeline system
uniform mat4 modelViewProjectionMatrix;
in vec4 position;
in vec4 color;

out vec4 colorV;

uniform float time;
uniform vec2 screenSize;

vec3 pal (in float time, in vec3 a, in vec3 b, in vec3 c, in vec3 d )
{
    return a + b * cos( 6.28318*(c*time+d) );
}


float random (in vec2 st){
    return fract(sin(dot(st.xy ,vec2(12.9898,78.233))) * 43758.5453123);
}

float noise (in vec2 st) {
    vec2 i = floor(st);
    vec2 f = fract(st);
//
    // Four corners in 2D of a tile
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));
//
//    // Smooth Interpolation
//
//    // Cubic Hermine Curve.  Same as SmoothStep()
    vec2 u = f*f*(3.0-2.0*f);
//    // u = smoothstep(0.,1.,f);
//
    // Mix 4 coorners percentages
    return mix(a, b, u.x) +
            (c - a)* u.y * (1.0 - u.x) +
            (d - b) * u.x * u.y;
}

void main()
{
    
    vec4 pos = position;
    vec4 col = color;
    
    vec3 a = vec3(0.7, 0.65, 0.8);
    vec3 b = vec3(0.3, 0.2, 0.4);
    vec3 c = vec3(0.8, 0.7, 0.1);
    vec3 d = vec3(0.15, 0.15, 0.10);
    
    float angle = atan(pos.x/pos.y);
    
    
//    pos.x = pos.x + 50*sin(time*0.5+pos.x*0.01);
//    pos.z = 400*noise(pos.xy*0.003);
//    pos.x = pos.x + 80*sin(time*0.5 + pos.x*0.001);
//    pos.y = pos.y + 50*cos(time*0.5+pos.y*0.3);
//    pos.z = -250*sin(time*0.5 + pos.y*0.002) * noise(vec2(time*0.4, (pos.x - pos.y)*0.005));
    pos.z = -120*sin(time*0.4 + pos.x*0.011 + pos.y*0.009) * noise( pos.xy*0.005);
    pos.x = pos.x + 40*cos(time*0.4 + pos.x*0.01 * cos(time*0.1 +pos.y*0.001));
//    pos.y = pos.y + 50*cos(time*0.5+pos.x*0.008*pos.y*0.003);
//    pos.x = pos.x + 50*sin(time*0.8+pos.z*0.02*pos.y*0.003*pos.x*0.003);

    col = col + 0.8*vec4(pal(pos.z*0.003, a, b, c, d), 1.0);

	gl_Position = modelViewProjectionMatrix * pos;
    colorV = col;
}
