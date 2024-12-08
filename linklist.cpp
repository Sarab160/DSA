using namespace std;
#include<iostream>

class Node {
public:
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = NULL;
	}

	//destructor
	~Node() {
		int value = this->data;
		if (this->next != NULL) {
			delete next;
			this->next = NULL;
		}
		cout << "Memory is free for node with data: " << value << endl;
	}
};

void insertatstart(Node*& head, int data) {
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;


}
void insertatend(Node* &tail, int data) {
	Node* temp = new Node(data);
	tail->next = temp;
	tail = temp;


}
void insertatmid(Node*& head, int pos, int data) {
	Node* temp = head;
	int i = 1;
	while (i < pos - 1) {
		temp = temp->next;
		i++;
	}
	Node* mid = new Node(data);
	mid->next = temp->next;
	temp->next = mid;

}
void deletenode(int postion, Node*& head) {
	if (postion == 1) {
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else {
		Node* curr = head;
		Node* prev = NULL;
		int cnt = 1;
		while (cnt < postion) {
			curr = curr->next;
			prev = curr;
			cnt++;
		}
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}
}
void print(Node*& head) {
	Node* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	Node* n1 = new Node(10);
	
	
	Node* head = n1;

	insertatstart(head, 12);

	print(head);
	Node* tail = n1;
	insertatend(tail,6);
	print(tail);
	
	insertatmid(head, 3, 67);
	print(head);
	deletenode(1, head);
	print(head);
	return 0; 
}