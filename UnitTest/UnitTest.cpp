// UnitTest.cpp : Defines the entry point for the console application.
//

#include "HashmapTest.h"
#include <gtest/gtest.h>


JK_Hashmap m_configMap;

int main(int argc, char* argv[])
{

	//HashmapTest	hashmaptest;
	//hashmaptest.TestFunction();

	testing::InitGoogleTest(&argc, argv);	// --��������Test��ص������п��أ��������עҲ�ɲ���   
	RUN_ALL_TESTS();						// --����������֪����ɶ��   
	std::cin.get();							// --ֻ��������ͣ���ѣ���Ȼһ����û��   

	return 0;
}



TEST(HashmapTest, AddTest)
{

	CTest* pTemp1 = new CTest();
	pTemp1->m_iX = 11;
	pTemp1->m_iY = 12;

	CTest* pTemp2 = new CTest();
	pTemp2->m_iX = 21;
	pTemp2->m_iY = 22;

	CTest* pTemp3 = new CTest();
	pTemp3->m_iX = 31;
	pTemp3->m_iY = 32;

	CTest* pTemp4 = new CTest();
	pTemp4->m_iX = 41;
	pTemp4->m_iY = 42;

	CTest* pTemp5 = new CTest();
	pTemp5->m_iX = 51;
	pTemp5->m_iY = 52;

	EXPECT_EQ(true, m_configMap.Init(64));
	EXPECT_EQ(true, m_configMap.Add("aaa", pTemp1) );
	//EXPECT_EQ(true, m_configMap.Add("aaa", pTemp1));
}	