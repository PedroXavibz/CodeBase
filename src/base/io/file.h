#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include "../types.h"

typedef enum {
  r,
  w,
  a,
} FileMode;

i8 create_file(const char *file_location);

i8 delete_file(const char *file_location);

FILE *open_file(const char *file_location, FileMode mode);

char *read_file(FILE *file);

i8 write_file(FILE *file, const char *content);

i8 append_file(FILE *file, const char *to_append);

i8 close_file(FILE *file);

#endif
