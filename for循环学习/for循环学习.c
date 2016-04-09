#include<stdio.h>
int main()
{
	/*以下是for循环从1+100之间的和*/
	int i;
	int sum = 0;
	for (i = 0; i <= 100; ++i) //这里括号结束时一定不能有标点符号
	{
		sum = sum + i;
	}
	printf("sum=%d", sum);//输出SUM的值
	getchar();//暂停
	return 0;//返回
}