//
//  ViewController.h
//  五子棋
//
//  Created by 张 家豪 on 14/11/25.
//  Copyright (c) 2014年 张 家豪. All rights reserved.
//

#import <UIKit/UIKit.h>
#import<Foundation/Foundation.h>
#import "AlartViewController.h"
#import "SettingViewController.h"
#include "ZFiveq.h"
typedef struct
{
    __unsafe_unretained UIButton *btn;
    __unsafe_unretained UIImageView *imagevie;
}ViewMap;
@interface ViewController : UIViewController<ExpendableAlartViewDelegate>
{
    int lasttagb;
    int lasttagw;
    int alarttag;
    UIView *myview;
    UIView *settingview;
    //ViewMap *viewmap;
    NSMutableArray *viewmapA;
    fiveq *zfq;
}
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;
-(IBAction) winAlert:(bool) pwin;
-(void)cleanAll;
-(void)initViewC;
-(void)creatButton;
-(void)creatView;
-(void) updataView;
@end

