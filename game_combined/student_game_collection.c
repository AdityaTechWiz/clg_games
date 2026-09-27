#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void game1(void);
void game2(void);
void game3(void);
void game4(void);
void game5(void);
void game6(void);
void game7(void);

int main(void)
{
    int choice;

    while (1)
    {
        printf("\n");
        printf("============================================================\n");
        printf("                  STUDENT GAME COLLECTION                  \n");
        printf("============================================================\n");
        printf("Student: Aditya Ghosh\n\n");

        printf("1. Color Reflex Arena\n");
        printf("2. Speed Tap Speedrun\n");
        printf("3. Speed Tap Speedrun (Anubhab Ray)\n");
        printf("4. Compass Trail - Follow Me\n");
        printf("5. Memory Maze - Vanishing Room\n");
        printf("6. Signal & Swat\n");
        printf("7. Trail Connector\n");
        printf("0. Exit\n\n");

        printf("Enter the game you want to play: ");
        if (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                game1();
                break;
            case 2:
                game2();
                break;
            case 3:
                game3();
                break;
            case 4:
                game4();
                break;
            case 5:
                game5();
                break;
            case 6:
                game6();
                break;
            case 7:
                game7();
                break;
            case 0:
                printf("\nThank you for playing!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a game from 0 to 7.\n");
        }

        printf("\n============================================================\n");
        printf("Returning to the main game menu...\n");
        printf("============================================================\n");
    }

    return 0;
}

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

#define TOTAL_ROUNDS_1 5

char read_key_1() {
    char ch;
    scanf(" %c", &ch);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return ch;
}

void print_stat_bar_1(int value, int max_val) {
    int bar_width = 20;
    int filled = (value * bar_width) / max_val;
    printf("[");
    for(int i = 0; i < bar_width; i++) {
        if (i < filled) printf(COLOR_CYAN " " COLOR_RESET);
        else printf(COLOR_DIM " " COLOR_RESET);
    }
    printf("] %d/%d\n", value, max_val);
}

