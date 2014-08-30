#ifndef __NETPROTOCOL_PX7G7U4_H__
#define __NETPROTOCOL_PX7G7U4_H__

/*   ���ṹ�������� Jake.Sun
1) ����(Request)			_SYN
2) ����Ӧ��(Answer)			_ACK
3) ֪ͨ(Command)			-CMD
4) �㲥(Broadcasting)		_BRD
*/


// message category
enum eMSGCATEGORY
{
	emc_CS_CATEGORY			= 1,			// client & server message
	emc_MS_CATEGORY			= 2,			// master & slave message
};


// client & server protocol number
enum elp_CS_PROTOCOL
{
	S2C_SVR_READY_CMD		= 0,			// S2C:������׼��
	S2C_GERERAL_RES_CMD		= 4,			// S2C:������ͨ��֪ͨ
	S2C_SELECT_ITEM_ACK		= 6,			// S2C:��ѯ�ظ�

	C2S_INSERT_ITEM_SYN		= 51,			// C2S:�������key-value pair
	C2S_REMOVE_ITEM_SYN		= 55,			// C2S:����ɾ��ָ��key
	C2S_UPDATE_ITEM_SYN		= 57,			// C2S:�������ָ��key��ֵ
	C2S_SELECT_ITEM_SYN		= 59,			// C2S:�����ѯָ��key
};



// master & slave protocol number
enum elp_MS_PROTOCOL
{
	M2S_GERERAL_RES_CMD		= 0,			// M2S:Masterͨ��֪ͨ

	S2M_APPENDFILE_SYN		= 1,			// S2M:����ͬ��append�ļ�
	M2S_APPENDFILE_ACK		= 2,			// M2S:append �ļ��ظ�

};


enum GENERALRESULT
{
	egr_NONE				= 0,
	egr_INSERTSUCCESS		= 1,
	egr_INSERTFAILD			= 2,
	egr_CANTFINDVAL			= 3,
	egr_REMOVESUCCESS		= 4,
};

#pragma pack(push,1)

//-------------------------------------------------------------------------------------------------------
// --������
// --������� Packet,���а��ĸ���
class MSG_BASE
{
public:
	BYTE						m_byCategory;	// Э�����
	BYTE						m_byProtocol;
};


/* ����: MSG_SERVER_TYPE
 * ˵��: ���������½��Ϣ��ָʾ�˷��������ͣ�ID�����ƣ��������������Ϣ
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
class MSG_S2C_GERERAL_RES_CMD : public MSG_BASE
{
public:
	MSG_S2C_GERERAL_RES_CMD()
	{
		m_byCategory = emc_CS_CATEGORY;
		m_byProtocol = S2C_GERERAL_RES_CMD;
	}
	int		m_iRes;
};


// --Server --> Client
class MSG_S2C_SVR_READY_CMD : public MSG_BASE
{
public:
	MSG_S2C_SVR_READY_CMD()
	{
		m_byCategory = emc_CS_CATEGORY;
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
		m_byCategory = emc_CS_CATEGORY;
		m_byProtocol = C2S_INSERT_ITEM_SYN;
	}
	char			strKey[168];
	char			strVal[1024];
};


// --Client-->Server �������ѯһ��key
class MSG_C2S_SELECT_ITEM_SYN : public MSG_BASE
{
public:
	MSG_C2S_SELECT_ITEM_SYN()
	{
		m_byCategory = emc_CS_CATEGORY;
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
		m_byCategory = emc_CS_CATEGORY;
		m_byProtocol = S2C_SELECT_ITEM_ACK;
	}
	char			strKey[168];
	char			strVal[1024];
};


// --Client-->Server ������ɾ��һ��key
class MSG_C2S_REMOVE_ITEM_SYN : public MSG_BASE
{
public:
	MSG_C2S_REMOVE_ITEM_SYN()
	{
		m_byCategory = emc_CS_CATEGORY;
		m_byProtocol = C2S_REMOVE_ITEM_SYN;
	}
	char			strKey[168];
};




// --Slave-->Master ��request replication
class MSG_S2M_APPENDFILE_SYN : public MSG_BASE
{
public:
	MSG_S2M_APPENDFILE_SYN()
	{
		m_byCategory = emc_MS_CATEGORY;
		m_byProtocol = S2M_APPENDFILE_SYN;
	}
};


#pragma pack(pop)




#endif // __PROTOCOL_CL_H__


