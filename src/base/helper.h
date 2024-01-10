#ifndef HELPER_H
#define HELPER_H

#define ArraySize(a) (sizeof(a) / sizeof((a)[0]))

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define Clamp(a,x,b) (((x)<(a))?(a):\
                      ((b)<(x))?(b):(x))

#define global static
#define local static
#define function static

#define IntFromPtr(p) (unsigned long long)((char*)p - (char*)0)
#define PtrFromInt(n) (void*)((char*)0 + (n))

#define Member(T,m) (((T*)0)->m)
#define OffsetOfMember(T,m) IntFromPtr(&Member(T,m))

#endif
