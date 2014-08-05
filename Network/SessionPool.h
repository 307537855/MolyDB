#ifndef _SESSIONPOOL_H_
#define _SESSIONPOOL_H_

#include <windows.h>
#include <vector>

using namespace std;

class Session;
class Session;
class SessionList;

//=============================================================================================================================
/// Session�����
//		Session�Ķ���ӿ� ���е�Session���ٶ�Ҫ��������ط�
//=============================================================================================================================
class SessionPool
{
public:
	SessionPool( DWORD dwSize, DWORD dwSendBufferSize, DWORD dwRecvBufferSize, DWORD dwMaxPacketSize, DWORD dwTimeOutTick, DWORD dwIndexStart, BOOL bAcceptSocket );
	~SessionPool();

	Session*		Alloc();
	void			Free( Session* pSession );
	int				GetLength();

private:
	VOID			Create( DWORD dwSize, DWORD dwSendBufferSize, DWORD dwRecvBufferSize, DWORD dwTimeOutTick, DWORD dwMaxPacketSize, DWORD dwIndexStart, BOOL bAcceptSocket );

	DWORD			m_dwMaxSize;
	SessionList		*m_pList;
};

#endif
