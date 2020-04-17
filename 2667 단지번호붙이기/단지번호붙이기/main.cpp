#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, cnt[400]={0,};
int complex = 0;
int arr[25][25];
bool visited[25][25];
int dx[4] ={-1, 1, 0, 0};
int dy[4] ={0, 0, -1, 1};


void dfs(int x, int y){
    visited[x][y] = true;
    cnt[complex]++;
    for(int i = 0; i < 4 ; i++){ // [x][y] 좌표 동 서 남 북 방향으로 이동
        int newX = x + dx[i];
        int newY = y + dy[i];

        if ((0 <= newX && newX < N) && (0 <= newY && newY < N) and arr[newX][newY]){ // 범위 안에서만 이동
            if (visited[newX][newY] == false){
                dfs(newX, newY);
            }
        }
    }
}



int main(){
    cin>>N;
    
    for(int row = 0 ; row < N ; row++)
        for(int col = 0 ; col < N; col++)
            scanf("%1d", &arr[row][col]);

    for(int row = 0 ; row < N ; row++){
        for(int col = 0 ; col < N; col++){
            if(visited[row][col] == false and arr[row][col]){
                dfs(row, col);
                complex++;
            }
        }
    }
    
    cout<<complex<<endl;
    sort(cnt, cnt+complex);
    for(int i = 0 ; i < complex ; i++)
        cout<<cnt[i]<<endl;
}
