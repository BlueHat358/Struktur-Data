#include <iostream>
using namespace std;

#define MAX 5

struct Data_Rental{
    char name[40], type[9];
    string date, hours;
    int price, denda, num;
};

struct Data_Rental rental[MAX], tmpRental[MAX];

struct Queue{
    int end;
}queue;

typedef struct Fee{
    double transaction;
    int index;
    Fee *nextFee;
}fee;