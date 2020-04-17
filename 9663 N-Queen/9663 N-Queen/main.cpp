#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int N, ans = 0;
vector<int> Col;

bool Promising(int idx){ // 유망한지 확인하는 함수
    // 해당 칸에 Queen을 배치할 수 있는지 여부를 검사
    for(int i = 0 ; i < idx; i++){
        // 같은 열이거나 대각선일경우 배치할 수가 없다
        if(Col[idx] == Col[i] || abs(Col[idx] - Col[i]) == idx - i)
            return false;
    }
    return true;
    // N번째 열까지 도달한 경우 완성된 체스판이므로 개수 카운트
    //  해당 열의 모든 칸에 퀸을 배치하면서 검사
}

void Queen(int x){
    if(x == N){
        ans++;
    }
    else{
        for(int i = 0; i < N; i++){ // 열에다 배치함
            Col[x] = i;
            if(Promising(x)){
                Queen(x+1);
            }
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N;
    Col.resize(N);
    Queen(0);
    
    cout<<ans<<endl;
}
/*
 행마다 한개 씩만 둘 수 있음 (퀸의 위치 이동때문에 당연한 것)
 같은 col에 "Queen"이 존재하는지 확인
 */
