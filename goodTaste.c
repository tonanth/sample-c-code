#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int val;
    node* next;
};

node* head;

void print_list(){
    node* current = head;
    printf("\n");
    while(current != NULL){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

void bad_taste_removal(node* entry) {
    node* prev = NULL;
    node* walk = head;

    //Walk the list

    while(walk != entry){
        prev = walk;
        walk = walk->next;
    }

    if(prev == NULL)
        head = entry->next;
    else
        prev->next = entry->next;
}

// Gets rid of the if statement and makes the corner case become the general case
// One of the indicators of "good taste"
void good_taste_removal(node* entry){
    // The "indirect" pointer points to the
    // address of the node we'll update

    node** indirect = &head;

    // Walk the list, looking for the thing that
    // points to the entry we want to remove

    while ((*indirect) != entry)
        indirect = &(*indirect)->next;

    //... and just remove it
    *indirect = entry->next;
}

/**
 * A somewhat crude C implementation of the remove entry in a linked list code presented
 * by the creator of the Linux kernel, Linus Torvalds.
 * Pay no attention to the quality of the boilerplate code, the star of the show are the
 * two functions above, bad_taste_removal and good_taste_removal. The function names are
 * self-explanatory.
 */


int main(){
    int n_nodes = 50;
    node** nodes = malloc(sizeof(node*)*n_nodes);   // Using this array as a sanity check.
                                                    // And for me to easily remove random elements
                                                    // from the linked list via pointer.
    nodes[0] = malloc(sizeof(node));
    nodes[0]->val = 0;
    int i;
    for(i = 1; i < n_nodes; i++){
        nodes[i] = malloc(sizeof(node));
        nodes[i]->val = i;
        nodes[i-1]->next = nodes[i];
    }
    nodes[n_nodes-1]->next=NULL;
    printf("Now checking node pointer array. It should be counting up starting from 0 to 49 inclusive.\n");
    for(i = 0; i < n_nodes; i++){
        printf("%d ", nodes[i]->val);
    }
    head = nodes[0];
    printf("\nNow checking the singly linked list itself.");
    print_list();
    bad_taste_removal(nodes[42]);
    print_list();
    good_taste_removal(nodes[0]);
    print_list();
}

