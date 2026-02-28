//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "Button1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
static inline void ValidCtrCheck(TBtnNClick *)
{
	new TBtnNClick(NULL);
}
//---------------------------------------------------------------------------
__fastcall TBtnNClick::TBtnNClick(TComponent* Owner)
    : TButton(Owner)
{
    NClick = 0;
}
//---------------------------------------------------------------------------
void __fastcall TBtnNClick::Click(void)
{
	NClick++;
	Caption = Name + " (" + IntToStr(NClick) + ") клацань";
    TButton::Click();
}
//---------------------------------------------------------------------------
namespace Button1
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TBtnNClick)};
		RegisterComponents(L"MyClass", classes, 0);
	}
}
//---------------------------------------------------------------------------

