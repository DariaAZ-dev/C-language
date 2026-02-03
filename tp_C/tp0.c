#include <stdio.h>

void izmenit(int *a,int *b,int *c){
    int t=*a;
    *a =*b;
    *b=*c;
    *c=t;
}

void delit(int *a,int*b){
    int q=(*a)/(*b);
    int r=(*a)%(*b);
    printf("%d//%d is %d and rest of %d\n",*a,*b,q,r);
}

int main(void){
    int aa;
    int ss;
    int q;
    int s;
    int d;
    scanf("%d,%d,%d",&q,&s,&d);
    izmenit(&q,&s,&d);
    printf("%d,%d,%d\n",q,s,d);
    scanf("%d,%d",&aa,&ss);
    delit(&aa,&ss);
    
    
    printf("hello world\n");
    
    return 0;
}