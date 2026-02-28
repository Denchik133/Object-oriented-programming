//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "TSG.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TSG *)
{
	new TSG(NULL);
}
//---------------------------------------------------------------------------
__fastcall TSG::TSG(TComponent* Owner)
	: TStringGrid(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSG::KeyDown(WORD &Key, TShiftState Shift)
{
	if(Key == VK_F11) {
		for(int i=0;i<RowCount;i++) {
			for(int j=0;j<ColCount;j++) {
				Cells[j][i] = IntToStr(random(100));
			}
		}
	}
	if(Key == VK_ESCAPE) {
		for(int i=0;i<RowCount;i++) {
			for(int j=0;j<ColCount;j++) {
				Cells[j][i] = "";
			}
		}
	}
    TStringGrid::KeyDown(Key,Shift);
}
//---------------------------------------------------------------------------
void __fastcall TSG::Click(void)
{
    Font->Size++;
    TStringGrid::Click();
}
namespace Tsg
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TSG)};
		RegisterComponents(L"MyClass", classes, 0);
	}
}
//---------------------------------------------------------------------------
