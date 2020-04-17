//
//  main.cpp
//  13913 숨바꼭질 4
//
//  Created by Emma on 2020/02/23.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXSIZE 100001
int N, K;
int check[MAXSIZE];
queue<pair<int, int>> q;
vector<int> tmp;


void BFS(int x, int times = 0){
    q.push({x, times});
    check[x] = true;
    int path[MAXSIZE] = {0,};
    
    while(!q.empty()){
        int x = q.front().first;
        int times = q.front().second;
        
        if(x == K){
            while(x != N){
                tmp.push_back(x);
                x = path[x];
            }
            tmp.push_back(N);
            return;
        }
        q.pop();
        
        // path에 전에 들렀던 번호 저장
        if(x-1 >= 0 and !check[x-1]){
            q.push({x-1, times+1});
            path[x-1] = x;
            check[x-1] = true;
        }
        if(x+1 < MAXSIZE and !check[x+1]){
            q.push({x+1, times+1});
            path[x+1] = x;
            check[x+1] = true;
        }
        if(2*x < MAXSIZE and !check[2*x]){
            q.push({2*x, times+1});
            path[2*x] = x;
            check[2*x] = true;
        }
    }
}
int main() {
    cin>>N>>K;
    
    BFS(N);

    cout<<q.front().second<<'\n';

    for(int i = (int)tmp.size()-1 ; i >= 0;i--){
        cout<<tmp[i]<<' ';
    }
    
}
