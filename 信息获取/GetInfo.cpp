#include"GetInfo.h"


/*******************************************************************************************************

ϵͳ�汾

********************************************************************************************************/

void GetVersionInfo(){

		system("cls");

		printf("\n\t\t\t\t�����ϵͳ�汾��\n\n");
		printf("\t************************************************************************************************************\\\n\n");

		 OSVERSIONINFO osvi;
		BOOL bIsWindowsXPorLater;

		ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

		GetVersionEx(&osvi);
		bIsWindowsXPorLater =((osvi.dwMajorVersion>5)||((osvi.dwMajorVersion == 5)&&(osvi.dwMinorVersion>=1)));

		if(bIsWindowsXPorLater)
			printf("\t��ĵ�����xp���ϵİ汾.\n");
		else 
		printf("\t��ĵ��Բ���xp���ϵİ汾.\n");

		printf("\n\t������Ϣ��\n");
		printf("\t����ϵͳ���汾��:%d\n\t����ϵͳ�ΰ汾��:%d\n\t����ϵͳ����汾��:%d\n\t����ϵͳ��ƽ̨:%d\n\tָ����װ��ϵͳ�ϵķ����:%S\n",osvi.dwMajorVersion,osvi.dwMinorVersion,osvi.dwBuildNumber,osvi.dwPlatformId,osvi.szCSDVersion);

		printf("\n\t************************************************************************************************************\\\n\n");

	getchar();

}


/*******************************************************************************************************

ϵͳӲ����Ϣ

********************************************************************************************************/


void SystemInfonation(){


		SYSTEM_INFO xinxi;
		 GetSystemInfo(&xinxi);

		 system("cls");

		printf("\n\t\t\t\t����ȡϵͳӲ����Ϣ��\n\n");
		printf("\t************************************************************************************************************\\\n\n");
 printf("\t�ڴ��ҳ��С��0x%.8x\n\t�������ڴ���ʼ:0x%.8x\n\t�����ڴ�:0x%.8x\n\t����������:%d\n\t����������:",xinxi.dwPageSize,xinxi.lpMinimumApplicationAddress,xinxi.lpMaximumApplicationAddress,xinxi.dwNumberOfProcessors);
		switch(xinxi.dwProcessorType)
		{
		case PROCESSOR_INTEL_386:

		printf("386");

		break;
		case PROCESSOR_INTEL_486:

		printf("486");

		break;
		case PROCESSOR_INTEL_PENTIUM:

		printf("PENTIUM");
		break;
		default:break;
		}


		printf("\n\t�������ܹ�:");

		switch(xinxi.wProcessorArchitecture)
		{

		case PROCESSOR_ARCHITECTURE_INTEL:
		printf("inter ");
		printf("%d",xinxi.wProcessorLevel);
		break;

		case PROCESSOR_ARCHITECTURE_IA64:
		printf("64bits inter");
		break;

		case PROCESSOR_ARCHITECTURE_UNKNOWN:
		printf("UNKNOW");
		break;

		default:break;
		}
		printf("\n\n\t************************************************************************************************************\\\n\n");
		getchar();


}


/*******************************************************************************************************

����������û���

********************************************************************************************************/


void GetUser(){

	DWORD jisuanjiname=MAX_COMPUTERNAME_LENGTH+1;
	DWORD username=30;
	
	char Jisuanjiname[MAX_COMPUTERNAME_LENGTH+1];
	char susername[30];

		system("cls");
		printf("\n\t\t\t\t����ȡ����������û�����\n\n");
		printf("\t************************************************************************************************************\\\n\n");

	if(SetComputerNameA("My_Computer"))
	{

	printf("\tsuccess ComputerName\n");

	}


	GetComputerNameA(Jisuanjiname,&jisuanjiname);


	printf("\t�������:%s\n",Jisuanjiname);
	GetUserNameA(susername,&username);
	printf("\t�û���:%s\n",susername);

	

	printf("\n\t************************************************************************************************************\\\n\n");
		getchar();

}


/*******************************************************************************************************

����ƶ��ٶ�

********************************************************************************************************/

