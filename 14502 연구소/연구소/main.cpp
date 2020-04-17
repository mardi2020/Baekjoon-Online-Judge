#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int safe = 0;
int map[9][9] = {0,};
int wall[9][9] = {0,};
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
vector<pair<int, int>> coordinate;

/* 벽을 세운후 바이러스를 퍼트림  : BFS */
void SpreadVirus(){
    queue<pair<int, int>> myque;
    for(auto e: coordinate)
        myque.push(e);
    
    while(!myque.empty()){
        int R = myque.front().first;
        int C = myque.front().second;
        myque.pop();
        
        for(int i = 0 ; i < 4 ;i++){
            int newR = R + dr[i];
            int newC = C + dc[i];
            
            if(0 <= newR and newR < N and 0 <= newC and newC < M){
                if(wall[newR][newC] == 0){
                    wall[newR][newC] = 2;
                    myque.push(make_pair(newR, newC));
                }

            }
        }
    }
}
void Init(){
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            wall[i][j] = map[i][j];
        
}

int CountSafeZone(){
    int after_safe = 0;
    for(int i = 0;i < N;i++)
        for(int j = 0 ;j < M;j++)
            if(wall[i][j] == 0)
                after_safe++;
    return after_safe;
}


void DFS(int StartIdx = 0, int cnt = 0){ // 기준
    if(cnt == 3){
        Init();
        SpreadVirus();
        int EachCase = CountSafeZone(); // 각 경우에 대해서 safe zone
        safe = max(safe, EachCase); // 더 큰수로 업데이트
        return;
    }
    for(int i = StartIdx; i < N*M;i++){ // --> 행별로
        int newR = i / M;
        int newC = i % M;
 
        if(map[newR][newC] == 0){
            map[newR][newC] = 1;
            DFS(StartIdx + 1, cnt + 1);
            map[newR][newC] = 0; //원상복귀
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    
    for(int i = 0 ; i < N;i++){
        for(int j = 0; j < M ;j++){
            cin>>map[i][j];
            if(map[i][j] == 2)
                coordinate.push_back(make_pair(i, j));
        }
    }
    DFS();
    
    cout<<safe<<endl;

    return 0;
    
}


