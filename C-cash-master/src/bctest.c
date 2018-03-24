
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "trnslist.h"
#include "puzzle.h"
#include "block.h"
#include "blockchain.h"

          // Default difficulty for hashing puzzles, increase to make mining harder

void makeNewBlock(TransactionList list, BlockChain* chainOne)
{
    Block_t* block = blkCreate(list, 2, NULL_NONCE); //make block
    bcAppend(chainOne, block);
    Puzzle_t p = blkCreatePuzzle(*block, block->prev->hash); //make puzzle
    block->proof_of_work = puzzleMine(p); // assing proof of work to block
}


void main()
{
    printf("hello blockchain: \n");
    
    BlockChain chainOne = bcNew(); //Creates a blockchain
    printf("%d",bcLen(chainOne));

    TransactionList list = tlistCreate();
    tlistAppend(&list,"Keaton",420,"Carter");
    tlistAppend(&list,"Bob",2100,"Bill");
    tlistAppend(&list,"Isabelle",50,"Keaton");
    
    makeNewBlock(list,&chainOne); //makes a new block and adds it to the chain
    assert(bcLen(chainOne)==1);
    
    TransactionList listTwo = tlistCreate();
    tlistAppend(&listTwo,"Cooper",4220,"Cohen");
    tlistAppend(&listTwo,"Carter",21020,"Keaton");
    tlistAppend(&listTwo,"Jo",505,"Bob");
    
    makeNewBlock(listTwo, &chainOne);
    assert(bcLen(chainOne)==2);
    
    TransactionList listThree = tlistCreate();
    tlistAppend(&listThree,"John",4220,"Joe");
    tlistAppend(&listThree,"Bill",21020,"Other Bill");
    tlistAppend(&listThree,"Joe",505,"Henry");

    makeNewBlock(listThree, &chainOne);
    assert(bcLen(chainOne)==3);

    bcPrint(chainOne);
   
    Block_t* tailTest = bcTail(chainOne);
    if(tailTest->id == 4){
        printf("Tail is at correct ID\n");
    }
    
    if(bcIsValid(chainOne)){ //checks is the blockchain is valid 
        printf("BLOCKCHAIN IS VALID\n");
    }else{
        printf("BLOCKCHAIN IS NOT VALID\n");
    }
    
    bcDelete(&chainOne); //deletes the blockchain
    //NOTE: THIS DELETES THE "DUMMY" BLOCK ASWELL, YOU CANNOT ACCESS THE chainOne BLOCKCHAIN AFTER THIS HAS BEEN CALLED
}

