#include <stdio.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

int main() {
    struct Job jobs[] = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    int n = 5;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (jobs[i].profit < jobs[j].profit) {
                struct Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    int slot[3] = {0};
    char result[3];

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                result[j] = jobs[i].id;
                break;
            }
        }
    }

    printf("Selected Jobs: ");
    for (int i = 0; i < 3; i++) {
        if (slot[i])
            printf("%c ", result[i]);
    }

    return 0;
}