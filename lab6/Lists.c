
#include "Lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <sys/time.h>

/* Function to generate random number */
unsigned int random_number_generator(unsigned int range) {
    range = rand() % range + 1;
    return range;
}

/* Vector Start */
vector* createVector() {
    vector* Vector;
    Data* data;
    Vector = malloc(sizeof (vector));
    data = malloc(sizeof (data));
    Vector->max_size = 1;
    Vector->current_size = 0;
    data->number = -1;
    Vector->data = data;
    return Vector;
}

void vectorInsert(vector *array, int index, Data value) {
    if (array == NULL || array->data == NULL) {
        return;
    } else {
        //        printf("initial Max Size %d and Current Size -> %d\n", array->current_size, array->max_size);
        if (index >= 0) {
            int new_max_size;
            new_max_size = 0;
            Data *temp;
            if (array->max_size < (index + 1)) {
                new_max_size = array->max_size * 2;
                //                printf("Later Max Size %d\n", new_max_size);
                Data *new_data = malloc(new_max_size * sizeof (Data));
                while ((index + 1) > new_max_size) {
                    free(new_data);
                    new_max_size = new_max_size * 2;
                    new_data = malloc(new_max_size * sizeof (Data));
                    array->max_size = new_max_size;
                    //                    printf("Current Size -> %d  and Final Max Size -> %d\n", array->current_size, array->max_size);
                }
                array->max_size = new_max_size;
                int nav_index = 0;
                //                 printf("Initialized values before populating newmaxsize is %d\n",new_max_size);
                while (nav_index < new_max_size) {
                    new_data[nav_index].number = -1;
                    //                    printf("Index === %d and Data ==== %d \n", nav_index, new_data[nav_index].number);
                    nav_index++;
                }
                //                printf("Printing values before populating\n");
                //                printVector(array);
                //                printf("Populating values\n");
                nav_index = 0;
                while (nav_index < array->current_size) {
                    new_data[nav_index].number = array->data[nav_index].number;
                    //                    printf("Copying values: Index : %d and replaced value : %d Replaced by : %d \n", nav_index, new_data[nav_index].number, array->data[nav_index].number);
                    nav_index++;
                }
                //                temp = array->data;
                free(array->data);
                array->data = new_data;
                array->data[index].number = value.number;
                //                printf("Final value copy ||| Index is : %d and Value : %d || New Populated value : %d\n", index, value.number,array->data[index].number);
                array->current_size = index + 1;
            } else {
                //                printf("else\n");
                array->data[index].number = value.number;
                array->current_size = index + 1;
                //                printf("Index : 0 | Data : %d \n",array->data[index].number);
            }

        } else {
            printf("Insertion not possible at negative index \n");
        }
    }
}

void vectorIncrementalInsert(vector *array, int index, Data value) {
    if (array == NULL || array->data == NULL) {
        return;
    } else {
        //        printf("initial Max Size %d and Current Size -> %d\n", array->current_size, array->max_size);
        if (index >= 0) {
            int new_max_size;
            new_max_size = 0;
            Data *temp;
            if (array->max_size < (index + 1)) {
                new_max_size = array->max_size + 1;
                //                printf("Later Max Size %d\n", new_max_size);
                Data *new_data = malloc(new_max_size * sizeof (Data));
                while ((index + 1) > new_max_size) {
                    free(new_data);
                    new_max_size = new_max_size + 1;
                    new_data = malloc(new_max_size * sizeof (Data));
                    array->max_size = new_max_size;
                    //                    printf("Current Size -> %d  and Final Max Size -> %d\n", array->current_size, array->max_size);
                }
                array->max_size = new_max_size;
                int nav_index = 0;
                //                 printf("Initialized values before populating newmaxsize is %d\n",new_max_size);
                while (nav_index < new_max_size) {
                    new_data[nav_index].number = -1;
                    //                    printf("Index === %d and Data ==== %d \n", nav_index, new_data[nav_index].number);
                    nav_index++;
                }
                //                printf("Printing values before populating\n");
                //                printVector(array);
                //                printf("Populating values\n");
                nav_index = 0;
                while (nav_index < array->current_size) {
                    new_data[nav_index].number = array->data[nav_index].number;
                    //                    printf("Copying values: Index : %d and replaced value : %d Replaced by : %d \n", nav_index, new_data[nav_index].number, array->data[nav_index].number);
                    nav_index++;
                }
                //                temp = array->data;
                free(array->data);
                array->data = new_data;
                array->data[index].number = value.number;
                //                printf("Final value copy ||| Index is : %d and Value : %d || New Populated value : %d\n", index, value.number,array->data[index].number);
                array->current_size = index + 1;
            } else {
                //                printf("else\n");
                array->data[index].number = value.number;
                array->current_size = index + 1;
                //                printf("Index : 0 | Data : %d \n",array->data[index].number);
            }

        } else {
            printf("Insertion not possible at negative index \n");
        }
    }
}

