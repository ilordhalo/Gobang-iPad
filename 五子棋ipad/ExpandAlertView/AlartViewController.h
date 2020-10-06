//
//  AlartViewController.h
//  MyReader
//
//  Created by broy denty on 14-8-4.
//  Copyright (c) 2014年 denty. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "LordConstat.h"

@protocol ExpendableAlartViewDelegate <NSObject>
- (void)positiveButtonAction;
- (void)negativeButtonAction;
- (void)closeButtonAction;
@end
@interface AlartViewController : UIViewController
{
    int style;
    NSString *titleName[100];
    NSString *positiveName;
    NSString *negativeName;
    UIColor *zjhColor1;
    UIColor *zjhColor2;
}
@property (nonatomic,strong) UIView *titleView;
@property (nonatomic,weak) id<ExpendableAlartViewDelegate> expendAbleAlartViewDelegate;
- (void)showView:(UIViewController *)VC;
CA_EXTERN CATransform3D CATransform3DMakePerspective(CGPoint center, float disZ);


CA_EXTERN CATransform3D CATransform3DPerspect(CATransform3D t, CGPoint center, float disZ);
-(void)setzjhColor:(UIColor *)color;
-(void)setStyle:(int) x;
-(void)setPositiveName:(NSString *)str;
-(void)setNegativeName:(NSString *)str;
-(void)setTitleName:(NSString *)str AtIndex:(int) index;
@end
