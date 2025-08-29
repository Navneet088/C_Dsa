#include <stdio.h>
#include <stdlib.h>

#define TOTAL_COWS 25
#define COWS_PER_GROUP 5
#define GROUP_SUM 65
#define TOTAL_GROUPS 5

int allGroups[1000][COWS_PER_GROUP];
int totalValidGroups = 0;
int usedCows[TOTAL_COWS + 1] = {0}; // cows are 1-indexed
int currentGroup[5][COWS_PER_GROUP];

void findGroups(int start, int depth, int sum, int group[]) {
    if (depth == COWS_PER_GROUP) {
        if (sum == GROUP_SUM) {
            for (int i = 0; i < COWS_PER_GROUP; i++)
                allGroups[totalValidGroups][i] = group[i];
            totalValidGroups++;
        }
        return;
    }

    for (int i = start; i <= TOTAL_COWS; i++) {
        if (!usedCows[i] && sum + i <= GROUP_SUM) {
            group[depth] = i;
            usedCows[i] = 1;
            findGroups(i + 1, depth + 1, sum + i, group);
            usedCows[i] = 0;
        }
    }
}

int isGroupUsed(int *group, int used[26]) {
    for (int i = 0; i < COWS_PER_GROUP; i++) {
        if (used[group[i]])
            return 1;
    }
    return 0;
}

void markGroup(int *group, int used[26], int value) {
    for (int i = 0; i < COWS_PER_GROUP; i++)
        used[group[i]] = value;
}

void search(int index, int depth, int used[26]) {
    if (depth == TOTAL_GROUPS) {
        printf("Valid Grouping:\n");
        for (int i = 0; i < TOTAL_GROUPS; i++) {
            printf("Group %d: ", i + 1);
            for (int j = 0; j < COWS_PER_GROUP; j++)
                printf("%2d ", currentGroup[i][j]);
            printf("\n");
        }
        printf("---------------------\n");
        return;
    }

    for (int i = index; i < totalValidGroups; i++) {
        if (!isGroupUsed(allGroups[i], used)) {
            markGroup(allGroups[i], used, 1);
            for (int j = 0; j < COWS_PER_GROUP; j++)
                currentGroup[depth][j] = allGroups[i][j];
            search(i + 1, depth + 1, used);
            markGroup(allGroups[i], used, 0);
        }
    }
}

int main() {
    int tempGroup[5];
    findGroups(1, 0, 0, tempGroup); // Step 1: find all valid 5-cow groups summing to 65

    int used[26] = {0};
    search(0, 0, used); // Step 2: search for 5 disjoint groups
    return 0;
}
