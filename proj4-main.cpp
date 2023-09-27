#include <iostream>
#include <fstream>
using namespace std;
#include "proj4-ItemInfo.hpp"


int main(){
    int capacity = 2;
    int cnt = 0;
    ifstream infile;
    infile.open("proj4-productServices.csv");
    ItemInfo *items = new ItemInfo[capacity];
    char *buffer = new char[500];
    char *id = new char[5];
    char *desc = new char[40];
    char *mcost = new char[5];
    char *sprice = new char[5];
    const char *fname = "\"firstItem\": {";
    const char *sname = "\"secondItem\": {";
    const char *tname = "\"thirdItem\": {";
    const char *foname = "\"fourthItem\": {";
    const char *finame = "\"fifthItem\": {";

    cout << "hello" << endl;
    cout << "Testing git: " << endl;
    while(!infile.eof()){

        int index = 0;
        char temp;
        int n = 0;

        if(cnt == capacity){
            capacity += 2;
            ItemInfo *itemstemp = new ItemInfo[capacity];
            for(int i = 0 ; i < capacity; i++){
                itemstemp[i] = items[i];
            }
            delete []items;
            items = new ItemInfo[capacity];

            for(int i = 0 ; i < capacity; i++){
                items[i] = itemstemp[i];
            }
        }
        
        while(infile.get(temp) && temp != '\n'){
            buffer[n] = temp;
            n++;
        }

        int blength = stuCstrLen(buffer);

        for(int i = 0 ; i < 5; i++){
            id[i] = buffer[i];
            index++;
        }
        items[cnt].setItemId(id);

        index++;

        int m = 0;
        while(buffer[index] != ','){
            desc[m] = buffer[index];
            m++;
            index++;
        }
        items[cnt].setDescription(desc);

        index++;

        int o = 0;
        while(buffer[index] != ','){
            mcost[o] = buffer[index];
            o++;
            index++;
        }
        items[cnt].setManCost(mcost);

        index++;

        int p = 0;
        while(index < blength){
            sprice[p] = buffer[index];
            p++;
            index++;
        }
        items[cnt].setSellPrice(sprice);


        


        delete []buffer;
        buffer = new char[500];
        delete []id;
        id = new char[5];
        delete []desc;
        desc = new char[40];
        delete []mcost;
        mcost = new char[5];
        delete []sprice;
        sprice = new char[5];



        
        cnt++;

    }

    //sort by profit
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < cnt - 1; j++){
            if(items[j].calcProfit() < items[j + 1].calcProfit()){
                ItemInfo temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    //printing in the amazon format
    //print storename
    const char *strname = "\"SamStore\": [";
    for(int i = 0; i < stuCstrLen(strname); i++){
        cout.put(strname[i]);
    }
    cout.put('\n');
    
    //first item
    cout.put('\t');
    for(int i = 0; i < stuCstrLen(fname); i++){
        cout.put(fname[i]);
    }
    items[0].toAmazonJSON(cout);
    cout.put(',');
    cout.put('\n');

    //second item
    cout.put('\t');
    for(int i = 0; i < stuCstrLen(sname); i++){
        cout.put(sname[i]);
    }
    items[1].toAmazonJSON(cout);
    cout.put(',');
    cout.put('\n');

    //third name
    cout.put('\t');
    for(int i = 0; i < stuCstrLen(tname); i++){
        cout.put(tname[i]);
    }
    items[2].toAmazonJSON(cout);
    cout.put(',');
    cout.put('\n');

    //fourth name
    cout.put('\t');
    for(int i = 0; i < stuCstrLen(foname); i++){
        cout.put(foname[i]);
    }
    items[3].toAmazonJSON(cout);
    cout.put(',');
    cout.put('\n');

    //fifth name
    cout.put('\t');
    for(int i = 0; i < stuCstrLen(finame); i++){
        cout.put(finame[i]);
    }
    items[4].toAmazonJSON(cout);
    cout.put('\n');
    cout.put('}');
    cout.put('\n');
    
    cout.put('\n');
    cout.put('\n');


    //printing in the format that prof aars wanted
    for(int i = 0 ; i < cnt; i++){
        items[i].displayItemInfo(cout);
        cout.put('\n');
    }

    


    delete []buffer;
    delete []id;
    delete []desc;
    delete []mcost;
    delete []sprice;

    infile.close();

    return 0;
}