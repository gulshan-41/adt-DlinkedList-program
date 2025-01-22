// Implementing Doubly Linked List - abstract data type.

#include <stdio.h>      // for: input & output.
#include <conio.h>      // for: getch();
#include <stdlib.h>     // for: exit(), system();

// Structure that contains a data variable & two pointers variables of it's own type. (NODE)
struct node {
    struct node *linkP;
    int data;
    struct node *linkN;
};

/* head node (short for headN) globally declared to reduce the number of parametes, 
++accessibility across program. */
struct node *headN = NULL;
int nodeCounter = 1;

void welcomeScreen();       // Introduction to main page & choice screen.
void screenCleaner();       // Clear the console & input buffer.

// Insertion choice screen & function.
void insertion();
void atBeginning();
void atEnd();
void atSpecificPosition();
void afterASpecificNode();
void beforeASpecificNode();

void deletion();
void theFirstNode();
void theLastNode();



void printL();
void tryAgain(int );

// Driver code.
void main () {
    welcomeScreen();
}

// Welcomescreen.
void welcomeScreen() {
    screenCleaner();

    int choice;

label1:
    screenCleaner();
    printf("-- Impelementing & demonstrating operations on Doubly Linked List.\n\n");

    printf("*Read the options carefully and choose.\n");
    printf("> 1. Insertion.\n");
    printf("> 2. Deletion.\n");
    printf("> 3. Update.\n");
    printf("> 4. Search.\n");
    printf("> 5. Sort.\n");
    printf("> 6. Reverse.\n");
    printf("> 7. Exit the program.\n\n");

    printf("*NOTE: Before choosing options like deletion, search,\n"
           "reverse,. must insert enough elements.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("Error! choose from the given options.\n");
            printf("Press any key to exit...");
            getch();
            goto label1;
    }
}

// Traverse through the list and print the elements.
void printL() {
    struct node *p = NULL;
    p = headN;
    
    if(headN == NULL) {
        printf("Alert: the list is empty!\n");
        return;
    }

    printf("\nThe List: ");
    while(p != NULL) {
        printf("| %d |", p->data);
        p = p->linkN;
    }
    printf("\n");
}

void insertion() {
    screenCleaner();
    if(headN == NULL) {
        headN = malloc(sizeof(struct node));
        if(!(headN)) {
            printf("\nError: Memory allocation failed!\n");
            exit(1);
        } else {
            printf("Important: Before inserting further nodes,\n"
                   "in the list must create the head NODE!\n");
            printf("\nheadN->data: ");
            scanf("%d", &(headN->data));

            headN->linkN = NULL;
            headN->linkN = NULL;
        }
    }
    
    int choice1;

label2:
    screenCleaner();
    printf("-- Insertion.\n\n");
    printf("Options: \n");
    printf("> 1. At the beginning.\n");
    printf("> 2. At the end.\n");
    printf("> 3. At a specific position.\n");
    printf("> 4. After a specific node.\n");
    printf("> 5. Before a specific node.\n");
    printf("> 6. Exit from this section.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch(choice1) {
        case 1:
            atBeginning();
            printL();
            tryAgain(1);
            break;
        case 2:
            atEnd();
            printL();
            tryAgain(1);
            break;
        case 3:
            atSpecificPosition();
            printL();
            tryAgain(1);
            break;
        case 4:
            afterASpecificNode();
            printL();
            tryAgain(1);
            break;
        case 5:
            beforeASpecificNode();
            printL();
            tryAgain(1);
            break;
        case 6:
            welcomeScreen();
            break;
        default:
            printf("\nError! choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            goto label2;
    }
}

// Insert a node at the beginning of the list.
void atBeginning() {
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    }

    printf("\nnewNode->data: ");
    scanf("%d", &(newNode->data));

    newNode->linkN = headN;
    newNode->linkP = NULL;
    headN = newNode;

    nodeCounter++;
}

// Insert a node at the end to the list.
void atEnd() {
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    }

    printf("\nnewNode->data: ");
    scanf("%d", &(newNode->data));

    struct node *end = headN;
    newNode->linkN = NULL;
    newNode->linkP = NULL;
            
    while(end->linkN != NULL) {
        end = end->linkN;
    }
    end->linkN = newNode;
    newNode->linkP = end;

    nodeCounter++;
}

