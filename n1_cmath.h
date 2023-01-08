#ifndef N1_CMATH_H
#define N1_CMATH_H

#include <math.h>

#include <immintrin.h>

//----------------------------------------
// common
//----------------------------------------

#define PI      (3.14159265358979323846)
#define HALF_PI (1.57079632679489661923)
#define THETA   (6.28318530717958647692)

#define PI64      (3.1415926535897932384626433832795028841971693993751058209749445923)
#define HALF_PI64 (1.5707963267948966192313216916397514420985846996875529104874722961)
#define THETA64   (6.2831853071795864769252867665590057683943387987502116419498891846)


#define min(a, b) (a <= b ? a : b)
#define max(a, b) (a >= b ? a : b)
#define abs(a)    (a > 0 ? a : -a)
#define sign(a)   (a >= 0 ? 1 : -1)

extern const int32_t inf_bits_;
extern const float   inf32    ;

extern const int32_t nan_bits_;
extern const float   nan32    ;

int is_nan(float x);
int is_inf(float x);

float clampf(float a, float min, float max);
float lerpf(float from, float to, float t);

float sinf(float angle);
float cosf(float angle);
float tanf(float angle);

float asinf(float x);
float acosf(float x);
float atanf(float x);

float cotanf(float angle);
float atan2f(float y, float x);

float sqrtf(float x);
float fmodf(float n, float d);
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
int   vec2_equal(vec2 u, vec2 v);
int   vec2_equal_epsilon(vec2 u, vec2 v, float e);

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
int   vec3_equal(vec3 u, vec3 v);
int   vec3_equal_epsilon(vec3 u, vec3 v, float e);

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
    __m128 m128;
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
int   vec4_equal(vec4 u, vec4 v);
int   vec4_equal_epsilon(vec4 u, vec4 v, float e);

//----------------------------------------
// quaternion
//----------------------------------------

typedef struct quaternion{
  union{
    struct {
      float i;
      float j;
      float k;
      float a;
    };
    float  af[4];
    __m128 m128;
    vec4   v4;
  };
} quaternion;

quaternion quat_make(float i, float j, float k, float a);
quaternion quat_make_identity();
quaternion quat_make_angle_axis(float rad, vec3 axis);
quaternion quat_make_yaw_pitch_roll(float yaw, float pitch, float roll);
vec3       quat_img(quaternion q);
float      quat_real(quaternion q);
quaternion quat_inverse(quaternion q);
quaternion quat_mulq(quaternion q0, quaternion q1);
vec3       quat_mulv(quaternion q0, vec3 u);
quaternion quat_from_basis_vectors(vec3 u0, vec3 u1, vec3 u2);
quaternion quat_look_rot(vec3 forward, vec3 up);

//----------------------------------------
// mat4
//----------------------------------------

typedef struct mat4{
  union{
    struct {
      vec4 col_0;
      vec4 col_1;
      vec4 col_2;
      vec4 col_3;
    };
    float  a_f[16];
    __m128 a_m128[4];
    vec4   a_v[4];
  };
} mat4;


mat4 mat4_make_cols(float c0_x, float c0_y, float c0_z, float c0_w,
                    float c1_x, float c1_y, float c1_z, float c1_w,
                    float c2_x, float c2_y, float c2_z, float c2_w,
                    float c3_x, float c3_y, float c3_z, float c3_w);

mat4 mat4_make_rows(float c0_x, float c1_x, float c2_x, float c3_x,
                    float c0_y, float c1_y, float c2_y, float c3_y,
                    float c0_z, float c1_z, float c2_z, float c3_z,
                    float c0_2, float c1_w, float c2_w, float c3_w);

