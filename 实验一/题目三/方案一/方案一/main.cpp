//
//  main.cpp
//  方案一
//
//  Created by WeiLai’s Macbook Pro on 2017/4/4.
//  Copyright © 2017年 WeiLai’s Macbook Pro. All rights reserved.
//


#include <iostream>
#include <math.h>
using namespace std;

#define MAXREPT 1000                                              //迭代次数
#define EPS 1E-6                                                  //求解精度
#define N_G(x) x-(x*x*x-sin(x)-12*x+1)/(2*x*x-cos(x)-12)          //牛顿迭代函数
#define R_G2(x) pow(x,1.0/3)                              //迭代函数
#define R_G1(x) (sin(x)+12*x-1);
int Newton (double & , int &);
int rept (double &x_k , int &i );

int main(){
    double x_k;
    int i;
    double x[6];
    int k[6];
    
    
    x_k = 3.5;
    Newton(x_k,i);
    x[0] = x_k;
    k[0] = i;
    
    x_k = 0;
    Newton(x_k,i);
    x[1] = x_k;
    k[1] = i;
    
    x_k = -3.5;
    Newton(x_k,i);
    x[2] = x_k;
    k[2] = i;
    
    x_k = -3.5;
    rept(x_k,i);
    x[3] = x_k;
    k[3] = i;
    
    x_k = 3.5;
    rept(x_k,i);
    x[4] = x_k;
    k[4] = i;
    cout << "初值为 2.5的牛顿迭代，共迭代了"<< k[0] << "次，方程的根为"<<x[0]<<endl;
    cout << "初值为 0.0的牛顿迭代，共迭代了 "<< k[1] << " 次，方程的根为"<<x[1]<<endl;
    cout << "初值为-2.5的牛顿迭代，共迭代了"<< k[2] << "次，方程的根为"<<x[2]<<endl;
    cout << '\n';
    cout << "初值为2.5的不动点迭代，共迭代了"<< k[4] << "次，方程的根为"<<x[4]<<endl;
    cout << "初值为-2.5的不动点迭代，共迭代了"<< k[3] << "次，方程的根为"<<x[3]<<endl;
}

int Newton (double &x_k , int &i){
    double x_k1 = x_k;
    cout <<'k'<< '\t' << "xk"<<endl;
    for ( i = 0 ; i < MAXREPT ; i++){
        cout << i << '\t' << x_k1 << endl;
        x_k1 = N_G(x_k);
        if(fabs( x_k1 - x_k) <EPS)
            return 0;
        x_k = x_k1;
    }
    return 0;
}

int rept (double &x_k , int &i ){
    double x_k1 = x_k;
    cout <<'k'<< '\t' << "xk"<<endl;
    for ( i = 0 ; i < MAXREPT ; i++){
        cout << i << '\t' << x_k1 << endl;
        
        x_k1 = R_G1(x_k);
        if( x_k1 < 0){
            x_k1 = -x_k1;
            x_k1 = R_G2(x_k1);
            x_k1 = -x_k1;
        } else
            x_k1 = R_G2(x_k1);
        
        if(fabs( x_k1 - x_k) <EPS)
            return 0;
        x_k = x_k1;
    }
    return 0;
}