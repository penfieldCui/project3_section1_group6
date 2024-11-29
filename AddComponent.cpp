//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddComponent.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddComponentForm *AddComponentForm;
//---------------------------------------------------------------------------
__fastcall TAddComponentForm::TAddComponentForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TAddComponentForm::ButtonOkClick(TObject *Sender)
{
	if (!EditType->Text.IsEmpty() && !EditCPUUsage->Text.IsEmpty() && !EditRAMUsage->Text.IsEmpty()) {
        ModalResult = mrOk;
	} else {
        ShowMessage("Please enter tyep, CPU usage and RAM usage.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TAddComponentForm::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------


