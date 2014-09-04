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
	int				GetNetIdx();

private:
	virtual VOID	OnAccept( DWORD dwNetworkIndex ) {}
	virtual VOID	OnDisconnect() {}
	virtual	VOID	OnRecv( BYTE *pMsg, WORD wSize ) = 0;
	virtual VOID	OnConnect( BOOL bSuccess, DWORD dwNetworkIndex ) {}
	virtual VOID	OnLogString( char *pszLog ) {}

	inline VOID		SetSession( Session *pSession ) { m_pSession = pSession; }

	Session			*m_pSession;
};
