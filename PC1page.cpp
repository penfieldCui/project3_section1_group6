//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "PC1page.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Surface.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TPC1pageform::TPC1pageform(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
