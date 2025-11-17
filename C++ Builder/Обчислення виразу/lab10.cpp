//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "lab10.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------

class Telement{
protected:
Telement *left, *right;
Telement (Telement* l, Telement* r)
{
left = l;
right = r;
}
public:
~Telement(void)
{delete left; delete right;}

virtual float rezult(void) {}
};

class Number: public Telement{
float f;
public:
Number(float F):Telement(NULL,NULL)

{
f = F;
}
float rezult(void)
{return f;}
};

class Plus: public Telement{
public:
Plus(Telement*l, Telement*r):Telement(l, r) {};
float rezult(void)
{
return left->rezult() + right->rezult();
}
};

struct Mult:public Telement{
Mult(Telement*l, Telement*r):Telement(l, r) {};
float rezult(void)
{
return left->rezult()*right->rezult();
}

};

Telement*form(AnsiString s)
{
Telement*h;
int p;
int l = s.Length();
AnsiString s1, s2;
if ((p=s.Pos("+"))>1)
{
s1=s.SubString(1, p-1);
s2= s.SubString(p + 1, l-p);
h= new Plus(form(s1), form(s2));
}
else if ((p=s.Pos("*"))>1)
{
s1=s.SubString(1, p-1);
s2= s.SubString(p + 1, l-p);
h = new Mult(form(s1), form(s2));
}
else if (s =="x")
h = new Number(StrToFloat(Form1->Edit3->Text));
else if (s == "y")
h = new Number(StrToFloat(Form1->Edit9->Text));
else
h = new Number(StrToFloat(s));
return h;
}
//---------------------------------------------------------------------------
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int dec = StrToInt(ComboBox1->Text);
Telement* x = form(Edit1->Text);
float xval = x->rezult();
delete x;
Edit3->Text = FloatToStrF(xval, ffFixed, 25, dec);
Telement* y = form(Edit8->Text);
float yval = y->rezult();
Edit9->Text = FloatToStrF(yval, ffFixed, 25, dec);
delete y;
Telement* fx = form(Edit2->Text);
float fval = fx->rezult();
Edit4-> Text = FloatToStrF(fval, ffFixed, 25, dec);
delete fx;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
Button1Click(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Number* a = new Number(3);
Number* b = new Number(4);
Number* c = new Number(2);
Mult* m = new Mult(a, b);
Plus* p = new Plus(m, c);
Edit5->Text = FloatToStrF(p->rezult(), ffFixed, 25, 8);
Edit6->Text = FloatToStrF(m->rezult(), ffFixed, 25, 8);
Edit7->Text = FloatToStrF(a->rezult(), ffFixed, 25, 8);
delete p;
}

//---------------------------------------------------------------------------
