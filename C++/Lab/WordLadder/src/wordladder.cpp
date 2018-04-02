// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include <queue.h>
#include <map.h>

using namespace std;

bool way1(string str){
    ifstream infile;
    infile.open("temp.txt");

    string word;
    bool b = false;

    while( getline(infile,word) )
    {
           if(str == word) b = true;
    }

    return b ;
}


int main() {
    string first,second,word;
    bool queueBool = false;
    queue<string> strQueue,ladder;
    map<string,string> mark;

    cout << "Please enter two words" << endl;

    cout << "first:" ;
    cin >> first ;

    cout << "second:" ;
    cin >> second ;

    int size = first.length();

    if(first.length() == second.length() && first!=second ){

        ofstream offile;
        offile.open("temp.txt");

        ifstream infile;
        infile.open("dictionary.txt");

        while( getline(infile,word) )
        {
               if(word.length() == size) offile << word << "\n";
        }

        strQueue.push(first);

        while(!queueBool){
           for(int i=0;i<size;i++){
               string strF = strQueue.front();
                string str = strQueue.front();
                if(str[i] != second[i]){
                    for(int ii=97;ii<=122;ii++){
                        if(str[i] != ii){
                            str[i] = ii;
                            if(way1(str)){
                                strQueue.push(str);
                                mark.insert(pair<string,string>(str,strF));
                                if(str == second)queueBool = true;
                            }
                        }
                    }
                }
                strQueue.pop();
            }
       }
/*
        int queueSize = strQueue.size();
        for(int i =0;i<queueSize;i++){
            string str = strQueue.front();
            cout<<str<<endl;
            strQueue.pop();

        }
*/
        cout<<second<<"\n";
        string strFather = second ;
        while(strFather != first){
            strFather = mark[strFather];
            cout << strFather << endl;
        }


    }

    return 0;
}

