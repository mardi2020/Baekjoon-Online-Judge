//
//  main.cpp
//  1543 문서 검색
//
//  Created by Emma on 2020/02/09.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#define endl "\n"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str; getline(cin, str);
    string word; getline(cin, word);
    
    if(str.size() < word.size()){
        cout<<0<<endl;
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i< str.size() - word.size() + 1; i++){
        bool flag = true;
        for(int j = 0; j < word.size();j++){
            if(str[i+j] != word[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            cnt++;
            i += word.size() - 1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
