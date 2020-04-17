

#include <iostream>
#include <stack>
using namespace std;
int cnt = 0;
int main(){
    stack<char> mystack;
    
    int T; cin>>T;
    
    for(int i = 0 ; i < T; i++){
        string str;
        cin>>str; // ABBA 인 경우
        for(int j = 0 ;j < str.length(); j++){
            if(mystack.empty())
                mystack.push(str[j]); // 첫번째 A는 스택에 저장
            
            else{
                if(mystack.top() == str[j]){
                    mystack.pop();
                }
                else{
                    mystack.push(str[j]);
                }
            }
        } // string 한글자씩
        if(mystack.empty())
            cnt++;

        while (!mystack.empty()) { 
            mystack.pop();
        }
    } // Test case 만큼 for문
    
    cout<<cnt<<endl;
}


