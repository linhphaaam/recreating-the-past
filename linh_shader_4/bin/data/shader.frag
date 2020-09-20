#define PI 3.14159265359

uniform float time;
uniform vec2 mouse;
uniform vec2 screenSize;

vec3 pal( in float time, in vec3 a, in vec3 b, in vec3 c, in vec3 d )
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

float parabola( float x, float k ){
    return pow( 4.0*x*(1.0-x), k );
}

float expImpulse( float x, float k )
{
    float h = k*x;
    return h*exp(1.0-h);
}

float gain(float x, float k)
{
    float a = 0.5*pow(2.0*((x<0.5)?x:1.0-x), k);
    return (x<0.5)?a:1.0-a;
}

void main()
{

    
    vec2 pos = gl_FragCoord.xy;
    vec2 mouse_adj = mouse.xy / screenSize.xy;
    pos.y = 1218. - pos.y;
    pos.x += 100.*sin(time);
    vec2 pos_adj = pos.xy / screenSize.xy;
    vec2 dis = mouse_adj.xy - pos_adj.xy;
    
    // Scale the coordinate system to see
    // some noise in action
    vec2 pos_2 = vec2(pos_adj*5.);

    // Use the noise function
    float n = noise(dis*4.);
    float n_2 = noise(pos_adj*3.);
    float p = gain(pos_adj.x, pos_adj.x);
//    vec3 a = vec3(n_2);
    vec3 a = vec3(0.73+sin(time)*0.15, 0.69+sin(time)*0.05, 0.95);
//    vec3 d = vec3(n_2);
    vec3 d = vec3(p);
    vec3 b = vec3(0.8, 0.7, .4);
    vec3 c = vec3(0.1, 1.0+sin(time*0.5+PI*0.5)*0.1, 1.0+sin(time*0.5)*0.1);
//    vec3 d = vec3(0.00, 0.10, 0.20);

    
    vec3 color = vec3(0.9,0.,0.);
//    vec3 col = pal( time*0.35+dis.y*pos_adj.x*2., a,b,c,d );
    vec3 col = pal( 1., a,b,c,d );
    color.r = color.r + sin(time*pos_adj.y*pos.y*0.0005 + cos(pos.y*0.5 + 3.04));
//    color.g = color.r + sin(0.5*time + sin(pos.y*0.11 + 1.04));
    color.b = color.b + sin(cos(0.4*time+2.3) + 0.15) + 0.1;
    
    gl_FragColor = vec4(vec3(p,p*2.,p*6.), 1.0);
    

//    gl_FragColor = vec4(vec3(n), 1.0);
    

}
