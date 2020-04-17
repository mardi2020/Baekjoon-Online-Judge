//
//  main.cpp
//  13023 ABCDE
//
//  Created by Emma on 2020/03/08.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m, ans;
vector<int> v1[2000];
int check[2000];

void Friend(int x, int cnt = 0){
    if(cnt == 4){
        ans = 1;
        return;
    }
    check[x] = true;
    for(int i = 0; i < v1[x].size();i++){
        int next = v1[x][i];
        if(!check[next])
            Friend(next, cnt + 1);
    }
    check[x] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    for(int i = 0; i < m;i++){
        int u, v; cin>>u>>v;
        v1[u].push_back(v);
        v1[v].push_back(u);
    }
    
    for(int i = 0; i < n;i++){
        memset(check, 0, sizeof(check));
        Friend(i);
        if(ans){
            cout<<1;
            return 0;
        }
    }
    cout<<0;
}
