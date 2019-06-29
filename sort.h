void sortStart(){
    for(int i = 0; i < queue.end; i++){
        tmpRental[i] = rental[i];
    }
}

void swap(Data_Rental *a, Data_Rental *b){
    Data_Rental tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void copy(){
    cout << "Bank [1]\n";
    for(int i = 0; i < queue.end; i++){
        cout << rental[i].name << endl;
    }
    cout << endl;

    cout << "Bank [2]\n";
    for(int i = 0; i < queue.end; i++){
        cout << tmpRental[i].name << endl;
    }
}

void sortQueue(){
    for(int i = 0; i < queue.end; i++){
        tmpRental[i] = rental[i];
    }
}

void sortName(){
    sortStart();
    for(int i = 0; i < queue.end-1; i++){
        for(int j = 0; j < queue.end - i-1; j++){
            if(tmpRental[j].name > tmpRental[j+1].name){
                swap(&tmpRental[j], &tmpRental[j+1]);
            }
        }
    }
}

void savedState(int saved){
    if(saved == 1){
        sortName();
    }
    else if(saved == 2){
        sortName();
    }
    else if(saved == 3){
        sortName();
    }
    else{
        sortQueue();
    }
}

// void sortFee(fee *head){
//     fee *i, *j;
//     int t;
//     for(i = head; i->nextFee != NULL; i = i->nextFee){
//         for(j=i->nextFee; j != NULL; j = j->nextFee){
//             if(i->transaction >)
//         }
//     }
// }