#include <thread>
#include <string>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <workerThread.h>

workerThread::workerThread(std::string& myThreadName, 
                           std::function<void(std::string&)> f) {
    m_f = f;
    m_myThreadName = myThreadName;
}

void workerThread::func() {
    //m_t = std::move(std::thread([=, this]() {
    m_t = std::thread([=, this]() {
        m_f(m_myThreadName);
        return 1;
    });
    //}));
    m_t.detach();
}

std::string workerThread::getName() {
    return m_myThreadName;
}

