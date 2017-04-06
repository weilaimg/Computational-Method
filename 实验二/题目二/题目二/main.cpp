//
//  main.cpp
//  题目二
//
//  Created by WeiLai’s Macbook Pro on 2017/4/6.
//  Copyright © 2017年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

#define N 3                          // 方程组的阶数
#define EPS 0.5E-6                   // 精度要求
static double

aa[N][N] = {
    {6,2,-1},
    {1,4,-2},
    {-3,1,4}
};
static double bb[N]={100,-200,345};

int main(){
    int i,j,k,NO;
    double a[N+1][N+1],b[N+1],x[N+1],y[N+1];
    double d,sum,max;
    for( i = 1 ; i <= N ; i++){
        for ( j = 1 ; j <= N ; j++)
            a[i][j] = aa[i-1][j-1];
        b[i] = bb[i-1];
    }
    cout << "\n Please Enter No:";
    cin >> NO;
    for ( i = 1 ; i <= N ; i++)
        x[i] =1;
    k = 0;
    printf("       k");
    for ( i = 1 ; i <= N ; i++)
        printf("%8cx[%d]",' ',i);
    printf ("\n       0");
    for ( i = 1 ; i <= N ; i++)
        printf("%12.8g",x[i]);
    printf("\n");
    do{
        for( i = 1 ; i <= N ; i++){
            sum = 0.0;
            for ( j = 1 ; j <= N ; j++)
                if( j != i )
                    sum = sum + a[i][j] * x[j];
            y[i] = (-sum + b[i])/a[i][i];
        }
        max = 0.0;
        for ( i = 1 ; i<= N ; i++){
            d = fabs (y[i] - x[i]);
            if(max < d) max = d;
            x[i] = y[i];
        }
        printf ("%8d",k+1);
        for (i = 1 ; i <= N ; i++)
            printf("%12.8g",x[i]);
        printf("\n");
        k++;
    }while((max >= EPS)&&(k<NO));
    if( k > NO )
        cout << "\n  fail!  \n";
    else
        for ( i = 1 ; i <= N ; i++)
            printf("   x[%d]=%g",i,x[i]);
    cout << "\n";
    return 0;
}