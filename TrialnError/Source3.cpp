//#include<iostream>
//using namespace std;
////static int x = 0;
////int &fun()
////{
////	//x = 10;
////	static int x = 10;
////
////	return x;
////}
////int main()
////{
////	fun() = 30;
////	cout << fun() << "  ..." ;
////	getchar();
////	return 0;
////}
//
//#include<iostream>
//using namespace std;
//
//
////void swap(char * &str1, char * &str2)
////{
////	char *temp = str1;
////	str1 = str2;
////	str2 = temp;
////}
////
////int main()
////{
////	char *str1 = "GEEKS";
////	char *str2 = "FOR GEEKS";
////	swap(str1, str2);
////	cout << "str1 is " << str1 << endl;
////	cout << "str2 is " << str2 << endl;
////	cout << endl;
////
////	int *ptr = NULL;
////	int& a = *ptr;
////	cout << a;
////
////
////
////	getchar();
////	return 0;
////}
//
//class base {
//public:
//	virtual void show() {  // Note the virtual keyword here
//		cout << "In base \n";
//	}
//};
//
//
//class derived : public base {
//public:
//	void show() {
//		cout << "In derived \n";
//	}
//};
//
//// Since we pass b as reference, we achieve run time polymorphism here.
//void print(base &b) {
//	b.show();
//}
//
//int main(void) {
//	base b;
//	derived d;
//	print(b);
//	print(d);
//	getchar();
//	return 0;
//}