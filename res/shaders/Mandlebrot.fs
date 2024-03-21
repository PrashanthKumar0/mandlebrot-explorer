#version 330 core
out vec3 fragColor;

// Uniforms
uniform vec2 uScreenRes;
uniform vec2 uTranslate;
uniform float uZoom;

vec2 square(vec2 num){
    // z = a + bi
    // z^2 = a^2  + 2abi - b^2
    return vec2(num.x * num.x - num.y * num.y , 2 * num.x * num.y);
}

bool isBounded(vec2 vec){
    return vec.x * vec.x + vec.y * vec.y <= 5.0;
}

vec3 getColor(float iter){
    if(iter <= 0.3) return vec3(0.0);
    // if(iter <= 0.3) return vec3(1.0,0.0,0.0);
    if(iter <= 0.6) return vec3(iter,1.0,0.0);
    if(iter <= 0.9) return vec3(1.0,iter,0.0);
    
    return vec3(0.0,0.0,0.0);
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
    while(iter < max_iter && isBounded(z0)){
        z0 = square(z0) + c;
        iter += 1.0;
    }

    fragColor = vec3(getColor(iter / max_iter));
}