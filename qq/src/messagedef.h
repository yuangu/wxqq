#ifndef MESSAGEDEF_H
#define MESSAGEDEF_H

#include <cstring>
inline unsigned short toShort(const char* twoByte)
{
	unsigned short messageId = 0;
	memcpy(&messageId, twoByte, 2);
	return messageId;
}

/*QQ��Ϣ����*/
#pragma pack(push) //�������״̬
#pragma pack(1)//�趨Ϊ4�ֽڶ���
struct QQHeader
{
	char head;
	char version[2];
	char cmd[2];
	char serial[2];
	char id[4];
};

struct QQTail
{
	char tail;
};

#pragma pack(pop)
#endif