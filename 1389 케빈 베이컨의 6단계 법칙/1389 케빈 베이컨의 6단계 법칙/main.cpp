//
//  main.cpp
//  1389 케빈 베이컨의 6단계 법칙
//
//  Created by Emma on 2020/02/14.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
vector<int> graph[101];
int visited[101];

int BFS(int start, int end){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    
    while(!q.empty()){
        int here = q.front().first;
        int n = q.front().second;
        q.pop();
        
        if (here == end)
            return n;
        
        for(int i = 0; i < graph[here].size(); i++){
            int next = graph[here][i];
            if(!visited[next]){
                visited[next] = true;
                q.push({next, n+1});
            }
        }
    }
    return -1;
}

int main() {
    cin>>N>>M;
    while(M--){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int minvalue = 101, idx = 0;
    for(int start = 1; start <= N;start++){
        int sum = 0;
        for(int end = 1; end <= N; end++){
            memset(visited, 0, sizeof(visited));
            if(!visited[start] && start != end){
                sum += BFS(start, end);
            }
        }
        if(sum < minvalue){
            minvalue = sum;
            idx = start;
        }
    }

    cout<<idx<<endl;
}
