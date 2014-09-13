// UnitTest.cpp : Defines the entry point for the console application.
//

#include "HashmapTest.h"
#include "AppendCmdQueue.h"
//#include <gtest/gtest.h>
#include "DListTest.h"





int main(int argc, char* argv[])
{
	//testing::InitGoogleTest(&argc, argv);	// --用来处理Test相关的命令行开关，如果不关注也可不加   
	//RUN_ALL_TESTS();						// --看函数名就知道干啥了   
	//std::cin.get();							// --只是让它暂停而已，不然一闪就没了   


	// begin to test DList
	DListTest dlist;
	dlist.TestDList();

	return 0;
}



//TEST(HashmapTest, AddTest)
//{
//
//	CTest* pTemp1 = new CTest();
//	pTemp1->m_iX = 11;
//	pTemp1->m_iY = 12;
//
//	CTest* pTemp2 = new CTest();
//	pTemp2->m_iX = 21;
//	pTemp2->m_iY = 22;
//
//	CTest* pTemp3 = new CTest();
//	pTemp3->m_iX = 31;
//	pTemp3->m_iY = 32;
//
//	CTest* pTemp4 = new CTest();
//	pTemp4->m_iX = 41;
//	pTemp4->m_iY = 42;
//
//	CTest* pTemp5 = new CTest();
//	pTemp5->m_iX = 51;
//	pTemp5->m_iY = 52;
//
//	EXPECT_EQ(true, m_configMap.Init(64));
//	EXPECT_EQ(true, m_configMap.Add("aaa", pTemp1) );
//
//	
//	EXPECT_EQ(true, m_configMap.Add("bbb", pTemp2) );
//	EXPECT_EQ(true, m_configMap.Add("ccc", pTemp3) );
//	EXPECT_EQ(true, m_configMap.Add("ddd", pTemp4) );
//
//	bool bhit = false;
//	try
//	{
//		m_configMap.Add("ccc", pTemp5);
//	}
//	catch (std::exception e)
//	{
//		bhit = true;
//	}
//	assert(bhit);
//
//
//	m_configMap.Add("9qjfwo", pTemp1);
//	m_configMap.Add("bqjfwf", pTemp2);
//
//	CTest* pMY = (CTest*)m_configMap.Get("bbb");
//	int xxx = pMY->m_iX;
//	int yyy = pMY->m_iY;
//
//	CTest* pMY2 = (CTest*)m_configMap.Get("opp");
//	if (pMY2)
//	{
//	}
//
//
//	CTest* pMY3 = (CTest*)m_configMap.Get("bqjfwf");
//	int xxx3 = pMY3->m_iX;
//	int yyy3 = pMY3->m_iY;
//
//	m_configMap.Remove("bqjfwf");
//	CTest* pMY4 = (CTest*)m_configMap.Get("bqjfwf");
//	if (pMY4)
//	{
//	}
//
//	//EXPECT_EQ(true, m_configMap.Add("aaa", pTemp1));
//}	