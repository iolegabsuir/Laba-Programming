#include "functions.h"

#ifndef TEST
int main()
{
    GoodsList GoodsBase;
    DcardsList DCardsBase;
    DealList DealBase;
    
    if (fileRead(GoodsBase,DCardsBase, DealBase, "shopHistory.txt", "cardBase.txt", "productBase.txt"))
        exit(1);
    
    int choice = -1;
    printMenu(0);
    check(&choice, 0, 5);
    while (choice)
    {
        switch (choice)
        {
            case 1:
            {
                int choice_1;
                printMenu(1);
                while (true)
                {
                    if (baseCheck(GoodsBase, DCardsBase))
                    {
                        cout << "Ошибка! База товаров или база карт скидок пуста!\n";
                        cout << "0 -> Вернуться в главное меню.\n";
                        check(&choice_1, 0, 0);
                        if (!choice_1)
                            printMenu(0);
                        break;
                    }
                    Deal deal;
                    DealBase.transaction(deal, GoodsBase, DCardsBase);
                    DealBase.add(deal);
                    
                    cout << "Чтобы выйти из режимы обслуживания введите 0, чтобы продолжить - 1: ";
                    check(&choice_1, 0, 1);
                    if (!choice_1)
                    {
                        printMenu(0);
                        break;
                    }
                }
                break;
            }
                
            case 2:
            {
                printMenu(2);
                
                int choice_2 = 10;
                while (choice_2)
                {
                    check(&choice_2, 0, 4);
                    switch (choice_2)
                    {
                        case 1:
                        {
                            DealBase.printBase();
                            cout << "Введите пункт: ";
                            break;
                        }
                            
                        case 2:
                        {
                            DealDate date;
                            dateMark(date);
                            string temp = to_string(date.Day) + '.' + to_string(date.Month) + '.' + to_string(date.Year);
                            DealBase.search(temp);
                            cout << "Введите пункт: ";
                            break;
                        }
                            
                        case 3:
                        {
                            Deal deal;
                            DealBase.transaction(deal, GoodsBase, DCardsBase);
                            DealBase.add(deal);
                            printMenu(2);
                            break;
                        }
                            
                        case 4:
                        {
                            DealBase.sortList();
                            DealBase.printBase();
                            cout << "Введите пункт: ";
                            break;
                        }
                            
                        default:
                            break;
                    }
                   
                }
                
                printMenu(0);
                break;
            }
                
            case 3:
            {
                printMenu(3);
                
                int choice_3 = 10;
                while (choice_3)
                {
                    check(&choice_3, 0, 4);
                    switch (choice_3)
                    {
                        case 1:
                        {
                            cout << "\t\tБаза Товаров Магазина:";
                            GoodsBase.printBase();
                            cout << "Введите пункт: ";
                            break;
                        }
                            
                        case 2:
                        {
                            string bcode;
                            bcodeCheck(bcode);
                            GoodsBase.search(bcode);
                            cout << "Введите пункт: ";
                            break;
                        }
                            
                        case 3:
                        {
                            ShopGoods temp;
                            cout << "Введите название товара: ";
                            cin >> temp.Name;
                            cout << "Введите цену товара: ";
                            cin >> temp.Price;
                            cout << "Введите кол-во товара: ";
                            cin >> temp.GoodBought;
                            bcodeCheck(temp.BarCode);
                            GoodsBase.add(temp);
                            printMenu(3);
                            break;
                        }
                            
                        case 4:
                        {
                            GoodsBase.sortList();
                            cout << "\t\tБаза Товаров Магазина:";
                            GoodsBase.printBase();
                            cout << "Введите пункт: ";
                            break;
                        }
                            
                        default:
                            break;
                    }
                   
                }
                
                printMenu(0);
                break;
            }
                
            case 4:
            {
                printMenu(4);
                
                int choice_4;
                check(&choice_4, 0, 4);
                while (choice_4)
                {
                    switch (choice_4)
                    {
                        case 1:
                        {
                            DCardsBase.printBase();
                            cout << "Введите пункт: ";
                            break;
                        }
                            
                        case 2:
                        {
                            int disc;
                            cout << "Введите примерное значение скидки(целое число): ";
                            check(&disc, 0, 100);
                            DCardsBase.search(disc);
                            cout << "Введите пункт: ";
                            break;
                        }
                            
                        case 3:
                        {
                            DiscountCard temp;
                            int code;
                            cout << "Введите номер карты(в формате: 00000000): ";
                            check(&code, 10000000, 99999999);
                            temp.DiscountCardCode = to_string(code);
                            
                            cout << "Введите объем скидки: ";
                            cin >> temp.Discount;
                            while (temp.Discount < 0 || temp.Discount > 100)
                            {
                                cout << "Ввод не верен!\nПовторите ввод: ";
                                cin >> temp.Discount;
                            }
                            DCardsBase.add(temp);
                            printMenu(4);
                            break;
                        }
                            
                        case 4:
                        {
                            DCardsBase.sortList();
                            DCardsBase.printBase();
                            cout << "Введите пункт: ";
                            break;
                        }
                            
                        default:
                            break;
                    }
                    check(&choice_4, 0, 4);
                }
                
                printMenu(0);
                break;
            }
                
            case 5:
            {
                system("clear");
                cout << "Разработал Аралин Игорь, гр. 053502\n";
                cout << "0 -> Вернуться в главное меню.\n";
                cout << "Введите пункт: ";
                
                int choice_5;
                check(&choice_5, 0, 0);
                printMenu(0);
                break;
            }
                
            default:
                break;
        }
        check(&choice, 0, 5);
    }
    
    if (GoodsBase.fwrite("productBase.txt"))
        return 1;
    if (DCardsBase.fwrite("cardBase.txt"))
        return 1;
    if (DealBase.fwrite("shopHistory.txt"))
        return 1;
    
    return 0;
}

