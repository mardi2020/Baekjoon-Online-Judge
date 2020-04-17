#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
int N, M;
vector<int> v1;

void Solution(int x){
    if(x == M){
        for(auto e: v1){
            cout<<e<<' ';
        }cout<<endl;
        return;
    }
    for(int i = 1; i<= N; i++){
        v1[x] = i;
        Solution(x+1);
    }
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    cin>>N>>M;
    v1.resize(M, 0);
    
    Solution(0); // 중복허용이므로 IsUsed 배열 필요가 업따
}
