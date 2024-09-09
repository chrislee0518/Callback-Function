#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//冒泡排序，两两比较，从小到大排序
//void bubblesort(int arr[], int sz)
//{
//	int i = 0;
//	//多少趟冒泡排序
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		//每趟要对比多少对数
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			int tmp = 0;
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j+1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,2,6,5,4,3,1,0,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubblesort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//void * 类型的指针 可以接收任意类型的地址
//void * 类型的指针 不能进行解引用操作，不知道访问几个字节
//void * 类型的指针 不能进行+-整数的操作

//void qsort(void *base, size_t num, size_t width, int(*cmp)(const void *e1, const void *e2));
//qsort(arr, sz, sizeof(arrr[0]), cmp_int);//cmp_int:自己设计的比较方法
// 第一个参数：待排序数组的首元素地址
// 第二个参数：待排序数组的元素个数
// 第三个参数：待排序数组的每个元素的大小-字节
// 第四个参数：函数指针:比较两个元素的函数的地址-自己实现
// 函数指针的两个参数是：待比较两个元素的地址
// 
// 类比冒泡排序，排序逻辑是一致的，但比较方法不同
//比较函数特点：e1<e2 则<0;e1= e2 则=0； e1 >e2 则>0;
struct Stu {
	char name[20];
	int age;
};//定义结构体
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int cmp_f(const void* e1, const void* e2)
{
	if (*(float*)e1  == *(float*)e2)
	{
		return 0;
	}
	else if (*(float*)e1 < *(float*)e2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int cmp_stu_by_age(const void* e1, const  void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_stu_by_name(const void* e1, const  void* e2)
{
	//比较字符串,不能直接用><=比较,用strcmp函数(用来比较字符串ascii值的)
	return strcmp(((struct Stu*)e1)->name , ((struct Stu*)e2)->name);
}

void test1()
{
	int arr[10] = { 0,1,3,2,5,4,7,6,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);//类似于冒泡排序，从小到大排序
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);

	}

}

void test2()
{
	float f[5] = { 1.0,2.0,5.0,7.0,9.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_f);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%f ", f[j]);

	}
}

void test3()
{


	struct Stu s[3] = { {"zhang",20},{"li",18},{"wang",29}};//初始化结构体
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);

}

void test4()
{


	struct Stu s[3] = { {"zhang",20},{"li",18},{"wang",29} };//初始化结构体
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);


}

//用qsort函数思想修改冒泡函数，实现多种数据类型排序,实现qsort函数（应用回调函数
// ）
void swap(char* buf1, char* buf2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubblesort1(void *base, int sz, int width, int(*cmp)(void *e1,void *e2))
{
	int i = 0;
	//多少趟冒泡排序
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		//每趟要对比多少对数
		for (j = 0; j < sz - 1 - i; j++)
		{
			//两个元素的比较
			if(cmp((char*)base+j*width, (char*)base + (j+1 )* width)>0)//每次跳一个元素即跳一个
				//宽度，强制转换为char*后，即跳宽度个字节就是跳一个元素
			{
			//交换，当需要交换时，需要把两个元素逐字节交换
			swap((char*)base + j * width, (char*)base + (j + 1) * width, width);//逐字节交换
			}
		}
	}
}

void test5()
{
	int arr[10] = { 0,1,3,2,5,4,7,6,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubblesort1(arr, sz, sizeof(arr[0]), cmp_int);

}

void test6()
{


	struct Stu s[3] = { {"zhang",20},{"li",18},{"wang",29} };//初始化结构体
	int sz = sizeof(s) / sizeof(s[0]);
	bubblesort1(s, sz, sizeof(s[0]), cmp_stu_by_name);


}

int main()
{

	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}