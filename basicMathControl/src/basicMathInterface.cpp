#include <externDef.h>
#include <basicMath.h>
#include <stdio.h>
#include <functional>
#include <emscripten/emscripten.h>

EXTERN EMSCRIPTEN_KEEPALIVE 
int basicMathAdd(int a, int b) {
    std::unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    return bmp->add(a, b);
}

EXTERN EMSCRIPTEN_KEEPALIVE 
int basicMathSubtract(int a, int b) {
    std::unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    return bmp->subtract(a, b);
}

EXTERN EMSCRIPTEN_KEEPALIVE 
int basicMathMultiply(int a, int b) {
    std::unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    return bmp->multiply(a, b);
}

EXTERN EMSCRIPTEN_KEEPALIVE 
int basicMathDivide(int a, int b) {
    std::unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    return bmp->divide(a, b);
}


