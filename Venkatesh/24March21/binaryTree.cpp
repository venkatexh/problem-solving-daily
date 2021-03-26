#include<iostream>
#include<queue>

struct node {
  int data;
  node *left;
  node* right;
};

node *newNode(int data) {
    node *new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(node *root, int data) {
    node *temp;
    std::queue<node*>q;
    q.push(root);
    while(!q.empty()) 
    {
        temp = q.front();
        q.pop();

        if(temp->left == NULL) {
            temp->left = newNode(data);
            break;
        } else {
          q.push(temp->left);
        }
            
        if(temp->right == NULL) {
            temp->right = newNode(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
}

void traversal(node *root) {
    if(root == NULL)
        return;
    traversal(root->left);
    std::cout << root->data << " ";
    traversal(root->right);
    
}

// for reference

void levelOrder(node *root) {
  if(root == NULL) {
    return;
  }
  std::queue<node *> q;
  q.push(root);
  while(!q.empty()) {
    node *curr = q.front();
    std::cout << curr->data << " ";
    if(curr->left != NULL){
      q.push(curr->left);
    } 
    if(curr->right != NULL) {
      q.push(curr->right);
    }
    q.pop();
  }
}

void leftView(node* root){
    if (root == NULL) {
        return;
    }
    std::queue<node*> queue;
    queue.push(root);
    node* curr = NULL;
    while (!queue.empty()) {
        int size = queue.size();
        int i = 0;
        while (i < size) {
            i++;
            curr = queue.front();
            queue.pop();
            if (i == 1) {
                std::cout << curr->data << " ";
            }
 
            if (curr->left) {
                queue.push(curr->left);
            }
 
            if (curr->right) {
                queue.push(curr->right);
            }
        }
    }
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(10);
    root->left->left = newNode(20);
    root->right = newNode(34);
    root->left->right = newNode(12);
    root->left->right->right = newNode(50);
    // root->left->right->left = newNode(30);
    // int key = 12;
    // insert(root, key);
    std::cout << std::endl;
    std::cout << "Inorder traversal: ";
    traversal(root);
    std::cout << std::endl;
    levelOrder(root);
    std::cout << std::endl;
    leftView(root);
}