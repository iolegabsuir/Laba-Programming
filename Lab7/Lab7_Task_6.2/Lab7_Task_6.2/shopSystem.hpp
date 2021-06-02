#ifndef shopSystem_hpp
#define shopSystem_hpp

#include <iostream>
#include <stdio.h>

using namespace  std;

struct ShopGoods
{
    string BarCode;
    long Price;
    string Name;
    int GoodBought;
    ShopGoods *Next, *Prev;
};

struct DiscountCard
{
    double Discount;
    string DiscountCardCode;
    DiscountCard *Next, *Prev;
};

struct DealDate
{
    short Year;
    short Month;
    short Day;
};

class GoodsList
{
    private:
        ShopGoods *head;
        ShopGoods *tail;
    public:
        GoodsList();
        void add(ShopGoods good);
        long getPrice(string bCode);
        int changeBought(string bCode, int amount);
        int search(string bCode);
        int searchB(string &bCode);
        void setGood(ShopGoods &good);
        int printBase() const;
        ShopGoods *getHead();
        int sortList();
        void swap(ShopGoods &a, ShopGoods &b);
        int fwrite(string prods);
};

struct Deal
{
    DealDate Date;
    int GoodsVariety;
    double Summ;
    bool IfUsedDiscount;
    DiscountCard UsedDiscountCard;
    bool IfUsedCreditCard;
    string CreditCardCode;
    GoodsList *ListOfBuyedGoods;
    string completeDate();
    Deal *Next, *Prev;
};

class DcardsList
{
    private:
        DiscountCard *head;
        DiscountCard *tail;
    public:
        DcardsList();
        void add(DiscountCard card);
        double getDiscount(int num);
        int search(int disc);
        void search(int &dcode, double &disc);
        int printBase() const;
        DiscountCard *getHead();
        int sortList();
        void swap(DiscountCard &a, DiscountCard &b);
        int fwrite(string cards);
};

class DealList
{
    private:
        Deal *head;
        Deal *tail;
    public:
        DealList();
        void add(Deal deal);
        void transaction(Deal &d, GoodsList base, DcardsList cardBase);
        int search(string date);
        int printBase() const;
        int sortList();
        void swap(Deal &a, Deal &b);
        int fwrite(string history);
};

#endif
