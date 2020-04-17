#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;
int N, M;
vector<int> v1;
vector<int> v2;
vector<bool> check;

void Solution(int x, int StartIdx){
    if(x == M){
        for(int e:v2){
            cout<<e<<' ';
        }cout<<endl;
        return;
    }
    for(int i = StartIdx ; i < N ; i++){
        if(!check[i]){
            v2[x] = v1[i];
            check[i] = true;
            Solution(x+1, i+1);
            check[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    // 수열은 오름차순
    v1.resize(N);
    for(int i = 0 ; i < N ; i++)
        cin>>v1[i];
    
    sort(v1.begin(), v1.end());
    v2.resize(M, 0);
    check.resize(N, false);
    Solution(0, 0);
}
