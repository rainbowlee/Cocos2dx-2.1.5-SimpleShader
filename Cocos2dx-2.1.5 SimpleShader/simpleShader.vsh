// precision mediump float;
// uniform mat4 CC_PMatrix;
// uniform mat4 CC_MVMatrix;
// uniform mat4 CC_MVPMatrix;
// uniform vec4 CC_Time;
// uniform vec4 CC_SinTime;
// uniform vec4 CC_CosTime;
// uniform vec4 CC_Random01;

attribute vec2 a_position;
attribute vec4 a_color;

varying vec4 v_fragmentColor;

void main()
{
    gl_Position = CC_MVPMatrix * vec4(a_position.x,a_position.y,0,1);
    v_fragmentColor = a_color;
}