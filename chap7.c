#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#define S_INIT "abc"

void using_siz_len(void);

int main(void){
    char s[4]=S_INIT;
    printf("using array to store string literal: %s\n", s);
    const char fix_s[]="abcd";
    printf("avoiding the undifined behavior :%s\n", fix_s);
    using_siz_len();
    return 0;
}
void using_siz_len(void){
    char str[100]="Hero comes to sun";
    size_t str_size=sizeof(str);
    printf("total allocate in byte: %d\n", str_size);
    printf("Total character appear : %d\n", strlen(str));
    wchar_t wide_char[100]=L"Here comes to sun";
    printf("Using wide charater, allocated in byte : %d\n", sizeof(wide_char));
    printf("wide character, test total character appear : %d\n", wcslen(wide_char));
    //narrow string, usefulness of the strlen function 
    char core_str[]="Hero comes to sun";
    char al_str= malloc(strlen(core_str)+1);
    //wide string 
    wchar_t wcore_str ="Heros comer to sun";
    wchar_t wal_str = malloc((wcslen(wcore_str)+1) * sizeof(wchar_t));
    char un_behavior[]="undifined \0 behavior";
    printf("total character, test the behavior null charater: %d\n", strlen(un_behavior));
}
