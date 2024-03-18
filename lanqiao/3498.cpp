#include <iostream>
#include <algorithm>

using namespace std;
const int N = 110;
struct Date
{
    int year;
    int month;
    int day;
};

bool leap = false;
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int main()
{
    int date1, date2;
    Date d1, d2;
    while (cin >> date1 >> date2)
    {

        if (date1 > date2)
            swap(date1, date2);
        d1.year = date1 / 10000;
        d1.month = (date1 / 100) % 100;
        d1.day = date1 % 100;
        d2.year = date2 / 10000;
        d2.month = (date2 / 100) % 100;
        d2.day = date2 % 100;
        int res = 0;
        for (int i = d1.year; i <= d2.year; i++)
        {
            res += 365;
            if (isLeap(i))
                res++;
        }
        for (int i = 1; i <= d1.month - 1; i++)
        {
            res -= day[i];
            if (isLeap(d1.year) && i == 2)
                res--;
        }
        res = res - d1.day + 1;
        for (int i = 12; i >= d2.month; i--)
        {
            res -= day[i];
            if (isLeap(d2.year) && i == 2)
                res--;
        }
        res = res + d2.day;
        printf("%d\n", res);
    }
    return 0;
}