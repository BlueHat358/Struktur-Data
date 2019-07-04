#include <iostream>

#include "model.h"

int n = 1, a, c = 1;

struct node {
   string name, title, date;
   int price;
   struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
struct node* temp1;

void Insert(string name, string title, string date, int price) {
   if (rear == NULL) {
      rear = (struct node *)malloc(sizeof(struct node));
      rear->next = NULL;
      rear->name = name;
      rear->title = title;
      rear->date = date;
      rear->price = price;
      temp->name = name;
      front = rear;
   } else {
      temp=(struct node *)malloc(sizeof(struct node));
      rear->next = temp;
      temp->name = name;
      temp->title = title;
      temp->price = price;
      temp->date = date;
      temp->next = NULL;
      rear = temp;
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
            cout << temp->price << "|" << temp->key << temp->index;
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
        b = temp->key;
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