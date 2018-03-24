
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



void main()
{
    printf("hello blockchain: \n");
    
    BlockChain chainOne = bcNew();
    printf("%d",bcLen(chainOne));

    TransactionList list = tlistCreate();
    
    tlistAppend(&list,"Keaton",420,"Carter");
    tlistAppend(&list,"Bob",420000,"Bill");
   // tlistAppend();
    Block_t* block = blkCreate(list, 2, NULL_NONCE);
    
    Puzzle_t p = blkCreatePuzzle(*block, NULL_HASH);
    
    block->proof_of_work = puzzleMine(p);

    
    assert(bcLen(chainOne)==0);


   // tlistPrint(block->transactions);
   // tlistPrint(chainOne.head->transactions);
    
    bcAppend(&chainOne, block);
    
    bcPrint(chainOne);
  /*  Block_t* t = chainOne.head->next;
    tlistPrint(t->transactions);
    tlistPrint(t->prev->transactions);
    
    tlistPrint(t->next->transactions); // should seg fault
*/

    printf("%d",bcLen(chainOne));
    
    

    
  
  
    
}