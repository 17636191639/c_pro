#include <stdio.h>
#include <stdlib.h>

int is_leap_year(int year);
int week(int year, int month, int day);
int day_in_month(int month, int year);

void calendar(int year)
{
    int i;
    int j;
    int month = 12;
    int days_in_month;
    int week_n;

    for(i = 1; i <= month; i++)
    {
        days_in_month = day_in_month(i, year);
        printf("/*year:%dmonth:%d*/\n", year , i);
        printf("一 二 三 四 五 六 日\n");
        week_n = week(year, i, 1);

        for(j = 0; j < week_n; j++)
        {
            printf("   ");
        }

        for(j = 1; j <= days_in_month; j++)
        {

            printf("%2d ", j);
            if(week(year, i, j) == 6)
            {
                printf("\n");
            }
        }
        printf("\n");
    }
}

int main()
{
    int year = 2020;
    
    scanf("%d", &year);
    
    if(year > 2040 && year < 1940)
    {
        printf("input error\n");
        exit(1);
    
    }
    calendar(year);

    return 0;
}

int is_leap_year(int year)
{
    if(year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }
    else if (year % 400 == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int day_in_month(int month,int year)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        return 31;        
    }else if (month == 2 && is_leap_year(year) == 1)
    {
        return 29;
    }else if(month == 2 && is_leap_year(year) == 0)
    {
        return 28;
    }else
    {
        return 30;
    }
}
int week(int year, int month, int day)
{
    if(month < 3)
    {
        return (day + 2 * (month + 12) + 3 * ((month + 12) + 1) / 5 + (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400)  % 7;
    }
    return (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
}
