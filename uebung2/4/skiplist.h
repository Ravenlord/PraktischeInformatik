/* 
 * File:   skiplist.h
 * Author: Richard Fussenegger
 * Author: Markus Deutschl
 *
 * Created on November 19, 2012, 10:45 PM
 */

#ifndef SKIPLISTS_H
#define	SKIPLISTS_H

#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename Tkey, typename Tval>
class skiplist {
public:
    /** Constructor */
    skiplist(int maxLevel = 5) : head(new node(defaultKey, defaultValue, maxLevel + 1)), currentLevel(0), maxLevel(maxLevel) {};

    /** Destructor */
    virtual ~skiplist() {
        delete this->head;
    }

    /**
     * Search for key in skiplist and receive value.
     * @param key
     *   The key to search for.
     * @return
     *   The value of the given key.
     */
    Tval search(const Tkey key) const {
        return this->search(this->head, key, this->currentLevel);
    }

    /**
     * Insert a key-value-pair into our skiplist.
     * @param key
     *   The key to insert.
     * @param val
     *   The value to insert.
     */
    void insert(const Tkey key, const Tval val) {
        this->insert(this->head, new node(key, val, this->randomSkiplistGenerator()), this->currentLevel);
    }

    /**
     * Remove node by key.
     * @param key
     *   The key of the node which we should remove.
     */
    void remove(Tkey key) {
        this->remove(this->head, key, this->currentLevel - 1);
    }

    /**
     * Print all nodes of the current skiplist to the standard output.
     */
    void print() {
        node* nodeObj = this->head;
        do {
            cout << "Node with key " << nodeObj->key << " has value " << nodeObj->val << "." << endl;
            nodeObj = nodeObj->next[0];
        } while (nodeObj->next[0]);
    }

private:

    /**
     * Node structure for skiplist element.
     */
    struct node {
        /** The key. */
        Tkey key;
        /** The value. */
        Tval val;
        /** The size. */
        int size;
        /** Array of next pointers. */
        node **next;

        /**
         * Constructor
         * @param key
         * @param val
         * @param size
         */
        node(const Tkey key, const Tval val, int size) : key(key), val(val), size(size), next(new node*[size]) {
            for (int i = 0; i < size; ++i) {
                this->next[i] = 0;
            }
        }

        /**
         * Destructor
         */
        ~node() {
            delete this->next[0];
            delete [] this->next;
        }
    };

    /** Default item in skiplist. */
    Tkey defaultKey;

    /** Default value in skiplist. */
    Tval defaultValue;

    /** Head in skiplist. */
    node* head;

    /** Current index in skiplist. */
    int currentLevel;

    /** Maximum index in skiplist. */
    int maxLevel;

    /**
     * Random skiplist level generator.
     * @return
     *   Newly generated random level.
     */
    int randomSkiplistGenerator() {
        /** Iterator i */
        int i = 1,
        /** Iterator j */
            j = 2,
        /** Randomly generated integer between [0, RAND_MAX]. */
            t = rand();

        // Generate random level.
        for (; i < this->maxLevel; i++, j += j) {
            // Makes sure that we have most nodes in the lower levels as described
            // in the skiplist paper.
            if (t > RAND_MAX / j) {
                break;
            }
        }

        // If the newly generated level is above the current level of our skiplist,
        // we expand our skiplist.
        if (i > this->currentLevel) {
            this->currentLevel = i;
        }

        return i;
    }

    /** Remove key and value. */
    void remove(node* nodeObj, Tkey key, int currentLevel);

    /** Remove all keys. */
    void removeAll(node* nodeObj, int currentLevel);

    /**
     * Search skiplist with given node, key and current level.
     * @param nodeObj
     * @param key
     * @param currentLevel
     * @return 
     */
    Tval search(node* nodeObj, const Tkey key, int currentLevel) const {
        // Search failed.
        if (nodeObj == 0) {
            return this->defaultValue;
        }

        // Search succeeded.
        if (key == nodeObj->key) {
            return nodeObj->val;
        }

        // Link to the node on same level.
        node* nextNodeObj = nodeObj->next[currentLevel];

        // Check if there is a next node in the same level or if the key is smaller
        // than the stored key of the next node.
        if (nextNodeObj == 0 || key < nextNodeObj->key) {
            // No more levels available, search failed.
            if (currentLevel == 0) {
                return this->defaultValue;
            }

            // Try previous level.
            return this->search(nodeObj, key, currentLevel - 1);
        }

        // Keep searching on the same level.
        return this->search(nextNodeObj, key, currentLevel);
    }

    /**
     * Insert new node into skiplist.
     * @param nodeObj
     * @param newNodeObj
     * @param currentLevel
     * @return 
     */
    void insert(node* nodeObj, node* newNodeObj, int currentLevel) {
        /** Current key of the new node. */
        Tkey key = newNodeObj->key;

        /** Next node object on current level. */
        node* nextNodeObj = nodeObj->next[currentLevel];

        // Check if next node object is present at all, or if the key of the next
        // node object is smaller than the key we want to insert.
        if (nextNodeObj == 0 || key < nextNodeObj->key) {
            // Check if we are in range of the total size and start rearranging the
            // pointers.
            if (currentLevel < newNodeObj->size) {
                newNodeObj->next[currentLevel] = nextNodeObj;
                nodeObj->next[currentLevel] = newNodeObj;
            }

            // Fail.
            if (currentLevel == 0) {
                return;
            }

            // If our current level is bigger or equal to the size of our new node
            // go one level down and try to insert there.
            this->insert(nodeObj, newNodeObj, currentLevel - 1);
            return;
        }

        // If the key is bigger or equal than the next nodes key go to that node and
        // try to insert there.
        this->insert(nextNodeObj, newNodeObj, currentLevel);
    }
    
};

#endif	/* SKIPLISTS_H */