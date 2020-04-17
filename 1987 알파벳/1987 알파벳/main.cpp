//
//  main.cpp
//  1987 알파벳
//
//  Created by Emma on 2020/02/14.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
using namespace std;
int R, C;
int maxvalue = 1;
char map[21][21];
bool visited[26];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void DFS(int x, int y, int cnt){
    if(cnt > maxvalue)
        maxvalue = cnt;
    
    for(int i = 0; i < 4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if(0 <= newX and newX < R and 0 <= newY and newY < C){
            if(!visited[map[newX][newY]-65]){
                visited[map[newX][newY]-65] = true;
                DFS(newX, newY, cnt+1);
                visited[map[newX][newY]-65] = false;
            }
        }
    }
}

int main() {
    cin>>R>>C;
    
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin>>map[i][j];
    
    visited[map[0][0]-65] = true;
    DFS(0, 0, maxvalue);
    cout<<maxvalue<<endl;
    
}
