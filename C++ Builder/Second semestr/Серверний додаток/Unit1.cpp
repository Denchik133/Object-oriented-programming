#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
TDateTime Time_Working;
WSADATA wsa;
char buffer[512];

// ------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    clientCount = 0;
	WSAStartup(MAKEWORD(2,2), &wsa);
    edPort->Text = "1234";
    btnSwitch->Tag = 0;
    btnSwitch->Caption = "Start!";
    mLog->Clear();
}
// ------------------------------------------------
void __fastcall TForm1::tmrTimeTimer(TObject *Sender)
{
    pTime->Caption = TimeToStr(Time());
}
// ------------------------------------------------
void __fastcall TForm1::btnSwitchClick(TObject *Sender)
{
    if(btnSwitch->Tag==0) {
		serverSocket = socket(AF_INET,SOCK_STREAM,0);
        sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(StrToInt(edPort->Text));
		addr.sin_addr.s_addr = INADDR_ANY;
        bind(serverSocket,(sockaddr*)&addr,sizeof(addr));
		listen(serverSocket,SOMAXCONN);
		btnSwitch->Tag=1;
        btnSwitch->Caption="Shutdown!";
		mLog->Lines->Add("Сервер запущено");
        tmrSocket->Enabled=true;
    }
    else {
        closesocket(serverSocket);
        btnSwitch->Tag=0;
        btnSwitch->Caption="Start!";
		mLog->Lines->Add("Сервер зупинено");
        tmrSocket->Enabled=false;
    }
}
// ------------------------------------------------
void __fastcall TForm1::tmrSocketTimer(TObject *Sender)
{
    fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(serverSocket,&readfds);
	for(int i=0;i<clientCount;i++) {
		FD_SET(clients[i],&readfds);
    }
	timeval tv={0,0};
	if(select(0,&readfds,NULL,NULL,&tv)>0) {
		if(FD_ISSET(serverSocket,&readfds)) {
            SOCKET client=accept(serverSocket,NULL,NULL);
			clients[clientCount++]=client;
            lbUsers->Items->Add("User"+IntToStr(clientCount));
            mLog->Lines->Add("Новий клієнт");
		}
		for(int i=0;i<clientCount;i++) {
			if(FD_ISSET(clients[i],&readfds)) {
                int r=recv(clients[i],buffer,512,0);
				if(r>0) {
                	buffer[r]=0;
					AnsiString msg(buffer);
					mLog->Lines->Add(msg);
					for(int j=0;j<clientCount;j++) {
						send(clients[j],buffer,r,0);
					}
                }
            }
        }
    }
}

// ------------------------------------------------
void __fastcall TForm1::tmrWorkingTimer(TObject *Sender)
{
    Time_Working += 1./86400;
    Caption="Сервер працює "+TimeToStr(Time_Working);
}
