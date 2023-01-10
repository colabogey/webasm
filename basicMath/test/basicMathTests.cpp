#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <functional>
#include <basicMath.h>

using namespace std;

// The fixture for testing
class BasicMathTest : public ::testing::Test {

  protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    BasicMathTest() {
        // You can do set-up work for each test here.
    }

    virtual ~BasicMathTest() {}

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

TEST_F(BasicMathTest, BasicMath_AddTwoInts_ExpectSum) {
    // arrange
    int a = 3;
    int b = 5;
    unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    // act
    int result = bmp->add(a, b);
    // assert
    ASSERT_EQ(result, (a + b));
}

TEST_F(BasicMathTest, BasicMath_SubtractTwoInts_ExpectPositiveDifference) {
    // arrange
    int a = 7;
    int b = 5;
    unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    // act
    int result = bmp->subtract(a, b);
    // assert
    ASSERT_EQ(result, (a - b));
}

TEST_F(BasicMathTest, BasicMath_SubtractTwoInts_ExpectNegativeDifference) {
    // arrange
    int a = 3;
    int b = 5;
    unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    // act
    int result = bmp->subtract(a, b);
    // assert
    ASSERT_EQ(result, (a - b));
}

TEST_F(BasicMathTest, BasicMath_MultiplytTwoInts_ExpectProduct) {
    // arrange
    int a = 3;
    int b = 5;
    unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    // act
    int result = bmp->multiply(a, b);
    // assert
    ASSERT_EQ(result, (a * b));
}

TEST_F(BasicMathTest, BasicMath_DivideTwoInts_NeitherZero_ExpectQuotient) {
    // arrange
    int a = 4;
    int b = 2;
    unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    // act
    int result = bmp->divide(a, b);
    // assert
    ASSERT_EQ(result, (a / b));
}

TEST_F(BasicMathTest, BasicMath_DivideTwoInts_NeitherZero_ExpectZero) {
    // arrange
    int a = 2;
    int b = 4;
    unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    // act
    int result = bmp->divide(a, b);
    // assert
    ASSERT_EQ(result, 0);
}

TEST_F(BasicMathTest, BasicMath_DivideTwoInts_DivisorZero_ExpectZero) {
    // arrange
    int a = 2;
    int b = 0;
    unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    // act
    int result = bmp->divide(a, b);
    // assert
    ASSERT_EQ(result, 0);
}

TEST_F(BasicMathTest, BasicMath_DivideTwoInts_DividendZero_ExpectZero) {
    // arrange
    int a = 0;
    int b = 6;
    unique_ptr<basicMath> bmp = std::make_unique<basicMath>();
    // act
    int result = bmp->divide(a, b);
    // assert
    ASSERT_EQ(result, 0);
}

