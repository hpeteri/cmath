#include <stdio.h>

#define N1_CMATH_IMPLEMENTATION
#include "n1_cmath.h"

int assert_count = 0;

#define assert(expression) {if(!(expression)){printf("assertion failed '%s' at line %d.\n", __func__, __LINE__);  assert_count ++; /* *(int*)NULL = 0; */ }}

#define assert_equal(a, b) {if(!((a) == (b))){printf("assertion failed '%s' at line %d.\n", __func__, __LINE__); assert_count ++; /* *(int*)NULL = 0;  */ }}

#define assert_todo() {printf("todo '%s' at line %d.\n", __func__, __LINE__); assert_count ++;/* *(int*)NULL = 0;  */ }

#define TEST_BANNER_START(){printf("\n === '%s()' === \n\n", __func__);}

//----------------------------------------
// common
//----------------------------------------

void test_min(){
  assert_equal(min(10, 20), 10);
  assert_equal(min(100, 20), 20);
  assert_equal(min(-10, 20), -10);
}

void test_max(){
  assert_equal(max(10, 20), 20);
  assert_equal(max(100, 20), 100);
  assert_equal(max(-10, 20), 20);
}
void test_is_nan(){
  assert_equal(0, is_nan(10 / 0.0f));
  assert_equal(0, is_nan(-10 / 0.0f));
  assert_equal(1, is_nan(nan32));
  assert_equal(1, is_nan(-nan32));
  assert_equal(1, is_nan(sqrtf(-1)));
}
void test_is_inf(){
  
  assert_equal(0, is_inf(0.0));
  assert_equal(1, is_inf(1.0/0.0));
  assert_equal(-1, is_inf(-1.0/0.0));
  assert_equal(0, is_inf(sqrt(-1.0)));
}
void test_clampf(){
  assert_equal(clampf(0, -10, 10),
               0);

  assert_equal(clampf(-20, -10, 10),
               -10);
  
  assert_equal(clampf(20, -10, 10),
               10);
}
void test_lerpf(){
  assert_equal(lerpf(-10, 10, 0.5f),
               0);

  assert_equal(lerpf(-10, 10, 0),
               -10);

  assert_equal(lerpf(-10, 10, 1),
               10);

  assert_equal(lerpf(-10, 10, 2),
               30);
}
void test_sinf(){
  assert_todo();
}
void test_cosf(){
  assert_todo();
}
void test_tanf(){
  assert_todo();
}
void test_asinf(){
  assert_todo();
}
void test_acosf(){
  assert_todo();
}
void test_atanf(){
  assert_todo();
}
void test_cotanf(){
  assert_todo();
}
void test_atan2f(){
  assert_todo();
}
void test_sqrtf(){
  assert_todo();
}
void test_fmodf(){
  assert_todo();
}

void test_common(){
  TEST_BANNER_START();

  test_min();
  test_max();
  test_is_nan();
  test_is_inf();
  test_clampf();
  test_lerpf();
  
  test_sinf();
  test_cosf();
  test_tanf();
  test_asinf();
  test_acosf();
  test_atanf();
  test_cotanf();
  test_atan2f();

  test_sqrtf();
  test_fmodf();
}

//----------------------------------------
// vec2 
//----------------------------------------

void test_vec2_make(){
 
  vec2 u = vec2_make(10, 20);
  assert_equal(u.x, 10);
  assert_equal(u.y, 20);    
}
void test_vec2_make1(){
  vec2 u = vec2_make1(1);
  assert_equal(u.x, 1);
  assert_equal(u.y, 1);    
  
}
void test_vec2_zero(){
  
  vec2 u = vec2_zero();
    
  assert_equal(u.x, 0);
  assert_equal(u.y, 0);    
}
void test_vec2_negate(){
  {
    vec2 u = vec2_make(10, 20);
    assert_equal(u.x, 10);
    assert_equal(u.y, 20);

    vec2 v = vec2_negate(u);
    assert_equal(v.x, -10);
    assert_equal(v.y, -20);
  }
  {
    vec2 u = vec2_make(-10, -20);
    assert_equal(u.x, -10);
    assert_equal(u.y, -20);

    vec2 v = vec2_negate(u);
    assert_equal(v.x, 10);
    assert_equal(v.y, 20);
  }
}
void test_vec2_abs(){
  {
    vec2 u = vec2_make(-10, -20);
    assert_equal(u.x, -10);
    assert_equal(u.y, -20);

    vec2 v = vec2_abs(u);
    assert_equal(v.x, 10);
    assert_equal(v.y, 20);
  }
}
void test_vec2_sign(){
  { 
    vec2 u = vec2_make(0, 0);
    assert_equal(u.x, 0);
    assert_equal(u.y, 0);

    vec2 v = vec2_sign(u);
    assert_equal(v.x, 1);
    assert_equal(v.y, 1);
  }
  { 
    vec2 u = vec2_make(10, -10);
    assert_equal(u.x, 10);
    assert_equal(u.y, -10);

    vec2 v = vec2_sign(u);
    assert_equal(v.x, 1);
    assert_equal(v.y, -1);
  }
  { 
    vec2 u = vec2_make(-10, 10);
    assert_equal(u.x, -10);
    assert_equal(u.y, 10);

    vec2 v = vec2_sign(u);
    assert_equal(v.x, -1);
    assert_equal(v.y, 1);
  }
}
void test_vec2_clampv(){
  {
    vec2 v = vec2_clampv(vec2_make(10, 20),
                         vec2_make(-10, -20),
                         vec2_make(5, 2));

    assert_equal(v.x, 5.0);
    assert_equal(v.y, 2.0);
    
  }

  {
    vec2 v = vec2_clampv(vec2_make(-100, 20),
                         vec2_make(-10, 0),
                         vec2_make(5, 100));

    assert_equal(v.x, -10);
    assert_equal(v.y, 20);
  }
}
void test_vec2_clampf(){
  {
    vec2 v = vec2_clampf(vec2_make(10, 20),
                         0, 5);

    assert_equal(v.x, 5);
    assert_equal(v.y, 5);
  }

  {
    vec2 v = vec2_clampf(vec2_make(-100, 20),
                         -10, 10);

    assert_equal(v.x, -10);
    assert_equal(v.y, 10);
  }
}
void test_vec2_lerp(){

  {
    vec2 v = vec2_lerp(vec2_make(-10, 10),
                       vec2_make(10, 20),
                       0);

    assert_equal(v.x, -10);
    assert_equal(v.y, 10);
  }
  {
    vec2 v = vec2_lerp(vec2_make(-10, 10),
                       vec2_make(10, 20),
                       0.5f);

    assert_equal(v.x, 0);
    assert_equal(v.y, 15);
  }
  {
    vec2 v = vec2_lerp(vec2_make(-10, 10),
                       vec2_make(10, 20),
                       1.0);

    assert_equal(v.x, 10);
    assert_equal(v.y, 20);
  }
}

