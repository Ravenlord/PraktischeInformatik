/* 
 * File:   CacheSimulator.h
 * Author: Richard Fussenegger <rfussenegger.mmt-m2012@fh-salzburg.ac.at>
 * Author: Markus Deutschl <mdeutschl.mmt-m2012@fh-salzburg.ac.at>
 * Author: Elisabeth Lang <elang.mmt-m2012@fh-salzburg.ac.at>
 * Created on December 28, 2012, 9:25 PM
 */

#include <cassert>
#include <cmath>
#include <map>

using namespace std;

#define log2(x) static_cast<unsigned>(log((x)) / log(2))
#define pow2(x) (1 << (x))

#ifndef CACHESIMULATOR_H
#define CACHESIMULATOR_H

typedef enum {
    DIRECT_MAPPED,
    FULLY_ASSOCIATIVE,
    SET_ASSOCIATIVE
} CACHE_ASSOCIATIVITY;

class CacheSimulator {
public:

    /**
     * Create new CacheSimulator instance.
     * 
     * @param size
     *   The size of the cache given in Bytes.
     * @param associativity
     *   The cache associativity policy.
     * @param lineSize
     *   The cache line size given in Bytes.
     * @param lackeyInputFile
     *   Absolute or relative path to lackey trace file.
     */
    CacheSimulator(unsigned size, CACHE_ASSOCIATIVITY associativity, unsigned lineSize) : size(size), associativity(associativity), lineSize(lineSize) {
        this->hitCounter = 0;
        this->missCounter = 0;
        this->usageCounter = 0;

        this->setLines();
        this->setOffsetBits();
        this->setMaxOffset();
        this->setIndexBits();
        this->setTagBits();
        this->setMaxIndex();
        this->setMaxTag();
    }

    /**
     * Change the cache associativity level.
     *
     * @param level
     *   The new cache associativity level.
     * @return
     *   False if the current associativity level is set to direct-mapped.
     *   Otherwise the level is set and true returned.
     */
    bool setAssociativityLevel(unsigned level) {
        if (this->associativity == DIRECT_MAPPED) return false;
        this->associativityLevel = level;
        return true;
    }

    /**
     * 
     * @param line
     *   The line that was read from the input file.
     */
    void read(string line) {
        line = this->trim(line);

        // Remove first character from string.
        line.erase(0, 1);

        // Again trim the string.
        line = this->trim(line);

        // Find the first comma.
        unsigned pos = line.find(",");

        // Extract address and size from line.
        string stringAddress = line.substr(0, pos);
        string stringSize = line.substr(pos + 1);

        stringstream ss;
        unsigned long long address;
        size_t size;

        ss << hex << stringAddress;
        ss >> address;

        ss.clear();

        ss << stringSize;
        ss >> size;

        unsigned keyOffset = address & (pow2(this->offsetBits) - 1);
        assert(keyOffset <= this->maxOffset);

        unsigned keyIndex = (address >> this->offsetBits) & (pow2(this->indexBits) - 1);
        assert(keyIndex <= this->maxIndex);

        unsigned keyTag = (unsigned) (address >> (this->offsetBits + this->indexBits));
        assert(keyTag <= this->maxTag);

        CacheLineSet *cacheLineSet = &this->data[keyIndex];

        for (unsigned i = 0; i < this->associativityLevel; i++) {
            if ((*cacheLineSet)[i].valid && (*cacheLineSet)[i].tag == keyTag) {
                this->hitCounter++;
                cout << " - HIT";
                return;
            }
        }

        this->missCounter++;
        cout << " - MISS";

        for (unsigned i = 0; i < this->associativityLevel; i++) {
            if (!(*cacheLineSet)[i].valid) {
                (*cacheLineSet)[i].tag = keyTag;
                (*cacheLineSet)[i].valid = true;
                this->usageCounter++;
                return;
            }
        }

        cout << " ( evict ) ";

        (*cacheLineSet)[0].tag = keyTag;
        (*cacheLineSet)[0].valid = true;
    }

