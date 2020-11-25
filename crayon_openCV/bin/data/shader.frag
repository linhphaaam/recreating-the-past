uniform sampler2DRect rockImg;
uniform sampler2DRect lineImg;
uniform float time;
//uniform vec2 mouse;



void main()
{
    
    //usinng the color from one image to figure out where to look at another image, and then pick that color to draw on the screen
    vec2 pos = gl_FragCoord.xy;
    pos.y = 800. - pos.y;
    vec3 color = texture2DRect(rockImg, pos).rgb;
    
    
    float amt = sin(pos.x*0.1 + time*2.) * 30. + 20.0;
    //float amt = sin(pos.x*0.01 + time) * 50. + 50.0;
    
    pos.x += (color.r*2. - 1.0) * 10.; // red value to control how offset in x
    pos.y += (color.b*2. - 1.0) * 10.; // blue value to control how offset in y
    
    vec3 color2 = texture2DRect(lineImg, pos).rgb;
    
    
    gl_FragColor = vec4(color2, 1.0);

}
