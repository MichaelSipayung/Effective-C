#include <stdio.h>
#include <stdlib.h>

int main(void){
    puts("Hello World");
    if(puts("test if bug occurs") == EOF){
        return EXIT_FAILURE;
    }
    printf("%s\n","hello world");
    printf("test hello world\n");
    return EXIT_SUCCESS;
}