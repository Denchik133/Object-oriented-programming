//---------------------------------------------------------------------------

#ifndef TSGH
#define TSGH
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class PACKAGE TSG : public TStringGrid
{
private:

protected:
    DYNAMIC void __fastcall KeyDown(WORD &Key, TShiftState Shift);
    DYNAMIC void __fastcall Click(void);

public:
    __fastcall TSG(TComponent* Owner);

__published:
};
//---------------------------------------------------------------------------
#endif