void test_vec2_mulv(){

  vec2 u = vec2_make(-5, 5);
  vec2 v = vec2_make(10, 10);

  vec2 v0 = vec2_mulv(u, v);
  
  assert_equal(v0.x, -50);
  assert_equal(v0.y, 50);
  
}
void test_vec2_divv(){

  vec2 u = vec2_make(100, 100);
  vec2 v = vec2_make(2, 25);

  vec2 v0 = vec2_divv(u, v);
  
  assert_equal(v0.x, 50);
  assert_equal(v0.y, 4);
}
void test_vec2_addv(){
  vec2 u = vec2_make(10, 20);
  vec2 v = vec2_make(30, 40);

  vec2 v0 = vec2_addv(u, v);
  
  assert_equal(v0.x, 40);
  assert_equal(v0.y, 60);
}
void test_vec2_subv(){
  vec2 u = vec2_make(30, 60);
  vec2 v = vec2_make(10, 20);

  vec2 v0 = vec2_subv(u, v);
  
  assert_equal(v0.x, 20);
  assert_equal(v0.y, 40);
}
void test_vec2_minv(){
  vec2 u = vec2_make(30, 20);
  vec2 v = vec2_make(10, 70);

  vec2 v0 = vec2_minv(u, v);
  assert_equal(v0.x, 10);
  assert_equal(v0.y, 20);
}
void test_vec2_maxv(){
  vec2 u = vec2_make(30, 20);
  vec2 v = vec2_make(10, 70);

  vec2 v0 = vec2_maxv(u, v);
  assert_equal(v0.x, 30);
  assert_equal(v0.y, 70);
}
void test_vec2_minf(){
  vec2 u = vec2_make(10, 70);
  float f = vec2_minf(u);
  
  assert_equal(f, 10);
}
void test_vec2_maxf(){
  vec2 u = vec2_make(10, 70);
  float f = vec2_maxf(u);

  assert_equal(f, 70);
}
void test_vec2_length(){
  assert_equal(vec2_length(vec2_make(10, 0)), 10);
  assert_equal(vec2_length(vec2_make(-10, 0)), 10);
  assert_equal(vec2_length(vec2_make(0, 10)), 10);
}
void test_vec2_normalize(){
  vec2 u = vec2_make(16, 0);
  vec2 v = vec2_normalize(u);

  assert_equal(v.x, 1);
  assert_equal(v.y, 0);
}
void test_vec2_normal(){
  vec2 u = vec2_make(16, 0);
  vec2 v = vec2_normal(u);

  assert_equal(v.x, 0);
  assert_equal(v.y, -16);
}
void test_vec2_dot(){
  vec2 u = vec2_make(8, 16);
  vec2 v = vec2_make(2, 4);

  float f = vec2_dot(u, v);
  assert_equal(f, 80);
}
void test_vec2_cross(){
  vec2 u = vec2_make(8, 16);
  vec2 v = vec2_make(2, 4);

  float cross = vec2_cross(u, v);
  assert_equal(cross, 8 * 4 - 16 * 2);
}
void test_vec2_equal(){
  vec2 u = vec2_make(8, 16);
  vec2 v = vec2_make(8, 4);

  int t = vec2_equal(u, u);
  int f = vec2_equal(u, v);

  assert_equal(t, 1);
  assert_equal(f, 0);
}
void test_vec2_equal_epsilon(){
  vec2 u = vec2_make(8, 16);
  vec2 v = vec2_make(8, 16.09f);

  int f  = vec2_equal(u, v);
  int ff = vec2_equal_epsilon(u, v, 0.01f);
  int t  = vec2_equal_epsilon(u, v, 0.1f);

  assert_equal(t, 1);
  assert_equal(f, 0);
  assert_equal(ff, 0);
}
void test_vec2(){
  TEST_BANNER_START();
  
  test_vec2_make();
  test_vec2_make1();
  test_vec2_zero();
  test_vec2_negate();
  test_vec2_abs();
  test_vec2_sign();
  test_vec2_clampv();
  test_vec2_clampf();
  test_vec2_lerp();
  test_vec2_mulv();
  test_vec2_divv();
  test_vec2_addv();
  test_vec2_subv();
  test_vec2_minv();
  test_vec2_maxv();
  test_vec2_minf();
  test_vec2_maxf();
  test_vec2_length();
  test_vec2_normalize();
  test_vec2_normal();
  test_vec2_dot();
  test_vec2_cross();
  test_vec2_equal();
  test_vec2_equal_epsilon();

}

