#ifdef TEST
#include "functions.h"
#include <assert.h>

int main()
{
    GoodsList gBase;
    DcardsList dcBase;
    DealList dBase;
    
    assert(baseCheck(gBase, dcBase) == 1);
    assert(gBase.getHead() == NULL);
    

    
    DiscountCard tempc;
    dcBase.add(tempc);
     
    assert(fileRead(gBase, dcBase, dBase, "shopHistory.txt", "", "") == 1);
    assert(fileRead(gBase, dcBase, dBase, "shopHistory.txt", "cardBase.txt", "") == 1);
    assert(fileRead(gBase, dcBase, dBase, "shopHistory.txt", "", "productBase.txt") == 1);
    assert(fileRead(gBase, dcBase, dBase, "shopHistory.txt", "cardBase.txt", "productBase.txt") == 0);
    assert(fileRead(gBase, dcBase, dBase, "", "", "") == 1);
    
   
    assert(dBase.search("123") == 1);
    
    assert(dBase.sortList() == 0);
    
    assert(dBase.printBase() == 0);
    assert(dcBase.printBase() == 0);
    
    for (int i = 0; i < 5; i++)
        assert(printMenu(i) == 0);
    assert(printMenu(5) == 1);
    assert(printMenu(-1) == 1);
    
    assert(gBase.fwrite("") == 1);
    assert(dBase.fwrite("") == 1);
    assert(dcBase.fwrite("") == 1);
    assert(gBase.fwrite("testfile1.txt") == 0);
    assert(dBase.fwrite("testfile2.txt") == 0);
    assert(dcBase.fwrite("testfile3.txt") == 0);
    
    GoodsList gBase2;
    DealList dBase2;
    DcardsList dcBase2;
    
    assert(gBase2.fwrite("testfile1.txt") == 1);
    assert(dBase2.fwrite("testfile2.txt") == 1);
    assert(dcBase2.fwrite("testfile3.txt") == 1);
    
    assert(gBase2.getPrice("BCODE") == -1);
    assert(gBase2.printBase() == 1);
    assert(gBase2.sortList() == 1);
    assert(gBase2.search("123") == 1);
    
    
    assert(dBase2.search("123") == 1);
    assert(dBase2.printBase() == 1);
    assert(dBase2.sortList() == 1);
    
    assert(dcBase2.printBase() == 1);
    assert(dcBase2.getDiscount(01) == 1);
    assert(dcBase2.sortList() == 1);
    assert(dcBase2.search(1000) == 1);
    
    DealDate dd;
    dateMark(dd);
    assert(dd.Day = 5);
    assert(dd.Day = 5);
    assert(dd.Day = 1991);
    
    
    return 0;
}
#endif
