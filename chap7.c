#include <stdio.h>
#define S_INIT "abc"

int main(void){
    char s[4]=S_INIT;
    printf("using array to store string literal: %s\n", s);
    const char fix_s[]="abcd";
    printf("avoiding the undifined behavior :%s\n", fix_s);
    return 0;
}