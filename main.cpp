#include <iostream>
#include <vector>
#include <unordered_map>
#include "HashMap.h"
using namespace std;


//https://cplusplus.com/reference/unordered_map/unordered_map/

int main() {
    string names[7]={"alice","brad","matt","brad","killjoy","kim"};
    unordered_map<string,int> myMap;
    for (int i=0; i<names->length();i++){
        if (myMap.find(names[i])!=myMap.end()){
            myMap.at(names[i])+=1;
        }else{
            myMap[names[i]]=1;
        }
    }
    cout<<myMap.at(names[1])<<endl;
    return 0;
}
