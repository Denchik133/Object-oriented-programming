//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Button1.h"
#include "TSG.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TBtnNClick *Btn;
TSG *Grid;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Btn = new TBtnNClick(Form1);
	Btn->Parent = Form1;
    Btn->Left = 70;
    Btn->Top = 100;
    Btn->Width = 200;
    Btn->Height = 30;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Grid = new TSG(Form1);
	Grid->Parent = Form1;
    Grid->Left = 50;
    Grid->Top = 80;
    Grid->Width = 300;
    Grid->Height = 200;
    Grid->RowCount = 5;
    Grid->ColCount = 5;
}
//---------------------------------------------------------------------------
