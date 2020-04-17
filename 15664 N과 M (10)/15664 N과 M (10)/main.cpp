#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
int N, M;
vector<int> v1;
vector<int> v2;


void Solution(int x, int StartIdx){
    if(x == M){
        for(int e: v2)
            cout<<e<<' ';
        cout<<endl;
        return;
    }
    int Usednum[1001] = {0,};
    for(int i = StartIdx ; i < N; i++){
        if(!Usednum[v1[i]]){
            v2[x] = v1[i];
            Usednum[v1[i]] = true;
            Solution(x+1, i+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    
    v1.resize(N);
    for(int i = 0; i<N;i++)
        cin>>v1[i];
    
    sort(v1.begin(), v1.end());
    v2.resize(M, 0);
    
    Solution(0, 0);
}
