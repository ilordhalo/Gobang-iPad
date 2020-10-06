//
//  SettingViewController.m
//  五子棋ipad
//
//  Created by 张 家豪 on 14/12/14.
//  Copyright (c) 2014年 张 家豪. All rights reserved.
//

#import "SettingViewController.h"

@interface SettingViewController ()

@end

@implementation SettingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    UILabel *lab=[[UILabel alloc] initWithFrame:CGRectMake((_ipadfullsizex-500)/2, 150, 500, 600)];
    [lab setText:@"zjh"];
    UIButton *btn=[[UIButton alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
    [btn setTitle:@"zjhisgod" forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(pressMainButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];
    [self.view setBackgroundColor:[UIColor whiteColor]];
    [self.view addSubview:lab];
    // Do any additional setup after loading the view.
}
/*
- (void)viewWillLayoutSubviews
{
    self.view.frame = CGRectMake(0, 100, 100, 100);
}*/
-(void)pressMainButton:(UIButton *)btn
{
    NSLog(@"haha");
}
-(void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
