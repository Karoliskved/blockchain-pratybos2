#ifndef BLOCKCHAIN_H_INCLUDED
#define BLOCKCHAIN_H_INCLUDED
#include "block.h"

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
        newBlock.settimestamp();
        newBlock.addtrasnactions(tpool, tusers);
        if(blocks.size()!=0){
           newBlock.setprevHash(blocks[blocks.size()-1].getblockhash()); 
        }
        
        newBlock.findnonce();
        newBlock.updatefiles(tpool, tusers);
        blocks.push_back(newBlock);

    }
    void mineblocks(string poolname, string usersname){
        //cout <<"pog"<< endl;
        vector<vector<int>> randomvalues;
        int noicesize=2000;
        int i=0;
         std::random_device dev;
    std::mt19937 rng(dev());
    vector<std::random_device> stuff;
    std::uniform_int_distribution<std::mt19937::result_type> dist1(1,1000); 
    for(int i=0; i<4; i++){
        for(int k=0; k<10000; k++){
        
            randomvalues[i].push_back(dist1(dev));
        }

    }
        while (i==0){
            //cout << "pog3" << endl;
        for(int j=1; j<=5; ++j){
           // cout << "pog4" << endl;
        pool tpool(poolname);
        users tusers(usersname);
        block newBlock; 
        newBlock.settimestamp();
        newBlock.addtrasnactions(tpool, tusers);
        cout << newBlock.gettransactionhash() << endl;
        if(blocks.size()!=0){
           newBlock.setprevHash(blocks[blocks.size()-1].getblockhash()); 
        }
        
        if(newBlock.findnoncecomp(noicesize)==true){
          //  cout << "pog2" << endl;
        newBlock.updatefiles(tpool, tusers);
        newBlock.setminer(to_string(j));
        blocks.push_back(newBlock); 
        i=1;
        break;
        
        }

        }
        noicesize=noicesize*2;
        }
        
    }

    block getblock(int i){
        return blocks[i];
    }
};

blockchain::blockchain(/* args */)
{
}

blockchain::~blockchain()
{
}

#endif