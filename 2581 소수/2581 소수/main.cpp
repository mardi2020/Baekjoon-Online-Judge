//
//  main.cpp
//  2581 소수
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
    cin.tie(0);

    int M, N; cin>>M>>N;
    if (M == 1)
        M++;
    
    int minvalue = 10001; int sum = 0;
    for(int k = M; k <= N; k++){
        bool flag = true;
        if(k == 2)
            minvalue = k;
        
        for(int i = 2; i <= k/2;i++){
            if(k % i == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            if(minvalue > k)
                minvalue = k;
            sum += k;
        }
    }

    if(!sum)
        cout<<-1<<endl;
    else
        cout<<sum<<endl<<minvalue<<endl;

}

