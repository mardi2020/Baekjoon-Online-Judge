//
//  main.cpp
//  10026 적록색약
//
//  Created by Emma on 2020/02/14.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N;
int cnt = 0;
char map[101][101];
char map2[101][101];
int visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void BFS(int x, int y, bool flag){
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    char color = map[x][y]; // 색깔
    char color2 = map2[x][y];
    
    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            
            if(0 <= newX and newX < N and 0 <= newY and newY < N and !visited[newX][newY]){
                if(flag){
                    if(map[newX][newY]==color){
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }else{
                    if(map2[newX][newY] == color2){
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
        }
    }
}

int main() {
    // R : 빨강, G : 초록, B: 파랑
    // 적록색약 : 빨강과 초록의 차이를 못느낌

    cin>>N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N;j++)
            cin>>map[i][j];
    memcpy(map2, map, sizeof(map));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N;j++){
            if(map2[i][j] == 'R')
                map2[i][j] = 'G';
        }
    }

    // 적록색약이 아닌 경우
    int cnt1 = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                BFS(i, j, 1);
                cnt1++;
            }
        }
    }
    // 적록색약인 경우
    memset(visited, 0, sizeof(visited)); // 초기화
    int cnt2 = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                BFS(i, j, 0);
                cnt2++;
            }
        }
    }
    cout<<cnt1<<' '<<cnt2<<endl;
}

