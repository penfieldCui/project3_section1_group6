//---------------------------------------------------------------------------

#ifndef MainPageH
#define MainPageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMainpageform : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TButton *Pcbutton1;
	TButton *Pcbutton2;
	TButton *Pcbutton3;
	TButton *Pcbutton4;
	void __fastcall Pcbutton3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainpageform(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainpageform *Mainpageform;
//---------------------------------------------------------------------------
#endif
