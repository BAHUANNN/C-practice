// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "hashmap.h"

using namespace std;

string word;
int valueNum,num,havePut = 0;
HashMap<string,Vector<string>> randomMap;
Vector<string> textValues,keyValues;

void firstRandom(){
    string begin = keyValues[randomInteger(0,keyValues.size()-1)];
    cout << "..." << begin ;
    Vector<string> oneValues = randomMap.get(begin);
    string value = oneValues[randomInteger(0,oneValues.size()-1)];
    cout << value;

    havePut += 3;

    while(havePut < num){
        string newBegin = begin + value;
        stringstream ss(newBegin);

        int i = 0;begin="";
        while(ss >> word){
            if(i > 0)begin += word + " ";
            i++;
        }
        Vector<string> oneValues = randomMap.get(begin);
        value = oneValues[randomInteger(0,oneValues.size()-1)];
        cout << value;

        havePut++;
        }
    }

int main() {

    cout << "Welcome to CS 106B Random Writer (aka 'N-Grams')." << endl;
    cout << "This program generates random text based on a document." << endl;
    cout << "Give me an input file and an 'N' value for groups" << endl;
    cout << "of words, and I'll generate random text for you." << endl << endl;
    cout << "Value of N?";
    cin >> valueNum;
    cout << "# of random words to generate (0 to quit)?";
    cin >> num;

    ifstream infile;
    infile.open("morrison.txt");
    while( infile >>  word ){
        textValues.add(word);
    }

    //key and value

    for(int i=0;i<textValues.size()-valueNum;i++){
        string key = "", value = textValues[i+valueNum-1];
        for(int j=1;j<valueNum;j++){
            key += textValues[i+j-1]+" ";
        }
        keyValues.add(key);

        if(randomMap.get(key).size() == 0){
            Vector<string> values;
            values.add(value+" ");
            randomMap.put(key,values);
        }else{
            randomMap.get(key).add(value);
        }

    }

    firstRandom();

    return 0;
}
