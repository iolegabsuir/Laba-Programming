#include "shopSystem.hpp"
#include "functions.h"

string Deal::completeDate()
{
    if (Date.Day && Date.Month && Date.Year)
        return to_string(Date.Day) + '.' + to_string(Date.Month) + '.' + to_string(Date.Year);
    else
        return "ERROR";
}

GoodsList::GoodsList()
{
   head = tail = NULL;
}

int GoodsList::fwrite(string prods)
{
    if (head)
    {
        ofstream productsin(prods, ios_base::out);
        
        if (!productsin.is_open())
            return 1;
        
        ShopGoods *buf = head;
        while (buf)
        {
            productsin << buf->Name
            << " " << buf->Price
            << " " << buf->GoodBought
            << " " << buf->BarCode;
            
            if (buf->Next)
                productsin << " .\n";
            buf = buf->Next;
        }
        productsin.close();
    }
    else
        return 1;
    return 0;
}

void GoodsList::add(ShopGoods good)
{
    ShopGoods *buf  = new ShopGoods;
    
    buf->BarCode = good.BarCode;
    buf->GoodBought = good.GoodBought;
    buf->Name = good.Name;
    buf->Price = good.Price;
    
    if (!head)
    {
        buf->Next = tail;
        head = buf;
        buf->Prev = NULL;
    }
    else
    {
        buf->Next = tail->Next;
        buf->Prev = tail;
        tail->Next = buf;
    }
    tail = buf;
}

long GoodsList::getPrice(string bCode)
{
    if (head)
    {
        ShopGoods *buf = head;
        while (buf)
        {
            if (buf->BarCode == bCode)
                return buf->Price;
            
            buf = buf->Next;
        }
        return -1;
    }
    else
        cout << "Ошибка. База пуста.\n";
    return -1;
}

void GoodsList::setGood(ShopGoods &good)
{
    ShopGoods *seargood = head;
    while (seargood)
    {
        if (seargood->BarCode == good.BarCode)
        {
            good.Name = seargood->Name;
            good.Price = seargood->Price;
            return;
        }
        seargood = seargood->Next;
    }
}

int GoodsList::changeBought(string bCode, int amount)
{
    ShopGoods *temp = head;
    while (temp)
    {
        if (temp->BarCode == bCode)
        {
            temp->GoodBought += amount;
            return 0;
        }
        temp = temp->Next;
    }
    return 1;
}

int GoodsList::printBase() const
{
    if (head)
    {
        ShopGoods *buf = head;
        while (buf)
        {
            cout << "\nШтрихкод: " << buf->BarCode
            << "  Название: " << buf->Name
            << "  Цена: " << buf->Price
            << "  Продано: " << buf->GoodBought;
            
            buf = buf->Next;
        }
        cout << endl;
        return 0;
    }
    else
        cout << "Ошибка. База пуста.\n";
    return 1;
}

void GoodsList::swap(ShopGoods &a, ShopGoods &b)
{
    ShopGoods temp;
    temp.Name = a.Name;
    temp.BarCode = a.BarCode;
    temp.GoodBought = a.GoodBought;
    temp.Price = a.Price;
    
    a.Name = b.Name;
    a.Price = b.Price;
    a.BarCode = b.BarCode;
    a.GoodBought = b.GoodBought;
    
    b.Name = temp.Name;
    b.Price = temp.Price;
    b.BarCode = temp.BarCode;
    b.GoodBought = temp.GoodBought;
}
 
int GoodsList::sortList()
{
    if (!head)
        return 1;
    ShopGoods *buf = head;
    for (ShopGoods *i = buf; i; i = i->Next)
        for (ShopGoods *j = i->Next; j; j = j->Next)
            if (i->Price < j->Price)
                swap(*i, *j);
    return 0;
}

ShopGoods *GoodsList::getHead()
{
    return head;
}

int GoodsList::search(string bCode)
{
    if (head)
    {
        ShopGoods *buf = head;
        int amount = 0;
        cout << "\t\tРезультат поиска:\n";
        
        while (buf)
        {
            if (buf->BarCode == bCode)
            {
                amount++;
                cout << amount << ")  Название: " << buf->Name
                     << "  Цена: " << buf->Price
                     << "  Продано: " << buf->GoodBought << endl;
            }
            
            buf = buf->Next;
        }
        if (amount)
            return 0;
        else
            cout << "Ошибка. Товар не найден.";
        return 1;
    }
    else
        cout << "Ошибка. База пуста.\n";
    return 1;
}

