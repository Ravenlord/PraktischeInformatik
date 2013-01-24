/* 
 * File:   main.cpp
 * Author: Richard Fussenegger <rfussenegger.mmt-m2012@fh-salzburg.ac.at>
 * Author: Markus Deutschl <mdeutschl.mmt-m2012@fh-salzburg.ac.at>
 * Author: Elisabeth Lang <elang.mmt-m2012@fh-salzburg.ac.at>
 * Created on December 28, 2012, 9:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "CacheSimulator.h"

using namespace std;

/**
 * Print a nice separator on the console.
 */
void printSeparator() {
    cout << endl;
    for (int i = 0; i < 80; i++) {
        cout << "-";
    }
    cout << endl;
}

/**
 * Main method including tests of our CircularBuffer.
 *
 * @return
 *   Always returns EXIT_SUCCESS.
 */
int main(int argc, const char* argv[]) {
    // TODO: Maybe we should create a base class CacheSimulator and two child classes. One for the
    // InstructionCacheSimulator (only reading instructions) and one for the DataCacheSimulator (
    // only reading data)?
    CacheSimulator iCache(4096, DIRECT_MAPPED, 32);
    //InstructionCacheSimulator iCache(4096, DIRECT_MAPPED, 32);

    printSeparator();
    cout << "Instruction Cache:" << endl << iCache.getConfiguration();

    CacheSimulator dCache(256 * 1024, FULLY_ASSOCIATIVE, 32);
    //DataCacheSimulator dCache(256 * 1024, FULLY_ASSOCIATIVE, 32);
    dCache.setAssociativityLevel(4);

    printSeparator();
    cout << "Data Cache:" << endl << dCache.getConfiguration();
    printSeparator();

    // Prepare reading of lackey memory trace file.
    ifstream inputStream(argv[0]);
    string line;

    // Read trace line by line.
    while (inputStream) {
        getline(inputStream, line);
        if (line.find("I") != string::npos) iCache.read(line);
        else dCache.read(line);
    }

    cout << endl;
    printSeparator();
    cout << "Instruction Cache:" << endl << iCache.toString();
    printSeparator();
    cout << "Data Cache:" << endl << dCache.toString();
    printSeparator();

    return EXIT_SUCCESS;
}
