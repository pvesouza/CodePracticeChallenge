#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


int main()
{
    int n = 0;
    int anterior1 = 0;
    int anterior2 = 1;
    int sum  = 0;

    printf("Choose a number n such as 0 < N < 46\n");

    scanf("%d", &n);

    // In case n is greater than 2
    if (n >= 3) {
        printf("%d %d", anterior1, anterior2);

        for (int i = 3; i <= n; i++) {
            sum = anterior1 + anterior2;
            anterior1 = anterior2;
            anterior2 = sum;
            printf(" %d", sum);
        }
        printf("\n");
    }
    else if (n == 2) {
        printf("%d %d", anterior1, anterior2);
    }
    else {
        printf("%d", anterior1);
    }



    return 0;
}
