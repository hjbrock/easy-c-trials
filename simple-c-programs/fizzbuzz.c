#include <stdio.h>

/* Print "Fizz" for all numbers from 1-100 that
 * are multiples of 3. Print "Buzz" for all 
 * multiples of 5. Print "FizzBuzz" for numbers
 * that are multiples of both 3 and 5. Print just
 * the number for all others.
 */
int main(void) {
    int i;

    for (i=1; i<101; i++) {
        if (i % 3 == 0)
            printf("Fizz");
        if (i % 5 == 0)
            printf("Buzz");
        if ((i % 3 != 0) && (i % 5 != 0))
            printf("%i",i);
        printf("\n");
    }
} 
