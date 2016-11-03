
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define buffer_size 255

struct Names{
    char *first_name, *last_name, *jedi_name;
};

void* allocate(unsigned int size);
void* deallocate(void* pointer, int size);
void read_name(char *filename,char mode);
char *jedi_name(struct Names names);

int heap_usage = 0;

/* -------PART 1 - START------------ */

/* Method to create Jedi Names */
char *jedi_name(struct Names names){
    char *firstname, *lastname, *buffer;
    firstname = NULL;lastname = NULL;buffer=NULL;
    firstname = names.first_name;
    lastname = names.last_name;
    char *buffer_index = (char*) allocate(5);
    int i,buffer_count,jedi_namecount;
    
    buffer_count=0;
    jedi_namecount = 0;
    for(i=0;lastname[i]!='\0';i++){
        if(jedi_namecount < 3){
            buffer_index[buffer_count] = lastname[i];
            buffer_count++;
            jedi_namecount++;
        }else{
            break;
        }
    }
    
    jedi_namecount = 0;
    for(i=0;firstname[i] != '\0';i++){
        if(jedi_namecount < 2){
            buffer_index[buffer_count] = tolower(firstname[i]);
            buffer_count++;
            jedi_namecount++;
        }else{
            break;
        }
    }
    
    buffer_index[buffer_count] = '\0';
    firstname = NULL;lastname = NULL;buffer=NULL;
    return buffer_index;
}

/* Method to read names from the file i.e. line by line */
void read_name(char *filename,char mode){
    char line_buffer[buffer_size];
    FILE *file_pointer;
    file_pointer= fopen(filename,&mode);
    if(file_pointer == NULL){
        printf("File does not exist\n\n");
    }else{
        char ch, *fullname, *firstname, *lastname, *jediname;
        char *namefull;
        firstname = NULL;lastname = NULL;jediname=NULL;fullname=NULL;
        /* code to read names from text file */
        while (fgets(line_buffer, sizeof(line_buffer), file_pointer))
        {
            int line_buffer_index,name_index;
            fullname = line_buffer;
            firstname = (char *) allocate(60);
            lastname = (char *) allocate(60);
            line_buffer_index=0;name_index=0;
            /* copying first name */
            while(line_buffer[line_buffer_index] != ','){
                if(line_buffer[line_buffer_index] == '\n' ||
                   line_buffer[line_buffer_index] == '\r' ||
                   line_buffer[line_buffer_index] == '\t'){
                    line_buffer_index++;
                }else{
                    firstname[name_index] = line_buffer[line_buffer_index];
                    line_buffer_index++;
                    name_index++;
                }
            }
            firstname[name_index] = '\0';
            line_buffer_index++;
            name_index=0;
            /* copying last name */
            while(line_buffer[line_buffer_index] != '\0'){
                if(line_buffer[line_buffer_index] == '\n' ||
                   line_buffer[line_buffer_index] == '\r' ||
                   line_buffer[line_buffer_index] == '\t'){
                    line_buffer_index++;
                }else{
                    lastname[name_index] = line_buffer[line_buffer_index];
                    name_index++;
                    line_buffer_index++;
                }
            }
            lastname[name_index]='\0';
            struct Names struct_name;
            struct_name.first_name = firstname;
            struct_name.last_name=lastname;
            jediname = jedi_name(struct_name);
            struct_name.jedi_name=jediname;
            printf("Full Name: %s,%s\nJedi Name is - %s\n\n",struct_name.first_name, struct_name.last_name,struct_name.jedi_name);
            
            firstname=deallocate(firstname,60);
            lastname=deallocate(lastname,60);
            jediname=deallocate(jediname,5);

            struct_name.jedi_name = NULL;
        }
    }
    
    
    fclose(file_pointer);
    file_pointer=NULL;
}

/* -------PART 1 - END------------ */

/* -------PART 2 - START------------ */
void *allocate(unsigned int size){
    heap_usage = heap_usage + size;
    return malloc(size);
}

void* deallocate(void* pointer, int size){
    free(pointer);
    pointer=NULL;
    heap_usage = heap_usage - size;
    return NULL;
}
/* -------PART 2 - END------------ */

int main(){
    /* -------PART 1 - START------------ */
    struct Names names;
        names.first_name = "Shashi";
        names.last_name  = "Upadhyay";
        names.jedi_name = jedi_name(names);
        deallocate(names.jedi_name,5);
        printf("Full Name: %s,%s | %s \n\n", names.first_name,names.last_name,names.jedi_name);
        names.first_name = NULL;
        names.last_name = NULL;
       names.jedi_name = NULL;
    
    char mode = 'r';
    char *filename = "names.txt";
    read_name(filename,mode);
    filename=NULL;
    printf("Heap usage=%d\n",heap_usage);
    /* -------PART 1 - END------------ */
    
    return 0;
}

