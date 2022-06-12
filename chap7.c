#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#define S_INIT "abc"
#define __STDC_WANT_LIB_EXT1__ 1
void using_siz_len(void);
size_t efesien_strlen(const char *);
void cp_str(void);
char *imp_strcpy(char *,const char*);
void get_y_or_n(void);
char *imp_gets(char *);
void cor_get_y_or_n(void);
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
    char *al_str= malloc(strlen(core_str)+1);
    //wide string 
    wchar_t wcore_str[] =L"Heros comer to sun";
    wchar_t *wal_str = malloc((wcslen(wcore_str)+1) * sizeof(wchar_t));
    //char un_behavior[]="undifined \0 behavior";
    //printf("total character, test the behavior null charater: %d\n", strlen(un_behavior));
    cp_str();
}
size_t efesien_strlen(const char *str){                     //another alternative for avoiding the undefenied behavior or strlen
    const char *s;
    for(s=str;*s;++s){}
    return (s-str);
}
void cp_str(void){
    char str[100]="Here comes the sun";
    size_t str_size=strlen(str)+1;
    char *dest =(char*)malloc(str_size);
    if(dest){
        strcpy(dest,str);
    }
    else{
        printf("Error occurs while copy a string...\n");
    }
}
char *imp_strcpy(char *dest,const char* src){
    char *save = dest;
    while (*dest++=*src);
    return save;
}
void get_y_or_n(void){
    //miuse of the obsolete gets function 
    char resposnse[8];
    puts("Continue ? [Y] n:");
    //gets(resposnse);                                                 //compiler will warn you
    if (resposnse[0]='n')
    {
        exit(0);
    }
    return;
}
char *imp_gets(char *dest){
    int c ;
    char *p =dest;                                                      //p points to same address with dest
    while((c==getchar()) !=EOF && c!='\n'){
        *p++=c;
    }
    *p='\0';
    return dest;
}
void cor_get_y_or_n(void){
    char response[8];
    size_t len= sizeof(response);
    puts("Continue ? [Y]: n");
    //gets_s(response, len);    
    if(response[0]='n'){
        exit(0);
    }
}