#endif

int printMenu(int num)
{
    system("clear");
    switch(num)
    {
        case 0:
        {
            cout << "\t\tМеню програмы:\n";
            cout << "1 -> Режим обслуживания покупателей.\n";
            cout << "2 -> Работа с историей покупок.\n";
            cout << "3 -> Работа со списком товаров на продажу.\n";
            cout << "4 -> Работа с информацией о дисконтных картах.\n";
            cout << "5 -> Информация о разработчике.\n";
            cout << "0 -> Выход из программы.\n";
            break;
        }
            
        case 1:
        {
            cout << "\t\tРежим обслуживания покупателей:\n";
            break;
        }
            
        case 2:
        {
            cout << "\t\tРабота с историей покупок:\n";
            cout << "1 -> Отображение всей истории покупок.\n";
            cout << "2 -> Поиск в истории покупок по дате покупки.\n";
            cout << "3 -> Добавление новой записи в историю покупок.\n";
            cout << "4 -> Сортировка истории по цене корзины.\n";
            cout << "0 -> Вернуться в главное меню.\n";
            break;
        }
            
        case 3:
        {
            cout << "\t\tРабота со списком товаров на продажу:\n";
            cout << "1 -> Отображение всего списка товаров.\n";
            cout << "2 -> Поиск товара по штрихкоду.\n";
            cout << "3 -> Добавить новый товар.\n";
            cout << "4 -> Сортировка списка товаров по цене.\n";
            cout << "0 -> Вернуться в главное меню.\n";
            break;
        }
            
        case 4:
        {
            cout << "\t\tРабота с информацией о дисконтных картах:\n";
            cout << "1 -> Отображение всего списка дисконтных карт.\n";
            cout << "2 -> Поиск дисконтной карты по объему скидки.\n";
            cout << "3 -> Добавление дисконтных карт.\n";
            cout << "4 -> Сортировка списка дисконтных карт по объему скидки.\n";
            cout << "0 -> Вернуться в главное меню.\n";
            break;
        }
            
        default:
            return 1;
            break;
    }
    if (num != 1)
        cout << "Введите пункт: ";
    
    return 0;
}

