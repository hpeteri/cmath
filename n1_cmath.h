#ifndef N1_CMATH_H
#define N1_CMATH_H

#include <math.h>

//----------------------------------------
// common
//----------------------------------------

#define min(a, b) (a > b ? a : b)
#define max(a, b) (a > b ? b : a)
#define abs(a)    (a > 0 ? a : -a)
#define sign(a)   (a >= 0 ? 1 : -1)

float clampf(float a, float min, float max);
float lerpf(float from, float to, float t);

//----------------------------------------
// vec 2
//----------------------------------------

typedef struct vec2{
  union{
    struct{
      float x;
      float y;
    };
    float a[2];
  };
} vec2;

vec2  vec2_make(float x, float y);
vec2  vec2_make1(float xy);
vec2  vec2_zero();
vec2  vec2_negate(vec2 u);
vec2  vec2_abs(vec2 u);
vec2  vec2_sign(vec2 u);
vec2  vec2_clampv(vec2 u, vec2 min, vec2 max);
vec2  vec2_clampf(vec2 u, float min, float max);
vec2  vec2_lerp(vec2 from, vec2 to, float t);
vec2  vec2_mulv(vec2 u, vec2 v);
vec2  vec2_divv(vec2 u, vec2 v);
vec2  vec2_addv(vec2 u, vec2 v);
vec2  vec2_subv(vec2 u, vec2 v);
vec2  vec2_minv(vec2 u, vec2 v);
vec2  vec2_maxv(vec2 u, vec2 v);
float vec2_minf(vec2 u);
float vec2_maxf(vec2 u);
float vec2_length(vec2 u);
vec2  vec2_normalize(vec2 u);
vec2  vec2_normal(vec2 u);
float vec2_dot(vec2 u, vec2 v);
float vec2_cross(vec2 u, vec2 v);
int   vec2_equals(vec2 u, vec2 v);
int   vec2_equals_epsilon(vec2 u, vec2 v, float e);

//----------------------------------------
// vec 3
//----------------------------------------

typedef struct vec3{
  union{
    struct{
      float x;
      float y;
      float z;
    };
    float a[3];
  };
} vec3;

vec3  vec3_make(float x, float y, float z);
vec3  vec3_make1(float xyz);
vec3  vec3_zero();
vec3  vec3_negate(vec3 u);
vec3  vec3_abs(vec3 u);
vec3  vec3_sign(vec3 u);
vec3  vec3_clampv(vec3 u, vec3 min, vec3 max);
vec3  vec3_clampf(vec3 u, float min, float max);
vec3  vec3_lerp(vec3 from, vec3 to, float t);
vec3  vec3_mulv(vec3 u, vec3 v);
vec3  vec3_divv(vec3 u, vec3 v);
vec3  vec3_addv(vec3 u, vec3 v);
vec3  vec3_subv(vec3 u, vec3 v);
vec3  vec3_minv(vec3 u, vec3 v);
vec3  vec3_maxv(vec3 u, vec3 v);
float vec3_minf(vec3 u);
float vec3_maxf(vec3 u);
float vec3_length(vec3 u);
vec3  vec3_normalize(vec3 u);
float vec3_dot(vec3 u, vec3 v);
vec3  vec3_cross(vec3 u, vec3 v);
int   vec3_equals(vec3 u, vec3 v);
int   vec3_equals_epsilon(vec3 u, vec3 v, float e);

//----------------------------------------
// vec 4
//----------------------------------------

typedef struct vec4{
  union{
    struct{
      float x;
      float y;
      float z;
      float w;
    };
    float a[4];
  };
} vec4;

