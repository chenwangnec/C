#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[])
{
	DWORD jisuanjiname = MAX_COMPUTERNAME_LENGTH + 1;
	DWORD username = 30;
	char Jisuanjiname[MAX_COMPUTERNAME_LENGTH + 1];
	char susername[30];
	GetUserNameA(susername, &username);
	printf("�û���:%s\n", susername);

	getchar();
	return 0;
}