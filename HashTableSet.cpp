#include "Set.h"

/**
 * Implement the HashTableSet methods correctly
 */
unsigned int HashTableSet::size() {
    /* YOUR CODE HERE */
    return ht.size();
}

void HashTableSet::insert(string s) {
    /* YOUR CODE HERE */
    if(find(s)) {
        return;
    }

    ht.insert(s);
}

void HashTableSet::remove(const string & s) {
    /* YOUR CODE HERE */
    ht.erase(s);
}

bool HashTableSet::find(const string & s) {
    /* YOUR CODE HERE */
    unordered_set<string>::iterator it;
    for(it = ht.begin(); it != ht.end(); it++) {
        if(*it == s) {
            return true;
        }
    }

    return false;
}
