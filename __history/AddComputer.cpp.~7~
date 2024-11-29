//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddComputer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddComputerForm *AddComputerForm;
//---------------------------------------------------------------------------
__fastcall TAddComputerForm::TAddComputerForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

// Ok

void __fastcall TAddComputerForm::ButtonOkClick(TObject *Sender)
{
     if (!EditIpAddress->Text.IsEmpty() && !EditName->Text.IsEmpty()) {
        ModalResult = mrOk;
	} else {
        ShowMessage("Please enter both IP Address and Name.");
    }
}
//---------------------------------------------------------------------------

void __fastcall TAddComputerForm::ButtonCancelClick(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

