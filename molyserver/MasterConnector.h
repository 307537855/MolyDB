
#ifndef _MASTERCON_EBX2ET3_H_
#define _MASTERCON_EBX2ET3_H_


#include "NetworkObject.h"

class  MasterConnector: public NetworkObject
{

public:

private:
	virtual void	OnAccept(DWORD connindex);							// --���µ�������������
	virtual void	OnDisconnect();
	virtual	void	OnRecv(BYTE *pMsg, WORD wSize);						// --�ɹ���ȡ��һ��������Ϣ
	virtual void	OnConnect(BOOL bSuccess, DWORD dwNetworkIndex);

};
#endif