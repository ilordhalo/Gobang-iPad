//
//  ViewController.m
//  五子棋
//
//  Created by 张 家豪 on 14/11/25.
//  Copyright (c) 2014年 张 家豪. All rights reserved.
//

#import "ViewController.h"
#define _mapsize 768
#define _chesssize 38.4
#define _fullsizex 768
#define _fullsizey 1024
@interface ViewController ()

@end
@implementation ViewController
- (void)viewDidLoad {
    [self initViewC];
    [self creatView];
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}
double t(double last, char* key){
    clock_t now = clock();
    printf("time:%fs \t key:%s \n", (last != 0) ? (double)(now - last) / CLOCKS_PER_SEC : 0, key);
    return now;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(void)initViewC
{
    myview=[[UIView alloc] init];
    fiveq l;
    zfq=&l;
    viewmapA=[NSMutableArray arrayWithCapacity:15*15];
}
-(void)creatView
{
    myview.frame=CGRectMake(0, 0, _fullsizex, _fullsizey);
    UIImageView *BGP=[[UIImageView alloc] initWithFrame:CGRectMake(0, 0, _ipadfullsizex, _ipadfullsizey)];
    BGP.image=[UIImage imageNamed:@"background5.png"];
    [self.view addSubview:BGP];
    
    UILabel *BGC=[[UILabel alloc] initWithFrame:CGRectMake(0, 0, _ipadfullsizex, _ipadfullsizey)];
    BGC.backgroundColor=[UIColor purpleColor];
    BGC.alpha=0.5;
    [self.view addSubview:BGC];
    
    UIImageView *vie=[[UIImageView alloc] init];
    vie.frame=CGRectMake(0,150,_mapsize,_mapsize);
    vie.image=[UIImage imageNamed:@"allmap.png"];
    vie.alpha=0.8;
    UILabel *label=[[UILabel alloc] init];
    label.frame=CGRectMake(0, 0, 768, 150);
    //label.backgroundColor=[UIColor whiteColor];
    label.text=@"五子棋";
    label.textAlignment=NSTextAlignmentCenter;
    label.adjustsFontSizeToFitWidth=YES;
    label.font=[UIFont boldSystemFontOfSize:40.0f];
    UIButton *btn=[UIButton buttonWithType:UIButtonTypeRoundedRect];
    btn.frame=CGRectMake(200, 150+_mapsize, _fullsizex-200*2,_fullsizey-(150+_mapsize));
    [btn setBackgroundImage:[UIImage imageNamed:@"ZstartButton"] forState:UIControlStateNormal];
    //[btn setTitle:@"重新开始" forState:UIControlStateNormal];
    //btn.titleLabel.font=[UIFont boldSystemFontOfSize:40.0f];
    [btn addTarget:self action:@selector(pressPlayAgain:) forControlEvents:UIControlEventTouchUpInside];
    [myview addSubview:btn];
    [myview addSubview:label];
    [myview addSubview:vie];
    [self creatButton];
    [self.view addSubview:myview];
    //设置界面
    settingview.frame=CGRectMake(0, 0, _fullsizex, _fullsizey);
    UILabel *settinglab=[[UILabel alloc] init];
    settinglab.frame=CGRectMake(0, 0, _fullsizex, _fullsizey);
    settinglab.backgroundColor=[UIColor whiteColor];
    settinglab.text=@"这是设置界面";
    settinglab.textAlignment=NSTextAlignmentCenter;
    settinglab.adjustsFontSizeToFitWidth=YES;
    settinglab.font=[UIFont boldSystemFontOfSize:40.0f];
    [settingview addSubview:settinglab];
}
-(void)creatButton
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            UIView *vie=[[UIView alloc] init];
            UIButton *btn=[UIButton buttonWithType:UIButtonTypeCustom];
            UIImageView *imagevie=[[UIImageView alloc] init];
            vie.frame=CGRectMake(12.8+50.24*i,150+12.8+50.24*j, _chesssize, _chesssize);
            btn.frame=CGRectMake(0, 0, _chesssize, _chesssize);
            btn.tag=i*15+j;
            imagevie.frame=CGRectMake(0, 0, _chesssize, _chesssize);
            [btn addTarget:self action:@selector(pressButton:) forControlEvents:UIControlEventTouchUpInside];
            //imagevie.image=[UIImage imageNamed:@"2.png"];
            [vie addSubview:btn];
            [vie addSubview:imagevie];
            [myview addSubview:vie];
            ViewMap viewmap;
            viewmap.btn=btn;
            viewmap.imagevie=imagevie;
            NSValue *value=[NSValue valueWithBytes:&viewmap objCType:@encode(ViewMap)];
            [viewmapA addObject:value];
            //
        }
    }
}
-(void)creatSettingView
{
}
-(void)cleanAll
{
    for(NSValue *value in viewmapA)
    {
        ViewMap viewmap;
        [value getValue:&viewmap];
        viewmap.imagevie.image=nil;
        viewmap.btn.enabled=YES;
    }
    fiveq l;
    zfq=&l;
}
-(IBAction)playAlert
{
    AlartViewController *alart=[[AlartViewController alloc] init];
    [alart setStyle:3];
    //[alart setzjhColor:[UIColor colorWithRed:0.6 green:0 blue:0.8 alpha:1]];
    [alart setzjhColor:[UIColor purpleColor]];
    [alart setPositiveName:@"确定"];
    [alart setNegativeName:@"取消"];
    [alart setTitleName:@"确定要重新开始吗?" AtIndex:0];
    alart.expendAbleAlartViewDelegate=self;
    __weak UIViewController *weakVC=self;
    [alart showView:weakVC];
}
-(IBAction) winAlert:(bool)pwin
{
    AlartViewController *alart=[[AlartViewController alloc]init];
    [alart setStyle:1];
    //[alart setzjhColor:[UIColor colorWithRed:0.6 green:0 blue:0.8 alpha:1]];
    [alart setzjhColor:[UIColor purpleColor]];
    [alart setPositiveName:@"重新开始"];
    if(pwin) [alart setTitleName:@"你赢了" AtIndex:0];
    else [alart setTitleName:@"你输了" AtIndex:0];
    alart.expendAbleAlartViewDelegate=self;
    __weak UIViewController *weakVC=self;
    [alart showView:weakVC];
    /*
    if(pwin)
    {
    UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"你赢了！"
                                                  message:nil
                                                 delegate:self
                                        cancelButtonTitle:nil
                                        otherButtonTitles:@"重来",nil];
        [alert show];
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"你输了！"
                                                       message:nil
                                                      delegate:self
                                             cancelButtonTitle:nil
                                             otherButtonTitles:@"重来",nil];
        [alert show];
    }*/
}
- (void)negativeButtonAction
{
    //[self cleanAll];
    NSLog(@"negative Action");
}

