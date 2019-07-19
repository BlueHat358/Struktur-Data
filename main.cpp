//  #include "search.h"
 #include "function.h"

int main(){

    while(pil_tmp != 3){
        table_main();
        if(pil_tmp == 1){
            while(true){
                showData();
                if(end1){
                    break;
                }
            }
        }
        if(pil_tmp == 2){
            while(true){
                Table2();
                Table_Menu2();
                Menu2();
                if(end2){
                    break;
                }
            }
        }
    }

    xy(0, height + 15);
    
    // denda();
}