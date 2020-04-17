//
//  main.cpp
//  2468 안전 영역
//
//  Created by Emma on 2020/02/04.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int map[101][101];
int visited[101][101] = {0,};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void DFS(int x, int y, int height){
    visited[x][y] = true;
    for(int i = 0 ; i < 4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if(0 <= newX and newX < N and 0 <= newY and newY < N){
            if(!visited[newX][newY] && map[newX][newY] > height){
                DFS(newX, newY, height);
            }
        }
    }
}
void Init(int& cnt){
    cnt = 0;
    memset(visited, false, sizeof(visited));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    int Min = 987654321; int Max = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
            Max = max(Max, map[i][j]);
            Min = min(Min, map[i][j]);
        }
    }
    
    int result = 1;
    for(int height = Min; height < Max; height++){
        int cnt; Init(cnt); // 재사용
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ;j < N; j++){
                if(!visited[i][j] && map[i][j] > height){
                    cnt++;
                    DFS(i, j, height);
                }
            }
        }
        result = max(result, cnt);
    }
    cout<<result;
    
}
