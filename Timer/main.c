#include <stdio.h>
#include <time.h>
#include <unistd.h>

void run_stopwatch() {
    struct timespec start, end;
    char buf[2];

    printf("Stopwatch: press Enter to start...\n");
    fgets(buf, sizeof(buf), stdin);
    clock_gettime(CLOCK_MONOTONIC, &start);

    printf("The countdown is on... press Enter to stop...\n");
    fgets(buf, sizeof(buf),stdin);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec - start.tv_nsec) / 1e9;
    printf("It's gone: %.2f sec.\n", elapsed);
}

void run_timer() {
    int seconds;
    printf("Timer: Enter the time in seconds: ");
    if (scanf("%d", &seconds) != 1 || seconds <= 0) {
        printf("Incorrect value\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    printf("Start timer for %d sec. (Ctrl+C for interrupt)\n");
    while (seconds > 0) {
        printf("\rLeft: %02d:%02d ", seconds / 60, seconds % 60);
        fflush(stdout);
        sleep(1);
        seconds--;
    }

    printf("\rLeft: 00:00\n");
    printf("Time's up!\n");
}

int main () {
    int choice;

    for (;;) {
        printf("1) Stopwatch\n");
        printf("2) Timer\n");
        printf("3) Exit\n");
        printf("Choose: ");

        if (scanf("%d", &choice) != 1) break;
        while (getchar() != '\n');

        if (choice == 1) {
            run_stopwatch();
        } else if (choice == 2) {
            run_timer();
        } else if (choice == 3) {
            printf("Exit\n");
            break;
        } else {
            printf("Wrong\n");
        }
    }

    return 0;
}