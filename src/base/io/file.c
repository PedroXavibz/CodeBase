#include "file.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

i8 create_file(const char *file_location) {
  FILE *file = fopen(file_location, "w");
  if (file == NULL) {
    fprintf(stderr, "FileError: error on create file\n");
    return 0;
  }
  return 1;
}

i8 delete_file(const char *file_location) {
  if (remove(file_location) != 0) {
    fprintf(stderr, "FileError: unable to delete the file \"%s\"\n",
            file_location);
    return 0;
  }
  return 1;
}

FILE *open_file(const char *file_location, FileMode mode) {
  char *file_mode;

  switch (mode) {
  case r:
    file_mode = "r";
    break;

  case w:
    file_mode = "w";
    break;

  case a:
    file_mode = "a";
    break;

  default:
    fprintf(stderr, "FileError: unknown access mode\n");
    exit(EXIT_FAILURE);
  }

  FILE *file = fopen(file_location, file_mode);
  if (file == NULL) {
    fprintf(stderr, "FileError: file %s not found\n", file_location);
    exit(EXIT_FAILURE);
  };

  return file;
}

char *read_file(FILE *file) {
  if (file == NULL) {
    fprintf(stderr, "FileError: invalid params\n");
    exit(EXIT_FAILURE);
  }

  // Get file length
  fseek(file, 0, SEEK_END);
  long file_lenght = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Get content length
  char *content = malloc(sizeof(char) * (file_lenght + 1));
  if (content == NULL) {
    close_file(file), content = NULL, file = NULL;
    fprintf(stderr, "MallocError: %s.\n", strerror(errno));
    exit(EXIT_FAILURE);
  } 

  content[file_lenght] = '\0';
  fread(content, sizeof(char), file_lenght, file);
  close_file(file);
  return content;
}

i8 write_file(FILE *file, const char *content) {
  if (file == NULL) {
    fprintf(stderr, "FileError: invalid params\n");
    exit(EXIT_FAILURE);
  }

  if (fprintf(file, "%s", content) < 0) {
    close_file(file), file = NULL;
    fprintf(stderr, "FileError: error on write file\n");
    exit(EXIT_FAILURE);
  };
  return close_file(file);
}

i8 append_file(FILE *file, const char *to_append) {
  if (file == NULL) {
    fprintf(stderr, "FileError: invalid params\n");
    exit(EXIT_FAILURE);
  }

  if (fprintf(file, "%s", to_append) < 0) {
    close_file(file), file = NULL;
    fprintf(stderr, "FileError: error on append file\n");
    exit(EXIT_FAILURE);
  };
  return close_file(file);
;
}

i8 close_file(FILE *file) {
  if (file == NULL)
    return 0;
  fclose(file);
  return 1;
}
