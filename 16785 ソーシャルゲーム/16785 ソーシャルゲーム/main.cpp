//
//  main.cpp
//  16785 ソーシャルゲーム
//
//  Created by Emma on 2020/02/05.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B, C; // A : 로그인시 받는 코인 수, B : 7일 연속 로그인할떄 추가로 받는 코인, C : 받고 싶은 코인의 수
    cin>>A>>B>>C;
    
    int coin = 0;
    for(int i = 1; i <= C ; i++){
        coin += A;
        if(i % 7 == 0) // 일주일 연속 출석할 경우
            coin+= B;
        if(C <= coin){
            cout<<i<<endl;
            return 0;
        }
    }
}

