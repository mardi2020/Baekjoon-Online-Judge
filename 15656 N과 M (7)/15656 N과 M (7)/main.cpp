#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"
int N, M;
vector<int> v1;
vector<int> v2;

void Solution(int x){
    if(x == M){
        for(int e:v2)
            cout<<e<<' ';
        cout<<endl;
        return;
    }
    for(int i = 0 ; i < N; i++){
        v2[x] = v1[i];
        Solution(x+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    
    v1.resize(N);
    for(int i = 0 ; i < N ; i++)
        cin>>v1[i];
    sort(v1.begin(), v1.end());
    v2.resize(M);
    Solution(0);
}
