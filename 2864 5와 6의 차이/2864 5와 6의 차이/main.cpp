//
//  main.cpp
//  2864 5와 6의 차이
//
//  Created by Emma on 2020/03/06.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
using namespace std;
string A, B;

int main() {
    cin>>A>>B;
    string max1 = "", max2 = "";
    string min1 = "", min2 = "";
    for(int i = 0; i < A.length();i++){
        if(A[i] == '5')
            A[i] = '6';
        
        if(B[i] == '5')
            B[i] = '6';
        
        max1 += A[i];
        max2 += B[i];
        
        if(B[i] == '6')
            B[i] = '5';
        
        if(A[i] == '6')
            A[i] = '5';
            
        min1 += A[i];
        min2 += B[i];
    }
   
    auto minvalue = stoi(min1) + stoi(min2);
    auto maxvalue = stoi(max1) + stoi(max2);
    
    printf("%d %d", minvalue, maxvalue);
}