vec4  vec4_make(float x, float y, float z, float w);
vec4  vec4_make1(float xyzw);
vec4  vec4_zero();
vec4  vec4_negate(vec4 u);
vec4  vec4_abs(vec4 u);
vec4  vec4_sign(vec4 u);
vec4  vec4_clampv(vec4 u, vec4 min, vec4 max);
vec4  vec4_clampf(vec4 u, float min, float max);
vec4  vec4_lerp(vec4 from, vec4 to, float t);
vec4  vec4_mulv(vec4 u, vec4 v);
vec4  vec4_divv(vec4 u, vec4 v);
vec4  vec4_addv(vec4 u, vec4 v);
vec4  vec4_subv(vec4 u, vec4 v);
vec4  vec4_minv(vec4 u, vec4 v);
vec4  vec4_maxv(vec4 u, vec4 v);
float vec4_minf(vec4 u);
float vec4_maxf(vec4 u);
float vec4_length(vec4 u);
vec4  vec4_normalize(vec4 u);
float vec4_dot(vec4 u, vec4 v);
vec4  vec4_cross(vec4 u, vec4 v);
int   vec4_equals(vec4 u, vec4 v);
int   vec4_equals_epsilon(vec4 u, vec4 v, float e);

#if defined N1_CMATH_IMPLEMENTATION

//----------------------------------------
// common
//----------------------------------------

float clampf(float a, float min, float max){
  float b = min(a, min);
  b = max(b, max);
  return b;
}

float lerpf(float from, float to, float t){
  return (to - from) * t + from;
}

//----------------------------------------
// vec2
//----------------------------------------

vec2  vec2_make(float x, float y){
  vec2 u = {x, y};
  return u;
}
vec2 vec2_make1(float xy){
  vec2 u = {xy, xy};
  return u;
}
vec2 vec2_zero(){
  vec2 u = {0, 0};
  return u;
}
vec2 vec2_negate(vec2 u){
  vec2 v = {-u.x, -u.y};
  return v;
}
vec2 vec2_abs(vec2 u){
  vec2 v = {abs(u.x), abs(u.y)};
  return v;
}
vec2 vec2_sign(vec2 u){
  vec2 v = {sign(u.x), sign(u.y)};
  return v;
}
vec2 vec2_clampv(vec2 u, vec2 min, vec2 max){
  vec2 v = {clampf(u.x, min.x, max.x), clampf(u.y, min.y, max.y)};
  return v;
}
vec2  vec2_clampf(vec2 u, float min, float max){
  vec2 v = {clampf(u.x, min, max), clampf(u.y, min, max)};
  return v;
}
vec2  vec2_lerp(vec2 from, vec2 to, float t){
  vec2 w = {lerpf(from.x, to.x, t), lerpf(from.y, to.y, t)};
  return w;
}
vec2  vec2_mulv(vec2 u, vec2 v){
  vec2 w = {u.x * v.x, u.y * u.y};
  return w;
}
vec2  vec2_divv(vec2 u, vec2 v){
  vec2 w = {u.x / v.x, u.y / u.y};
  return w;
}
vec2  vec2_addv(vec2 u, vec2 v){
  vec2 w = {u.x + v.x, u.y + u.y};
  return w;
}
vec2  vec2_subv(vec2 u, vec2 v){
  vec2 w = {u.x - v.x, u.y - u.y};
  return w;
}
vec2  vec2_minv(vec2 u, vec2 v){
  vec2 w = {min(u.x, v.x), min(u.y, u.y)};
  return w;
}
vec2  vec2_maxv(vec2 u, vec2 v){
  vec2 w = {max(u.x, v.x), max(u.y, u.y)};
  return w;
}
float vec2_minf(vec2 u){
  return min(u.x, u.y);
}
float vec2_maxf(vec2 u){
  return max(u.x, u.y);
}
float vec2_length(vec2 u){
  return (float)sqrt((double)(u.x * u.x + u.y * u.y));
}
vec2  vec2_normalize(vec2 u){
  const float d = vec2_length(u);
  vec2 v = {u.x / d, u.y / d};
  return v;
}
vec2 vec2_normal(vec2 u){
  vec2 v = {u.y, -u.x};
  return v;
}
float vec2_dot(vec2 u, vec2 v){
  return (u.x * v.x) + (u.y * v.y);
}
float vec2_cross(vec2 u, vec2 v){
  return (u.x * v.y) - (v.x * u.y);
}
int vec2_equals(vec2 u, vec2 v){
  return (u.x == v.x && u.y == v.y);
}
int vec2_equals_epsilon(vec2 u, vec2 v, float e){
  vec2 w = vec2_abs(vec2_subv(u, v));
  return w.x <= e && w.y <= e;
}

