#ifndef MYHASH_H_INCLUDED
#define MYHASH_H_INCLUDED
#include <string>
using std::string;

string myHash(string n){
   
    string finalhash="";
    unsigned int sum=0;
    unsigned int sumreverse=0;
    unsigned int sumfinal=0;
    int movedbits;
    int reversemovedbits;
    for (int i=0; i!=n.length(); i++){
        movedbits = (int(n[i]) << 5);
        sum+=((sum/7+movedbits) << 5);
       reversemovedbits=(int(n[n.size()-1-i]) << 7);
        sumreverse+=((sumreverse/7+reversemovedbits) << 7);
        sumfinal+=sum+sumreverse;
    }
  string hexcode="0123456789abcdef";
    for(int i=1; i!=65; ++i){
        sumfinal+=((/*7**/(sumfinal >> 5))+i);
        finalhash+=hexcode[((sumfinal%113)%16)];
    }
    return finalhash;
 
}

#endif