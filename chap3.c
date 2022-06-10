#include <stdio.h>
#include <limits.h>
#include <math.h>
void declare_integer(void);
void signed_integer(void);
void using_double(void);
const char *show_classification(double x);
void casting(void);
int main(){
    declare_integer();
    signed_integer();
    using_double();
    return 0;
}
void declare_integer(void){
    unsigned int ui;
    unsigned u;                             //int can be omitted
    unsigned long long ull2;                //int can be omitted
    unsigned char uc;                       //unsigned is required

    int i;
    long long int sll;                      //signed can be omitted
    signed char sc;                         //signed is required

    unsigned int max = UINT_MAX;
    printf("maximum value for unsigned integer: %u\n", max);
    unsigned long max_long = ULONG_MAX;
    printf("maximum value for unsigned long int: %u\n", max_long);
    unsigned long long int max_dLong =(int)pow(2,64)-1;
    printf("Maximum unsigned long long int %u\n", max_dLong);
    printf("sizeof ullong : %d\n", sizeof(max_long));
    //wraparound case 
    extern unsigned int i_wrap,j_wrap;
    if (i_wrap-j_wrap<0)                    //can't happen
    {
        printf("this line never executed");
    }
    long long x_long =LLONG_MAX;
    printf("maximum value %lu\n", x_long);   
}
void signed_integer(void){
    long long int li=LLONG_MAX;
    unsigned long long ul=ULLONG_MAX;
    printf("maximum signed long int %ld\n", li);                //using %ld for signed long long int
    printf("sizeof long long int : %d\n", sizeof(li));
    printf("sizeof unsigned long long : %d\n", sizeof(ul));
    printf("maximum unsigned long long int %lu\n", ul);         //using %ld for signed long long int
    int agent =017;                                             //using octal constant
    printf("using octal constant %o to decimal \t: %d\n", agent,agent);
    int burger=0xDEADBEEF;
    printf("using hexadecimal constant : %x to decimal number %d", burger,burger);
    unsigned int ui =71U;                                       //append a suffix 
    signed long int sli = 9223372036854775807L;
}
void using_double(void){
    double dl =15.74;
    double dl_scie=1.1574e1;
    printf("Size of double in this machine %d byte \n", sizeof(dl));
}
const char *show_classification(double x){
    switch (fpclassify(x))
    {
    case FP_INFINITE:
        return "Inf";
        break;
    case FP_NAN:
        return "Nan";
        break;
    case FP_NORMAL:
        return "Normal";
        break;
    case FP_SUBNORMAL:
        return "subnormal";
        break;
    case FP_ZERO:
        return "zero";
        break;
    default:
        break;                                          //unknown behavior... working test with floating value
    }
}
void casting(void){
    int si =5;
    short ss=8;
    long sl =(long)si;                                  // casting using cast operator 
    unsigned short us = (unsigned short) (ss+sl);
}
