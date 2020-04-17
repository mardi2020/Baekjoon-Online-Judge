//
//  main.cpp
//  1159 농구 경기
//
//  Created by Emma on 2020/02/26.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int check[123];
char alpha[26];
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0, a = 'a'; i < 26; i++)
          alpha[i] = a++;
    for(int i = 0 ; i < N; i++){
        string str; cin>>str;
        for(int j = 0; j < 26; j++){
            if(str[0] == alpha[j]){
                check[alpha[j]]++;
            }
        }
    }
    bool flag = true;
    for(int i = 97; i < 123;i++){
        if(check[i] >= 5){
            printf("%c", i);
            flag = false;
        }
    }
    
    if(flag)
        cout<<"PREDAJA";
}
