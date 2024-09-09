#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ð�����������Ƚϣ���С��������
//void bubblesort(int arr[], int sz)
//{
//	int i = 0;
//	//������ð������
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		//ÿ��Ҫ�Աȶ��ٶ���
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

//void * ���͵�ָ�� ���Խ����������͵ĵ�ַ
//void * ���͵�ָ�� ���ܽ��н����ò�������֪�����ʼ����ֽ�
//void * ���͵�ָ�� ���ܽ���+-�����Ĳ���

//void qsort(void *base, size_t num, size_t width, int(*cmp)(const void *e1, const void *e2));
//qsort(arr, sz, sizeof(arrr[0]), cmp_int);//cmp_int:�Լ���ƵıȽϷ���
// ��һ���������������������Ԫ�ص�ַ
// �ڶ��������������������Ԫ�ظ���
// �����������������������ÿ��Ԫ�صĴ�С-�ֽ�
// ���ĸ�����������ָ��:�Ƚ�����Ԫ�صĺ����ĵ�ַ-�Լ�ʵ��
// ����ָ������������ǣ����Ƚ�����Ԫ�صĵ�ַ
// 
// ���ð�����������߼���һ�µģ����ȽϷ�����ͬ
//�ȽϺ����ص㣺e1<e2 ��<0;e1= e2 ��=0�� e1 >e2 ��>0;
struct Stu {
	char name[20];
	int age;
};//����ṹ��
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
	//�Ƚ��ַ���,����ֱ����><=�Ƚ�,��strcmp����(�����Ƚ��ַ���asciiֵ��)
	return strcmp(((struct Stu*)e1)->name , ((struct Stu*)e2)->name);
}

void test1()
{
	int arr[10] = { 0,1,3,2,5,4,7,6,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);//������ð�����򣬴�С��������
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


	struct Stu s[3] = { {"zhang",20},{"li",18},{"wang",29}};//��ʼ���ṹ��
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);

}

void test4()
{


	struct Stu s[3] = { {"zhang",20},{"li",18},{"wang",29} };//��ʼ���ṹ��
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);


}

//��qsort����˼���޸�ð�ݺ�����ʵ�ֶ���������������,ʵ��qsort������Ӧ�ûص�����
// ��
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
	//������ð������
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		//ÿ��Ҫ�Աȶ��ٶ���
		for (j = 0; j < sz - 1 - i; j++)
		{
			//����Ԫ�صıȽ�
			if(cmp((char*)base+j*width, (char*)base + (j+1 )* width)>0)//ÿ����һ��Ԫ�ؼ���һ��
				//��ȣ�ǿ��ת��Ϊchar*�󣬼�����ȸ��ֽھ�����һ��Ԫ��
			{
			//����������Ҫ����ʱ����Ҫ������Ԫ�����ֽڽ���
			swap((char*)base + j * width, (char*)base + (j + 1) * width, width);//���ֽڽ���
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


	struct Stu s[3] = { {"zhang",20},{"li",18},{"wang",29} };//��ʼ���ṹ��
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