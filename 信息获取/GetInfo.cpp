#include"GetInfo.h"


/*******************************************************************************************************

系统版本

********************************************************************************************************/

void GetVersionInfo(){

		system("cls");

		printf("\n\t\t\t\t【检测系统版本】\n\n");
		printf("\t************************************************************************************************************\\\n\n");

		 OSVERSIONINFO osvi;
		BOOL bIsWindowsXPorLater;

		ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

		GetVersionEx(&osvi);
		bIsWindowsXPorLater =((osvi.dwMajorVersion>5)||((osvi.dwMajorVersion == 5)&&(osvi.dwMinorVersion>=1)));

		if(bIsWindowsXPorLater)
			printf("\t你的电脑是xp以上的版本.\n");
		else 
		printf("\t你的电脑不是xp以上的版本.\n");

		printf("\n\t具体信息：\n");
		printf("\t操作系统主版本号:%d\n\t操作系统次版本号:%d\n\t操作系统编译版本号:%d\n\t操作系统的平台:%d\n\t指定安装在系统上的服务包:%S\n",osvi.dwMajorVersion,osvi.dwMinorVersion,osvi.dwBuildNumber,osvi.dwPlatformId,osvi.szCSDVersion);

		printf("\n\t************************************************************************************************************\\\n\n");

	getchar();

}


/*******************************************************************************************************

系统硬件信息

********************************************************************************************************/


