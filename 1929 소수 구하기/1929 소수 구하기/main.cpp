//
//  main.cpp
//  1929 소수 구하기
//
//  Created by Emma on 2020/02/09.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
#define endl "\n"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int M, N; cin>>M>>N;
    if(M == 1)
        M++;
    
    for(;M <= N; M++){
        bool flag = true;
        for(int i = 2; i <= sqrt(M); i++){
            if(M % i == 0){
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<M<<endl;
    }
}


