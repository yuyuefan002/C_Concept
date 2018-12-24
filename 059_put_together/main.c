#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "counts.h"
#include "kv.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  FILE * f = fopen(filename, "r");
  if (f == NULL) {
    perror("Usage: fail to open the file\n");
    exit(EXIT_FAILURE);
  }
  counts_t * c = createCounts();
  char * curr = NULL;
  size_t sz = 0;
  while (getline(&curr, &sz, f) >= 0) {
    int l = strlen(curr);
    curr[l - 1] = '\0';
    addCount(c, lookupValue(kvPairs, curr));
  }
  free(curr);
  if (fclose(f) != 0) {
    perror("Usage: fail to close the file\n");
  }
  return c;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  if (argv[1] == NULL) {
    fprintf(stderr, "Usage: no such file");
    return EXIT_FAILURE;
  }
  kvarray_t * kv = readKVs(argv[1]);
  //count from 2 to argc (call the number you count i)
  for (int i = 2; i < argc; i++) {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c = countFile(argv[i], kv);
    //compute the output file name from argv[i] (call this outName)
    char * outName = computeOutputFileName(argv[i]);
    //open the file named by outName (call that f)
    FILE * f = fopen(outName, "w");
    if (f == NULL) {
      perror("Usage: can't open the file");
      return EXIT_FAILURE;
    }
    //print the counts from c into the FILE f
    printCounts(c, f);
    //close f
    if (fclose(f) != 0) {
      perror("Usage: fail to close the file");
    }
    //free the memory for outName and c
    freeCounts(c);
    free(outName);
  }
  //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