void SystemInfonation(){


		SYSTEM_INFO xinxi;
		 GetSystemInfo(&xinxi);

		 system("cls");

		printf("\n\t\t\t\t【获取系统硬件信息】\n\n");
		printf("\t************************************************************************************************************\\\n\n");
 printf("\t内存分页大小：0x%.8x\n\t可以用内存起始:0x%.8x\n\t可用内存:0x%.8x\n\t处理器个数:%d\n\t处理器类型:",xinxi.dwPageSize,xinxi.lpMinimumApplicationAddress,xinxi.lpMaximumApplicationAddress,xinxi.dwNumberOfProcessors);
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


		printf("\n\t处理器架构:");

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

计算机名，用户名

********************************************************************************************************/


void GetUser(){

	DWORD jisuanjiname=MAX_COMPUTERNAME_LENGTH+1;
	DWORD username=30;
	
	char Jisuanjiname[MAX_COMPUTERNAME_LENGTH+1];
	char susername[30];

		system("cls");
		printf("\n\t\t\t\t【获取计算机名和用户名】\n\n");
		printf("\t************************************************************************************************************\\\n\n");

	if(SetComputerNameA("My_Computer"))
	{

	printf("\tsuccess ComputerName\n");

	}


	GetComputerNameA(Jisuanjiname,&jisuanjiname);


	printf("\t计算机名:%s\n",Jisuanjiname);
	GetUserNameA(susername,&username);
	printf("\t用户名:%s\n",susername);

	

	printf("\n\t************************************************************************************************************\\\n\n");
		getchar();

}


/*******************************************************************************************************

鼠标移动速度

********************************************************************************************************/

void GetMouseMoveSpeed(){


	BOOL ret;
	static int mouse,mouse2;
	int mouse1[3];

	system("cls");
		printf("\n\t\t\t\t【获取鼠标速度】\n\n");
		printf("\t************************************************************************************************************\\\n\n");


	ret=SystemParametersInfo(SPI_GETMOUSE,0,&mouse,0);
	if(ret)
	{
	printf("\t鼠标的速度%d\n",mouse);
	}

	mouse1[1]=2*mouse;
	SystemParametersInfo(SPI_GETMOUSE,0,mouse1,SPIF_SENDCHANGE);
	ret=SystemParametersInfo(SPI_GETMOUSE,0,&mouse2,0);
	if(ret)
	{
	printf("\t鼠标的速度%d\n",mouse2);
	}

		printf("\n\t************************************************************************************************************\\\n\n");
		getchar();


}

/*******************************************************************************************************

系统时间

********************************************************************************************************/


void GetSystemTimeInfo(){

	system("cls");
		printf("\n\t\t\t\t【时间获取】\n\n");
	printf("\t************************************************************************************************************\\\n\n");

			SYSTEMTIME time;
		GetLocalTime(&time);
		printf("\t当前时间为：%.2d:%.2d:%.2d\n",time.wHour,time.wMinute,time.wSecond);
		printf("\t当前年月日为：%4d:%.2d:%.2d\n",time.wYear,time.wMonth,time.wDay);
	printf("\n\t************************************************************************************************************\\\n\n");
		getchar();


}


/*******************************************************************************************************

系统摄像头

********************************************************************************************************/

void GetCapInfo(){

	char strDeviceVersion[80];    //设备版本信息
		char  strDeviceAndVersion[160];  //设备名和版本信息
		int nIndex;
		int nDriverCount = 0;                //支持的设备驱动程序个数
   system("cls");
		printf("\n\t\t\t\t【检测摄像头信息】\n\n");
		printf("\t************************************************************************************************************\\\n\n");
   
		for(nIndex=0; nIndex <9; nIndex++) 
		{ 
			if(capGetDriverDescriptionA(nIndex,strDeviceAndVersion,sizeof(strDeviceAndVersion),strDeviceVersion,sizeof(strDeviceVersion))) 
			{ 
				
				nDriverCount++;                  //得到vfw设备信息及连的设备数量
				printf("\t设备名:%s\n\n\t设备版本信息%s\n",strDeviceAndVersion,strDeviceVersion);
				
			} 
			
		} 
		if (nDriverCount==0)
			printf("\n\t没有摄像头\n"); 
		else{
			printf("\n\n\t支持的设备驱动程序个数:%d\n",nDriverCount); 
		

		
		}

	printf("\n\t************************************************************************************************************\\\n\n");
		getchar();

}


/*******************************************************************************************************

系统磁盘信息

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
		printf("\n\t\t\t\t【检测磁盘信息】\n\n");
		printf("\t************************************************************************************************************\\\n\n");
   
for(drivename[0]='a';drivename[0]<='z';drivename[0]++)
{
	type=::GetDriveTypeA(drivename);
	if(type==DRIVE_REMOVABLE)
	{
		disk=drivename[0];
		printf("\t%c盘：USB移动硬盘\n",disk-32);
		GetVolumeInformationA(drivename,DriveShowname,MAX_PATH,NULL,NULL,&dwflags,SZname,MAX_PATH);
		ret=GetDiskFreeSpaceExA(drivename,(PULARGE_INTEGER)&a,(PULARGE_INTEGER)&b,(PULARGE_INTEGER)&c);
	
		printf("\n\t\t************************\n\n");
				printf("\t\t驱动器名:%s\n\t\t文件系统类型:%s\n",DriveShowname,SZname);
		if(ret)
		{
			a1=c/1024.0/1024.0/1024.0;
			b1=b/1024.0/1024.0/1024.0;
			c1=c/1024.0/1024.0/1014.0;		
			printf("\t\t空余空间:%.3f GB\n",a1);
			printf("\t\t已用空间:%.3f GB\n",b1-c1);
			printf("\t\t总空间字节:%.3f GB\n",b1);
			
		}
			printf("\n\t\t************************\n\n");


	}
	else if(type==DRIVE_CDROM)
	{
		disk=drivename[0];
		printf("\t%c盘：光驱CDROM\t",disk-32);

		if(!GetVolumeInformationA(drivename,DriveShowname,MAX_PATH,NULL,NULL,&dwflags,SZname,MAX_PATH)){cuowu=GetLastError();
			if(cuowu==21)
			{
			printf("\t没有光盘\n");
			}}else{
				ret=GetDiskFreeSpaceExA(drivename,(PULARGE_INTEGER)&a,(PULARGE_INTEGER)&b,(PULARGE_INTEGER)&c);
				printf("\n\t\t************************\n\n");
				printf("\t\t存在光盘\n");
				printf("\t\t驱动器名:%s\n\t\t文件系统类型:%s\n",DriveShowname,SZname);
							if(ret)
					{
						a1=c/1024.0/1024.0/1024.0;
						b1=b/1024.0/1024.0/1024.0;
						c1=c/1024.0/1024.0/1014.0;		
						printf("\t\t空余空间:%.3f GB\n",a1);
						printf("\t\t已用空间:%.3f GB\n",b1-c1);
						printf("\t\t总空间字节:%.3f GB\n",b1);
			
					}
				
				printf("\n\t\t************************\n\n");
			}
	}
	else if(type==DRIVE_RAMDISK)
	{
		disk=drivename[0];
		printf("\t%c盘：RAMDISK\n",disk-32);
	}
	else if(type==DRIVE_FIXED)
	{
	disk=drivename[0];
	printf("\t%c盘：固定硬盘\n",disk-32);
	GetVolumeInformationA(drivename,DriveShowname,MAX_PATH,NULL,NULL,&dwflags,SZname,MAX_PATH);
	ret=GetDiskFreeSpaceExA(drivename,(PULARGE_INTEGER)&a,(PULARGE_INTEGER)&b,(PULARGE_INTEGER)&c);
			printf("\n\t\t************************\n\n");
				printf("\t\t驱动器名:%s\n\t\t文件系统类型:%s\n",DriveShowname,SZname);
			if(ret)
		{
			a1=c/1024.0/1024.0/1024.0;
			b1=b/1024.0/1024.0/1024.0;
			c1=c/1024.0/1024.0/1014.0;
		
			printf("\t\t空余空间:%.3f GB\n",a1);
			printf("\t\t已用空间:%.3f GB\n",b1-c1);
			printf("\t\t总空间字节:%.3f GB\n",b1);
		
		}
			printf("\n\t\t************************\n\n");
	


	}
	else if(type==DRIVE_REMOTE){
	
	disk=drivename[0];
	printf("\t%c盘：网络硬盘\n",disk-32);
	
	}
	else if(type==DRIVE_UNKNOWN){
	
	disk=drivename[0];
	printf("\t%c盘：未知磁盘类型\n",disk-32);
	
	}

}
printf("\n\t************************************************************************************************************\\\n\n");
		getchar();


}



/*******************************************************************************************************

当前进程

********************************************************************************************************/


void GetProcessInf(){


	PROCESSENTRY32 pe32;
	pe32.dwSize=sizeof(pe32);
	//使用PROCESSENTRY32前因该对其设置大小

	system("cls");
		printf("\n\t\t\t\t【当前进程】\n\n");
printf("\t************************************************************************************************************\\\n\n");

	HANDLE hpxian=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	
	if(hpxian==INVALID_HANDLE_VALUE)
	{
		printf("\t进程获取失败\n");
		return;
	}

	BOOL liu=Process32First(hpxian,&pe32);
char *proname;
	while(liu)
	{
		proname=(char *)malloc(sizeof(char)*MAX_PATH);
		WideCharToMultiByte(0,0,pe32.szExeFile,MAX_PATH,proname,MAX_PATH,0,0);
	printf("\t进程名称:%s\t\t\t",proname);
	printf("PID:%u\n",pe32.th32ProcessID);
	liu=Process32Next(hpxian,&pe32);
	free(proname);

	}
	CloseHandle(hpxian);

printf("\n\t************************************************************************************************************\\\n\n");
getchar();



}