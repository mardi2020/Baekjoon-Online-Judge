#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> v1;
void Solution(int x, int StartIdx){
    if(x == M){
        for(auto e:v1){
            cout<<e<<' ';
        }cout<<endl;
        return;
    }
    for(int i = StartIdx; i <= N; i++){
        cout<<"v["<<x<<"] = "<<i<<endl;
        v1[x] = i;
        Solution(x+1, i);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    v1.resize(M, 0);
    // 중복 허용, 비내림차순이어야함 -> 오름차순이지만 중복도 되는 수열 출력하면됨
    Solution(0, 1);
}
