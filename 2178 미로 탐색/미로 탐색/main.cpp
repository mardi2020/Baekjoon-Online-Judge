/* 미로 탐색 - BFS (Queue) */
#include <iostream>
#include <queue>
using namespace std;
int map[101][101]={0,};
int check[101][101]={0,};
queue<pair<int,int>> q;
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y){
    check[x][y] = 1;
    pair<int,int> p1(x, y);
    q.push(p1);
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4;i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            pair<int, int> p(newX, newY);
            
            if(newX >= 0 and newX < N and newY >= 0 and newY < M)
                if(check[newX][newY] == false and map[newX][newY]){
                    q.push(p);
                    check[newX][newY] = check[x][y] + 1;
                }
        }
    }
}


int main(){
    cin>>N>>M;
    
    // 배열에 "붙어서" 입력받기
    for(int i=0;i<N;i++)
        for(int j = 0;j<M;j++)
            scanf("%1d", &map[i][j]);
    
    bfs(0, 0);
    cout<<check[N-1][M-1];

}

