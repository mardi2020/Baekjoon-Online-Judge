#include <iostream>
#include <list>
using namespace std;

int main(){
    //string str; cin>>str;
    list<char> mylist;
    string str; cin>>str;
    // 입력받은 string을 list에 넣음

    for(int i = 0; i < str.length(); i++)
        mylist.push_back(str[i]);

    // iterator가 커서 역할
    list<char>::iterator end_iter = mylist.end();

    long M; cin>>M;
    for(int i = 0 ; i < M ; i++){
        char command; cin>>command;
        
        if (command == 'L' && end_iter != begin(mylist)){
            end_iter--;
        }
        else if(command == 'D'&& end_iter != end(mylist)){
            end_iter++;
        }
        else if(command == 'B' && end_iter != begin(mylist)){ // 삭제
            end_iter--;
            end_iter = mylist.erase(end_iter);
            //end_iter++;
        }
        else if(command == 'P'){
            char c; cin>>c;
            mylist.insert(end_iter, c); // end_iter가 가리키는거 앞에 c 추가
        }
    }

    for(auto e: mylist)
        cout<<e;
    cout<<endl;
}


