//
//  ZFiveq.cpp
//  五子棋
//
//  Created by 张 家豪 on 14/12/1.
//  Copyright (c) 2014年 张 家豪. All rights reserved.
//

#include "ZFiveq.h"
int fiveq::zsort(sortq q[][10],int k,int mn,int turn)
{
    int n=0;
    for(int i=mxh-1;i<=mxt+1;i++)
    {
        for(int j=myh-1;j<=myt+1;j++)
        {
            if(inmap(i,j)==1)
            {
                n++;
                if(turn%2==0) lmap[i][j]='x';
                else lmap[i][j]='o';
                cvalue2();
                q[n][k].v=svalue();
                q[n][k].x=i;
                q[n][k].y=j;
                lmap[i][j]='.';
            }
        }
    }
    int r=min(mn,n);
    if(turn%2==1)
        for(int i=1;i<=r;i++)
        {
            bestv=q[i][k].v;
            bestj=i;
            for(int j=i+1;j<=n;j++)
            {
                if(q[j][k].v>bestv)
                {
                    bestv=q[j][k].v;
                    bestj=j;
                }
            }
            swap(q[i][k],q[bestj][k]);
        }
    else
        for(int i=1;i<=r;i++)
        {
            bestv=q[i][k].v;
            bestj=i;
            for(int j=i+1;j<=n;j++)
            {
                if(q[j][k].v<bestv)
                {
                    bestv=q[j][k].v;
                    bestj=j;
                }
            }
            swap(q[i][k],q[bestj][k]);
        }
    return r;
}
/****************************************************/
/*************≈–∂œ∏√µ„ «∑Òø…œ¬◊”*********************/
/****************************************************/
int fiveq::inmap(int x,int y)
{
    if(lmap[x][y]=='.'&&x>0&&x<16&&y>0&&y<16) return 1;
    else return 0;
}
/****************************************************/
/******************* ‰≥ˆ∆Â≈Ã*************************/
/****************************************************/
void fiveq::show()
{
    for(int i=0;i<=mmap;i++) if(i>=10) cout<<i; else cout<<i<<" ";
    cout<<endl;
    for(int i=1;i<=mmap;i++)
    {
        if(i>=10) cout<<i;
        else cout<<i<<" ";
        for(int j=1;j<=mmap;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}
/****************************************************/
/**************π¿÷µ∫Ø ˝(æˆ∂®À„∑®÷«ƒ‹µƒπÿº¸)**********/
/****************************************************/
char fiveq::anchess(char x)
{
    if(x=='x') return 'o';
    else return 'x';
}
void fiveq::cnow(int numo,int close,char c,long long k)
{
    if(numo==0) return;
    if(k==1)
    {
        if(c=='x')
        {
            if(close==0) {value-=dox[numo]; }//if(dox[numo]>=maxint) cout<<"black o"<<numo<<endl;}
            else if(close==1) {value-=dcx[numo]; }//if(dcx[numo]>=maxint) cout<<"black c"<<numo<<endl;}
            else {value-=cc[numo]; }//cout<<"cc"<<numo<<endl;}
        }
        else if(c=='o')
        {
            if(close==0) {value+=ox[numo]; }//if(ox[numo]>=maxint) cout<<"white o"<<numo<<endl;}
            else if(close==1) {value+=cx[numo]; }//if(cx[numo]>=maxint) cout<<"white c"<<numo<<endl;}
            else value+=cc[numo];
        }
    }
    else
    {
        if(c=='x')
        {
            if(close==0) {value-=eox[numo]; }//if(dox[numo]>=maxint) cout<<"black o"<<numo<<endl;}
            else if(close==1) {value-=ecx[numo]; }//if(dcx[numo]>=maxint) cout<<"black c"<<numo<<endl;}
            else {value-=ecc[numo]; }//cout<<"cc"<<numo<<endl;}
        }
        else if(c=='o')
        {
            if(close==0) {value+=eox[numo]; }//if(ox[numo]>=maxint) cout<<"white o"<<numo<<endl;}
            else if(close==1) {value+=ecx[numo]; }//if(cx[numo]>=maxint) cout<<"white c"<<numo<<endl;}
            else value+=ecc[numo];
        }
    }
}
void fiveq::cvalue2()    //O(4*mmap*mmap)
{
    const long long k=2;
    value=0;
    int numo=0;
    for(int haha=1;haha<=2;haha++)
    {
        char chess='x'; //black
        if(haha==2) chess='o';
        //向右下角遍历棋盘
        for(int i=1;i<=mmap;i++)
        {
            //第一行
            int wayx=aa[4],wayy=bb[4];
            int close=1;
            numo=0;
            for(int j=0;j<=mmap-i+1;j++)
            {
                int nx=1+wayx*j,ny=i+wayy*j;
                //cout<<nx<<" "<<ny<<endl;
                if(lmap[nx][ny]==anchess(chess)||lmap[nx][ny]=='!')
                {
                    if(close<2) close++;
                    cnow(numo,close,chess,1);
                    numo=0;
                    close=1;
                }
                else if(lmap[nx][ny]=='.')
                {
                    cnow(numo,close,chess,1);
                    if(lmap[nx-wayx][ny-wayy]==chess&&lmap[nx+wayx][ny+wayy]==chess)
                    {
                        int ph=-1,pt=1;
                        close=0;
                        while(1)
                        {
                            bool zjh=false;
                            if(lmap[nx+wayx*ph][ny+wayy*ph]==chess) {ph--;zjh=true;}
                            if(lmap[nx+wayx*pt][ny+wayy*pt]==chess) {pt++;zjh=true;}
                            if(!zjh) break;
                        }
                        if(lmap[nx+wayx*ph][ny+wayy*ph]==anchess(chess)||lmap[nx+wayx*ph][ny+wayy*ph]=='!')
                        {
                            close++;
                        }
                        if(lmap[nx+wayx*pt][ny+wayy*pt]==anchess(chess)||lmap[nx+wayx*pt][ny+wayy*pt]=='!')
                        {
                            close++;
                        }
                        pt--;
                        ph++;
                        cnow(pt-ph,close,chess,k);
                        close=0;
                        numo=0;
                    }
                    else
                    {
                        close=0;
                        numo=0;
                    }
                }
                else if(lmap[nx][ny]==chess) numo++;
            }
            //第一列
            close=1;
            numo=0;
            if(i>=2)
                for(int j=0;j<=mmap-i+1;j++)
                {
                    int nx=i+wayx*j,ny=1+wayy*j;
                    //cout<<nx<<" "<<ny<<endl;
                    if(lmap[nx][ny]==anchess(chess)||lmap[nx][ny]=='!')
                    {
                        if(close<2) close++;
                        cnow(numo,close,chess,1);
                        numo=0;
                        close=1;
                    }
                    else if(lmap[nx][ny]=='.')
                    {
                        cnow(numo,close,chess,1);
                        if(lmap[nx-wayx][ny-wayy]==chess&&lmap[nx+wayx][ny+wayy]==chess)
                        {
                            int ph=-1,pt=1;
                            close=0;
                            while(1)
                            {
                                bool zjh=false;
                                if(lmap[nx+wayx*ph][ny+wayy*ph]==chess) {ph--;zjh=true;}
                                if(lmap[nx+wayx*pt][ny+wayy*pt]==chess) {pt++;zjh=true;}
                                if(!zjh) break;
                            }
                            if(lmap[nx+wayx*ph][ny+wayy*ph]==anchess(chess)||lmap[nx+wayx*ph][ny+wayy*ph]=='!')
                            {
                                close++;
                            }
                            if(lmap[nx+wayx*pt][ny+wayy*pt]==anchess(chess)||lmap[nx+wayx*pt][ny+wayy*pt]=='!')
                            {
                                close++;
                            }
                            pt--;
                            ph++;
                            cnow(pt-ph,close,chess,k);
                            close=0;
                            numo=0;
                        }
                        else
                        {
                            close=0;
                            numo=0;
                        }
                    }
                    else if(lmap[nx][ny]==chess) numo++;
                }
        }
        //向左下角遍历棋盘
        for(int i=1;i<=mmap;i++)
        {
            //第一行
            int wayx=aa[6],wayy=bb[6];
            int close=1;
            numo=0;
            for(int j=0;j<=i;j++)
            {
                int nx=1+wayx*j,ny=i+wayy*j;
                //cout<<nx<<" "<<ny<<endl;
                if(lmap[nx][ny]==anchess(chess)||lmap[nx][ny]=='!')
                {
                    if(close<2) close++;
                    cnow(numo,close,chess,1);
                    numo=0;
                    close=1;
                }
                else if(lmap[nx][ny]=='.')
                {
                    cnow(numo,close,chess,1);
                    if(lmap[nx-wayx][ny-wayy]==chess&&lmap[nx+wayx][ny+wayy]==chess)
                    {
                        int ph=-1,pt=1;
                        close=0;
                        while(1)
                        {
                            bool zjh=false;
                            if(lmap[nx+wayx*ph][ny+wayy*ph]==chess) {ph--;zjh=true;}
                            if(lmap[nx+wayx*pt][ny+wayy*pt]==chess) {pt++;zjh=true;}
                            if(!zjh) break;
                        }
                        if(lmap[nx+wayx*ph][ny+wayy*ph]==anchess(chess)||lmap[nx+wayx*ph][ny+wayy*ph]=='!')
                        {
                            close++;
                        }
                        if(lmap[nx+wayx*pt][ny+wayy*pt]==anchess(chess)||lmap[nx+wayx*pt][ny+wayy*pt]=='!')
                        {
                            close++;
                        }
                        pt--;
                        ph++;
                        cnow(pt-ph,close,chess,k);
                        close=0;
                        numo=0;
                    }
                    else
                    {
                        close=0;
                        numo=0;
                    }
                }
                else if(lmap[nx][ny]==chess) numo++;
            }
            //第十五列
            close=1;
            numo=0;
            if(i>=2)
                for(int j=0;j<=mmap-i+1;j++)
                {
                    int nx=i+wayx*j,ny=15+wayy*j;
                    //cout<<nx<<" "<<ny<<endl;
                    if(lmap[nx][ny]==anchess(chess)||lmap[nx][ny]=='!')
                    {
                        if(close<2) close++;
                        cnow(numo,close,chess,1);
                        numo=0;
                        close=1;
                    }
                    else if(lmap[nx][ny]=='.')
                    {
                        cnow(numo,close,chess,1);
                        if(lmap[nx-wayx][ny-wayy]==chess&&lmap[nx+wayx][ny+wayy]==chess)
                        {
                            int ph=-1,pt=1;
                            close=0;
                            while(1)
                            {
                                bool zjh=false;
                                if(lmap[nx+wayx*ph][ny+wayy*ph]==chess) {ph--;zjh=true;}
                                if(lmap[nx+wayx*pt][ny+wayy*pt]==chess) {pt++;zjh=true;}
                                if(!zjh) break;
                            }
                            if(lmap[nx+wayx*ph][ny+wayy*ph]==anchess(chess)||lmap[nx+wayx*ph][ny+wayy*ph]=='!')
                            {
                                close++;
                            }
                            if(lmap[nx+wayx*pt][ny+wayy*pt]==anchess(chess)||lmap[nx+wayx*pt][ny+wayy*pt]=='!')
                            {
                                close++;
                            }
                            pt--;
                            ph++;
                            cnow(pt-ph,close,chess,k);
                            close=0;
                            numo=0;
                        }
                        else
                        {
                            close=0;
                            numo=0;
                        }
                    }
                    else if(lmap[nx][ny]==chess) numo++;
                }
        }
        //向下遍历
        for(int i=1;i<=mmap;i++)
        {
            //第一行
            int wayx=aa[5],wayy=bb[5];
            int close=1;
            numo=0;
            for(int j=0;j<=mmap;j++)
            {
                int nx=1+wayx*j,ny=i+wayy*j;
                //cout<<nx<<" "<<ny<<endl;
                if(lmap[nx][ny]==anchess(chess)||lmap[nx][ny]=='!')
                {
                    if(close<2) close++;
                    cnow(numo,close,chess,1);
                    numo=0;
                    close=1;
                }
                else if(lmap[nx][ny]=='.')
                {
                    cnow(numo,close,chess,1);
                    if(lmap[nx-wayx][ny-wayy]==chess&&lmap[nx+wayx][ny+wayy]==chess)
                    {
                        int ph=-1,pt=1;
                        close=0;
                        while(1)
                        {
                            bool zjh=false;
                            if(lmap[nx+wayx*ph][ny+wayy*ph]==chess) {ph--;zjh=true;}
                            if(lmap[nx+wayx*pt][ny+wayy*pt]==chess) {pt++;zjh=true;}
                            if(!zjh) break;
                        }
                        if(lmap[nx+wayx*ph][ny+wayy*ph]==anchess(chess)||lmap[nx+wayx*ph][ny+wayy*ph]=='!')
                        {
                            close++;
                        }
                        if(lmap[nx+wayx*pt][ny+wayy*pt]==anchess(chess)||lmap[nx+wayx*pt][ny+wayy*pt]=='!')
                        {
                            close++;
                        }
                        pt--;
                        ph++;
                        cnow(pt-ph,close,chess,k);
                        close=0;
                        numo=0;
                    }
                    else
                    {
                        close=0;
                        numo=0;
                    }
                }
                else if(lmap[nx][ny]==chess) numo++;
            }
        }
        //向右遍历
        for(int i=1;i<=mmap;i++)
        {
            //第一列
            int wayx=aa[3],wayy=bb[3];
            int close=1;
            numo=0;
            for(int j=0;j<=mmap;j++)
            {
                int nx=i+wayx*j,ny=1+wayy*j;
                //cout<<nx<<" "<<ny<<endl;
                if(lmap[nx][ny]==anchess(chess)||lmap[nx][ny]=='!')
                {
                    if(close<2) close++;
                    cnow(numo,close,chess,1);
                    numo=0;
                    close=1;
                }
                else if(lmap[nx][ny]=='.')
                {
                    cnow(numo,close,chess,1);
                    if(lmap[nx-wayx][ny-wayy]==chess&&lmap[nx+wayx][ny+wayy]==chess)
                    {
                        int ph=-1,pt=1;
                        close=0;
                        while(1)
                        {
                            bool zjh=false;
                            if(lmap[nx+wayx*ph][ny+wayy*ph]==chess) {ph--;zjh=true;}
                            if(lmap[nx+wayx*pt][ny+wayy*pt]==chess) {pt++;zjh=true;}
                            if(!zjh) break;
                        }
                        if(lmap[nx+wayx*ph][ny+wayy*ph]==anchess(chess)||lmap[nx+wayx*ph][ny+wayy*ph]=='!')
                        {
                            close++;
                        }
                        if(lmap[nx+wayx*pt][ny+wayy*pt]==anchess(chess)||lmap[nx+wayx*pt][ny+wayy*pt]=='!')
                        {
                            close++;
                        }
                        pt--;
                        ph++;
                        cnow(pt-ph,close,chess,k);
                        close=0;
                        numo=0;
                    }
                    else
                    {
                        close=0;
                        numo=0;
                    }
                }
                else if(lmap[nx][ny]==chess) numo++;
            }
        }
    }
}
void fiveq::cvalue()
{
    s=0;
    numo=0;
    //∫·œÚ≤È’“
    for(int i=1;i<=mmap;i++)
    {
        for(int j=1;j<=mmap;j++)
        {
            if(lmap[i][j]=='o')
            {
                numo++;
                if(lmap[i][j-1]=='x'||lmap[i][j-1]=='!')
                {
                    for(ii=j+1;;ii++)
                    {
                        if(lmap[i][ii]=='.') {s=s+cx[numo]; break;}
                        else if(lmap[i][ii]=='x'||lmap[i][ii]=='!') {s=s+cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[i][j-1]=='.')
                {
                    for(ii=j+1;;ii++)
                    {
                        if(lmap[i][ii]=='.') {s=s+ox[numo]; break;}
                        else if(lmap[i][ii]=='x'||lmap[i][ii]=='!') {s=s+cx[numo]; break;}
                        else numo++;
                    }
                }
            }
            else if(lmap[i][j]=='x')
            {
                numo++;
                if(lmap[i][j-1]=='o'||lmap[i][j-1]=='!')
                {
                    for(ii=j+1;;ii++)
                    {
                        if(lmap[i][ii]=='.') {s=s-dcx[numo]; break;}
                        else if(lmap[i][ii]=='o'||lmap[i][ii]=='!') {s=s-cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[i][j-1]=='.')
                {
                    for(ii=j+1;;ii++)
                    {
                        if(lmap[i][ii]=='.') {s=s-dox[numo]; break;}
                        else if(lmap[i][ii]=='o'||lmap[i][ii]=='!') {s=s-dcx[numo]; break;}
                        else numo++;
                    }
                }
            }
            numo=0;
        }
    }
    
    //◊›œÚ≤È’“
    for(int j=1;j<=mmap;j++)
    {
        for(int i=1;i<=mmap;i++)
        {
            if(lmap[i][j]=='o')
            {
                numo++;
                if(lmap[i-1][j]=='x'||lmap[i-1][j]=='!')
                {
                    for(ii=i+1;;ii++)
                    {
                        if(lmap[ii][j]=='.') {s=s+cx[numo]; break;}
                        else if(lmap[ii][j]=='x'||lmap[ii][j]=='!') {s=s+cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[i-1][j]=='.')
                {
                    for(ii=i+1;;ii++)
                    {
                        if(lmap[ii][j]=='.') {s=s+ox[numo]; break;}
                        else if(lmap[ii][j]=='x'||lmap[ii][j]=='!') {s=s+cx[numo]; break;}
                        else numo++;
                    }
                }
            }
            else if(lmap[i][j]=='x')
            {
                numo++;
                if(lmap[i-1][j]=='o'||lmap[i-1][j]=='!')
                {
                    for(ii=i+1;;ii++)
                    {
                        if(lmap[ii][j]=='.') {s=s-dcx[numo]; break;}
                        else if(lmap[ii][j]=='o'||lmap[ii][j]=='!') {s=s-cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[i-1][j]=='.')
                {
                    for(ii=i+1;;ii++)
                    {
                        if(lmap[ii][j]=='.') {s=s-dox[numo]; break;}
                        else if(lmap[ii][j]=='o'||lmap[ii][j]=='!') {s=s-dcx[numo]; break;}
                        else numo++;
                    }
                }
            }
            numo=0;
        }
    }
    //◊Û…œ”“œ¬≤È’“
    for(int j=mmap-4;j>=1;j--)
    {
        for(int k=0;k<=mmap-j;k++)
        {
            if(lmap[1+k][j+k]=='o')
            {
                numo++;
                if(lmap[k][j+k-1]=='x'||lmap[k][k+j-1]=='!')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[1+ii][j+ii]=='.') {s=s+cx[numo]; break;}
                        else if(lmap[1+ii][j+ii]=='x'||lmap[1+ii][j+ii]=='!') {s=s+cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[k][j+k-1]=='.')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[1+ii][j+ii]=='.') {s=s+ox[numo]; break;}
                        else if(lmap[1+ii][j+ii]=='x'||lmap[1+ii][j+ii]=='!') {s=s+cx[numo]; break;}
                        else numo++;
                    }
                }
            }
            else if(lmap[1+k][j+k]=='x')
            {
                numo++;
                if(lmap[k][j+k-1]=='o'||lmap[k][k+j-1]=='!')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[1+ii][j+ii]=='.') {s=s-dcx[numo]; break;}
                        else if(lmap[1+ii][j+ii]=='o'||lmap[1+ii][j+ii]=='!') {s=s-cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[k][j+k-1]=='.')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[1+ii][j+ii]=='.') {s=s-dox[numo]; break;}
                        else if(lmap[1+ii][j+ii]=='o'||lmap[1+ii][j+ii]=='!') {s=s-dcx[numo]; break;}
                        else numo++;
                    }
                }
            }
            numo=0;
        }
    }
    for(int i=2;i<=mmap-4;i++)
    {
        for(int k=0;k<=mmap-i;k++)
        {
            if(lmap[i+k][1+k]=='o')
            {
                numo++;
                if(lmap[i+k-1][k]=='x'||lmap[i+k-1][k]=='!')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[i+ii][1+ii]=='.') {s=s+cx[numo]; break;}
                        else if(lmap[i+ii][1+ii]=='x'||lmap[i+ii][1+ii]=='!') {s=s+cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[i+k-1][k]=='.')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[i+ii][1+ii]=='.') {s=s+ox[numo]; break;}
                        else if(lmap[i+ii][1+ii]=='x'||lmap[i+ii][1+ii]=='!') {s=s+cx[numo]; break;}
                        else numo++;
                    }
                }
            }
            else if(lmap[i+k][1+k]=='x')
            {
                numo++;
                if(lmap[i+k-1][k]=='o'||lmap[i+k-1][k]=='!')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[i+ii][1+ii]=='.') {s=s-dcx[numo]; break;}
                        else if(lmap[i+ii][1+ii]=='o'||lmap[i+ii][1+ii]=='!') {s=s-cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[i+k-1][k]=='.')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[i+ii][1+ii]=='.') {s=s-dox[numo]; break;}
                        else if(lmap[i+ii][1+ii]=='o'||lmap[i+ii][1+ii]=='!') {s=s-dcx[numo]; break;}
                        else numo++;
                    }
                }
            }
            numo=0;
        }
    }
    //”“…œ◊Ûœ¬≤È’“
    for(int j=5;j<=mmap;j++)
    {
        for(int k=0;k<=j-1;k++)
        {
            if(lmap[1+k][j-k]=='o')
            {
                numo++;
                if(lmap[k][j-k+1]=='x'||lmap[k][j-k+1]=='!')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[1+ii][j-ii]=='.') {s=s+cx[numo]; break;}
                        else if(lmap[1+ii][j-ii]=='x'||lmap[1+ii][j-ii]=='!') {s=s+cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[k][j-k+1]=='.')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[1+ii][j-ii]=='.') {s=s+ox[numo]; break;}
                        else if(lmap[1+ii][j-ii]=='x'||lmap[1+ii][j-ii]=='!') {s=s+cx[numo]; break;}
                        else numo++;
                    }
                }
            }
            else if(lmap[1+k][j-k]=='x')
            {
                numo++;
                if(lmap[k][j-k+1]=='o'||lmap[k][j-k+1]=='!')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[1+ii][j-ii]=='.') {s=s-dcx[numo]; break;}
                        else if(lmap[1+ii][j-ii]=='o'||lmap[1+ii][j-ii]=='!') {s=s-cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[k][j-k+1]=='.')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[1+ii][j-ii]=='.') {s=s-dox[numo]; break;}
                        else if(lmap[1+ii][j-ii]=='o'||lmap[1+ii][j-ii]=='!') {s=s-dcx[numo]; break;}
                        else numo++;
                    }
                }
            }
            numo=0;
        }
    }
    for(int i=2;i<=mmap-4;i++)
    {
        for(int k=0;k<=mmap-i;k++)
        {
            if(lmap[i+k][mmap-k]=='o')
            {
                numo++;
                if(lmap[i+k-1][mmap-k+1]=='x'||lmap[i+k-1][mmap-k+1]=='!')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[i+ii][mmap-ii]=='.') {s=s+cx[numo]; break;}
                        else if(lmap[i+ii][mmap-ii]=='x'||lmap[i+ii][mmap-ii]=='!') {s=s+cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[i+k-1][mmap-k+1]=='.')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[i+ii][mmap-ii]=='.') {s=s+ox[numo]; break;}
                        else if(lmap[i+ii][mmap-ii]=='x'||lmap[i+ii][mmap-ii]=='!') {s=s+cx[numo]; break;}
                        else numo++;
                    }
                }
            }
            else if(lmap[i+k][mmap-k]=='x')
            {
                numo++;
                if(lmap[i+k-1][mmap-k+1]=='o'||lmap[i+k-1][mmap-k+1]=='!')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[i+ii][mmap-ii]=='.') {s=s-dcx[numo]; break;}
                        else if(lmap[i+ii][mmap-ii]=='o'||lmap[i+ii][mmap-ii]=='!') {s=s-cc[numo]; break;}
                        else numo++;
                    }
                }
                else if(lmap[i+k-1][mmap-k+1]=='.')
                {
                    for(ii=k+1;;ii++)
                    {
                        if(lmap[i+ii][mmap-ii]=='.') {s=s-dox[numo]; break;}
                        else if(lmap[i+ii][mmap-ii]=='o'||lmap[i+ii][mmap-ii]=='!') {s=s-dcx[numo]; break;}
                        else numo++;
                    }
                }
            }
            numo=0;
        }
    }
    value=s;
}
/****************************************************/
/******************∑µªÿ∂‘µ±«∞∆Â≈Ãµƒπ¿÷µ**************/
/****************************************************/
long long fiveq::svalue()
{
    return value;
}
/****************************************************/
/**************alpha-betaºÙ÷¶À—À˜********************/
/****************************************************/
long long fiveq::alphabeta(int k,int lasti,long long alpha,long long beta,int m,int mn,int turn)
{
    //if(k>=depth) {return q[lasti][k-1].v;}
    //if(k%2==)
    if(k>=depth) {if(turn%2==0) return -q[lasti][k-1].v; else return q[lasti][k-1].v;}
    if(abs(q[1][k-1].v)>maxlong/10) {depth=k; if(turn%2==0) return -q[lasti][k-1].v; else return q[lasti][k-1].v;}
    int ben=zsort(q,k,mn,turn);
    for(int i=1;i<=ben;i++)
    {
        if(turn%2==0) lmap[q[i][k].x][q[i][k].y]='x';
        else lmap[q[i][k].x][q[i][k].y]='o';
        //if(i==1) cout<<k<<" "<<q[i][k].x<<" "<<q[i][k].y<<endl;
        int lmxh=mxh,lmxt=mxt,lmyh=myh,lmyt=myt;
        mxh=min(q[i][k].x,mxh);
        mxt=max(q[i][k].x,mxt);
        myh=min(q[i][k].y,myh);
        myt=max(q[i][k].y,myt);
        long long val=-alphabeta(k+1,i,-beta,-alpha,m,mn,turn+1);
        lmap[q[i][k].x][q[i][k].y]='.';
        mxh=lmxh;
        mxt=lmxt;
        myh=lmyh;
        myt=lmyt;
        if(val>=beta)
        {
            return beta;
        }
        if(val>alpha)
        {
            //cout<<k<<" "<<q[i][k].x<<" "<<q[i][k].y<<" "<<val<<endl;
            alpha=val;
            if(k==1)
            {
                bx=q[i][k].x;
                by=q[i][k].y;
            }
        }
    }
    return alpha;
}
long long fiveq::alphabeta3(int k,int lasti,long long alpha,long long beta,int m,int mn,int turn)
{
    //if(k>=depth) {return q[lasti][k-1].v;}
    //if(k%2==)
    if(k>=depth) {if(turn%2==0) return -q[lasti][k-1].v; else return q[lasti][k-1].v;}
    if(abs(q[1][k-1].v)>maxlong/10) {depth=k; if(turn%2==0) return -q[lasti][k-1].v; else return q[lasti][k-1].v;}
    int ben=zsort(q,k,mn,turn);
    long long val=-maxlong*10;
    long long best=val;
    for(int i=1;i<=ben;i++)
    {
        if(turn%2==0) lmap[q[i][k].x][q[i][k].y]='x';
        else lmap[q[i][k].x][q[i][k].y]='o';
        //if(i==1) cout<<k<<" "<<q[i][k].x<<" "<<q[i][k].y<<endl;
        int lmxh=mxh,lmxt=mxt,lmyh=myh,lmyt=myt;
        mxh=min(q[i][k].x,mxh);
        mxt=max(q[i][k].x,mxt);
        myh=min(q[i][k].y,myh);
        myt=max(q[i][k].y,myt);
        val=-alphabeta(k+1,i,-beta,-alpha,m,mn,turn+1);
        lmap[q[i][k].x][q[i][k].y]='.';
        mxh=lmxh;
        mxt=lmxt;
        myh=lmyh;
        myt=lmyt;
        if(val>best)
        {
            best=val;
        }
        if(best>alpha)
        {
            //cout<<k<<" "<<q[i][k].x<<" "<<q[i][k].y<<" "<<val<<endl;
            alpha=best;
            if(k==1)
            {
                bx=q[i][k].x;
                by=q[i][k].y;
            }
        }
        if(val>=beta)
        {
            break;
        }
    }
    return best;
}
long long fiveq::alphabeta2(int k,long long alpha,long long beta,int m,int turn)
{
    //if(k>=depth) {return q[lasti][k-1].v;}
    //if(k%2==)
    if(k>=m) {cvalue2(); if(turn%2==0) return -value; else return value;}
    //if(abs(q[1][k-1].v)>maxlong/10) {depth=k; if(turn%2==0) return -q[lasti][k-1].v; else return q[lasti][k-1].v;}
    for(int i=mxh-1;i<=mxt+1;i++)
    {
        for(int j=myh-1;j<=myt+1;j++)
        {
            if(inmap(i,j)==1)
            {
        if(turn%2==0) lmap[i][j]='x';
        else lmap[i][j]='o';
        //if(i==1) cout<<k<<" "<<q[i][k].x<<" "<<q[i][k].y<<endl;
        int lmxh=mxh,lmxt=mxt,lmyh=myh,lmyt=myt;
        mxh=min(i,mxh);
        mxt=max(i,mxt);
        myh=min(j,myh);
        myt=max(j,myt);
        long long val=-alphabeta2(k+1,-beta,-alpha,m,turn+1);
        lmap[i][j]='.';
        mxh=lmxh;
        mxt=lmxt;
        myh=lmyh;
        myt=lmyt;
        if(val>=beta)
        {
            return beta;
        }
        if(val>alpha)
        {
            //cout<<k<<" "<<q[i][k].x<<" "<<q[i][k].y<<" "<<val<<endl;
            alpha=val;
            if(k==1)
            {
                bx=i;
                by=j;
            }
        }
            }
        }
    }
    return alpha;
}
long long fiveq::minmax(int k,int lasti,int m,int mn,int turn)
{
    long long best=-maxlong*10;
    if(k>=depth) {if(turn%2==0) return -q[lasti][k-1].v; else return q[lasti][k-1].v;}
    //if(k%2==)
    if(abs(q[1][k-1].v)>maxlong/10) {if(turn%2==0) depth=k; return q[1][k-1].v;}
    int ben=zsort(q,k,mn,turn);
    for(int i=1;i<=ben;i++)
    {
        if(turn%2==0) lmap[q[i][k].x][q[i][k].y]='x';
        else lmap[q[i][k].x][q[i][k].y]='o';
        //if(i==1) cout<<k<<" "<<q[i][k].x<<" "<<q[i][k].y<<endl;
        int lmxh=mxh,lmxt=mxt,lmyh=myh,lmyt=myt;
        mxh=min(q[i][k].x,mxh);
        mxt=max(q[i][k].x,mxt);
        myh=min(q[i][k].y,myh);
        myt=max(q[i][k].y,myt);
        long long val=-minmax(k+1,i,m,mn,turn+1);
        lmap[q[i][k].x][q[i][k].y]='.';
        mxh=lmxh;
        mxt=lmxt;
        myh=lmyh;
        myt=lmyt;
        if(val>best)
        {
            cout<<k<<" "<<q[i][k].x<<" "<<q[i][k].y<<" "<<val<<endl;
            best=val;
            if(k==1)
            {
                bx=q[i][k].x;
                by=q[i][k].y;
            }
        }
    }
    return best;
}
void fiveq::PM()
{
    for(int i=1;i<=mmap;i++)
    {
        for(int j=1;j<=mmap;j++)
        {
            cout<<lmap[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
/****************************************************/
/**********************µÁƒ‘œ¬◊”**********************/
/****************************************************/
void fiveq::cplay()
{
    mxh=min(bx,mxh);
    mxt=max(bx,mxt);
    myh=min(by,myh);
    myt=max(by,myt);
    map[bx][by]='o';
    lmap[bx][by]='o';
    cvalue2();
    cout<<value<<endl;
}
void fiveq::firstcplay(int x)
{
    if(x==1)
    {
        bx=8;
        by=8;
    }
    if(x==2)
        while(1)
        {
            srand(time(NULL));
            bx=rand()%8;
            bx=lx+aa[bx];
            by=rand()%8;
            by=ly+bb[by];
            if(map[bx][by]=='.') break;
        }
}
/****************************************************/
/********************ÕÊº“œ¬◊”************************/
/****************************************************/
void fiveq::pplay()
{
lab1:
    cin>>x;
    cin>>y;
    lx=x;
    ly=y;
    if(inmap(x,y)==1) {map[x][y]='x'; lmap[x][y]=map[x][y];}
    else {cout<<"¥À¥¶≤ªø…œ¬∆Â£¨«Î÷ÿ–¬ ‰»Î"<<endl; goto lab1;}
}
void fiveq::iospplay(int x,int y)
{
    lx=x;
    ly=y;
    mxh=min(lx,mxh);
    mxt=max(lx,mxt);
    myh=min(ly,myh);
    myt=max(ly,myt);
    map[x][y]='x';
    lmap[x][y]='x';
}
/****************************************************/
/*******************≈–∂œ ‰”Æµƒ∫Ø ˝*******************/
/****************************************************/
int fiveq::win()
{
    for(int i=1;i<=mmap;i++)
    {
        for(int j=1;j<=mmap;j++)
        {
            if((map[i][j]==map[i+1][j+1])&&(map[i][j]==map[i+2][j+2])&&(map[i][j]==map[i+3][j+3])&&(map[i][j]==map[i+4][j+4])&&(map[i][j]=='x'))
            {
                return 1;
            }
            else if(map[i][j]==map[i+1][j]&&map[i][j]==map[i+2][j]&&map[i][j]==map[i+3][j]&&map[i][j]==map[i+4][j]&&map[i][j]=='x')
            {
                return 1;
            }
            else if(map[i][j]==map[i][j+1]&&map[i][j]==map[i][j+2]&&map[i][j]==map[i][j+3]&&map[i][j]==map[i][j+4]&&map[i][j]=='x')
            {
                return 1;
            }
            else if(map[i][j]==map[i-1][j+1]&&map[i][j]==map[i-2][j+2]&&map[i][j]==map[i-3][j+3]&&map[i][j]==map[i-4][j+4]&&map[i][j]=='x')
            {
                return 1;
            }
        }
    }
    for(int i=1;i<=mmap;i++)
    {
        for(int j=1;j<=mmap;j++)
        {
            if((map[i][j]==map[i+1][j+1])&&(map[i][j]==map[i+2][j+2])&&(map[i][j]==map[i+3][j+3])&&(map[i][j]==map[i+4][j+4])&&(map[i][j]=='o'))
            {
                return 2;
            }
            else if(map[i][j]==map[i+1][j]&&map[i][j]==map[i+2][j]&&map[i][j]==map[i+3][j]&&map[i][j]==map[i+4][j]&&map[i][j]=='o')
            {
                return 2;
            }
            else if(map[i][j]==map[i][j+1]&&map[i][j]==map[i][j+2]&&map[i][j]==map[i][j+3]&&map[i][j]==map[i][j+4]&&map[i][j]=='o')
            {
                return 2;
            }
            else if(map[i][j]==map[i-1][j+1]&&map[i][j]==map[i-2][j+2]&&map[i][j]==map[i-3][j+3]&&map[i][j]==map[i-4][j+4]&&map[i][j]=='o')
            {
                return 2;
            }
        }
    }
    return 0;
}
/*
int main()
{
    freopen("fiveq.in","r",stdin);
    fiveq a;
    for(int k=1;k<=9;k++)
    {
        for(int i=1;i<=mmap;i++)
        {
            for(int j=1;j<=mmap;j++)
            {
                cin>>a.lmap[i][j];
            }
        }
        a.cvalue2();
        cout<<a.value<<endl;
    }
    return 0;
}*/