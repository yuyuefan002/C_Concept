#include "fileinfo.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <unistd.h>
//read fileinfo into stat
struct stat * readFileInfo(char * str) {
  struct stat * s = malloc(sizeof(*s));
  if (lstat(str, s) == -1) {  //make system call to read file info into *s
    perror("lstat");
    exit(EXIT_FAILURE);
  }
  return s;
}
//print basic file information
//for example
/*
  File: ‘README’
  Size: 2825		Blocks: 8          IO Block: 4096   regular file
Device: fc00h/64512d	Inode: 801829      Links: 1
*/
void printFileInfo(struct stat * s, char * str) {
  //judge whether the file is a symbolic link
  if (S_ISLNK(s->st_mode)) {
    //read the link path
    char linktarget[256];
    ssize_t len = readlink(str, linktarget, 256);
    linktarget[len] = '\0';
    printf("  File: %s -> %s\n", str, linktarget);
  }
  else {
    printf("  File: %s\n", str);
  }
  char * tmp;
  //read the file type
  switch (s->st_mode & S_IFMT) {
    case S_IFBLK:
      tmp = "block special file";
      break;
    case S_IFCHR:
      tmp = "character special file";
      break;
    case S_IFDIR:
      tmp = "directory";
      break;
    case S_IFIFO:
      tmp = "fifo";
      break;
    case S_IFLNK:
      tmp = "symbolic link";
      break;
    case S_IFREG:
      tmp = "regular file";
      break;
    case S_IFSOCK:
      tmp = "socket";
      break;
    default:
      tmp = "unknown?";
      break;
  }

  printf("  Size: %-10lu\tBlocks: %-10lu IO Block: %-6lu %s\n",
         s->st_size,
         s->st_blocks,
         s->st_blksize,
         tmp);
  //judge whether the file stated is a device
  if (S_ISCHR(s->st_mode) || S_ISBLK(s->st_mode)) {
    printf("Device: %lxh/%lud\tInode: %-10lu  Links: %-5lu Device type: %d,%d\n",
           s->st_dev,
           s->st_dev,
           s->st_ino,
           s->st_nlink,
           major(s->st_rdev),
           minor(s->st_rdev));
  }
  else {
    printf("Device: %lxh/%lud\tInode: %-10lu  Links: %lu\n",
           s->st_dev,
           s->st_dev,
           s->st_ino,
           s->st_nlink);
  }
}
