//
//  main.cpp
//  11051 이항계수 2
//
//  Created by Emma on 2020/04/20.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <algorithm>
int n, k;
int B[1001][1001];

int bino(int n, int k){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= std::min(i, j) ; j++){
            if(i == j || j == 0)
                B[i][j] = 1;
            else
                B[i][j] = (B[i-1][j-1] + B[i-1][j])%10007;
        }
    }
    return B[n][k];
}
int main(){
    scanf("%d%d", &n, &k);
    int res = bino(n, k);
    printf("%d\n", res);
}
