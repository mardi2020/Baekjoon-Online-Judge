#include <iostream>
#include <cmath>
#include <limits.h>
#include <algorithm>
using namespace std;

int S[21][21];
int start[20];
int Start_Stats, Link_Stats, N;
int Min = INT_MAX; // limits.h , int형

void dfs(int Start_idx, int cnt){
    if(cnt == N/2){ // 능력치
        for(int i = 0; i < N; i++){
            if(start[i]){
                for(int j = i + 1; j < N; j++)
                    if(start[j])
                        Start_Stats = Start_Stats + S[j][i] + S[i][j];
            }
            else{
                for(int j = i + 1; j < N; j++)
                    if(!start[j])
                        Link_Stats = Link_Stats + S[j][i] + S[i][j];
            }
        }

        Min = min(Min, abs(Start_Stats - Link_Stats)); // 두 팀의 능력치 차가 가장 적은 걸로 갱신
        Start_Stats = 0; Link_Stats = 0;

        return;
    }

    for(int i = Start_idx + 1; i < N; i++){
        start[i] = 1;
        dfs(i, cnt+1);
        start[i] = 0; //원상복귀
    }
    return;
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            cin >> S[i][j];
        }

    for(int i = 0; i < N; i++){
        start[i] =  1;
        dfs(i, 1);
        start[i] = 0;
    }
    cout << Min <<endl;

}

