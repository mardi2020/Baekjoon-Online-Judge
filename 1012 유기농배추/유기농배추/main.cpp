#include <iostream>
using namespace std;
int M, N, K;
int land[51][51];
int check[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y){
    check[x][y] = true;
    
    for(int i = 0 ; i < 4 ; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if((0 <= newX && newX < N) && (0 <= newY && newY < M)){
            if(land[newX][newY]  && check[newX][newY] == false){
                DFS(newX, newY);
            }
        }
    }
}
void Init(){
    for(int i =0;i<N;i++){
        for(int j=0;j<M;j++){
            land[i][j] = 0;
            check[i][j] = 0;
        }
    }
}
int main(){
    // 테스트 케이스
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin>>T;
    
    while(T--){
        // row M, col N
        cin>>M>>N>>K;
        
        Init();
        
        // 배추가 있는 좌표 K개 입력
        for(int i = 0; i < K;i++){
            int x, y; cin>>x>>y;
            land[y][x] = 1; /* !! */
        }
        
        int cabbage_worm = 0;
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < M; j++){
                if(land[i][j] && check[i][j] == false){
                    DFS(i, j);
                    cabbage_worm++;
                }
            }
        }
        cout<<cabbage_worm<<endl;
    }
    return 0;
}
