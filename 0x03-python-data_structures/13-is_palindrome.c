#include <stdio.h>
#include <stdlib.h>

/* Definition of a singly linked list node */
struct Node 
{
	int data;
	struct Node* next;
}

/* Function to check if a singly linked list is a palindrome */

int is_palindrome(struct Node** head) 
{
	/* Check if the list is empty or has only one element */
	if (*head == NULL || (*head)->next == NULL) 
	{
		return 1; /* Empty list or single-element list is considered a palindrome
    }

    struct Node* slow = *head;
    struct Node* fast = *head;
    struct Node* prev = NULL;

    // Find the middle of the list and reverse the first half
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;

        struct Node* temp = slow;
        slow = slow->next;
        temp->next = prev;
        prev = temp;
    }

    // If the list has odd number of elements, skip the middle node
    if (fast != NULL) {
        slow = slow->next;
    }

    // Compare the reversed first half with the second half
    while (prev != NULL && slow != NULL) {
        if (prev->data != slow->data) {
            return 0; // Not a palindrome
        }
        prev = prev->next;
        slow = slow->next;
    }

    return 1; // Palindrome
}

// Function to create a new node with the given data
struct Node* new_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list
void push(struct Node** head, int data) {
    struct Node* new_node = new_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to print the elements of the list
void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Test the is_palindrome function
int main() {
    struct Node* head = NULL;

    // Create a palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("List: ");
    print_list(head);

    int result = is_palindrome(&head);
    if (result == 1) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    return 0;
}
