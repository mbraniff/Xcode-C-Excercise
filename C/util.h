#ifndef UTIL_H
#define UTIL_H

#define REINTERPRET(new_name, cast_me, type) \
type new_name = (type)(cast_me)

#ifndef NULL
#define NULL (void*)0
#endif

#define IGNORE(arg) \
    (void*)arg

#define NaN (void)0;

#endif