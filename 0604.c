#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//strcpy:将str2的字符串给str1
//void my_cpy(char * str1, const char * str2){
//	int i;
//	int ret = strlen(str2);
//	for (i = 0; i < ret; ++i){
//		str1[i] = str2[i];
//	}
//	puts(str1);
//}
//int main(){
//	char str1[20] = "abcdefgh";
//	char str2[20] = "12345";
//	my_cpy(str1, str2);
//	system("pause");
//	return 0;
//}

//strcat:将str2拼接到str1后面
//void my_cat(char *str1,const char *str2){
//	int i;
//	int ret = strlen(str2);
//	int a = strlen(str1);
//	for (i = 0; i < ret; ++i){
//		str1[i + a] = str2[i];
//	}
//	puts(str1);
//}
//int main(){
//	char str1[20] = "abcdefgh";
//	char str2[20] = "12345";
//	my_cat(str1, str2);
//	system("pause");
//	return 0;
//}

//strstr:查找str1里面是否有str2
//int my_str(const char * str1, const char * str2){
//	char *start1 = (char *)str1;
//	char *start2 = (char *)str2;
//	char *p = (char *)str1;
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (*p){
//		start1 = p;
//		while (*start1 != '\0'&&*start2 != '\0'&&*start1 == *start2){
//			start1++;
//			start2++;
//		}
//		if (*start2 == '\0'){
//			printf("%s\n",p);
//		}
//		start2 = (char *)str2;
//		p++;
//	}
//	return 0;
//}
//int main(){
//	char a[20] = "abbbcdef";
//	char b[10] = "bbcde";
//	printf("%s\n", my_str(a, b));
//	system("pause");
//	return 0;
//}

//strchr:在字符串里面查找字符
//char *my_strchr(const char *str1, char str2)
//{
//	char *m = NULL;
//	while (*str1 != NULL)
//	{
//		if (*str1 == str2)
//		{
//			return (char *)str1;
//		}
//		*str1++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char *a = "abcderf";
//	char b = 'e';
//	char *c = NULL;
//	c = my_strchr(a, b);
//	printf("%s\n", c);
//	system("pause");
//	return 0;
//}

//strcmp:比较两个字符串是不是相等
//int my_strcmp(char const *s1, char const *s2)
//{
//	assert(s1 != NULL);
//	assert(s2 != NULL);
//	int ret = 0;
//	while (!(ret = (*s1 - *s2)) && *s1 && *s2)//如果两者相等且不为'\0'
//	{
//		s1++;
//		s2++;
//	}
//	if (ret < 0)
//		ret = -1;
//	else if (ret>0)
//		ret = 1;
//	return ret;
//}
//int main()
//{
//	char *s1 = "abcd";
//	char*s2 = "abbb";
//	printf("%d\n", my_strcmp(s1, s2));
//	system("pause");
//	return 0;
//}

//memcpy:内存拷贝
void* my_memcpy(void* dest, void* src, size_t n)
{
	void* ret = dest;
	char* str1 = (char*)dest;
	char* str2 = (char*)src;
	assert(dest);
	assert(src);
	while (n--)
	{
		*str1++ = *str2++;
	}
	return ret;
}
//内存移动
void* my_memmove(void* dest, void* src, size_t n)
{
	void* ret = dest;
	char* str1 = (char*)dest;
	char* str2 = (char*)src;
	assert(dest);
	assert(src);
	if (str1 > str2)
	{
		while (n--)
		{
			*(str1 + n) = *(str2 + n);
		}
	}
	else
	{
		while (n--)
		{
			*str1++ = *str2++;
		}
	}
	return ret;
}
int main()
{
	int i = 0;
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[10] = { 0 };
	int arr3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	my_memmove(arr3 + 5, arr3 + 4, 3 * sizeof(int));
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr3[i]);
	}
	system("pause");
	return 0;
}