#include <stdio.h>

#define N1_CMATH_IMPLEMENTATION
#include "n1_cmath.h"

#define assert(expression) {if(!(expression)){printf("assertion failed '%s' at line %d.\n", __func__, __LINE__); *(int*)NULL = 0;}}

#define assert_equals(a, b) {if(!((a) == (b))){printf("assertion failed '%s' at line %d.\n", __func__, __LINE__); *(int*)NULL = 0;}}

void test_clampf(){
  assert_equals(clampf(0, -10, 10),
                0);

  assert_equals(clampf(-20, -10, 10),
                -10);
  
  assert_equals(clampf(20, -10, 10),
                10);
}
void test_lerpf(){
  assert_equals(lerpf(-10, 10, 0.5f),
                0);

  assert_equals(lerpf(-10, 10, 0),
                -10);

  assert_equals(lerpf(-10, 10, 1),
                10);

  assert_equals(lerpf(-10, 10, 2),
                30);
}

void test_common(){
  test_clampf();
  test_lerpf();
  printf("pass test_common()\n");
}
// vec2 
void test_vec2_make(){
  {
    vec2 u = vec2_make(10, 20);
    assert_equals(u.x, 10);
    assert_equals(u.y, 20);    
  }
  {
    vec2 u = vec2_make1(10);
    assert_equals(u.x, 10);
    assert_equals(u.y, 10);    
  }
}
void test_vec2_make1(){
  {
    vec2 u = vec2_make1(0);
    assert_equals(u.x, 0);
    assert_equals(u.y, 0);    
  }
  {
    vec2 u = vec2_make1(1);
    assert_equals(u.x, 1);
    assert_equals(u.y, 1);    
  }
}
void test_vec2_zero(){
  vec2 u = vec2_make1(1);
  u = vec2_zero();
    
  assert_equals(u.x, 0);
  assert_equals(u.y, 0);    
}
void test_vec2_negate(){
  {
    vec2 u = vec2_make(10, 20);
    assert_equals(u.x, 10);
    assert_equals(u.y, 20);

    vec2 v = vec2_negate(u);
    assert_equals(v.x, -10);
    assert_equals(v.y, -20);
  }
  {
    vec2 u = vec2_make(-10, -20);
    assert_equals(u.x, -10);
    assert_equals(u.y, -20);

    vec2 v = vec2_negate(u);
    assert_equals(v.x, 10);
    assert_equals(v.y, 20);
  }
}
void test_vec2_abs(){
  {
    vec2 u = vec2_make(-10, -20);
    assert_equals(u.x, -10);
    assert_equals(u.y, -20);

    vec2 v = vec2_abs(u);
    assert_equals(v.x, 10);
    assert_equals(v.y, 20);
  }
}
void test_vec2_sign(){
  { 
    vec2 u = vec2_make(0, 0);
    assert_equals(u.x, 0);
    assert_equals(u.y, 0);

    vec2 v = vec2_sign(u);
    assert_equals(v.x, 1);
    assert_equals(v.y, 1);
  }
  { 
    vec2 u = vec2_make(10, -10);
    assert_equals(u.x, 10);
    assert_equals(u.y, -10);

    vec2 v = vec2_sign(u);
    assert_equals(v.x, 1);
    assert_equals(v.y, -1);
  }
  { 
    vec2 u = vec2_make(-10, 10);
    assert_equals(u.x, -10);
    assert_equals(u.y, 10);

    vec2 v = vec2_sign(u);
    assert_equals(v.x, -1);
    assert_equals(v.y, 1);
  }
}
void test_vec2_clampv(){
  {
    vec2 v = vec2_clampv(vec2_make(10, 20),
                         vec2_make(-10, -20),
                         vec2_make(5, 2));

    assert_equals(v.x, 5.0);
    assert_equals(v.y, 2.0);
    
  }

  {
    vec2 v = vec2_clampv(vec2_make(-100, 20),
                         vec2_make(-10, 0),
                         vec2_make(5, 100));

    assert_equals(v.x, -10);
    assert_equals(v.y, 20);
  }
}
void test_vec2_clampf(){
  {
    vec2 v = vec2_clampf(vec2_make(10, 20),
                         0, 5);

    assert_equals(v.x, 5);
    assert_equals(v.y, 5);
  }

  {
    vec2 v = vec2_clampf(vec2_make(-100, 20),
                         -10, 10);

    assert_equals(v.x, -10);
    assert_equals(v.y, 10);
  }
}
void test_vec2_lerp(){

  {
    vec2 v = vec2_lerp(vec2_make(-10, 10),
                       vec2_make(10, 20),
                       0);

    assert_equals(v.x, -10);
    assert_equals(v.y, 10);
  }
  {
    vec2 v = vec2_lerp(vec2_make(-10, 10),
                       vec2_make(10, 20),
                       0.5f);

    assert_equals(v.x, 0);
    assert_equals(v.y, 15);
  }
  {
    vec2 v = vec2_lerp(vec2_make(-10, 10),
                       vec2_make(10, 20),
                       1.0);

    assert_equals(v.x, 10);
    assert_equals(v.y, 20);
  }
}

void test_vec2_mulv(){assert(0);}
void test_vec2_divv(){assert(0);}
void test_vec2_addv(){assert(0);}
void test_vec2_subv(){assert(0);}
void test_vec2_minv(){assert(0);}
void test_vec2_maxv(){assert(0);}
void test_vec2_minf(){assert(0);}
void test_vec2_maxf(){assert(0);}
void test_vec2_length(){assert(0);}
void test_vec2_normalize(){assert(0);}
void test_vec2_normal(){assert(0);}
void test_vec2_dot(){assert(0);}
void test_vec2_cross(){assert(0);}
void test_vec2_equals(){assert(0);}
void test_vec2_equals_epsilon(){assert(0);}

void test_vec2(){

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
  test_vec2_equals();
  test_vec2_equals_epsilon();
  
  printf("pass test_vec2()\n");
}

// vec3
void test_vec3_make(){assert(0);}
void test_vec3_make1(){assert(0);}
void test_vec3_zero(){assert(0);}
void test_vec3_negate(){assert(0);}
void test_vec3_abs(){assert(0);}
void test_vec3_sign(){assert(0);}
void test_vec3_clampv(){assert(0);}
void test_vec3_clampf(){assert(0);}
void test_vec3_lerp(){assert(0);}
void test_vec3_mulv(){assert(0);}
void test_vec3_divv(){assert(0);}
void test_vec3_addv(){assert(0);}
void test_vec3_subv(){assert(0);}
void test_vec3_minv(){assert(0);}
void test_vec3_maxv(){assert(0);}
void test_vec3_minf(){assert(0);}
void test_vec3_maxf(){assert(0);}
void test_vec3_length(){assert(0);}
void test_vec3_normalize(){assert(0);}
void test_vec3_normal(){assert(0);}
void test_vec3_dot(){assert(0);}
void test_vec3_cross(){assert(0);}
void test_vec3_equals(){assert(0);}
void test_vec3_equals_epsilon(){assert(0);}
  
void test_vec3(){

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
  test_vec3_normal();
  test_vec3_dot();
  test_vec3_cross();
  test_vec3_equals();
  test_vec3_equals_epsilon();
  
  printf("pass test_vec3()\n");
}
int main(int argc, const char* argv[]){
  printf("Hello sailor\n");
  
  test_common();
  test_vec2();
  test_vec3();

  printf("done\n");
  return 0;
}