//----------------------------------------
// vec3
//----------------------------------------
void test_vec3_make(){
  vec3 u = vec3_make(10, 20, 30);
  assert_equal(u.x, 10);
  assert_equal(u.y, 20);
  assert_equal(u.z, 30);
}
void test_vec3_make1(){
  vec3 u = vec3_make1(1);
  assert_equal(u.x, 1);
  assert_equal(u.y, 1);    
  assert_equal(u.z, 1);    
}
void test_vec3_zero(){
  vec3 u = vec3_zero();
    
  assert_equal(u.x, 0);
  assert_equal(u.y, 0);
  assert_equal(u.z, 0);
}
void test_vec3_negate(){

  vec3 u = vec3_make(10, 20, 30);
  assert_equal(u.x, 10);
  assert_equal(u.y, 20);
  assert_equal(u.z, 30);

  vec3 v = vec3_negate(u);
  assert_equal(v.x, -10);
  assert_equal(v.y, -20);
  assert_equal(v.z, -30);

  v = vec3_negate(v);
  assert_equal(v.x, 10);
  assert_equal(v.y, 20);
  assert_equal(v.z, 30);
}
void test_vec3_abs(){

  vec3 u = vec3_make(-10, -20, -30);
  assert_equal(u.x, -10);
  assert_equal(u.y, -20);
  assert_equal(u.z, -30);

  vec3 v = vec3_abs(u);
  assert_equal(v.x, 10);
  assert_equal(v.y, 20);
  assert_equal(v.z, 30);

}
void test_vec3_sign(){
  { 
    vec3 u = vec3_zero();
    vec3 v = vec3_sign(u);

    assert_equal(v.x, 1);
    assert_equal(v.y, 1);
    assert_equal(v.z, 1);
  }
  { 
    vec3 u = vec3_make(10, -10, 10);
    vec3 v = vec3_sign(u);

    assert_equal(v.x, 1);
    assert_equal(v.y, -1);
    assert_equal(v.z, 1);

    u = vec3_negate(u);
    v = vec3_sign(u);

    assert_equal(v.x, -1);
    assert_equal(v.y, 1);
    assert_equal(v.z, -1);
  }
}
void test_vec3_clampv(){

  vec3 v = vec3_clampv(vec3_make(10, 20, 30),
                       vec3_make(-10, -20, -30),
                       vec3_make(5, 2, 4));

  assert_equal(v.x, 5.0);
  assert_equal(v.y, 2.0);
  assert_equal(v.z, 4);
}
void test_vec3_clampf(){

  vec3 v = vec3_clampf(vec3_make(10, 20, 30),
                       0,
                       5);

  assert_equal(v.x, 5);
  assert_equal(v.y, 5);
  assert_equal(v.z, 5);
  
  v = vec3_clampf(vec3_make(-10, -20, -30),
                  -20, 2);

  assert_equal(v.x, -10);
  assert_equal(v.y, -20);
  assert_equal(v.z, -20);
  
}
void test_vec3_lerp(){

  
  vec3 v = vec3_lerp(vec3_make(-10, 10, 5),
                     vec3_make(10, 20, 15),
                     0.5);

  assert_equal(v.x, 0);
  assert_equal(v.y, 15);
  assert_equal(v.z, 10);
}

