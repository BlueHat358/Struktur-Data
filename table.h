

int height = 25, width = 105;
int pil_tmp;

void Table_Menu();
void Table_Menu2();

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
    xy(97,1);
        cout << "Price";
}

void Table_Menu() {
	for (int i = height; i < 35; i++) {
		xy(0, i);
		cout << char(179);
		xy(109, i);
		cout << char(179);
	}
	xy(0, 25);
	for (int i = 0; i < 109; i++) {
		if (i == 0) 
			cout << char(218);
		if (i == 108)
			cout << char(191);
		else
			cout << char(196);
	}
	xy(0, 35);
	for (int i = 0; i < 109; i++) {
		if (i == 0)
			cout << char(192);
		if (i == 108)
			cout << char(217);
		else
			cout << char(196);
	}
}

void main_menu(){
    int x = 25, y = 6;
    xy(x+15,y+2); cout << "Rental Kaset";
    xy(x+20,y+3); cout << "dan";
    xy(x+16,y+4); cout << "Rental PS4";

    xy(x+5,y+8); cout << "1. Rental PS4";
    xy(x+5,y+9); cout << "2. Rental Kaset";
    xy(x+5,y+10); cout << "3. Exit";
    xy(x+5,y+11); cout << "Pilihan : "; cin >> pil_tmp;
}

void table_main(){
    int x = 20, y = 5;
    system("cls");

    for(int i = 1; i < 15; i++){
        xy(x,i+y);
            cout << char(179);
        xy(x+50, i+y);
            cout << char(179);
    }

    xy(x,y);
    for(int i = 0; i < 50; i++){
        if(i == 0)
            cout << char(218);
        if(i == 49)
            cout << char(191);
        else
            cout << char(196);
        
    }

    xy(x,y+15);
    for(int i = 0; i < 50; i++){
        if(i == 0)
            cout << char(192);
        if(i == 49)
            cout << char(217);
        else
            cout << char(196);
        
    }

    main_menu();
}

void Table2(){
    system("cls");

    for(int i = 1; i < height-1; i++){
        xy(0,i);
            cout << char(179);
        xy(42,i);
            cout << char(179);
        xy(69,i);
            cout << char(179);
        xy(94,i);
            cout << char(179);
        xy(width+15, i);
            cout << char(179);
    }

    xy(0,0);
    for(int i = 0; i < width + 12; i++){
        if(i == 0)
            cout << char(218);
        if(i == 41 || i == 67 || i == 91)
            cout << char(194);
        if(i == width + 11)
            cout << char(191);
        else
            cout << char(196);
    }

    xy(0,2);
    for(int i = 0; i < width+12; i++){
        if(i == 0)
            cout << char(195);
        if(i == 41 || i == 67 || i == 91)
            cout << char(197);
        if(i == width + 11)
            cout << char(180);
        else
            cout << char(196);
    }

    xy(0,height-1);
    for(int i = 0; i < width+12; i++){
        if(i == 0)
            cout << char(192);
        if(i == 41 || i == 67 || i == 91)
            cout << char(193);
        if(i == width + 11)
            cout << char(217);
        else
            cout << char(196);
    }
    Table_Menu2();
}

void title2(){
    xy(19,1);
        cout << "Name";
    xy(54,1);
        cout << "Title";
    xy(80,1);
        cout << "Date";
    xy(105,1);
        cout << "Price";
}

void Table_Menu2() {
    int x = 33;
	for (int i = height; i < 35; i++) {
		xy(x, i);
		cout << char(179);
		xy(x+50, i);
		cout << char(179);
	}
	xy(x, 25);
	for (int i = 0; i < 50; i++) {
		if (i == 0) 
			cout << char(218);
		if (i == 49)
			cout << char(191);
		else
			cout << char(196);
	}
	xy(x, 35);
	for (int i = 0; i < 50; i++) {
		if (i == 0)
			cout << char(192);
		if (i == 49)
			cout << char(217);
		else
			cout << char(196);
	}
}