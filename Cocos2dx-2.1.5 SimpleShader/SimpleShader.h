//
//  SimpleShader.h
//  
//
//  Created by Tjaz Hrovat on 8/17/13.
//
//

#ifndef __Simple_Shader__
#define __Simple_Shader__

#include "cocos2d.h"

struct PositionAndColor {
    cocos2d::_ccVertex2F position;
    cocos2d::_ccColor4B  color;
};

struct Quad {
    PositionAndColor   tl;
    PositionAndColor   bl;
    PositionAndColor   tr;
    PositionAndColor   br;
};

class SimpleShader : public cocos2d::CCNode {
public:
    SimpleShader() {}
    ~SimpleShader();
    
    bool init();

private:   
    Quad quad;
    void draw();
};

#endif