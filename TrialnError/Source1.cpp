//////#define _WINSOCK_DEPRECATED_NO_WARNINGS
//////#include<stdio.h>
//////#include<winsock2.h>
//////
//////#pragma comment(lib,"ws2_32.lib") 
//////#define BUFLEN 512  
//////#define TCPPORT 4916 
//////#define MAXPENDING                   10
//////
//////
//////int TcpBind()
//////{
//////	SOCKET s;
//////	struct sockaddr_in server, si_other;
//////	int slen, recv_len;
//////	char buf[BUFLEN];
//////	WSADATA wsa;
//////
//////	slen = sizeof(si_other);
//////
//////	//Initialise winsock
//////	printf("\nInitialising Winsock...");
//////	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
//////	{
//////		printf("Failed. Error Code : %d", WSAGetLastError());
//////		exit(EXIT_FAILURE);
//////	}
//////	printf("Initialised.\n");
//////
//////	//Create a socket
//////
//////	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
//////	{
//////		printf("Could not create socket : %d", WSAGetLastError());
//////	}
//////	printf("Socket created.\n");
//////	Sleep(4000);
//////	//Prepare the sockaddr_in structure
//////	server.sin_family = AF_INET;
//////	server.sin_addr.s_addr = inet_addr("127.0.0.1");
//////	server.sin_port = htons(TCPPORT);
//////
//////	//Bind 
//////	BOOL Reuse = 1;
//////	setsockopt(s, SOL_SOCKET, SO_EXCLUSIVEADDRUSE, (char*)&Reuse, sizeof(Reuse));
//////	if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
//////	{
//////		printf("Bind failed with error code : %d", WSAGetLastError());
//////		Sleep(4000);
//////		exit(EXIT_FAILURE);
//////	}
//////	puts("Bind done");
//////
//////	//keep listening for data
//////	while (1)
//////	{
//////		// printf("Waiting for data...");
//////		fflush(stdout);
//////
//////		memset(buf, '\0', BUFLEN);
//////
//////		if (listen(s, MAXPENDING) < 0)
//////		{
//////			printf("ERROR : %d", WSAGetLastError());
//////
//////		}
//////
//////	}
//////
//////	closesocket(s);
//////	WSACleanup();
//////}
//////int main()
//////{
//////	TcpBind();
//////
//////	getchar();
//////	return 0;
//////}
//////#include <windows.h>
//////#include <stdio.h>
//////#include <iostream>
//////using namespace std;
//////
//////int main()
//////{
//////	BOOL res = 0;
//////	res = system("netstat -noa |findstr 7260");
//////	if (res != -1)
//////	{
//////		printf("res:%d\n", res);
//////	}
//////	else
//////	{
//////		printf("res:%d%d\n", res, GetLastError());
//////	}
//////	unsigned int i = 1;
//////	char *c = (char*)&i;
//////	if (*c)
//////		printf("Little endian");
//////	else
//////		printf("Big endian");
//////	
//////	getchar();
//////}
////#include <stdio.h>
////#include<iostream>
////using namespace std;
/////* function to show bytes in memory, from location start to start+n*/
////void show_mem_rep(char *start, int n)
////{
////	int i;
////	for (i = 0; i < n; i++)
////		printf(" %.2x", start[i]);
////	printf("\n");
////}
////class cd {
////public:
////	int set();
////
////};
////
////
////class ab {
////	int as;
////public: friend class cd;
////};
////
////int cd::set()
////{
////	printf(".........a");
////	return 0;
////};
////
////
////class Base
////{
////	int x;
////public:
////	Base() { cout << "Base default constructor\n"; }
////};
////
////class Derived : public Base
////{
////	int y;
////public:
////	Derived() { cout << "Derived default constructor\n"; }
////	Derived(int i) { cout << "Derived parameterized constructor\n"; }
////};
////
////
////
////
////
////
////
////
//
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <iphlpapi.h>
//#include <stdio.h>
//#include<tchar.h>
//#include <process.h>
//#include <tlhelp32.h>
//#include<strsafe.h>
//
//// Need to link with Iphlpapi.lib and Ws2_32.lib
//#pragma comment(lib, "iphlpapi.lib")
//#pragma comment(lib, "ws2_32.lib")
//
//#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
//#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))
///* Note: could also use malloc() and free() */
//
//int main()
//{
//
//	 
//			char logbuffer[6096];
//			TCHAR exeNames[5096];
//			int id[16] = { 0 };
//			int CountIndex = 0;
//				int IpmUserInteractCount = 0;
//				memset(exeNames, 0, sizeof(exeNames));
//				TCHAR UserInteractExeName[60] = { L'\0' };
//				TCHAR UserInteractNameProcess[60] = { L'\0' };
//				wmemset(UserInteractExeName, 0, sizeof(UserInteractExeName) / sizeof(wchar_t));
//				wmemset(UserInteractNameProcess, 0, sizeof(UserInteractNameProcess) / sizeof(wchar_t));
//				StringCbCopy(UserInteractExeName, STRSAFE_MAX_CCH * sizeof(TCHAR), L"IPMPlusUserInteract.exe");
//				StringCbCopy(UserInteractNameProcess, STRSAFE_MAX_CCH * sizeof(TCHAR), L"IPMPlusUserInteract.exe*32");
//		
//				HANDLE hProcessSnap;
//				PROCESSENTRY32 pe32;
//				hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//				if (hProcessSnap == INVALID_HANDLE_VALUE)
//				{
//					memset(logbuffer, 0, sizeof(logbuffer));
//					StringCchPrintfA(logbuffer, sizeof(logbuffer), ("CreateToolhelp32Snapshot Failed : %d %s %d"), GetLastError(), __FILE__, __LINE__);
//					// WritelogFile(logbuffer,IPMErrorConst); 
//				}
//				pe32.dwSize = sizeof(PROCESSENTRY32);
//				if (!Process32First(hProcessSnap, &pe32))
//				{
//					memset(logbuffer, 0, sizeof(logbuffer));
//					StringCchPrintfA(logbuffer, sizeof(logbuffer), ("Process32First Failed : %d %s %d"), GetLastError(), __FILE__, __LINE__);
//					// WritelogFile(logbuffer,IPMErrorConst); 
//					CloseHandle(hProcessSnap);
//				}
//				TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>"), Tempbuffer[100], Tempbuffer1[100];
//				do
//				{
//					memset(szProcessName, 0, sizeof(szProcessName));
//					size_t StringbuffLen = 0;
//					StringCchLength(pe32.szExeFile, STRSAFE_MAX_CCH, &StringbuffLen);
//					StringCchCopy(szProcessName, (StringbuffLen + 1), pe32.szExeFile);
//					//	wcscat(exeNames, szProcessName);
//					//printf("szProcessName:%S\n", szProcessName);
//					if ((lstrcmpi(szProcessName, UserInteractExeName) == 0) || (lstrcmpi(szProcessName, UserInteractNameProcess) == 0))
//					{
//						IpmUserInteractCount++;
//						id[CountIndex] = pe32.th32ProcessID;
//						printf("Pid(%d): %d\n", CountIndex + 1, id[CountIndex]);
//						CountIndex++;
//		
//					}
//		
//				} while (Process32Next(hProcessSnap, &pe32));//enumerate all process 
//				CloseHandle(hProcessSnap);
//		
//			
//	
//	/////////////////// Declare and initialize variables
//	PMIB_TCPTABLE2 pTcpTable;
//	ULONG ulSize = 0;
//	DWORD dwRetVal = 0;
//
//	char szLocalAddr[128];
//	char szRemoteAddr[128];
//
//	struct in_addr IpAddr;
//
//	int i;
//
//	pTcpTable = (MIB_TCPTABLE2 *)MALLOC(sizeof(MIB_TCPTABLE2));
//	if (pTcpTable == NULL) {
//		printf("Error allocating memory\n");
//		return 1;
//	}
//
//	ulSize = sizeof(MIB_TCPTABLE);
//	// Make an initial call to GetTcpTable2 to
//	// get the necessary size into the ulSize variable
//	if ((dwRetVal = GetTcpTable2(pTcpTable, &ulSize, TRUE)) ==
//		ERROR_INSUFFICIENT_BUFFER) {
//		FREE(pTcpTable);
//		pTcpTable = (MIB_TCPTABLE2 *)MALLOC(ulSize);
//		if (pTcpTable == NULL) {
//			printf("Error allocating memory\n");
//			return 1;
//		}
//	}
//	// Make a second call to GetTcpTable2 to get
//	// the actual data we require
//	if ((dwRetVal = GetTcpTable2(pTcpTable, &ulSize, TRUE)) == NO_ERROR) {
//		printf("\tNumber of entries: %d, id:%d\n", (int)pTcpTable->dwNumEntries,id[0]);
//	// 	Sleep(3000);
//
//		for (i = 0; i < (int)pTcpTable->dwNumEntries; i++) { //(pTcpTable->table[i].dwOwningPid == 1604) && (pTcpTable->table[i].dwState= MIB_TCP_STATE_ESTAB)
//			//printf("pid:%d\n", pTcpTable->table[i].dwOwningPid);
//			if ((pTcpTable->table[i].dwOwningPid == id[0]) && (pTcpTable->table[i].dwState = MIB_TCP_STATE_ESTAB))
//			{
//				//printf("................:%d\n", pTcpTable->table[i].dwState);
//				printf("\n\tTCP[%d] State: %ld - ", i,pTcpTable->table[i].dwState);
//				switch (pTcpTable->table[i].dwState) {
//				case MIB_TCP_STATE_CLOSED:
//					printf("CLOSED\n");
//					break;
//				case MIB_TCP_STATE_LISTEN:
//					printf("LISTEN\n");
//					break;
//				case MIB_TCP_STATE_SYN_SENT:
//					printf("SYN-SENT\n");
//					break;
//				case MIB_TCP_STATE_SYN_RCVD:
//					printf("SYN-RECEIVED\n");
//					break;
//				case MIB_TCP_STATE_ESTAB:
//					printf("ESTABLISHED\n");
//					break;
//				case MIB_TCP_STATE_FIN_WAIT1:
//					printf("FIN-WAIT-1\n");
//					break;
//				case MIB_TCP_STATE_FIN_WAIT2:
//					printf("FIN-WAIT-2 \n");
//					break;
//				case MIB_TCP_STATE_CLOSE_WAIT:
//					printf("CLOSE-WAIT\n");
//					break;
//				case MIB_TCP_STATE_CLOSING:
//					printf("CLOSING\n");
//					break;
//				case MIB_TCP_STATE_LAST_ACK:
//					printf("LAST-ACK\n");
//					break;
//				case MIB_TCP_STATE_TIME_WAIT:
//					printf("TIME-WAIT\n");
//					break;
//				case MIB_TCP_STATE_DELETE_TCB:
//					printf("DELETE-TCB\n");
//					break;
//				default:
//					wprintf(L"UNKNOWN dwState value: %d\n", pTcpTable->table[i].dwState);
//					break;
//				}
//
//				IpAddr.S_un.S_addr = (u_long)pTcpTable->table[i].dwLocalAddr;
//				strcpy_s(szLocalAddr, sizeof(szLocalAddr), inet_ntoa(IpAddr));
//				//printf("\tTCP[%d] Local Addr: %s\n", i, szLocalAddr);
//
//			//	printf("\tTCP[%d] Local Port: %d \n", i,
//				//	ntohs((u_short)pTcpTable->table[i].dwLocalPort));
//
//				IpAddr.S_un.S_addr = (u_long)pTcpTable->table[i].dwRemoteAddr;
//				strcpy_s(szRemoteAddr, sizeof(szRemoteAddr), inet_ntoa(IpAddr));
//			//	printf("\tTCP[%d] Remote Addr: %s\n", i, szRemoteAddr);
//
//			//	printf("\tTCP[%d] Remote Port: %d\n", i,
//					//ntohs((u_short)pTcpTable->table[i].dwRemotePort));
//
//			//	printf("\tTCP[%d] Owning PID: %d\n", i, pTcpTable->table[i].dwOwningPid);
//
//			//	printf("\tTCP[%d] Offload State: %ld - ", i,
//					//pTcpTable->table[i].dwOffloadState);
//				switch (pTcpTable->table[i].dwOffloadState) {
//				case TcpConnectionOffloadStateInHost:
//					//printf("Owned by the network stack and not offloaded \n");
//					break;
//				case TcpConnectionOffloadStateOffloading:
//					//printf("In the process of being offloaded\n");
//					break;
//				case TcpConnectionOffloadStateOffloaded:
//					//printf("Offloaded to the network interface control\n");
//					break;
//				case TcpConnectionOffloadStateUploading:
//					//printf("In the process of being uploaded back to the network stack \n");
//					break;
//				default:
//					printf("UNKNOWN Offload state value\n");
//					break;
//				}
//			}
//			else
//			{
//				printf("No matching Pid \n");
//				//break;
//			}
//			
//
//		}
//	}
//	else {
//		printf("\tGetTcpTable2 failed with %d\n", dwRetVal);
//		FREE(pTcpTable);
//		return 1;
//	}
//
//	if (pTcpTable != NULL) {
//		FREE(pTcpTable);
//		pTcpTable = NULL;
//	}
//	getchar();
//	return 0;
//}
//
////
//
