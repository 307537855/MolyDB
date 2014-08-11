// molyclient.cpp : Defines the entry point for the console application.
//

#include "NetBase.h"
#include "NetMsg.h "


CNetBase*			g_pNetBase;						// ����ӿ�

#define MAX_CONNECT_NUM 50
#define NET_MSG WM_USER + 100


void ProcessLTConnectMsg(int nConctID, MSG_BASE* pMsg)
{

	switch (pMsg->m_byProtocol)
	{
		case S2C_SVR_READY_CMD:
		{
			MSG_S2C_SVR_READY_CMD* pReadyMsg = (MSG_S2C_SVR_READY_CMD*)pMsg;
			printf("Connet server success!");
			int i = pReadyMsg->sHighVer;
		}break;

	default:
		break;
	}

}



//-----------------------------------------------------------------------------------------------------------------------
// Prototype	:		int	CMyAppDlg::ProcessLSMsg( char* pMsg )
// Function		:		�����½��������Ϣ
// Input  Param :		- 
// Output Param :		-
// Info			:		SXF	/ 2012.08.01 / 1.0
//-----------------------------------------------------------------------------------------------------------------------
int ServerPro( int nConctID, char* pMsg, int nLen )
{
	MSG_BASE* pMsgHead = (MSG_BASE*)pMsg;

	//������Ϣͷ
	switch( pMsgHead->m_byCategory )
	{
	case CS_LOGON:
		ProcessLTConnectMsg(nConctID, pMsgHead );
		break;

	//case HMsg_TLConnect:									// LoginServer
	//	ProcessLTConnectMsg( nConctID, pMsg );
	//	break;

	//case HMsg_TWConnect:									// --World����
	//	ProcessTWConnectMsg( nConctID, pMsg );
	//	break;

	}
	return 0;
}





int main(int argc, char* argv[])
{
	g_pNetBase = new CNetBase;
	g_pNetBase->InitNet( MAX_CONNECT_NUM, ServerPro, NULL, NET_MSG );
	g_pNetBase->ConncetToServer(8, "127.0.0.1", 3690 );

	while ( true )
	{
		Sleep(1000);
	}

	return 0;
}

