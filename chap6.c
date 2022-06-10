#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
typedef struct{
    char c[10];
    int i;
    double d;
}widget;
int closedir(DIR *dirp);
void limit_dangling_pointer(void);
int main(void){
    widget *p = malloc(sizeof(widget));
    if (p==NULL){
        printf("failed to allocated storange");
    }
    else{
        p->d=3.1459287;
        printf("Success allocated memory, try to dereference result: %.f\n", p->d);
    }
    char *str=(char*)malloc(16);
    if(str){
        strncpy(str,"123456789abcdef",15);
        str[15]='\0';                                   //good allocate for null terminate
        printf("result with defined behavior \t: %s. \n",str );
        free(str);
        return EXIT_SUCCESS;
    }
    else{
        return EXIT_FAILURE;
    }
    printf("correct way to realocate and avoid memory leak\n");
    void *p2;
    void *p_av=malloc(100);
    size_t nsize=50;
    if((nsize==0)||(p2=realloc(p_av,nsize))==NULL)
    {
        free(p_av);
        //return NULL;
    }
    p_av=p2;
    
    return 0;
}
int closedir(DIR *dirp){
    //free(dirp->d_buf);                        //double free vulnerability 
    free(dirp);
    //return close(dirp->d_fd);                 //dirp has already been freed
    return 0;
}
void limit_dangling_pointer(void){
    char *ptr = malloc(16);
    free(ptr);
    ptr=NULL;                                   //set every pointer to null to avoid accesed the free pointer
    return;
}
