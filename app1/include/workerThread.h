#pragma once
#include <functional>
#include <thread>
#include <string>

// TODO: make the string be const ?
//
typedef std::function<void(std::string&)> workerThreadFunc_t;

class workerThread {
  public:
    workerThread(std::string&, workerThreadFunc_t f);
    workerThread() = delete;
    virtual ~workerThread() = default;
    void func();
    std::string getName();

  private:
    workerThreadFunc_t m_f;
    std::thread m_t;
    std::string m_myThreadName;
};
