#include "function.h"

void showSearch(int index){
    if(index == -1){
        cout << "Data not found" << endl;
    }
    else{
        cout << "Customer [" << index+1 << "]" << endl;
        cout << "===============================" << endl;
        cout << "Name : " << rental[index].name << endl;
        cout << "===============================" << endl << endl;
    }
}

void search(string par){
    string name;
    string id, money;
    bool found = false;

    for(int i = 0; i < queue.end; i++){
        name = rental[i].name;
        
        if(par.compare(name)==0){
            found = false;
            showSearch(i);
        }
        else if(id == par){
            found = false;
            showSearch(i);
        }
        else if(money == par){
            found = false;
            showSearch(i);
        }
    }

    if(!found){
        cout << "Data not found\n";
    }
    cout << found;
}