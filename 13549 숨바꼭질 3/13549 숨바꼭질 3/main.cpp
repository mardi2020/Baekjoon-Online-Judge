//
//  main.cpp
//  13549 숨바꼭질 3
//
//  Created by Emma on 2020/02/24.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAXSIZE 100001
int N, K;
int check[MAXSIZE];
queue<pair<int, int>> q;

void BFS(int x, int times = 0){
    q.push({x, times});
    check[x] = true;
    
    while (!q.empty()) {
        int x = q.front().first;
        int times = q.front().second;
        if(x == K)
            break;
        q.pop();
        check[x] = true;
        
        if(2*x < MAXSIZE and !check[2*x]){ // 0초
            q.push({2*x, times});
        }
        if(x-1 >= 0 and !check[x-1]){ // 1초
            q.push({x-1, times+1});
        }
        if(x+1 < MAXSIZE and !check[x+1]){ // 1초
            q.push({x+1, times+1});
        }
    }
}

int main(){
    cin>>N>>K;
    BFS(N);
    cout<<q.front().second<<endl;
}
