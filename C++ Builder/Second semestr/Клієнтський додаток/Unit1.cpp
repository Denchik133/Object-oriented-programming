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
    WSAStartup(MAKEWORD(2,2),&wsa);
    btnConnect->Tag=0;
    btnConnect->Caption="Connect!";
}
// ------------------------------------------------
void __fastcall TForm1::tmrTimeTimer(TObject *Sender)
{
    pTime->Caption=TimeToStr(Time());
}
// ------------------------------------------------
void __fastcall TForm1::btnConnectClick(TObject *Sender)
{
	if(btnConnect->Tag == 0) {
		clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(StrToInt(lePort->Text));
		addr.sin_addr.s_addr = inet_addr(AnsiString(leAddress->Text).c_str());
		int res = connect(clientSocket, (sockaddr*)&addr, sizeof(addr));
		if(res == 0) {
            AnsiString nick = "#" + leNickname->Text;
			send(clientSocket, nick.c_str(), nick.Length(), 0);
            btnConnect->Tag = 1;
			btnConnect->Caption = "Disconnect!";
			mLog->Lines->Add("Підключено до сервера");
            tmrSocket->Enabled = true;
        }
		else {
			int err = WSAGetLastError();
			mLog->Lines->Add("Помилка підключення! Код: " + IntToStr(err));
		}
	}
	else {
		closesocket(clientSocket);
        btnConnect->Tag = 0;
		btnConnect->Caption = "Connect!";
		mLog->Lines->Add("Відключено від сервера");
        tmrSocket->Enabled = false;
    }
}
// ------------------------------------------------
void __fastcall TForm1::tmrSocketTimer(TObject *Sender)
{
    u_long mode = 1;
	ioctlsocket(clientSocket, FIONBIO, &mode);
    int r = recv(clientSocket, buffer, 512, 0);
    if(r > 0)
    {
        buffer[r] = 0;
        mLog->Lines->Add(AnsiString(buffer));
    }
}
// ------------------------------------------------
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if(Key==13)
    {

	}
}


void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
AnsiString msg=leNickname->Text+": "+Edit1->Text;
send(clientSocket,msg.c_str(),msg.Length(),0);
Edit1->Text="";
}
//---------------------------------------------------------------------------
