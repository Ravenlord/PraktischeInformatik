/* 
 * File:   main.cpp
 * Author: Richard Fussenegger <rfussenegger.mmt-m2012@fh-salzburg.ac.at>
 * Author: Markus Deutschl <mdeutschl.mmt-m2012@fh-salzburg.ac.at>
 * Created on December 17, 2012, 4:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>
#include "CircularBuffer.h"

using namespace std;

/**
 * Size of the test CircularBuffer.
 */
#define TEST_SIZE 10

/**
 * Data type to use with the test CircularBuffer.
 */
typedef unsigned CIRCULAR_BUFFER_TYPE;

/**
 * Print a nice separator on the console.
 */
void printSeparator() {
    for (int i = 0; i < 80; i++) {
        cout << "-";
    }
    cout << endl;
}

/**
 * Helper method to print test output.
 *
 * @param testName
 *   The name of the test case.
 * @param testOutput
 *   The output of the test case.
 */
void printTest(string testName, string testOutput) {
    cout << "Starting " << testName << " Test:" << endl;
    printSeparator();
    cout << testOutput;
    printSeparator();
    cout << endl;
}

/**
 * Test CircularBuffer's write method.
 */
void testWrite() {
    CircularBuffer<CIRCULAR_BUFFER_TYPE> cb(TEST_SIZE);
    ostringstream stream;
    for (unsigned i = 0; i < TEST_SIZE; i++) {
        stream << "Writing " << i << " to CircularBuffer." << endl;
        cb.write(i);
    }
    printTest("Write", stream.str());
}

/**
 * Test CircularBuffer's read method.
 */
void testRead() {
    CircularBuffer<CIRCULAR_BUFFER_TYPE> cb(TEST_SIZE);
    unsigned i;
    ostringstream stream;

    // Fill CircularBuffer instance with values.
    for (i = 0; i < TEST_SIZE; i++) {
        cb.write(i);
    }

    // Print all inserted values to console.
    for (i = 0; i < TEST_SIZE; i++) {
        stream << "Reading " << cb.read() << " from CircularBuffer." << endl;
    }

    // Test if empty CircularBuffer returns correct default value.
    CIRCULAR_BUFFER_TYPE readValue = cb.read();
    stream << "Reading value " << readValue << " from empty CircularBuffer." << endl;
    assert(readValue == INT_MAX);

    printTest("Read", stream.str());
}

/**
 * Test CircularBuffer's write method overflow handling.
 */
void testWriteOverflow() {
    CircularBuffer<CIRCULAR_BUFFER_TYPE> cb(TEST_SIZE);
    ostringstream stream;

    // Write more values than the CircularBuffer has slots.
    for (unsigned i = 0; i <= TEST_SIZE; i++) {
        stream << "Writing " << i << " to CircularBuffer." << endl;
        cb.write(i);
    }

    // Check if the last value is now the second value we've inserted.
    CIRCULAR_BUFFER_TYPE lastRead = cb.read();
    stream << "Reading last value " << lastRead << " from CircularBuffer." << endl;
    assert(lastRead == 1);

    printTest("Write Overflow", stream.str());
}

/**
 * Test if newly created CircularBuffer returns correct value for emptiness.
 */
void testReadEmpty() {
    CircularBuffer<CIRCULAR_BUFFER_TYPE> cb(TEST_SIZE);

    CIRCULAR_BUFFER_TYPE readValue = cb.read();
    ostringstream stream;
    stream << "Reading value " << readValue << " from newly created CircularBuffer instance." << endl;
    assert(readValue == INT_MAX);

    printTest("Read Empty", stream.str());
}

/**
 * Test if implemented self checks work correctly.
 */
void testSelfChecks() {
    CircularBuffer<CIRCULAR_BUFFER_TYPE> cbOther(TEST_SIZE);
    unsigned i = 0;

    // Fill CircularBuffer instance with values.
    for (i = 0; i < TEST_SIZE; i++) {
        cbOther.write(i);
    }

    // Call copy and assignment of CircularBuffer and delete original instance.
    CircularBuffer<CIRCULAR_BUFFER_TYPE> cbCopy(cbOther);
    CircularBuffer<CIRCULAR_BUFFER_TYPE> cbAssign = cbOther;

    // Change values of our copy and assigned CircularBuffer.
    for (i = 0; i < TEST_SIZE; i++) {
        cbCopy.write(i + 10);
        cbAssign.write(i + 20);
    }

    // Test if copy worked correctly.
    assert(cbCopy.read() == 10);

    // Test assignment.
    assert(cbAssign.read() == 20);
}

/**
 * Main method including tests of our CircularBuffer.
 *
 * @return
 *   Always returns EXIT_SUCCESS.
 */
int main() {
    testWrite();
    testRead();
    testWriteOverflow();
    testReadEmpty();
    testSelfChecks();
    return EXIT_SUCCESS;
}