#include <stdio.h>
#include <emscripten/emscripten.h>

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

//EXTERN void myFunction(int argc, char ** argv) {
EXTERN EMSCRIPTEN_KEEPALIVE int myFunction(int x) {
    printf("MyFunction Called(%d)\n", x);
    return x;
}
