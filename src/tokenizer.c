#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

// Returns true if character is a space or tab, false otherwise
int space_char(char c)
{
  return (c == ' ' || c == '\t') && c != 0;
}

// Returns true if character is not a space, tab or null, false otherwise
int non_space_char(char c)
{
  return c != ' ' && c != '\t' && c != 0;
}

// Returns a pointer to the start of a word in a string
char *word_start(char *word)
{
  if (*word == '\0')
    return 0;

// Advances the pointer to the first non-space character
  while (space_char(*word)) {
    word++;
  }
  return word;
}

// Returns a pointer to the end of a word in a string
char *word_terminator(char *word)
{
// Advances the pointer to the end of the word
  while (non_space_char(*word)) {
    word++;
  }
  return word;
}

// Returns the number of words in a string
int count_words(char *str)
{
  int count = 0;
  while (*str != '\0') {
    str = word_start(str);
    str = word_terminator(str);
    count++;
  }
  return count;
}

// Returns a pointer to a copy of a string of given length
char *copy_str(char *inStr, short len)
{
  char *copyStr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    copyStr[i] = inStr[i];
  }
  copyStr[i] = '\0';
  return copyStr;
}

// Returns an array of pointers to tokens
char **tokenize(char *str)
{
  int word_size = count_words(str);
  char **words = malloc((word_size + 1) * sizeof(char *));
  int i = 0;

// Iterates through each word in the string and creates a copy of it
  for (i = 0; i < word_size; i++) {
    char* start = word_start(str);
    str = word_terminator(start);
    words[i] = copy_str(start, str - start);
  }
  words[i] = NULL;
  return words;
}

// Prints the tokens in an array
void print_tokens(char **tokens)
{
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    printf("\nTokens[%d] : %s\n", i, tokens[i]);
  }
}

// Frees the memory allocated for an array of tokens
void free_tokens(char **tokens)
{
  char **temp = tokens;
  while (*temp != NULL) {
    free(*temp);
    temp++;
  }
  free(tokens);
}