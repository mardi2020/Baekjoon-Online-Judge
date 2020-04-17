#include <stdio.h>
#define MAXSIZE 1000001
int n, m, a, b, c;
int p[MAXSIZE];

int Find(int x){ // x가 어느 집합에 포함되어 있는지
    if(p[x] == x){
        return x;
    }else{
        return p[x] = Find(p[x]);
    }
}
void Union(int x, int y){ // Set x와 y 합치기
    x = Find(x);
    y = Find(y);
    
    p[y] = x;
}
int main(){
    scanf("%d%d", &n, &m);
    
    for(int i = 0 ; i <= n; i++){
        p[i] = i;
    }
    
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d%d", &c, &a, &b);
        
        if(!c){
            Union(a, b);
        }else{
            if(Find(a) == Find(b)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
        
    }
}
