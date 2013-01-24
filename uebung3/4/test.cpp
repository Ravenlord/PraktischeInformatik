/* 
 * File:   test.cpp
 * Author: Elisabeth Lang
 * Author: Richard Fussenegger
 * Author: Markus Deutschl
 *
 * Created on December 1, 2012, 16:30 PM
 */

#include <iostream>
#include <cassert>
#include "skiplist.h"

using namespace std;

int main() {
    /** Iterator and random key variable. */
    unsigned i = 0;

    cout << "Skiplist Unit Test" << endl;
    for (i = 0; i < 80; ++i) {
        cout << "-";
    }
    cout << endl;

    cout << "Creating new skiplist..." << endl;
    skiplist<int, int> skiplistObj(5);

    // Should return 2 with key 67, value was inserted.
    cout << "Inserting value 2 with key 67." << endl;
    skiplistObj.insert(67, 2);
    int skipValue = skiplistObj.search(67);
    assert(skipValue == 2);
    cout << "True - Value 2 was inserted correctly with key 67." << endl;

    // Inserting 4 new values.
    cout << "Inserting keys 83, 27, 91 and 12." << endl;
    skiplistObj.insert(83, 6);
    skiplistObj.insert(27, 9);
    skiplistObj.insert(91, 3);
    skiplistObj.insert(12, 8);

    // Two new arrays with keys and values in the right order.
    int newKeys[5];
    newKeys[0] = 12;
    newKeys[1] = 27;
    newKeys[2] = 67;
    newKeys[3] = 83;
    newKeys[4] = 91;

    // Get vector of keys.
    vector<int> skiplistKeys = skiplistObj.getKeyVector();

    // Are the sorted array and the keys list equal?
    cout << "Check whole array if keys equal with sorted array." << endl;
    for (i = 0; i < skiplistKeys.size(); ++i) {
        assert(newKeys[i] == skiplistKeys[i]);
    }
    cout << "True - All keys are equal." << endl;

    // Inserting negative key.
    skiplistObj.insert(-2, -4);
    skiplistKeys = skiplistObj.getKeyVector();

    cout << "Check if negative key is first in list." << endl;
    assert(skiplistKeys[0] == -2);
    cout << "True - Negative key is first in list." << endl;

    return 0;
}
