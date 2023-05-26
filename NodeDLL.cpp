#include "NodeDLL.h"
#include <iostream>
using std::string;
//using std::vector;

NodeDLL::NodeDLL(){
    // TODO
    data = new StockDLL();
    next = nullptr;
    prev = nullptr;
};
NodeDLL::~NodeDLL(){
    // TODO
   delete data;

};

void StockDLL::ResetStockDLL(StockDLL* stock){

    //loops through linkedlist
    //sets all stock::on_hand values to DEFAULT_STOCK_LEVEL 20

    stock->on_hand = DEFAULT_STOCK_LEVEL;

}

// void Coin::ResetCoins(Coin* coin){

//     //resets coins to correct denomination
//     //DEFAULT_COIN_COUNT 20

//     coin->count = DEFAULT_COIN_COUNT;
    

// }

   
