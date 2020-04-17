//
//  main.cpp
//  2583 영역 구하기
//
//  Created by Emma on 2020/02/04.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int M, N, K;
int size[400] = {0,};
int map[101][101];
int visited[101][101] = {0,};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt = 0;

void DFS(int x, int y){
    visited[x][y] = true;
    size[cnt]++;
    
    for(int i = 0 ; i < 4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if(newX >= 0 && newX < M && newY >= 0 && newY < N){
            if(!map[newX][newY] && !visited[newX][newY])
                DFS(newX, newY);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N>>K;
    
    memset(map, 0, sizeof(map));
    memset(visited, false , sizeof(visited));
    
    while(K--){ // k개의 직사각형
        // 직사각형의 왼쪽 아래 꼭지점과 오른쪽 위 꼭지점
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        
        for(int i = y1; i < y2; i++)
            for(int j = x1; j < x2; j++)
                map[i][j] = 1;
        
    }
    
    for(int i = 0 ; i < M; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j] && !map[i][j]){ // 0인 영역 카운트
                DFS(i, j);
                cnt++;
            }
        }
    }
    
    cout<<cnt<<endl;
    sort(size, size+cnt);
    for(int i = 0 ;i < cnt;i++)
        cout<<size[i]<<' ';
    
}
