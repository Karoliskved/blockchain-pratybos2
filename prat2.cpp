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
  int n;
blockchain blockchaintest;
string string1="transactions.txt", string2="vartotojai.txt";
std::chrono::duration<double> diff;
std::chrono::duration<double> diff1;
cout << "pasirinkite uzduoti" <<endl;
cin >> n;
if(n==1){
  auto start = std::chrono::high_resolution_clock::now();
  blockchaintest.gennewblock(string1, string2);
  auto end = std::chrono::high_resolution_clock::now();
  diff+=(end-start);
   std::cout << "1 bloko generavimas " << diff/std::chrono::milliseconds(1) << " ms\n";
    blockchaintest.getInfoAboutBlock(0);

    auto start1 = std::chrono::high_resolution_clock::now();
blockchaintest.gennewblock(string1, string2);
auto end1 = std::chrono::high_resolution_clock::now();
cout << "second block" << endl;
diff1+=(end1-start1);
   std::cout << "1 bloko generavimas " << diff1/std::chrono::milliseconds(1) << " ms\n";
 blockchaintest.getInfoAboutBlock(1);
}
if(n==2){
  blockchaintest.mineblocks(string1, string2);
   blockchaintest.getInfoAboutBlock(0);
}
if(n==3){
  int i;
  blockchaintest.populateblockchain(string1, string2);
  cout << blockchaintest.getnumberofblocks() << endl;

  while(i!=-1){
    cout << "issirinkite block ivede skaiciu arba baikite procesa ivede -1" << endl;
    cin >> i;
    if(i==-1){
      break;
    }
    if(i>blockchaintest.getnumberofblocks()){
      cout <<"ivestas blokas neegzistuoja" << endl;
    }
    else{
      blockchaintest.getInfoAboutBlock(i-1);
    }
  }
}

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