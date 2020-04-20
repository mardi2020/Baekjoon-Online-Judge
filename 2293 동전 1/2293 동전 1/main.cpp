//
//  main.cpp
//  2293 동전 1
//
//  Created by Emma on 2020/04/20.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
int n, k; // 동전의 수, k원
int coin[101], dp[10001];// 동전의 가치, k원을 만들 수 있는 모든 경우의 수

int main(){
    scanf("%d%d", &n, &k);
    
    for(int i = 1;i <= n;i++)
        scanf("%d", &coin[i]);
    
    dp[0] = 1;
    for(int i = 1; i <= n;i++)
        for(int j = coin[i]; j <= k; j++)
                dp[j] += dp[j - coin[i]];
        
    printf("%d", dp[k]);
}
