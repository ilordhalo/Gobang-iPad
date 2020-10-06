//
//  ZFiveq.h
//  五子棋
//
//  Created by 张 家豪 on 14/12/1.
//  Copyright (c) 2014年 张 家豪. All rights reserved.
//

//重写空的价值！   
#ifndef _______ZFiveq__
#define _______ZFiveq__

#include <stdio.h>

#endif /* defined(_______ZFiveq__) */
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<time.h>
#include<cstdlib>
using namespace std;
#define mmap 15
const long long defk=1;
#define maxint 1000000000
#define maxlong 10000000000000000
class fiveq
{
public:
    long long value;
    int iosstep=0,x,y,by,bx,ly,lx,ii,mxh,mxt,myh,myt,depth;
    long long s,numo,val,bestv,bestj;
    char lmap[mmap+2][mmap+2];
    char map[mmap+2][mmap+2];
    long long dcx[10]={0,5,25,10000,maxlong/10000,maxlong,maxlong,maxlong,maxlong,maxlong};
    long long cx[10]={0,5,25,10000,maxlong/10000,maxlong,maxlong,maxlong,maxlong,maxlong};
    long long ox[10]={0,10,10000,maxint,maxlong/100,maxlong,maxlong,maxlong,maxlong,maxlong};
    long long dox[10]={0,10,10000,maxint,maxlong/100,maxlong,maxlong,maxlong,maxlong,maxlong};
    long long eox[10]={0,10,100,maxint/10,maxlong/10000,maxlong/10000,maxlong/10000,maxlong/10000,maxlong/10000,maxlong/10000};
    long long ecx[10]={0,5,15,10000,maxlong/10000,maxlong/10000,maxlong/10000,maxlong/10000,maxlong/10000,maxlong/10000};
    long long ecc[10]={0,0,0,0,maxlong/10000,maxlong/10000,maxlong/10000,maxlong/10000,maxlong/10000,maxlong/10000};
    long long cc[10]={0,0,0,0,0,maxlong,maxlong,maxlong,maxlong,maxlong};
    int aa[8]={-1,-1,-1,0,1,1,1,0};
    int bb[8]={-1,0,1,1,1,0,-1,-1};
    struct sortq
    {
        int x;
        int wwin;
        int y;
        long long v;
    }q[1000][10];
public:
    fiveq()
    {
        mxh=maxint;
        mxt=-maxint;
        myh=maxint;
        myt=-maxint;
        for(int i=0;i<=mmap+1;i++) {map[i][0]='!'; map[i][mmap+1]='!';}
        for(int j=0;j<=mmap+1;j++) {map[0][j]='!'; map[mmap+1][j]='!';}
        for(int i=0;i<1000;i++) for(int j=0;j<10;j++) {q[i][j].v=0;}
        for(int i=1;i<=mmap;i++)
        {
            for(int j=1;j<=mmap;j++)
            {
                map[i][j]='.';
                lmap[i][j]='.';
            }
        }
        for(int i=0;i<=mmap+1;i++)
        {
            for(int j=0;j<=mmap+1;j++)
            {
                lmap[i][j]=map[i][j];
            }
        }
    }
    void iospplay(int x,int y);
    void show();
    void cvalue();
    void firstcplay(int x);
    long long minmax(int l,int lasti,int m,int mn,int turn);
    long long svalue();
    void cplay();
    void pplay();
    long long alphabeta(int k,int lasti,long long alpha,long long beta,int m,int mn,int turn);
    long long alphabeta2(int k,long long alpha,long long beta,int m,int turn);
    long long alphabeta3(int k,int lasti,long long alpha,long long beta,int m,int mn,int turn);
    int inmap(int x,int y);
    int win();
    void cnow(int numo,int close,char c,long long k);
    void cvalue2();
    int zsort(sortq q[][10],int k,int mn,int turn);
    char anchess(char x);
    void PM();
};