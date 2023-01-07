#include <externDef.h>
#include <unistd.h>
#include <iostream>
#include <emscripten/emscripten.h>

//int myFunction(int);
EXTERN EMSCRIPTEN_KEEPALIVE
int main() {
    /*
    puts("Before the thread");

    int arg = 42;
    std::thread thread([&]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Inside the thread: " << arg << std::endl;
    });

    thread.join();

    std::cout << "After the thread" << std::endl;
    */

    std::cout << "main" << std::endl;
    return 0;
}
