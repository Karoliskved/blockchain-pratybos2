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
#include "user.h"
#include "users.h"
#include "transaction.h"
#include "pool.h"

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
string prevHash="0";
string version="0.1";
string timestamp="0:00";
string transactionHash;
string miner="me";
int nonce;
string difficulty="3";
string blockhash;
vector<transaction> bTransactions;

public:

//constr destr
block();
~block();

//setters
void setminer(string miner_){
    miner=miner_;
}
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

void setnonce(int i){
nonce=i;

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
string getminer(){
    return miner;
}
int getnonce(){
    return nonce;
}
string getdifficulty(){
    return difficulty;
}
vector<transaction> gettransactions(){
    return bTransactions;
}
string getblockhash(){
    return blockhash;
}
// other func

void addtrasnactions(pool & tPool, users & tuser);
void findnonce();
bool findnoncecomp(int noicesize);
string generateMerklehash(vector<transaction> transactions);
void updatefiles(pool & tPool, users & tuser);

};
block::block(){

}
block::~block(){

}

string block::generateMerklehash(vector<transaction> transactions){
    vector<string> merkle;
    for(int i=0; i<transactions.size(); i++){
        merkle.push_back(myHash(transactions[i].getData()));
    }
    while (merkle.size()!=1)
    {
        if(merkle.size()%2!=0){
            merkle.push_back(merkle.back());
        }
        vector<string> newVector;
        for(int i=0; i<merkle.size(); i=i+2){
            newVector.push_back(myHash(merkle[i].append(merkle[i+1])));
        }
        merkle=newVector;
    }
    
    return merkle[0];
}
void block::addtrasnactions(pool & tPool, users & tuser){
ifstream infile("transactions.txt");  
int index;  
string allt;
for(int i=0; i<100; i++){
index=tuser.finduser(tPool.gettrasnaction(i).getSender());
if(tuser.checkbalanceofuser(index, tPool.gettrasnaction(i).getAmount())==true){
bTransactions.push_back(tPool.gettrasnaction(i)); 
//allt+=tPool.gettrasnaction(i).getTranactionId()+""+tPool.gettrasnaction(i).getSender()+""+tPool.gettrasnaction(i).getResever()+""+to_string(tPool.gettrasnaction(i).getAmount());
//cout << "sender " <<index << " user balance before " <<tuser.userbalance(index);
tuser.takemoneyfromusser(index, tPool.gettrasnaction(i).getAmount());
/*cout <<" amount " << tPool.gettrasnaction(i).getAmount() ;
cout << "balance after " << tuser.userbalance(index) <<endl;*/
index=tuser.finduser(tPool.gettrasnaction(i).getResever());
//cout << "resever " <<index<< " user balance before " <<tuser.userbalance(index); ;
tuser.addmoneytouser(index, tPool.gettrasnaction(i).getAmount());
/*cout <<" amount " << tPool.gettrasnaction(i).getAmount() ;
cout << "balance after " << tuser.userbalance(index) <<endl;*/    
}
else{
   /* cout << "start" << endl;
   cout << tuser.userbalance(index) << endl;
  cout << tPool.gettrasnaction(i).getAmount() << endl;
  cout << "end" << endl;*/
  tPool.removetransaction(i);
  i--;
}


}
transactionHash=generateMerklehash(bTransactions);


}

void block::findnonce(){

    string info;
    string result2="1";
    int i=0;
    info=prevHash+version+timestamp+transactionHash+difficulty;
    while(result2[0]!='0' || result2[1]!='0' || result2[2]!='0' || result2[3]!='0' /*|| result2[4]!='0' || result2[5]!='0'*/ ){
            result2=myHash((info+to_string(i)));
           
            i++;
            //cout << i << endl;
        }

        blockhash=result2;
        nonce=i;

}
bool block::findnoncecomp(int noicesize){

    string info;
    string result2="1";
    int i=0;
    info=prevHash+version+timestamp+transactionHash+difficulty;
    while((result2[0]!='0' || result2[1]!='0' || result2[2]!='0' || result2[3]!='0') & i<noicesize /*|| result2[4]!='0' || result2[5]!='0'*/ ){
            result2=myHash((info+to_string(i)));
           
            i++;
            //cout << i << endl;
        }
        if(result2[0]=='0' & result2[1]=='0' & result2[2]=='0' & result2[3]=='0'){
        blockhash=result2;
        nonce=i;
        return 1;
        }
        else{
            return 0; 
        }
        

}
void block::updatefiles(pool & tPool, users & tuser){
tuser.savetofile("vartotojai.txt");

for(int i=0; i<100; i++)
{
    tPool.removetransaction(0);
}
tPool.savetofile("transactions.txt");
}
#endif