#include <stdio.h>
#include <math.h>


int main(){

    printf("Hello World! \n");

    /* PART A -- START */

    /* Evaluate the expression -- START */
    printf("\n");
    /* Evaluation of first statement (Start) */
    printf("Evaluation of expressions \n");
    float x=2.55;
    float result = 3*x*x*x-5*x*x+6;
    printf("Output of first expression = %f \n ", result);
    /* Evaluation of first statement (END) */

    /* Evaluation of second statement (Start) */
    double result_exp2 = (3.31*pow(10,-8)*2.01*pow(10,-7))/(7.16*pow(10,-6)+2.01*pow(10,-8));
    printf("Output of second expression = %e \n ", result_exp2);
    /* Evaluation of second statement (END) */

    printf("\n");
    /* Evaluate the expression -- END */

    /* Round off integer section --- START */

    int multiple;
    int divisor;
    int next_multiple;
    printf("Round off integers \n");
    /* First calculation */
    multiple = 365;
    divisor = 7;
    next_multiple = multiple + divisor - multiple%divisor;
    if(next_multiple%2 > 0){
        next_multiple = next_multiple + divisor;
    }
    printf("Round of %d to next largest even multiple of %d = %d \n ", multiple,divisor,next_multiple);

    /* Second calculation */
    multiple = 12258;
    divisor = 28;
    next_multiple = multiple + divisor - multiple%divisor;
    if(next_multiple%2 > 0){
        next_multiple = next_multiple + divisor;
    }
    printf("Round of %d to next largest even multiple of %d = %d \n ", multiple,divisor,next_multiple);

    /* Third calculation */
    multiple = 996;
    divisor = 4;
    next_multiple = multiple + divisor - multiple%divisor;
    if(next_multiple%2 > 0){
        next_multiple = next_multiple + divisor;
    }
    printf("Round of %d to next largest even multiple of %d = %d \n ", multiple,divisor,next_multiple);
    printf("\n");
    /* Round off integer section --- END */

    /* Conversion of degrees Fehrenhite to degrees celsius -- START */
    printf("Conversion of degree fehrenhite into degree celsius \n");
    float fehrenhite;
    float celsius = (fehrenhite - 32)/1.8;

    /* Convert 27 degree fehrenhite to degree celsius */
    fehrenhite = 27;
    celsius = (fehrenhite - 32)/1.8;
    printf("%.0f degree F = %.2f degree C \n ", fehrenhite, celsius);

    /* Convert 100 degree fehrenhite to degree celsius */
    fehrenhite = 100;
    celsius = (fehrenhite - 32)/1.8;
    printf("%.0f degree F = %.2f degree C \n ", fehrenhite, celsius);

    /* Convert 32 degree fehrenhite to degree celsius */
    fehrenhite = 32;
    celsius = (fehrenhite - 32)/1.8;
    printf("%.0f degree F = %.2f degree C \n ", fehrenhite, celsius);

    /* Convert -40 degree fehrenhite to degree celsius */
    fehrenhite = -40;
    celsius = (fehrenhite - 32)/1.8;
    printf("%.0f degree F = %.2f degree C \n ", fehrenhite, celsius);

    /* Conversion of degrees Fehrenhite to degrees celsius -- END */

    /* PART A -- END */

    /* PART B -- START */
    printf("\n");
    /* Creation of variable - START */
    long int large_num = 9838263505978427528;
    /* Creation of variable - END */

    /* Typecast of variables - START */
    printf("Typecast of variables \n");
    int typecast_large_num_int = (int) large_num;
    printf("Output into integer = %d \n", typecast_large_num_int);

    double typecast_large_num_double = (double) large_num;
    printf("Output into double = %.2lf \n", typecast_large_num_double);

    char typecast_large_num_char = (char) large_num;
    printf("Output into char = %c \n", typecast_large_num_char);

    /* Typecast of variables - END */

    /* PART B -- ENDS */


return 0;
}

