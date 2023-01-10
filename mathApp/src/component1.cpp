#include <externDef.h>
#include <stdio.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <emscripten/emscripten.h>

int z = 0;
int former_main(int);

EXTERN EMSCRIPTEN_KEEPALIVE 
int myFunction(int x) {
//int myFunction(int x) {
    printf("MyFunction Called(%d)\n", x);
    former_main(27);
    exit(0);
}


int former_main(int x) {
    //puts("Before the thread");
    std::cout << "Before the thread - " << z << std::endl;

//    std::thread thread([&]() {
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        std::cout << "Inside the thread: " << x << std::endl;
//    });

//    thread.join();

    std::cout << "After the thread" << std::endl;

    return 0;
}
