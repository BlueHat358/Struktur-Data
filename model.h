#include <iostream>
#include "xcurse.h"
using namespace std;

#define MAX 5
int pos, s = 0;

struct Data_Rental{
    char name[40], type[9];
    string date;
    int num, hour, day, month, year, price;
};

struct Data_Rental rental[MAX], tmpRental[MAX];

struct Queue{
    int end;
}queue;
