//
//  main.cpp
//  10818 최소, 최대
//
//  Created by Emma on 2020/03/05.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n, x, minvalue = INT_MAX , maxvalue = INT_MIN;
    cin>>n;
    while(n--){
        cin>>x;
        if(x > maxvalue)
            maxvalue = x;
        if(x < minvalue)
            minvalue = x;
    }
    cout<<minvalue<<' '<<maxvalue;
}
