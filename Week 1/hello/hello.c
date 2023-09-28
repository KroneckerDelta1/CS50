#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name;

    // Get the user's name.
    name = get_string("What's your name? ");

    // Say hello to the user.
    printf("hello, %s\n", name);
}