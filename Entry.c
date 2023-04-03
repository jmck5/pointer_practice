#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> // Boolean isn't a standard data type in C? What the hell?
// Okay my version apparently sucks. This is quite good though really. 
struct Grocery {
	char item[50];
	int quantity;
	struct Grocery* next;
};

int main() {

	printf("Welcome to the Grocery List.\n\n");
	bool keepGoing = true;
	// intialize list?
	struct Grocery *first = malloc(sizeof(struct Grocery) * 1);
	struct Grocery *current = first;

	while (keepGoing) {
		printf("What groceries would you like to add to the list?\n");
		scanf_s("%s", &current->item, 50); // Need to include length of allowed string for some reason, this is a little tricky actuall I want to use char* but then well it should be okay. hmm
		printf("Enter the quantity you would like: ");
		scanf_s("%d", &current->quantity); // also note the syntax &current->quantity, this will get the address of quantity, even though it looks a bit weird to me like I expected it to look like &(current->quantity)
		getchar(); // ugly.. this is because the "Enter" from the above line was being read and consumed later when I tried to get the char for y/n
		char addMore = 'Y';
		printf("Would you like to get anything else? yes or no? \n");
		
		addMore = getchar(); // Why is this getting skipped? still getting skipped // or reached before previous printf?
		printf("...");
		addMore = toupper(addMore);
		if (addMore == 'Y') {
			printf("You selected you want to add additional groceries.\n");
			current->next = malloc(sizeof(struct Grocery) * 1);
			current = current->next;

		}
		else {
			printf("You selected you are finished with the grocery list.\n");
			keepGoing = false;
			current->next = NULL;
			printf("Okay all done thanks.\n");
		}
	}

	printf("Okay now that the list is done, let's see what we got.\n\n");
	current = first;
	while (current) {
		printf("We got %d lots of %s. \n", current->quantity, current->item);
		current = current->next;
	};
	printf("And that should be it.\n");





	return 0;
}