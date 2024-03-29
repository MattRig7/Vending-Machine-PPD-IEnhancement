#include <iostream>
#include <limits>
#include <cctype>
#include <string>
#include "LinkedList.h"
#include "Purchase.h"
#include "Display.h"
#include "Coin.h"
using std::string;

// Checks if price input is valid in that it matches the required format
bool is_valid_price(const std::string &price_str) {
    bool decimal_point_found = false;
    bool is_valid = true; // Assuming the string the formatting requirements
    int digits_after_decimal = 0;

    for (const char &c : price_str) {
        if (c == '.') {
            if(decimal_point_found){
                is_valid = false; //if the decimal point appears twice, the string does not match the requirement
            }
            decimal_point_found = true;
        }else if (!std::isdigit(c)) // if the character is not a number
        {
            is_valid = false;
        }else if (decimal_point_found)
        {
            ++digits_after_decimal;
            if(digits_after_decimal > 2){
                is_valid = false; // if there are more than two decimal places after the decimal point
            }
        }
        
        
    }

    return is_valid && decimal_point_found && digits_after_decimal == 2;
}
/**
 * manages the running of the program, initialises data structures, loads
 * data, display the main menu, and handles the processing of options. 
 * Make sure free memory and close all files before exiting the program.
 **/

int main(int argc, char **argv)
{
    /* validate command line arguments */
    // TODO
    LinkedList stockList;
    LinkedList coinList;
    // Check if 3 command line parameters have been entered
    if (argc != 3){
        std::cerr << "Error:invalid arguments passed in. " << std::endl;
        std::cerr << "Correct arguments are:"<< std::endl << argv[0] << " <stockfile> <coinsfile>" << std::endl;
        std::cerr << "Where <stockfile> and <coinfile> are two valid files in the expected format." << std::endl;
        EXIT_FAILURE; 
    }

    const char* StockFile = argv[1];
    const char* CoinsFile = argv[2];

    string choice = "0";
    bool selection = false;

    while (selection == false){
    
    std::cout << "Please choose which version of the code to run:" << std::endl;
    std::cout << "1. Group Implementation" << std::endl;
    std::cout << "2. Individual Implementation" << std::endl;
    std::cout << "Enter: " << std::endl;
    std::cin >> choice;

    
    if (choice == "1"){
        stockList.loadStockData(StockFile);
        coinList.loadCoinsData(CoinsFile); 
        selection = true;
    }
    else if (choice == "2"){
        stockList.loadStockDataDLL(StockFile);
        coinList.loadCoinsDataDLL(CoinsFile);
        selection = true;
    }     
    else{
        std::cout << "Invalid choice. Only an integer 1 or 2 can be entered. "<< std::endl;
    }    
            
    }
    

    Purchase purchase(stockList);

    Display display;
    Coin coin;

    display.show_menu();

    string userInput = "";
    //int num = 0;
    while(std::cin>>userInput)
    {
        if(userInput == "1")
        {
        std::cout<<"\n";    
        std::cout<<"\n"; 
        std::cout<<"Items Menu\n";
        std::cout<<"----------\n";
        std::cout<<"ID   |Name \t\t\t\t |Available |Price\n";
        std::cout<<"------------------------------------------------------------\n";
        
        if (choice == "1"){
            stockList.displayItems();
        }
        else if (choice == "2"){
            stockList.displayItemsDLL();
        }
        std::cout<<"\n";
        
        display.show_menu();


        }
        else if(userInput == "2")
        {
            purchase.purchase_room();
        }

        else if(userInput == "3")
        {

            if (choice == "1"){
                stockList.saveStockData(StockFile);
                coinList.saveCoinsData(CoinsFile);
                stockList.freeMemory();
                coinList.freeMemory();
            }
            else if (choice == "2"){
                stockList.saveStockDataDLL(StockFile);
                coinList.saveCoinsDataDLL(CoinsFile);
                stockList.freeMemoryDLL();
                coinList.freeMemoryDLL(); 
            }
            exit(0);
        }
        else if(userInput == "4")
        {
            // Enter paramters which the new item will be based off
            std::cout<<"\n";  
            std::cout<<"\n";
            std::cout << "You will now add a new stock item to the Vending Machine:\n";


            std::string new_id = "";

            if (choice == "1"){
                Node* current = stockList.getHead();
                while (current != NULL){
                    Stock* stock = current->data;
                    new_id = stock->id;
                    new_id = new_id.substr(1);
                    int id = std::stoi(new_id) + 1;
                    std::string str = std::to_string(id);
                    if (str.length() == 1)
                    {
                        new_id = "I000" + str;
                    }else if (str.length() == 2)
                    {
                        new_id = "I00" + str;
                    }else if (str.length() == 3)
                    {
                        new_id = "I0" + str;
                    }else if (str.length() == 4)
                    {
                        new_id = "I" + str;
                    }
                    current = current->next;
            }
            }
            else if (choice == "2"){
                NodeDLL* current = stockList.getHeadDLL();
                while (current != NULL){
                    StockDLL* stock = current->data;
                    new_id = stock->id;
                    new_id = new_id.substr(1);
                    int id = std::stoi(new_id) + 1;
                    std::string str = std::to_string(id);
                    if (str.length() == 1)
                    {
                        new_id = "I000" + str;
                    }else if (str.length() == 2)
                    {
                        new_id = "I00" + str;
                    }else if (str.length() == 3)
                    {
                        new_id = "I0" + str;
                    }else if (str.length() == 4)
                    {
                        new_id = "I" + str;
                    }
                    current = current->next;
            }
            }
            
            std::string name, desc;
            double price = 0.0;
            int onHand = 10;

            std::cout << "The id of the new item will be: " << new_id << "\n";

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter the item name: ";
            std::getline(std::cin, name);

            std::cout << "Enter the item description: ";
            std::getline(std::cin, desc);
            bool flag = true;

            while (flag) {
                std::cout << "Enter item price (in the format x.yy): ";
                std::string price_str;
                std::getline(std::cin, price_str);
                if (is_valid_price(price_str)) {
                    price = std::stod(price_str);
                    flag = false;
                } else {
                    std::cout << "Invalid format. Please enter the price in the format x.yy.\n";
                }
            }

            // Extract dollars and cents from the user-in5put price
            int dollars = static_cast<int>(price);
            int cents = static_cast<int>((price - dollars) * 100 + 0.5); // Add 0.5 for rounding

            if (choice == "1"){
            // Add the item to the linked list using the addStock function and user-input parameters
                stockList.addStock(new_id, name, desc, dollars, cents, onHand);
            }
            else if (choice == "2"){
                stockList.addStockDLL(new_id, name, desc, dollars, cents, onHand);
            }

            std::cout<<"\n"; 
            std::cout << "This item: \""<< name << " - " << desc << "\" has now been added to the menu.\n";
            std::cout << "\n";

            display.show_menu();


        }
        else if(userInput == "5")
        {
            std::cout<<"\n"; 
            std::cout<<"\n"; 
            std::cout<<"You will now remove a stock item from the Vending Machine based on it's given ID:\n";
            
            std::string itemId;
            std::cout << "Enter the ID of the item you want to remove: ";
            std::cin >> itemId;
            stockList.removeItem(itemId);
            std::cout<<"\n";
            std::cout << "Item removed"<< std::endl;
            std::cout<<"\n";
            display.show_menu();
          }
          

     
        else if(userInput == "6")
        {
            std::cout<<"\n";  
            std::cout<<"\n";  
            if (choice == "1"){
                coinList.displayCoins(coinList);      
            }
            else if (choice == "2"){
                coinList.displayCoinsDLL(coinList);
            }
            std::cout<<"\n";     
            display.show_menu();

        }
        else if(userInput == "7")

        {   
            
            if (choice == "1"){
            Node* current = stockList.getHead();
            while (current != NULL) {
                Stock* stock = current->data;
                stock->ResetStock(stock);
                //std::cout << stock->on_hand << std::endl;
                current = current->next;
            }
            }
            else if (choice == "2"){
                NodeDLL* current = stockList.getHeadDLL();
                while (current != NULL) {
                    StockDLL* stock = current->data;
                    stock->ResetStockDLL(stock);
                    //std::cout << stock->on_hand << std::endl;
                    current = current->next;
            } 
            }
            std::cout<<"\n";  
            std::cout<<"\n";
            std::cout << "“All stock has been reset to the default level of " << DEFAULT_STOCK_LEVEL << "”" << std::endl;
            std::cout<<"\n";  
            display.show_menu();
        {
        }
            
        }
        else if(userInput == "8")
        {

            //coin->ResetCoins(coin);

            if (choice == "1"){
                Node* current = coinList.getHead();
                while (current != NULL) {

                    Coin* coin = current->data1;
                    coin->ResetCoins(coin);               
                    current = current->next;
                    
                }
            }    
            else if (choice == "2"){
                NodeDLL* current = coinList.getHeadDLL();
                while (current != NULL) {

                    Coin* coin = current->data1;
                    coin->ResetCoins(coin);               
                    current = current->next;
                    
                }
            }
            std::cout<<"\n";  
            std::cout << "“All coins has been reset to the default level of " << DEFAULT_COIN_COUNT << "”" << std::endl;
            std::cout<<"\n";  
            display.show_menu();

        }
        else if(userInput == "9")
        {
            exit(0);
        }

        else{
            std::cout << "Not a valid option selected. Please enter an integer from the following options:" << std::endl;
            display.show_menu();
        }
          
        }
    



}
