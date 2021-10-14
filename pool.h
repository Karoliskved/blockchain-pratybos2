#ifndef POOL_H_INCLUDED
#define POOL_H_INCLUDED

#include <string>
#include "transaction.h"
#include "user.h"

using std::string;
class pool
{
private:
    vector<transaction> alltransactions;
public:

// cons
pool(){

}
pool(string filename){
ifstream infile(filename);    
 for(int i=0; i!=10000; i++){
     string thash;  
string user1; 
string user2;
double amount; 

infile >> thash;
infile >> user1;
infile >> user2;
infile >> amount;
transaction newTransaction(thash, user1, user2, amount);
alltransactions.push_back(newTransaction);   
 }
}
// setters


//getters
transaction gettrasnaction(int i){
    return alltransactions[i];
}
void removetransaction(int i){
    alltransactions.erase(alltransactions.begin()+i);
}
void savetofile(string filename){
    ofstream offile(filename);
    for(int i=0; i!=alltransactions.size(); i++)
    {
    offile << alltransactions[i].getTranactionId() << endl;
    offile << alltransactions[i].getSender() << endl;
    offile << alltransactions[i].getResever() << endl;
    offile << alltransactions[i].getAmount() << endl;
    }
}
};








#endif