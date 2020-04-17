//
//  main.cpp
//  4963 섬의개수
//
//  Created by Emma on 2020/02/03.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <cstring> // memset
using namespace std;
#define endl "\n"
int w, h; // 너비와 높이
int map[51][51];
bool visit[51][51];
int shima = 0;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}; // 8가지 방향 상하좌우대각선

void dfs(int x, int y){
    visit[x][y] = true;
    for(int i = 0 ; i < 8; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if ((0 <= newX && newX < h) && (0 <= newY && newY < w)){
            if(!visit[newX][newY] && map[newX][newY]){
                dfs(newX, newY);
            }
        }
        
    }
}
void Init(){
    memset(map, 0, sizeof(map));
    memset(visit, false, sizeof(visit));
    shima = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin>>w>>h;
        if(w == 0 && h == 0)
            return 0;
        Init();
        
        // 지도( 1은 땅, 0은 바다 )
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                cin>>map[i][j];
            }
        }
        
        for(int row = 0 ; row < h ; row++){
            for(int col = 0 ; col < w; col++){
                if(!visit[row][col] and map[row][col]){
                    dfs(row, col);
                    shima++;
                }
            }
        }
        cout<<shima<<endl;
    }
    
}

// input : 지도
// output : 섬의 개수
