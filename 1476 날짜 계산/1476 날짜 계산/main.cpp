//
//  main.cpp
//  1476 날짜 계산
//
//  Created by Emma on 2020/04/21.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
using namespace std;


int main(){
    int e, s, m;
    scanf("%d%d%d", &e, &s, &m);
    
    int res, year = 1;
    while(1){
        if(!((year-e)%15) and !((year-s)%28) and !((year-m)%19)){
            res = year;
            break;
        }
        year++;
    }
    printf("%d\n", year);
}
