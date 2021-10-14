#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

#include <string>
#include "transaction.h"
#include "user.h"

using std::string;
class users
{
private:
    vector<user> allusers;
public:

// cons
users(){

}
users(string filename){
ifstream infile(filename);    
 for(int i=0; i!=1000; i++){
string thash;  
string user1; 
double amount; 
infile >> user1;
infile >> thash;
infile >> amount;
user newUser(user1, thash,  amount);
allusers.push_back(newUser);   
 }
}
// setters


//getters
user getuser(int i){
    return allusers[i];
}
void removeuser(int i){
    allusers.erase(allusers.begin()+i);
}
int finduser(string name_){
    int index;
    auto it = find_if(allusers.begin(), allusers.end(), [&name_](user& obj) {return obj.getname() == name_;});
    if (it != allusers.end())
{
 
   index = distance(allusers.begin(), it);
}
return index;
}
void addmoneytouser(int i, double amount){
    allusers[i].addmoney(amount);
}
void takemoneyfromusser(int i, double amount){
    allusers[i].takemoney(amount);
}
double userbalance(int i){
    return allusers[i].getsum();
}
void savetofile(string filename){
    ofstream offile(filename);
    for(int i=0; i!=allusers.size(); i++)
    {
    offile << allusers[i].getname() << endl;
    offile << allusers[i].getuserhash() << endl;
    offile << allusers[i].getsum() << endl;
    
    }
}
int returnsize(){
    return allusers.size();
}
};








#endif