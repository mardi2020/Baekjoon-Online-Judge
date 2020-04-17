//
//  main.cpp
//  6603 로또
//
//  Created by Emma on 2020/02/03.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int k;
vector<int> S;
vector<int> v1;

void solution(int x, int StartIdx){
    if(x == 6){
        for(int i = 0; i < 6; i++)
            cout<<v1[i]<<' ';
        cout<<endl;
        return;
    }
    int IsUsed[51] ={0,};
    for(int i = StartIdx ; i < k; i++){
        if(!IsUsed[S[i]]){
            v1[x] = S[i];
            IsUsed[S[i]] = true;
            solution(x+1, i+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        cin>>k;
        if(!k)
            return 0;
        
        S.resize(k, 0);
        for(int i = 0 ;i < k; i++)
            cin>>S[i];
        
        v1.resize(k-1);
        solution(0, 0);
        cout<<endl;
    }
}
