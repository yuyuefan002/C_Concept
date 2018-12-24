#include "counts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * counts = malloc(sizeof(*counts));
  counts->array = NULL;
  counts->length = 0;
  counts->timesUnknown = 0;
  return counts;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if (name == NULL) {
    c->timesUnknown++;
    return;
  }
  for (int i = 0; i < c->length; i++) {
    if (strcmp(c->array[i]->values, name) == 0) {
      c->array[i]->times++;
      return;
    }
  }
  c->array = realloc(c->array, (c->length + 1) * sizeof(*c->array));
  c->array[c->length] = malloc(sizeof(one_count_t));
  c->array[c->length]->values = malloc(strlen(name) + 1);
  c->array[c->length]->times = 1;
  strcpy(c->array[c->length++]->values, name);
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for (int i = 0; i < c->length; i++) {
    fprintf(outFile, "%s: %d\n", c->array[i]->values, c->array[i]->times);
  }
  if (c->timesUnknown > 0) {
    fprintf(outFile, "<unknown> : %d\n", c->timesUnknown);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (int i = 0; i < c->length; i++) {
    free(c->array[i]->values);
    free(c->array[i]);
  }
  free(c->array);
  free(c);
}
