/* date = December 23rd 2020 9:16 am */

#ifndef RAY_H
#define RAY_H

#include "ray_math.h"

#pragma pack(push, 1)
typedef struct BitmapHeader {
    u16 fileType;
    u32 fileSize;
    u16 reserved1;
    u16 reserved2;
    u32 bitmapOffset;
    u32 size;
    s32 width;
    s32 height;
    u16 planes;
    u16 bitsPerPixel;
    u32 compression;
    u32 sizeOfBitmap;
    s32 horizontalResolution;
    s32 veritcalResolution;
    u32 coloursUsed;
    u32 coloursImportant;
} BitmapHeader;
#pragma pack(pop)

typedef struct ImageU32 {
    u32 width;
    u32 height;
    u32* pixels;
} ImageU32;

typedef struct Material {
    Colour colour;
} Material;

typedef struct Sphere {
    u32 materialIndex;
    V3 normal;
    f32 distance;
} Sphere;


typedef struct Plane {
    V3 point;
    f32 radius;
} Plane;


typedef struct World {
    u32 materialCount;
    Material* materials;
    
    u32 planeCount;
    Plane* planes;
    
    u32 sphereCount;
    Sphere* spheres;
} World;

#endif //RAY_H
