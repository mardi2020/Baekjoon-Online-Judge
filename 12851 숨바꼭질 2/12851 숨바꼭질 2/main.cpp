//
//  main.cpp
//  12851 숨바꼭질 2
//
//  Created by Emma on 2020/02/24.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAXSIZE 100001
int N, K, ans1, ans2;
int check[MAXSIZE];
queue<pair<int, int>> q;

void BFS(int x, int times = 0){
    q.push({x, times});
    check[x] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        int times = q.front().second;
        q.pop();
        check[x] = true;
        
        if(ans1 != 0 and ans1 < times)
            return;
        
        if(ans1 == times and x == K){ // 이미 목적지에 방문했을 경우
            ans2++;
            continue;
        }
        if(ans1 == 0 and x == K){ // 목적지에 처음 방문한 경우
            ans1 = times;
            ans2++;
        }
        if(x-1 >= 0 and !check[x-1]){
            q.push({x-1, times+1});
        }
        if(x+1 < MAXSIZE and !check[x+1]){
            q.push({x+1, times+1});
        }
        if(2*x < MAXSIZE and !check[2*x]){
            q.push({2*x, times+1});
        }
    }
}
int main() {
    cin>>N>>K;
    BFS(N);
    
    cout<<ans1<<'\n'<<ans2<<'\n';
}
