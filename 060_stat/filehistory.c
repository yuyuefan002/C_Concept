#include "filehistory.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
//This function is for Step 4

char * time2str(const time_t * when, long ns) {
  char * ans = malloc(128 * sizeof(*ans));
  char temp1[64];
  char temp2[32];
  const struct tm * t = localtime(when);
  strftime(temp1, 512, "%Y-%m-%d %H:%M:%S", t);
  strftime(temp2, 32, "%z", t);
  snprintf(ans, 128, "%s.%09ld %s", temp1, ns, temp2);
  return ans;
}
//print file history, the date of file accessed,modified,changed and its birth
void printHistory(struct stat * s) {
  char * atime = time2str(&s->st_atime, s->st_atim.tv_nsec);
  char * mtime = time2str(&s->st_mtime, s->st_mtim.tv_nsec);
  char * ctime = time2str(&s->st_ctime, s->st_ctim.tv_nsec);
  printf("Access: %s\n", atime);
  printf("Modify: %s\n", mtime);
  printf("Change: %s\n", ctime);
  printf(" Birth: -\n");
  free(atime);
  free(mtime);
  free(ctime);
}
