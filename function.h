#include <ctime>
#include <string>
#include <locale>
#include <iostream>

#include "linkedlist.h"
#include "sort.h"
#include "table.h"
#include "search.h"

void showData();

bool end1 = false, end2 = false;

int state = 0;

bool isFull(){
    if(queue.end == MAX){ return true;}
    else{ return false;}
}

bool isEmpty(){
    if(queue.end == -1){ return true;}
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

int t, dex;
char buffer [25];

void Date(int num){
    time_t now;
    time(&now);
    now += num*60*60;
    tm *ltm = localtime(&now);

    rental[dex].year = 1900+ltm->tm_year;
    rental[dex].month = 1+ltm->tm_mon;
    rental[dex].day = 0+ltm->tm_mday;
    rental[dex].hour = 0+ltm->tm_hour;

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
        xy(0, height + 3);
        cout << i;
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
                s++;
                xy(66,queue.end + 3);
                cin >> num;
                Date(num);
                rental[i].date = buffer;
                rental[i].price = price(num, t);
            }
        }
        else{
            queue.end--;
            t = 0;
        }
        
        queue.end++;

        if(s > 20){
            s = 0;
        }
    }
    else
        cout << "Queue is Full";
}

void deQueue(){
    if(!isEmpty()){
        cout << "Name : " << rental[0].name << endl;
        swap();
        queue.end--;
        cout << endl << "The money was added to customer";
    }
    else{
        cout << "Queue is Empty";
    }
}

void Menu() {
	int pilihan;
    string val;
	xy(15, 26);
	cout << "MENU";
	xy(2, 27);
	cout << "1. INQEUE";
	xy(2, 28);
	cout << "2. DEQEUE";
	xy(2, 29);
	cout << "3. SEARCH";
	xy(2, 30);
	cout << "4. EXIT";
	xy(2, 33);
	cout << "Pilihan Menu: ";
	cin >> pilihan;

    switch(pilihan){
        case 1:
            inQueue();
        break;
        case 2:
            deQueue();
        break;
        case 3:
            cout << "search";
            cin >> val;
            search(val);
            system("pause");
        break;
        case 4:
            end1 = true;
        break;
    }
}

void Menu2() {
	int pilihan, pric, num, y = n, x = 36;
    char name[40], title[15];
    string date, val, name_, title_;

    title2();
    Display();

	xy(x+23, 26);
	cout << "MENU";
	xy(x, 27);
	cout << "1. INSERT";
	xy(x, 28);
	cout << "2. REMOVE";
	// xy(x, 29);
	// cout << "3. SEARCH";
	xy(x, 29);
	cout << "3. EXIT";
	xy(x, 33);
	cout << "Pilihan Menu: ";
	cin >> pilihan;

    switch(pilihan){
        case 1:
            // cin.ignore();
            xy(2, y+3);
            cin >> name_;
            xy(43, y+3);
            // cin.getline(title,15);
            cin >> title_;
            xy(70,y+3);
            cin >> num;
            Date(num);
            date = buffer;
            pric = price(num,1);
            Insert(name_, title_, date, pric);
        break;
        case 2:
            removeElement(1);
        break;
        // case 3:
        //     // cout << "search";
        //     // cin >> val;
        //     // search(val);
        //     // system("pause");
        //     Display();
        // break;
        case 3:
            end2 = true;
        break;
    }
}

void showData(){
    system("clear");
    Table();
    sortDefault();
    if(isEmpty()){
        cout << "Queue is Empty";
    }
    else{
        savedState(state);
        Table();
        title();
        for(pos = 0; pos < queue.end; pos++){
            xy(4,pos + 3);
            cout << rental[pos].num;
            xy(11,pos+ 3);
            cout << rental[pos].name;
            xy(54,pos + 3);
            cout << rental[pos].type;
            xy(66,pos+ 3);
            cout << rental[pos].date;
            xy(91,pos+3);
            cout << "Rp. " << rental[pos].price;
        }
        Table_Menu();
        Menu();
    }
}