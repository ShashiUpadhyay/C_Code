
#ifndef LISTHEADERFILE
#define LISTHEADERFILE

typedef struct _Data {
    int number;
} Data;

typedef struct _vector {
    Data *data;
    int current_size;
    int max_size;
} vector;

typedef struct _Node{
    Data data;
    struct _Node *next;
    struct _Node *prev;
}Node;

typedef struct _Linked_List{
    Node *head_node;
}Linked_List;

typedef struct _Stack{
    Linked_List *linked_list;
}Stack;

typedef struct _Queue{
    Linked_List *linked_list;
}Queue;

/* Vector Function definition START */
vector* createVector();
void vectorInsert(vector *array, int index, Data value);
void vectorIncrementalInsert(vector *array, int index, Data value);
void vectorRemove(vector *array, int index);
int vectorRead(vector *array, int index);
int maxSizeVector(vector *array);
int currentSizeVector(vector *array);
void printVector(vector *array);
/* Vector Function definition END */

/* Linked List Functions - START */
Node *createNode();
Linked_List *createList();
Node *front(Linked_List *linkedlist);
void printLinkedList(Linked_List *linkedlist);
Node *insert(Linked_List *linkedlist,int index, Data value);
void delete_Node(Node* delete_node);
unsigned int random_number_generator(unsigned int range);
int removeNode(Linked_List *linkedlist, int index);
void delete_linked_list(Linked_List *linkedlist);
int searchForward(Linked_List *linkedlist, int index);
int searchBackward(Linked_List *linkedlist, int value);
void printLinkedListBackward(Linked_List *linkedlist);
/* Linked List Functions - END */

/* Stack Functions - START */
Stack* creatStack();
void push(Stack * stack, int value);
int pop(Stack * stack);
void deleteStack(Stack* stack);
/* Stack Functions - END */

/* QUEUE Functions - START */
Queue* createQueue();
void deleteQueue(Queue *queue);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
/* QUEUE Functions - END */

/* Function to generate random number*/
unsigned int random_number_generator(unsigned int range);

#endif