//
//  main.cpp
//  14940 쉬운 최단거리
//
//  Created by Emma on 2020/02/20.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int N, M;
int map[1001][1001];
int check[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4;i++){
            int newX = nx + dx[i];
            int newY = ny + dy[i];
            
            if(0 <= newX and newX < N and 0 <= newY and newY < M){
                if(!check[newX][newY] and map[newX][newY]){
                    check[newX][newY] = check[nx][ny] + 1;
                    q.push({newX, newY});
                }
                
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int u = 0, v = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>map[i][j];
            if(!map[i][j]) { // 벽
                map[i][j] = -3;
                check[i][j] = -3;
            }
            if(map[i][j] == 2){
                u = i; v = j;
            }
        }
    }
    BFS(u, v);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(check[i][j] == -3)
                check[i][j] = 0;
            else if (check[i][j] == 0)
                check[i][j] = -1;
        }
    }
    check[u][v] = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout<<check[i][j]<<' ';
        }cout<<endl;
    }
}
