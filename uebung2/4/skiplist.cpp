/* 
 * File:   test.cpp
 * Author: Richard Fussenegger
 * Author: Markus Deutschl
 *
 * Created on November 19, 2012, 10:50 PM
 */

#include <iostream>
#include "skiplist.h"

using namespace std;

int main() {
    /** Iterator and random key variable. */
    int i = 0, randKey;

    /** Our skiplist to test. */
    skiplist<int, int> skiplistObj(5);

    // Fill something into our skiplist.
    for (; i < 10; ++i) {
        randKey = rand() % 100;
        skiplistObj.insert(randKey, i);
        cout << "Inserted key " << randKey << " with value " << i << "." << endl;
    }

    // Show me!
    skiplistObj.print();

    return 0;
}