    /**
     * 
     * @return 
     */
    string getConfiguration() {
        stringstream ss;

        ss << "Cache Lines: " << this->lines << endl;
        ss << "Offset Bits: " << this->offsetBits << endl;
        ss << "Index Bits: " << this->indexBits << endl;
        ss << "Tag Bits: " << this->tagBits << endl;

        return ss.str();
    }

    /**
     * 
     * @return 
     */
    string toString() {
        stringstream ss;

        ss << "Hits:\t\t" << this->hitCounter << endl;
        ss << "Hit Ratio:\t" << getRatio(this->hitCounter) << "%" << endl;
        ss << "Misses:\t\t" << this->missCounter << endl;
        ss << "Miss Ratio:\t" << getRatio(this->missCounter) << "%" << endl;

        return ss.str();
    }

private:

    /**
     * The size of the cache addresses given in Bit.
     */
    unsigned addressSize; // Bit

    /**
     * The size of the cache given in Bytes.
     */
    unsigned size; // Byte

    /**
     * The cache associativity policy.
     */
    CACHE_ASSOCIATIVITY associativity;

    /**
     * The cache associativity level. Default is 0 (zero), means direct-mapped policy.
     */
    unsigned associativityLevel;

    /**
     * The cache line size given in Bytes..
     */
    unsigned lineSize; // Byte

    /**
     * The amount of cache lines this cache has.
     */
    unsigned lines;

    /**
     * The amount of offset bits this cache has.
     */
    unsigned offsetBits;

    /**
     * The maximum cache offset of this cache.
     */
    unsigned maxOffset;

    /**
     * 
     */
    unsigned indexBits;

    /**
     * 
     */
    unsigned tagBits;

    /**
     * 
     */
    unsigned maxIndex;

    /**
     * 
     */
    unsigned maxTag;

    /**
     * 
     */
    struct CacheLine {
        CacheLine() : valid(false), tag(0) {}
        bool valid;
        unsigned tag;
    };

    /**
     * 
     */
    typedef map<unsigned, CacheLine> CacheLineSet;

    /**
     * 
     */
    map<unsigned, CacheLineSet> data;

    /**
     * 
     */
    unsigned hitCounter;

    /**
     * 
     */
    unsigned missCounter;

    /**
     * 
     */
    unsigned usageCounter;

    /**
     * 
     */
    void setLines() {
        this->lines = this->size / this->lineSize;
    }

    /**
     * 
     */
    void setOffsetBits() {
        this->offsetBits = log2(this->lineSize);
    }

    /**
     * 
     */
    void setMaxOffset() {
        this->maxOffset = this->lineSize - 1;
    }

    /**
     * 
     */
    void setIndexBits() {
        switch (this->associativityLevel) {
            case DIRECT_MAPPED:
                this->indexBits = log2(this->lines);
                break;
            case FULLY_ASSOCIATIVE:
                this->indexBits = 0;
                break;
            case SET_ASSOCIATIVE:
                this->indexBits = log2(this->size / this->lineSize / this->associativity);
                break;
        }
    }

    /**
     * 
     */
    void setTagBits() {
        this->tagBits = this->size - this->indexBits - this->offsetBits;
    }

    /**
     * 
     */
    void setMaxIndex() {
        this->maxIndex = pow2(this->indexBits) - 1;
    }

    /**
     * 
     */
    void setMaxTag() {
        this->maxTag = pow2(this->tagBits) - 1;
    }

    /**
     * 
     * @param counter
     * @return 
     */
    unsigned getRatio(unsigned counter) {
        return counter / double(this->missCounter + this->hitCounter) * 100;
    }

    /**
     * Trim whitespace from beginning and end of string.
     *
     * @link http://www.c-plusplus.de/forum/125204-full
     * @param str
     *   The string to trim.
     * @return
     *   The trimmed string.
     */
    string trim(string str) {
        unsigned pos1 = str.find_first_not_of(" ");
        unsigned pos2 = str.find_last_not_of(" ");

        return str.substr(pos1, pos2 - pos1 + 1);
    }

};

#endif	/* CACHESIMULATOR_H */
