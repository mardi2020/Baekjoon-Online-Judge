#include <iostream>
#include <queue>
#include <functional>
using namespace std;
#define endl "\n"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
    int N; cin>>N;
    
    while(N--){
        int x, y; cin>>x>>y;
        pq.push({x, y});
    }
    while(!pq.empty()){
        cout<<pq.top().first<<' '<<pq.top().second<<endl;
        pq.pop();
    }
    
}
