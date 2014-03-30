#include "login.h"
#include "message.h"
#include "messagedef.h"


Login::Login()
{
	MessageManager::getInstance().RegisterMessage( toShort("\x2f\x35"), &Login::shakeHand, this);
}

void Login::shakeHand()
{
	QQHeader head;
}

void Login::shakeHand(const char* buff, int lenth)
{

}