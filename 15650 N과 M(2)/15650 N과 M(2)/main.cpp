#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
int N, M;
vector<int> v1;
vector<bool> IsUsed;

void Solution(int x, int StartIdx){
    if(x == M){
        for(auto e: v1){
            cout<<e<<' ';
        }cout<<endl;
        return;
    }
    for(int i = StartIdx ; i <= N; i++){
        if(!IsUsed[i]){
            v1[x] = i;
            IsUsed[i] = true;
            Solution(x+1, i+1);
            IsUsed[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin>>N>>M;
    v1.resize(M, 0);
    IsUsed.resize(N, false);
    // 수열은 오름차순이어야 한다.
    Solution(0, 1);
}
