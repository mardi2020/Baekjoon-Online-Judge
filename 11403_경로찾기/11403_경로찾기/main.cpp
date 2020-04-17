#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;
int N, cnt = 0;
vector<int> v1[101];
int visited[101];
int ans[101][101];

void bfs(int start, int end){
    queue<int> myque;
    myque.push(start);
    
    while(!myque.empty()){
        int here = myque.front();
        myque.pop();
        
        if(here == end && cnt != 0){
            ans[start][end] = 1;
            break;
        }
        
        for(int i = 0 ; i < v1[here].size();i++){
            int next = v1[here][i];
            if(!visited[next]){
                cnt++;
                visited[next] = true;
                myque.push(next);
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    memset(ans, 0, sizeof(ans));
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            int x; cin>>x;
            if(x)
                v1[i].push_back(j);
        }
    }

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            memset(visited, false, sizeof(visited));
            cnt = 0; // 대각원소가 바로 1되는거 방지
            bfs(i, j);
        }
    }
    
    // 출력
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++)
            cout<<ans[i][j]<<' ';
        cout<<endl;
    }
}

