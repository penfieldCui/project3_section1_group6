//---------------------------------------------------------------------------

#ifndef AddComponentH
#define AddComponentH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TAddComponentForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TButton *ButtonOk;
	TButton *ButtonCancel;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label4;
	TEdit *EditType;
	TEdit *EditRAMUsage;
	TEdit *EditCPUUsage;
	void __fastcall ButtonOkClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAddComponentForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddComponentForm *AddComponentForm;
//---------------------------------------------------------------------------
#endif