void GetMouseMoveSpeed(){


	BOOL ret;
	static int mouse,mouse2;
	int mouse1[3];

	system("cls");
		printf("\n\t\t\t\t����ȡ����ٶȡ�\n\n");
		printf("\t************************************************************************************************************\\\n\n");


	ret=SystemParametersInfo(SPI_GETMOUSE,0,&mouse,0);
	if(ret)
	{
	printf("\t�����ٶ�%d\n",mouse);
	}

	mouse1[1]=2*mouse;
	SystemParametersInfo(SPI_GETMOUSE,0,mouse1,SPIF_SENDCHANGE);
	ret=SystemParametersInfo(SPI_GETMOUSE,0,&mouse2,0);
	if(ret)
	{
	printf("\t�����ٶ�%d\n",mouse2);
	}

		printf("\n\t************************************************************************************************************\\\n\n");
		getchar();


}

/*******************************************************************************************************

ϵͳʱ��

********************************************************************************************************/


void GetSystemTimeInfo(){

	system("cls");
		printf("\n\t\t\t\t��ʱ���ȡ��\n\n");
	printf("\t************************************************************************************************************\\\n\n");

			SYSTEMTIME time;
		GetLocalTime(&time);
		printf("\t��ǰʱ��Ϊ��%.2d:%.2d:%.2d\n",time.wHour,time.wMinute,time.wSecond);
		printf("\t��ǰ������Ϊ��%4d:%.2d:%.2d\n",time.wYear,time.wMonth,time.wDay);
	printf("\n\t************************************************************************************************************\\\n\n");
		getchar();


}


/*******************************************************************************************************

ϵͳ����ͷ

********************************************************************************************************/

void GetCapInfo(){

	char strDeviceVersion[80];    //�豸�汾��Ϣ
		char  strDeviceAndVersion[160];  //�豸���Ͱ汾��Ϣ
		int nIndex;
		int nDriverCount = 0;                //֧�ֵ��豸�����������
   system("cls");
		printf("\n\t\t\t\t���������ͷ��Ϣ��\n\n");
		printf("\t************************************************************************************************************\\\n\n");
   
		for(nIndex=0; nIndex <9; nIndex++) 
		{ 
			if(capGetDriverDescriptionA(nIndex,strDeviceAndVersion,sizeof(strDeviceAndVersion),strDeviceVersion,sizeof(strDeviceVersion))) 
			{ 
				
				nDriverCount++;                  //�õ�vfw�豸��Ϣ�������豸����
				printf("\t�豸��:%s\n\n\t�豸�汾��Ϣ%s\n",strDeviceAndVersion,strDeviceVersion);
				
			} 
			
		} 
		if (nDriverCount==0)
			printf("\n\tû������ͷ\n"); 
		else{
			printf("\n\n\t֧�ֵ��豸�����������:%d\n",nDriverCount); 
		

		
		}

	printf("\n\t************************************************************************************************************\\\n\n");
		getchar();

}


/*******************************************************************************************************

ϵͳ������Ϣ

********************************************************************************************************/


