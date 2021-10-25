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
        blocks.push_back(newBlock);

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