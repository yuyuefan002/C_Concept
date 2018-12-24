#include "accessInfo.h"

#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
//return the char indicates 'b','c', 'd', 'p', 'l', '-', or 's' depending
//          on the file type (corresponding to S_IFBLK, S_IFCHR, S_IFDIR, S_IFIFO,
//          S_IFLNK, S_IFREG, S_IFSOCK in that order)
char parseType(struct stat * s) {
  switch (s->st_mode & S_IFMT) {
    case S_IFBLK:
      return 'b';
      break;
    case S_IFCHR:
      return 'c';
      break;
    case S_IFDIR:
      return 'd';
      break;
    case S_IFIFO:
      return 'p';
      break;
    case S_IFLNK:
      return 'l';
      break;
    case S_IFREG:
      return '-';
      break;
    case S_IFSOCK:
      return 's';
      break;
    default:
      return 'u';
      break;
  }
  //fprintf(stderr, "unknown file type\n");
  //exit(EXIT_FAILURE);
  //return 'u';
}
//return the char indicating readability depends on user(USR, GRP,OTHER)
char parseReadable(struct stat * s, user_t user) {
  switch (user) {
    case USR:
      if (s->st_mode & S_IRUSR)
        return 'r';
      break;
    case GRP:
      if (s->st_mode & S_IRGRP)
        return 'r';
      break;
    case OTHER:
      if (s->st_mode & S_IROTH)
        return 'r';
      break;
  }
  return '-';
}
//return the char indicating writability depends on user(USR, GRP,OTHER)
char parseWritable(struct stat * s, user_t user) {
  switch (user) {
    case USR:
      if (s->st_mode & S_IWUSR)
        return 'w';
      break;
    case GRP:
      if (s->st_mode & S_IWGRP)
        return 'w';
      break;
    case OTHER:
      if (s->st_mode & S_IWOTH)
        return 'w';
      break;
  }
  return '-';
}
//return the char indicating executability depends on user(USR, GRP,OTHER)
char parseExecutable(struct stat * s, user_t user) {
  switch (user) {
    case USR:
      if (s->st_mode & S_IXUSR)
        return 'x';
      break;
    case GRP:
      if (s->st_mode & S_IXGRP)
        return 'x';
      break;
    case OTHER:
      if (s->st_mode & S_IXOTH)
        return 'x';
      break;
  }
  return '-';
}
//print the file access info
void printAccess(struct stat * s) {
  //description of file access info,totally 10 char plus 1 for '\0'
  char * d = malloc((10 + 1) * sizeof(*d));
  d[0] = parseType(s);
  d[1] = parseReadable(s, USR);
  d[2] = parseWritable(s, USR);
  d[3] = parseExecutable(s, USR);
  d[4] = parseReadable(s, GRP);
  d[5] = parseWritable(s, GRP);
  d[6] = parseExecutable(s, GRP);
  d[7] = parseReadable(s, OTHER);
  d[8] = parseWritable(s, OTHER);
  d[9] = parseExecutable(s, OTHER);
  d[10] = '\0';
  struct passwd * uid = getpwuid(s->st_uid);
  struct group * gid = getgrgid(s->st_gid);
  printf("Access: (%04o/%s)  Uid: (%5d/%8s)   Gid: (%5d/%8s)\n",
         (unsigned int)s->st_mode & ~S_IFMT,
         d,
         s->st_uid,
         uid->pw_name,
         s->st_gid,
         gid->gr_name);

  free(d);
}
