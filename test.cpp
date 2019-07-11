#include <iostream>

using namespace std;

struct before {
	string name, title;
};

struct node {
	struct before b;
	struct node *next;
};

node *head = NULL;
node *tail = NULL;
node *baru;

void Insert(struct before data) {
	baru = new(node);

	baru->b = data;

	if (head == NULL) {
		head = baru;
		tail = baru;
	}
	else {
		tail->next = baru; 
		tail = baru;
		tail->next = nullptr;
	}
}

int main() {
	struct before data = { "1", "1" };
	Insert(data);
}