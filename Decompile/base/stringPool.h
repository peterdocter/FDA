//
// Created by F8LEFT on 2016/4/7.
//

#ifndef FDA_STRINGPOOL_H
#define FDA_STRINGPOOL_H

#include <vector>
#include <string>
using namespace std;

class stringPool {
private:
    vector<string> pool;
    int iRead;
public:
    stringPool();

public:
    vector<string>::iterator begin() { return pool.begin(); }
    vector<string>::iterator end() { return pool.end(); }
    void pushback(const string &str) { pool.push_back(str); }
    void reserve(unsigned size) { pool.reserve(size); }

};


#endif //FDA_STRINGPOOL_H
