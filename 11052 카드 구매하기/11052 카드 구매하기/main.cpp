//
//  main.cpp
//  11052 카드 구매하기
//
//  Created by Emma on 2020/04/20.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <algorithm>
int n;
int p[1001];
int ans[1001];


int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            ans[i] = std::max(ans[i], ans[i-j] + p[j]);
        
    printf("%d\n", ans[n]);
}
