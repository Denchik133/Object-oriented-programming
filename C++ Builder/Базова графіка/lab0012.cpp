//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lab0012.h"
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int a,i,px,py,cx,cy;
const float pi = 3.141563;
a=100;
cx=Image1->Width/2;
cy=Image1->Height/2;
for (int i=0;i<=180;i++)
{px=(int)(a*pow(cos(2*pi*i/180),3));
py=(int)(a*pow(sin(2*pi*i/180),3));
Image1->Canvas->Pixels[cx+px][cy+py]=clBlue; }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int a,i,px,py,cx,cy;
const float pi = 3.141563;
a=100;
cx=Image1->Width/2;
cy=Image1->Height/2;
Image1->Canvas->MoveTo(cx,cy);
Image1->Canvas->Pen->Color=clRed;
for (int i=0;i<=180;i++)
{ px=(int)(a*pow(cos(2*pi*i/180),3));
py=(int)(a*pow(sin(2*pi*i/180),3));
Image1->Canvas->LineTo(cx+px,cy+py); }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Image1->Canvas->FillRect(Rect(0,0,Image1->Width,Image1->Height));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
if (RadioGroup1->ItemIndex==0)
for (X=0,Y=0;X+Y<300;X+=3,Y+=3)
Image1->Canvas->Pixels[X][Y]=clBlue;
else
{Image1->Canvas->Pen->Color=clRed;
Image1->Canvas->LineTo(X,Y);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Image2->Canvas->Font->Style << fsBold;
Image2->Canvas->Arc(10,10,90,90,90,50,10,50);
Image2->Canvas->TextOut(40,60,"Arc");
Image2->Canvas->Chord(110,10,190,90,190,50,110,50);
Image2->Canvas->TextOut(135,60,"Chord");
Image2->Canvas->Ellipse(210,10,290,50);
Image2->Canvas->TextOut(230,60,"Ellipse");
Image2->Canvas->Pie(310,10,390,90,390,30,310,30);
Image2->Canvas->TextOut(340,60,"Pie");
TPoint points[5];
points[0] = Point(30,150);
points[1] = Point(40,130);
points[2] = Point(50,140);
points[3] = Point(60,130);
points[4] = Point(70,150);
Image2->Canvas->Polygon(points,4);
Image2->Canvas->TextOut(30,170,"Polygon");
points[0].x += 100;
points[1].x += 100;
points[2].x += 100;
points[3].x += 100;
points[4].x += 100;
Image2->Canvas->Polyline(points,4);
Image2->Canvas->TextOut(130,170,"Polyline");
Image2->Canvas->Rectangle(230,120,280,160);
Image2->Canvas->TextOut(230,170,"Rectangle");
Image2->Canvas->RoundRect(330,120,380,160,20,20);
Image2->Canvas->TextOut(325,170,"RoundRect");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
for (int i = 1; i < 8; i++)
{Image3->Canvas->Pen->Style = TPenStyle(i-1);
Image3->Canvas->MoveTo(0,i*35);
Image3->Canvas->LineTo(Image1->Width,i*35);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
#define Pi 3.14159
float X,Y;
int PX,PY;
Image5->Canvas->MoveTo(0,Image5->Height / 2);
for (PX = 0; PX <= Image4->Width; PX++){
X = PX * 4 * Pi / Image4->Width;
Y = /*2 **/ sin(X);
PY = Image4->Height - (Y+1) * Image4->Height/2;
Image4->Canvas->Pixels[PX][PY] = clBlack;
Image5->Canvas->LineTo(PX,PY);
}
}
//---------------------------------------------------------------------------
short int num = 0;
short int H=30;
short int Xpos = 2 * H;
short int Ypos = 120;
short int Hmen = 30;
short int Rhead = 10;
short int Rhead2 = Rhead / 2;
short int revers = 1;
short int L = H * 1.41;
void __fastcall TForm1::Draw()
{
short int Yhead;
switch (num)
{
case 0:
Yhead = Ypos-H-Hmen;
Image6->Canvas->MoveTo(Xpos-H,Ypos);
Image6->Canvas->LineTo(Xpos,Ypos-H);
Image6->Canvas->LineTo(Xpos+H,Ypos);
Image6->Canvas->MoveTo(Xpos,Ypos-H);
Image6->Canvas->LineTo(Xpos,Yhead);
Image6->Canvas->MoveTo(Xpos+revers*H,Yhead-H);
Image6->Canvas->LineTo(Xpos,Yhead+4);
Image6->Canvas->Ellipse(Xpos+revers*H-Rhead2,Yhead-H+Rhead2,Xpos+revers*H+Rhead2,Yhead-H+Rhead2);
Image6->Canvas->LineTo(Xpos+revers*H,Yhead+H);
Image6->Canvas->Ellipse(Xpos+revers*H-Rhead2, Yhead+H-Rhead2,Xpos+revers*H+Rhead2, Yhead+H+Rhead2);
Image6->Canvas->Ellipse(Xpos-Rhead,Yhead,Xpos+Rhead, Yhead-2*Rhead);
Image6->Canvas->Rectangle(Xpos-Rhead,Yhead-2*Rhead-1, Xpos+Rhead,Yhead-2*Rhead-4);
break;
case 1:
Yhead = Ypos-L-Hmen;
Image6->Canvas->MoveTo(Xpos,Ypos);
Image6->Canvas->LineTo(Xpos,Yhead);
Image6->Canvas->MoveTo(Xpos,Yhead+4);
Image6->Canvas->LineTo(Xpos+revers*L,Yhead+4);
Image6->Canvas->Ellipse(Xpos+revers*L-Rhead2,Yhead+4-Rhead2, Xpos+revers*L+Rhead2,Yhead+4+Rhead2);
Image6->Canvas->Ellipse(Xpos-Rhead,Yhead,Xpos+Rhead,Yhead-2*Rhead);
Image6->Canvas->Rectangle(Xpos-H/2, Yhead-2*Rhead-1, Xpos+H/2, Yhead-2*Rhead-4);
}
}
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Image6->Canvas->MoveTo(0,Ypos+3);
Image6->Canvas->Pen->Width = 4;
Image6->Canvas->LineTo(Image1->ClientWidth,Ypos+3);
Image6->Canvas->Pen->Width = 1;
Image6->Canvas->Pen->Mode = pmNotXor;
Draw();
}
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Draw();
if ((Xpos >= Image6->Picture->Width-H)||(Xpos <= H))
revers = -revers;
Xpos = Xpos + revers * H;
num = 1-num;
Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
Timer1->Enabled = ! Timer1->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
Image7->Canvas->Brush->Color=clWhite;
Image7->Canvas->FillRect(Rect(0,0,Image7->Width,Image7->Height));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image7MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
int sx,sy;
sx=random(100); sy=random(100);
Image7->Canvas->Brush->Color=TColor(RGB(0 - sx*sy, 255 - sx*sy, 0 - sx*sy));
switch (RadioGroup4->ItemIndex) {
case 0: Image7->Canvas->Pen->Mode=pmCopy;break;
case 1: Image7->Canvas->Pen->Mode=pmXor; break;
case 2: Image7->Canvas->Pen->Mode=pmNotXor; break; }
switch (RadioGroup3->ItemIndex) {
case 0: Image7->Canvas->Brush->Style=bsSolid; break;
case 1: Image7->Canvas->Brush->Style=bsCross; break;
case 2: Image7->Canvas->Brush->Style=bsDiagCross; break;
case 3: Image7->Canvas->Brush->Style=bsVertical; break; }
switch (RadioGroup2->ItemIndex) {
case 0: Image7->Canvas->Rectangle(X,Y,X+sx,Y+sy); break;
case 1: Image7->Canvas->Ellipse(X,Y,X+sx,Y+sy); break;
case 2: Image7->Canvas->TextOut(X,Y, "Графіка в С++ Builder"); break;
case 3:
Image7->Canvas->Brush->Color=TColor(RGB(0 - sx*sy, 255 - sx*sy, 0 - sx*sy));
Image7->Canvas->FloodFill(X,Y,clWhite,fsSurface);
break; }
}
//---------------------------------------------------------------------------
