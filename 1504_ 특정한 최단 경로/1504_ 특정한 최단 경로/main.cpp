#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;
int INF = 987654321;
int N, E,from, to, weight;
int u, v;
vector<pair<int,int>> adj[801];

int dijkstra(int x, int num){
    vector<int> dist(N+1, INF);
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, x));
    dist[x] = 0;
    while(!pq.empty()){
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        if(dist[current] < distance)
            continue;
        
        for(int i = 0 ; i < adj[current].size();i++){
            int next = adj[current][i].second;
            int nextDistance = distance + adj[current][i].first;
            if(nextDistance < dist[next]){
                dist[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
        
    }
    return dist[num];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>E; // 정점의 개수 N, 간선의 개수 E
    while (E--) {
        cin>>from>>to>>weight; // a 정점에서 b 정점까지 양방향 길이 존재하고, 그 거리가 c이다
        adj[from].push_back({weight, to});
        adj[to].push_back({weight, from});
    }
    
    cin>>u>>v; // 반드시 거쳐야 하는 정점 2개
    
    // 1부터 정점 N까지 가는 최단 거리
    int Dist1 = dijkstra(1, u) + dijkstra(u, v) + dijkstra(v, N);
    int Dist2 = dijkstra(1, v) + dijkstra(v, u) + dijkstra(u, N);
    int answer = min(Dist1, Dist2);
    if(answer >= INF or answer < 0){
        cout<<-1<<endl;
    }
    else{
        cout<<answer<<endl;
    }
    return 0;
}

/*
 * 특정한 최단 경로 ?
 * 임의로 주어진 두 정점은 반드시 통과해야 한다는 것
 * 한번 이동했던 정점, 간선을 다시 이동할 수 있지만 최단 경로여야 한다.
 */
