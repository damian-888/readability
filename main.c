#include <stdio.h>    // For standard input/output functions
#include <stdlib.h>   // For standard library functions, such as malloc
#include <string.h>   // For string manipulation functions
#include <ctype.h>    // For char comparision & letter functions

int count_letters(char *input);
int count_words(char *input);
int count_sentences(char *input);

int main() {
    char *input;
    size_t buffer_size = 256; // Initial buffer size

    // Allocate memory for the input string
    input = (char *)malloc(buffer_size * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Ask the user to input text
    printf("Text: ");

    // Use getline to read the entire line of input
    getline(&input, &buffer_size, stdin); 

    // Initialize letter count
    int letters = count_letters(input);
    int words = count_words(input);
    int sentences = count_sentences(input);

    // Calc formula
    float letter_avg = ((float) letters / words) * 100;
    float sentence_avg = ((float) sentences / words) * 100; 
    int index = (int)(0.0588 * letter_avg - 0.296 * sentence_avg - 15.8 + 0.5);

    //Print the level
    int grade = 1;
    if(index < 1) {
        printf("Below Grade 1");
    } else if(index > 16) {
        printf("Grade 16+");
    } else {
        printf("Grade %d", index);
    }

    // Free the allocated memory
    free(input);
    return 0;
}

int count_letters(char *input) { 
    int letters = 0;

    // Iterate over each character in the input string
    for (int i = 0, len = strlen(input); i < len; i++) {
        if (input[i] == ' ') {
            // Skip spaces
            continue;
        } else if (isalpha(input[i]) || input[i] == '-') {
            // Count letters and hyphens
            letters++;
        }
    }
    return letters; 
}

int count_words(char *input) {
    int words = 0;
    int spaces = 0;

    // Iterate over and find space, then spaces +1
    for (int i = 0, len = strlen(input); i < len; i++) {
        if (input[i] == ' ') {
            spaces++;
        }
        words = spaces +1; 
    }
    return words;
}

int count_sentences(char *input) {
    int sentences = 0;

    for(int i = 0, len = strlen(input); i < len; i++) {
        if(input[i] == '.' || input[i] == '?' || input[i] == '!') {
            sentences++;
        }
    }
    return sentences;
}