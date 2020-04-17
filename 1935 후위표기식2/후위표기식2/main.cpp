#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    int N;cin>>N;
    string str; cin>>str;

    int ary[N];
    for(int i = 0; i < N ; i++)
        cin>>ary[i];

    stack<double> mystack;
    for(int i = 0; i<str.length();i++){
        if(str[i]=='-' || str[i]=='+' ||str[i]=='/' || str[i]=='*'){
            // operator
            double y = mystack.top(); // -나 / 일때 연산 순서 확인
            mystack.pop();
            double x = mystack.top();
            mystack.pop();

            double result = 0.0;
            if(str[i] == '+')
                result = x + y;
            else if(str[i] == '-')
                result = x - y;
            else if(str[i] == '/')
                result = x / y;
            else if(str[i] == '*')
                result = x * y;
            mystack.push(result);
        }
        else // operand이면 stack.push
            mystack.push(ary[str[i] - 'A']);
    }
    cout.precision(2);
    cout<<fixed<<mystack.top()<<endl;
        
}
