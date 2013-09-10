//
//  Cocos2dx_2_1_5_SimpleShaderAppController.h
//  Cocos2dx-2.1.5 SimpleShader
//
//  Created by Tjaz Hrovat on 9/10/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) RootViewController *viewController;

@end

