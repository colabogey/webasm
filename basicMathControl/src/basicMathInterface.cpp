/* Copyright 2022-Present Steve Yackey

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <externDef.h>
#include <basicMath.h>
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


