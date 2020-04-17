#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int priority(char c){
    if(c=='(')
        return 0;
    else if(c=='+' || c=='-')
        return 1;
    else if(c=='/' || c=='%' || c=='*')
        return 2;
    else
        return 3;
}

int main(){
    string str;
    cin>>str;

    stack<char> Operator;
    queue<char> Result;
    
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '%' || str[i] == '/' || str[i] == '+' || str[i] == '*' || str[i]=='-' || str[i] == '(' || str[i] == ')'){// operator 인 경우
            switch (str[i]) {
                case '(': // ( 상관없이 추가됨
                    Operator.push(str[i]);
                    break;
                case ')': // str[i] ==')'
                    while(Operator.top() != '('){ // stack의 top이 (일까지
                        Result.push(Operator.top());
                        Operator.pop();
                    }
                    Operator.pop(); // '(' 버리기
                    break;
                default: // str[i] == % / * + - operator 일경우
                    while(!Operator.empty() && priority(Operator.top()) >= priority(str[i])){
                        Result.push(Operator.top());
                        Operator.pop();
                    }
                    Operator.push(str[i]);
                    break;

            } //switch문 끝
            
        }
        else{ //operand인 경우
            Result.push(str[i]);
        }
    }

    while(!Operator.empty()){  // 위의 과정을 다 하고나서 stack이 빌때까지 수행
        Result.push(Operator.top());
        Operator.pop();
     }
    
    int len = Result.size(); /* queue의 size가 pop할 때마다 줄어드니까 변수에 저장해두고 쓰기 */
    
    for(int i =0 ;i< len ; i++){
        printf("%c",Result.front());
        Result.pop();
    }
    printf("\n");
}