void GetDiskTypeInfo(){


	char disk=NULL;
UINT type=0;
char drivename[4]={0};

char SZname[MAX_PATH]={0};
DWORD dwflags;
DWORD cuowu;
BOOL ret;
DWORD64 a,b,c;
float a1,b1,c1;
char DriveShowname[MAX_PATH]={0};
sprintf(drivename,"a:\0");
system("cls");
		printf("\n\t\t\t\t����������Ϣ��\n\n");
		printf("\t************************************************************************************************************\\\n\n");
   
for(drivename[0]='a';drivename[0]<='z';drivename[0]++)
{
	type=::GetDriveTypeA(drivename);
	if(type==DRIVE_REMOVABLE)
	{
		disk=drivename[0];
		printf("\t%c�̣�USB�ƶ�Ӳ��\n",disk-32);
		GetVolumeInformationA(drivename,DriveShowname,MAX_PATH,NULL,NULL,&dwflags,SZname,MAX_PATH);
		ret=GetDiskFreeSpaceExA(drivename,(PULARGE_INTEGER)&a,(PULARGE_INTEGER)&b,(PULARGE_INTEGER)&c);
	
		printf("\n\t\t************************\n\n");
				printf("\t\t��������:%s\n\t\t�ļ�ϵͳ����:%s\n",DriveShowname,SZname);
		if(ret)
		{
			a1=c/1024.0/1024.0/1024.0;
			b1=b/1024.0/1024.0/1024.0;
			c1=c/1024.0/1024.0/1014.0;		
			printf("\t\t����ռ�:%.3f GB\n",a1);
			printf("\t\t���ÿռ�:%.3f GB\n",b1-c1);
			printf("\t\t�ܿռ��ֽ�:%.3f GB\n",b1);
			
		}
			printf("\n\t\t************************\n\n");


	}
	else if(type==DRIVE_CDROM)
	{
		disk=drivename[0];
		printf("\t%c�̣�����CDROM\t",disk-32);

		if(!GetVolumeInformationA(drivename,DriveShowname,MAX_PATH,NULL,NULL,&dwflags,SZname,MAX_PATH)){cuowu=GetLastError();
			if(cuowu==21)
			{
			printf("\tû�й���\n");
			}}else{
				ret=GetDiskFreeSpaceExA(drivename,(PULARGE_INTEGER)&a,(PULARGE_INTEGER)&b,(PULARGE_INTEGER)&c);
				printf("\n\t\t************************\n\n");
				printf("\t\t���ڹ���\n");
				printf("\t\t��������:%s\n\t\t�ļ�ϵͳ����:%s\n",DriveShowname,SZname);
							if(ret)
					{
						a1=c/1024.0/1024.0/1024.0;
						b1=b/1024.0/1024.0/1024.0;
						c1=c/1024.0/1024.0/1014.0;		
						printf("\t\t����ռ�:%.3f GB\n",a1);
						printf("\t\t���ÿռ�:%.3f GB\n",b1-c1);
						printf("\t\t�ܿռ��ֽ�:%.3f GB\n",b1);
			
					}
				
				printf("\n\t\t************************\n\n");
			}
	}
	else if(type==DRIVE_RAMDISK)
	{
		disk=drivename[0];
		printf("\t%c�̣�RAMDISK\n",disk-32);
	}
	else if(type==DRIVE_FIXED)
	{
	disk=drivename[0];
	printf("\t%c�̣��̶�Ӳ��\n",disk-32);
	GetVolumeInformationA(drivename,DriveShowname,MAX_PATH,NULL,NULL,&dwflags,SZname,MAX_PATH);
	ret=GetDiskFreeSpaceExA(drivename,(PULARGE_INTEGER)&a,(PULARGE_INTEGER)&b,(PULARGE_INTEGER)&c);
			printf("\n\t\t************************\n\n");
				printf("\t\t��������:%s\n\t\t�ļ�ϵͳ����:%s\n",DriveShowname,SZname);
			if(ret)
		{
			a1=c/1024.0/1024.0/1024.0;
			b1=b/1024.0/1024.0/1024.0;
			c1=c/1024.0/1024.0/1014.0;
		
			printf("\t\t����ռ�:%.3f GB\n",a1);
			printf("\t\t���ÿռ�:%.3f GB\n",b1-c1);
			printf("\t\t�ܿռ��ֽ�:%.3f GB\n",b1);
		
		}
			printf("\n\t\t************************\n\n");
	


	}
	else if(type==DRIVE_REMOTE){
	
	disk=drivename[0];
	printf("\t%c�̣�����Ӳ��\n",disk-32);
	
	}
	else if(type==DRIVE_UNKNOWN){
	
	disk=drivename[0];
	printf("\t%c�̣�δ֪��������\n",disk-32);
	
	}

}
printf("\n\t************************************************************************************************************\\\n\n");
		getchar();


}



/*******************************************************************************************************

��ǰ����

********************************************************************************************************/


void GetProcessInf(){


	PROCESSENTRY32 pe32;
	pe32.dwSize=sizeof(pe32);
	//ʹ��PROCESSENTRY32ǰ��ö������ô�С

	system("cls");
		printf("\n\t\t\t\t����ǰ���̡�\n\n");
printf("\t************************************************************************************************************\\\n\n");

	HANDLE hpxian=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	
	if(hpxian==INVALID_HANDLE_VALUE)
	{
		printf("\t���̻�ȡʧ��\n");
		return;
	}

	BOOL liu=Process32First(hpxian,&pe32);
char *proname;
	while(liu)
	{
		proname=(char *)malloc(sizeof(char)*MAX_PATH);
		WideCharToMultiByte(0,0,pe32.szExeFile,MAX_PATH,proname,MAX_PATH,0,0);
	printf("\t��������:%s\t\t\t",proname);
	printf("PID:%u\n",pe32.th32ProcessID);
	liu=Process32Next(hpxian,&pe32);
	free(proname);

	}
	CloseHandle(hpxian);

printf("\n\t************************************************************************************************************\\\n\n");
getchar();



}