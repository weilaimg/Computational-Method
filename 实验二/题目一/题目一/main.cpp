//
//  main.cpp
//  题目一
//
//  Created by WeiLai’s Macbook Pro on 2017/4/6.
//  Copyright © 2017年 WeiLai’s Macbook Pro. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

#define N 4  //方程初始阶数

//--------增广矩阵的初始数据------
static double
/*
aa[N][N+1]{
    {  1,-1,1,-4,2},
    {  5,-4,3,12,4},
    {  2,1,1,11,3},
    {  2,-1,7,-1,0}
};
*/

 aa[N][N+1]{
 {  0.3E-15,59.14,3,1,59.17},
 {  5.291,-6.130,.1,2,46.78},
 {  11.2,9,5,2,1},
 {  1,2,1,1,2}
 };


int gauss (double a[][N+2],double x[]);   //高斯消去法
int PartialPivot(double a[][N+2],double x[]);
void putout (double a[][N+2]);            //输出增广矩阵

int main(){
    int i,j,det;
    double a[N+1][N+2],x[N+1];
    for ( i = 1 ; i <= N ; i++)
        for ( j = 1 ; j<= N+1 ; j++)
            a[i][j] = aa[i-1][j-1];             //用a数组存放增广矩阵
    //det = gauss (a,x);                          //调用gauss求解方程，并获取返回标志
    det = PartialPivot(a,x);                    //调用列主元消去法求解方程，并获取返回标志
    if(det != 0)
        for( i = 1 ; i <= N ; i++)
            cout << "x[" << i <<"] = "<<x[i] << "    ";
    putchar('\n');
    return 0;
}

int gauss (double a[][N+2],double x[]){
    int i,j,k;
    double c;
    putout (a);
    for ( k = 1 ; k <= N-1 ; k++){
        if( fabs(a[k][k]) < 1E-17){
            cout << "\n pivot element is 0.fail! "<<endl;
            return 0;
        }
        for ( i = k+1 ; i <= N ; i++){
            c = a[i][k] / a[k][k];
            for ( j = k ; j <= N+1 ; j++)
                a[i][j] = a[i][j] - c*a[k][j];
        }
        putout (a);
    }
    if( fabs(a[N][N]) < 1E-17){
        cout << "\n pivot element is 0.fail! "<<endl;
        return 0;
    }
    for ( k = N ; k >= 1 ; k--){
        x[k] = a[k][N+1];
        for ( j = k+1 ; j<= N ; j++){
            x[k] = x[k]-a[k][j]*x[j];
        }
        x[k] = x[k]/a[k][k];
    }
    return 1;
}

int PartialPivot(double a[][N+2],double x[]){
    int i,j,k,r;
    double c;
    putout (a);
    for ( k = 1 ; k <= N ; k++){
        r = k;
        for ( i = k ; i <= N ; i ++)
            if( fabs(a[i][k]) > fabs(a[r][k]))
                r = i;
        if( fabs(a[r][k]) < 1E-17){
            cout << "\n pivot element is 0.fail! "<<endl;
            return 0;
        }
        if (r != k )
            for ( j = k ; j <= N+1 ; j++){
                c = a[k][j];
                a[k][j] = a[r][j];
                a[r][j] = c;
            }
        for ( i = k+1 ; i <= N ; i++){
            c = a[i][k]/a[k][k];
            for(j = k ; j <= N+1 ; j++){
                a[i][j] = a[i][j] - c*a[k][j];
            }
        }
        putout(a);
    }
    if( fabs(a[N][N]) < 1E-17){
        cout << "\n pivot element is 0.fail! "<<endl;
        return 0;
    }
    for ( k = N ; k >= 1 ; k--){
        x[k] = a[k][N+1];
        for (j = k+1 ; j <= N ; j++){
            x[k] = x[k] - a[k][j]*x[j];
        }
        x[k] = x[k] / a[k][k];
    }
    return 1;
}


void putout (double a [][N+2]){
    for (int i = 1 ; i <= N ; i++){
        for (int j=1 ; j<= N+1 ; j++)
            printf ("%15g",a[i][j]);
        printf("\n");
    }
    printf ("\n");
}