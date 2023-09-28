#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    int row = 1;

    // Get the height of the pyramid.
    while (height > 8 || height < 1)
    {
        height = get_int("Height: ");
    }

    // Make the pyramid.
    while (height >= row)
    {
        // Print the left side of the pyramid.
        printf("%.*s", (height - row), "        ");
        printf("%.*s", row, "########");

        // Print the space in the center.
        printf("  ");

        // Print the right side of the pyramid.
        printf("%.*s\n", row, "########");

        // Next row.
        row++;
    }
}