//---------------------------------------------------------------------------

#ifndef HomeH
#define HomeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "Computer.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class THomeForm : public TForm
{
__published:	// IDE-managed Components
	TTimer *UpdateTimer;
	TPanel *Panel1;
	TListView *ComputerListView;

	void __fastcall UpdateTimerTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComputerListViewDblClick(TObject *Sender); // generate by OnCreate event
private:	// User declarations

	std::vector<Computer> computers;

public:		// User declarations
	__fastcall THomeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THomeForm *HomeForm;
//---------------------------------------------------------------------------
#endif