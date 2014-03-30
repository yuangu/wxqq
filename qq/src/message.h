#ifndef  MESSAGE_H
#define  MESSAGE_H
#include "singleton.h"
#include <map>
#include <vector>
#include "evanet.h"

class MessageHandBase
{
public:
	virtual void run(const char* buff, int lenth)
	{

	}
};

template<typename T>
class MessageHand:public MessageHandBase
{
	typedef void (T::*pf)(const char*, int);
public:
	MessageHand(T* c, pf f)
	{
		m_this = c;
		m_func = f;
	};

	void run(const char* buff, int lenth)
	{
		(m_this->*m_func)(buff, lenth);
	}
public:
	T*    m_this;
	pf    m_func;

};

class MessageManager:public CSingleton<MessageManager>
{
public:
	template<typename T>
	void RegisterMessage(unsigned short messageId, void(T::*f)(const char*, int), T* t)
	{
		MessageHandBase* p_messageHand = new MessageHand<T>(t, f);
		std::map<unsigned short, std::vector<MessageHandBase*> >::iterator it = m_messageMap.find(messageId);
		if (it != m_messageMap.end())
		{
			it->second.push_back(p_messageHand);
			return;
		}
		std::vector<MessageHandBase*> handVector;
		handVector.push_back(p_messageHand);
		m_messageMap.insert(std::make_pair(messageId, handVector));
	}

	void epoll()
	{
		char buff[255];
		int recvLen = EvaNet::getInstance().epoll(buff, 255);
		if(recvLen > 0)
		{
			if (recvLen < 6) return;			
			short messageId;
			memcpy(&messageId, buff + 3, 2);

			std::map<unsigned short, std::vector<MessageHandBase*> >::iterator it = m_messageMap.find(messageId);
			if (it != m_messageMap.end())
			{
				for (std::vector<MessageHandBase*>::iterator itv = it->second.begin(); itv != it->second.end(); ++itv)
				{
					(**itv).run(buff + 10, recvLen - 11);  //去掉协议头和协议尾
				}
				return;
			}
		}
	}
private:
	std::map<unsigned short, std::vector<MessageHandBase*> > m_messageMap;
};



#endif