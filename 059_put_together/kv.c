#include "kv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

kvpair_t * split(char * cur) {
  kvpair_t * kvpair = NULL;
  char * p;
  p = strchr(cur, '\n');
  if (p != NULL) {
    *p = '\0';
  }
  p = strchr(cur, '=');
  if (p == NULL) {
    fprintf(stderr, "Usage: informal input");
    exit(EXIT_FAILURE);
  }
  int sz = strlen(cur);
  kvpair = malloc(sizeof(*kvpair));
  kvpair->value = malloc(sz - (p - cur) + 1);
  strcpy(kvpair->value, p + 1);
  *p = '\0';
  kvpair->key = malloc(p - cur + 1);
  strcpy(kvpair->key, cur);
  return kvpair;
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen(fname, "r");
  if (f == NULL) {
    return NULL;
  }
  kvarray_t * kvarray;
  kvarray = malloc(sizeof(*kvarray));
  kvarray->kvpair = NULL;
  size_t i = 0;
  char * cur = NULL;
  size_t sz;

  while (getline(&cur, &sz, f) >= 0) {
    kvarray->kvpair = realloc(kvarray->kvpair, (i + 1) * sizeof(kvpair_t *));
    kvarray->kvpair[i++] = split(cur);
  }
  free(cur);
  if (fclose(f) != 0) {
    return NULL;
  }
  kvarray->length = i;
  return kvarray;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    free(pairs->kvpair[i]->value);
    free(pairs->kvpair[i]->key);
    free(pairs->kvpair[i]);
  }
  free(pairs->kvpair);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    printf("key = '%s' value = '%s'\n", pairs->kvpair[i]->key, pairs->kvpair[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    if (strcmp(pairs->kvpair[i]->key, key) == 0) {
      return pairs->kvpair[i]->value;
    }
  }
  return NULL;
}
