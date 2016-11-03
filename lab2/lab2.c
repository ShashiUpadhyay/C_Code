#include <stdio.h>
#include <math.h>
#include <time.h>
#include <limits.h>

/* Code to convert decimal number into binary - START */
int binary_conversion(int number){
    printf("%14d = ",number);
    unsigned int mask= 1;
    mask = mask << 31;
    int i;
    for(i=0; i<=31;i++){
        if((number & mask) == 0){
            printf("0");
        }else{
            printf("1");
        }
        mask = mask >> 1;
    }
    printf("\n");
    
    return 0;
}
/* Code to convert decimal number into binary - END */

int main(){

    /* -- Part A -- Start */
    int first_num = 0;
    int second_num = 1;
    int fibonici;
    int count = 20;
    printf("\nFibonicci Sequence of first %d numbers is \n %4d\n", count,first_num);
    printf(" %4d\n", second_num);
    int i;
    for(i =3; i <=count; i++){
        fibonici = first_num + second_num;
        printf(" %4d\n",fibonici);
        first_num = second_num;
        second_num = fibonici;
    }
    printf("\n");
    /* -- Part A -- Ends */
    
    /* Binary Printer section - START */
    printf("Decimal Number   Binary Equivalent\n");
    
    binary_conversion(2);

    binary_conversion(255);

    binary_conversion(32);

    binary_conversion(-1);

    binary_conversion(INT_MAX);

    binary_conversion(INT_MIN);

    /* Binary Printer section - END */
    
    
    /* -- Part B (Printing a Random Binary Number) -- Start */
     printf("\n");
     int min = INT_MIN;
     int max = INT_MAX;
     srand(time(0));
     printf(" Random Number  Binary Equivalent\n");
     int random = rand()%max+1 + min;
     binary_conversion(random);
     printf("\n"); 
 
    /* -- Part B (Printing a Random Binary Number) -- End */
    


return 0;
}

