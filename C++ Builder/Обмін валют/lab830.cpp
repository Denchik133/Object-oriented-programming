//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lab830.h"
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
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
Label3->Caption = "4";
Edit3 -> SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
Label3->Caption = "3";
Edit3 -> SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
exit(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
float f1 = StrToFloat(Edit1 ->Text);
float f2 = StrToFloat(Edit2 ->Text);
float f3 = StrToFloat(Edit3 ->Text);
float f4;
if (RadioButton1 -> Checked){
	f4 = f1* f3;
}
else {
	f4 = f2*f3;
}
Edit4 -> Text = FloatToStr(f4);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Edit3 -> Text = "";
Edit4 -> Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label3Click(TObject *Sender)
{
if (RadioButton1 -> Checked == true){
Label3 -> Caption = "4";
Edit3 -> SetFocus();
RadioButton1 -> Checked = false;
RadioButton2 -> Checked = true;
}
else {
Label3 -> Caption = "3";
Edit3 -> SetFocus();
RadioButton1 -> Checked = true;
RadioButton2 -> Checked = false;
}
}
//---------------------------------------------------------------------------


