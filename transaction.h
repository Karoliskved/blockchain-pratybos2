#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include <string>
using std::string;
class transaction
{
private:
    string transactionId;
    string sender;
    string resever;
    double amount;
public:

// cons
transaction(){

}
transaction(string transactionId_, string sender_, string resever_, double amount_){
   transactionId=transactionId_;
   sender=sender_;
   resever=resever_;
   amount=amount_;
}
// setters
void setTranactionId(string transactionId_){
    transactionId=transactionId_;
}
void setSender(string sender_){
    sender=sender_;
}
void setResever(string resever_){
    resever=resever_;
}
void setAmount( double amount_){
    amount=amount_;
}

//getters
 string getTranactionId(){
     return transactionId;

 }
 string getSender(){
     return sender;

 }
 string getResever(){
     return resever;

 }
 int getAmount(){
     return amount;
 }
 string getData(){
     return sender+resever+to_string(amount);
 }
};








#endif