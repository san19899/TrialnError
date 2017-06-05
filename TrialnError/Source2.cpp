//#define STRICT
//#include <windows.h>
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//
//
//void DumpLPI(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX pslpi)
//{
//	union {
//		PPROCESSOR_RELATIONSHIP Processor;
//		PNUMA_NODE_RELATIONSHIP NumaNode;
//		PCACHE_RELATIONSHIP Cache;
//		PGROUP_RELATIONSHIP Group;
//	};
//
//	Processor = &pslpi->Processor;
//
//	switch (pslpi->Relationship)
//	{
//	/*case RelationProcessorPackage:
//		printf("RelationProcessorPackage(GroupCount = %u)\n", Processor->GroupCount);
//
//		if (WORD GroupCount = Processor->GroupCount)
//		{
//			PGROUP_AFFINITY GroupMask = Processor->GroupMask;
//			do
//			{
//				printf("group<%u> Mask = %08x\n", GroupMask->Group, GroupMask->Mask);
//			} while (GroupMask++, --GroupCount);
//		}
//		break;*/
//
//	//case RelationProcessorCore:
//		//printf("RelationProcessorCore(%x): Mask = %08x\n", Processor->Flags, Processor->GroupMask->Mask);
//	//	break;
//
//	case RelationGroup:
//		//printf("RelationGroup(%u/%u)\n", Group->ActiveGroupCount, Group->MaximumGroupCount);
//
//		if (WORD ActiveGroupCount = Group->ActiveGroupCount)
//		{
//			PPROCESSOR_GROUP_INFO GroupInfo = Group->GroupInfo;
//			do
//			{
//				printf("ActiveProcessors/Inactive Processors: %u/%u \n\n ",
//					GroupInfo->ActiveProcessorCount,
//					GroupInfo->MaximumProcessorCount);
//			} while (GroupInfo++, --ActiveGroupCount);
//		}
//		break;
//
////	case RelationCache:
//		//printf("Cache L%u (%x, %x) %x\n", Cache->Level, Cache->LineSize, Cache->CacheSize, Cache->Type);
//	//	break;
//
//	//case RelationNumaNode:
//		//printf("NumaNode<%u> (group = %u, mask = %08x)\n", NumaNode->NodeNumber, NumaNode->GroupMask.Group, NumaNode->GroupMask.Mask);
//	//	break;
//	//default:
//	//	printf("unknown Relationship=%x\n", pslpi->Relationship);
//
//	}
//}
//
//void TestLP2()
//{
//	ULONG rcb = 0x100, Size, err;
//
//	PVOID buf;
//
//	BOOL fOk;
//
//	do
//	{
//		if (buf = new UCHAR[rcb])
//		{
//			fOk = GetLogicalProcessorInformationEx(RelationAll, (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX)buf, &rcb);
//
//			err = GetLastError();
//
//			if (fOk)
//			{
//				if (rcb)
//				{
//					union {
//						PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX pslpi;
//						PBYTE pb;
//					};
//
//					pslpi = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX)buf;
//
//					do
//					{
//						DumpLPI(pslpi);
//
//						Size = pslpi->Size;
//						pb += Size;
//
//					} while (rcb -= Size);
//				}
//			}
//
//			delete[] buf;
//		}
//		else
//		{
//			break;
//		}
//
//	} while (!fOk && err == ERROR_INSUFFICIENT_BUFFER);
//}
//
//
//
//void main()
//{
//	//LOGICAL_PROCESSOR_RELATIONSHIP Relationship = {};
//	//SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX *m_pinfoBase = nullptr;
//	//SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX *m_pinfoCurrent = nullptr;
//	//DWORD m_cbRemaining = 0;
//	//DWORD cb = 0;
//
//	//m_pinfoBase = reinterpret_cast<SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX *>(LocalAlloc(LMEM_FIXED, cb));
//
//	//if (!GetLogicalProcessorInformationEx(Relationship,
//	//	m_pinfoBase, &cb))
//	//{
//	//	printf("Error 1 %d\n", GetLastError());
//	//	//return;
//	//}
//	//else
//	//{
//	//	printf("ActobeCores:%d\n", m_pinfoBase->Group.GroupInfo->ActiveProcessorCount);
//	//}
//
//	TestLP2();
//	while(1)
//	{
//		Sleep(60000);
//		TestLP2();
//	}
//	getchar();
//
//
//	//return 0;
//}