#include <stdio.h>
#include <time.h>

int main() {
    int taps = 10;
    char target = 'z';
    char ch;

    printf("Finger tapping test\n");
    printf("Alternate between z and x as fast as you can.\n");
    printf("Press enter to start...");
    getchar();

    clock_t t1 = clock();

    for (int i = 0; i < taps; i++) {
        printf("press %c: ", target);
        scanf(" %c", &ch);

        if (target == 'z') {
            target = 'x';
        } else {
            target = 'z';
        }
    }

    clock_t t2 = clock();

    double total = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("\nDone!\n");
    printf("Time: %.2f seconds\n", total);
    printf("Taps/sec: %.2f\n", taps / total);

    return 0;
}
