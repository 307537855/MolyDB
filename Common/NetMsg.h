#ifndef __NETPROTOCOL_CS_H__
#define __NETPROTOCOL_CS_H__


/*   ���ṹ�������� Jake.Sun
1) ����(Request)						_SYN
2) ����Ӧ��(Answer)					_ACK
3) ֪ͨ(Command)						-CMD
4) �㲥(Broadcasting)				_BRD
*/


// --��ϢЭ��
#define		CS_CATEGORY_LENGTH		40
#define		WS_CATEGORY_LENGTH		50
#define		DS_CATEGORY_LENGTH		100

enum
{
	CS_CATEGORY_BASE	=	10,
	WS_CATEGORY_BASE	=	CS_CATEGORY_BASE + CS_CATEGORY_LENGTH,
	DS_CATEGORY_BASE	=	WS_CATEGORY_BASE + WS_CATEGORY_LENGTH,
};


enum eCS_CATEGORY
{
	CS_LOGON		= CS_CATEGORY_BASE,				// --��½��Ϣ����
	WS_DATA			= WS_CATEGORY_BASE,				// --
};


// --��¼��֤
enum eCS_LOGON
{
	S2C_SVR_READY_CMD		= 0,			// --S2C:������׼��
	S2C_GERERAL_RES_CMD		= 4,			// --S2C:�Ͽ�����
	S2C_SELECT_ITEM_ACK		= 6,			// --S2C:��ѯ�ظ�


	C2S_INSERT_ITEM_SYN		= 51,			// --C2S:������뵥����Ŀ
	C2S_REMOVE_ITEM_SYN		= 55,			// --C2S:����ɾ��������Ŀ
	C2S_UPDATE_ITEM_SYN		= 57,			// --C2S:������µ�����Ŀ
	C2S_SELECT_ITEM_SYN		= 59,			// --C2S:�����ѯ������Ŀ
};



// --��¼��֤
enum eWS_AUTH
{
	W2S_WSCONNECTED_CMD	= 0,				// --W2S:Web����������֪ͨ
	S2W_PUSHSVRAUTH_SYN	= 1,				// --S2W:���ͷ�������֤����
	W2S_AUTH_RESULT_ACK	= 2,				// --W2S:���ͷ�������֤����
	W2S_NEWORDERBRD_CMD	= 4,				// --W2S:���������㲥����

	S2W_TEST_ORDER_SYN	= 52,				// --S2W:�����µ�
};


#pragma pack(push,1)

//-------------------------------------------------------------------------------------------------------
// --������
// --������� Packet,���а��ĸ���
struct MSG_BASE
{
	BYTE						m_byCategory;	// Э�����
	BYTE						m_byProtocol;
};


/* ����: MSG_SERVER_TYPE
 * ˵��: ���������½��Ϣ��ָʾ�˷��������ͣ��ɣģ����ƣ��������������Ϣ
 */
struct MSG_SERVER_TYPE : public MSG_BASE
{
	BYTE						m_byServerType;					// ����������
 	char						m_szServerName[32];				// ����������
 	UINT16						m_nChanleID;					// ������ID
	UINT16						m_nServerID;					// ������ID	С���ڱ���Ψһ
	UINT16						m_nMaxPlayerCount;				// ����������û�����
};


struct MSG_DBPROXY_RESULT : public MSG_BASE
{
	void *						m_pData;
};



// --Server --> Client
class MSG_S2C_SVR_READY_CMD : public MSG_BASE
{
public:
	MSG_S2C_SVR_READY_CMD()
	{
		m_byCategory = CS_LOGON;
		m_byProtocol = S2C_SVR_READY_CMD;
	}
	SHORT		sHighVer;					// --�߰汾��
	SHORT		sLowVer;					// --�Ͱ汾��
	int			iEncKey;					// --��Կ
};



// --Client-->Server ������д��һ������
class MSG_C2S_INSERT_ITEM_SYN : public MSG_BASE
{
public:
	MSG_C2S_INSERT_ITEM_SYN()
	{
		m_byCategory = CS_LOGON;
		m_byProtocol = C2S_INSERT_ITEM_SYN;
	}
	char			strKey[168];
	char			strVal[1024];
};


// --Client-->Server ������д��һ������
class MSG_C2S_SELECT_ITEM_SYN : public MSG_BASE
{
public:
	MSG_C2S_SELECT_ITEM_SYN()
	{
		m_byCategory = CS_LOGON;
		m_byProtocol = C2S_SELECT_ITEM_SYN;
	}
	char			strKey[168];
};


// --Server-->Client ����ѯ�ظ�
class MSG_S2C_SELECT_ITEM_ACK : public MSG_BASE
{
public:
	MSG_S2C_SELECT_ITEM_ACK()
	{
		m_byCategory = CS_LOGON;
		m_byProtocol = S2C_SELECT_ITEM_ACK;
	}
	char			strKey[168];
	char			strVal[1024];
};


#pragma pack(pop)




#endif // __PROTOCOL_CL_H__


