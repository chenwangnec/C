#include"GetInfo.h"


void  ShowError()
{

TCHAR *lpMsgBuf;

FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER| //自动分配消息缓冲区
	FORMAT_MESSAGE_FROM_SYSTEM, //从系统获得信息
	NULL,GetLastError(),//获取错误标识
	MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),//使用系统缺省语言
	(LPTSTR)&lpMsgBuf, //消息缓冲区
	0,
	NULL);

MessageBox(NULL,lpMsgBuf,TEXT("错误"),MB_ICONERROR);



}


int main(int argc,char *argv[]){

	if(argc==2){
	
		if(strcmp(argv[1],"version")==0){
		
			GetVersionInfo();
		}
		else if(strcmp(argv[1],"system")==0){
		SystemInfonation();

		}
		else if(strcmp(argv[1],"name")==0){
		GetUser();
		}
		else if(strcmp(argv[1],"speed")==0){
		GetMouseMoveSpeed();
		}
		else if(strcmp(argv[1],"time")==0){
		GetSystemTimeInfo();
		}
		else if(strcmp(argv[1],"cap")==0){
		GetCapInfo();
		}
		else if(strcmp(argv[1],"disk")==0){
		GetDiskTypeInfo();
		}
		else if(strcmp(argv[1],"process")==0){
		GetProcessInf();
		}
	
		else printf("\t参数错误：可使用的参数： version，system，name，speed，time，cap，disk，process\n\n");
	return 0;
	}
	HWND hwnd=GetForegroundWindow();
		SetWindowTextA(hwnd,"系统信息");
	int x=GetSystemMetrics(SM_CXSCREEN)+300,y=GetSystemMetrics(SM_CYSCREEN)+300;
	char setting[30];
	sprintf(setting,"mode con:cols=%d lines=%d",x,y);
	system(setting);
	
	 
		
		 ::SetWindowPos(hwnd, HWND_TOPMOST,0,0,x+300,y+300,NULL);
		
		 SetWindowRgn(hwnd, CreateRectRgn(30,30,x+1300,y+1300),true);
		 MoveWindow(hwnd,-30,-40,x+300,y+300,true);
	int choose=0;
	
	while(1){


		system("cls");
		system("color 0A");
		printf("\n\n\t\t\t\t\t\t【获取系统信息】\n\n");
		printf("\t************************************************************************************************************\\\n\n");
		printf("\t**\t选项：\t\t\n");
		printf("\t**\t1.检测系统版本\t\t\n");
		printf("\t**\t2.获取系统硬件信息\n");
		printf("\t**\t3.获取计算机名和用户名\n");
		printf("\t**\t4.获取鼠标速度\n");
		printf("\t**\t5.时间获取\n");
		printf("\t**\t6.检测摄像头信息\n");
		printf("\t**\t7.检测磁盘信息\n");
		printf("\t**\t8.当前进程信息\n");
		printf("\t**\t0.退出\n");
		printf("\n\t************************************************************************************************************\\\n");
	
	printf("\n\t请选择：");
	scanf("%d",&choose);
	getchar();
	
	switch(choose){

	case 0:{
		
		    return 0;
		   }break;

	
	case 1:{
		   GetVersionInfo();
		   }break;

	case 2:{
		   SystemInfonation();
		   }break;

	case 3:{
		   GetUser();
		   }break;

	case 4:{
		   GetMouseMoveSpeed();
		   }break;

	case 5:{
		   GetSystemTimeInfo();
		   }break;

	case 6:{
		GetCapInfo();
		    
		   }break;
	case 7:{
		GetDiskTypeInfo();
		    
		   }break;
	case 8:{
		    GetProcessInf();
		   }
		   break;
		
	
	default:break;
	
	
	}

	
	
	}




	return 0;



}


