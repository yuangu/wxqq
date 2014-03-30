#ifndef LOGIN_H
#define LOGIN_H
class Login
{
public:
	Login();
	void shakeHand();  //发送的	；
	void shakeHand(const char* buff, int lenth); //接收的；
};
#endif