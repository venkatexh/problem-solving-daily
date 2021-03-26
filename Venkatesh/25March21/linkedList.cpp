#include<iostream>

class node {
  public:
  int data;
  node* next;
};

class LinkedList {
  public:
  LinkedList() {
    head = NULL;
  }
  ~LinkedList(){}
  void insertLast(int k);
  void traverse();
  node* head;
};

void LinkedList::insertLast(int k) {
  node* new_node = new node();
  new_node->data = k;
  new_node->next = NULL;
  if(head == NULL) {
    head = new_node;
  } else {
    node* temp = head;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}

void LinkedList::traverse() {
  if(head == NULL) {
    std::cout << "List empty.";
  } else {
    node* temp = head;
    while(temp != NULL) {
      std::cout << "->" << temp->data;
      temp = temp->next;
    }
    std::cout << std::endl;
  }
}

// Using two pointers

void moveLastToFirstTwo(node **head) {
  if(head == NULL) {
    std::cout << "Empty list.";
    return;
  } 
  node* p = *head, *q = *head;
  while(q->next != NULL) {
    p = q;
   q = q->next;
  }
  p->next = NULL;
  q->next = *head;
  *head = q;
}

// Using one pointer

void moveLastToFirstOne(node **head) {
  if(head == NULL) {
    std::cout << "Empty list.";
    return;
  }
  node *p = *head;
  while(p->next->next != NULL) {
    p = p->next;
  }
  p->next->next = *head;
  *head = p->next;
  p->next = NULL;

}

int main() {
  LinkedList *list = new LinkedList();
  list->insertLast(10);
	list->insertLast(20);
	list->insertLast(30);
	list->insertLast(40);
	list->traverse();
  moveLastToFirstOne(&list->head);
  list->traverse();
  moveLastToFirstTwo(&list->head);
  list->traverse();
	delete list;
	return 0;
}
