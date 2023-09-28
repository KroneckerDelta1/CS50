#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start = 0;
    int end = 0;
    int current = 0;
    int years = 0;

    while (start < 9)
    {
        start = get_int("Start size: ");
        current = start;
    }

    while (end < start)
    {
        end = get_int("End size: ");
    }

    while (current < end)
    {
        int births = current / 3;
        int deaths = current / 4;
        current = current + births - deaths;
        years++;
    }

    printf("Years: %i\n", years);
}
