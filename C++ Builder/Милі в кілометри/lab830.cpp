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
Edit2 -> SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
Label3->Caption = "3";
Edit1 -> SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
exit(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	float value, result, mileValue;
	if (RadioGroup1->ItemIndex == 0){
	mileValue = 1.609344;
	}
	else if (RadioGroup1->ItemIndex == 1){
	mileValue = 1.852;
	}

	if (RadioButton1 -> Checked){
	value = StrToFloat(Edit1->Text);
	result = value * mileValue;
	Edit2->Text = FloatToStr(result);
	}
	else if (RadioButton2 -> Checked){
	value = StrToFloat(Edit2->Text);
	result = value / mileValue;
	Edit1->Text = FloatToStr(result);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Edit1 -> Text = "";
Edit2 -> Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label3Click(TObject *Sender)
{
if (RadioButton1 -> Checked == true){
Label3 -> Caption = "4";
Edit2 -> SetFocus();
RadioButton1 -> Checked = false;
RadioButton2 -> Checked = true;
}
else {
Label3 -> Caption = "3";
Edit1 -> SetFocus();
RadioButton1 -> Checked = true;
RadioButton2 -> Checked = false;
}
}
//---------------------------------------------------------------------------


