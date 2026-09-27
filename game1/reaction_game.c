#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_CYAN    "\033[1;36m"
#define COLOR_BOLD    "\033[1m"
#define COLOR_DIM     "\033[2m"

#define TOTAL_ROUNDS 5

char read_key() {
    char ch;
    scanf(" %c", &ch);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return ch;
}

void print_stat_bar(int value, int max_val) {
    int bar_width = 20;
    int filled = (value * bar_width) / max_val;
    printf("[");
    for(int i = 0; i < bar_width; i++) {
        if (i < filled) printf(COLOR_CYAN "�" COLOR_RESET);
        else printf(COLOR_DIM "�" COLOR_RESET);
    }
    printf("] %d/%d\n", value, max_val);
}

int main() {
    int score = 0;
    char key;
    char target;
    double round_times[TOTAL_ROUNDS];
    int round_correct[TOTAL_ROUNDS];
    double total_time = 0.0;

    srand((unsigned int)time(NULL));

    printf("\n" COLOR_CYAN);
    printf("+----------------------------------------------------------+\n");
    printf("�                 ? COLOR REFLEX ARENA ?                  �\n");
    printf("+----------------------------------------------------------+\n" COLOR_RESET);
    printf("Instructions: Hit the matching key (" COLOR_RED "R" COLOR_RESET ", " 
           COLOR_GREEN "G" COLOR_RESET ", " COLOR_BLUE "B" COLOR_RESET ", " 
           COLOR_YELLOW "Y" COLOR_RESET ") as fast as you can!\n");
    printf(COLOR_DIM "Press ENTER to start the challenge..." COLOR_RESET);
    while (getchar() != '\n');
    printf("\n");

    for (int i = 0; i < TOTAL_ROUNDS; i++) {
        int r = rand() % 4;

        printf(COLOR_BOLD "-- Round %d of %d --\n" COLOR_RESET, i + 1, TOTAL_ROUNDS);

        if (r == 0) {
            printf(">> Press " COLOR_RED "[R] RED" COLOR_RESET "    : ");
            target = 'R';
        } else if (r == 1) {
            printf(">> Press " COLOR_GREEN "[G] GREEN" COLOR_RESET "  : ");
            target = 'G';
        } else if (r == 2) {
            printf(">> Press " COLOR_BLUE "[B] BLUE" COLOR_RESET "   : ");
            target = 'B';
        } else {
            printf(">> Press " COLOR_YELLOW "[Y] YELLOW" COLOR_RESET " : ");
            target = 'Y';
        }

        clock_t start = clock();
        key = read_key();
        clock_t end = clock();

        if (key >= 'a' && key <= 'z') {
            key = key - 32;
        }

        double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
        round_times[i] = timeTaken;

        if (key == target) {
            printf(COLOR_GREEN "? Correct! (%.2f s)\n\n" COLOR_RESET, timeTaken);
            score++;
            round_correct[i] = 1;
            total_time += timeTaken;
        } else {
            printf(COLOR_RED "? Wrong! You entered '%c' (%.2f s)\n\n" COLOR_RESET, key, timeTaken);
            round_correct[i] = 0;
            total_time += timeTaken;
        }
    }

    double avg_time = total_time / TOTAL_ROUNDS;
    double accuracy = ((double)score / TOTAL_ROUNDS) * 100.0;

    printf("\n" COLOR_CYAN);
    printf("+----------------------------------------------------------+\n");
    printf("�                    PERFORMANCE REPORT                    �\n");
    printf("+----------------------------------------------------------+\n" COLOR_RESET);

    printf(COLOR_BOLD "+--------------------------------------+\n");
    printf("� Round �  Time (sec)  �    Status     �\n");
    printf("+-------+--------------+---------------�\n" COLOR_RESET);

    for (int i = 0; i < TOTAL_ROUNDS; i++) {
        printf("�   %d   �    %6.2fs    �   %s   �\n", 
               i + 1, 
               round_times[i], 
               round_correct[i] ? COLOR_GREEN "? PASSED " COLOR_RESET : COLOR_RED "? FAILED " COLOR_RESET);
    }
    printf(COLOR_BOLD "+--------------------------------------+\n\n" COLOR_RESET);

    printf(COLOR_BOLD "Accuracy Rate: " COLOR_RESET);
    print_stat_bar(score, TOTAL_ROUNDS);
    printf(COLOR_BOLD "Average Speed: " COLOR_RESET "%.2f seconds\n", avg_time);

    printf("\n" COLOR_BOLD "Reflex Tier: " COLOR_RESET);
    if (score == 5 && avg_time < 0.60) {
        printf(COLOR_CYAN "? GODLIKE REFLEXES (Esports Ready!)\n" COLOR_RESET);
    } else if (score >= 4 && avg_time < 1.00) {
        printf(COLOR_GREEN "?? SHARP SHOOTER (Excellent focus)\n" COLOR_RESET);
    } else if (score >= 3) {
        printf(COLOR_YELLOW "? AVERAGE REFLEXES (Solid run)\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "?? SLEEPING TURTLE (Need more coffee!)\n" COLOR_RESET);
    }

    printf(COLOR_DIM "\n----------------------------------------------------------\n" COLOR_RESET);
    printf("Thanks for playing! Run the program again to beat your time.\n\n");

    return 0;
}
