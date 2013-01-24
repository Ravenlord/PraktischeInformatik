/* 
 * File:   CircularBuffer.h
 * Author: Richard Fussenegger <rfussenegger.mmt-m2012@fh-salzburg.ac.at>
 * Author: Markus Deutschl <mdeutschl.mmt-m2012@fh-salzburg.ac.at>
 * Created on December 17, 2012, 4:39 PM
 */

#include "DefaultCircularBufferErrorPolicy.h"

using namespace std;

#ifndef CIRCULARBUFFER_H
#define	CIRCULARBUFFER_H

template
<
    typename T,
    template <typename> class ErrorPolicy = DefaultCircularBufferErrorPolicy
>
class CircularBuffer : public ErrorPolicy<T> {
public:

    /**
     * Constructor for new CircularBuffer instance.
     *
     * @param size
     *   Size of the newly created CircularBuffer.
     */
    CircularBuffer(unsigned size) : size(size), start(0), count(0), elements(new T[size]) {
        cout << "CircularBuffer constructed." << endl;
    }

    /**
     * Destructor for the current CircularBuffer instance.
     */
    ~CircularBuffer() {
        delete[] this->elements;
        cout << "CircularBuffer destroyed." << endl;
    }

    /**
     * Copy constructor for CircularBuffer.
     *
     * @param cb
     *   The other CircularBuffer instance passed by reference.
     */
    CircularBuffer(CircularBuffer& cb) {
        this->count = cb.count;
        this->size = cb.size;
        this->start = cb.start;
        this->elements = new T[cb.size];
        for (unsigned i = 0; i < cb.size; i++) {
            this->elements[i] = cb.elements[i];
        }
    }

    /**
     * Assignment operator for CircularBuffer.
     *
     * @param cbTmp
     *   The other CircularBuffer instance.
     * @return
     *   Current CircularBuffer instance with copied values from other instance.
     */
    CircularBuffer& operator=(CircularBuffer cbTmp) {
        swap(this->count, cbTmp.count);
        swap(this->size, cbTmp.size);
        swap(this->start, cbTmp.start);
        swap(this->elements, cbTmp.elements);
        return *this;
    }

    /**
     * Write a value into our CircularBuffer.
     *
     * @param value
     *   The value to push.
     */
    void write(T value) {
        super::write(value, this->elements, this->start, this->count, this->size);
    }

    /**
     * Read the oldest value from the CircularBuffer.
     */
    T read() {
        if (this->count == 0) return super::emptyCircularBuffer();

        // Store the return value.
        T returnValue = this->elements[this->start];

        // Move start index.
        this->start = (this->start + 1) % this->size;
        --this->count;

        return returnValue;
    }

private:

    /**
     * Reference to our parent class.
     */
    typedef ErrorPolicy<T> super;

    /**
     * The size of the CircularBuffer.
     */
    unsigned size;

    /**
     * Start index in the internally used array.
     */
    unsigned start;

    /**
     * Counter to keep track on written elements.
     */
    unsigned count;

    /**
     * Internal array of values.
     */
    T *elements;

};

#endif	/* CIRCULARBUFFER_H */
