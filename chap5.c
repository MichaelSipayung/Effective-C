#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include <stdalign.h>

bool isN(int*ptr,int n);
void logical_op(void);
int conditional_op(int);
void alig_op(void);
void point_arr(void);
void sum_m_elemen(void);
int main(void){
    alig_op();
    point_arr();

    return 0;
}
bool isN(int*ptr,int n){
    return ptr && *ptr ==n;                     //don't dereference a null pointer
}
int conditional_op(int a){
    return (a<12) ? 12:13;
}
void alig_op(void){
    int arr[4];
    double arr_d[6];
    static_assert(_Alignof(arr_d)==8,"unexpected alignment");
    printf("sizeof data %d\n",sizeof(arr));
    static_assert(_Alignof(arr)==4,"unexpected alignment");
    assert(alignof(max_align_t)==16);          //runtime assertion 
    printf("Alignment of arr = %zu\n", _Alignof(arr));
    printf("Alignment of max_align_t= %zu \n",alignof(max_align_t));
}
void point_arr(void){
    int arr[100];
    int *arrp1=arr[40];
    int *arrp2=arrp1+20;                //arrp2 points to arr[60]
    printf("test pointer arithmetic %td\n", arrp2-arrp1);
    printf("test value from a pointer %td\n", arrp1);
  
}
void sum_m_elemen(void){
    int m[2]={1,2};
    int *pi;
    int j=0;
    for(pi=&m[0];pi<&m[2];++pi){
        j+=*pi;
    }
    return j;
}
