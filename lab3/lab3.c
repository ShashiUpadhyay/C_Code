
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define EQUAL ==

#if TRUE
#define TRACE fprintf(stderr,"\nLine Number is %d \n",__LINE__);
#define DEBUG(format,message) fprintf(stderr,format,message);
#else
#define DEBUG(x,y)
#define TRACE
#endif

/* 

    This function will take 3 strings, a 'haystack' string, a 'needle' string, and
    a buffer string. This function will search the sequence of needle in haystack string.
    And once match found will copy the string in buffer.

*/

int myStrStr(char haystack[], char needle[], char buffer[]){
    int hay_index;
    hay_index=0;
    int needle_index;
    needle_index=0;
    int second_itr_index;
    second_itr_index=0;
    int buffer_index;
    buffer_index=0;
    int hay_print;
    int needle_print;
    
//    DEBUG("Needle : ");
    DEBUG("%s","Needle : ");
    for(needle_print=0;needle_print<=strlen(needle);needle_print++){
        DEBUG("%c", needle[needle_print]);
    }

//    DEBUG("\nHayStack : ");
    DEBUG("%s","\nHayStack : ");
    for(hay_print=0;hay_print<=strlen(haystack);hay_print++){
         DEBUG("%c", haystack[hay_print]);
    }
    
    DEBUG("%s","\n");
    
    buffer[buffer_index]='\0';
    
    if(strlen(needle) <= strlen(haystack)){
        for(needle_index=0;needle_index<strlen(needle);needle_index++){
            for (hay_index=second_itr_index; hay_index<=strlen(haystack);hay_index++){
                if(needle[needle_index] EQUAL haystack[hay_index]){
                    buffer[buffer_index] = haystack[hay_index];
                    ++buffer_index;
                    second_itr_index = hay_index+1;
                    break;
                }/* end of internal if loop */
            }/* end of hay_index for loop */
        }/* end of neeled_index for loop */
    
        buffer[buffer_index]='\0';

        if(strlen(buffer) EQUAL strlen(needle)){
            return 1;
        }else{
            return 0;
        }/*end of inner if loop*/
    }else{
        return 2;
    }/* end of outer if loop */
    
}

/* Function will print the content of buffer array */
void print_buffer(char buffer[],int match){
    int buffer_index;
    if(match EQUAL 1){
//        printf("Buffer : ");
        DEBUG("%s","Buffer : ");
        for(buffer_index=0; buffer_index<strlen(buffer);buffer_index++){
            DEBUG("%c",buffer[buffer_index]);
        }
    }else if(match EQUAL 2){
//        printf("Length of Needle string is greater than Haystack");
        DEBUG("%s","Length of Needle string is greater than Haystack");
    }else{
//        printf("Haystack does not contain the matching string of Needle");
        DEBUG("%s","Haystack does not contain the matching string of Needle");
    }
    DEBUG("%s","\n\n");
}

int main(){
    
    /* Section A - STARTS */

    DEBUG("%s","\nDebugging Enabled !!!\n");
    TRACE;
    
    /* Section A - ENDS */
    
    /* Section B - String Manipulation - STARTS */
//        printf("\nString Manipulation\n");
        DEBUG("%s","\nString Manipulation\n");
        char buffer[200];
    
        int match;
    
        match = myStrStr("apple","app",buffer);
        print_buffer(buffer,match);
    
        match = myStrStr("orange","ge",buffer);
        print_buffer(buffer,match);
    
        match = myStrStr("blueberry","ueber",buffer);
        print_buffer(buffer,match);
    
        match = myStrStr("strawberry","strawberry",buffer);
        print_buffer(buffer,match);

        match = myStrStr("grapefruit","terrible",buffer);
        print_buffer(buffer,match);
    
    /* Section B - String Manipulation - ENDS */
    return 0;

}