void vectorRemove(vector *array, int index) {
    if (array == NULL) {
        return;
    } else {
        if (index > array->max_size) {
            return;
        } else {
            array->data[index].number = -1;
            array->current_size -= 1;
        }
    }
}

int vectorRead(vector *array, int index) {
    if (array == NULL) {
        return -1;
    }
    if (index > array->max_size) {
        return -1;
    } else {
        return array->data[index].number;
    }
}

vector *vectorDelete(vector *array) {
    if (array == NULL) {
        return NULL;
    } else {
        free(array->data);
        free(array);
        array = NULL;
        return NULL;
    }
}

int maxSizeVector(vector *array) {
    printf("Vector Max Size = %d \n", array->max_size);
    return array->max_size;
}

int currentSizeVector(vector *array) {
    printf("Vector Current Size = %d \n", array->current_size);
    return array->current_size;
}

void printVector(vector *array) {
    int nav_index = 0;
    printf("Printing Vector Values with max_size is %d  \n", array->max_size);
    while (nav_index < array->max_size) {
//        printf("Index : %d | Value : %d \n", nav_index, array->data[nav_index].number);
        nav_index++;
    }
}
/* Vector END */

/* Linked List Functions - START */
Node *createNode() {
    Node *node = (Node*) malloc(sizeof (Node));
    node->data.number = INT_MIN;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Linked_List *createList() {
    Linked_List *linkedlist = (Linked_List*) malloc(sizeof (Linked_List));
    linkedlist->head_node = NULL;
    return linkedlist;
}

Node *front(Linked_List *linkedlist) {
    return linkedlist->head_node;
}

void printLinkedList(Linked_List *linkedlist) {
    if (linkedlist == NULL) {
        printf("Linked List is empty\n");
    } else {
        printf("Printing Linked List\n");
        Node *currentnode = front(linkedlist);
        while (currentnode != NULL) {
            printf(" %d \n", currentnode->data.number);
            currentnode = currentnode->next;
        }
    }
}

void printLinkedListBackward(Linked_List *linkedlist) {
    if (linkedlist == NULL) {
        printf("Linked List is empty\n");
    } else {

        Node *currentnode;
        Node *previousnode;
        currentnode = linkedlist->head_node;
        int length;
        length = 0;
        int back_index;
        back_index = 1;
        while (currentnode != NULL) {
            previousnode = currentnode;
            currentnode = currentnode->next;
            length++;
        }
        currentnode = previousnode;
        printf("Printing Linked List Backward \n");
        while (currentnode != NULL) {
            printf(" %d \n", currentnode->data.number);
            currentnode = currentnode->prev;
            //            currentnode = previousnode;

        }
    }
}

//
//void printLinkedListBackward(Linked_List *linkedlist){
//    if(linkedlist == NULL){
//        printf("Linked List is empty\n");
//    }else{
//         printf("Printing Linked List Backward \n");
//        Node *currentnode;
//        Node *previousnode;
//        currentnode = linkedlist->head_node;
//        int length;length=0;
//        int back_index;back_index=1;
//        while(currentnode!=NULL){
//            previousnode = currentnode;
//            currentnode =  currentnode->next;
//            length++;
//        }
//        
//        while(previousnode != NULL){
//            printf(" %d \n", previousnode->data.number);
//            currentnode = previousnode;
//            previousnode = previousnode->prev;
//        }
//    }
//}

int length_linked_list(Linked_List *linkedlist) {
    int length_linkedlist;
    length_linkedlist = 0;
    if (linkedlist != NULL) {
        Node *currentnode = front(linkedlist);
        while (currentnode != NULL) {
            currentnode = currentnode->next;
            length_linkedlist++;
        }
    }
    return length_linkedlist;
}

Node *insert(Linked_List *linkedlist, int index, Data value) {

    if (linkedlist->head_node == NULL) {
        Node* new_created_node = createNode();
        new_created_node->data = value;
        linkedlist->head_node = new_created_node;
        return new_created_node;
    }

    Node* current_node = linkedlist->head_node;
    Node* previous_node;

    if (index == 0) {
        Node* new_created_node = createNode();
        new_created_node->data = value;
        linkedlist->head_node->prev = new_created_node;
        new_created_node->next = linkedlist->head_node;
        linkedlist->head_node = new_created_node;

        //        new_created_node->next = current_node;
        //        new_created_node->prev = new_created_node;
        //        linkedlist->head_node = new_created_node;
        return new_created_node;
    }

    Node *new_node_to_be_added = createNode();
    new_node_to_be_added->data = value;

    int length_linkedlist;
    length_linkedlist = length_linked_list(linkedlist);
    int counter;
    counter = 0;
    if (index < length_linkedlist) {
        while (counter < (index - 2)) {
            counter++;
            current_node = current_node->next;
        }
        printf("Counter in less %d \n", counter);
        Node * nextnode = current_node->next;
        current_node->next = new_node_to_be_added;
        new_node_to_be_added->prev = current_node;
        new_node_to_be_added->next = nextnode;
        current_node->next->prev = new_node_to_be_added;
        return new_node_to_be_added;
    } else if (index == length_linkedlist) {
        while (counter < (index - 1)) {
            counter++;
            current_node = current_node->next;
        }
        printf("Counter in equal %d \n", counter);
        current_node->next = new_node_to_be_added;
        new_node_to_be_added->prev = current_node;
        //        new_node_to_be_added->next = NULL;
        return new_node_to_be_added;
    } else {
//        printf("Inserting at greater index\n");
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node_to_be_added;
        new_node_to_be_added->prev = current_node;
        //        new_node_to_be_added->next = NULL;
        return new_node_to_be_added;
    }
    return 0;
}

void delete_Node(Node* delete_node) {
    free(delete_node);
    delete_node = NULL;
}

void delete_linked_list(Linked_List *linkedlist) {
    Node *current_node = linkedlist->head_node;
    Node *temp_node;
    while (current_node != NULL) {
        temp_node = current_node->next;
        free(current_node);
        current_node = NULL;
        current_node = temp_node;
    }
    free(linkedlist);
    linkedlist = NULL;
}

int removeNode(Linked_List *linkedlist, int index) {
    //    printf("Deleting Node - %d \n", index);
    if (linkedlist != NULL || linkedlist->head_node != NULL) {
        int length_linkedlist;
        length_linkedlist = length_linked_list(linkedlist);
        Node *node_to_be_deleted;
        Node *next_node;
        Node *prev_node;
        int deleted_value;
        deleted_value = 0;
        if (index == 0) {
            node_to_be_deleted = linkedlist->head_node;
            linkedlist->head_node = linkedlist->head_node->next;
            deleted_value = node_to_be_deleted->data.number;
            delete_Node(node_to_be_deleted);
            node_to_be_deleted = NULL;
            return deleted_value;
        } else if (index < (length_linkedlist - 1)) {
            Node* current_node = linkedlist->head_node;
            int counter;
            counter = 0;
            while (counter < index) {
                counter++;
                prev_node = current_node;
                current_node = current_node->next;
            }
//            printf("After while counter : %d  and index is %d \n", counter, index);
//            printf("Current Node Value = %d\n", current_node->data.number);
            node_to_be_deleted = current_node;
            deleted_value = node_to_be_deleted->data.number;
            prev_node->next = current_node->next;
            current_node->next->prev = prev_node;
            current_node = current_node->next;
            delete_Node(node_to_be_deleted);
            node_to_be_deleted = NULL;
            return deleted_value;
        } else if (index == (length_linkedlist - 1)) {
            Node* current_node = linkedlist->head_node;
            int counter;
            counter = 0;
            while (counter < index) {
                counter++;
                prev_node = current_node;
                current_node = current_node->next;
            }
//            printf("Last Node deleting\n");
//            printf("After while counter : %d  and index is %d \n", counter, index);
//            printf("Current Node Value = %d\n", current_node->data.number);
            node_to_be_deleted = current_node;
            deleted_value = node_to_be_deleted->data.number;
            prev_node->next = NULL;
            delete_Node(node_to_be_deleted);
            node_to_be_deleted = NULL;
            return deleted_value;
        } else if (index > length_linkedlist) {
            printf("\nCannot remove : Index out of Bound\n");
            return -1;
        } else if (index < 0) {
            printf("Negative Index : Removing not possible\n");
            return -1;
        }
    } else {
        printf("Negative Index : Removing not possible\n");
        return -1;
    }
    return -1;
}

int searchForward(Linked_List *linkedlist, int value) {
    printf("Searching Backward \n");
    int list_index;
    list_index = 0;
    int valueindex;
    valueindex = -1;
    Node *current_node = linkedlist->head_node;
    while (current_node != NULL) {
        printf("Index : %3d | Value : %3d \n", list_index, current_node->data.number);
        if (current_node->data.number == value) {
            valueindex = list_index;
            return valueindex;
        }
        list_index++;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return -1;
    }
    return -1;
}

int searchBackward(Linked_List *linkedlist, int value) {
    Node *currentnode;
    Node *previousnode;
    currentnode = linkedlist->head_node;
    int nav_index;
    nav_index = 0;
    int back_index;
    back_index = -1;
    while (currentnode != NULL) {
        previousnode = currentnode;
        currentnode = currentnode->next;
    }
    while (previousnode != NULL) {
        printf("Index : %3d | Value : %3d \n", nav_index, previousnode->data.number);
        if (previousnode->data.number == value) {
            back_index = nav_index;
            return back_index;
        }
        currentnode = previousnode;
        previousnode = previousnode->prev;
        nav_index++;
    }
    return back_index;
}
/* Linked List Functions - END */

/* Stack Functions - START */
Stack* creatStack() {
    Stack *stack = (Stack*) malloc(sizeof (Stack));
    stack->linked_list = createList();
    return stack;
}

void push(Stack * stack, int value) {
    Data data;
    data.number = value;
    insert(stack->linked_list, 0, data);
}

int pop(Stack *stack) {
    return removeNode(stack->linked_list, 0);
}

void deleteStack(Stack* stack) {
    delete_linked_list(stack->linked_list);
    free(stack);
    stack = NULL;
}
/* Stack Functions - END */

/* QUEUE Functions - START */
Queue* createQueue() {
    Queue *queue = (Queue*) malloc(sizeof (Queue));
    queue->linked_list = createList();
    return queue;
}

void deleteQueue(Queue *queue) {
    delete_linked_list(queue->linked_list);
    free(queue);
    queue = NULL;
}

void enqueue(Queue *queue, int value) {
    Data data;
    data.number = value;
    insert(queue->linked_list, INT_MAX, data);
}

int dequeue(Queue *queue) {
    return removeNode(queue->linked_list, 0);
}

/* QUEUE Functions - END */


