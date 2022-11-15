//
// Created by Anh on 11/14/2022.
//

#include "HashMap.h"

HashMap::HashMap() {
    map_ = *(new vector<pair<string, string>*> {nullptr, nullptr});
}

int HashMap::hash(string &key) {
    int index = 0;
    for (char &c: key) {
        index += int(c);
    }
    return index % capacity_;
}

string *HashMap::get(string &key) {
    int index = hash(key);
    while (map_[index]) {
        if (map_[index]->first == key) {
            return &map_[index]->second;
        }
        // Open address method approach
        index++;
        index = index % capacity_;
    }
    return nullptr;
}

void HashMap::put(string &key, string &val) {
    int index = hash(key);
    while (true) {
        if (map_[index] == nullptr) {
            map_[index] = new pair<string, string>(key, val);
            size_++;
            if (size_ >= capacity_ / 2) {
                rehash();
            }
            return;
        } else if (map_[index]->first == key) {
            map_[index]->second = val;
            return;
        }
        index++;
        index = index % capacity_;
    }
}

void HashMap::remove(string &key) {
    if (!get(key)) {
        return;
    }
    int index = hash(key);
    while (true) {
        if (map_[index]->first == key) {
            map_[index] = 0;
            size_--;
            return;
        }
        index++;
        index = index % capacity_;
    }
}

void HashMap::rehash() {
    capacity_ = 2 * capacity_;
    vector<pair<string, string>*> newMap = *(new vector<pair<string, string>*>());

    for (int i = 0; i < capacity_; i++) {
        newMap.push_back(nullptr);
    }
    vector<pair<string, string>*> oldMap = map_;
    map_ = newMap;
    size_ = 0;
    for (auto& pair: oldMap) {
        if (pair != nullptr) {
            put(pair->first, pair->second);
        }
    }
}

void HashMap::print() {
    cout << "Printing size=" << size_ << endl;
    for (auto& pair: map_) {
        if (pair) {
            cout << pair->first << ' ' << pair->second << '-';
        }
        cout << endl;
    }
}
