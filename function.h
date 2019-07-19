#include <ctime>
#include <string>
#include <locale>
#include <iostream>

#include "linkedlist.h"
#include "sort.h"
#include "table.h"
#include "search.h"

void showData();
void show();
void denda();
string spliter(int number);

bool end1 = false, end2 = false;

bool isFull(){
    if(queue.end >= MAX){ return true;}
    else{ return false;}
}

bool isEmpty(){
    if(queue.end <= -1){ return true;}
    else {return false;}
}

void swap(){
    for(int i = 0; i < queue.end; i++){
        rental[i] = rental[i+1];
    }

}

void clear(){
    queue.end = -1;
}

int t, dex, arr[3];
char buffer [25];

void Date(int num, int choose){
    time_t now;
    time(&now);
    now += num*60*60;
    tm *ltm = localtime(&now);

    if(choose == 1){
        rental[dex].year = 1900+ltm->tm_year;
        rental[dex].month = 1+ltm->tm_mon;
        rental[dex].day = 0+ltm->tm_mday;
        rental[dex].hour = 0+ltm->tm_hour;
    }else{
        arr[0] = 1900+ltm->tm_year;
        arr[1] = 1+ltm->tm_mon;
        arr[2] = ltm->tm_mday;
    }

    strftime(buffer, 25,"%d/%m/%Y || %H:%M:%S", ltm);
}

int price(int num, int type){
    int price;
    switch (type)
    {
        case 1:
            price = num * 5000;
            break;
    
        case 2:
            price = num * 10000;
            break;
    }
    return price;
}

void inQueue(){
    int number, error = 0;
    char name[40], type[9];
    string date;

    if(isEmpty()){
        queue.end++;
    }

    int i = queue.end;
    dex = i;

    if(!isFull()){
        int num, number;
        xy(4,queue.end + 3);
        cin >> num;
        for(int a = 0; a < queue.end; a++){
            if(num == rental[a].num){
                t = -1;
            }
        }
        if(t != -1){
            rental[i].num = num;
            cin.ignore();
            xy(11,queue.end + 3);
            cin.getline(rental[i].name,40);
            xy(54,queue.end + 3);
            cin.getline(rental[i].type,9);
            if(strcmp(rental[i].type, "PS")==0 || strcmp(rental[i].type, "ps")==0)
                t = 1;
            else if(strcmp(rental[i].type, "FULL SET")==0 || strcmp(rental[i].type, "full set")==0)
                t = 2;
            else{
                t = 0;
                queue.end--;
            }
            
            if(t != 0){
                xy(66,queue.end + 3);
                cin >> num;
                Date(num,1);
                rental[i].date = buffer;
                rental[i].price = price(num, t);
            }
        }
        else{
            queue.end--;
            t = 0;
        }
        
        queue.end++;
    }
    else
        cout << "Queue is Full";
}

void deQueue(){
    if(!isEmpty()){
        denda();
        swap();
        queue.end--;
    }
}

void Menu() {
	int pilihan;
    char val[40];
    color(ftex, bg);
	xy(15, height+2);
	cout << "MENU";
	xy(2, height+4);
	cout << "1. Insert";
	xy(2, height+5);
	cout << "2. Remove";
	xy(2, height+6);
	cout << "3. Search";
	xy(2, height+7);
	cout << "4. Exit";
	xy(2, height+9);
	cout << "Pilihan Menu: ";
	cin >> pilihan;

    switch(pilihan){
        case 1:
            system("cls");
            Table();
            title();
            show();
            inQueue();
        break;
        case 2:
            deQueue();
        break;
        case 3:
            cin.ignore();
            xy(5, height+10);
            cout << "Search : ";
            cin.getline(val, 40);
            search(val);
            getch();
        break;
        case 4:
            end1 = true;
        break;
    }
}

void Menu2() {
	int pilihan, pric, num, y = n, x = 36;
    char name[40], title[15];
    string date, val;
    end2 = false;

    title2();
    Display();

    color(ftex,bg);
	xy(x+23, height2+up+2);
	cout << "MENU";
	xy(x, height2+up+4);
	cout << "1. Insert";
	xy(x, height2+up+5);
	cout << "2. Remove";
	xy(x, height2+up+6);
	cout << "3. Remove At";
    xy(x, height2+up+7);
	cout << "4. Search";
	xy(x, height2+up+8);
	cout << "5. Exit";
	xy(x, height2+up+10);
	cout << "Pilihan Menu: ";
	cin >> pilihan;

    switch(pilihan){
        case 1:
            cin.ignore();
            xy(1, y+3);
            cin.getline(name, 40);
            xy(43, y+3);
            cin.getline(title,15);
            xy(70,y+3);
            cin >> num;
            Date(num,2);
            date = buffer;
            pric = price(num,1);
            Insert(name, title, date, pric, arr);
        break;
        case 2:
            removeElement(1);
        break;
        case 3:
            cin.ignore();
            cout << "Search : ";
            getline(cin, val);
            findIndex(val);
        break;
        case 4:
            cin.ignore();
            cout << "Search : ";
            getline(cin, val);
            search_linked(n, val);
            getch();
        break;
        case 5:
            end2 = true;
        break;
    }
}

void show(){
    int z = 1;
    for(pos = 0; pos < queue.end; pos++){
        if(z%2 == 0)
            fg = f1;
        else
            fg = f2;
        color(fg,bg);
        xy(4,pos + 3);
        cout << rental[pos].num;
        xy(11,pos+ 3);
        cout << rental[pos].name;
        xy(54,pos + 3);
        cout << rental[pos].type;
        xy(66,pos+ 3);
        cout << rental[pos].date;
        xy(91,pos+3);
        cout << "Rp. " << spliter(rental[pos].price);
        z++;
    }
}

void showData(){
    system("clear");
    if(isEmpty()){
        Table();
        title();
        Table_Menu();
        xy(10, height+12);
        cout << "Queue is Empty";
        Menu();
    }
    else{
        Table();
        sortDefault();
        title();
        show();
        Table_Menu();
        Menu();
    }
}

void denda(){
    int year, month, day, hour;
    time_t now;
    time(&now);
    tm *ltm = localtime(&now);

    struct tm temp = {0,0,0,rental[0].day, rental[0].month-1, rental[0].year-1900};
    time_t temp_time = mktime(&temp);
    int diff;

    year = 1900+ltm->tm_year;
    month = 1+ltm->tm_mon;
    day = 0+ltm->tm_mday;
    hour = 0+ltm->tm_hour;

    if((year > rental[0].year) || (month > rental[0].month) || (day > rental[0].day)){
        xy(10, height + 11);
        diff = difftime(now, temp_time) / (60*60*24);
        cout << "Terlambat : " << diff << " Hari" << endl;
        xy(10, height + 12);
        cout << "Anda terkena denda : Rp. " << spliter(diff * 15000);
        getch();
    }
}

string spliter(int number){
    string hasil = to_string(number);
        int split = hasil.length() - 3;
        while(split > 0){
            hasil.insert(split, ",");
            split -= 3;
        }
        return (hasil);
}