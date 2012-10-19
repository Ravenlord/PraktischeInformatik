#include <list>

typedef std::list<unsigned int> intlist;

intlist merge_lists(intlist *lists, unsigned int k) {
    intlist merged;
    
    do {
        int m = -1; // list index with largest element
        for (unsigned int i = 0; i < k; i++) {
            if (lists[i].empty()) continue; // skip list if already empty
            
            if (m < 0) m = i; // first list we see...
            else if (lists[i].front() > lists[m].front()) // check first element of subsequent list
                m = i;
        }
        
        if (m < 0) break; // all lists were empty, done
        
        merged.push_back(lists[m].front()); // append largest element to results
        lists[m].pop_front(); // remove largest element from list
    } while (true);
    
    return merged;
}