void test_vec3_mulv(){

  vec3 u = vec3_make(-1, 2, -3);
  vec3 v = vec3_make(10, 10, 10);

  vec3 v0 = vec3_mulv(u, v);
  
  assert_equal(v0.x, -10);
  assert_equal(v0.y, 20);
  assert_equal(v0.z, -30);
  
}
void test_vec3_divv(){

  vec3 u = vec3_make(100, 100, 100);
  vec3 v = vec3_make(2, 25, 50);

  vec3 v0 = vec3_divv(u, v);
  
  assert_equal(v0.x, 50);
  assert_equal(v0.y, 4);
  assert_equal(v0.z, 2);
}
void test_vec3_addv(){
  vec3 u = vec3_make(10, 20, 30);
  vec3 v = vec3_make(30, 40, 50);

  vec3 v0 = vec3_addv(u, v);
  
  assert_equal(v0.x, 40);
  assert_equal(v0.y, 60);
  assert_equal(v0.z, 80);
}
void test_vec3_subv(){
  vec3 u = vec3_make(30, 60, 90);
  vec3 v = vec3_make(10, 20, 30);

  vec3 v0 = vec3_subv(u, v);
  
  assert_equal(v0.x, 20);
  assert_equal(v0.y, 40);
  assert_equal(v0.z, 60);
}
void test_vec3_minv(){
  vec3 u = vec3_make(30, 20, 10);
  vec3 v = vec3_make(10, 70, 0);

  vec3 v0 = vec3_minv(u, v);
  assert_equal(v0.x, 10);
  assert_equal(v0.y, 20);
  assert_equal(v0.z, 0);
}
void test_vec3_maxv(){
  vec3 u = vec3_make(30, 20, 50);
  vec3 v = vec3_make(10, 70, 30);

  vec3 v0 = vec3_maxv(u, v);
  assert_equal(v0.x, 30);
  assert_equal(v0.y, 70);
  assert_equal(v0.z, 50);
}
void test_vec3_minf(){
  vec3 u = vec3_make(10, 70, 5);
  float f = vec3_minf(u);
  
  assert_equal(f, 5);
}
void test_vec3_maxf(){
  vec3 u = vec3_make(10, 70, 60);
  float f = vec3_maxf(u);

  assert_equal(f, 70);
}
void test_vec3_length(){
  assert_equal(vec3_length(vec3_make(10, 0, 0)), 10);
  assert_equal(vec3_length(vec3_make(-10, 0, 0)), 10);

  assert_equal(vec3_length(vec3_make(0, 10, 0)), 10);
  assert_equal(vec3_length(vec3_make(0, -10, 0)), 10);

  assert_equal(vec3_length(vec3_make(0, 0, 10)), 10);
  assert_equal(vec3_length(vec3_make(0, 0,-10)), 10);
}
void test_vec3_normalize(){
  vec3 u = vec3_make(16, 0, 0);
  vec3 v = vec3_normalize(u);

  assert_equal(v.x, 1);
  assert_equal(v.y, 0);
  assert_equal(v.z, 0);
}

void test_vec3_dot(){
  vec3 u = vec3_make(8, 16, 1);
  vec3 v = vec3_make(2, 4, 5);

  float f = vec3_dot(u, v);
  assert_equal(f, 85);
}
void test_vec3_cross(){
  vec3 u = vec3_make(1, 0, 0);
  vec3 v = vec3_make(0, 1, 0);

  vec3 cross = vec3_cross(u, v);
  
  assert_equal(cross.x, 0);
  assert_equal(cross.y, 0);
  assert_equal(cross.z, 1);
}
void test_vec3_equal(){
  vec3 u = vec3_make(8, 16, 32);
  vec3 v = vec3_make(8, 4, 2);

  int t = vec3_equal(u, u);
  int f = vec3_equal(u, v);

  assert_equal(t, 1);
  assert_equal(f, 0);
}
void test_vec3_equal_epsilon(){
  vec3 u = vec3_make(8, 16, 0);
  vec3 v = vec3_make(8, 16.09f, 0);

  int f  = vec3_equal(u, v);
  int ff = vec3_equal_epsilon(u, v, 0.01f);
  int t  = vec3_equal_epsilon(u, v, 0.1f);

  assert_equal(t, 1);
  assert_equal(f, 0);
  assert_equal(ff, 0);
}
void test_vec3(){

  TEST_BANNER_START();
  
  test_vec3_make();
  test_vec3_make1();
  test_vec3_zero();
  test_vec3_negate();
  test_vec3_abs();
  test_vec3_sign();
  test_vec3_clampv();
  test_vec3_clampf();
  test_vec3_lerp();
  test_vec3_mulv();
  test_vec3_divv();
  test_vec3_addv();
  test_vec3_subv();
  test_vec3_minv();
  test_vec3_maxv();
  test_vec3_minf();
  test_vec3_maxf();
  test_vec3_length();
  test_vec3_normalize();
  test_vec3_dot();
  test_vec3_cross();
  test_vec3_equal();
  test_vec3_equal_epsilon();
}

//----------------------------------------
// vec4
//----------------------------------------

