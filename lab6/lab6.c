
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <sys/time.h>
#include "Lists.h"

int main() {
    Data data;
    int count;
    count = 0;
    unsigned int range;

    /* PART 1 (A) --- START */
    srand(time(0));
    int vector_work_index;
    vector_work_index = 20;
    vector* vector_ref;
    vector_ref = createVector();
    range = 100;
    int userInputVector;
    userInputVector = 0;
    printf("Passing 20 random integers to insert in Vector \n");
    while (count < vector_work_index) {
        data.number = random_number_generator(range);
        vectorInsert(vector_ref, count, data);
        count++;
    }

    int find_index;
    find_index = 0;
    int vector_value;
    vector_value = 0;
    printf("Printing Values:\n");
    printf("Index\tValues\n");
    while (find_index < vector_work_index) {
        vector_value = vector_ref->data[find_index].number;
        printf("%3d\t%3d\n", find_index, vector_value);
        find_index++;
    }
    int delete_index;
    delete_index = 0;
    while (delete_index < vector_work_index) {
        vectorRemove(vector_ref, delete_index);
        delete_index++;
    }
    vectorDelete(vector_ref);
    vector_ref = NULL;
    /* PART 1 (A) --- END */


    /* PART 1 (B) --- START */
    srand(time(0));
    struct timeval start, stop;
    time_t start_time, stop_time, final_time;
    int profiling_count;
    profiling_count = 0;

    /* Profiling Geometric Expansion start */
    printf("Profiling of the code \n");
    vector_ref = createVector();
    gettimeofday(&start, NULL);
    /* Profiling */
    for (profiling_count = 0; profiling_count < 10000; profiling_count++) {
        data.number = random_number_generator(range);
        vectorInsert(vector_ref, profiling_count, data);
    }
    gettimeofday(&stop, NULL);
    start_time = (start.tv_sec * 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec * 1000000) + stop.tv_usec;
    final_time = stop_time - start_time;
    printf("Profiling Time for Geometric expansion Insert version = %ld ms.\n", final_time);
    vectorDelete(vector_ref);
    /* Profiling Geometric Expansion end */

    /* Profiling incremental Expansion start */
    srand(time(0));
    vector_ref = createVector();
    gettimeofday(&start, NULL);
    /* Profiling */
    for (profiling_count = 0; profiling_count < 10000; profiling_count++) {
        data.number = random_number_generator(range);
        vectorIncrementalInsert(vector_ref, profiling_count, data);
    }
    gettimeofday(&stop, NULL);
    start_time = (start.tv_sec * 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec * 1000000) + stop.tv_usec;
    final_time = stop_time - start_time;
    printf("Profiling Time for Incremental expansion Insert version = %ld ms.\n", final_time);
    vectorDelete(vector_ref);
    /* Profiling incremental Expansion end */
    vector_ref = NULL;
    printf("\nAll nodes are Removed. Vector is Empty now\n");
    /* PART 1 (B) --- END */


    /* ------ PART 2 LINKED-LIST START ------- */
    int i;
    int input;
    srand(time(0));
    Linked_List *linkedlist = createList();
    printf("Going to insert 10 random numbers in the Linked List \n");
    printf("Inserting below mentioned values \n");
    /* Generating 10 random  */
    count = 0;
    while (count < 20) {
        data.number = random_number_generator(100);
        insert(linkedlist, count, data);
        printf("Index : %d | Value : %d \n", count, data.number);
        count++;
    }

    printf("Printing Linked List values \n");
    printLinkedList(linkedlist);
    int length_linkedlist;
    length_linkedlist = length_linked_list(linkedlist);
    data.number = random_number_generator(range);
    printf("Going to insert data = %d at Index 20 in linked list of length %d \n", data.number, length_linkedlist);
    insert(linkedlist, 20, data);
    printf("printing Inserted values on the Linked List\n");
    printLinkedList(linkedlist);
    //    printLinkedListBackward(linkedlist);

    printf("\nEnter the number for forward search \n");
    int value_search, value_found;
    scanf("%d", &value_search);
    value_found = searchForward(linkedlist, value_search);
    if (value_found < 0) {
        printf("The Value was not found \n");
    } else {
        printf("Found at Index : %d \n", value_found);
    }

    printf("\nEnter the number for backward search \n");
    scanf("%d", &value_search);
    value_found = searchBackward(linkedlist, value_search);
    if (value_found < 0) {
        printf("The Value was not found \n");
    } else {
        printf("Found at Index : %d \n", value_found);
    }

    printLinkedList(linkedlist);
    int removeindex, removeStatus, removecount;
    removecount=0;
    length_linkedlist = length_linked_list(linkedlist);
    printf("Length of Linked List before deletion : %d \n", length_linkedlist);
    while (removecount <= length_linkedlist && length_linkedlist > 0) {
        printf("Enter the node index you want to remove.\t Linked List current size = %d \n\tEnter 99 to exit.",length_linkedlist);
        scanf("%d", &removeindex);
        removeStatus = removeNode(linkedlist, removeindex);
        printLinkedList(linkedlist);
        length_linkedlist = length_linked_list(linkedlist);
        if(removeindex == 99){
            break;
        }
    }
    delete_linked_list(linkedlist);
    linkedlist = NULL;
    printf("\nAll nodes are Removed. Linked List is Empty\n");
    
    /* ------ PART 2 LINKED-LIST END------- */

    /* ------ PART 3 (A) - STACK ------- START */
    printf("\nEnter any 5 numbers to store in Stack \n");
    Stack *stack = creatStack();
    for (i = 0; i < 5; i++) {
        scanf("%d", &input);
        push(stack, input);
    }

    printf("\nStack\n");
    printLinkedList(stack->linked_list);

    printf("Popping Data from the Stack \n");
    printf("Index : Popped Value\n");
    for (i = 0; i < 5; i++) {
        input = pop(stack);
        printf("%d : %d\n", i, input);
    }
    deleteStack(stack);
    stack = NULL;
    printf("\nAll nodes are Removed. Stack is Empty now\n");
    
    /* ------ PART 3 (A) - STACK ------- END */
    /* ------ PART 3 (A) - QUEUE ------- START */

    printf("\nEnter any 5 numbers to store in Queue \n");
    Queue* queue = createQueue();
    for (i = 0; i < 5; i++) {
        scanf("%d", &input);
        enqueue(queue, input);
    }

    printf("Queue ");
    printLinkedList(queue->linked_list);
    printf("Dequeue of the Queue \n");
    for (i = 0; i < 5; i++) {
        input = dequeue(queue);
        printf("%d : %d\n", i, input);
    }
    deleteQueue(queue);
    queue = NULL;
    printf("\nAll nodes are Removed. Queue is Empty now\n");
    
    /* ------ PART 3 (A) - QUEUE ------- END */

    return 0;
}