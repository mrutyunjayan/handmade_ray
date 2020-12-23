/* date = December 22nd 2020 7:08 pm */

#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>
// TODO(Jai): implement math ourselves
#include <math.h>

#define localPersist static
#define global static
#define internal static
#define false 0
#define true 1
#define readOnly const

#define PI 3.14159265359f

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef s32 b32;
typedef unsigned int uint;

typedef float f32;
typedef double f64;

#define U32_MAX        0xFFFFFFFF
#define U64_MAX        0xFFFFFFFFFFFFFFFF

// NOTE(Jai): Recursive type definition only for 
// editor syntax highlighting
typedef size_t size_t;
typedef size_t memoryIndex;

#define KB(value) (value * 1024LL)
#define MB(value) (KB(value) * 1024LL)
#define GB(value) (MB(value) * 1024LL)
#define TB(value) (GB(value) * 1024LL)

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

#if HR_SLOW
#define ASSERT(expression) \
if (!(expression)) { \
*(volatile int*)0 = 0;\
}
#else
#define ASSERT(expression)
#endif

#define STRING(name) #name

#define IS_POWER_OF_2(x) ((x & (x - 1)) == 0)

#define CLAMP(value, min, max) (value <= min) ? min : (value >= max) ? max : value;


//*************************************************************************
// ------------------STRING STUFF------------------------------------------
//*************************************************************************

inline internal void
catStrings(s64 sourceACount, char* sourceA,
           s64 sourceBCount, char* sourceB,
           s64 destCount, char* dest) {
    // TODO(Jai): dest bounds checking
    for (int i = 0; i < sourceACount; ++i) {
        *dest++ = *sourceA++;
    }
    
    for (int i = 0; i < sourceBCount; ++i) {
        *dest++ = *sourceB++;
    }
    
    *dest++ = 0;
}

inline internal int
stringLength(char* string) {
    int count = 0;
    while (*string++) {
        ++count;
    }
    return count;
}

//*************************************************************************
// ------------------NUMBER STUFF------------------------------------------
//*************************************************************************

inline internal u32 
safeTruncate_s64(s64 value) {
    // TODO(Jai): Defines for maximum values (u32_t)
    ASSERT(value <= 0xFFFFFFFF);
    u32 result = (u32)value;
    
    return result;
}

// NOTE(Jai): Round up the float value to int
inline internal s32
round_floatToI32(f32 number) {
    return ((s32)(number + 0.5f));
}

inline internal s32
trunate_floatToI32(f32 number) {
    return (s32)number;
}

inline internal s32
floor_floatToI32(f32 number) {
    return (s32)(floorf(number));
}

inline internal f32
handmade_sin(f32 angle) {
    return sinf(angle);
} 

inline internal f32
handmade_cos(f32 angle) {
    return cosf(angle);
}

inline internal f32
handmade_tan(f32 angle) {
    return tanf(angle);
}

inline internal f32
handmade_asin(f32 value) {
    return asinf(value);
}

inline internal f32
handmade_acos(f32 value) {
    return acosf(value);
}

inline internal f32
handmade_atan(f32 value) {
    return atanf(value);
}

//*************************************************************************
// ------------------ARENA STUFF------------------------------------------
//*************************************************************************

typedef struct MemoryArena {
	memoryIndex size;
	u8* base;
	memoryIndex used;
} MemoryArena;

#define PUSH_STRUCT(arena, type) (type*)pushSize_(arena, sizeof(type)) 
#define PUSH_ARRAY(arena, count, type) (type*)pushSize_(arena, (count * sizeof(type)))

void*
pushSize_(MemoryArena* arena,
		  memoryIndex size) {
	
	ASSERT((arena->used + size) <= arena->size);
    void* result = arena->base + arena->used;
    arena->used += size;
    
    return result;
}

#endif //UTILS_H
