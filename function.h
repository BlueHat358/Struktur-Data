#include <ctime>
#include <string>
#include <locale>

#include "model.h"
#include "sort.h"
#include "table.h"

void showData();

bool end1 = false;

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
        if(num == 99)
            end1 = true;
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
                Date(num);
                rental[i].date = buffer;
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
        cout << "Name : " << rental[0].name << endl;
        swap();
        queue.end--;
        cout << endl << "The money was added to customer";
    }
    else{
        cout << "Queue is Empty";
    }
}

void showData(){
    Table();
    sortDefault();
    if(isEmpty()){
        cout << "Queue is Empty";
    }
    else{
        savedState(state);
        Table();
        for(int i = 0; i < queue.end; i++){
            xy(4,i + 3);
            cout << rental[i].num;
            xy(11,i+ 3);
            cout << rental[i].name;
            xy(54,i + 3);
            cout << rental[i].type;
            xy(66,i+ 3);
            cout << rental[i].date;
            xy(91,i + 3);
            cout << "Rp. " << rental[i].price;
        }
    }
    title();
}