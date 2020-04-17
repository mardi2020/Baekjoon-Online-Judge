#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int a, b;
int check[101]={0,};
vector<int> adj[101];

void BFS(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        
        if(here == b)
            break;
        
        for(int i = 0 ; i < adj[here].size(); i++){
            int next = adj[here][i];
            if(!check[next]){
                q.push(next);
                check[next] = check[here] + 1; //
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n; // 전체 사람의 수    
    cin>>a>>b; // 촌수를 계산해야 하는 서로 다른 두 사람의 번호
    cin>>m; // 부모 자식들 간의 관계의 개수
    
    while(m--){
        int x, y;
        cin>>x>>y; // x는 y의 부모 번호
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    BFS(a);
    if(!check[b]){
        cout<<-1<<endl;
        return 0;
    }
    cout<<check[b]<<endl;
    
    return 0;
}
