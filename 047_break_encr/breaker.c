#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int max(int x, int y) {
  if (x > y)
    return x;
  return y;
}
int largefrequency(int * letterfrequency) {
  int largest = 0;
  for (int i = 0; i < 26; i++) {
    if (letterfrequency[i] > letterfrequency[largest])
      largest = i;
  }
  return largest;
}
int breaker(FILE * f) {
  int key = 0;
  int c;
  int letter;
  int letterfrequency[26] = {0};
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      letterfrequency[c]++;
    }
  }
  letter = largefrequency(letterfrequency);
  key = ((letter + 'a' + 26) - 'e') % 26;
  return key;
}
int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: encrypt key input FileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int key = breaker(f);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  printf("%d\n", key);
  return EXIT_SUCCESS;
}
