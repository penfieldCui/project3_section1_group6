//---------------------------------------------------------------------------

#ifndef AddComputerH
#define AddComputerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TAddComputerForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditIpAddress;
	TEdit *EditName;
	TLabel *Label3;
	TLabel *Label4;
	TButton *ButtonOk;
	TButton *ButtonCancel;
	void __fastcall ButtonOkClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAddComputerForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddComputerForm *AddComputerForm;
//---------------------------------------------------------------------------
#endif
