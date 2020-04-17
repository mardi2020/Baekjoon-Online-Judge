#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, V;
vector<bool> Check;
vector<vector<int>> Graph; //adj[i]는 정점 i와 간선을 통해 연결된 정점들의 번호를 저장하는 연결 리스트

void DFS(int x){ // recursion
    Check[x] = true;
    cout<<x<<' ';
    for(int i = 0 ; i < Graph[x].size(); i++){
        int next = Graph[x][i];
        if(!Check[next])
            DFS(next);
    }
}

void BFS(int x){ // queue
    queue<int> q; // 방문할 정점 목록
    q.push(x);
    Check[x] = true;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        
        cout<<here<<' ';
        for(int i = 0 ; i < Graph[here].size();i++){
            int next = Graph[here][i];
            if(!Check[next]){
                q.push(next);
                Check[next] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M>>V;
    
    Graph.resize(N+1);
    Check.resize(N+1, false);
    
    while(M--){
        int a, b; cin>>a>>b;
        // a와 b를 연결 시켜야함
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    // 정점의 번호가 가장 작은 것부터 방문
    for(int i = 1; i <= N; i++)
        sort(Graph[i].begin(), Graph[i].end());

    DFS(V);
    cout<<endl;
    Check.assign(N+1, false);
    BFS(V);
}

// Input : N(정점의 개수), M(간선의 개수), V(탐색을 시작할 정점의 번호)
// Output : DFS의 결과, BFS의 결과
