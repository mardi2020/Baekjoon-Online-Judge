#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;
const int INF = 987654321;
int E, V, K;
vector<pair<int, int>> adj[20001]; // 간선 정보

vector<int> Dijkstra(int start){
    vector<int> dist(V+1, INF); // 최소 비용
    dist[start] = 0;
    priority_queue<pair<int, int>> pq; // <정점번호, 간선의 가중치>
    pq.push(make_pair(0, start));
    
    while(!pq.empty()){
        int distance = -pq.top().first;
        int current = pq.top().second; // 짧은 것이 먼저 오게 음수로
        pq.pop();

        if(dist[current] < distance) // 지금 꺼낸 것보다 더 짧은 경로를 안다면 지금 꺼낸것을 무시함
            continue;
        
        for(int i = 0; i < adj[current].size();i++){
            // 선택된 노드를 인접 노드로 거쳐서 가능 비용
            int nextDistance = distance + adj[current][i].first;
            // 인접 노드
            int next = adj[current][i].second;
            
            // 기존의 짧은 경로보다 더 짧다면 갱신
            if(dist[next] > nextDistance){
                dist[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
    return dist;
}


int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);cout.tie(NULL);
    
    cin>>V>>E; // 정점의 개수, 간선의 개수
    cin>>K; // 시작 정점의 번호
    
    while(E--){
        int u, v, w; // u에서 v로 가는 가중치 w인 간선이 존재
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(w, v));
    }
    vector<int> Distance = Dijkstra(K);
    
    for(int i = 1; i <= V; i++){
        if(Distance[i] == INF)
            cout<<"INF"<<endl;
        else
            cout<<Distance[i]<<endl;
    }
    return 0;
}

/*
 Dijkstra Algorithm 은 BFS와 유사함. 시작점에서 가까운 순서대로 정점을 방문
 이 알고리즘은 BFS와 달리, 우선순위 큐에 정점의 번호화 함께 지금까지 찾아낸 해당 정점까지의 최단 거리를 pair로 넣음
 우선순위 큐는 정점까지의 최단거리를 기준으로 정점을 배열함, 아직 방문하지 않은 정점 중 시작점으로부터의 거리가 가장 가까운 점을 찾게 함
 최단 경로가 갱신될 수가 있음
 */
