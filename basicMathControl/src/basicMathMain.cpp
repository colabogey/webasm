#include <externDef.h>
#include <stdio.h>
#include <emscripten/emscripten.h>

EXTERN EMSCRIPTEN_KEEPALIVE
int main() {
    printf("main\n");

    return 0;
}
