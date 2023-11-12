#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node* next;

	Node(int x) {
		val = x;
		next = nullptr;
	}
};

void print(Node* head) {
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
}

/* filtrowanie listy tylko nieparzyste */
void mod(Node* head) {
	while (head -> next) {
		if (head->val %2 == 1) 
			if (head->next)
				head->next = head->next->next;
		if (head -> next)
			head = head -> next;
	}

}
/* filtrowanie listy tylko parzyste*/
void mod1(Node* head) {
	while (head -> next) {
		if (head->val %2 == 0) 
			head->next = head->next->next;
		head = head -> next;
	}

}

int main(){

	Node* head = new Node(1);
	Node* temp = head;

	for (int i=2; i<=10; i++) {
		Node* next = new Node(i); 

		temp->next = next; 
		temp = temp->next;
	}
	mod1(head);
	
	print(head);


}
