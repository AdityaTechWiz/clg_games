#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    char key;
    char target;

    srand(time(NULL));

    printf("Reaction Game! Press R, G, B, or Y when told.\n\n");

    for (int i = 1; i <= 5; i++) {
        int r = rand() % 4;

        if (r == 0) {
            printf("Round %d: Type RED (R): ", i);
            target = 'R';
        } else if (r == 1) {
            printf("Round %d: Type GREEN (G): ", i);
            target = 'G';
        } else if (r == 2) {
            printf("Round %d: Type BLUE (B): ", i);
            target = 'B';
        } else {
            printf("Round %d: Type YELLOW (Y): ", i);
            target = 'Y';
        }
        clock_t start = clock();
        scanf(" %c", &key);
        clock_t end = clock();
        
        if (key >= 'a' && key <= 'z') {
            key = key - 32;
        }

        double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

        if (key == target) {
            printf("Time: %.2f sec\n\n", timeTaken);
            score++;
        } else {
            printf("wrong key.\n\n");
        }
    }

    printf("r?You got %d out of 5 right.\n", score);

    return 0;
}
