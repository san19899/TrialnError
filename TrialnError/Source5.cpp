//#include<Windows.h>
//#include<tchar.h>
//#include <process.h>
//#include <tlhelp32.h>
//#include<strsafe.h>
////int fib(int n)
////{
////	if (n <= 1)
////		return 1;
////	else
////		return fib(n - 1) + fib(n - 2);
////}
////void main()
////{
////	int res = fib(50);
////	printf("res:%d\n", res);
////	getchar();
////}
//// Assuming n-th disk is bottom disk (count down)
//void tower(int n, char sourcePole, char destinationPole, char auxiliaryPole)
//{
//	// Base case (termination condition)
//	if (0 == n)
//		return;
//
//	// Move first n-1 disks from source pole
//	// to auxiliary pole using destination as
//	// temporary pole
//	tower(n - 1, sourcePole, auxiliaryPole,destinationPole);
//
//	// Move the remaining disk from source
//	// pole to destination pole
//	printf("Move the disk %d from %c to %c\n", n,sourcePole, destinationPole);
//
//	// Move the n-1 disks from auxiliary (now source)
//	// pole to destination pole using source pole as
//	// temporary (auxiliary) pole
//	tower(n - 1, auxiliaryPole, destinationPole,sourcePole);
//}
//
//void main()
//{
//	tower(3, 'S', 'D', 'A');
//	getchar();
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//tower(int n,char s,char d,char a)
//{
//	tower((n-1),'s','a','d')
//		tower()
//}
//
//
//
//
//main()
//{
//	tower(3, 's', 'd', 'a');
//}
#include<Windows.h>
#include<tchar.h>
#include <process.h>
#include <tlhelp32.h>
#include<strsafe.h>
#include<iostream>
using namespace std;
//class firsta
//{
//	int var = 9;
//public:
//	firsta()
//	{
//		printf("Constructor called of firsta\n");
//	};
//
//	
//	void func1();
//	friend void two::func2();
//};
//
//
//void firsta::func1()
//{
//	printf("This is func1, func of first class\n");
//}
//class two
//{
//public:
//	two()
//	{
//		printf("Constructor of second class called");
//	};
//	void func2();
//
//	
//};
//
//void two::func2()
//{
//	firsta asr;
//	asr.
//	printf("func2, which is a mem fun of class two, but also a frnd in class 1, hence accessing private mem of class 1 from class 2, which is: %d \n");
//}
//
//int main()
//{
//	
//
//
//
//	firsta obj;
//	obj.func1();
//	
//	two obj2;
//	obj2.func2
//
//
//	return 0;
//}

class WithFriend
{
	int i;
public:
	friend void fun(); // Global function as friend
};

class two {
public:
	void fun();
};
void two:: fun()
{
	WithFriend wf;
	wf.i = 10;  // Access to private data member
	cout << wf.i;
}

int main()
{
	fun(); //Can be called directly
}