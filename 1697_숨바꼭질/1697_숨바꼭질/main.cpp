#include <iostream>
#include <queue>
using namespace std;
#define MAXSIZE 100001
int N,K;
int check[MAXSIZE]={0,};
queue<pair<int, int>> q; // <좌표, 몇번째인가>

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int times = q.front().second;
        
        if(x == K)
            break;
        
        q.pop();
        
        check[x] = 1;
        
        if(x-1 >= 0 and !check[x-1])
            q.push(make_pair(x-1, times+1));
        if(x+1 < MAXSIZE and !check[x+1])
            q.push(make_pair(x+1, times+1));
        if(2*x < MAXSIZE and !check[2*x])
            q.push(make_pair(2*x, times+1));
    }
}


int main(){
    cin>>N>>K;
    
    q.push(make_pair(N, 0));

    bfs();
    
    cout<<q.front().second<<endl;
}

