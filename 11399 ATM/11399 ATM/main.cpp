//
//  main.cpp
//  11399 ATM
//
//  Created by Emma on 2020/02/06.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v1(1001);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin>>N;
    v1.resize(N);
    for(int i = 0; i < N; i++){
        cin>>v1[i].first; // 사용시간
        v1[i].second = i+1; // 사람 번호
    }
    sort(v1.begin(), v1.end());
    vector<int> sum(N+1);
    sum[0] = v1[0].first;
    int s = sum[0];
    for(int i = 1; i < N;i++){
        sum[i] = sum[i-1] + v1[i].first;
        s += sum[i];
    }

    cout<<s<<'\n';
}