// Insert a node at a specified serial number.
void atSpecificPosition() {
    int index;

    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    } else {
        printf("\nnewNode->data: ");
        scanf("%d", &(newNode->data));
        newNode->linkN = NULL;
        newNode->linkP = NULL;
        printf("serial: ");
        scanf("%d", &index);

        struct node *p = headN;

        // The serial number should be between the list, or at the end.
        if(index > nodeCounter + 1 || index < 1) {
            printf("\nError: Enter a valid serial number.");
            printf("\nPress any key to continue...");
            getch();
            insertion();
        } else if(index == 1) {
            newNode->linkN = headN;
            newNode->linkP = NULL;
            headN = newNode;
        } else {
            index = index - 1;
            while(index != 1) {
                p = p->linkN;
                index--;
            }
            newNode->linkN = p->linkN;
            newNode->linkP = p;
            p->linkN = newNode;
        }
    }

    nodeCounter++;
}

// Insert a node "after" a specified node (by value), the occuring would be considered.
void afterASpecificNode() {
    int target, i , choice, flag = 0;

    if(headN == NULL) {
        printf("\nError: The list is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    printL();
    printf("*Searching it by value, the first occuring would be considered.\n\n");
    printf("element: ");
    scanf("%d", &target);

    struct node *p = headN;

    for(i = 1; i <= nodeCounter; i++) {
        if(target == p->data) {
            flag++;
            break;
        }
        p = p->linkN;
    }

    if(flag == 0) {
        printf("\nError: Element not found! Check the list & enter a valid element.");
        printf("\nPress any key to continue...");
        getch();
        insertion();
    }

    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    }
    printf("newNode->data: ");
    scanf("%d", &(newNode->data));

    newNode->linkN = p->linkN;
    p->linkN = newNode;
    newNode->linkP = p;

    nodeCounter++;
}

void beforeASpecificNode() {
    int target, i , choice, flag = 0;

    if(headN == NULL) {
        printf("\nError: The list is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    printL();
    printf("*Searching it by value, the first occuring would be considered.\n\n");
    printf("element: ");
    scanf("%d", &target);

    struct node *p1 = headN;
    struct node *p2 = NULL;

    for(i = 1; i <= nodeCounter; i++) {
        if(target == p1->data) {
            flag++;
            break;
        }
        p2 = p1;
        p1 = p1->linkN;
    }

    if(flag == 0) {
        printf("\nError: Element not found! Check the list & enter a valid element.");
        printf("\nPress any key to continue...");
        getch();
        insertion();
    }

    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    }
    printf("newNode->data: ");
    scanf("%d", &(newNode->data));

    if (p2 == NULL) {
        newNode->linkN = headN;
        headN->linkP = newNode;
        headN = newNode;
    } else {
        newNode->linkN = p1;
        newNode->linkP = p2;
        p2->linkN = newNode;
        p1->linkP = newNode;
}


    nodeCounter++;
}

void deletion() {
    screenCleaner();

    if(headN == NULL) {
        printf("\nAlert: The list is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    int choice2;

label3:
    screenCleaner();
    printf("-- Deletion.\n\n");
    printf("Options: \n");
    printf("> 1. First node.\n");
    printf("> 2. Last node.\n");
    printf("> 3. A specific node.\n");
    printf("> 4. Exit from this section.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice2);

    switch(choice2) {
        case 1:
            theFirstNode();
            printL();
            tryAgain(2);
            break;
        case 2:
            theLastNode();
            printL();
            tryAgain(2);
            break;
        default:
            printf("\nError! choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            goto label3;
    }
}

void theFirstNode() {
    struct node *p = headN;
    headN = (headN)->linkN;
        
    free(p);
    p = NULL;

    nodeCounter--;
}

void theLastNode() {
    if((headN)->linkN == NULL) {
        free(headN);
        headN = NULL;
    } else {
        struct node *p1 = headN;
        struct node *p2 = NULL;

        while(p1->linkN != NULL) {
            p2 = p1;
            p1 = p1->linkN;
        }
        p2->linkN = NULL;
        free(p1);
        p1 = NULL;
    }

    nodeCounter--;
}

// Try again program.
void tryAgain(int choice) {
    char ch;

    printf("\nDo you want to try again[y/N]: ");
    scanf(" %c", &ch);

    switch(ch) {
        case 'y':
        case 'Y':
            if(choice == 1) {
                insertion();
            } else {
                deletion();
            }
            break;
        case 'n':
        case 'N':
            welcomeScreen();
            break;
        default:
            printf("\nError: invalid input. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
    }
}
// Screen cleaner function.
void screenCleaner() {
    system("cls");
    fflush(stdin);
}