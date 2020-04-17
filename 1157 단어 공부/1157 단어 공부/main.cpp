//
//  main.cpp
//  1157 단어 공부
//
//  Created by Emma on 2020/02/10.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str; cin>>str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    
    int arr[26], temp[26]={0,};
    for(int i = 0,a = 'A'; i < 26; i++)
        arr[i] = a++;
    
    
    for(int i = 0; i < str.length();i++){
        for(int j = 0; j < 26; j++){
            if(str[i] == arr[j])
                temp[j]++;
        }
    }
    int max = 0;
    for(int i = 0; i < 26; i++){
        if (max < temp[i]){
            max = temp[i];
        }
    }
    int cnt = 0; int x = 0;
    for(int i = 0; i < 26; i++){
        if (max == temp[i]){
            x = arr[i];
            cnt++;
        }
    }
    if(cnt > 1){
        cout<<'?'<<endl;
        return 0;
    }
    else if(cnt == 1){
        printf("%c\n", x);
        return 0;
    }
}
