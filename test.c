#include "kappalib.h"
#include "assert.h"

#define typename(x) _Generic((x), \
    int:     "int", \
    double:   "double", \
    float:   "float", \
    char*:   "char*", \
    default: "other")

int main(void) {
    double i;
    char* s1;
    int n1;
    double x;
    char* s;
    int test;
    double grades[5];
    char* directions[4];
}