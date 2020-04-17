#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int M, N; //  M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수
int box[1005][1005];
int check[1005][1005]={0,};
int tomato = 0, tomato_cnt = 0;
queue<pair<int,int>> myque;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y){
    check[x][y] = 1;
    while(!myque.empty()){
        x = myque.front().first;
        y = myque.front().second;
        myque.pop();
        for(int i = 0 ; i < 4;i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 and newX < N and newY >= 0 and newY < M){
                if(check[newX][newY] == 0 and box[newX][newY] == 0){
                    myque.push((make_pair(newX, newY)));
                    check[newX][newY] = check[x][y] + 1;
                    box[newX][newY] = 1; // 익은거 전파됨
                    tomato_cnt++;
                }
                else if (box[newX][newY] == -1 and check[newX][newY] == 0)
                    check[newX][newY] = -1;
            }
        } //end for statement
    } // end while statement
    
}
int main(){
    cin>>M>>N;
    for(int i = 0;i < N; i++){
        for(int j = 0;j < M;j++){
            cin>>box[i][j];
            
            if(box[i][j] == 1){
                myque.push(make_pair(i, j));
                check[i][j] = 1;
            }
            else if(box[i][j] == 0)
                tomato++;
        }
    }
    
    if(!myque.empty()) // 배열이 모두다 -1이거나 0이면 큐가 비어있으므로 조건을 추가해야함
        bfs(myque.front().first, myque.front().second);
    else{ // 큐가 비었다[0, -1]면 애초에 토마토 후숙 작업을 할 필요가 없음
        if(tomato)
            cout<<-1<<endl;
        else
            cout<<0<<endl;
        return 0;
    }
    
   

    if(tomato_cnt < tomato){// 다 익지 못함
        cout<<-1<<endl;
        return 0;
    }
    
    int date = 0;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M ; j++){
            if(check[i][j] > date)
                date = max(date, check[i][j]);
        }
    }
    cout<<date - 1<<endl;
    
}
