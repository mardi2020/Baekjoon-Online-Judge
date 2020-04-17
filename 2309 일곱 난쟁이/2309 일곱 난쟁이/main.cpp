//
//  main.cpp
//  2309 일곱 난쟁이
//
//  Created by Emma on 2020/03/02.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];

int main() {
    int sum = 0;
    for(int i = 0; i < 9; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    bool flag = false;
    for(int i = 0;i < 9;i++){
        for(int j = i + 1;j < 9;j++){
            if((sum - arr[i] - arr[j])== 100){
                arr[i] = -1;
                arr[j] = -1;
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    sort(arr, arr+9);
    for(int i = 2;i < 9;i++)
        printf("%d\n", arr[i]);
}
