#include<iostream>

class Node {
  public:
  int data;
  Node *next;
};

class LinkedList {
  public:
  LinkedList() {
    head = NULL;
  }
  ~LinkedList(){}
  void insertLast(int);
  void traverse();
  Node *head;
};

void LinkedList::insertLast(int k) {
  Node *new_node = new Node();
  new_node->data = k;
  new_node->next = NULL;
  if(head == NULL) {
    head = new_node;
  } else {
    Node *temp = head;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}

void LinkedList::traverse() {
  if(head == NULL) {
    std::cout << "List empty.";
    return;
  }
  Node *temp = head;
  while(temp != NULL) {
    std::cout << "->" << temp->data;
    temp = temp->next;
  }
  std::cout << std::endl;
}

//Printing first element in case of even number of elements

void findMiddle(Node *head) {
  Node *p = head, *q = head;
  while(q->next != NULL && q->next->next != NULL) {
    p = p->next;
    q = q->next->next;
  }
  std::cout << "Middle element: " << p->data;
}

int main() {
  LinkedList *list = new LinkedList();
  list->insertLast(10);
	list->insertLast(20);
	list->insertLast(30);
	list->insertLast(40);
	list->traverse();
  findMiddle(list->head);
	delete list;
	return 0;
}

