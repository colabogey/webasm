# webasm
## research into using webassembly

Basically,
- a C++ class that does basic math
- the class lives in an archive library
- export functions access the class members
  - simply creates a unique_ptr and accesses the object
  - these use the KEEP_ALIVE tag
- build creates client side and server side js
  - server side uses MODULARIZE
- html files use client side js and uses
  - ccall
  - cwrap
  - the so called streaming method that uses the wasm file directly
- server side includes additions
  - to call ccall
  - runnable via node.js
