#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int convert_little_big (int a, int b)
{
    a = a << 8;

    return (a |= b);
}
int main()
{
    FILE* f;
    int sum = 0, counter = 0, beg = 0, end = 0;
    int mas[10];

    f = fopen("dummyData.info", "r");

    if (f == NULL) {
        printf("ошибка\n");
        return -1;
    }

    while (counter < 10)
    {
        beg = convert_little_big(getc(f), getc(f));
        
        for (int j = 0; j < 2; j++)
        {
            
            getc(f);
        }

        mas[counter] = getc(f);

        for (int j = 0; j < 3; j++)
        {
            getc(f);
        }
        
        end = convert_little_big(getc(f), getc(f));

        if (beg != 0x0A || end != 0x0F)
            mas[counter] = 0;

        counter++;
    }
    
    counter--;
    while (counter >= 0)
    {
        mas[counter] = mas[counter] & 0xF;
       
        sum += mas[counter];
        counter--;
    }

    printf("%d", sum);

    fclose(f);
}