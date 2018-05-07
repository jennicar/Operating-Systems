/*
Jennica Ramones
May 2018
Operating Systems final project

Simple file system implementation
This file system example reads files from a directory and prints out its contents
 */

#define FUSE_USE_VERSION 31

#include <fuse.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// gets the attributes of the file, returns 0 on success
static int do_getattr(const char *path, struct stat *st){
  printf("calling getattr()\n");
  // gets the user id (uid) and group id (gid) of the user who mounted the file system
  st->st_uid = getuid();
  st->st_gid = getgid();

  // mode specifies its type (file, directory, etc.)
  // and the permission bits of the file
  // nlink specifies the number of hard links
  // size specifies the size of the file in bytes
  if (strcmp(path, "/" == 0)){ // root directory
      st->st_mode = S_IFDIR | 0755;
      st->st_nlink = 2; // two hard links for /. and /..
  }
  else {
    st->st_mode = S_IFREG | 0644;
    st->st_nlink = 1;
    st->st_size = 1024;
  }

    return 0;
}

  // reads the directory
  static int do_readdir(const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi){
    printf("reading files\n");
    filler(buffer, ".", NULL, 0);
    filler(buffer, "..", NULL, 0);
    
    if (strcmp(path, "/") == 0){
      filler(buffer, "file2", NULL, 0);
      filler(buffer, "file100", NULL, 0);
    }
    return 0;
  }

  static int do_read(const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi){
    char file2Contents[] = "file2's contents";
    char file100Contents[] = "file100's contents";
    char *selectedContents = NULL;

    if (strcmp(path, "/file2") == 0) selectedContents = file2Contents;
    else if (strcmp(path, "/file100") == 0) selectedContents = file100Contents;
    else return -1;

    // copies the contents of the files and returns the number of bytes
    memcpy(buffer, selectedContents + offset, size);
    return strlen(selectedContents) - offset;
  }

  static struct fuse_operations operations = {
  .getattr = do_getattr,
  .readdir = do_readdir,
  .read = do_read,
};

int main(int argc, char *argv[]){
  return fuse_main(argc, argv, &operations, NULL);
}
