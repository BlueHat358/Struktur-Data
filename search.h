//#include "function.h"

void showSearch(int index){
    if(index == -1){
        cout << "Data not found" << endl;
    }
    else{
        xy(4,index + 3);
        cout << rental[index].num;
        xy(11,index+ 3);
        cout << rental[index].name << endl;
        xy(54,index + 3);
        cout << rental[index].type;
        xy(66,index+ 3);
        cout << rental[index].date;
        xy(91,index+3);
        cout << "Rp. " << rental[index].price;
    }
}

void search(string par){
    string name, id;
    bool found = false;
    system("cls");
    Table();
    title();

    for(int i = 0; i < queue.end; i++){
        name = rental[i].name;
        id = to_string(rental[i].num);
        
        if(par.compare(name)==0){
            found = true;
            showSearch(i);
        }
        else if(par.compare(id)==0){
            found = false;
            showSearch(i);
        }
    }

    if(!found){
        cout << "Data not found\n";
    }
    cout << found;
}