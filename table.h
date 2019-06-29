#include "xcurse.h"

int height = 25, width = 105;

void Table(){
    system("cls");

    for(int i = 1; i < height-1; i++){
        xy(0,i);
            cout << char(179);
        xy(9,i);
            cout << char(179);
        xy(52,i);
            cout << char(179);
        xy(64,i);
            cout << char(179);
        xy(89,i);
            cout << char(179);
        xy(width+4, i);
            cout << char(179);
    }

    xy(0,0);
    for(int i = 0; i < width; i++){
        if(i == 0)
            cout << char(218);
        if(i == 8 || i == 50 || i == 61 || i == 85)
            cout << char(194);
        if(i == width -1)
            cout << char(191);
        else
            cout << char(196);
    }

    xy(0,2);
    for(int i = 0; i < width; i++){
        if(i == 0)
            cout << char(195);
        if(i == 8 || i == 50 || i == 61 || i == 85)
            cout << char(197);
        if(i == width -1)
            cout << char(180);
        else
            cout << char(196);
    }

    xy(0,height-1);
    for(int i = 0; i < width; i++){
        if(i == 0)
            cout << char(192);
        if(i == 8 || i == 50 || i == 61 || i == 85)
            cout << char(193);
        if(i == width -1)
            cout << char(217);
        else
            cout << char(196);
    }
}

void title(){
    xy(2,1);
        cout << "Number";
    xy(30,1);
        cout << "Name";
    xy(56,1);
        cout << "Type";
    xy(73,1);
        cout << "Date";
    xy(95,1);
        cout << "Price";
}