#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <functional>
#include <workEngine.h>

using namespace std;

// The fixture for testing
class WebasmTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    WebasmTest() {
        // You can do set-up work for each test here.
    }

    virtual ~WebasmTest() {}

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
        //
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    // Objects declared here can be used by all tests.
    //

};

TEST_F(WebasmTest, WaitableThreadGetName) {
    // arrange
    int a = 4;
    int x = 2;
    std::unique_ptr<workEngine> e = std::make_unique<workEngine>(x);
    // act
    e->start();
    std::string s = e->result();
    // assert
    ASSERT_EQ(a, 4);
}

