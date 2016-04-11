#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[])
{
	//DWORD jisuanjiname = MAX_COMPUTERNAME_LENGTH + 1;//(暂时无用)
	DWORD username = 30;
	//char Jisuanjiname[MAX_COMPUTERNAME_LENGTH + 1];//(暂时无用)
	char susername[30];
	GetUserNameA(susername, &username);
	printf("用户名:%s\n", susername);

	getchar();
	return 0;
}