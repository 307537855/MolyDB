#pragma once

#include <windows.h>

class Session;

//-------------------------------------------------------------------------------------------------
/// NetworkObject
//	- fnCreateAcceptedObject ��������������С����Ԫ
//	  
//	- ��������Ҫʵ��(OnAccept, OnDisconnect, OnRecv, OnConnect)��������
//-------------------------------------------------------------------------------------------------
class NetworkObject
{
	friend class Session;
	friend class IoHandler;

public:
	NetworkObject();
	virtual ~NetworkObject();

	VOID			Disconnect( BOOL bGracefulDisconnect = TRUE );
	BOOL			Send( BYTE *pMsg, WORD wSize );
	BOOL			SendEx( DWORD dwNumberOfMessages, BYTE **ppMsg, WORD *pwSize );
	VOID			Redirect( NetworkObject *pNetworkObject );
	char*			GetIP();
	u_short			GetPort();
	int				GetNetIdx();

	VOID			SetSession(Session *pSession);


private:
	virtual VOID	OnAccept( DWORD dwNetworkIndex ) {}
	virtual VOID	OnDisconnect() {}
	virtual	VOID	OnRecv( BYTE *pMsg, WORD wSize ) = 0;
	virtual VOID	OnConnect( BOOL bSuccess, DWORD dwNetworkIndex ) {}
	virtual VOID	OnLogString( char *pszLog ) {}



	Session			*m_pSession;
	char			m_szIP[32];
	u_short			m_usPort;
};
