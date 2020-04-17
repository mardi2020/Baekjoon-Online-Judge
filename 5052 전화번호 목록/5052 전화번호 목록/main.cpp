//
//  main.cpp
//  5052 전화번호 목록
//
//  Created by Emma on 2020/02/03.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#define endl "\n"
using namespace std;

bool Hashing(vector<string> phone_book) {
    unordered_map<string, int> unmap;
    for(auto e: phone_book)
        unmap[e] = 1;
    
    for(int i = 0 ; i <phone_book.size();i++){
        string pnumber = "";
        for(int j = 0 ; j < phone_book[i].size();j++){
            pnumber += phone_book[i][j];
    
            if(pnumber != phone_book[i] && unmap[pnumber])
                return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n; cin>>n; //전화번호수
        vector<string> v1(n);
        for(int i = 0 ; i < n; i++)
            cin>>v1[i];
        
        if(Hashing(v1))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
