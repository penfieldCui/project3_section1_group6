//---------------------------------------------------------------------------

#ifndef PC3pageH
#define PC3pageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TPC3pageform : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TButton *Homebutton;
	TButton *TurnOnMicbutton;
	TButton *TurnOnCamerbutton;
	TButton *MuteSpeakersbutton;
	TButton *SignOutbutton;
	TButton *RestartPCbutton;
	TLabel *Label10;
private:	// User declarations
public:		// User declarations
	__fastcall TPC3pageform(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPC3pageform *PC3pageform;
//---------------------------------------------------------------------------
#endif