void dateMark(DealDate &date)
{
    int day, month, year;
    
    cout << "Введите день покупки: ";
    check(&day, 1, 31);
    cout << "Введите месяц покупки: ";
    check(&month, 1, 12);
    cout << "Введите год покупки: ";
    check(&year, 1970, 2021);
    
    date.Day = day;
    date.Month = month;
    date.Year = year;
}

int fileRead(GoodsList &GoodsBase, DcardsList &DCardsBase, DealList &DealBase, string hist, string cards, string prods)
{
    ifstream historyin(hist, ios_base::in);
    if (!historyin.is_open())
        return 1;
    ifstream cardsin(cards, ios_base::in);
    if (!cardsin.is_open())
        return 1;
    ifstream productsin(prods, ios_base::in);
    if (!productsin.is_open())
        return 1;
    
    char c;
    
    while(!cardsin.eof())
    {
        DiscountCard temp;
        cardsin >> temp.DiscountCardCode;
        cardsin >> temp.Discount;
        DCardsBase.add(temp);
        cardsin >> c;
    }
    cardsin.close();
    
    while(!productsin.eof())
    {
        ShopGoods temp;
        productsin >> temp.Name;
        productsin >> temp.Price;
        productsin >> temp.GoodBought;
        productsin >> temp.BarCode;
        productsin >> c;
        GoodsBase.add(temp);
    }
    productsin.close();

    while (!historyin.eof())
    {
        Deal d;
        d.GoodsVariety = 0;
        string temps = "";
        
        historyin >> d.Date.Day;
        historyin >> d.Date.Month;
        historyin >> d.Date.Year;
        
        GoodsList *goods = new GoodsList;
        d.Summ = 0;
        
        while(temps != "#")
        {
            ShopGoods temp;
            string barcode;
            
            historyin >> barcode;
            temp.BarCode = barcode;
            
            GoodsBase.setGood(temp);
            historyin >> temp.GoodBought;
            goods->add(temp);
            d.Summ += temp.Price * temp.GoodBought;
            
            d.GoodsVariety++;
            
            historyin >> temps;
        }
        
        temps = "";
        
        d.ListOfBuyedGoods = goods;
        
        historyin >> d.IfUsedDiscount;
        if (d.IfUsedDiscount)
        {
            double disc;
            int code;
            historyin >> code;
            DCardsBase.search(code, disc);
            d.UsedDiscountCard.DiscountCardCode = to_string(code);
            d.UsedDiscountCard.Discount = disc;
            
            d.Summ = d.Summ * (100 - disc) / 100;
        }
        
        historyin >> d.IfUsedCreditCard;
        if (d.IfUsedCreditCard)
            historyin >> d.CreditCardCode;
        
        DealBase.add(d);
        historyin >> c;
    }
    historyin.close();
    
    return 0;
}

void check(int *a, int min, int max)
{
    int valid = 0;
    char inpStr[1024];
    char buffer = 0;
    
    while(!valid)
        {
            buffer = 0;
            if((scanf("%1023[^\n]%c",inpStr,&buffer) != 2) || buffer != '\n')
            {
                if(printf("Ввод не верен!\nПовторите ввод: "))
                    getchar();
            }
            else
                if((sscanf(inpStr,"%d%c",&*a,&buffer) != 1) || buffer != '\n')
                    printf("Ввод не верен!\nПовторите ввод: ");
            else
                if (*a < min || *a > max)
                    printf("Ввод не верен!\nПовторите ввод: ");
            else
                valid = 1;
        }
}

void bcodeCheck(string &bcode)
{
    cout << "Введите штрихкод товара(формат: ТР******): ";
    cin >> bcode;
    while (true)
    {
        if (bcode[0] == 'T' && bcode[1] == 'P' && bcode.length() == 8)
            break;
        else
        {
            cout << "Неверный формат! Повторите ввод штрихкода: ";
            cin >> bcode;
        }
    }
}

int baseCheck(GoodsList base, DcardsList cardBase)
{
    if (!base.getHead())
        return 1;
    if (!cardBase.getHead())
        return 1;
    return 0;
}
