//
//  main.cpp
//  7562 나이트의 이동
//
//  Created by Emma on 2020/02/22.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int chess[301][301];
int visited[301][301];
int l;
int u, v;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == u and y == v){
            cout<<visited[x][y]<<'\n';
            break;
        }
        
        for(int i = 0; i < 8; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(0 <= newX and newX < l and 0 <= newY and newY < l){
                if(!visited[newX][newY]){
                    visited[newX][newY] = visited[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }
}
int main(){
    int T; cin>>T;
    while(T--){
        cin>>l; // 한 변의 길이
        memset(chess, 0, sizeof(chess));
        memset(visited, 0, sizeof(visited));
        int x, y; cin>>x>>y; // 시작지점
        cin>>u>>v; // 도착지점
        BFS(x, y);
        
    }
}
