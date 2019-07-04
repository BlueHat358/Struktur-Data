#include <iostream>

#include "model.h"

int a, n;
int pub_price;

struct node {
   string name, title, date;
   int price, key;
   struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
struct node* temp1;

void Insert(string name, string title, string date, int price) {

   if (rear == NULL) {
      n++;
      rear = (struct node *)malloc(sizeof(struct node));
      rear->next = NULL;
      rear->name = name;
      rear->title = title;
      rear->date = date;
      rear->price = price;
      front = rear;
   } else {
      n++;
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
   int m = 0;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue is empty"<<endl;
   }
   while(temp != NULL){
      xy(1,m+3);
      cout << temp->name;
      xy(43,m+3);
      cout << temp->title;
      xy(71,m+3);
      cout << temp->date;
      xy(95,m+3);
      cout << "Rp. " << temp->price;
      temp = temp->next;
      m++;
   }
}

void findIndex(int n) {
   temp = front;
   char b;
   bool ada;
   while(temp != NULL){
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
}

void removeElement(int c) {
    temp = front;
    if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
    }
    else {
        if(temp->next != NULL){
            if(c == 1){
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