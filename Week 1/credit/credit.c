#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the card number.
    long number = get_long("Number: ");
    int numDigits = 0;

    // Get the total number of digits in the card.
    long length = number;

    while (length > 0)
    {
        length = length / 10;
        numDigits++;
    }

    // Extract the digits in the card.
    long tempNumber = number;
    int digitsLeft = numDigits;
    int digits[numDigits];

    while (digitsLeft > 0)
    {
        digits[digitsLeft - 1] = tempNumber % 10;
        tempNumber /= 10;
        digitsLeft -= 1;
    }

    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits
    // together.

    int sumMultDigits = 0;
    int multDigit = numDigits - 2;

    while (multDigit >= 0)
    {
        int product = digits[multDigit] * 2;

        if (product >= 10)
        {
            int first = product / 10;
            int second = product % 10;
            sumMultDigits += first + second;
        }
        else
        {
            sumMultDigits += product;
        }

        multDigit -= 2;
    }

    // Add the sum to the sum of the digits that weren’t multiplied by 2.

    int sumAddDigits = 0;
    int addDigit = numDigits - 1;

    while (addDigit >= 0)
    {
        sumAddDigits += digits[addDigit];
        addDigit -= 2;
    }

    // If the total’s last digit is not 0, the number is invalid!

    int finalCheck = (sumMultDigits + sumAddDigits) % 10;

    // It's a valid card, detemine what type.

    long firstTwo = number;

    if (numDigits != 16)
    {
        firstTwo = firstTwo / 10;
    }

    while (firstTwo > 100)
    {
        firstTwo = firstTwo / 100;
    }

    if ((numDigits != 13 && numDigits != 15 && numDigits != 16) || (finalCheck != 0))
    {
        printf("INVALID\n");
    }
    else if (firstTwo == 34 || firstTwo == 37)
    {
        printf("AMEX\n");
    }
    else if (firstTwo >= 51 && firstTwo <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (firstTwo >= 40 && firstTwo <= 49)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}