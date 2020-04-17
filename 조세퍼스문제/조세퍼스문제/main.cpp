#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, K;
    cin>>N>>K;
    queue<int> myque;
    queue<int> result;
    
    for(int i = 0 ; i < N; i++)
        myque.push(i+1);
    
    int count = 0;
    while(1){
        if(myque.empty())
            break;
        if(count < K-1){
            myque.push(myque.front());
            myque.pop();
            count++;
        }
        else if(count == K-1){
            result.push(myque.front());
            myque.pop();
            count = 0;
        }
    }
    
    int len = result.size();
    cout<<'<';
    for(int i = 0 ;i<len ; i++){
        cout<<result.front();
        result.pop();
        if(i<len-1)
            cout<<", ";
    }
    cout<<'>'<<endl;
}
