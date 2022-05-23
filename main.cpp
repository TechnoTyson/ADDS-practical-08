#include "Node.h"
#include "LinkedList.h"
#include <array>
#include <iostream>
#include <string>

int main(){
    std::array<int,100> values;
    std::string function;
    int param1;
    int param2;
    std::string input;
    int count = 0;
    bool ischar = false;

    do{
        std::cin >> input;
        if (isdigit(input.at(0))){
            values.at(count) = std::stoi(input);
            count++;
        }
        else{
            function = input;
            ischar = true;
            break;
        }
    }while(ischar == false);
    std::cin >> param1;
    std::cin >> param2;


    LinkedList* list = new LinkedList(&values.at(0), count);

    if (function == "AF"){
        list->addFront(param1);
    }
    else if (function == "AE"){
        list->addEnd(param1);
    }
    else if (function=="AP"){
        list->addAtPosition(param1, param2);
    }
    else if (function=="S"){
        list->search(param1);
    }
    else if (function=="DF"){
        list->deleteFront();
    }
    else if (function=="DE"){
        list->deleteEnd();
    }
    else if (function=="DP"){
        list->deletePosition(param1);
    }
    else if (function=="GI"){
        list->getItem(param1);
    }
    else{
        std::cout << "error";
    }

    list->printItems();

    delete list;
    return 0;
}