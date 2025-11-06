//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lab09.h"
#include <math.h>
#include <vector>
using namespace std;
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
void __fastcall TForm1::N9Click(TObject *Sender)
{
Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
exit(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
float a = StrToFloat(Edit1->Text);
float b = StrToFloat(Edit2->Text);
float h = StrToFloat(Edit3->Text);
Memo1->Lines->Clear();
Memo1->Lines->Append("X\tY");
int n = (b - a) / h + 1;
float *Y = new float[n];
float x = a;
float y;
float max, min;
if (CheckBox4->Checked){
y = cos(a);
}
else{
y = sin(a) + 1;
}
max = y;
min = y;
int i = 0;
Series1->Clear();
while (x <= b + h/2){
	if (CheckBox4->Checked){
	y = cos(x);
	}
	else {
	y = sin(x) + 1;
	}
	if (CheckBox3->Checked && i < n){
	Y[i++] = y;
	}
	if (CheckBox1->Checked)
	{
	Memo1->Lines->Append(
	FloatToStrF(x, ffFixed, 8, 2) + "\t" +
	FloatToStrF(y, ffFixed, 8, 2)
	);
	}
	Series1->AddXY(x, y, "", clRed);
	if (y > max) { max = y; }
	if (y < min) { min = y; }
	x += h;
	}
int count = 0;
for (int j = 0; j < i; j++){
	if (Y[j] > 0.5 && Y[j] < 1)
	count++;
	}
if (CheckBox3->Checked){
Memo1->Lines->Append("");
Memo1->Lines->Append("Масив Y:");
for (int j = 0; j < i; j++){
Memo1->Lines->Append(FloatToStrF(Y[j], ffFixed, 8, 4));
}
Memo1->Lines->Append("");
Memo1->Lines->Append("Максимум: " + FloatToStrF(max, ffFixed, 8, 4));
Memo1->Lines->Append("Мінімум: " + FloatToStrF(min, ffFixed, 8, 4));
Memo1->Lines->Append("Кількість елементів (0.5 < Y < 1): " + IntToStr(count));
}
delete[] Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
CheckBox1->Checked = false;
CheckBox2->Checked = false;
CheckBox3->Checked = false;
CheckBox4->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
CheckBox1->Checked = true;
CheckBox2->Checked = true;
CheckBox3->Checked = true;
CheckBox4->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
CheckBox1->Checked = !CheckBox1->Checked;
CheckBox2->Checked = !CheckBox2->Checked;
CheckBox3->Checked = !CheckBox3->Checked;
CheckBox4->Checked = !CheckBox4->Checked;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N11Click(TObject *Sender)
{
float x, y;
float a = StrToFloat(Edit1->Text);
float b = StrToFloat(Edit2->Text);
float h = StrToFloat(Edit3->Text);
Series1->Clear();
for (x = a; x <= b + h/2; x += h){
	y = sin(x) + 1;
	Series1->AddXY(x, y, FloatToStrF(x, ffFixed, 2, 2), clRed);
	}
}
//---------------------------------------------------------------------------

