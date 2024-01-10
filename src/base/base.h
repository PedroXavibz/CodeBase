#ifndef BASE_H
#define BASE_H

#if defined(__clang__)
#define COMPILER_CLANG 1

#if defined(__amd64__)
# define ARCH_x64 1
#elif defined(__i386__)
# define ARCH_x86 1
#elif defined(_arm__)
# define ARCH_ARM 1
#elif defined(__aarch64__)
# define ARCH_ARM64 1
#else
# error missing ARCH detection
#endif

#if defined(_WIN32)
# define OS_WINDOWS 1
#elif defined(__gnu_linux__)
# define OS_LINUX 1
#elif defined(__APPLE__) && defined(__MACH__)
# define OS_MAC 1
#else
# error missing OS detection
#endif

#elif defined(__GNUC__)
#define COMPILER_GCC 1

#if defined(__amd64__)
# define ARCH_x64 1
#elif defined(__i386__)
# define ARCH_x86 1
#elif defined(_arm__)
# define ARCH_ARM 1
#elif defined(__aarch64__)
# define ARCH_ARM64 1
#else
# error missing ARCH detection
#endif

#if defined(_WIN32)
# define OS_WINDOWS 1
#elif defined(__gnu_linux__)
# define OS_LINUX 1
#elif defined(__APPLE__) && defined(__MACH__)
# define OS_MAC 1
#else
# error missing OS detection
#endif

#elif defined(__MINGW32__)
#define COMPILER_MINGW

#if defined(_WIN32)
# define OS_WINDOWS 1
#else 
# error missing OS detection
#endif

#if defined(__amd64__)
# define ARCH_x64 1
#elif defined(__i386__)
# define ARCH_x86 1
#elif defined(_arm__)
# define ARCH_ARM 1
#elif defined(__aarch64__)
# define ARCH_ARM64 1
#else
# error missing ARCH detection
#endif

#elif defined(_MSC_VER)
#define COMPILER_CL 1

#if defined(_WIN32)
# define OS_WINDOWS 1
#else 
# error missing OS detection
#endif

#if defined(__amd64__)
# define ARCH_x64 1
#elif defined(__i386__)
# define ARCH_x86 1
#elif defined(_arm__)
# define ARCH_ARM 1
#else
# error missing ARCH detection
#endif

#else
# error no context cracking for this compiler
#endif

#if !defined(COMPILER_CLANG)
# define COMPILER_CLANG 0
#endif
#if !defined(COMPILER_GCC)
# define COMPILER_GCC 0
#endif
#if !defined(COMPILER_MINGW)
# define COMPILER_MINGW 0
#endif
#if !defined(COMPILER_CL)
# define COMPILER_CL 0
#endif
#if !defined(ARCH_x64)
# define ARCH_x64 0
#endif
#if !defined(ARCH_x86)
# define ARCH_x86 0
#endif
#if !defined(ARCH_ARM)
# define ARCH_ARM 0
#endif
#if !defined(ARCH_ARM64)
# define ARCH_ARM64 0
#endif
#if !defined(OS_WINDOWS)
# define OS_WINDOWS 0
#endif
#if !defined(OS_LINUX)
# define OS_LINUX 0
#endif
#if !defined(OS_MAC)
# define OS_MAC 0
#endif

#endif
