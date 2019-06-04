#include "readint.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
using namespace std;

TEST(ReadIntTest, zeroinput) {
    // Open a file stream to read the file zeroinput.txt (remember CS-172)
    // Replace "UnitTester" with the name of your Native Unit Test project
        ifstream ss("tests\\zeroinput.txt");

    // Check if we opened the file stream successfully
        if (ss.fail())
            throw int(-1); // throw an integer with value -1

    // Replace the cin read buffer with the read buffer from the file stream 
        streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

    // Perform the read_int() test.
    // cin will now read from your file and not from the keyboard.
    // We expect the correct value returned is 0, ignoring the Hello string.
    ASSERT_EQ(read_int("My prompt: ", -3, 3), 0);

    // Close the file stream
        ss.close();
}


TEST(ReadIntTest, InvalidArg1) {
    auto func = []() { 
        // call with incorrect arguments (test case 2)
        read_int("My prompt: ", 5, 1);
    };

    ASSERT_THROW(func(), std::invalid_argument);
}

TEST(ReadIntTest, threeinput) {
    // Replace "UnitTester" with the name of your Native Unit Test project
        ifstream ss("tests\\threeinput.txt");

    // Check if we opened the file stream successfully
        if (ss.fail())
            throw int(-1); // throw an integer with value -1

    // Replace the cin read buffer with the read buffer from the file stream 
        streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

    // Perform the read_int() test.
    // cin will now read from your file and not from the keyboard.
    // We expect the correct value returned is 3
    ASSERT_EQ(read_int("My prompt: ", 0, 4), 3);

    // Close the file stream
        ss.close();
}

TEST(ReadIntTest, InvalidArg2) {
    auto func = []() { 
        // call with incorrect arguments (test case 4)
        read_int("My prompt: ", 0, 0);
    };

    ASSERT_THROW(func(), std::invalid_argument);
}


int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

/*


Test case 1: If read_int(“My prompt: ”, -3, 3) AND input is “Hello\n0” 
	Expect 0 will be returned by the function
	
Test case 2: If read_int(“My prompt: ”, 5, 1) 
	Expect invalid_argument exception will be thrown
	
	Test case 3: If read_int(“My prompt: ”, 0, 4) AND input is “-3\n5\n10\n-2\n3”
	Expect 3 will be returned by the function

Test case 4: If read_int(“My prompt: ”, 0, 0) 
	Expect invalid_argument exception will be thrown

*/