//
//  main.cpp
//  2775 부녀회장이 될테야
//
//  Created by Emma on 2020/02/11.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
#define endl "\n"
int apartment[15][15];

void Init(){
    for(int i = 0; i < 15; i++){ // 층
        for(int j = 1; j < 15; j++){ //호
            if(i == 0)
                apartment[i][j] = j;
            else{
                apartment[i][j] = apartment[i][j-1] + apartment[i-1][j];
            }
            if(j == 1)
                apartment[i][j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin>>T;
    while(T--){
        int k; cin>>k;
        int n; cin>>n;
        
        Init();
        cout<<apartment[k][n]<<endl;
    }
}
