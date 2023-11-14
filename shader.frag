#version 330 core

out vec4 fragColor;
uniform vec2 screenSize;

void main()
{
    vec2 normalizedPos = gl_FragCoord.xy / screenSize;

    vec2 fractNormalizedPos = fract(normalizedPos * 4);

    fragColor = vec4(fractNormalizedPos, (normalizedPos.x + normalizedPos.y) / 2, 1.0);
}