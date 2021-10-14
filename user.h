#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
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
#include <algorithm>
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
using std::find_if;
using std::distance;

class user
{
private:
    /* data */
    string name;
    string userHash;
    double sum;
public:
    user(string name_, string userHash_, double sum_);
    ~user();
    //setters
    void setword(string word_){
        name=word_;
    }
    void setuserHash(string userHash_){
        userHash=userHash_;
    }
    void setsum(double sum_){
        sum=sum_;
    }
    void genuserHash(){
        userHash=myHash(name);
    }
    bool checkbalance(double transactionsum){
        return (sum-transactionsum)>0;
    }
    void addmoney(double transactionsum){
        sum+=transactionsum;
    }
    void takemoney(double transactionsum){
        sum-=transactionsum;
    }
    string getname(){
        return name;
    }
    string getuserhash(){
        return userHash;
    }
    double getsum(){
        return sum;
    }

};

user::user(string name_, string userHash_, double sum_)
{
    name=name_;
    userHash=userHash_;
    sum=sum_;
}

user::~user()
{
}


#endif