#include "utils.h"
#include "win32_main.h"

#include "ray.h"

#include <stdio.h>
#include <windows.h>

internal u32
pixel_getTotalSize(ImageU32 image) {
    
    u32 result = image.width * image.height * sizeof(u32);
    return result;
}

internal ImageU32
image_allocate(u32 width, u32 height) {
    
    u32* pixels = (u32*)VirtualAlloc(NULL,
                                     width * height * sizeof(u32),
                                     MEM_COMMIT | MEM_RESERVE,
                                     PAGE_READWRITE);
    
    ImageU32 result = {
        .width = width,
        .height = height,
        .pixels = pixels
    };
    return result;
}

internal void
image_write(ImageU32 image, char* fileName) {
    
    u32 outputPixelSize = pixel_getTotalSize(image);
    
    BitmapHeader bitmapHeader = {
        .fileType = 0x4D42, // 'BM' in ASCII
        .fileSize = sizeof(bitmapHeader) + outputPixelSize,
        .bitmapOffset = sizeof(bitmapHeader),
        .size =  sizeof(bitmapHeader) - 14,
        .width = (s32)image.width,
        .height = (s32)image.height,
        .planes = 1,
        .bitsPerPixel = 32,
        .sizeOfBitmap = outputPixelSize,
        .horizontalResolution = 11811,
        .veritcalResolution = 11811,
    };
    
#if 0    
    HANDLE inFileHandle = CreateFile("../data/paint.bmp",
                                     GENERIC_READ,
                                     FILE_SHARE_READ,
                                     NULL,
                                     OPEN_EXISTING,
                                     FILE_ATTRIBUTE_NORMAL,
                                     NULL);
    BitmapHeader inFileHeader = {0};
    DWORD bytesRead;
    ReadFile(inFileHandle,
             &inFileHeader,
             sizeof(inFileHeader),
             &bytesRead,
             NULL);
#endif
    
    char* outputFileRelativePath = "../data/";
    
    char outputFileFullName[255];
    
    catStrings(stringLength(outputFileRelativePath), outputFileRelativePath,
               stringLength(fileName), fileName,
               stringLength(outputFileFullName), outputFileFullName);
    
    
    HANDLE fileHandle = CreateFile(outputFileFullName,
                                   GENERIC_WRITE,
                                   0,
                                   0,
                                   CREATE_ALWAYS,
                                   FILE_ATTRIBUTE_NORMAL,
                                   NULL);
    
    if (fileHandle != INVALID_HANDLE_VALUE) {
        
        DWORD bytesWritten;
        WriteFile(fileHandle,
                  &bitmapHeader,
                  sizeof(bitmapHeader),
                  &bytesWritten,
                  NULL);
        WriteFile(fileHandle,
                  image.pixels,
                  outputPixelSize,
                  &bytesWritten,
                  NULL);
    } else { fprintf(stderr, "[ERROR]: Unable to write to output file %s\n", outputFileRelativePath); }
}

int 
main(int argCount, char** args) {
    
    u32 outputWidth = 1920;
    u32 outputHeight = 1080;
    ImageU32 image = image_allocate(outputWidth, outputHeight);
    
    u32* out = image.pixels;
    
    for (u32 y = 0; y < image.height; ++y) {
        for (u32 x = 0; x < image.width; ++x) {
            
            *out++ = (y < 32) ? ARGB(255, 0, 0, 255) : ARGB(255, 255, 0, 0);
        }
    }
    
    image_write(image, "test.bmp");
    
    Material materials[2]  = {0};
    materials[0].colour = (Colour){ 0, 0, 0 };
    materials[1].colour = (Colour){ 1, 0, 0 };
    Plane plane = {0};
    
    World world = {
        .materialCount = 2,
        .materials = materials,
        .planeCount = 1,
        .planes = &plane,
        .sphereCount = 0,
        .spheres = NULL
    };
    
    return 0;
}
