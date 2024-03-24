#version 330 core
out vec3 fragColor;
precision highp float;

// Uniforms
uniform highp vec2 uScreenRes;
uniform highp vec2 uTranslate;
uniform highp float uZoom;

vec2 square(vec2 num)
{
    // z = a + bi
    // z^2 = a^2  + 2abi - b^2
    return vec2(num.x * num.x - num.y * num.y , 2 * num.x * num.y);
}

bool isBounded(vec2 vec)
{
    return vec.x * vec.x + vec.y * vec.y <= 5.0;
}

// hsl2rgb took form : https://www.shadertoy.com/view/XljGzV

vec3 hsl2rgb(vec3 c )
{
    vec3 rgb = clamp(abs(mod(c.x*6.0+vec3(0.0,4.0,2.0),6.0)-3.0)-1.0, 0.0, 1.0 );

    return c.z + c.y * (rgb-0.5)*(1.0-abs(2.0*c.z-1.0));
}

vec3 getGradientColor(float iter) {
    return hsl2rgb(vec3(iter * 360.0, 0.4, 0.6));
}

vec3 getColor(float iter, vec2 z)
{
    float norm = length(z);
    vec3 pipes_mask = vec3(log2(sqrt(norm)));
    vec3 color = getGradientColor(iter); 
    return pipes_mask * color;
}

void main()
{
    vec2 gridCoord = ((gl_FragCoord.xy / uScreenRes) - 0.5) * 2.0 * uZoom;
    gridCoord.x -= 0.5;
    gridCoord -= uTranslate;
    
    vec2 z0 = vec2(0.0,0.0);
    vec2 c = gridCoord;
    
    float iter = 0;
    float max_iter = 100;
    while(iter < max_iter && isBounded(z0))
    {
        z0 = square(z0) + c;
        iter += 1.0;
    }

    fragColor = vec3(getColor(iter / max_iter, z0));
}