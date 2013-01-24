/* 
 * File:   CircularBufferErrorPolicy.h
 * Author: Richard Fussenegger <rfussenegger.mmt-m2012@fh-salzburg.ac.at>
 * Author: Markus Deutschl <mdeutschl.mmt-m2012@fh-salzburg.ac.at>
 * Created on December 17, 2012, 6:35 PM
 */

#include <climits>

#ifndef CIRCULARBUFFERERRORPOLICY_H
#define	CIRCULARBUFFERERRORPOLICY_H

template <typename T>
class DefaultCircularBufferErrorPolicy {
public:

    /**
     * Write a value into our CircularBuffer.
     *
     * The oldest value in the CircularBuffer will be overwritten if the buffer
     * is full. Otherwise is simply pushed on the array.
     *
     * @param value
     *   The value to push.
     * @param elements
     *   Internal array of values.
     * @param start
     *   Start index in the internally used array.
     * @param count
     *   Counter to keep track on written elements.
     * @param size
     *   The size of the CircularBuffer.
     */
    void write(T value, T *elements, unsigned &start, unsigned &count, unsigned size) {
        // Insert new value on latest position.
        elements[(start + count) % size] = value;

        // If our CircularBuffer is full, move the start index of the valid
        // data one position further.
        (count == size) ? (start = (start + 1) % size) : ++count;
    }

    /**
     * @return
     *   Default policy if CircularBuffer is empty, is to return INT_MAX.
     */
    int emptyCircularBuffer() {
        return INT_MAX;
    }

};

#endif	/* CIRCULARBUFFERERRORPOLICY_H */