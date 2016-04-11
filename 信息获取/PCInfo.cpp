#include"GetInfo.h"


void  ShowError()
{

TCHAR *lpMsgBuf;

FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER| //�Զ�������Ϣ������
	FORMAT_MESSAGE_FROM_SYSTEM, //��ϵͳ�����Ϣ
	NULL,GetLastError(),//��ȡ�����ʶ
	MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),//ʹ��ϵͳȱʡ����
	(LPTSTR)&lpMsgBuf, //��Ϣ������
	0,
	NULL);

MessageBox(NULL,lpMsgBuf,TEXT("����"),MB_ICONERROR);



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
	
		else printf("\t�������󣺿�ʹ�õĲ����� version��system��name��speed��time��cap��disk��process\n\n");
	return 0;
	}
	HWND hwnd=GetForegroundWindow();
		SetWindowTextA(hwnd,"ϵͳ��Ϣ");
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
		printf("\n\n\t\t\t\t\t\t����ȡϵͳ��Ϣ��\n\n");
		printf("\t************************************************************************************************************\\\n\n");
		printf("\t**\tѡ�\t\t\n");
		printf("\t**\t1.���ϵͳ�汾\t\t\n");
		printf("\t**\t2.��ȡϵͳӲ����Ϣ\n");
		printf("\t**\t3.��ȡ����������û���\n");
		printf("\t**\t4.��ȡ����ٶ�\n");
		printf("\t**\t5.ʱ���ȡ\n");
		printf("\t**\t6.�������ͷ��Ϣ\n");
		printf("\t**\t7.��������Ϣ\n");
		printf("\t**\t8.��ǰ������Ϣ\n");
		printf("\t**\t0.�˳�\n");
		printf("\n\t************************************************************************************************************\\\n");
	
	printf("\n\t��ѡ��");
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


