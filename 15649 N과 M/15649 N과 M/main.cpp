#include <iostream>
#include <vector>
using namespace std;
#define endl "\n"
int N,M;
vector<int> v1;// M개의 숫자를 저장하는 배열
vector<bool> IsUsed;// 순서대로 1~N까지 숫자들이 사용되었다면 true

void Solution(int x){
    if(x == M){
        for(auto e:v1){
            cout<<e<<' ';
        }cout<<endl;
        return;
    }
    // v1에 M개의 숫자가 들어갈 때 까지
    for(int i = 1;i <= N;i++){
        if(!IsUsed[i]){ // 숫자 i가 아직 사용되지 않았다면
            v1[x] = i;
            IsUsed[i] = true; // 사용했으니까 true로
            Solution(x+1); // 그 다음 수로
            IsUsed[i] = false; // 다시 처음 상태로 되돌려줌
        }
    }
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin>>N>>M;
    
    v1.resize(M, 0);
    IsUsed.resize(N, false);
    Solution(0);
}


/* "가지치기"
 * Backtracking [되추적] : "배제"와 "풀이 시간의 단축"
 * " 유망하지 않으면 배제하고 부모노드로 되돌아가면서 풀이 시간이 단축된다."
 * <<스택을 사용하고 스택에 넣기 전에 유망성 검사를 한다>>
 */
