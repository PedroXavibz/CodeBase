#include "./base/base.h"
#include "./base/arena.h"
#include <stdio.h>

void base_test() {
  printf("COMPILER\n");
  printf("gcc = %d\n", COMPILER_GCC);
  printf("clang = %d\n", COMPILER_CLANG);
  printf("cl = %d\n", COMPILER_CL);
  printf("mingw = %d\n", COMPILER_MINGW);

  printf("\nOS\n");
  printf("linux = %d\n", OS_LINUX);
  printf("windows = %d\n", OS_WINDOWS);
  printf("mac = %d\n", OS_MAC);

  printf("\nARCH\n");
  printf("x64 = %d\n", ARCH_x64);
  printf("x86 = %d\n", ARCH_x86);
  printf("arm = %d\n", ARCH_ARM);
  printf("arm64 = %d\n", ARCH_ARM64);
  printf("armx86 = %d\n", ARCH_x86);
}

int main(int argc, char *argv[]) {
  Arena arena = arena_init(1024);
}
