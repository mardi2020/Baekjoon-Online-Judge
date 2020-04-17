//
//  main.cpp
//  2589 보물섬
//
//  Created by Emma on 2020/02/23.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int R, C;
int map[51][51];
int visited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int ans = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            ans = max(ans, visited[x][y]);
            if(0 <= nx and nx < R and 0 <= ny and ny < C){
                if(!visited[nx][ny] and !map[nx][ny]){
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return ans-1;
}

int main() {
    cin>>R>>C;
    for(int i = 0 ; i < R;i++){
        for(int j = 0; j < C;j++){
            char a; cin>>a;
            if(a == 'W')
                map[i][j] = 1;
            else if(a == 'L')
                map[i][j] = 0;
            
        }
    }
    int ans = 0;
    for(int i = 0;i < R;i++){
        for(int j = 0; j < C;j++){
            if(!map[i][j]){ // 육지
                memset(visited, false, sizeof(visited));
                ans = max(ans, BFS(i, j));
            }
        }
    }
    cout<<ans;
}
