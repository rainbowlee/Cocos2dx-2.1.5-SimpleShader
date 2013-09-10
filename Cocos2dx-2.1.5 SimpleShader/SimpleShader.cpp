//
//  SimpleShader.cpp
//  
//
//  Created by Tjaz Hrovat on 8/17/13.
//
//

#include "SimpleShader.h"

using namespace cocos2d;

SimpleShader::~SimpleShader() {
    getShaderProgram()->release();
}

bool SimpleShader::init() {
    if ( !CCNode::init() )
        return false;
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    Quad quad_tmp = {
//                   Position                                      Color
        { { 0.0f,             winSize.height },           {255, 0,   0,   255} },
        { { 0.0f,             0.0f           },           {0,   255, 0,   255} },
        { { winSize.width,    winSize.height },           {0,   0,   255, 255} },
        { { winSize.width,    0.0f           },           {255, 255, 255, 255} }
    };    
    quad = quad_tmp;
    
    setContentSize(CCSizeMake(winSize.width, winSize.height));

    CCGLProgram *shaderProg = new CCGLProgram;
    shaderProg->initWithVertexShaderFilename("simpleShader.vsh", "simpleShader.fsh");
    setShaderProgram( shaderProg );
    
    CHECK_GL_ERROR_DEBUG();
    
    shaderProg->link();
    shaderProg->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
    shaderProg->addAttribute(kCCAttributeNameColor, kCCVertexAttrib_Color);
    
    CHECK_GL_ERROR_DEBUG();
    
    shaderProg->updateUniforms();
    
    CHECK_GL_ERROR_DEBUG();
    
    shaderProg->setUniformsForBuiltins();
        
    return true;
}

void SimpleShader::draw() {
    glEnable(GL_CULL_FACE);
    getShaderProgram()->use();
    getShaderProgram()->setUniformsForBuiltins();
    
    CCPoint p = getPosition();
    CCSize s = getContentSize();
        
    int vertSize = sizeof(quad.tl); // ccVertex2F & ccVertex4B
    long offset = (long)&quad;
    
    ccGLEnableVertexAttribs(kCCVertexAttribFlag_Position | kCCVertexAttribFlag_Color);
//  glEnableVertexAttribArray(kCCVertexAttribFlag_Position);
//  glEnableVertexAttribArray(kCCVertexAttribFlag_Color);
    
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, vertSize, (GLvoid*) (offset));
    glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, vertSize, (GLvoid*) (offset + sizeof(_ccVertex2F)));
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glDisable(GL_CULL_FACE);
}