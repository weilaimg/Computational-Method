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

#define x0 1.5                                //迭代初值
#define MAXREPT 10                            //迭代次数
#define G(x) x-(x*x*x-x-1)/(3*x*x-1)          //迭代函数

int main(){
    int i;
    double x_k = x0 ,x_k1 = x0;
    cout <<'k'<< '\t' << "xk"<<endl;
    for ( i = 0 ; i < MAXREPT ; i++){
        cout << i << '\t' << x_k1 << endl;
        x_k1 = G(x_k);
        x_k = x_k1;
    }
    cout << MAXREPT << "次迭代已完成"<<endl;
    return 0;
}