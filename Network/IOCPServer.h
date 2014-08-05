#pragma once

#pragma comment( lib, "ws2_32.lib" )

#include <windows.h>
#include <map>

class NetworkObject;
class IoHandler;

typedef std::map<DWORD, IoHandler*>		IOHANDLER_MAP;
typedef std::pair<DWORD, IoHandler*>	IOHANDLER_MAP_PAIR;
typedef IOHANDLER_MAP::iterator			IOHANDLER_MAP_ITER;

typedef NetworkObject* (*fnCallBackCreateAcceptedObject)();
typedef VOID (*fnCallBackDestroyAcceptedObject)( NetworkObject *pNetworkObject );
typedef VOID (*fnCallBackDestroyConnectedObject)( NetworkObject *pNetworkObject );

//-------------------------------------------------------------------------------------------------
/// I/O �ڵ鷯 �ʱ�ȭ�� �ʿ��� ������ ��� ����ü
//-------------------------------------------------------------------------------------------------
typedef struct tagIOHANDLER_DESC
{
	DWORD								dwIoHandlerKey;					///< I/O ��
	DWORD								dwMaxAcceptSession;				///< ��������
	DWORD								dwMaxConnectSession;			///< ���ȴ�������
	DWORD								dwSendBufferSize;				///< ���ͻ��峤��
	DWORD								dwRecvBufferSize;				///< ���ջ��峤��
	DWORD								dwTimeOut;						///< ������ʱ��
	DWORD								dwMaxPacketSize;				///< ������󳤶�
	DWORD								dwNumberOfIoThreads;			///< I/O �߳���
	DWORD								dwNumberOfAcceptThreads;		///< Accept �߳���
	DWORD								dwNumberOfConnectThreads;		///< Connect �߳���
	fnCallBackCreateAcceptedObject		fnCreateAcceptedObject;			///< 
	fnCallBackDestroyAcceptedObject		fnDestroyAcceptedObject;		///<		�ص�����ָ��
	fnCallBackDestroyConnectedObject	fnDestroyConnectedObject;		///< 
} IOHANDLER_DESC, *LPIOHANDLER_DESC;

//-------------------------------------------------------------------------------------------------
/// IOCP ���� Ŭ����
/**
	@remarks
			- IOCP ���� I/O �̳߳ع���
			- Update �ڸú����д������ݣ�Ҫ���ⲿѭ������.
	@see
			IoHandler
			tagIOHANDLER_DESC
*/
//-------------------------------------------------------------------------------------------------
class IOCPServer
{
	friend unsigned __stdcall send_thread( LPVOID param );

public:
	IOCPServer();
	virtual ~IOCPServer();

	BOOL				Init( LPIOHANDLER_DESC lpDesc, DWORD dwNumberofIoHandlers );
	BOOL				StartListen( DWORD dwIoHandlerKey, char *pIP, WORD wPort );
	VOID				Update();
	VOID				Shutdown();
	DWORD				Connect( DWORD dwIoHandlerKey, NetworkObject *pNetworkObject, char *pszIP, WORD wPort, DWORD dwSendBufferSize, DWORD dwRecvBufferSize, DWORD dwMaxPacketSize );
	BOOL				IsListening( DWORD dwIoHandlerKey );
	DWORD				GetNumberOfConnections( DWORD dwIoHandlerKey );

private:
	BOOL				InitWinsock();
	VOID				CreateIoHandler( LPIOHANDLER_DESC lpDesc );

	HANDLE				m_hSendThread;
	BOOL				m_bShutdown;
	IOHANDLER_MAP		m_mapIoHandlers;
};
