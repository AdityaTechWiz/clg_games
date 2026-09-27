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

#define TOTAL_TAPS 10

char read_tap_key() {
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
    for (int i = 0; i < bar_width; i++) {
        if (i < filled) printf(COLOR_CYAN "¦" COLOR_RESET);
        else printf(COLOR_DIM "¦" COLOR_RESET);
    }
    printf("] %d/%d\n", value, max_val);
}

int main() {
    char target = 'z';
    char ch;
    int correct_taps = 0;
    double split_times[TOTAL_TAPS];
    int tap_status[TOTAL_TAPS];

    printf("\n" COLOR_CYAN);
    printf("+----------------------------------------------------------+\n");
    printf("¦                ? SPEED TAP SPEEDRUN ?                   ¦\n");
    printf("+----------------------------------------------------------+\n" COLOR_RESET);
    printf("Instructions: Alternate between " COLOR_YELLOW "[Z]" COLOR_RESET " and " COLOR_BLUE "[X]" COLOR_RESET " as fast as possible!\n");
    printf(COLOR_DIM "Press ENTER to begin..." COLOR_RESET);
    while (getchar() != '\n');
    printf("\n");

    clock_t start_total = clock();
    clock_t split_start = start_total;

    for (int i = 0; i < TOTAL_TAPS; i++) {
        if (target == 'z') {
            printf(COLOR_BOLD "[%2d/%2d] Press " COLOR_YELLOW "Z" COLOR_RESET COLOR_BOLD ": " COLOR_RESET, i + 1, TOTAL_TAPS);
        } else {
            printf(COLOR_BOLD "[%2d/%2d] Press " COLOR_BLUE "X" COLOR_RESET COLOR_BOLD ": " COLOR_RESET, i + 1, TOTAL_TAPS);
        }

        ch = read_tap_key();
        clock_t split_end = clock();

        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }

        double split_duration = (double)(split_end - split_start) / CLOCKS_PER_SEC;
        split_times[i] = split_duration;
        split_start = split_end;

        if (ch == target) {
            tap_status[i] = 1;
            correct_taps++;
        } else {
            tap_status[i] = 0;
        }

        target = (target == 'z') ? 'x' : 'z';
    }

    clock_t end_total = clock();
    double total_time = (double)(end_total - start_total) / CLOCKS_PER_SEC;
    double taps_per_sec = (total_time > 0) ? (TOTAL_TAPS / total_time) : 0.0;
    double accuracy = ((double)correct_taps / TOTAL_TAPS) * 100.0;

    printf("\n" COLOR_CYAN);
    printf("+----------------------------------------------------------+\n");
    printf("¦                  FINAL TAP SCORECARD                     ¦\n");
    printf("+----------------------------------------------------------+\n" COLOR_RESET);

    printf(COLOR_BOLD "+--------------------------------------+\n");
    printf("¦  Tap  ¦  Split (sec) ¦    Status     ¦\n");
    printf("+-------+--------------+---------------¦\n" COLOR_RESET);

    for (int i = 0; i < TOTAL_TAPS; i++) {
        printf("¦  %2d   ¦    %6.2fs    ¦   %s   ¦\n",
               i + 1,
               split_times[i],
               tap_status[i] ? COLOR_GREEN "? ACCURATE" COLOR_RESET : COLOR_RED "? MISSED  " COLOR_RESET);
    }
    printf(COLOR_BOLD "+--------------------------------------+\n\n" COLOR_RESET);

    printf(COLOR_BOLD "Accuracy:       " COLOR_RESET);
    print_stat_bar(correct_taps, TOTAL_TAPS);
    printf(COLOR_BOLD "Total Duration: " COLOR_RESET "%.2f seconds\n", total_time);
    printf(COLOR_BOLD "Tapping Speed:  " COLOR_RESET COLOR_CYAN "%.2f taps/sec\n" COLOR_RESET, taps_per_sec);

    printf("\n" COLOR_BOLD "Agility Tier:   " COLOR_RESET);
    if (correct_taps == TOTAL_TAPS && taps_per_sec >= 4.0) {
        printf(COLOR_CYAN "? CYBORG DIGITS (Insane CPS!)\n" COLOR_RESET);
    } else if (correct_taps >= 8 && taps_per_sec >= 2.5) {
        printf(COLOR_GREEN "?? RHYTHM MASTER (Fluid & Rapid)\n" COLOR_RESET);
    } else if (correct_taps >= 6) {
        printf(COLOR_YELLOW "? CASUAL TAPPER (Steady Pace)\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "?? KEYBOARD STUMBLER (Hands Froze Up!)\n" COLOR_RESET);
    }

    printf(COLOR_DIM "\n----------------------------------------------------------\n" COLOR_RESET);
    printf("Run again to push your taps-per-second higher!\n\n");

    return 0;
}
