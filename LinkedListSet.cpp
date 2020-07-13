#include "Set.h"

/**
 * Implement the LinkedListSet methods correctly
 */
unsigned int LinkedListSet::size() {
    /* YOUR CODE HERE */
    return linked.size();
}

void LinkedListSet::insert(string s) {
    /* YOUR CODE HERE */
    if(find(s)) {
        return;
    }

    linked.push_back(s);
}

void LinkedListSet::remove(const string & s) {
    /* YOUR CODE HERE */
    linked.remove(s);
}

bool LinkedListSet::find(const string & s) {
    /* YOUR CODE HERE */
    list<string>::iterator it;
    for(it = linked.begin(); it != linked.end(); it++) {
        if(*it == s) {
            return true;
        }
    }

    return false;
}
