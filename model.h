#include <iostream>
#include <conio.h>
#include "xcurse.h"
using namespace std;

#define MAX 10
int pos, fg = 2, bg = 0, f1 = 2, f2 = 3, ftit = 2, ftab = 2, ftex = 2, up = 0, n_temp;

struct Data_Rental{
    char name[40], type[9];
    string date;
    int num, hour, day, month, year, price;
};

struct Data_Rental rental[MAX], tmpRental[MAX];

struct Queue{
    int end;
}queue;
