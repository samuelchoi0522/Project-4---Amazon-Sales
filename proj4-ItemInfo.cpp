#include "proj4-ItemInfo.hpp"


void ItemInfo::setItemId(const char *num){
    itemId = stuCstrToDbl(num);
}

void ItemInfo::setDescription(const char *cstr){
    int cnt = stuCstrLen(cstr);
    if(cnt <= 40){  
        for(int i = 0; i < cnt; i++){
            description[i] = cstr[i];
        }
    }
    else{
        for(int i = 0; i < 40; i++){
            description[i] = cstr[i];
        }
    }
}

void ItemInfo::setManCost(const char *num){
    manCost = stuCstrToDbl(num);
}

void ItemInfo::setSellPrice(const char *num){
    sellPrice = stuCstrToDbl(num);
}


int ItemInfo::getItemId(){
    return itemId;
}

const char *ItemInfo::getDescription(){
    return description;
}

double ItemInfo::getManCost(){
    return manCost;
}

double ItemInfo::getSellPrice(){
    return sellPrice;
}


void ItemInfo::toAmazonJSON(ostream &out){

    const char *ids = "\"itemId\": ";
    const char *descs = "\"description\": ";
    const char *prices = "\"manPrice\": ";
    const char *costs = "\"sellPrice\": ";
    char *idstring = new char[5];
    char *pricestring = new char[5];
    char *coststring = new char[5];


    

    //itemid
    out.put('\n');
    out.put('\t');
    out.put('\t');
    for(int i = 0; i < stuCstrLen(ids); i++){
        out.put(ids[i]);
    }
    stuDblToCstr(idstring, itemId);
    for(int i = 0 ; i < 5; i++){
        out.put(idstring[i]);
    }
    out.put(',');
    out.put('\n');

    //description
    out.put('\t');
    out.put('\t');
    for(int i = 0; i < stuCstrLen(descs); i++){
        out.put(descs[i]);
    }
    out.put('\"');
    for(int i = 0 ; i < stuCstrLen(description); i++){
        out.put(description[i]);
    }
    out.put('\"');
    out.put(',');
    out.put('\n');

    //manprice
    out.put('\t');
    out.put('\t');
    for(int i = 0 ; i < stuCstrLen(prices); i++){
        out.put(prices[i]);
    }
    stuDblToCstr(pricestring, manCost);
    for(int i = 0 ; i < 5; i++){
        out.put(pricestring[i]);
    }
    out.put(',');
    out.put('\n');

    //sellprice
    out.put('\t');
    out.put('\t');
    for(int i = 0 ; i < stuCstrLen(costs); i++){
        out.put(costs[i]);
    }
    stuDblToCstr(coststring, sellPrice);
    for(int i = 0 ; i < 5; i++){
        out.put(coststring[i]);
    }
    out.put('\n');
    out.put('\t');
    out.put('}');

}

void ItemInfo::displayItemInfo(ostream &out){
    const char *ids = "itemId: ";
    double idbl = itemId;
    char *pid = new char [5];
    const char *descs = "description: ";
    const char *costs = "manCost: ";
    char *pcost = new char[5];
    const char *sells = "sellPrice: ";
    char *pprice = new char[5];
    const char *calcs = "calculatedProfit: ";
    char *pprofit = new char[5];

    //id
    for(int i = 0 ; i < stuCstrLen(ids); i++){
        out.put(ids[i]);
    }
    stuDblToCstr(pid, idbl);
    for(int i = 0 ; i < 5; i++){
        out.put(pid[i]);
    }
    out.put('\n');

    //description
    for(int i = 0 ; i < stuCstrLen(descs); i++){
        out.put(descs[i]);
    }
    for(int i = 0; i < stuCstrLen(description); i++){
        out.put(description[i]);
    }
    out.put('\n');

    //man cost
    for(int i = 0; i < stuCstrLen(costs); i++){
        out.put(costs[i]);
    }
    stuDblToCstr(pcost, manCost);
    for(int i = 0; i < stuCstrLen(pcost); i++){
        out.put(pcost[i]);
    }
    out.put('\n');

    //sell price
    for(int i = 0; i < stuCstrLen(sells); i++){
        out.put(sells[i]);
    }
    stuDblToCstr(pprice, sellPrice);
    for(int i = 0; i < stuCstrLen(pprice); i++){
        out.put(pprice[i]);
    }
    out.put('\n');

    //calculated profit
    for(int i = 0; i < stuCstrLen(calcs); i++){
        out.put(calcs[i]);
    }
    stuDblToCstr(pprofit, calcProfit());
    for(int i = 0; i < stuCstrLen(pprofit); i++){
        out.put(pprofit[i]);
    }
    out.put('\n');
}

double ItemInfo::calcProfit(){
    return sellPrice - manCost;
}


double stuCstrToDbl(const char *num){
    double result = 0.0;
    double fraction = 0.1;

    while (*num >= '0' && *num <= '9') {
        result = result * 10 + (*num - '0');
        ++num;
    }

    if (*num == '.') {
        ++num;
        while (*num >= '0' && *num <= '9') {
            result += (*num - '0') * fraction;
            fraction /= 10;
            ++num;
        }
    }

    return result;
}

void stuDblToCstr(char *cstr, double num){
    string s = to_string(num);
    for(unsigned int i = 0; i < s.length() - 4; i++){
        cstr[i] = s.at(i);
    }
}

int stuCstrLen(const char *src){
    int cnt = 0;
    while(src[cnt]){
        cnt++;
    }
    return cnt;
}

ostream& printCString(ostream &out, const char *src){
    int len = stuCstrLen(src);

    for(int i = 0; i < len; i++){
        out.put(src[i]);
    }
    return out;
}
