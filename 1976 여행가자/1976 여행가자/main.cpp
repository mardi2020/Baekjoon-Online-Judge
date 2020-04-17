#include <iostream>
using namespace std;
int p[201];
int path[1001] = {0,};

int Find(int x){ // 노드 x가 속해있는 집합의 루트를 반환
    if(p[x] == x)
        return x;
    else
        return p[x] = Find(p[x]);
    /*
     * find(x) == find(y)일때 x와 y는 같은 집합이고 다르면 다른 집합
     */
}
// 다른 집합에 있으면 Union을 통해 합치기
void Union(int x, int y){ // 노드 x가 속해 있는 집합과 노드 y가 속해있는 집합을 합침
    x = Find(x);
    y = Find(y);
    if(x < y)
        p[y] = x;
    else
        p[x] = y;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // N : 도시의 수
    // M : 여행 계획에 속한 도시들의 수
    int N, M;
    cin>>N>>M;
    
    for(int i = 1 ; i <= N; i++)
        p[i] = i;
    
    int map;
    // oper : 1이면 두 도시가 연결, 0이면 연결되지 않음
    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= N; j++){
            cin>>map;
            if(map){
                Union(i, j);
            }
        }
    }
    // 마지막줄 여행계획
    for(int i = 1; i <= M; i++)
        cin>>path[i];
    
    
    bool flag = true;
    for(int i = 1 ; i < M ; i++){
        if( Find(path[i]) != Find(path[i+1]) ){
            flag = false;
            break;
        }
    }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