mat4 mat4_make_identity();
mat4 mat4_transpose(mat4 m);
mat4 mat4_mulm(mat4 a, mat4 b);
vec4 mat4_mulv(mat4 a, vec4 u);
mat4 mat4_translate(float x, float y, float z);
mat4 mat4_translatev(vec3 u);
mat4 mat4_scale(float x, float y, float z);
mat4 mat4_scalef(float s);
mat4 mat4_scalev(vec3 u);
mat4 mat4_rot_x(float rad);
mat4 mat4_rot_y(float rad);
mat4 mat4_rot_z(float rad);
mat4 mat4_rot(quaternion rot);
mat4 mat4_ts(vec3 transform, vec3 scale);
mat4 mat4_trs(vec3 transform, quaternion rot, vec3 scale);
mat4 mat4_rts(quaternion rot, vec3 transform, vec3 scale);
mat4 mat4_ortho_lh(float l, float r, float t, float b, float ne, float fa);
mat4 mat4_ortho_rh(float l, float r, float t, float b, float ne, float fa);
mat4 mat4_perspective_lh(float fov, float aspect, float ne, float fa);
mat4 mat4_perspective_rh(float fov, float aspect, float ne, float fa);
mat4 mat4_look_at(vec3 from, vec3 to, vec3 up);


#if defined N1_CMATH_IMPLEMENTATION

//----------------------------------------
// common
//----------------------------------------

const int32_t inf_bits_ = 0b01111111100000000000000000000000; //0x7F800000;
const float   inf32     = ((INFINITY));

const int32_t nan_bits_ = 0x7F800001;
const float   nan32     = ((NAN));


int is_nan(float x){
  return isnan(x);
}

int is_inf(float x){
  return isinf(x);
}
float clampf(float a, float min, float max){
  float b = max(a, min);
  b = min(b, max);
  return b;
}

float lerpf(float from, float to, float t){
  return (to - from) * t + from;
}

float sinf(float angle){
  return (float)(sin(angle));
}

float cosf(float angle){
  return (float)(cos(angle));
}

float tanf(float angle){
  return (float)(tan(angle));
}

float asinf(float x){
  return (float)asin(x);
}

float acosf(float x){
  return (float)acos(x);
}

float atanf(float x){
  return (float)atan(x);
}
float cotanf(float angle){
  return 1.0f / tan(angle);
}
float atan2f(float y, float x){
  return (float)atan2(y, x);
}

float sqrtf(float x){
  if(x < 0){
    return nan32;
  }
  return (float)(sqrt(x));
}
float fmodf(float n, float d){
  return (float)(fmod(n, d));
}

//----------------------------------------
// vec2
//----------------------------------------

