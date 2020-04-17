//
//  main.cpp
//  9020 골드바흐의 추측
//
//  Created by Emma on 2020/02/09.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 10001
int Isprime[10001];

void Init(){
    memset(Isprime, true, sizeof(Isprime));
    for(int i = 2; i <= MAX; i++){
        for(int j = 2 * i ; j <= MAX; j+=i){
            if(Isprime[j])
                Isprime[j] = false;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n; cin>>n; 
        Init();
        
        for(int i = n/2 ; i > 0 ; i--) {
            if(Isprime[i] && Isprime[n-i]){
                cout<<i<<' '<<n-i<<endl;
                break;
            }
        }
    }
}
