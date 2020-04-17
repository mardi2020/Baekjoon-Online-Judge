#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(){
    int T; cin>>T;
    for(int i = 0; i < T; i++){
        int N, M; cin>>N>>M; // 문서개수N, 알고싶은 문서의 위치M
        int count = 0;
        queue<pair<int, int>> que;
        priority_queue<int> pq; // 우선순위(큰게 젤 중요한거)
        for(int j = 0; j < N ; j++){
            int priority; cin>>priority;
            pair<int, int> p(priority, j); // 우선순위, 인덱스
            que.push(p);
            pq.push(priority);
        }
        int index, prior;
        while(que.size()){
            index = que.front().second;
            prior = que.front().first;
            que.pop();
            if(pq.top() == prior){
                ++count;
                pq.pop();
                if(index == M)
                    break;
            }
            else
                que.push({prior, index});
        }
        cout<<count<<endl;
    }
}
