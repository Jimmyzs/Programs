//Jimmy Yuan
#ifndef SCRAMBLE_H
#define SCRAMBLE_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Scramble{
    public:
    Scramble();
    void addWord(string s);
    void begin();
    void scramble(int letter);

    private:
    list<string> words;
    vector<string> outputs;
    int tries;
    int length;
    string word;
    bool play;


};

#endif

