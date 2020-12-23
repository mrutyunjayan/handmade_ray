/* date = December 23rd 2020 10:11 am */

#ifndef RAY_MATH_H
#define RAY_MATH_H

//~ STRUCTURES

typedef struct V2 {
	f32 x;
	f32 y;
} V2;

typedef struct V3 {
	f32 x;
	f32 y;
    f32 z;
} V3;

typedef V3 Colour;

//~ SCALAR FUNCTIONS
inline f32
squareRoot(f32 number) {
    
    f32 result = __builtin_sqrtf(number);
    return result;
}

//~ VECTOR FUNCTIONS
inline internal V2 
v2_unitVector(void) {
	
	V2 result = {0};
	
	result.x = 1.0f;
	result.y = 1.0f;
	
	return result;
}

inline internal V2 
v2_add(V2 a, V2 b) {
	
	V2 result = {0};
	
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	
	return result;
}

inline internal V2 
v2_addValue(V2 v, f32 value) {
	
	V2 result = {0};
	
	result.x = v.x + value;
	result.y = v.y + value;
	
	return result;
}

inline internal V2 
v2_subtract(V2 a, V2 b) {
	
	V2 result = {0};
	
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	
	return result;
}

inline internal V2 
v2_subtractValue(V2 v, f32 value) {
	
	V2 result = {0};
	
	result.x = v.x - value;
	result.y = v.y - value;
	
	return result;
}

inline internal V2 
v2_scaleUp(V2 a, f32 scale) {
	
	V2 result = {0};
	
	result.x = scale * a.x;
	result.y = scale * a.y;
	
	return result;
}

inline internal V2 
v2_scaleDown(V2 a, f32 scale) {
	
	V2 result = {0};
	
	result.x = a.x / scale;
	result.y = a.y / scale;
	
	return result;
}

inline internal V3 
v3_unitVector(void) {
	
	V3 result = {0};
	
	result.x = 1.0f;
	result.y = 1.0f;
	result.z = 1.0f;
	
	return result;
}

inline internal V3 
v3_add(V3 a, V3 b) {
	
	V3 result = {0};
	
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	
	return result;
}

inline internal V3 
v3_addValue(V3 v, f32 value) {
	
	V3 result = {0};
	
	result.x = v.x + value;
	result.y = v.y + value;
	result.z = v.z + value;
	
	return result;
}

inline internal V3 
v3_subtract(V3 a, V3 b) {
	
	V3 result = {0};
	
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	
	return result;
}

inline internal V3 
v3_subtractValue(V3 v, f32 value) {
	
	V3 result = {0};
	
	result.x = v.x - value;
	result.y = v.y - value;
	result.z = v.z - value;
	
	return result;
}

inline internal V3 
v3_scaleUp(V3 a, f32 scale) {
	
	V3 result = {0};
	
	result.x = scale * a.x;
	result.y = scale * a.y;
	result.z = scale * a.z;
	
	return result;
}

inline internal V3 
v3_scaleDown(V3 a, f32 scale) {
	
	V3 result = {0};
	
	result.x = a.x / scale;
	result.y = a.y / scale;
	result.z = a.z / scale;
	
	return result;
}

#endif //RAY_MATH_H
