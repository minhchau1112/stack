#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

struct Stack {
	Node* top;
};

void Init(Stack& s) {
	s.top = NULL;
}

bool isEmpty(Stack s) {
	if (s.top == NULL)return true;
	return false;
}

void Push(Stack& s,int data) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "Stack Overfolow" << endl;
		return;
	}
	p->data = data;
	p->next = s.top;
	s.top = p;
}

void Pop(Stack& s) {
    Node* p;
    if (s.top == NULL)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    else
    {
        p = s.top;
        s.top = s.top->next;
        delete[] p;
    }
}

void DisPlay(Stack s) {
	if (isEmpty(s))return;
	for (Node* p = s.top; p; p = p->next) {
		cout << p->data << " ";
	}
	cout << endl;
}

int main() {
	Stack s;
	Init(s);
	Push(s, 10);
	Push(s, 30);
	Push(s, 18);
	Push(s, 3);
	Push(s, 5);
	Push(s, 40);
	Push(s, 24);
	Pop(s);
	DisPlay(s);
	return 0;
}