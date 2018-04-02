/* 
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.
 */

#include <math.h>
#include "recursion.h"
#include "map.h"
#include "vector.h"
#include "set.h"
#include "gwindow.h"
#include "gobjects.h"
#include "tokenscanner.h"
using namespace std;

bool isContain(Vector<string> v,string s);

int colorNum(0);//记录更改像素的数量，只能用全局变量喽

Vector<string> v;//4

string sentenceStr("");//5

int gcd(int a, int b) {


    if(b == 0){

        cout << "gcd(" <<  a << "," << b << ") = " << a << endl;
        return a;
    }
    else{

        cout << "gcd(" <<  a << "," << b << ") = ";
        cout << "gcd(" <<  b << "," << a%b << ") " << endl;
        return gcd(b , a % b);
    }
}

void serpinskii(GWindow &w, int x1, int x2, int x3, int y1, int y2, int y3, int size, int order) {
    if(order>0){
        w.drawLine(x1,y1,x2,y2);
        w.drawLine(x2,y2,x3,y3);
        w.drawLine(x3,y3,x1,y1);
        order--;
        serpinskii(w,x1,(x2+x1)/2,(x3+x1)/2,y1,y2,(y3+y1)/2,size,order);
        serpinskii(w,(x2+x1)/2,x2,(x3+x2)/2,y1,y2,(y3+y1)/2,size,order);
        serpinskii(w,(x3+x1)/2,(x3+x2)/2,(x2+x1)/2,(y3+y1)/2,(y3+y1)/2,y3,size,order);
    }
}

int floodFill(GBufferedImage& image, int x, int y, int newColor) {

    int w = image.getWidth();
    int h = image.getHeight();

    if(image.getRGB(x,y) != newColor && x <= w && y <= h){

        int oldColor = image.getRGB(x,y);

        image.setRGB(x,y,newColor);
        colorNum++;

        if(image.getRGB(x+1,y) == oldColor)floodFill(image,x+1,y,newColor);
        if(image.getRGB(x,y+1) == oldColor)floodFill(image,x,y+1,newColor);
        if(image.getRGB(x-1,y) == oldColor)floodFill(image,x-1,y,newColor);
        if(image.getRGB(x,y-1) == oldColor)floodFill(image,x,y-1,newColor);
    }

    return colorNum;
}

void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {

    Vector<string> temp = prereqMap[goal];

    for(int i = 0;i < temp.size();i++){

        string tempWord = temp[i];

        v.add(tempWord);

        personalCurriculum(prereqMap,tempWord);
    }
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {

    Vector<string> tempV = grammar[symbol];

    string str = tempV[randomInteger(0,tempV.size()-1)];

    TokenScanner ts(str);

    while(ts.hasMoreTokens()){

       string token = ts.nextToken();

       Vector<string> vt = grammar[token];

       cout<<token<<endl;


       if(vt.size() > 0){
           generate(grammar,token);
       }else{

       }
    }

    return " ";
}

//自定义方法一~~~4
bool isContain(Vector<string> v,string s){
    for(int i = 0;i < v.size();i++){
        if(v[i] == s) return true;
    }

    return false;
}

//自定義方法二~~~4
void personal(){

    Vector<string> tempV;

    for(int i = v.size();i > 0;i--){
        if(!isContain(tempV,v[i-1])){
            tempV.add(v[i-1]);
            cout<<v[i-1]<<endl;
        }
    }
}


