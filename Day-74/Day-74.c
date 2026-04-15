/*
Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate 
who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
*/
#include <stdio.h>
#include <string.h>

int main() {
    char votes[][20] = {"ram", "shyam", "ram", "mohan", "shyam", "ram"};
    int n = 6;

    char names[100][20];
    int count[100] = {0};
    int unique = 0;

    // Count votes
    for(int i = 0; i < n; i++) {
        int found = -1;

        for(int j = 0; j < unique; j++) {
            if(strcmp(names[j], votes[i]) == 0) {
                found = j;
                break;
            }
        }

        if(found == -1) {
            strcpy(names[unique], votes[i]);
            count[unique]++;
            unique++;
        } else {
            count[found]++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[20];

    for(int i = 0; i < unique; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if(count[i] == maxVotes) {
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("Winner: %s\n", winner);

    return 0;
}
