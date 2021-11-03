#ifndef BLOCKCHAIN_H_INCLUDED
#define BLOCKCHAIN_H_INCLUDED
#include "block.h"

bool checkifempty(ifstream& file){
  return file.peek() == std::ifstream::traits_type::eof();
}


class blockchain
{
private:
  
   vector<block> blocks;
   

public:
    blockchain();
    ~blockchain();
    //add block
    void gennewblock(string poolname, string usersname){
        pool tpool(poolname);
        users tusers(usersname);
        block newBlock;
         srand(time(NULL));
         int seed=rand()%1000000+1;
        newBlock.settimestamp();
       // cout<< "pog" << endl;
        newBlock.addtrasnactions(tpool, tusers, seed);
       // cout << "pog1" << endl;
        if(blocks.size()!=0){
           newBlock.setprevHash(blocks[blocks.size()-1].getblockhash()); 
        }
     //   cout << newBlock.gettransactions().size() << endl;
        newBlock.findnonce();
        newBlock.updatefiles(tpool, tusers);
        blocks.push_back(newBlock);

    }
    void mineblocks(string poolname, string usersname){
        //cout <<"pog"<< endl;
        vector<int> randomvalues;
        int noicesize=2000;
        int i=0;
        srand(time(NULL));
       /*  std::random_device dev;
    std::mt19937 rng(dev());
    vector<std::random_device> stuff;
    std::uniform_int_distribution<std::mt19937::result_type> dist1(1,1000); */

    for(int i=0; i<4; i++){
        randomvalues.push_back(rand()%1000000+1);
    }
        while (i==0){
            //cout << "pog3" << endl;
        for(int j=0; j<=4; ++j){
           // cout << "pog4" << endl;
        pool tpool(poolname);
        users tusers(usersname);
        block newBlock; 
        newBlock.settimestamp();
        newBlock.addtrasnactions(tpool, tusers, randomvalues[j]);
       cout << newBlock.gettransactionhash() << endl;
        if(blocks.size()!=0){
           newBlock.setprevHash(blocks[blocks.size()-1].getblockhash()); 
        }
        
        if(newBlock.findnoncecomp(noicesize)==true){
          //  cout << "pog2" << endl;
        newBlock.updatefiles(tpool, tusers);
        newBlock.setminer(to_string(j+1));
        blocks.push_back(newBlock); 
        i=1;
        break;
        
        }

        }
        noicesize=noicesize*2;
        }
        
    }
    void getInfoAboutBlock(int i){
    cout << blocks[i].getprevHash()<<endl;
    cout << blocks[i].getversion()<<endl;
    cout << blocks[i].gettimestamp()<<endl;
    cout << blocks[i].gettransactionhash()<<endl;
    cout << blocks[i].getnonce()<<endl;
    cout << blocks[i].getdifficulty()<<endl;
    cout << blocks[i].getblockhash()<<endl;
    cout << blocks[i].gettransactions().size()<<endl;
    }
    void getInfoAboutTransaction(int i){
        blocks[i].getalltransactions();
    }
    int getnumberofblocks(){
       return blocks.size();
    }
    block getblock(int i){
        return blocks[i];
    }
    void populateblockchain(string Fstring, string Sstring){
        int i=0;
        while(i!=1){
            ifstream file(Fstring);
           //  cout << i << endl;
             //cout <<checkifempty(file) << endl;
            if(checkifempty(file)==1){
                 i=1;
                 break;
            }
            //cout << i << endl;
            gennewblock(Fstring, Sstring);
           
        }

    }

};

blockchain::blockchain(/* args */)
{
}

blockchain::~blockchain()
{
}

#endif