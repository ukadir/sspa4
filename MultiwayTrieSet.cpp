#include "Set.h"
#include <iostream>

/**
 * Implement the MultiwayTrieSet constructor
 */
MultiwayTrieSet::MultiwayTrieSet() {
    /* YOUR CODE HERE */
    root = NULL;
    numElements = 0; 
}

/**
 * Implement the MultiwayTrieSet destructor
 */
MultiwayTrieSet::~MultiwayTrieSet() {
    /* YOUR CODE HERE */
    if(root == NULL)
        return;
    
    root->rDelete();
    root = NULL;
}

/**
 * Implement the MultiwayTrieSet methods correctly
 */
unsigned int MultiwayTrieSet::size() {
    /* YOUR CODE HERE */
    return numElements;
}

void MultiwayTrieSet::insert(string s) {
    /* YOUR CODE HERE */
    if(root == NULL)
        root = new Node();

    Node* curr = root;
    unsigned int letter = 0;
    unordered_map<char, Node*>::iterator it = curr->children.find(s.at(letter));;

    while( it != curr->children.end() && letter < s.length()) {
        //cout << s.at(letter) << "found in inserted\n";
        curr = it->second;
        letter++;
        it = curr->children.find(s.at(letter));
    }

    
    while(letter < s.length()) {
        Node* newNode = new Node();
        curr->children.insert({s.at(letter), newNode});
        curr = newNode;
        letter++;
    }

    if(!(curr->isWord)) {
        curr->isWord = true;
        numElements++;
    }
        
}

void MultiwayTrieSet::remove(const string & s) {
    /* YOUR CODE HERE */
    if(root == NULL)
        return;

    Node* curr = root;
    unsigned int letter = 0;
    unordered_map<char, Node*>::iterator it = curr->children.find(s.at(letter));

    while(letter < s.length()) {
        it = curr->children.find(s.at(letter));
        //cout << s.at(letter) << "found in removed\n";
        if(it == curr->children.end()) {
            return;
        }
        curr = it->second;
        letter++;
        
    }
    if(curr->isWord) {
        curr->isWord = false;
        numElements--;
    } 

}

bool MultiwayTrieSet::find(const string & s) {
    /* YOUR CODE HERE */
    if(root == NULL)
        return false;

    Node* curr = root;
    unsigned int letter = 0;
    unordered_map<char, Node*>::iterator it;

    while(letter < s.length()) {
        it = curr->children.find(s.at(letter));
        if(it == curr->children.end()) {
            return false;
        }
        curr = it->second;
        letter++;
        
    }

    if(curr->isWord) {
        return true;
    } else {
        return false;
    }
}

void MultiwayTrieSet::Node::rDelete() {
    for(auto pair : this->children) {
        pair.second->rDelete();
    }

    delete this;
}
