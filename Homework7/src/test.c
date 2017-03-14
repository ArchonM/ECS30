
#include <stdio.h>
#include <stdlib.h>


#define MAX_BUFFER_SIZE 64
struct ListNode;

typedef enum {OFF, ON, DYING} CellState;

typedef struct {
    int x, y;
    CellState s;
} Cell;

typedef struct {
    struct ListNode* head;
    int size;
} List;

typedef struct ListNode {
    Cell data;
    struct ListNode* next;
} ListNode;


/*
 * Input:
 *      List* list, a List to print
 * Summary:
 *      Prints elements from list, starting with the head
 */
void List_Print(List* list) {
    // TODO: complete this function
    listNode* NodePT;
    NodePT = 
}
/*
 * Output:
 *      Returns a newly allocated List
 * Summary:
 *      Allocates space for an empty new List and returns it
 */

List* List_Create() {
    List* result = malloc(sizeof(List));
    if (result != NULL) {
        result->head = NULL;
        result->size = 0;
    }
    return result;
}

/*
 * Input:
 *      FILE* fp, a file pointer pointing to a read-only open file
 * Output:
 *      Returns a newly allocated list
 * Summary:
 *      Reads Cells from a file and puts them in a new List
 */
List* List_Read(FILE* fp) {
    char buffer[MAX_BUFFER_SIZE];
    List* result;
    if (fp == NULL) {
        printf("List_Read Error: NULL parameter passed.\n");
        exit(0);
    }
    result = List_Create();
    while (fgets(buffer, MAX_BUFFER_SIZE, fp)) {
        Cell C = Cell_ReadCell(buffer);
        List_PushFront(result, C);
    }
    return result;
}

/*
 * Input:
 *      List* list, the List to delete
 * Summary:
 *      Calls free on every node to deallocate memory
 *      used by the nodes of the List, then deallocates
 *      the list itself
 */
void List_Delete(List* list) {
    ListNode* currentNode = list->head;
    while (currentNode != NULL) {
        ListNode* nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    free(list);
    return;
}

/*
 * Input:
 *      List* list, a List to add data to
 *      Cell data, data to add to the list
 * Output:
 *      Returns the size of list after adding data
 * Summary:
 *      Adds a data to the front of list
 */
int List_PushFront(List* list, Cell data) {
    ListNode* newNode = ListNode_Create(data, list->head);
    if (newNode != NULL) {
        list->head = newNode;
        list->size++;
    }
    return list->size;
}



/*
 * Input:
 *      Cell data, data for the ListNode
 *      ListNode* node, the next node after the ListNode
 * Output:
 *      Returns a ListNode* to a newly allocated ListNode
 * Summary:
 *      Allocates space for a ListNode and initializes its
 *      data and node members
 */
ListNode* ListNode_Create(Cell data, ListNode* node) {
    ListNode* listNode = (ListNode*) malloc(sizeof(ListNode));
    if (listNode != NULL) {
        listNode->data = data;
        listNode->next = node;
    }
    return listNode;
}
void flushStdin();

int main() {
    char buffer[MAX_BUFFER_SIZE];
    char action;
    List* list = List_Create();
    do {
        printf("Type 'c' to enter a cell or 'q' to quit: ");
        action = getchar();
        flushStdin();
        if (action != 'c' && action != 'q') {
            printf("Invalid command.\n");
        } else if (action == 'c') {
            printf("Enter a cell: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);
            List_PushFront(list, Cell_ReadCell(buffer));
        }
    } while(action != 'q');
    List_Print(list);
    List_Delete(list);
    return 0;
}

void flushStdin() {
    char c;
    while ((c = getchar()) != EOF && c != '\n') {};
}
