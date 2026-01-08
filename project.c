#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to scramble a word by shuffling its letters
void scrambleWord(char *word, char *scrambled) {
    int len = strlen(word);
    strcpy(scrambled, word);  // Copy original to scrambled
    
    // Fisher-Yates shuffle
    for (int i = len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = scrambled[i];
        scrambled[i] = scrambled[j];
        scrambled[j] = temp;
    }
}

int main() {
    srand(time(NULL));  // Seed random number generator
    
    // List of words (expand as needed)
    const char *words[] = {
        "apple", "banana", "cherry", "date", "mango",
        "fig", "grape", "guava", "kiwi", "lemon"
    };
    int numWords = sizeof(words) / sizeof(words[0]);
    
    int score = 0;
    int rounds = 5;  // Number of rounds
    
    printf("Welcome to the Word Scrambler Game!\n");
    printf("Unscramble the word and type your guess.\n\n");
    
    for (int round = 1; round <= rounds; round++) {
        // Select a random word
        int index = rand() % numWords;
        const char *original = words[index];
        
        // Scramble the word
        char scrambled[50];
        scrambleWord(original, scrambled);
        
        printf("Round %d: Scrambled word: %s\n", round, scrambled);
        printf("Your guess: ");
        
        char guess[50];
        scanf("%s", guess);
        
        // Check if guess is correct (case-insensitive)
        if (strcasecmp(guess, original) == 0) {
            printf("Correct! +10 points\n\n");
            score += 10;
        } else {
            printf("Wrong! The word was: %s\n\n", original);
        }
    }
    
    printf("Game over! Your final score: %d/%d\n", score, rounds * 10);
    return 0;
}