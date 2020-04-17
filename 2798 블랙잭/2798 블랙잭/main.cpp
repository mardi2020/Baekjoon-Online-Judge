//
//  main.cpp
//  2798 블랙잭
//
//  Created by Emma on 2020/02/24.
//  Copyright © 2020 Emma. All rights reserved.
//

#include <iostream>
using namespace std;
int card[100];

int main() {
    int N, K;
    cin>>N>>K;

    for(int i = 0; i < N;i++){
        cin>>card[i];
    }

    int Blackjack = 0;
    for(int i = 0; i< N - 2;i++){
        for(int j = i + 1; j < N - 1; j++){
            for(int k = j + 1; k < N; k++){
                if(card[i] + card[j] + card[k] <= K and K - (card[i] + card[j] + card[k]) < K - Blackjack){
                    Blackjack = card[i] + card[j] + card[k];
                }
            }
        }
    }
    cout<<Blackjack;
}


