//
// Created by Anh on 11/14/2022.
//

#ifndef HASHMAP_HASHMAP_H
#define HASHMAP_HASHMAP_H
#include <vector>
#include <string>
#include <utility>
#include <iostream>
using namespace std;


class HashMap {
public:
    int size_ = 0;
    int capacity_ = 2;
    vector<pair<string, string>*> map_;
    //constructor
    HashMap();
    //Hash function
    int hash(string& key);
    //Get function
    string* get(string& key);
    //Put key and values in hashMap
    void put(string& key, string& val);

    // Removing an element using open-addressing actually causes a bug,
    // because we may create a hole in the list, and our get() may
    // stop searching early when it reaches this hole.
    void remove(string& key);
    //Rehash function
    void rehash();
    //Print function O(n) complexity
    void print();
};

//27
//39
//26
//17

#endif //HASHMAP_HASHMAP_H
