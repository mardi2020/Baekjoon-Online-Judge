//
//  main.cpp
//  1002 터렛
//
//  Created by Emma on 2020/02/10.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int x1, y1, r1, x2, y2, r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;

        double d = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
        
        if(d <= max(r1, r2)){ // 원 안의 원이 있을 때
            if(x1 == x2 && y1 == y2 && r1 == r2) // 같은 원 (류재명이 있을 수 있는 위치가 무한개일 경우)
                cout<<-1<<endl;
            else if (d + min(r1, r2) < max(r1, r2))
                cout<<0<<endl;
            else if (d + min(r1, r2) == max(r1, r2))
                cout<<1<<endl;
            else if (d + min(r1, r2) > max(r1, r2))
                cout<<2<<endl;
        }else{ // 원 밖에 있을 떄
            if(d > max(r1, r2) + min(r1, r2))
                cout<<0<<endl;
            else if(d == max(r1, r2) + min(r1, r2))
                cout<<1<<endl;
            else if(d < max(r1, r2) + min(r1, r2))
                cout<<2<<endl;
        }
    }
}
    
