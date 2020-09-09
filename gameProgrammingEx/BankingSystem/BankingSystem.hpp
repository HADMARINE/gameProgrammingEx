//
//  BankingSystem.hpp
//  gameProgrammingEx
//
//  Created by 이호준 on 2020/08/24.
//  Copyright © 2020 HADMARINE. All rights reserved.
//

#ifndef BankingSystem_hpp
#define BankingSystem_hpp

#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;



namespace BankingSystem {

class Account {
private:
    string id;
    int amount;
    string customerName;
public:
    string getId(void);
    void setId(string id);
    int getAmount(void);
    void changeAmount(int amount);
    void setCustomerName(string customerName);
    string getCustomerName(void);
    Account(string id, int amount, string customerName);
};

void CreateAccount(void);
void DepositMoney(bool);
void ShowAccount(void);
void ShowAllAccountInfo(void);
void DeleteAccount(void);
int main(void);
namespace ChoiceStatus {
enum {CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, INQUIRE_ALL, DELETE, EXIT};
}
}

#endif /* BankingSystem_hpp */
