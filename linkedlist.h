#include <iostream>

#include "model.h"

int a, n;
void removeElement(int c);
void denda1(struct node *tmp);

struct times{
   int day, month, year;
};

struct node {
   string name, title, date;
   int price;
   struct times t;
   struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
struct node* temp1;

void Insert(string name, string title, string date, int price, int arr[3]) {

   int day = arr[2], month = arr[1], year = arr[0];
   struct times t = {day, month, year};

   if (rear == NULL) {
      n++;
      rear = new(node);
      rear->next = NULL;
      rear->name = name;
      rear->title = title;
      rear->date = date;
      rear->price = price;
      rear->t = t;
      front = rear;
   } else {
      n++;
      temp= new(node);
      rear->next = temp;
      temp->name = name;
      temp->title = title;
      temp->price = price;
      temp->date = date;
      temp->t = t;
      temp->next = NULL;
      rear = temp;
      if(n > 8){
         up = n - 8;
      }
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
      free(front);
      front = temp;
   } else {
      free(front);
      front = NULL;
      rear = NULL;
   }
}

void Display() {
   int z = 1;
   temp = front;
   int m = 0;
   if ((front == NULL) && (rear == NULL)) {
      // cout<<"Queue is empty"<<endl;
   }
   while(temp != NULL){
      if(z%2 == 0) 
         fg = f1;
      else
         fg = f2;
      color(fg,bg);

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
      z++;
   }
}

void findIndex(string n) {
   temp = front;
   string b;
   int ind = 0;
   bool ada;
   while(temp != NULL){
        b = temp->name;
        ind++;
        if(b.compare(n) == 0){
            ada = true;
            removeElement(ind);
            break;
        }else{
            ada = false;
        }
        temp = temp->next;
    }
}

void removeElement(int c) {
   struct node *temp2;
    temp = front;
    if (front == NULL) {
       xy(56, 13+up+11);
      cout<<"List is Empty"<<endl;
      return;
    }
    else {
        if(temp->next != NULL){
            if(c == 1){
               n--;
               up--;
                front = temp->next;
                temp2 = temp;
                free(temp);
                return;
            }
            for(int i = 0; i < c-2; i++){
                temp = temp->next;
            }
            n--;
            up--;
            temp1 = temp->next;
            temp2 = temp->next;
            temp->next = temp1->next;
            free(temp1);
        }else{
           n--;
           up--;
           temp2 = front;
            free(front);
            front = NULL;
            rear = NULL;
        }
    } 
    denda1(temp2);
}

void denda1(struct node *tmp){
   int height = 5 + MAX;
    int year, month, day, hour;
    time_t now;
    time(&now);
    tm *ltm = localtime(&now);

    struct tm temp = {0,0,0, tmp->t.day, tmp->t.month-1, tmp->t.year-1900};
    time_t temp_time = mktime(&temp);
    int diff;

    year = 1900+ltm->tm_year;
    month = 1+ltm->tm_mon;
    day = 0+ltm->tm_mday;
    hour = 0+ltm->tm_hour;

   //  cout << tmp->t.day; getch();

    if((year > tmp->t.year) || (month > tmp->t.month) || (day > tmp->t.day)){
        xy(45, height + 11);
        diff = difftime(now, temp_time) / (60*60*24);
        cout << "Terlambat : " << diff << " Hari" << endl;
        xy(45, height + 12);
        cout << "Anda terkena denda : Rp. " << diff * 5000;
        getch();
    }
}