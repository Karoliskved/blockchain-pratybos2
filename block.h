#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include <iostream>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <time.h>
#include "myHash.h"

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::vector;
using std::string;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::getline;
using std::to_string;
using std::exception;
using std::bitset;
using std::hex;
class block{
private:
string prevHash;
string version="0.1";
string timestamp;
string transactionHash;
string nonce;
string difficulty="4";
vector<stringstream> alltransactions;

public:

//constr destr
block();
~block();

//setters
void setprevHash(string prevHash_){
    prevHash=prevHash_;
}
void setversion(string version_){
    version=version_;
}
void settimestamp(){
  time_t timer;
  struct tm y2k = {0};
  double seconds;

  y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
  y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

  time(&timer);  /* get current time; same as: timer = time(NULL)  */

  seconds = difftime(timer,mktime(&y2k));
   timestamp=to_string(seconds);
}
void settransactionHash(){

}
void setnonce(int i){
nonce=to_string(i);

}
void setdifficulty(string difficulty_){
    difficulty=difficulty_;

}
//getters
string getprevHash(){
    return prevHash;
}
string getversion(){
    return version;
}
string gettimestamp(){
    return timestamp;
}
string gettransactionhash(){
    return transactionHash;
}
string getnonce(){
    return nonce;
}
string getdifficulty(){
    return difficulty;
}

};
block::block(){

}

#endif