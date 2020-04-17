#include <iostream>
using namespace std;
int p[100001];
int G; // 게이트 수
int P; // 공항에 도착할 비행기 수

int Find(int x){
    if(x == p[x])
        return x;
    else
        return p[x] = Find(p[x]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>G>>P;
    
    for(int i = 1; i <= G; i++)
        p[i] = i; // 초기화
    
    int sum = 0;
    for(int i = 1; i <= P; i++){
        int x; cin>>x;
        if(Find(x) == 0)
            break;
        sum++;
        p[Find(x)] = Find(x) - 1; //
    }
    cout<<sum<<endl;
}
