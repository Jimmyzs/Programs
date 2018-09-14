//Jimmy Yuan
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Scramble.h"

using namespace std;

//Constructor initiating tries and play
Scramble::Scramble():tries(3),play(true),length(0){}

//Checks if word is at least 3 letters long, makes it capital and adds it to the list
void Scramble::addWord(string s){
    length=s.length();
    if(length>=3){
        for(int i=0;i<length;i++){
            s[i]=toupper(s[i]);
        }
        words.push_back(s);
    }
}

//Adds all of the permutations of a word that are not the same as the original word using recursion
void Scramble::scramble(int letter){
    length=word.length();
    if(letter+1!=length){
        for(int i=letter+1;i<length;i++){
            swap(word[letter], word[i]);
            if(word!=outputs[0]){
                outputs.push_back(word);
            }
            scramble(letter+1);
            swap(word[letter], word[i]);
        }
    }
}

//Starts the game and randomly picks a word and mixes up the word
void Scramble::begin(){
    auto it=words.begin();
    string user;

    //Loops until every word is used or user quits
    while(play&&!words.empty()){
        srand(time(0));
        int randNum=rand()%words.size();
        int size=6;
        advance(it,randNum);
        for(int i=4;i<(*it).length();i++){ //Gets the max size of the vector n!
            size*=i;
        }
        outputs.reserve(size);
        outputs.push_back(*it);
        word=*it;
        scramble(0); //Scrambles the word
        words.erase(it); //Erases the word from the list
        it=words.begin();
        srand(time(0));
        randNum=(rand() % (outputs.size()-1))+1;
        cout<<"Unscramble ("<<outputs[randNum]<<")"<<endl; //Random scrambled word
        while(play){ //Takes user input
            cout<<tries<<" tries left"<<endl;
            cin>>user;
            length=user.length();
            for(int i=0;i<length;i++){
                user[i]=toupper(user[i]);
            }
            if(user==outputs[0]){
                cout<<"You Win!"<<endl;
                play=false;
            }
            else{
                tries-=1;
            }
            if(tries==0){
                cout<<"You lose the word was "<<outputs[0]<<endl;
                play=false;
            }
        }
        cout<<"Enter y to play again and anything else to exit: "; //Asks if they want to play again
        char cont;
        cin>>cont;
        if(cont=='y'){
            play=true;
            tries=3;
        }
        else
            return;
        outputs.clear(); //Clears the vector
        if(words.empty()){ //List is empty
            cout<<"Out of Words"<<endl;
            return;
        }

    }

}