- (void)positiveButtonAction
{
    NSLog(@"positive Action");
    [self cleanAll];
}

- (void)closeButtonAction
{
    NSLog(@"close Action");
}
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if(buttonIndex==0)
    [self cleanAll];
}
-(void)pressPlayAgain:(UIButton *)btn
{
    SettingViewController *settingvc=[[SettingViewController alloc] init];
    [settingvc setModalPresentationStyle:UIModalPresentationFormSheet];
    [self presentViewController:settingvc animated:YES completion:^{}];
    settingvc.view.superview.frame = CGRectMake(0, 0, 100, 100);
    settingvc.view.superview.center = self.view.center;
    //[self playAlert];
    //[self.view removeFromSuperview];
    //[self.view addSubview:settingview];
    //[self.view insertSubview:settingview aboveSubview:myview];
    //[self cleanAll];
}
//***********************非常屌的函数调用可立即更新UIView*********************//
void giveSomeLove()
{
    // 给程序一点爱，他才能更新窗口
    [[NSRunLoop currentRunLoop] runUntilDate: [NSDate distantPast]];
} // giveSomeLove
-(void)pressButton:(UIButton *)btn
{
    zfq->iosstep++;
    NSValue *value=[viewmapA objectAtIndex:btn.tag];
    ViewMap viewmap;
    [value getValue:&viewmap];
    viewmap.btn.enabled=NO;
    viewmap.imagevie.image=[UIImage imageNamed:@"blackchess.png"];
    //printf("%d\nzjhisgod",zfq->iosstep);
    if(zfq->iosstep!=1)
    {
        value=[viewmapA objectAtIndex:lasttagw];
        [value getValue:&viewmap];
        viewmap.imagevie.image=[UIImage imageNamed:@"whitechess.png"];
    }
    lasttagb=btn.tag;
    if(zfq->win()==1)
    {
        [self winAlert:true];
    }
    else if(zfq->win()==2)
    {
        [self winAlert:false];
    }
    giveSomeLove();
    zfq->iospplay(btn.tag%15+1, btn.tag/15+1);
    // d=5 b=10 ipad2cost=5s bug t=1
    //d=5 b=5 ipad2cost=0.8s bug
    // d=3 b=unlim ipad2costt=0.5s nobug t=1
    zfq->depth=5;
    if(zfq->iosstep==1)
    {
        zfq->firstcplay(2);
    }
    else if(zfq->iosstep<=20)
    {
        clock_t beginT=clock();
        double delt=0.0;
        zfq->alphabeta3(1,0,-maxlong*10, maxlong*10, 6,5,1);
        //zfq->alphabeta2(1, -maxlong*10, maxlong*10, 3, 1);
        //zfq->minmax(1,0,5,5,1);
        clock_t endT=clock();
        delt=(double)(endT-beginT)/CLOCKS_PER_SEC;
        cout<<delt<<endl;
    }
    else if(zfq->iosstep>20)
    {
        clock_t beginT=clock();
        double delt=0.0;
        zfq->alphabeta3(1,0,-maxlong*10, maxlong*10, 6,5,1);
        //zfq->alphabeta2(1, -maxlong*10, maxlong*10, 3, 1);
        //zfq->minmax(1,0,5,5,1);
        clock_t endT=clock();
        delt=(double)(endT-beginT)/CLOCKS_PER_SEC;
        cout<<delt<<endl;
    }
    /*
    else if(zfq->iosstep<=10)
    {
        double t1 = t(0, "");
                zfq->alphabeta(1, -maxlong*10, maxlong*10, 3, 13);
        t(t1, "end");
    }
    else
    {
        zfq->alphabeta(1, -maxlong*10, maxlong*10, 5, 5);
    }*/
    zfq->cplay();
    value=[viewmapA objectAtIndex:(zfq->by-1)*15+(zfq->bx-1)];
    [value getValue:&viewmap];
    viewmap.imagevie.image=[UIImage imageNamed:@"whitechess(j).png"];
    lasttagw=(zfq->by-1)*15+(zfq->bx-1);
    viewmap.btn.enabled=NO;
    if(zfq->win()==1)
    {
        [self winAlert:true];
    }
    else if(zfq->win()==2)
    {
        [self winAlert:false];
    }
    //printf("%d %d",zfq->lx,zfq->ly);
}
@end