int GoodsList::searchB(string &bCode)
{
    if (!head)
        return 1;
    ShopGoods *buf = head;
    
    while (buf)
    {
        if (buf->BarCode == bCode)
            return 0;
        buf = buf->Next;
    }
    
    cout << "Штрихкод неверен!\n";
    bcodeCheck(bCode);
    searchB(bCode);
    return  0;
}

DcardsList::DcardsList()
{
   head = tail = NULL;
}

void DcardsList::add(DiscountCard good)
{
    DiscountCard *buf  = new DiscountCard;
    
    buf->Discount = good.Discount;
    buf->DiscountCardCode = good.DiscountCardCode;
    
    if (!head)
    {
        buf->Next = tail;
        head = buf;
        buf->Prev = NULL;
    }
    else
    {
        buf->Next = tail->Next;
        buf->Prev = tail;
        tail->Next = buf;
    }
    tail = buf;
}

double DcardsList::getDiscount(int num)
{
    if (head)
    {
        DiscountCard *buf = head;
        while (buf)
        {
            if (buf->DiscountCardCode == to_string(num))
                return buf->Discount;
            buf = buf->Next;
        }
        cout << "Ошибка. Неверный код карты.";
        return 1;
    }
    else
        cout << "Ошибка. База пуста.\n";
    return 1;
}

int DcardsList::printBase() const
{
    if (head)
    {
        DiscountCard *buf = head;
        cout << "\t\tБаза Cкидочных Карт:";
        while (buf)
        {
            cout << "\nНомер Карты: " << buf->DiscountCardCode
            << "  Объем скидки: " << buf->Discount << "%";
            
            buf = buf->Next;
        }
        cout << endl;
        return 0;
    }
    else
        cout << "Ошибка. База пуста.\n";
    return 1;
}

int DcardsList::fwrite(string cards)
{
    if (head)
    {
        ofstream cardsin(cards, ios_base::out);
        
        if (!cardsin.is_open())
            return 1;
        
        DiscountCard *buf = head;
        while (buf)
        {
            cardsin << buf->DiscountCardCode
            << " " << buf->Discount;
            
            if (buf->Next)
                cardsin << " .\n";
            buf = buf->Next;
        }
        cardsin.close();
    }
    else
        return 1;
    return 0;
}

void DcardsList::swap(DiscountCard &a, DiscountCard &b)
{
    DiscountCard temp;
    temp.Discount = a.Discount;
    temp.DiscountCardCode = a.DiscountCardCode;
    
    a.Discount = b.Discount;
    a.DiscountCardCode = b.DiscountCardCode;
    
    b.Discount = temp.Discount;
    b.DiscountCardCode = temp.DiscountCardCode;
}
 
int DcardsList::sortList()
{
    if (!head)
        return 1;
    DiscountCard *buf = head;
    for (DiscountCard *i = buf; i; i = i->Next)
        for (DiscountCard *j = i->Next; j; j = j->Next)
            if (i->Discount < j->Discount)
                swap(*i, *j);
    return 0;
}

int DcardsList::search(int disc)
{
    if (head)
    {
        DiscountCard *buf = head;
        int amount = 0;
        cout << "\t\tРезультат поиска:\n";
        while (buf)
        {
            if (buf->Discount < disc + 1 && buf->Discount > disc - 1)
            {
                amount++;
                cout << amount << ") Номер Карты: " << buf->DiscountCardCode
                     << "  Объем скидки: " << buf->Discount << "%" << endl;
            }
            
            buf = buf->Next;
        }
        if (amount)
            return 0;
        else
            cout << "Ошибка. Карты не найдены.";
        return 1;
    }
    else
        cout << "Ошибка. База пуста.\n";
    return 1;
}

void DcardsList::search(int &dcode, double &disc)
{
    DiscountCard *searcard = head;
    while (searcard)
    {
        if (searcard->DiscountCardCode == to_string(dcode))
        {
            disc = searcard->Discount;
            return;;
        }
        searcard = searcard->Next;
    }
    
    cout << "Введенный код карты отсуствует в базе. Повторите ввод: ";
    check(&dcode, 10000000, 99999999);
    search(dcode, disc);
}

