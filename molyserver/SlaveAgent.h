
#ifndef _SLAVEAGENT_J1BXE9T_H_
#define _SLAVEAGENT_J1BXE9T_H_


#include "NetworkObject.h"

class SlaveAgent : public NetworkObject
{
public:
private:

protected:
	virtual void	OnAccept(DWORD connindex);							// --���µ�������������
	virtual void	OnDisconnect();
	virtual	void	OnRecv(BYTE *pMsg, WORD wSize);						// --�ɹ���ȡ��һ��������Ϣ
	virtual void	OnConnect(BOOL bSuccess, DWORD dwNetworkIndex);

};
#endif