#version 460 

in vec2 vertexPosition;

void main() {
    gl_position.xy = vertexPosition;
    gl_position.z = 0;
    gl_position.w = 1;
}