void test_vec4_make(){
  vec4 u = vec4_make(10, 20, 30, 40);
  assert_equal(u.x, 10);
  assert_equal(u.y, 20);
  assert_equal(u.z, 30);
  assert_equal(u.w, 40);
}
void test_vec4_make1(){
  vec4 u = vec4_make1(1);
  assert_equal(u.x, 1);
  assert_equal(u.y, 1);    
  assert_equal(u.z, 1);
  assert_equal(u.w, 1);
}
void test_vec4_zero(){
  vec4 u = vec4_zero();
    
  assert_equal(u.x, 0);
  assert_equal(u.y, 0);
  assert_equal(u.z, 0);
  assert_equal(u.w, 0);
}
void test_vec4_negate(){

  vec4 u = vec4_make(10, 20, 30, 40);
  assert_equal(u.x, 10);
  assert_equal(u.y, 20);
  assert_equal(u.z, 30);
  assert_equal(u.w, 40);

  vec4 v = vec4_negate(u);
  assert_equal(v.x, -10);
  assert_equal(v.y, -20);
  assert_equal(v.z, -30);
  assert_equal(v.w, -40);

  v = vec4_negate(v);
  assert_equal(v.x, 10);
  assert_equal(v.y, 20);
  assert_equal(v.z, 30);
  assert_equal(v.w, 40);
}
void test_vec4_abs(){

  vec4 u = vec4_make(-10, -20, -30, -40);
  assert_equal(u.x, -10);
  assert_equal(u.y, -20);
  assert_equal(u.z, -30);
  assert_equal(u.w, -40);

  vec4 v = vec4_abs(u);
  assert_equal(v.x, 10);
  assert_equal(v.y, 20);
  assert_equal(v.z, 30);
  assert_equal(v.w, 40);

}
void test_vec4_sign(){
  { 
    vec4 u = vec4_zero();
    vec4 v = vec4_sign(u);
    
    assert_equal(v.x, 1);
    assert_equal(v.y, 1);
    assert_equal(v.z, 1);
    assert_equal(v.w, 1);
  }
  { 
    vec4 u = vec4_make(10, -10, 10, -10);
    vec4 v = vec4_sign(u);

    assert_equal(v.x, 1);
    assert_equal(v.y, -1);
    assert_equal(v.z, 1);
    assert_equal(v.w, -1);

    u = vec4_negate(u);
    v = vec4_sign(u);

    assert_equal(v.x, -1);
    assert_equal(v.y, 1);
    assert_equal(v.z, -1);
    assert_equal(v.w, 1);
  }
}
void test_vec4_clampv(){

  vec4 v = vec4_clampv(vec4_make(10, 20, 30, 40),
                       vec4_make(-10, -20, -30, -40),
                       vec4_make(5, 2, 4, 3));

  assert_equal(v.x, 5.0);
  assert_equal(v.y, 2.0);
  assert_equal(v.z, 4);
  assert_equal(v.w, 3);
}
void test_vec4_clampf(){

  vec4 v = vec4_clampf(vec4_make(10, 20, 30, 40),
                       0,
                       5);

  assert_equal(v.x, 5);
  assert_equal(v.y, 5);
  assert_equal(v.z, 5);
  assert_equal(v.w, 5);
  
  v = vec4_clampf(vec4_make(-10, -20, -30, -40),
                  -20, 2);

  assert_equal(v.x, -10);
  assert_equal(v.y, -20);
  assert_equal(v.z, -20);
  assert_equal(v.w, -20);
  
}
void test_vec4_lerp(){

  
  vec4 v = vec4_lerp(vec4_make(-10, 10, 5, -5),
                     vec4_make(10, 20, 15, -15),
                     0.5);

  assert_equal(v.x, 0);
  assert_equal(v.y, 15);
  assert_equal(v.z, 10);
  assert_equal(v.w, -10);
  
}

