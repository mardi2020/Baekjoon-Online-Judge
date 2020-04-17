//
//  main.cpp
//  2960 에라토스테네스의 체
//
//  Created by Emma on 2020/02/06.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
#define endl "\n"
int isPrime[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin>>N>>K;
    
    int cnt = 0;
    memset(isPrime, true, sizeof(isPrime));
    int num = 0;
    for(int i = 2; i <= N; i++){
        if(isPrime[i]){
            cnt++;
            isPrime[i] = false;
//            cout<<"i : "<<i<<" cnt : "<<cnt<<endl;
            if(cnt == K){
                num = i;
            }
        }
        for(int j = i * 2; j <= N; j+=i){
            if(isPrime[j]){
                cnt++;
                isPrime[j] = false;
//                cout<<"j : "<<j<<" cnt : "<<cnt<<endl;
                if(cnt == K){
                    num = j;
                }
            }
        }
    }
    cout<<num<<endl;
}
