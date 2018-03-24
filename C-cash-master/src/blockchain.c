/**
 *  BlockChain ADT : private implementation / algorithms
 *
 *  COMP220: Assignment 3
 *  Author:  
 *  Date:    Feb. 1, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#include "trnslist.h"
#include "puzzle.h"
#include "block.h"
#include "blockchain.h"

/***********************
 * BLOCKCHAIN private implementation details
 ***********************/
const int DEFAULT_DIFFICULTY = 2;              // Default difficulty for hashing puzzles, increase to make mining harder

/*********************
 *  PUBLIC INTERFACE
 *********************/
 
/*
 * Constructor - return a new, empty BlockChain 
 * POST:  bcLen(chain) == 0
 */
BlockChain bcNew()
{
    TransactionList firstList = tlistCreate();
    Block_t* firstBlock = blkCreate(firstList, DEFAULT_DIFFICULTY, NULL_NONCE);
    BlockChain b = {firstBlock,firstBlock};
    
    return b;
}

/*
 * Destructor - remove all data and free all memory associated with the chain 
 * POST: bcLen(chain) == 0
 */
void bcDelete( BlockChain *chain ); 

/*
 * Print a text representation of this chain on STDOUT
 */
void bcPrint( const BlockChain chain )
{
    Block_t* p = chain.head;
    
    while (p != NULL){
        tlistPrint(p->transactions);
        p = p->next;
    }
   //tlistPrint(chain);
    
}

/*
 * Return the number of Blocks in the chain
 */
int bcLen( const BlockChain chain )
{
    int i = 0; 
    Block_t* p = chain.head;
    
    while (p != NULL){
        i++;
        p = p->next;
    }
    return i-1;
}

/*
 *  Return true iff blkIsValid(block) for every block in the chain
 */
bool bcIsValid(const BlockChain chain)
{
    
}


/*
 * Return a pointer to the chain's tail Block
 */
Block_t* bcTail(const BlockChain chain)
{
    return chain.tail;
}

/*
 * Append the given block to the chain 
 *    iff blkValidates(new_block, bcTail->hash, new_block->proof_of_work)
 * POST: bcTail(*chain) == new_block && blkIsValid(*new_block)
 */
void bcAppend( BlockChain* chain, Block_t* new_block )
{
    chain->tail->next = new_block;
    new_block->prev = chain->tail;
    chain->tail = new_block;
}
