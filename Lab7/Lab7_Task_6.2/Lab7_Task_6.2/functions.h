#ifndef functions_h
#define functions_h

#include "shopSystem.hpp"
#include <alloca.h>
#include <iostream>
#include <fstream>

using namespace std;

void check(int *a, int min, int max);
int printMenu(int num);
void bcodeCheck(string &bcode);
void dateMark(DealDate &date);
int baseCheck(GoodsList base, DcardsList cardBase);
int fileRead(GoodsList &GoodsBase, DcardsList &DCardsBase, DealList &DealBase,
             string hist, string cards, string prods);

#endif
