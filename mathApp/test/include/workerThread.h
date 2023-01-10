#pragma once
#include <functional>
#include <string>
#include <thread>

// TODO: make the string be const ?
//
typedef std::function<void(int, std::string &)> workerThreadFunc_t;

class workerThread {
  public:
    workerThread(int, std::string &, workerThreadFunc_t f);
    workerThread() = delete;
    virtual ~workerThread() = default;
    void func();
    void workerJoin();
    std::string getName();

    std::thread m_t;
  private:
    workerThreadFunc_t m_f;
    int m_howMany;
    std::string m_myThreadName;
};
