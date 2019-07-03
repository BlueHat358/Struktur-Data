#include <iostream>

using namespace std;
#include "model.h"

int n = 1, a, c = 1;

struct node {
   int price;
   int index;
   struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
struct node* temp1;

struct duplicate {
   int price;
   int index;
   struct duplicate *next;
};
struct duplicate* front_ = NULL;
struct duplicate* rear_ = NULL;
struct duplicate* temp_;

void Insert(int val) {
   if (rear == NULL) {
      rear = (struct node *)malloc(sizeof(struct node));
      rear->next = NULL;
      rear->price = val;
      rear->index = n;
      front = rear;
   } else {
       n++;
      temp=(struct node *)malloc(sizeof(struct node));
      rear->next = temp;
      temp->price = val;
      temp->next = NULL;
      rear = temp;
      rear->index = n;
   }
}

void Delete() {
   temp = front;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
   } else
   if (temp->next != NULL) {
      temp = temp->next;
      cout<<"Element deleted from queue is : "<<front->price<<endl;
      free(front);
      front = temp;
   } else {
      cout<<"Element deleted from queue is : "<<front->price<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}

void Display() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue is empty"<<endl;
   }
   for(int i = 0; i < n; i++){
            xy(91,i+3);
            cout << temp->price;
            temp = temp->next;
       }
}

void findIndex(int n) {
   temp = front;
   char b;
   bool ada;
   while(temp != NULL){
        c++;
        temp = temp->next;
        b = temp->index;
        if(b == n){
            ada = true;
            cout << ada;
            break;
        }else{
            ada = false;
            cout << ada;
        }
    }
    cout << c;
}

void removeElement(int c) {
    temp = front;
    if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
    }
    else {
        if(temp->next != NULL){
            if(n == 1){
                front = temp->next;
                free(temp);
                return;
            }
            for(int i = 0; i < c-2; i++){
                temp = temp->next;
            }
            temp1 = temp->next;
            temp->next = temp1->next;
            free(temp1);
        }else{
            free(front);
            front = NULL;
            rear = NULL;
        }
    } 
}