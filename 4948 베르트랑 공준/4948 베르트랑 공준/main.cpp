//
//  main.cpp
//  4948 베르트랑 공준
//
//  Created by Emma on 2020/02/09.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define endl "\n"
#define MAX 1000001
bool isPrime[MAX];

void Init(){
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i <= MAX; i++){
        for(int j = i * 2 ; j <= MAX;j+=i){
            if(isPrime[j])
                isPrime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Init();
    
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;
        int x = 2*n;
        n++;
        int cnt = 0;
        for(; n <= x; n++){
            if(isPrime[n]){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