void test_vec4_mulv(){

  vec4 u = vec4_make(-1, 2, -3, 4);
  vec4 v = vec4_make(10, 10, 10, 10);

  vec4 v0 = vec4_mulv(u, v);
  
  assert_equal(v0.x, -10);
  assert_equal(v0.y, 20);
  assert_equal(v0.z, -30);
  assert_equal(v0.w, 40);
  
}
void test_vec4_divv(){

  vec4 u = vec4_make(100, 100, 100, 100);
  vec4 v = vec4_make(2, 25, 50, 100);

  vec4 v0 = vec4_divv(u, v);
  
  assert_equal(v0.x, 50);
  assert_equal(v0.y, 4);
  assert_equal(v0.z, 2);
  assert_equal(v0.w, 1);
}
void test_vec4_addv(){
  vec4 u = vec4_make(10, 20, 30, 40);
  vec4 v = vec4_make(30, 40, 50, 60);

  vec4 v0 = vec4_addv(u, v);
  
  assert_equal(v0.x, 40);
  assert_equal(v0.y, 60);
  assert_equal(v0.z, 80);
  assert_equal(v0.w, 100);
}
void test_vec4_subv(){
  vec4 u = vec4_make(30, 60, 90, 120);
  vec4 v = vec4_make(10, 20, 30, 40);

  vec4 v0 = vec4_subv(u, v);
  
  assert_equal(v0.x, 20);
  assert_equal(v0.y, 40);
  assert_equal(v0.z, 60);
  assert_equal(v0.w, 80);
}
void test_vec4_minv(){
  vec4 u = vec4_make(30, 20, 10, 5);
  vec4 v = vec4_make(10, 70, 0, -10);

  vec4 v0 = vec4_minv(u, v);
  assert_equal(v0.x, 10);
  assert_equal(v0.y, 20);
  assert_equal(v0.z, 0);
  assert_equal(v0.w, -10);
}
void test_vec4_maxv(){
  vec4 u = vec4_make(30, 20, 50, 20);
  vec4 v = vec4_make(10, 70, 30, 40);

  vec4 v0 = vec4_maxv(u, v);
  assert_equal(v0.x, 30);
  assert_equal(v0.y, 70);
  assert_equal(v0.z, 50);
  assert_equal(v0.w, 40);
}
void test_vec4_minf(){
  vec4 u = vec4_make(10, 70, 5, -5);
  float f = vec4_minf(u);
  
  assert_equal(f, -5);
}
void test_vec4_maxf(){
  vec4 u = vec4_make(10, 70, 60, -5);
  float f = vec4_maxf(u);

  assert_equal(f, 70);
}
void test_vec4_length(){
  assert_equal(vec4_length(vec4_make(10, 0, 0, 0)), 10);
  assert_equal(vec4_length(vec4_make(-10, 0, 0, 0)), 10);

  assert_equal(vec4_length(vec4_make(0, 10, 0, 0)), 10);
  assert_equal(vec4_length(vec4_make(0, -10, 0, 0)), 10);

  assert_equal(vec4_length(vec4_make(0, 0, 10, 0)), 10);
  assert_equal(vec4_length(vec4_make(0, 0,-10, 0)), 10);

  assert_equal(vec4_length(vec4_make(0, 0, 0, 10)), 10);
  assert_equal(vec4_length(vec4_make(0, 0, 0, -10)), 10);
}
void test_vec4_normalize(){
  vec4 u = vec4_make(16, 0, 0, 0);
  vec4 v = vec4_normalize(u);

  assert_equal(v.x, 1);
  assert_equal(v.y, 0);
  assert_equal(v.z, 0);
  assert_equal(v.w, 0);
}
void test_vec4_equal(){
  vec4 u = vec4_make(8, 16, 32, 64);
  vec4 v = vec4_make(8, 4, 2, 1);

  int t = vec4_equal(u, u);
  int f = vec4_equal(u, v);

  assert_equal(t, 1);
  assert_equal(f, 0);
}
void test_vec4_equal_epsilon(){
  vec4 u = vec4_make(8, 16, 0, 0);
  vec4 v = vec4_make(8, 16.09f, 0, 0);

  int f  = vec4_equal(u, v);
  int ff = vec4_equal_epsilon(u, v, 0.01f);
  int t  = vec4_equal_epsilon(u, v, 0.1f);

  assert_equal(t, 1);
  assert_equal(f, 0);
  assert_equal(ff, 0);
}
void test_vec4(){

  TEST_BANNER_START();
  
  test_vec4_make();
  test_vec4_make1();
  test_vec4_zero();
  test_vec4_negate();
  test_vec4_abs();
  test_vec4_sign();
  test_vec4_clampv();
  test_vec4_clampf();
  test_vec4_lerp();
  test_vec4_mulv();
  test_vec4_divv();
  test_vec4_addv();
  test_vec4_subv();
  test_vec4_minv();
  test_vec4_maxv();
  test_vec4_minf();
  test_vec4_maxf();
  test_vec4_length();
  test_vec4_normalize();
  test_vec4_equal();
  test_vec4_equal_epsilon();
}

//----------------------------------------
// quaternion
//----------------------------------------

void test_quat_make(){
  quaternion q = quat_make(1,2,3,4);
  
  assert_equal(q.i, 1);
  assert_equal(q.j, 2);
  assert_equal(q.k, 3);
  assert_equal(q.a, 4);

  q = quat_make(10, 20, 30, 40);
  
  assert_equal(q.i, 10);
  assert_equal(q.j, 20);
  assert_equal(q.k, 30);
  assert_equal(q.a, 40);
}
void test_quat_make_identity(){
  quaternion q = quat_make_identity();
  assert_equal(q.i, 0);
  assert_equal(q.j, 0);
  assert_equal(q.k, 0);
  assert_equal(q.a, 1);
}
void test_quat_make_angle_axis(){
  quaternion q0 = quat_make_angle_axis(0,  vec3_make(1, 0, 0));
  assert_equal(q0.i, 0);
  assert_equal(q0.j, 0);
  assert_equal(q0.k, 0);
  assert_equal(q0.a, 1);

  assert_todo();
}
void test_quat_make_yaw_pitch_roll(){
  quaternion q0 = quat_make_yaw_pitch_roll(0, 0, 0);
  assert_equal(q0.i, 0);
  assert_equal(q0.j, 0);
  assert_equal(q0.k, 0);
  assert_equal(q0.a, 1);

  assert_todo();
}
void test_quat_img(){
  quaternion q = quat_make(1, 2, 3, 4);
  vec3 img = quat_img(q);

  assert_equal(img.x, q.i);
  assert_equal(img.y, q.j);
  assert_equal(img.z, q.k);
  
}
void test_quat_real(){
  quaternion q = quat_make(1, 2, 3, 4);

  float r = quat_real(q);
  assert_equal(r, q.a);
}

void test_quat_inverse(){
  quaternion q = quat_make_yaw_pitch_roll(0, 0, 0);
  q = quat_inverse(q);
  
  assert_equal(q.i, 0);
  assert_equal(q.j, 0);
  assert_equal(q.k, 0);
  assert_equal(q.a, 1);
}