void game1() {
    int score = 0;
    char key;
    char target;
    double round_times[TOTAL_ROUNDS_1];
    int round_correct[TOTAL_ROUNDS_1];
    double total_time = 0.0;

    srand((unsigned int)time(NULL));

    printf("\n" COLOR_CYAN);
    printf("+----------------------------------------------------------+\n");
    printf("                  ? COLOR REFLEX ARENA ?                   \n");
    printf("+----------------------------------------------------------+\n" COLOR_RESET);
    printf("Instructions: Hit the matching key (" COLOR_RED "R" COLOR_RESET ", " 
           COLOR_GREEN "G" COLOR_RESET ", " COLOR_BLUE "B" COLOR_RESET ", " 
           COLOR_YELLOW "Y" COLOR_RESET ") as fast as you can!\n");
    printf(COLOR_DIM "Press ENTER to start the challenge..." COLOR_RESET);
    while (getchar() != '\n');
    printf("\n");

    for (int i = 0; i < TOTAL_ROUNDS_1; i++) {
        int r = rand() % 4;

        printf(COLOR_BOLD "-- Round %d of %d --\n" COLOR_RESET, i + 1, TOTAL_ROUNDS_1);

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
        key = read_key_1();
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

    double avg_time = total_time / TOTAL_ROUNDS_1;
    double accuracy = ((double)score / TOTAL_ROUNDS_1) * 100.0;

    printf("\n" COLOR_CYAN);
    printf("+----------------------------------------------------------+\n");
    printf("                     PERFORMANCE REPORT                     \n");
    printf("+----------------------------------------------------------+\n" COLOR_RESET);

    printf(COLOR_BOLD "+--------------------------------------+\n");
    printf("  Round    Time (sec)       Status      \n");
    printf("+-------+--------------+--------------- \n" COLOR_RESET);

    for (int i = 0; i < TOTAL_ROUNDS_1; i++) {
        printf("    %d        %6.2fs        %s    \n", 
               i + 1, 
               round_times[i], 
               round_correct[i] ? COLOR_GREEN "? PASSED " COLOR_RESET : COLOR_RED "? FAILED " COLOR_RESET);
    }
    printf(COLOR_BOLD "+--------------------------------------+\n\n" COLOR_RESET);

    printf(COLOR_BOLD "Accuracy Rate: " COLOR_RESET);
    print_stat_bar_1(score, TOTAL_ROUNDS_1);
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

    return;
}

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

#define TOTAL_TAPS_2 10

char read_tap_key_2() {
    char ch;
    scanf(" %c", &ch);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return ch;
}

void print_stat_bar_2(int value, int max_val) {
    int bar_width = 20;
    int filled = (value * bar_width) / max_val;
    printf("[");
    for (int i = 0; i < bar_width; i++) {
        if (i < filled) printf(COLOR_CYAN "¦" COLOR_RESET);
        else printf(COLOR_DIM "¦" COLOR_RESET);
    }
    printf("] %d/%d\n", value, max_val);
}

void game2() {
    char target = 'z';
    char ch;
    int correct_taps = 0;
    double split_times[TOTAL_TAPS_2];
    int tap_status[TOTAL_TAPS_2];

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

    for (int i = 0; i < TOTAL_TAPS_2; i++) {
        if (target == 'z') {
            printf(COLOR_BOLD "[%2d/%2d] Press " COLOR_YELLOW "Z" COLOR_RESET COLOR_BOLD ": " COLOR_RESET, i + 1, TOTAL_TAPS_2);
        } else {
            printf(COLOR_BOLD "[%2d/%2d] Press " COLOR_BLUE "X" COLOR_RESET COLOR_BOLD ": " COLOR_RESET, i + 1, TOTAL_TAPS_2);
        }

        ch = read_tap_key_2();
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
    double taps_per_sec = (total_time > 0) ? (TOTAL_TAPS_2 / total_time) : 0.0;
    double accuracy = ((double)correct_taps / TOTAL_TAPS_2) * 100.0;

    printf("\n" COLOR_CYAN);
    printf("+----------------------------------------------------------+\n");
    printf("¦                  FINAL TAP SCORECARD                     ¦\n");
    printf("+----------------------------------------------------------+\n" COLOR_RESET);

    printf(COLOR_BOLD "+--------------------------------------+\n");
    printf("¦  Tap  ¦  Split (sec) ¦    Status     ¦\n");
    printf("+-------+--------------+---------------¦\n" COLOR_RESET);

    for (int i = 0; i < TOTAL_TAPS_2; i++) {
        printf("¦  %2d   ¦    %6.2fs    ¦   %s   ¦\n",
               i + 1,
               split_times[i],
               tap_status[i] ? COLOR_GREEN "? ACCURATE" COLOR_RESET : COLOR_RED "? MISSED  " COLOR_RESET);
    }
    printf(COLOR_BOLD "+--------------------------------------+\n\n" COLOR_RESET);

    printf(COLOR_BOLD "Accuracy:       " COLOR_RESET);
    print_stat_bar_2(correct_taps, TOTAL_TAPS_2);
    printf(COLOR_BOLD "Total Duration: " COLOR_RESET "%.2f seconds\n", total_time);
    printf(COLOR_BOLD "Tapping Speed:  " COLOR_RESET COLOR_CYAN "%.2f taps/sec\n" COLOR_RESET, taps_per_sec);

    printf("\n" COLOR_BOLD "Agility Tier:   " COLOR_RESET);
    if (correct_taps == TOTAL_TAPS_2 && taps_per_sec >= 4.0) {
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

    return;
}

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

#define TOTAL_TAPS_3 10

char read_tap_key_3() {
    char ch;
    scanf(" %c", &ch);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return ch;
}

void print_stat_bar_3(int value, int max_val) {
    int bar_width = 20;
    int filled = (value * bar_width) / max_val;
    printf("[");
    for (int i = 0; i < bar_width; i++) {
        if (i < filled) printf(COLOR_CYAN "¦" COLOR_RESET);
        else printf(COLOR_DIM "¦" COLOR_RESET);
    }
    printf("] %d/%d\n", value, max_val);
}

void game3() {
    char target = 'z';
    char ch;
    int correct_taps = 0;
    double split_times[TOTAL_TAPS_3];
    int tap_status[TOTAL_TAPS_3];

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

    for (int i = 0; i < TOTAL_TAPS_3; i++) {
        if (target == 'z') {
            printf(COLOR_BOLD "[%2d/%2d] Press " COLOR_YELLOW "Z" COLOR_RESET COLOR_BOLD ": " COLOR_RESET, i + 1, TOTAL_TAPS_3);
        } else {
            printf(COLOR_BOLD "[%2d/%2d] Press " COLOR_BLUE "X" COLOR_RESET COLOR_BOLD ": " COLOR_RESET, i + 1, TOTAL_TAPS_3);
        }

        ch = read_tap_key_3();
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
    double taps_per_sec = (total_time > 0) ? (TOTAL_TAPS_3 / total_time) : 0.0;
    double accuracy = ((double)correct_taps / TOTAL_TAPS_3) * 100.0;

    printf("\n" COLOR_CYAN);
    printf("+----------------------------------------------------------+\n");
    printf("¦                  FINAL TAP SCORECARD                     ¦\n");
    printf("+----------------------------------------------------------+\n" COLOR_RESET);

    printf(COLOR_BOLD "+--------------------------------------+\n");
    printf("¦  Tap  ¦  Split (sec) ¦    Status     ¦\n");
    printf("+-------+--------------+---------------¦\n" COLOR_RESET);

    for (int i = 0; i < TOTAL_TAPS_3; i++) {
        printf("¦  %2d   ¦    %6.2fs    ¦   %s   ¦\n",
               i + 1,
               split_times[i],
               tap_status[i] ? COLOR_GREEN "? ACCURATE" COLOR_RESET : COLOR_RED "? MISSED  " COLOR_RESET);
    }
    printf(COLOR_BOLD "+--------------------------------------+\n\n" COLOR_RESET);

    printf(COLOR_BOLD "Accuracy:       " COLOR_RESET);
    print_stat_bar_3(correct_taps, TOTAL_TAPS_3);
    printf(COLOR_BOLD "Total Duration: " COLOR_RESET "%.2f seconds\n", total_time);
    printf(COLOR_BOLD "Tapping Speed:  " COLOR_RESET COLOR_CYAN "%.2f taps/sec\n" COLOR_RESET, taps_per_sec);

    printf("\n" COLOR_BOLD "Agility Tier:   " COLOR_RESET);
    if (correct_taps == TOTAL_TAPS_3 && taps_per_sec >= 4.0) {
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

    return;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRAIL_LENGTH_4 8
#define TOTAL_ROUNDS_4 2
#define SECONDS_PER_STEP_4 5   


void flush_line_4(void) {
    int c;
    c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}


void wait_for_enter_4(void) {
    printf("(Press ENTER to continue) ");
    flush_line_4();
}

void clear_screen_4(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char opposite_direction_4(char d) {
    if (d == 'N') return 'S';
    if (d == 'S') return 'N';
    if (d == 'E') return 'W';
    if (d == 'W') return 'E';
    return '?';
}


void print_full_name_4(char d) {
    if (d == 'N') printf("NORTH");
    else if (d == 'S') printf("SOUTH");
    else if (d == 'E') printf("EAST");
    else if (d == 'W') printf("WEST");
}

void game4() {
    
    char directions[4] = {'N', 'S', 'E', 'W'};
    char trail[MAX_TRAIL_LENGTH_4];
    char correct_return[MAX_TRAIL_LENGTH_4];
    char player_answer[MAX_TRAIL_LENGTH_4];
    char input[10];
    int round;
    int trail_length;
    int i;
    int random_index;
    int mistakes;
    int correct;
    double accuracy;
    double time_taken;
    double max_time;
    double accuracy_score;
    double time_score;
    double score;
    time_t start_time;
    time_t end_time;
    time_t now;
    struct tm *t;
    FILE *file;
    

    srand(time(NULL));

    printf("===================================\n");
    printf("      COMPASS TRAIL - FOLLOW ME\n");
    printf("===================================\n\n");
    printf("Remember the directions shown.\n");
    printf("Memorise it and walk it back in REVERSE later.\n");
    printf("Each step waits for YOU to press ENTER, so take\n");
    printf("as much time as you need.\n\n");
    printf("There are %d rounds, and the path gets LONGER each\n", TOTAL_ROUNDS_4);
    printf("round: Round 1 has 4 directions, Round 2 has 6.\n\n");
    printf("You also get a SCORE out of 100: 70 marks come from your\n");
    printf("accuracy, and 30 marks come from your speed. This way,\n");
    printf("answering fast but wrong won't score well, and being slow\n");
    printf("even if correct won't get full marks either.\n\n");
    wait_for_enter_4();

    for (round = 1; round <= TOTAL_ROUNDS_4; round++) {

        trail_length = 4 + (round - 1) * 2;   
        if (trail_length > MAX_TRAIL_LENGTH_4) trail_length = MAX_TRAIL_LENGTH_4;

        
        for (i = 0; i < trail_length; i++) {
            random_index = rand() % 4;
            trail[i] = directions[random_index];
        }

        clear_screen_4();
        printf("===================================\n");
        printf("   ROUND %d  (%d directions)\n", round, trail_length);
        printf("===================================\n\n");

        
        for (i = 0; i < trail_length; i++) {
            printf("\nStep %d: Go ", i + 1);
            print_full_name_4(trail[i]);
            printf(" ...\n");
            wait_for_enter_4();
        }

        printf("\nYou have reached the destination! Get ready...\n");
        wait_for_enter_4();

        
        clear_screen_4();

        printf("===================================\n");
        printf("   ROUND %d - RETURN TRIP\n", round);
        printf("===================================\n\n");
        printf("The path is gone. Now try to get back to original point.\n");
        printf("Remember: reverse the order AND flip each direction\n");
        printf("(N becomes S, S becomes N, E becomes W, W becomes E, while returning)\n\n");
        wait_for_enter_4();

        
        for (i = 0; i < trail_length; i++) {
            correct_return[i] = opposite_direction_4(trail[trail_length - 1 - i]);
        }

        
        printf("\n");
        start_time = time(NULL);

        for (i = 0; i < trail_length; i++) {
            printf("Return step %d (type N, S, E or W): ", i + 1);
            scanf("%9s", input);
            flush_line_4();   
            player_answer[i] = input[0];
            
            if (player_answer[i] >= 'a' && player_answer[i] <= 'z') {
                player_answer[i] = player_answer[i] - 32;
            }
        }

        end_time = time(NULL);
        time_taken = difftime(end_time, start_time);

       
        mistakes = 0;
        printf("\n----- RESULT -----\n");
        printf("Correct return path : ");
        for (i = 0; i < trail_length; i++) {
            printf("%c ", correct_return[i]);
        }
        printf("\nYour return path    : ");
        for (i = 0; i < trail_length; i++) {
            printf("%c ", player_answer[i]);
            if (player_answer[i] != correct_return[i]) {
                mistakes++;
            }
        }
        printf("\n");

        correct = trail_length - mistakes;
        accuracy = (correct / (double)trail_length) * 100;

        
        max_time = trail_length * SECONDS_PER_STEP_4;   

        accuracy_score = (accuracy / 100.0) * 70.0;

        time_score = ((max_time - time_taken) / max_time) * 30.0;
        if (time_score < 0) time_score = 0;     
        if (time_score > 30) time_score = 30;   

        score = accuracy_score + time_score;
        

        printf("\nRound %d Result -> Correct: %d/%d | Mistakes: %d | Accuracy: %.1f%% | Time: %.2f seconds\n",
               round, correct, trail_length, mistakes, accuracy, time_taken);
        printf("Score (Accuracy 70%% + Speed 30%%): %.2f out of 100\n", score);

        
        file = fopen("compass_trail_results.txt", "a");
        if (file != NULL) {
            now = time(NULL);
            t = localtime(&now);
            fprintf(file,
                "%04d-%02d-%02d %02d:%02d | Round=%d TrailLength=%d Correct=%d Mistakes=%d Accuracy=%.1f%% Time=%.2fs Score=%.2f\n",
                t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                t->tm_hour, t->tm_min,
                round, trail_length, correct, mistakes, accuracy, time_taken, score);
            fclose(file);
        }

        if (round < TOTAL_ROUNDS_4) {
            printf("\nReady for the next round? The path will be longer this time.\n");
            wait_for_enter_4();
        }
    }

    printf("\n\nAll rounds complete! Your results are saved in compass_trail_results.txt\n");
    printf("Play again another day to see how your orientation recall changes over time.\n");

    return;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_ROUNDS_5 3
#define SECONDS_PER_OBJECT_5 6   


void flush_line_5(void) {
    int c;
    c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}


void wait_for_enter_5(void) {
    printf("(Press ENTER to continue) ");
    flush_line_5();
}

void clear_screen_5(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void print_round_banner_5(int round, int count) {
    printf("\n-----------------------------------\n");
    printf("   ROUND %d  (%d objects)\n", round, count);
    printf("-----------------------------------\n\n");
}

void game5() {
    
    char objects[8][20] = {"Pen", "Book", "Clock", "Key",
                            "Cup", "Chair", "Phone", "Bag"};
    int round;
    int i, j;
    int count;
    int order[8];
    int answer[8];
    int temp;
    int correct;
    int mistakes;
    double accuracy;
    double time_taken;
    double max_time;
    double accuracy_score;
    double time_score;
    double score;
    time_t now;
    time_t start_time;
    time_t end_time;
    struct tm *t;
    FILE *file;

    
    int history_count[TOTAL_ROUNDS_5];
    int history_correct[TOTAL_ROUNDS_5];
    int history_mistakes[TOTAL_ROUNDS_5];
    double history_accuracy[TOTAL_ROUNDS_5];
    double history_time[TOTAL_ROUNDS_5];
    double history_score[TOTAL_ROUNDS_5];
    

    srand(time(NULL));

    
    printf("===================================\n");
    printf("     MEMORY MAZE - VANISHING ROOM\n");
    printf("===================================\n\n");
    printf("HOW TO PLAY:\n");
    printf("1. A list of everyday objects will appear on screen.\n");
    printf("2. Read them and remember the ORDER they are shown in.\n");
    printf("3. Press ENTER when you are ready - the objects will vanish.\n");
    printf("4. A numbered reference list will appear (each object has\n");
    printf("   a fixed number). Type the NUMBERS in the same order you\n");
    printf("   saw the objects.\n");
    printf("5. Your accuracy, mistakes, and response time are recorded.\n");
    printf("6. You also get a SCORE out of 100: 70 marks come from your\n");
    printf("   accuracy, and 30 marks come from your speed. This way,\n");
    printf("   answering fast but wrong won't score well, and being slow\n");
    printf("   even if correct won't get full marks either.\n\n");
    printf("There are %d rounds, and each round is HARDER than the last:\n", TOTAL_ROUNDS_5);
    printf("   Round 1 -> 3 objects\n");
    printf("   Round 2 -> 4 objects\n");
    printf("   Round 3 -> 5 objects\n\n");
    printf("At the end, you will see a summary of all 3 rounds together,\n");
    printf("and your full history will be saved in memory_maze_results.txt\n\n");
    wait_for_enter_5();
    

    for (round = 1; round <= TOTAL_ROUNDS_5; round++) {

        count = round + 2;          
        if (count > 8) count = 8;   

        for (i = 0; i < count; i++) {
            order[i] = i;
        }

        
        for (i = count - 1; i > 0; i--) {
            j = rand() % (i + 1);
            temp = order[i];
            order[i] = order[j];
            order[j] = temp;
        }

       
        clear_screen_5();
        print_round_banner_5(round, count);

        printf("Remember these objects IN ORDER:\n\n");
        for (i = 0; i < count; i++) {
            printf("%d. %s\n", i + 1, objects[order[i]]);
        }

        printf("\nTake your time reading the list above.\n");
        wait_for_enter_5();   

        
        clear_screen_5();

        printf("Objects hidden! Here is the reference list (each object\n");
        printf("has a fixed number, NOT the order they were shown in):\n");
        for (i = 0; i < count; i++) {
            printf("%d = %s\n", i, objects[i]);
        }

        printf("\nType the NUMBER of each object in the order you saw them.\n");

        start_time = time(NULL);

        for (i = 0; i < count; i++) {
            printf("Position %d: ", i + 1);
            scanf("%d", &answer[i]);
            flush_line_5();   
        }

        end_time = time(NULL);
        time_taken = difftime(end_time, start_time);

       
        correct = 0;
        mistakes = 0;

        printf("\nCorrect order was : ");
        for (i = 0; i < count; i++) printf("%s ", objects[order[i]]);

        printf("\nYou answered      : ");
        for (i = 0; i < count; i++) {
            if (answer[i] >= 0 && answer[i] < count)
                printf("%s ", objects[answer[i]]);
            else
                printf("? ");

            if (answer[i] == order[i]) correct++;
            else mistakes++;
        }
        printf("\n");

        accuracy = (correct / (double)count) * 100;

        
        max_time = count * SECONDS_PER_OBJECT_5;   

        accuracy_score = (accuracy / 100.0) * 70.0;

        time_score = ((max_time - time_taken) / max_time) * 30.0;
        if (time_score < 0) time_score = 0;     
        if (time_score > 30) time_score = 30;   

        score = accuracy_score + time_score;
       

        printf("\nRound %d Result -> Correct: %d/%d | Mistakes: %d | Accuracy: %.1f%% | Time: %.2f seconds\n",
               round, correct, count, mistakes, accuracy, time_taken);
        printf("Score (Accuracy 70%% + Speed 30%%): %.2f out of 100\n", score);

       
        history_count[round - 1]    = count;
        history_correct[round - 1]  = correct;
        history_mistakes[round - 1] = mistakes;
        history_accuracy[round - 1] = accuracy;
        history_time[round - 1]     = time_taken;
        history_score[round - 1]    = score;

       
        file = fopen("memory_maze_results.txt", "a");
        if (file != NULL) {
            now = time(NULL);
            t = localtime(&now);
            fprintf(file,
                "%04d-%02d-%02d %02d:%02d | Round=%d Objects=%d Correct=%d Mistakes=%d Accuracy=%.1f%% Time=%.2fs Score=%.2f\n",
                t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                t->tm_hour, t->tm_min,
                round, count, correct, mistakes, accuracy, time_taken, score);
            fclose(file);
        }

        if (round < TOTAL_ROUNDS_5) {
            printf("\nReady for the next round? It will be a little harder.\n");
            wait_for_enter_5();
        }
    }

    
    printf("\n\n===================================\n");
    printf("      FINAL SUMMARY - ALL ROUNDS\n");
    printf("===================================\n\n");
    for (round = 1; round <= TOTAL_ROUNDS_5; round++) {
        printf("Round %d (%d objects): Correct %d/%d | Mistakes %d | Accuracy %.1f%% | Time %.2f sec | Score %.2f/100\n",
               round,
               history_count[round - 1],
               history_correct[round - 1], history_count[round - 1],
               history_mistakes[round - 1],
               history_accuracy[round - 1],
               history_time[round - 1],
               history_score[round - 1]);
    }

    printf("\nYour whole history across every session you have ever played\n");
    printf("is saved in memory_maze_results.txt\n");
    printf("Play again another day to see how your memory performance changes over time.\n");

    return;
}

#include <stdio.h>
#include <stdlib.h>

void game6() {
    int i;
    char answer;
    int signal;
    int correct = 0;
    int wrong = 0;
    float accuracy;

    printf("SIGNAL & SWAT\n");
    printf("G = GO     -> Press G\n");
    printf("N = NO-GO  -> Press N\n");
    printf("You will receive 10 random signals.\n");
    printf("Respond as quickly and correctly as possible.\n\n");

    for (i = 1; i <= 10; i++) {
        signal = rand() % 2;

        printf("Signal %d: ", i);

        if (signal == 0) {
            printf("G (GO) -> ");
            scanf(" %c", &answer);

            if (answer == 'g' || answer == 'G') {
                printf("Correct!\n\n");
                correct++;
            } else {
                printf("Wrong! The correct response was G.\n\n");
                wrong++;
            }
        } else {
            printf("N (NO-GO) -> ");
            scanf(" %c", &answer);

            if (answer == 'n' || answer == 'N') {
                printf("Correct!\n\n");
                correct++;
            } else {
                printf("Wrong! The correct response was N.\n\n");
                wrong++;
            }
        }
    }

    accuracy = (correct / 10.0) * 100;

    printf("             RESULT\n");
    printf("Correct responses : %d\n", correct);
    printf("Wrong responses : %d\n", wrong);
    printf("Accuracy : %.1f%%\n", accuracy);

    if (accuracy == 100)
        printf("Performance: PERFECT! Excellent response.\n");
    else if (accuracy >= 80)
        printf("Performance: GREAT JOB!\n");
    else if (accuracy >= 60)
        printf("Performance: GOOD! Keep practicing.\n");
    else
        printf("Performance: KEEP PRACTICING!\n");

    return;
}

#include <stdio.h>

void showInstructions() {
    printf("HOW TO PLAY\n");
    printf("Connect the trail by entering the correct character in order.\n");
    printf("Correct answer: +10 points\n");
    printf("Wrong answer: Lose 1 life\n");
    printf("You have 3 lives.\n");
    printf("Complete the full sequence to win.\n");
}

void playGame() {
    char sequence[] = {'1', 'A', '2', 'B', '3', 'C', '4', 'D'};
    char input;
    int position = 0;
    int lives = 3;
    int score = 0;

    printf("TRAIL CONNECTOR\n");
    printf("Connect the trail in this order:\n");
    printf("1 -> A -> 2 -> B -> 3 -> C -> 4 -> D\n");

    while (position < 8 && lives > 0)
    {
        printf("Lives: %d | Score: %d\n", lives, score);
        printf("Enter next connector: ");
        scanf(" %c", &input);

        if (input == sequence[position])
        {
            printf("Correct! The trail continues.\n\n");
            score += 10;
            position++;
        }
        else
        {
            printf("Wrong connector! Expected: %c\n", sequence[position]);
            lives--;
            printf("You lost 1 life.\n\n");
        }
    }

    printf("RESULT ->\n");

    if (position == 8)
    {
        printf("TRAIL COMPLETE! YOU WIN!\n");
        printf("Final Score: %d\n", score);
        printf("Lives Remaining: %d\n", lives);
    }
    else
    {
        printf("GAME OVER!\n");
        printf("You could not complete the trail.\n");
        printf("Final Score: %d\n", score);
    }
}

void game7()
{
    int choice;

    while (1) {
        printf("TRAIL CONNECTOR\n");
        printf("1. Start Game\n");
        printf("2. Instructions\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            playGame();
        else if (choice == 2)
            showInstructions();
        else if (choice == 3) {
            printf("Thank you for visiting!\n");
            break;
        }
        else
            printf("Invalid choice. Please enter correct choice.\n");
    }

    return;
}