#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"
int N, M;
vector<int> v1;
vector<int> v2;
vector<bool> IsUsed;

void Solution(int x){
    if(x == M){
        for(auto e:v1)
            cout<<e<<' ';
        cout<<endl;
        return;
    }
    for(int i = 0 ; i < N; i++){ // v2에서 숫자 꺼내오기
        if(!IsUsed[i]){
            v1[x] = v2[i];
            IsUsed[i] = true;
            Solution(x+1);
            IsUsed[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>N>>M;
    v1.resize(M);
    v2.resize(N);
    IsUsed.resize(10001, false); //  사용한 숫자 체크
    
    for(int i = 0 ; i < N; i++)
        cin>>v2[i];
    
    sort(v2.begin(), v2.end());
    Solution(0);
    
}
