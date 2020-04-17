//
//  main.cpp
//  1463 1로 만들기
//
//  Created by Emma on 2020/02/24.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAXSIZE 1000001
int visited[MAXSIZE];
int N;
queue<pair<int, int>> q;

void BFS(){
    q.push({N, 0});
    visited[N] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        int times = q.front().second;
        
        if(x == 1)
            break;
        q.pop();
        
        if(0 > x and x > MAXSIZE)
            continue;
        
        if (x-1 >= 0 and !visited[x-1]){
            q.push({x-1, times+1});
            visited[x-1] = true;
        }
        if (x % 3 == 0 and !visited[x/3]){
            q.push({x/3, times+1});
            visited[x/3] = true;
        }
        if (x % 2 == 0 and !visited[x/2]){
            q.push({x/2, times+1});
            visited[x/2] = true;
        }
    }
    
}

int main() {
    cin>>N;
    BFS();
    cout<<q.front().second;
}
