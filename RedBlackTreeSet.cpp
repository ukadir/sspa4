#include "Set.h"

/**
 * Implement the RedBlackTreeSet methods correctly
 */
unsigned int RedBlackTreeSet::size() {
    /* YOUR CODE HERE */
    return rbt.size();
}

void RedBlackTreeSet::insert(string s) {
    /* YOUR CODE HERE */
    if(find(s)) {
        return;
    }

    rbt.insert(s);
}

void RedBlackTreeSet::remove(const string & s) {
    /* YOUR CODE HERE */
    rbt.erase(s);
}

bool RedBlackTreeSet::find(const string & s) {
    /* YOUR CODE HERE */
    set<string>::iterator it;
    for(it = rbt.begin(); it != rbt.end(); it++) {
        if(*it == s) {
            return true;
        }
    }

    return false;
}