void test_quat_mulq(){
  {
    quaternion q0 = quat_make_identity();
    quaternion q1 = quat_mulq(q0, q0);
    assert_equal(q0.i, q1.i);
    assert_equal(q0.j, q1.j);
    assert_equal(q0.k, q1.k);
    assert_equal(q0.a, q1.a);
  }
  {
    quaternion q0 = quat_make_angle_axis(0,  vec3_make(1, 0, 0));
    quaternion q1 = quat_make_angle_axis(PI, vec3_make(0, 1, 0));
    quaternion q2 = quat_mulq(q0, q1);

    quaternion r = {
      q0.k * q1.i + q2.i * q1.k + q2.j * q1.k - q2.k * q1.j,
      q0.k * q1.j - q2.i * q1.k + q2.j * q1.k + q2.k * q1.i,
      q0.k * q1.k + q2.i * q1.j - q2.j * q1.i + q2.k * q1.k,
      q0.k * q1.k - q2.i * q1.i - q2.j * q1.j - q2.k * q1.k
    };

    assert_todo();
    //assert_equal(q2.i, r.i);
    //assert_equal(q2.j, r.j);
    //assert_equal(q2.k, r.k);
    //assert_equal(q2.a, r.a);
  }
}
void test_quat_mulv(){
  quaternion q = quat_make_angle_axis(0,  vec3_make(1, 0, 0));
  vec3       u0 = vec3_make(1, 1, 1);
  vec3       u1 = quat_mulv(q, u0);

  
  assert_equal(u1.x, 1);
  assert_equal(u1.y, 1);
  assert_equal(u1.z, 1);    
}

void test_quaternion(){
  TEST_BANNER_START();
  
  test_quat_make();                
  test_quat_make_identity();       
  test_quat_make_angle_axis();     
  test_quat_make_yaw_pitch_roll();
  test_quat_img();
  test_quat_real();
  test_quat_inverse();             
  test_quat_mulq();                  
  test_quat_mulv();
}
//----------------------------------------
// mat4
//----------------------------------------
void test_mat4_make_cols(){
  mat4 m = mat4_make_cols(1, 2, 3, 4,
                          5, 6, 7, 8,
                          9, 10, 11, 12,
                          13, 14, 15, 16);

  assert_equal(1, vec4_equal(m.col_0, vec4_make(1, 2, 3, 4)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(5, 6, 7, 8)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(9, 10, 11, 12)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(13, 14, 15, 16)));
}
void test_mat4_make_rows(){

  mat4 m = mat4_make_rows(1, 5, 9, 13,
                          2, 6, 10, 14,
                          3, 7, 11, 15,
                          4, 8, 12, 16);

  assert_equal(1, vec4_equal(m.col_0, vec4_make(1, 2, 3, 4)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(5, 6, 7, 8)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(9, 10, 11, 12)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(13, 14, 15, 16)));

};
void test_mat4_make_identity(){
  mat4 m = mat4_make_identity();

  assert_equal(1, vec4_equal(m.col_0, vec4_make(1, 0, 0, 0)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(0, 1, 0, 0)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, 1, 0)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(0, 0, 0, 1)));
  
}
void test_mat4_transpose(){

  mat4 m = mat4_make_rows(1, 2, 3, 4,
                          5, 6, 7, 8,
                          9, 10, 11, 12,
                          13, 14, 15, 16);

  m = mat4_transpose(m);
  
  assert_equal(1, vec4_equal(m.col_0, vec4_make(1, 2, 3, 4)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(5, 6, 7, 8)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(9, 10, 11, 12)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(13, 14, 15, 16)));
}

