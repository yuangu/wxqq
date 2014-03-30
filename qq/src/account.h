#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "singleton.h"

/*’ ∫≈–≈œ¢*/
class Account:public CSingleton<Account>
{
public:
	int id;
	char version[2];
	char passwd[50];


};
#endif