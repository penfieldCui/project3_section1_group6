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
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class THomeForm : public TForm
{
__published:	// IDE-managed Components
	TTimer *UpdateTimer;
	TPanel *Panel1;
	TListView *ComputerListView;
	TPanel *Panel2;
	TPopupMenu *PopupMenu;
	TMenuItem *MenuItemDelete;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TMenuItem *Edit1;
	TMenuItem *urnonoff1;

	void __fastcall UpdateTimerTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComputerListViewDblClick(TObject *Sender);
	void __fastcall MenuItemDeleteClick(TObject *Sender);
	void __fastcall Panel5Click(TObject *Sender);
	void __fastcall Edit1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall urnonoff1Click(TObject *Sender); // generate by OnCreate event
private:	// User declarations

	std::vector<Computer> computers;

    void edit(TObject *Sender);

public:		// User declarations
	__fastcall THomeForm(TComponent* Owner);

    void SaveAll();

};
//---------------------------------------------------------------------------
extern PACKAGE THomeForm *HomeForm;
//---------------------------------------------------------------------------
#endif
