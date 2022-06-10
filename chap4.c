#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>                     //size_t type
int glob;
int max(int,int);
int f(void);
int g(void);
void operator_prec(void);
void op_sizeof(void);
int main(){
    operator_prec();
    return 0;
}
void operator_prec(void){
    char abc[]="abc";
    char xyz[]="xyz";
    char *p=abc;
    printf("%c\n",++*p);                  //equal to ++(*p) call using prefix operator
    p=xyz;
    printf("%c\n",*p++);                  //equal to *(p++) call using postfix operator
    max(f(), g());                        //order of evaluation to call f and g, especially working for the same shared data
    int f_val =f();
    int g_val =g();
    int max_value= max(f(),g());         // now the result will give predictable behavior
    op_sizeof();
}
int f(void){
    return glob+10;
}
int g(void){
    glob =42;
    return glob;
}
int max(int x,int y){
    return x<y ? y:x;
}
void op_sizeof(void){
    long long i;
    size_t i_size =sizeof(i)*__CHAR_BIT__;
    printf("total bit store in memory %d\n", i_size);
}