DiscountCard *DcardsList::getHead()
{
    return head;
}

DealList::DealList()
{
   head = tail = NULL;
}

void DealList::add(Deal deal)
{
    Deal *buf  = new Deal;
    
    buf->Date = deal.Date;
    buf->GoodsVariety = deal.GoodsVariety;
    buf->Summ = deal.Summ;
    buf->IfUsedDiscount = deal.IfUsedDiscount;
    buf->UsedDiscountCard = deal.UsedDiscountCard;
    buf->IfUsedCreditCard = deal.IfUsedCreditCard;
    buf->CreditCardCode = deal.CreditCardCode;
    buf->ListOfBuyedGoods = deal.ListOfBuyedGoods;
    
    if (!head)
    {
        buf->Next = tail;
        head = buf;
        buf->Prev = NULL;
    }
    else
    {
        buf->Next = tail->Next;
        buf->Prev = tail;
        tail->Next = buf;
    }
    tail = buf;
}

int DealList::printBase() const
{
    if (head)
    {
        int i = 0;
        Deal *buf = head;
        cout << "\t\tИстория покупок:";
        while (buf)
        {
            i++;
            cout << "\n" << i << ") Дата покупки: " << buf->completeDate()
                 << "\nКол-во товаров: " << buf->GoodsVariety
                 << "\nСумма чека: " << buf->Summ
                 << "\n\tСписок покупок: ";
            buf->ListOfBuyedGoods->printBase();
            
            if (buf->IfUsedDiscount)
                cout << "Номер скидочной карты: " << buf->UsedDiscountCard.DiscountCardCode
                     << "\tОбъем скидки: " << buf->UsedDiscountCard.Discount << "%" << endl;
            else
                cout << "Скидочная карта не использовалась.\n";
            
            if (buf->IfUsedCreditCard)
                cout << "Номер кредитной карты: " << buf->CreditCardCode;
            else
                cout << "Кредитная карта не использовалась.";
            
            buf = buf->Next;
            if (buf)
                cout << endl;
        }
        cout << endl;
        return 0;
    }
    else
        cout << "Ошибка. База пуста.\n";
    return 1;
}

void DealList::swap(Deal &a, Deal &b)
{
    Deal temp;
    
    temp.Date = a.Date;
    temp.GoodsVariety = a.GoodsVariety;
    temp.Summ = a.Summ;
    temp.IfUsedDiscount = a.IfUsedDiscount;
    temp.UsedDiscountCard = a.UsedDiscountCard;
    temp.IfUsedCreditCard = a.IfUsedCreditCard;
    temp.CreditCardCode = a.CreditCardCode;
    temp.ListOfBuyedGoods = a.ListOfBuyedGoods;
    
    a.Date = b.Date;
    a.GoodsVariety = b.GoodsVariety;
    a.Summ = b.Summ;
    a.IfUsedDiscount = b.IfUsedDiscount;
    a.UsedDiscountCard = b.UsedDiscountCard;
    a.IfUsedCreditCard = b.IfUsedCreditCard;
    a.CreditCardCode = b.CreditCardCode;
    a.ListOfBuyedGoods = b.ListOfBuyedGoods;
    
    b.Date = temp.Date;
    b.GoodsVariety = temp.GoodsVariety;
    b.Summ = temp.Summ;
    b.IfUsedDiscount = temp.IfUsedDiscount;
    b.UsedDiscountCard = temp.UsedDiscountCard;
    b.IfUsedCreditCard = temp.IfUsedCreditCard;
    b.CreditCardCode = temp.CreditCardCode;
    b.ListOfBuyedGoods = temp.ListOfBuyedGoods;
}
 
int DealList::sortList()
{
    if (!head)
        return 1;
    Deal *buf = head;
    for (Deal *i = buf; i; i = i->Next)
        for (Deal *j = i->Next; j; j = j->Next)
            if (i->Summ < j->Summ)
                swap(*i, *j);
    return 0;
}

