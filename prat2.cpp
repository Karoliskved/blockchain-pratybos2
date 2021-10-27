#include <iostream>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include "block.h"
#include "transaction.h"
#include "users.h"
#include "blockchain.h"

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
int main(){
blockchain blockchaintest;
string string1="transactions.txt", string2="vartotojai.txt";
std::chrono::duration<double> diff;
std::chrono::duration<double> diff1;
auto start = std::chrono::high_resolution_clock::now();
  blockchaintest.gennewblock(string1, string2);
  auto end = std::chrono::high_resolution_clock::now();
  diff+=(end-start);
   std::cout << "1 bloko generavimas " << diff/std::chrono::milliseconds(1) << " ms\n";
   /*cout << blockchaintest.getblock(0).getprevHash()<<endl;
    cout << blockchaintest.getblock(0).getversion()<<endl;
    cout << blockchaintest.getblock(0).gettimestamp()<<endl;
    cout << blockchaintest.getblock(0).gettransactionhash()<<endl;
    cout << blockchaintest.getblock(0).getnonce()<<endl;
    cout << blockchaintest.getblock(0).getdifficulty()<<endl;
    cout << blockchaintest.getblock(0).getblockhash()<<endl;*/
    auto start1 = std::chrono::high_resolution_clock::now();
blockchaintest.gennewblock(string1, string2);
auto end1 = std::chrono::high_resolution_clock::now();
cout << "second block" << endl;
diff1+=(end1-start1);
   std::cout << "1 bloko generavimas " << diff1/std::chrono::milliseconds(1) << " ms\n";
  /*cout << blockchaintest.getblock(1).getprevHash()<<endl;
    cout << blockchaintest.getblock(1).getversion()<<endl;
    cout << blockchaintest.getblock(1).gettimestamp()<<endl;
    cout << blockchaintest.getblock(1).gettransactionhash()<<endl;
    cout << blockchaintest.getblock(1).getnonce()<<endl;
    cout << blockchaintest.getblock(1).getdifficulty()<<endl;
    cout << blockchaintest.getblock(1).getblockhash()<<endl;*/
    //blockchaintest.gennewblock(testpool, testusers);

  
}
/*
  block block1;
    pool tPool("transactions.txt");
  //  users tusers("test.txt");
  users tusers("vartotojai.txt");
  
    //cout << block1.getversion() << endl;
    block1.addtrasnaction(tPool, tusers);
    vector<transaction> test =block1.gettransactions();
    block1.findnonce();
    cout << block1.getprevHash()<<endl;
    cout << block1.getversion()<<endl;
    cout << block1.gettimestamp()<<endl;
    cout << block1.gettransactionhash()<<endl;
    cout << block1.getnonce()<<endl;
    cout << block1.getdifficulty()<<endl;
    cout << block1.getblockhash()<<endl;
*/


/*  for(int i=0; i!=test.size(); i++){
        cout << test[i].getTranactionId() << endl;
        cout << test[i].getSender() << endl;
        cout << test[i].getResever() << endl;
        cout << test[i].getAmount() << endl;
    }*/
   /*int index= tusers.finduser("vartotojas6");
   cout << index << endl;
   tusers.addmoneytouser(index, 69);
   tusers.savetofile("test.txt");*/