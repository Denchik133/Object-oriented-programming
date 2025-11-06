//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lab08_1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


const UnicodeString label1 = "Портретна фотографія";
const UnicodeString label2 = "Художня фотографія";
const UnicodeString label3 = "Третя фотографія";

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (Button1->Caption == label2)
	{
		Image1->Visible = false;
		Image2->Visible = true;
		Button1->Caption = label3;
		Label6->Caption = label2;
	}
	else if (Button1->Caption == label3)
	{
		Image2->Visible = false;
		Image3->Visible = true;
		Button1->Caption = label1;
		Label6->Caption = label3;
	}
	else if (Button1->Caption == label1)
	{
		Image3->Visible = false;
		Image1->Visible = true;
		Button1->Caption = label2;
		Label6->Caption = label1;
	}
	Button2->Enabled = true;
	Button2->Visible = true;
	Label6->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Image1->Visible = false;
	Image2->Visible = false;
	Image3->Visible = false;
	Button2->Enabled = false;
	Button2->Visible = false;
	Label6->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Image1->Visible=false;
Image2->Visible=false;
Image3->Visible=true;
}
//---------------------------------------------------------------------------

