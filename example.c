#include "kappalib.h"



typedef struct Circle {
double x, y;
double radius;
void (*move) (struct Circle *self ,double dx, double dy);
double (*perimeter) (struct Circle *self );
double (*area) (struct Circle *self );
}Circle;

double area(struct Circle *self ){
return 3.14 * (pow(self->radius, 2));
};

double perimeter(struct Circle *self ){
return 2 * 3.14 * self->radius;
};

void move(struct Circle *self ,double dx, double dy){
self->x = self->x + dx;
self->y = self->y + dx;
};

Circle ctor_Circle = {.move = move,.perimeter = perimeter,.area = area};

double pi = 3.14152;
int test2 = 0;
int test3 = 1;
double i, j;
char* s1, s2;
int n1;
double x, y;
char* s, ss;
int test;
double grades[5];
char* directions[4];
char** test4;

void test(char* promt, char* msg){
int n1;
double x, y;
if (n1 == 1){
x = x + 1;
x = x - 7;
}else{
x = x + y;
x = x + 3;
}
if (n1 == 1){
x = x + 1;
};
int* new_array = (int*)malloc(5 * sizeof(int)); 
for (int elm = 0; elm < 5; ++elm){
new_array[elm] = x + 5;
}
for (int x = 1 ; x < 5 ; x += 1){
x = x + 3;
}
double* half = (double*)malloc(100 * sizeof(double)); 
for (int array_i = 0; array_i < 100; ++array_i){
half[array_i] = a[array_i];
}
}

ctor_int test2(char* promt, char* msg){
int n1;
double x, y;
while (x + 2 < 5){
x = x + 1;
y = x - 1;
}
break;
continue;


readStr();
readInteger();
return;
return x + 4;
return 1;
}

void main() {
a = b + 1;

}
