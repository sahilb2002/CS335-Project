#include<stdio.h>
int foo(int a, int a);
int foo(int a, int b){
    int a=1;
    a = a+1;
    // int a =3;
    return b;
}
int main(){
    for(int i=0;i<10;i++){
        int i=2;
        printf("%d\n",i);
    }
}