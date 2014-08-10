#pragma once
#include "NetMsg.h"
#include "ClientStruct.h"
#include "GDefines.h"

#pragma pack( push )
#pragma pack( 1 )


const BYTE HMsg_TLConnect	= 10;			// --������֤

enum enSCConnectAuth
{
	l2t_AUTH_CONNECT_ACK	= 1,			// --��½׼�����
	t2l_AUTH_VERSION_SYN	= 2,			// --�汾��֤����
	l2t_AUTH_VERSION_ACK	= 3,			// --�汾��֤����
	t2l_AUTH_VERIFY_SYN		= 101,			// --������֤����
	l2t_AUTH_VERIFY_ACK		= 5,			// --������֤����
	l2t_AUTH_GMINFO_ACK		= 105,			// --������֤����
	t2l_AUTH_SVRLIST_SYN	= 6,			// --�������б�����
	l2t_AUTH_SVRLIST_ACK	= 10,			// --�������б���
	t2l_AUTH_SELESVR_SYN	= 8,			// --������ѡ������
	l2t_AUTH_SELESVR_ACK	= 9,			// --������ѡ����
};


BEGIN_MAKE_MSG_CLASS( HMsg_TLConnect, l2t_AUTH_CONNECT_ACK )
DWORD	m_dwEncKey;
END_MAKE_MSG_CLASS()


BEGIN_MAKE_MSG_CLASS( HMsg_TLConnect, t2l_AUTH_VERSION_SYN )
BYTE		m_byHVersion;							// --�汾
BYTE		m_byMVersion;
BYTE		m_byLVersion;
char		m_szLocalIP[MAX_IP_ADDR_LEN];
END_MAKE_MSG_CLASS()


BEGIN_MAKE_MSG_CLASS( HMsg_TLConnect, l2t_AUTH_VERSION_ACK )
BYTE		m_byResult;
END_MAKE_MSG_CLASS()


BEGIN_MAKE_MSG_CLASS( HMsg_TLConnect, t2l_AUTH_VERIFY_SYN )
DWORD		m_dwAuthUserID;							// --��֤ ������ID��
char		m_szID	[MAX_USER_ID_LEN];				// --�ʺ�
char		m_szPwd [MAX_PASSWORD_LEN];				// --����
END_MAKE_MSG_CLASS()


BEGIN_MAKE_MSG_CLASS( HMsg_TLConnect, l2t_AUTH_VERIFY_ACK )
short		m_sErrCode;
END_MAKE_MSG_CLASS()


BEGIN_MAKE_MSG_CLASS( HMsg_TLConnect, t2l_AUTH_SVRLIST_SYN )
END_MAKE_MSG_CLASS()


BEGIN_MAKE_MSG_CLASS( HMsg_TLConnect, l2t_AUTH_SVRLIST_ACK )
BYTE		m_bySvrCnt;								// --����������
AGENT_SERVER_INFO m_szServerList[MAX_SERVERS_CNT];	// --�б�
END_MAKE_MSG_CLASS()


BEGIN_MAKE_MSG_CLASS( HMsg_TLConnect, t2l_AUTH_SELESVR_SYN )
USHORT		m_usSvrIndex;							// ѡ��Ƶ��������ID
END_MAKE_MSG_CLASS()


BEGIN_MAKE_MSG_CLASS( HMsg_TLConnect, l2t_AUTH_SELESVR_ACK )
DWORD		m_dwAuthUserID;							// LoginServer �����KEY ����ʹ�����KEY���ܵ�½��AgentServer
BYTE		m_szSerialKey[MAX_AUTH_KEY_LEN];		// connection 
char		m_szSvrIP[MAX_IP_ADDR_LEN];				// ��Ϸ ������ IP
DWORD		m_dwSvrPort;							// ��Ϸ ������ 
BYTE		m_byResult;								//
END_MAKE_MSG_CLASS()


BEGIN_MAKE_MSG_CLASS( HMsg_TLConnect, l2t_AUTH_GMINFO_ACK )
short		m_sGMRightLv;
DWORD		m_dwGMGuid;
END_MAKE_MSG_CLASS()


#pragma pack( pop )