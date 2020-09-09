//
//  BankingSystem.cpp
//  gameProgrammingEx
//
//  Created by 이호준 on 2020/08/24.
//  Copyright © 2020 HADMARINE. All rights reserved.
//

#include "BankingSystem.hpp"


namespace BankingSystem {

string Account::getId() {
    return this->id;
}

void Account::setId(string id) {
    this->id = id;
}

int Account::getAmount() {
    return this->amount;
}

void Account::changeAmount(int amount) {
    this->amount += amount;
}

void Account::setCustomerName(string customerName) {
    this->customerName = customerName;
}

string Account::getCustomerName() {
    return this->customerName;
}

Account::Account(string id, int amount, string customerName) {
    this->id = id;
    this->amount = amount;
    this->customerName = customerName;
};



vector<Account*> *accountVector = new vector<Account*>;

//void

int main() {
    int *choice_number = new int;
    bool *flag = new bool;
    *flag = true;
    *choice_number = -1;
    while (*flag) {
        cout << "-----계좌 관리 시스템-----" << endl << "1. 계좌 개설" << endl << "2. 입 급" << endl << "3. 출 금" << endl << "4. 계좌 정보 출력" << endl << "5. 계좌 정보 전체 출력" << endl << "6. 계좌 삭제" << endl << "7. 프로그램 종료"  << endl << "선택 : ";
        cin >> *choice_number;
        switch (*choice_number) {
            case ChoiceStatus::CREATE:
                CreateAccount();
                break;
            case ChoiceStatus::DEPOSIT:
                DepositMoney(true);
                break;
            case ChoiceStatus::WITHDRAW:
                DepositMoney(false);
                break;
            case ChoiceStatus::INQUIRE:
                ShowAccount();
                break;
            case ChoiceStatus::INQUIRE_ALL:
                ShowAllAccountInfo();
                break;
            case ChoiceStatus::DELETE:
                DeleteAccount();
                break;
            case ChoiceStatus::EXIT:
                *flag = false;
                break;
            default:
                cout << "잘못 선택하셨습니다." << endl;
                break;
        }
    }
    delete flag;
    delete choice_number;
    delete accountVector;
    return 0;
}

void CreateAccount() {
    string *id = new string , *customerName = new string;
    int *amount = new int;
    
    cout << "계정을 생성합니다. " << endl << "계좌번호를 입력해주세요 : ";
    cin >> *id;
    for (int i = 0; i < accountVector->size(); i++) {
        if(accountVector->at(i)->getId() == *id) {
            cout << "이미 등록되어있는 계좌번호입니다." << endl;
            delete id;
            delete amount;
            delete customerName;
            return;
        }
    }
    cout << "액수를 입력해주세요 : ";
    cin >> *amount;
    cout << "예금주를 입력해주세요 : ";
    cin >> *customerName;
    
    
    
    Account *accPtr = new Account {*id, *amount, *customerName};
    accountVector->push_back(accPtr);
    accPtr = nullptr;
    delete id;
    delete amount;
    delete customerName;
}

Account* findAccount() {
    string *choice = new string;
    Account *find_data = nullptr;
    
    cout << "계좌번호를 입력해주세요 : ";
    cin >> *choice;
    for (int i = 0; i < accountVector->size(); i++) {
        if(accountVector->at(i)->getId() == *choice) {
            find_data = accountVector->at(i);
        }
    }
    
    delete choice;
    return find_data;
}

void DepositMoney(bool isPlus) {
    Account* find_data = findAccount();
    
    if(find_data == nullptr) {
        cout << "계좌를 찾을 수 없습니다." << endl;
        delete find_data;
        return;
    }
    
    int *changeValue = new int;
    
    cout << "액수 증감값을 입력해주세요 : ";
    cin >> *changeValue;
    
    if(*changeValue < 0) {
        cout << "금액은 양수이어야 합니다." << endl;
        delete changeValue;
        return;
    }
    
    if(!isPlus) {
        *changeValue = - *changeValue;
    }
    
    if(find_data->getAmount() < - *changeValue) {
        cout << "잔고가 부족합니다." << endl;
        delete changeValue;
        return;
    }
    
    find_data->changeAmount(*changeValue);
    
    cout << "변경이 완료되었습니다." << endl;
    delete changeValue;
}

void ShowAccount(void) {
    Account* find_data = findAccount();
    
    if(find_data == nullptr) {
        cout << "계좌를 찾을 수 없습니다." << endl;
        return;
    }
    
    cout << "계좌번호 : " << find_data->getId() << " 보유 잔고 : " << find_data->getAmount() << " 예금주 : " << find_data->getCustomerName() << endl;
}

void ShowAllAccountInfo(void) {
    for (int i = 0; i < accountVector->size(); i++) {
        Account *find_data = accountVector->at(i);
        cout << "계좌번호 : " << find_data->getId() << " 보유 잔고 : " << find_data->getAmount() << " 예금주 : " << find_data->getCustomerName() << endl;
    }
}

void DeleteAccount(void) {
    Account* find_data = findAccount();
    if(find_data == nullptr) {
        cout << "계좌를 찾을 수 없습니다." << endl;
        return;
    }
    for (int i = 0; i < accountVector->size(); i++) {
        if(accountVector->at(i)->getId() == find_data->getId()) {
            delete (*accountVector).at(i);
            accountVector->erase(accountVector->begin() + i);
        }
    }
}

}
