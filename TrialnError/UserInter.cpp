//#include<Windows.h>
//#include<tchar.h>
//#include <process.h>
//#include <tlhelp32.h>
//#include<strsafe.h>
//void main()
//{
//	char logbuffer[6096];
//	TCHAR exeNames[5096];
//	int id[16] = { 0 };
//	int CountIndex = 0;
//	try
//	{
//		int IpmUserInteractCount = 0;
//		memset(exeNames, 0, sizeof(exeNames));
//		TCHAR UserInteractExeName[60] = { L'\0' };
//		TCHAR UserInteractNameProcess[60] = { L'\0' };
//		wmemset(UserInteractExeName, 0, sizeof(UserInteractExeName) / sizeof(wchar_t));
//		wmemset(UserInteractNameProcess, 0, sizeof(UserInteractNameProcess) / sizeof(wchar_t));
//		StringCbCopy(UserInteractExeName, STRSAFE_MAX_CCH * sizeof(TCHAR), L"IPMPlusUserInteract.exe");
//		StringCbCopy(UserInteractNameProcess, STRSAFE_MAX_CCH * sizeof(TCHAR), L"IPMPlusUserInteract.exe*32");
//
//		HANDLE hProcessSnap;
//		PROCESSENTRY32 pe32;
//		hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//		if (hProcessSnap == INVALID_HANDLE_VALUE)
//		{
//			memset(logbuffer, 0, sizeof(logbuffer));
//			StringCchPrintfA(logbuffer, sizeof(logbuffer), ("CreateToolhelp32Snapshot Failed : %d %s %d"), GetLastError(), __FILE__, __LINE__);
//			// WritelogFile(logbuffer,IPMErrorConst); 
//		}
//		pe32.dwSize = sizeof(PROCESSENTRY32);
//		if (!Process32First(hProcessSnap, &pe32))
//		{
//			memset(logbuffer, 0, sizeof(logbuffer));
//			StringCchPrintfA(logbuffer, sizeof(logbuffer), ("Process32First Failed : %d %s %d"), GetLastError(), __FILE__, __LINE__);
//			// WritelogFile(logbuffer,IPMErrorConst); 
//			CloseHandle(hProcessSnap);
//		}
//		TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>"), Tempbuffer[100], Tempbuffer1[100];
//		do
//		{
//			memset(szProcessName, 0, sizeof(szProcessName));
//			size_t StringbuffLen = 0;
//			StringCchLength(pe32.szExeFile, STRSAFE_MAX_CCH, &StringbuffLen);
//			StringCchCopy(szProcessName, (StringbuffLen + 1), pe32.szExeFile);
//			//	wcscat(exeNames, szProcessName);
//			//printf("szProcessName:%S\n", szProcessName);
//			if ((lstrcmpi(szProcessName, UserInteractExeName) == 0) || (lstrcmpi(szProcessName, UserInteractNameProcess) == 0))
//			{
//				IpmUserInteractCount++;
//				id[CountIndex] = pe32.th32ProcessID;
//				printf("Pid(%d): %d\n", CountIndex + 1, id[CountIndex]);
//				CountIndex++;
//
//			}
//
//		} while (Process32Next(hProcessSnap, &pe32));//enumerate all process 
//		CloseHandle(hProcessSnap);
//
//		if (IpmUserInteractCount > 1)
//		{
//			printf("IpmUserInteractCount: %d\n", IpmUserInteractCount);
//			printf("\n %d instances of UserInteract are running, terminating %d instance/s \n", IpmUserInteractCount, IpmUserInteractCount - 1);
//			for (int g = 1; g <IpmUserInteractCount; g++)
//			{
//				//DWORD PID = 9188;
//				printf(".........:%d\n", id[g]);
//				HANDLE UiHandle = OpenProcess(PROCESS_TERMINATE, FALSE, id[g]);
//
//				DWORD Exitcode = 0;
//				GetExitCodeProcess(UiHandle, &Exitcode);
//				if (!TerminateProcess(UiHandle, Exitcode))
//				{
//					DWORD ret = GetLastError();
//					printf("%d", ret);
//				}
//				else
//				{
//					CloseHandle(UiHandle);
//				}
//			}
//		}
//		else
//		{
//			printf("\nOnly one instance of UserInteract is running \n");
//		}
//		getchar();
//	}
//	catch (...)
//	{
//		printf("Error:%d\n", GetLastError());
//	}
//}
//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base Constructor" << endl;
//	}
//	 void show() { cout << " In Base \n"; }
//};
//
//class Derived : public Base
//{
//public:
//	Derived()
//	{
//		cout << "Derived Constructor" << endl;
//	}
//	void show() { cout << "In Derived \n"; }
//};
//
//int main(void)
//{
//
//	Base *bp = new Base ;
//	//bp->show();  // RUN-TIME POLYMORPHISM
//	printf(".......................\n");
//	//Derived *dp = new Derived;
//	getchar();
//	return 0;
