#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void read_matrix(FILE * f, char (*matrix)[10]) {
  int c;
  int i = 0, j = 0;
  while ((c = fgetc(f)) != EOF) {
    if (j == 10 && c == '\n') {
      j = 0;
      i++;
      continue;
    }
    else if (c == '\n') {
      fprintf(stderr, "much or less column\n");
      exit(EXIT_FAILURE);
    }
    if (i < 10 && j < 10)
      matrix[i][j++] = c - 97 + 'a';
  }
  if (i != 10) {
    fprintf(stderr, "much or less row\n");
    exit(EXIT_FAILURE);
  }
}
void swap(char * a, char * b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}
void printf_matrix(char (*matrix)[10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
}
void rotate_dia(char (*matrix)[10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10 - i; j++) {
      if (10 - 1 - i == j)
        continue;
      swap(&matrix[i][j], &matrix[10 - 1 - j][10 - 1 - i]);
    }
  }
}
void rotate_upbottom(char (*matrix)[10]) {
  int up = 0, bottom = 9;
  while (up < bottom) {
    for (int j = 0; j < 10; j++) {
      swap(&matrix[up][j], &matrix[bottom][j]);
    }
    up++;
    bottom--;
  }
}
void rotate_matrix(char (*matrix)[10]) {
  rotate_dia(matrix);
  rotate_upbottom(matrix);
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: you should input one and only onefile\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file\n");
    return EXIT_FAILURE;
  }
  char matrix[10][10];
  /*= {"0123456789",
                         "1234567890",
                         "2345678901",
                         "3456789012",
                         "4567890123",
                         "5678901234",
                         "6789012345",
                         "7890123456",
                         "8901234567",
                         "9012345678"};
  */
  read_matrix(f, matrix);
  rotate_matrix(matrix);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!\n");
  }
  printf_matrix(matrix);
  return EXIT_SUCCESS;
}
