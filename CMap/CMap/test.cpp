#include  "E:\code\C\CMap\CMap.h"
#include <iostream>
#include "Time.h"
#include "windows.h"
using namespace std;
int main() 
{
	char dd[80] = "test";
	CMap map_test(100);
	map_test.insert(12, dd);
	printf("msg is %p\r\n",map_test.find(12));
	/*map_test.remove(12);
	printf("msg is %s\r\n", map_test.find(12));*/
	map_test.insert(4343, (char*)"sssssss");
	map_test.insert(1111, (char*)"sllllll");
	map_test.insert(4255, (char*)"gggggg");
	LARGE_INTEGER freq, start, end;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&start);
	printf("msg is %s\r\n", map_test.find(4343));
	//finish = clock();
	QueryPerformanceCounter(&end); 
	cout << "运行时间：" << (end.QuadPart - start.QuadPart) * 1.0 / freq.QuadPart << endl;
	printf("map left size is %d\r\n", map_test.sizeLeft());
	map_test.remove(4343);
	printf("msg is %s\r\n", map_test.find(4343));
	map_test.remove(1111);
	//map_test.remove(12);
	printf("map left size is %d\r\n", map_test.sizeLeft());
	return 0;
}