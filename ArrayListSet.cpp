#include "Set.h"
#include <iostream>

/**
 * Implement the ArrayListSet methods correctly
 */
unsigned int ArrayListSet::size() {
    /* YOUR CODE HERE */
    return arr.size();
}

void ArrayListSet::insert(string s) {
    /* YOUR CODE HERE */
    if(find(s)) {
        return;
    }

    arr.push_back(s);
}

void ArrayListSet::remove(const string & s) {
    /* YOUR CODE HERE */
    vector<string>::iterator it;
    
    for(it = arr.begin(); it != arr.end(); it++) {
        //cout << *it << endl;
        if(*it == s) {
            arr.erase(it);
            break;
        }
    }
}

bool ArrayListSet::find(const string & s) {
    /* YOUR CODE HERE */
    for(string i : arr) {
        if(i == s) {
            return true;
        }
    }

    return false;
}