void test_mat4_mulm(){
  mat4 m0 = mat4_make_rows(1, 2, 3, 4,
                           5, 6, 7, 8,
                           9, 10, 11, 12,
                           13, 14, 15, 16);
  
  mat4 m1 = mat4_make_rows(17, 18, 19, 20,
                           21, 22, 23, 24,
                           25, 26, 27, 28,
                           29, 30, 31, 32);
  
  mat4 m = mat4_mulm(m0, m1);
  
  assert_equal(1, vec4_equal(m.col_0, vec4_make(250, 618, 986, 1354)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(260, 644, 1028, 1412)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(270, 670, 1070, 1470)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(280, 696, 1112, 1528)));
}
void test_mat4_mulv(){
  mat4 m = mat4_scale(2, 4, 8);

  vec4 u = vec4_make(1, 2, 3, 1);
  vec4 v = mat4_mulv(m, u);

  assert_equal(1, vec4_equal(v, vec4_make(2, 8, 24, 1)));
}
void test_mat4_translate(){
  mat4 m = mat4_translate(10, 20, 30);
  
  assert_equal(1, vec4_equal(m.col_0, vec4_make(1, 0, 0, 0)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(0, 1, 0, 0)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, 1, 0)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(10, 20, 30, 1)));
}
void test_mat4_translatev(){
  mat4 m = mat4_translatev(vec3_make(10, 20, 30));
  
  assert_equal(1, vec4_equal(m.col_0, vec4_make(1, 0, 0, 0)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(0, 1, 0, 0)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, 1, 0)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(10, 20, 30, 1)));
}
void test_mat4_scale(){
  const float x = 10;
  const float y = 20;
  const float z = 30;
  
  mat4 m = mat4_scale(x, y, z);
  
  assert_equal(1, vec4_equal(m.col_0, vec4_make(x, 0, 0, 0)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(0, y, 0, 0)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, z, 0)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(0, 0, 0, 1)));
}
void test_mat4_scalef(){
  const float s = 10;
  mat4 m = mat4_scalef(s);
  
  assert_equal(1, vec4_equal(m.col_0, vec4_make(s, 0, 0, 0)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(0, s, 0, 0)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, s, 0)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(0, 0, 0, 1)));
}
void test_mat4_scalev(){
  const float x = 10;
  const float y = 20;
  const float z = 30;
  
  mat4 m = mat4_scalev(vec3_make(x, y, z));
  
  assert_equal(1, vec4_equal(m.col_0, vec4_make(x, 0, 0, 0)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(0, y, 0, 0)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, z, 0)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(0, 0, 0, 1)));

}
void test_mat4_rot_x(){
  mat4 m = mat4_rot_x(PI);
  assert_todo();
}
void test_mat4_rot_y(){
  mat4 m = mat4_rot_y(PI);
  assert_todo();
}
void test_mat4_rot_z(){
  mat4 m = mat4_rot_z(PI);
  assert_todo();
}
void test_mat4_rot(){
  assert_todo();
}
void test_mat4_ts(){
  const float px = 1;
  const float py = 2;
  const float pz = 3;

  const float x = 10;
  const float y = 20;
  const float z = 30;
  
  mat4 m = mat4_ts(vec3_make(px, py, pz),
                   vec3_make(x, y, z));
  
  assert_equal(1, vec4_equal(m.col_0, vec4_make(x, 0, 0, 0)));
  assert_equal(1, vec4_equal(m.col_1, vec4_make(0, y, 0, 0)));
  assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, z, 0)));
  assert_equal(1, vec4_equal(m.col_3, vec4_make(px, py, pz, 1)));
}
void test_mat4_trs(){
  {
    mat4 m = mat4_trs(vec3_make(0, 0, 0),
                      quat_make_identity(),
                      vec3_make(1,1,1));
  
    assert_equal(1, vec4_equal(m.col_0, vec4_make(1, 0, 0, 0)));
    assert_equal(1, vec4_equal(m.col_1, vec4_make(0, 1, 0, 0)));
    assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, 1, 0)));
    assert_equal(1, vec4_equal(m.col_3, vec4_make(0, 0, 0, 1)));
  }
  {
    mat4 m = mat4_trs(vec3_make(10, 20, 30),
                      quat_make_identity(),
                      vec3_make(1,2,3));
  
    assert_equal(1, vec4_equal(m.col_0, vec4_make(1, 0, 0, 0)));
    assert_equal(1, vec4_equal(m.col_1, vec4_make(0, 2, 0, 0)));
    assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, 3, 0)));
    assert_equal(1, vec4_equal(m.col_3, vec4_make(10, 20, 30, 1)));
  }
  assert_todo();
}
void test_mat4_rts(){
    {
    mat4 m = mat4_trs(vec3_make(0, 0, 0),
                      quat_make_identity(),
                      vec3_make(1,1,1));
  
    assert_equal(1, vec4_equal(m.col_0, vec4_make(1, 0, 0, 0)));
    assert_equal(1, vec4_equal(m.col_1, vec4_make(0, 1, 0, 0)));
    assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, 1, 0)));
    assert_equal(1, vec4_equal(m.col_3, vec4_make(0, 0, 0, 1)));
  }
  {
    mat4 m = mat4_trs(vec3_make(10, 20, 30),
                      quat_make_identity(),
                      vec3_make(1,2,3));
  
    assert_equal(1, vec4_equal(m.col_0, vec4_make(1, 0, 0, 0)));
    assert_equal(1, vec4_equal(m.col_1, vec4_make(0, 2, 0, 0)));
    assert_equal(1, vec4_equal(m.col_2, vec4_make(0, 0, 3, 0)));
    assert_equal(1, vec4_equal(m.col_3, vec4_make(10, 20, 30, 1)));
  }
  assert_todo();
}
void test_mat4_ortho_lh(){assert_todo();}
void test_mat4_ortho_rh(){assert_todo();}
void test_mat4_perspective_lh(){assert_todo();}
void test_mat4_perspective_rh(){assert_todo();}
void test_mat4_look_at(){assert_todo();}

void test_mat4(){
  TEST_BANNER_START();
  
  test_mat4_make_cols();
  test_mat4_make_rows();
  test_mat4_make_identity();
  test_mat4_transpose();
  test_mat4_mulm();
  test_mat4_mulv();
  test_mat4_translate();
  test_mat4_translatev();
  test_mat4_scale();
  test_mat4_scalef();
  test_mat4_scalev();
  test_mat4_rot_x();
  test_mat4_rot_y();
  test_mat4_rot_z();
  test_mat4_rot();
  test_mat4_ts();
  test_mat4_trs();
  test_mat4_rts();
  test_mat4_ortho_lh();
  test_mat4_ortho_rh();
  test_mat4_perspective_lh();
  test_mat4_perspective_rh();
  test_mat4_look_at();
}
int main(int argc, const char* argv[]){
    
  test_common();
  test_vec2();
  test_vec3();
  test_vec4();
  test_quaternion();
  test_mat4();
  
  printf("\ndone\n");
  printf("assertions: %d\n", assert_count);
  return 0;
}
