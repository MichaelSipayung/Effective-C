#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
void swap(int,int);                         //function declaration                 
void swapP(int*,int*);                      //parameters are pointer to a function, parameter is a pointet to int type
void f(int i);
void increment(void);
int *func(int i);
void usingBool(void);
void usingDerivedType(void);
struct S
{
    int i; double d;char c;
};
struct sigrecord{
    int signum;
    char signame[20];
    char sigdesc[100];
} sigline, *sigline_p;                      //sigline and sigline_ has sigrecord data type
void access_struct(void);
union{
    struct 
    {
        int type;
    }n;
    struct{
        int type;
        int intnode;
    }ni;
    struct{
        int type;
        double doublenode;
    }nf;
}u;
void access_union(void);
struct thisTag
{
    int member_1;
    //code to executed here
};
void initialize_using_tag(void);
enum day_tag{sunday,monday,tuesday};
void behavior_const(void);
int main(){
    int a=21,b=17;
    swap(a,b);
    printf("swap: a= %d , b=%d\n", a,b);
    printf("Using indirection operator to fix the bug");
    swapP(&a,&b);                           //call using unary &, the address-of operator
    printf("swap: a= %d , b=%d\n", a,b);
    for(int i=0;i<5;i++){
        increment();
    }
    increment();                            //as long program executed the last value will used to print
    unsigned char bad_buff[sizeof(struct S)]; //alignment.. compatible data type, value to your cpu and memory
    _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];
    struct S *bad_s_ptr =(struct S*)bad_buff; // wrong pointer alignment
    struct S *good_s_ptr = (struct S*) good_buff; //correct pointer alignment
    printf("\n");
    usingBool();
    enum day{sun,mon,tue,wed,thu,fri,sat};  //using enumeration sun will be filled with 0 and the next month wil be incremented by 1
    enum cardinal_points{north=0,east=90,south=180,west=270};
    enum month{jan=1,feb=2};
    usingDerivedType();
    access_struct();
    return 0;
}

void swap(int a,int b){                     //function defenition
    int t=a;
    a=b;
    b=t;
    printf("swap: a= %d , b=%d\n", a,b);
}
void swapP(int *pa,int *pb){
    int t=*pa;
    *pa=*pb;
    *pb =t;
    return;
}
void f(int i){
    int j=1;
    i++;
    for(int i=1;i<10;i++){                  //point to inner scope i
        int j=2;
        printf("%d", j);
    }
    printf("%d",j);                         //return outer scope and point to j=1
}
void increment(void){
    static unsigned int counter=0;          //the variable begin with value 0, when the program startup
    counter++;                              //counter value will increase as long the function executed
    printf("%d  ", counter);
}
int *func(int i){
    static unsigned int k =12;              //the static object must refer to constant value
    return &k;
}
void usingBool(void){
    _Bool firstDeclare=true;
    bool secondDeclare=false;
    printf(" 1.tes boolean :%d\n", firstDeclare);
    printf(" 2.tes boolean :%d\n", secondDeclare);
}
void usingDerivedType(void){
    int i=17;
    int *ip = &i;
    int a[17];
    float *afp[17];                         //pointer to float which is the array data type
    char str[11];
    for(unsigned int i=0;i<10;++i){
        str[i]='0' +i;
    }
    str[10]='\0';
    for (size_t i = 0; i < 10; i++)
    {
        printf("%c", str[i]);
    }
    typedef unsigned int non_negative;
    non_negative nilai =12;                     //nonegative only other name to unsigned int data type 
}
void access_struct(void){
    sigline.signum=12;
    strcpy(sigline.signame,"SIGINT");
    strcpy(sigline.sigdesc,"Interrupt from keyboard");
    sigline_p = &sigline;                       //sigline_p now point to the sigline object
    printf("sign number : %d\n", sigline.signum);
    printf("sign number : %d , call using structure pointer operator(->)\n", sigline_p->signum);
    sigline_p->signum=90;                       //modify current value
    printf("sign number : %d , call using structure pointer operator(->)\n", sigline_p->signum);
    strcpy(sigline_p->signame,"JACk");
}
void access_union(void){
    u.nf.type=1;                                //access union and it'e member
    u.nf.doublenode=3.14;
}
void initialize_using_tag(void){
    struct thisTag nameType;                    //nameType now has thisTag structure type
    nameType.member_1=12;                       //access the member
    enum day_tag name_call;                     //declare name_call as day_type which declared as enum type
}
void behavior_const(void){
    const int i=1;
    int *ip=(int*)&i;                           //undifined behavior, casting constant and try taje the address
    int name_f=12;
    const int j =12;
    const int *ip_f=&i;
    const int *jp_f=&j;
    *(int*)ip_f=12;                             //ok
    *(int*)jp_f=98;                             //undifined behavior
}
