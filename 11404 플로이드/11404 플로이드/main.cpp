//
//  main.cpp
//  11404 플로이드
//
//  Created by Emma on 2020/04/28.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#define INF 987654321
using namespace std;
int n, m;
int map[101][101];

int main(){
    cin>>n>>m;
    
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n; j++){
            map[i][j] = INF;
            if(i == j)
                map[i][j] = 0;
        }
    }
    
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(map[a][b] < c)
            continue;
        else
            map[a][b] = c;
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (map[j][i] != INF && map[i][k] != INF)
                    map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
                
            
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n; j++){
            if(map[i][j] == INF)
                cout<<0<<' ';
            else
                cout<<map[i][j]<<' ';
        }
        cout<<"\n";
    }
}