int DealList::search(string date)
{
    if (head)
    {
        Deal *buf = head;
        int amount = 0;
        cout << "\t\tРезультат поиска:";
        while (buf)
        {
            if (buf->completeDate() == date)
            {
                amount++;
                cout << "\n" << amount << ") Дата покупки: " << buf->completeDate()
                     << "\nКол-во товаров: " << buf->GoodsVariety
                     << "\nСумма чека: " << buf->Summ
                     << "\n\tСписок покупок: ";
                buf->ListOfBuyedGoods->printBase();
                
                if (buf->IfUsedDiscount)
                    cout << "Номер скидочной карты: " << buf->UsedDiscountCard.DiscountCardCode
                         << "\tОбъем скидки: " << buf->UsedDiscountCard.Discount << "%" << endl;
                else
                    cout << "Скидочная карта не использовалась.\n";
                
                if (buf->IfUsedCreditCard)
                    cout << "Номер кредитной карты: " << buf->CreditCardCode;
                else
                    cout << "Кредитная карта не использовалась.";
                    cout << endl;
            }
            
            buf = buf->Next;
        }
        if (amount)
            return 0;
        else
            cout << "Ошибка. Товары не найден.";
        return 1;
    }
    else
        cout << "Ошибка. База пуста.\n";
    return 1;
}

int DealList::fwrite(string history)
{
    if (head)
    {
        ofstream historyin(history, ios_base::out);
        
        if (!historyin.is_open())
            return 1;
        
        Deal *buf = head;
        while (buf)
        {
            historyin << buf->Date.Day
                      << " " << buf->Date.Month
                      << " " << buf->Date.Year << " ";
            
            ShopGoods *buf2 = buf->ListOfBuyedGoods->getHead();
            while (buf2)
            {
                historyin << buf2->BarCode
                << " " << buf2->GoodBought;
                
                if (!buf2->Next)
                    historyin << " # ";
                else
                    historyin << " . ";
                buf2 = buf2->Next;
            }
            
            historyin << buf->IfUsedDiscount << " ";
            
            if (buf->IfUsedDiscount)
                historyin << buf->UsedDiscountCard.DiscountCardCode << " ";
            historyin << buf->IfUsedCreditCard << " ";
            
            if (buf->IfUsedCreditCard)
                historyin << buf->CreditCardCode;
            
            if (buf->Next)
                historyin << " .\n";
            
            buf = buf->Next;
        }
        historyin.close();
    }
    else
        return 1;
    return 0;
}


void DealList::transaction(Deal &d, GoodsList base, DcardsList cardBase)
{
    dateMark(d.Date);
    GoodsList *goods = new GoodsList;
    double rawSumm = 0;
    d.GoodsVariety = 0;
    
    cout << "\t\tВвод продуктов:\n";
    while(true)
    {
        ShopGoods temp;
        string barcode;
        int checked, amount;
        
        bcodeCheck(barcode);
        base.searchB(barcode);
        temp.BarCode = barcode;
        base.setGood(temp);
        
        cout << "Введите кол-во продукта: ";
        check(&amount, 1, 100);
        base.changeBought(barcode, amount);
        temp.GoodBought = amount;
        d.GoodsVariety++;
        
        rawSumm += base.getPrice(barcode) * amount;
        goods->add(temp);

        cout << "Чтобы завершить ввод продуктов введите 0, чтобы продолжить - 1: ";
        check(&checked, 0, 1);
        
        if (checked == 0)
            break;
        else
            checked = -1;
    }
    
    d.ListOfBuyedGoods = goods;
    
    int code;
    double disc;
    cout << "Если Вы используете скидочную карту, введите ее номер(если нет введите 0):\n";
    check(&code, 0, 99999999);
    
    if ((code && code < 10000000) || code < 0)
    {
        cout << "Ввод не верен! Повторите ввод: ";
        check(&code, 10000000, 99999999);
    }
    else
        d.IfUsedDiscount = false;
    
    if (code)
    {
        d.IfUsedDiscount = true;
        cardBase.search(code, disc);
        d.UsedDiscountCard.DiscountCardCode = to_string(code);
        d.UsedDiscountCard.Discount = disc;
        rawSumm = rawSumm * (100 - disc) / 100;
    }
    
    d.Summ = rawSumm;
    
    cout << "Если Вы используете кредитную карту, введите ее номер(если нет введите 0):\n";
    check(&code, 0, 99999999);
    if ((code && code < 10000000) || code < 0)
    {
        cout << "Ввод не верен! Повторите ввод: ";
        check(&code, 10000000, 99999999);
    }
    else
        d.IfUsedCreditCard = false;
    
    if (code)
    {
        d.CreditCardCode = to_string(code);
        d.IfUsedCreditCard = true;
    }
}
