#include <iostream>
#include <vector>
using namespace std;

vector<int> v1[1001];
bool visit[1001];


void dfs(int start){
    visit[start] = true;

    for(int i = 0 ; i < v1[start].size(); i++){
        int next = v1[start][i];
        if(visit[next] ==  false)
            dfs(next);
    }
}

int main(){
    int N, M;
    cin>>N>>M;
    int result = 0;
    for(int i = 0 ; i < M ; i++){
        int u, v; cin>>u>>v;
        v1[u].push_back(v);
        v1[v].push_back(u);
    }

    for(int i = 1 ; i <= N;i++){
        if(visit[i] == false){
            dfs(i);
            result++;
        }
    }
    cout<<result<<endl;
}


