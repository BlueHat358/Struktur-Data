//#include "function.h"
#include <string>

int zk = 1, zn;

void showSearch(int index){
    if(index == -1){
        cout << "Data not found" << endl;
    }
    else{
        if(zk%2 == 0) 
            fg = f1;
        else
            fg = f2;
        color(fg,bg);

        xy(4,zn + 3);
        cout << rental[index].num;
        xy(11,zn+ 3);
        cout << rental[index].name << endl;
        xy(54,zn + 3);
        cout << rental[index].type;
        xy(66,zn+ 3);
        cout << rental[index].date;
        xy(91,zn+3);
        cout << "Rp. " << rental[index].price;
    }
}

void search(char par[40]){
    zn = -1;
    char name[40], id[40];
    bool found = false;
    system("cls");
    Table();
    title();

    for(int i = 0; i < queue.end; i++){
        // name = rental[i].name;
        itoa(rental[i].num,id,40);
        
        if(strcmp(par, rental[i].name) == 0){
            found = true;
            zk++;
            zn++;
            showSearch(i);
        }
        else if(strcmp(par, id)==0){
            found = true;
            zk++;
            zn++;
            showSearch(i);
        }
    }

    if(!found){
        Table_Menu();
        color(ftex,bg);
        xy(5, height+4);
        cout << "Data not found\n";
    }
}

void search_linked(int c, string key){
    system("cls");
    Table2();
    Table_Menu2();
    temp = front;
    string b;
    int m = 0, z = 1;
    if (front == NULL) {
        xy(56, height2+up+11);
      cout<<"List is Empty"<<endl;
      return;
    }
    else {
        if(temp->next != NULL){
            for(int i = 0; i < c; i++){
                b = temp->name;
                if(key.compare(b)==0){
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
                    m++;
                    z++;
                }
                temp = temp->next;
            }
        }
    } 
}