vec2 vec2_make(float x, float y){
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
vec2 vec2_clampf(vec2 u, float min, float max){
  vec2 v = {clampf(u.x, min, max), clampf(u.y, min, max)};
  return v;
}
vec2 vec2_lerp(vec2 from, vec2 to, float t){
  vec2 w = {lerpf(from.x, to.x, t), lerpf(from.y, to.y, t)};
  return w;
}
vec2 vec2_mulv(vec2 u, vec2 v){
  vec2 w = {
    u.x * v.x,
    u.y * v.y
  };
  return w;
}
vec2 vec2_divv(vec2 u, vec2 v){
  vec2 w = {
    u.x / v.x,
    u.y / v.y
  };
  return w;
}
vec2 vec2_addv(vec2 u, vec2 v){
  vec2 w = {
    u.x + v.x,
    u.y + v.y
  };
  return w;
}
vec2 vec2_subv(vec2 u, vec2 v){
  vec2 w = {
    u.x - v.x,
    u.y - v.y
  };
  return w;
}
vec2 vec2_minv(vec2 u, vec2 v){
  vec2 w = {
    min(u.x, v.x),
    min(u.y, v.y)
  };
  return w;
}
vec2 vec2_maxv(vec2 u, vec2 v){
  vec2 w = {
    max(u.x, v.x),
    max(u.y, v.y)
  };
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
vec2 vec2_normalize(vec2 u){
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
int vec2_equal(vec2 u, vec2 v){
  return (u.x == v.x && u.y == v.y);
}
int vec2_equal_epsilon(vec2 u, vec2 v, float e){
  vec2 w = vec2_abs(vec2_subv(u, v));
  return w.x <= e && w.y <= e;
}

//----------------------------------------
// vec3
//----------------------------------------

vec3 vec3_make(float x, float y, float z){
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
vec3 vec3_clampf(vec3 u, float min, float max){
  vec3 v = {
    clampf(u.x, min, max),
    clampf(u.y, min, max),
    clampf(u.z, min, max)
  };
  return v;
}
vec3 vec3_lerp(vec3 from, vec3 to, float t){
  vec3 w = {
    lerpf(from.x, to.x, t),
    lerpf(from.y, to.y, t),
    lerpf(from.z, to.z, t)
  };
  return w;
}
vec3 vec3_mulv(vec3 u, vec3 v){
  vec3 w = {
    u.x * v.x,
    u.y * v.y,
    u.z * v.z
  };
  return w;
}
vec3 vec3_divv(vec3 u, vec3 v){
  vec3 w = {
    u.x / v.x,
    u.y / v.y,
    u.z / v.z
  };
  return w;
}
vec3 vec3_addv(vec3 u, vec3 v){
  vec3 w = {
    u.x + v.x,
    u.y + v.y,
    u.z + v.z
  };
  return w;
}
vec3 vec3_subv(vec3 u, vec3 v){
  vec3 w = {
    u.x - v.x,
    u.y - v.y,
    u.z - v.z
  };
  return w;
}
vec3 vec3_minv(vec3 u, vec3 v){
  vec3 w = {
    min(u.x, v.x),
    min(u.y, v.y),
    min(u.z, v.z)
  };
  return w;
}
vec3 vec3_maxv(vec3 u, vec3 v){
  vec3 w = {
    max(u.x, v.x),
    max(u.y, v.y),
    max(u.z, v.z),
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
vec3 vec3_normalize(vec3 u){
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
int vec3_equal(vec3 u, vec3 v){
  return (u.x == v.x && u.y == v.y && u.z == v.z);
}
int vec3_equal_epsilon(vec3 u, vec3 v, float e){
  vec3 w = vec3_abs(vec3_subv(u, v));
  return w.x <= e && w.y <= e && w.z <= e;
}

//----------------------------------------
// vec4
//----------------------------------------

vec4 vec4_make(float x, float y, float z, float w){
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
vec4 vec4_clampf(vec4 u, float min, float max){
  vec4 v = {
    clampf(u.x, min, max),
    clampf(u.y, min, max),
    clampf(u.z, min, max),
    clampf(u.w, min, max)
  };
  return v;
}
vec4 vec4_lerp(vec4 from, vec4 to, float t){
  vec4 w = {
    lerpf(from.x, to.x, t),
    lerpf(from.y, to.y, t),
    lerpf(from.z, to.z, t),
    lerpf(from.w, to.w, t)
  };
  return w;
}
vec4 vec4_mulv(vec4 u, vec4 v){
  vec4 w = {
    u.x * v.x,
    u.y * v.y,
    u.z * v.z,
    u.w * v.w
  };
  return w;
}
vec4 vec4_divv(vec4 u, vec4 v){
  vec4 w = {
    u.x / v.x,
    u.y / v.y,
    u.z / v.z,
    u.w / v.w
  };
  return w;
}
vec4 vec4_addv(vec4 u, vec4 v){
  vec4 w = {
    u.x + v.x,
    u.y + v.y,
    u.z + v.z,
    u.w + v.w
  };
  return w;
}
vec4 vec4_subv(vec4 u, vec4 v){
  vec4 w = {
    u.x - v.x,
    u.y - v.y,
    u.z - v.z,
    u.w - v.w
  };
  return w;
}
vec4 vec4_minv(vec4 u, vec4 v){
  vec4 w = {
    min(u.x, v.x),
    min(u.y, v.y),
    min(u.z, v.z),
    min(u.w, v.w)
  };
  return w;
}
vec4 vec4_maxv(vec4 u, vec4 v){
  vec4 w = {
    max(u.x, v.x),
    max(u.y, v.y),
    max(u.z, v.z),
    max(u.w, v.w),
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
vec4 vec4_normalize(vec4 u){
  const float d = vec4_length(u);
  vec4 v = {u.x / d, u.y / d, u.z / d, u.w / d};
  return v;
}
int vec4_equal(vec4 u, vec4 v){
  return (u.x == v.x && u.y == v.y && u.z == v.z && u.w == v.w);
}
int vec4_equal_epsilon(vec4 u, vec4 v, float e){
  vec4 w = vec4_abs(vec4_subv(u, v));
  return w.x <= e && w.y <= e && w.z <= e && w.w <= e;
}

//----------------------------------------
// quaternion
//----------------------------------------

quaternion quat_make(float i, float j, float k, float a){
  quaternion q = {i, j, k, a};
  return q;
}

quaternion quat_make_identity(){
  quaternion q = {0, 0, 0, 1};
  return q;
}

vec3 quat_img(quaternion q){
  vec3 u = {q.i, q.j, q.k};
  return u;
}

float quat_real(quaternion q){
  return q.a;
}

quaternion quat_make_angle_axis(float angle, vec3 axis){
  const float c = cosf(angle / 2.0f);
  const float s = sinf(angle / 2.0f);
  const vec3  n = vec3_normalize(axis);

  quaternion q = {
    s * n.x,
    s * n.y,
    s * n.z,
    c
  };
  
  return q;
}

quaternion quat_make_yaw_pitch_roll(float yaw, float pitch, float roll){
  
  const quaternion q_yaw   = quat_make_angle_axis(yaw, vec3_make(0, 1, 0));
  const quaternion q_pitch = quat_make_angle_axis(pitch, vec3_make(1, 0, 0));
  const quaternion q_roll  = quat_make_angle_axis(roll, vec3_make(0, 0, 1));
  
  quaternion q = quat_mulq(q_yaw, q_pitch);
  q = quat_mulq(q, q_roll);
  
  return q;
}

quaternion quat_inverse(quaternion q){
  quaternion q0 = {-q.i, -q.j, -q.k, q.a};
  return q0;
}

quaternion quat_mulq(quaternion q0, quaternion q1){
  quaternion result;
   
  vec3 cross = vec3_cross(quat_img(q0), quat_img(q1));
   
  result.i = q1.i * q0.a + q0.i * q1.a + cross.x;
  result.j = q1.j * q0.a + q0.j * q1.a + cross.y;
  result.k = q1.k * q0.a + q0.k * q1.a + cross.z;
  result.a = q0.a * q1.a - vec3_dot(quat_img(q0), quat_img(q1));
   
  return result;    
}

vec3 quat_mulv(quaternion q, vec3 u){

  const vec3 img = quat_img(q);

  // (q.ijk * 2) x u 
  const vec3 cross = vec3_cross(vec3_mulv(img, vec3_make1(2)),
                                u);
  
  //(cross * q.a)
  const vec3 cross_a = vec3_mulv(cross, vec3_make1(q.a));

  //u + (cross * q.a)
  vec3 result = vec3_addv(u, cross_a);

  //[u + (cross * this->a)] + (q.ijk x cross); 
  result = vec3_addv(result, vec3_cross(img, cross));
  
  return result;  
}

quaternion quat_from_basis_vectors(vec3 u0, vec3 u1, vec3 u2){
  quaternion q;

  //qw= √(1 + m00 + m11 + m22) /2
  //  qx = (m21 - m12)/( 4 *qw)
  //  qy = (m02 - m20)/( 4 *qw)
  //  qz = (m10 - m01)/( 4 *qw)
  
  q.a = sqrt((1 + u0.x + u1.y + u2.z)) / 2.0;
  q.i = (u2.y - u1.z) / (4 * q.a);
  q.j = (u0.z - u2.x) / (4 * q.a);
  q.k = (u1.x - u0.y) / (4 * q.a);

  
  return quat_inverse(q);
}

quaternion quat_look_rot(vec3 forward, vec3 up){

  forward = vec3_negate(forward);
  vec3 right = vec3_cross(up, forward);
  up = vec3_cross(forward, right);

  quaternion q = quat_from_basis_vectors(vec3_normalize(right),
                                         vec3_normalize(up),
                                         vec3_normalize(forward));

  return q;
}
//----------------------------------------
// mat4
//----------------------------------------

mat4 mat4_make_cols(float c0_x, float c0_y, float c0_z, float c0_w,
                    float c1_x, float c1_y, float c1_z, float c1_w,
                    float c2_x, float c2_y, float c2_z, float c2_w,
                    float c3_x, float c3_y, float c3_z, float c3_w){
  mat4 m = {
    c0_x,  c0_y,  c0_z,  c0_w,
    c1_x,  c1_y,  c1_z,  c1_w,
    c2_x,  c2_y,  c2_z,  c2_w,
    c3_x,  c3_y,  c3_z,  c3_w
  };

  return m;
}

mat4 mat4_make_rows(float c0_x, float c1_x, float c2_x, float c3_x,
                    float c0_y, float c1_y, float c2_y, float c3_y,
                    float c0_z, float c1_z, float c2_z, float c3_z,
                    float c0_w, float c1_w, float c2_w, float c3_w){
  mat4 m = {
    c0_x,  c0_y,  c0_z,  c0_w,
    c1_x,  c1_y,  c1_z,  c1_w,
    c2_x,  c2_y,  c2_z,  c2_w,
    c3_x,  c3_y,  c3_z,  c3_w
  };
  return m;
}

mat4 mat4_make_identity(){
  mat4 m = {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
  };
  return m;
}
mat4 mat4_transpose(mat4 m){
  mat4 mm = {
    m.a_f[0], m.a_f[4], m.a_f[8], m.a_f[12],
    m.a_f[1], m.a_f[5], m.a_f[9], m.a_f[13],
    m.a_f[2], m.a_f[6], m.a_f[10], m.a_f[14],
    m.a_f[3], m.a_f[7], m.a_f[11], m.a_f[15],
  };
  return mm;
}

mat4 mat4_mulm(mat4 a, mat4 b){
  vec4 rows[4];

  
  rows[0] = vec4_make(a.col_0.x, a.col_1.x, a.col_2.x, a.col_3.x);
  rows[1] = vec4_make(a.col_0.y, a.col_1.y, a.col_2.y, a.col_3.y);
  rows[2] = vec4_make(a.col_0.z, a.col_1.z, a.col_2.z, a.col_3.z);
  rows[3] = vec4_make(a.col_0.w, a.col_1.w, a.col_2.w, a.col_3.w);

  mat4 m;
  for(char r = 0; r < 4; r++){
    for(char c = 0; c < 4; c++){
      vec4 mul;
      mul.m128 = _mm_mul_ps(rows[r].m128, b.a_m128[c]);
      m.a_f[c * 4 + r] = mul.x + mul.y + mul.z + mul.w;
    }
  }
  return m;
}
vec4 mat4_mulv(mat4 a, vec4 u){
  mat4 mat = mat4_transpose(a);
  vec4 result;
  
  __m128 temp;
  float* temp_p = (float*)&temp;
    
  temp = _mm_mul_ps(mat.a_m128[0], u.m128);
  result.x = temp_p[0] + temp_p[1] + temp_p[2] + temp_p[3];
    
  temp = _mm_mul_ps(mat.a_m128[1], u.m128);
  result.y = temp_p[0] + temp_p[1] + temp_p[2] + temp_p[3];
    
  temp = _mm_mul_ps(mat.a_m128[2], u.m128);
  result.z = temp_p[0] + temp_p[1] + temp_p[2] + temp_p[3];

  temp = _mm_mul_ps(mat.a_m128[3], u.m128);
  result.w = temp_p[0] + temp_p[1] + temp_p[2] + temp_p[3];
  
  return result;
}

mat4 mat4_translate(float x, float y, float z){
  mat4 m = {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    x, y, z, 1};
  return m;
}

mat4 mat4_translatev(vec3 u){
  mat4 m = {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    u.x, u.y, u.z, 1};
  return m;
}

mat4 mat4_scale(float x, float y, float z){
  mat4 m = {
    x, 0, 0, 0,
    0, y, 0, 0,
    0, 0, z, 0,
    0, 0, 0, 1};
  return m;
}
mat4 mat4_scalef(float s){
  mat4 m = {
    s, 0, 0, 0,
    0, s, 0, 0,
    0, 0, s, 0,
    0, 0, 0, 1};
  return m;  
}
mat4 mat4_scalev(vec3 u){
  mat4 m = {
    u.x, 0, 0, 0,
    0, u.y, 0, 0,
    0, 0, u.z, 0,
    0, 0, 0, 1};
  return m;  
}

mat4 mat4_rot_x(float angle){
  const float c = cosf(angle);
  const float s = sinf(angle);
  
  const mat4 m = {
    1, 0, 0, 0,
    0, c, s, 0,
    0, -s, c, 0,
    0, 0, 0, 1
  };

  return m;
}
mat4 mat4_rot_y(float angle){
  const float c = cosf(angle);
  const float s = sinf(angle);
    
  const mat4 m = {
    c, 0, -s, 0,
    0, 1, 0, 0,
    s, 0, c, 0,
    0, 0, 0, 1
  };

  return m;
}
mat4 mat4_rot_z(float angle){
  const float c = cosf(angle);
  const float s = sinf(angle);
    
  const mat4 m = {
    c, s, 0, 0,
    -s, c, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
  };
  return m;
}
mat4 mat4_rot(quaternion q){

  mat4 a = {
    q.a, q.k,-q.j, q.i,
    -q.k, q.a, q.i, q.j,
    q.j,-q.i, q.a, q.k,
    -q.i,-q.j,-q.k, q.a
  };
    
  mat4 b = {
    q.a, q.k,-q.j,-q.i,
    -q.k, q.a, q.i,-q.j,
    q.j,-q.i, q.a,-q.k,
    q.i, q.j, q.k, q.a
  };
    
  return mat4_mulm(a, b);
}
mat4 mat4_ts(vec3 transform, vec3 scale){
  mat4 m = {
    scale.x, 0, 0, 0,
    0, scale.y, 0, 0,
    0, 0, scale.z, 0,
    transform.x, transform.y, transform.z, 1};
  return m;  
}
mat4 mat4_trs(vec3 transform, quaternion rot, vec3 scale){
  if(vec4_equal(rot.v4, quat_make_identity().v4)){
    return mat4_ts(transform, scale);
  }

  const mat4 tr = mat4_mulm(mat4_translatev(transform),
                            mat4_rot(rot));

  return mat4_mulm(tr, mat4_scalev(scale));
}
mat4 mat4_rts(quaternion rot, vec3 transform, vec3 scale){

  if(vec4_equal(rot.v4, quat_make_identity().v4)){
    return mat4_ts(transform, scale);
  }

  const mat4 rt = mat4_mulm(mat4_rot(rot),
                            mat4_translatev(transform));
                            

  return mat4_mulm(rt, mat4_scalev(scale));  
}

mat4 mat4_ortho_lh(float left, float right, float top, float bottom, float ne, float fa){
  mat4 m = {2.0f / (right - left), 0.0f, 0.0f, 0.0f,
      0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
      0.0f, 0.0f, 1.0f / (ne - fa), 0.0f,
      ((right + left) / (left - right)), ((top + bottom) / (bottom - top)), (ne / (fa - ne)), 1.0f};
  return m;
}
mat4 mat4_ortho_rh(float left, float right, float top, float bottom, float ne, float fa){
  mat4 m = {
    2.0f / (right - left), 0.0f, 0.0f, 0.0f,
    0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f / (ne - fa), 0.0f,
    ((right + left) / (left - right)), ((top + bottom) / (bottom - top)), (ne / (ne - fa)), 1.0f};

  return m;
}

mat4 mat4_perspective_lh(float fov, float aspect, float ne, float fa){
  const float y_scale = cotanf(0.5f * (fov / 180.0f * PI));
  const float x_scale = y_scale / aspect;
  const mat4 m = {
    x_scale, 0, 0, 0,
    0, y_scale, 0, 0,
    0, 0, fa / (fa - ne), 1,
    0, 0, (-ne * fa) / (fa - ne), 0
  };
  return m;
}
mat4 mat4_perspective_rh(float fov, float aspect, float ne, float fa){
  const float y_scale = cotanf(0.5f * (fov / 180.0f * PI));
  const float x_scale = y_scale / aspect;
  const mat4 m = {
    x_scale, 0, 0, 0,
    0, y_scale, 0, 0,
    0, 0, fa / (ne - fa), -1,
    0, 0, (ne * fa) / (ne - fa), 0
  };
  return m;
}
mat4 mat4_look_at(vec3 from, vec3 to, vec3 up_0){
  const vec3 forward = vec3_normalize(vec3_subv(to, from));
  const vec3 right   = vec3_normalize(vec3_cross(forward, up_0));
  const vec3 up      = vec3_normalize(vec3_cross(right, forward));

  from = vec3_negate(from);
  
  const mat4 m = {
    right.x, up.x, forward.x, 0,
    right.y, up.y, forward.y, 0,
    right.z, up.z, forward.z, 0,
    vec3_dot(right, from), vec3_dot(up, from), vec3_dot(forward, from), 1
  };

  return m;
}


//----------------------------------------
// eof
//----------------------------------------

#endif
#endif
