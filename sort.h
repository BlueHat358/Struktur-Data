// void sortStart(){
//     for(int i = 0; i < queue.end; i++){
//         tmpRental[i] = rental[i];
//     }
// }

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

void sortDefault(){
    string hour, date, month, year, hour1, date1, month1, year1;
    for(int i = 0; i < queue.end-1; i++){
        for(int j = 0; j < queue.end - i-1; j++){
            hour = rental[j].hour;
            date = rental[j].day;
            month = rental[j].month;
            year = rental[j].year;
            hour1 = rental[j+1].hour;
            date1 = rental[j+1].day;
            month1 = rental[j+1].month;
            year1 = rental[j+1].year;
            if(rental[j].hour > rental[j+1].hour){
                swap(&rental[j], &rental[j+1]);
            }
        }
    }
}

// hour > hour1 || date > date1 || month > month1

void savedState(int saved){
    if(saved == 1){
        sortDefault();
    }
    else if(saved == 2){
        sortDefault();
    }
    else if(saved == 3){
        sortDefault();
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