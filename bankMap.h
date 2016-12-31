/*
 * bankMap.h
 *
 *  Created on: 30 ���� 2016
 *      Author: Eitan Levin
 */

#ifndef BANK_MAP_H_
#define BANK_MAP_H_

#include <map>
#include <stdlib.h>
#include "bankAccount.h"
#include "Exceptions.h"

/*
 * In this file all the top level functions will be.
 * Any validation of password or otherwise is done here.
 * All actions are implemented here.
 */

using std::map;
typedef map<int, bankAccount> AccountsMap;
typedef AccountsMap::value_type Pair;
typedef AccountsMap::iterator Iterator;

class bankMap {
private:
	AccountsMap _innerMap;

public:
	bankMap() {
		_innerMap = new AccountsMap;
	}
	~bankMap() {
		delete _innerMap;
	}

	void openNewAccount(int accountNumber, int accountPass, int balance);
	int getAccountBalance(int accountNumber, int accountPass);
	void freezeAccount(int accountNumber, int accountPass);
	void unFreezeAccount(int accountNumber, int accountPass);
	bool depositToAccount(int accountNumber, int accountPass, int depositSum);
	bool withrawFromAccont(int accountNumber, int accountPass, int withrawSum);
	void transferMoney(int srcAccountNumber, int srcAccountPass, int DestAccountNumber, int amount);
	int takeComission(int accountNumber);
	int getPassword(int accountNumber, int accountPass);
	bool isAccountInMap(int accountNumber);

};

//This is the map for the bank accounts:
//BankMap bankAccountsMap;//TODO beware of duplication

#define SRC_ACCOUNT 1
#define DST_ACCOUNT 2



#endif /* BANK_MAP_H_ */