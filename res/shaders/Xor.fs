#version 330 core
out vec3 fragColor;

// Uniforms
uniform vec2 screenRes;

void main()
{
    float reMap = 512.0 * 64.0;
    ivec2 fragCoord = ivec2(gl_FragCoord.xy / screenRes * reMap);

    float xorred = float(fragCoord.x ^ fragCoord.y);
    fragColor = vec3(xorred / reMap);
}