//----------------------------------------
// vec3
//----------------------------------------

vec3  vec3_make(float x, float y, float z){
  vec3 u = {x, y, z};
  return u;
}
vec3 vec3_make1(float xyz){
  vec3 u = {xyz, xyz, xyz};
  return u;
}
vec3 vec3_zero(){
  vec3 u = {0, 0, 0};
  return u;
}
vec3 vec3_negate(vec3 u){
  vec3 v = {-u.x, -u.y, -u.z};
  return v;
}
vec3 vec3_abs(vec3 u){
  vec3 v = {abs(u.x), abs(u.y), abs(u.z)};
  return v;
}
vec3 vec3_sign(vec3 u){
  vec3 v = {sign(u.x), sign(u.y), sign(u.z)};
  return v;
}
vec3 vec3_clampv(vec3 u, vec3 min, vec3 max){
  vec3 v = {
    clampf(u.x, min.x, max.x),
    clampf(u.y, min.y, max.y),
    clampf(u.z, min.z, max.z)
  };
  return v;
}
vec3  vec3_clampf(vec3 u, float min, float max){
  vec3 v = {
    clampf(u.x, min, max),
    clampf(u.y, min, max),
    clampf(u.z, min, max)
  };
  return v;
}
vec3  vec3_lerp(vec3 from, vec3 to, float t){
  vec3 w = {
    lerpf(from.x, to.x, t),
    lerpf(from.y, to.y, t),
    lerpf(from.z, to.z, t)
  };
  return w;
}
vec3  vec3_mulv(vec3 u, vec3 v){
  vec3 w = {
    u.x * v.x,
    u.y * u.y,
    u.z * u.z
  };
  return w;
}
vec3  vec3_divv(vec3 u, vec3 v){
  vec3 w = {
    u.x / v.x,
    u.y / u.y,
    u.z / u.z
  };
  return w;
}
vec3  vec3_addv(vec3 u, vec3 v){
  vec3 w = {
    u.x + v.x,
    u.y + u.y,
    u.z + u.z
  };
  return w;
}
vec3  vec3_subv(vec3 u, vec3 v){
  vec3 w = {
    u.x - v.x,
    u.y - u.y,
    u.z - u.z
  };
  return w;
}
vec3  vec3_minv(vec3 u, vec3 v){
  vec3 w = {
    min(u.x, v.x),
    min(u.y, u.y),
    min(u.z, u.z)
  };
  return w;
}
vec3  vec3_maxv(vec3 u, vec3 v){
  vec3 w = {
    max(u.x, v.x),
    max(u.y, u.y),
    max(u.z, u.z),
  };    
  return w;
}
float vec3_minf(vec3 u){
  return min(min(u.x, u.y), u.z);
}
float vec3_maxf(vec3 u){
  return max(max(u.x, u.y), u.z);
}
float vec3_length(vec3 u){
  return (float)sqrt((double)(u.x * u.x + u.y * u.y + u.z * u.z));
}
vec3  vec3_normalize(vec3 u){
  const float d = vec3_length(u);
  vec3 v = {u.x / d, u.y / d, u.z / d};
  return v;
}
float vec3_dot(vec3 u, vec3 v){
  return (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
}
vec3 vec3_cross(vec3 u, vec3 v){
  vec3 w;
    
  w.x = u.y * v.z - u.z * v.y;
  w.y = -(u.x * v.z - u.z * v.x);
  w.z = u.x * v.y - u.y * v.x;
    
  return w;
}
int vec3_equals(vec3 u, vec3 v){
  return (u.x == v.x && u.y == v.y && u.z == v.z);
}
int vec3_equals_epsilon(vec3 u, vec3 v, float e){
  vec3 w = vec3_abs(vec3_subv(u, v));
  return w.x <= e && w.y <= e && w.z <= e;
}

//----------------------------------------
// vec4
//----------------------------------------

vec4  vec4_make(float x, float y, float z, float w){
  vec4 u = {x, y, z, w};
  return u;
}
vec4 vec4_make1(float xyzw){
  vec4 u = {xyzw, xyzw, xyzw, xyzw};
  return u;
}
vec4 vec4_zero(){
  vec4 u = {0, 0, 0, 0};
  return u;
}
vec4 vec4_negate(vec4 u){
  vec4 v = {-u.x, -u.y, -u.z, -u.w};
  return v;
}
vec4 vec4_abs(vec4 u){
  vec4 v = {abs(u.x), abs(u.y), abs(u.z), abs(u.w)};
  return v;
}
vec4 vec4_sign(vec4 u){
  vec4 v = {sign(u.x), sign(u.y), sign(u.z), sign(u.w)};
  return v;
}
vec4 vec4_clampv(vec4 u, vec4 min, vec4 max){
  vec4 v = {
    clampf(u.x, min.x, max.x),
    clampf(u.y, min.y, max.y),
    clampf(u.z, min.z, max.z),
    clampf(u.w, min.w, max.w)
  };
  return v;
}
vec4  vec4_clampf(vec4 u, float min, float max){
  vec4 v = {
    clampf(u.x, min, max),
    clampf(u.y, min, max),
    clampf(u.z, min, max),
    clampf(u.w, min, max)
  };
  return v;
}
vec4  vec4_lerp(vec4 from, vec4 to, float t){
  vec4 w = {
    lerpf(from.x, to.x, t),
    lerpf(from.y, to.y, t),
    lerpf(from.z, to.z, t),
    lerpf(from.w, to.w, t)
  };
  return w;
}
vec4  vec4_mulv(vec4 u, vec4 v){
  vec4 w = {
    u.x * v.x,
    u.y * u.y,
    u.z * u.z,
    u.w * u.w
  };
  return w;
}
vec4  vec4_divv(vec4 u, vec4 v){
  vec4 w = {
    u.x / v.x,
    u.y / u.y,
    u.z / u.z,
    u.w / u.w
  };
  return w;
}
vec4  vec4_addv(vec4 u, vec4 v){
  vec4 w = {
    u.x + v.x,
    u.y + u.y,
    u.z + u.z,
    u.w + u.w
  };
  return w;
}
vec4  vec4_subv(vec4 u, vec4 v){
  vec4 w = {
    u.x - v.x,
    u.y - u.y,
    u.z - u.z,
    u.w - u.w
  };
  return w;
}
vec4  vec4_minv(vec4 u, vec4 v){
  vec4 w = {
    min(u.x, v.x),
    min(u.y, u.y),
    min(u.z, u.z),
    min(u.w, u.w)
  };
  return w;
}
vec4  vec4_maxv(vec4 u, vec4 v){
  vec4 w = {
    max(u.x, v.x),
    max(u.y, u.y),
    max(u.z, u.z),
    max(u.w, u.w),
  };    
  return w;
}
float vec4_minf(vec4 u){
  return min(min(min(u.x, u.y), u.z), u.w);
}
float vec4_maxf(vec4 u){
  return max(max(max(u.x, u.y), u.z), u.w);
}
float vec4_length(vec4 u){
  return (float)sqrt((double)(u.x * u.x + u.y * u.y + u.z * u.z + u.w * u.w));
}
vec4  vec4_normalize(vec4 u){
  const float d = vec4_length(u);
  vec4 v = {u.x / d, u.y / d, u.z / d, u.w / d};
  return v;
}
int vec4_equals(vec4 u, vec4 v){
  return (u.x == v.x && u.y == v.y && u.z == v.z && u.w == v.w);
}
int vec4_equals_epsilon(vec4 u, vec4 v, float e){
  vec4 w = vec4_abs(vec4_subv(u, v));
  return w.x <= e && w.y <= e && w.z <= e && w.w <= e;
}

//----------------------------------------
// eof
//----------------------------------------

#endif
#endif
