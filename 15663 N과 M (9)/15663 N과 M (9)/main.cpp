#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, len;
vector<int> v1;
vector<int> v2;
vector<bool> check;

void Solution(int x){
    if(x == M){
        for(int e:v2)
            cout<<e<<' ';
        cout<<endl;
        return;
    }
    bool Usednum[1001]={0,};
    for(int i = 0 ; i < len; i++){
        if(!check[i] && !Usednum[v1[i]]){
            v2[x] = v1[i];
            check[i] = true;
            Usednum[v1[i]] = true;
            Solution(x+1);
            check[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    
    v1.resize(N);
    for(int i = 0 ; i < N; i++)
        cin>>v1[i];
    sort(v1.begin(), v1.end());
    
    len = (int)v1.size();
    
    v2.resize(M);
    check.resize(N);

    Solution(0);
}
