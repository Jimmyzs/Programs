//Jimmy Yuan
#include <iostream>
#include <fstream>
#include "Scramble.h"

using namespace std;

int main(){
    ifstream in;
    in.open("words.txt");
    if(in.fail()){ //Makes sure there is a words.txt
        cerr<<"words.txt cannot be openned"<<endl;
        return 0;
    }
    Scramble game;
    string word;
    while(in>>word){ //Adds words from the file
        game.addWord(word);
    }
    in.close(); //Closes file
    game.begin(); //Begins game
    
    return 0;
}

