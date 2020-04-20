#include <iostream>
#include <fstream>
using namespace std;
#define DEL 0 // 한번 쓰고 지운거 표기
#define endl "\n"
/*
 * Solution number에 따라 달라짐
 * linear : 1, quadratic : 2, Double : 3
 */

typedef struct HashTbl *HashTable;
struct HashTbl{
    int count;
    int TableSize;
    int *TheLists;
};

void Insert(HashTable H, int value, int solution);
void Delete(HashTable H, int value, int solution);
int find(HashTable H, int value, int solution);
void print(HashTable H);
int Hash(int value, int size, int i, int solution);


int main(){
    int N; cin>>N;
    HashTbl H;
    
    for(int i = 0 ; i < N ; i++){
        string hashing; cin>>hashing; // #define linear 1 이런걸로
        int solution = -1;
        
        if(hashing.compare("Linear") == 0){
            solution = 1;
        }
        else if(hashing.compare("Quadratic") == 0){
            solution = 2;
        }
        else if(hashing.compare("Double") == 0){
            solution = 3;
        }
            
        int size; cin>>size;
        
        H.count = 0;
        H.TableSize = size;
        H.TheLists = new int[H.TableSize];
        for(int i = 0;i < size;i++)
            H.TheLists[i] = 0;
        
        while(1){
            char command; cin>>command;
            
            if(command == 'q'){
                delete [] H.TheLists;
                break;
            }
            
            int value;
            if(command == 'i'){
                cin>>value;
                Insert(&H, value, solution);
            }
            else if(command == 'f'){
                cin>>value;
                find(&H, value, solution);
            }
            else if(command == 'd'){
                cin>>value;
                Delete(&H, value, solution);
            }
            
            else if(command == 'p'){
                print(&H);
            }
        }
        
    }
}

void Insert(HashTable H, int value, int solution){ // 추가 : 비어있거나 DEL인 칸에 추가
    if(find(H, value, solution) != -1 and H->count != 0){
        cout<<"Alreay exists"<<endl;
        return;
    }
    
    for(int i = 0;;){
        if(H->TheLists[Hash(value, H->TableSize, i, solution)] == 0 or
           H->TheLists[Hash(value, H->TableSize, i, solution)] == DEL){ // 넣을 칸이 비었거나 DEL 표기가 되어있거나
            H->TheLists[Hash(value, H->TableSize, i, solution)] = value;
            H->count++;
            cout<<"Inserted "<<value<<endl;
            break;
        }
        else
            i++;
    }
    
}
void Delete(HashTable H, int value, int solution){ // 삭제 : 삭제후 DEL 표기
    if(find(H, value, solution) > -1){
        H->TheLists[find(H, value, solution)] = DEL;
        H->count--;
        cout<<"Deleted "<<value<<endl;
        return;
    }
    cout<<value<<" not exists"<<endl;
    return;
    
}

int find(HashTable H, int value, int solution){ // 검색 : 빈칸일때까지 검색
    for(int i = 0;;){
        if(H->count == 0 || (H->count != 0 && H->TheLists[Hash(value, H->TableSize, i, solution)] == 0) ){
            return -1;
        }
        else if(H->TheLists[Hash(value, H->TableSize, i, solution)] == value){
            return Hash(value, H->TableSize, i, solution);
        }
        i++;
    }
}

void print(HashTable H){
    for(int i = 0 ; i < H->TableSize ; i++){
        cout<<H->TheLists[i]<<' ';
    }
    cout<<endl;
}

int Hash(int value, int size, int i, int solution){
    switch (solution) {
        case 1: // linear
            return (value + i) % size;
        case 2: // quadratic
            return (value + (i * i) ) % size;
        case 3: // double
            return (value + i * ( 7 - ( value % 7 ) ) ) % size;
    }
    return -1;

} // 반환 : index, 아니면 -1
