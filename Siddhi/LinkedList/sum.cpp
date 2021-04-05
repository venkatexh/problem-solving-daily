/*

Sum of two numbers stored in two different linked lists in reverse order
*/


#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* add(struct node *h1, struct node* h2)
{
    int carry = 0, sum;
    struct node* sumList = (struct node*)malloc(sizeof(struct node));
    struct node* curSum = sumList;
    while(h1!=NULL || h2!=NULL)
    {
        int x = h1!=NULL?h1->data:0;
        int y = h2!=NULL?h2->data:0;
        sum = x+y+carry;
        curSum->data = sum%10;
        curSum->next = new struct node;
        curSum = curSum->next;
        carry = sum/10;

        if(h1!=NULL) h1 = h1->next;
        if(h2!=NULL) h2 = h2->next;
    }



    if(carry>0)
    {
        curSum->data  = carry;
    }
    return sumList;
}