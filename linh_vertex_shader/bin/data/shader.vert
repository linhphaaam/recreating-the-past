#version 150

// these are for the programmable pipeline system
uniform mat4 modelViewProjectionMatrix;
in vec4 position;
in vec4 color;
out vec4 colorV;

uniform float mouseRange;
uniform vec2 mousePos;
uniform vec4 mouseColor;
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
    
    vec4 col = color;
    col = vec4(0.2, 0.3, 0.5, 1.0);
    
    
//    vec3 a = vec3(0.5, 0.55, 0.8);
//    vec3 b = vec3(0.3, 0.04, 0.04);
//    vec3 c = vec3(1.0, 1.0, 1.0);
//    vec3 d = vec3(0.80, 0.60, 0.50);
    
    
    // copy position so we can work with it.
    vec4 pos = position;
    
//    col = vec4(vec3(pal(time*0.1+pos.z*0.002,a,b,c,d)), 1.0);
    
    
//    pos.w = 1.1;
    pos.z = 100*noise(vec2(time+pos.y*0.01*pos.x*0.001, pos.x*0.005));
//    col = vec4(vec3(pal(pos.z*0.01,a,b,c,d)), 1.0);
    col.r = pos.z*0.01;
    
    // direction vector from mouse position to vertex position.
	vec2 dir = pos.xy - mousePos;
    
    
    // distance between the mouse position and vertex position.
	float dist =  sqrt(dir.x * dir.x + dir.y * dir.y);
    
    // check vertex is within mouse range.
//	if(dist > 0.0 && dist < mouseRange) {
//
//		// normalise distance between 0 and 1.
//		float distNorm = dist / mouseRange;
//
//		// flip it so the closer we are the greater the repulsion.
//		distNorm = 1.0 - distNorm;
//
//        // make the direction vector magnitude fade out the further it gets from mouse position.
//        dir *= distNorm;
////        col.r += pos.z;
////        col.b += 0.5;
//
//		// add the direction vector to the vertex position.
//		pos.x += dir.x;
//		pos.y += dir.y;
//	}

	// finally set the pos to be that actual position rendered
	gl_Position = modelViewProjectionMatrix * pos;
    colorV = col;
}
