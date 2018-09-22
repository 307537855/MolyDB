#ifndef _CLIENTAGENT_U53XE9J_H_
#define _CLIENTAGENT_U53XE9J_H_


#include "NetworkObject.h"


class ClientAgent : public NetworkObject
{
public:
	ClientAgent();
	~ClientAgent();
	BOOL			Send(BYTE *pMsg, WORD wSize);

protected:
	virtual void	OnAccept(DWORD connindex);							// --���µ�������������
	virtual	void	OnRecv(BYTE *pMsg, WORD wSize);						// --�ɹ���ȡ��һ��������Ϣ
	virtual void	OnConnect(BOOL bSuccess, DWORD dwNetworkIndex);
	virtual VOID	OnDisconnect();

	

private:
	int				m_iAgentType;

	inline bool		CheckSvrReady(); 
	inline void		ReplyResult( int iRes );

	int				m_iPageView = 0;

};


#endif