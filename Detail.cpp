#include <vcl.h>
#pragma hdrstop

#include "Detail.h"
#include "AddComponent.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TDetailForm *DetailForm;

__fastcall TDetailForm::TDetailForm(TComponent* Owner, Computer* RComputer, THomeForm* RHomeForm)
    : TForm(Owner), computer(RComputer), homeForm(RHomeForm)
{
	UpdateTimerDetail->Interval = 1000;
	UpdateTimerDetail->Enabled = true;

	FieldName->Text = computer->GetName().c_str();
	FieldIP->Text = computer->GetIpAddress().c_str();

    char buffer[10];
	snprintf(buffer, sizeof(buffer), "%5.1f%%", computer->GetCpuUsage());
	FieldCPU->Text = buffer; // CPU (%)

	snprintf(buffer, sizeof(buffer), "%5.1f%%", computer->GetRamUsage());
	FieldRAM->Text = buffer; // RAM (%)

//	FieldCPU->Text = (std::to_string(computer->GetCpuUsage()) + "%").c_str();
//	FieldRAM->Text = (std::to_string(computer->GetRamUsage()) + "%").c_str();
	FieldPower->Text = computer->IsPoweredOn() ? "On" : "Off";
	FieldNetwork->Text = computer->IsConnected() ? "Connected" : "Disconnected";

	// 清空 ComponentListView
	ComponentListView->Items->Clear();

	// 添加组件信息到 ListView 中
	for (const auto &component : computer->components) {
		TListItem *item = ComponentListView->Items->Add();



		item->Caption = AnsiString(component.GetType().c_str());

		// Power
		item->SubItems->Add(component.IsPoweredOn() ? "On" : "Off");

		double cpuUsagePercentage = component.GetCpuUsage();
		double ramUsagePercentage = component.GetRamUsage();

		char buffer[10];
		snprintf(buffer, sizeof(buffer), "%.1f", cpuUsagePercentage);
		item->SubItems->Add(buffer); // CPU (%)

		snprintf(buffer, sizeof(buffer), "%.1f", ramUsagePercentage);
		item->SubItems->Add(buffer); // RAM (%)


	}

}


void __fastcall TDetailForm::UpdateTimerDetailTimer(TObject *Sender)
{
	//


	if (this->computer != nullptr){

		FieldPower->Text = computer->IsPoweredOn() ? "On" : "Off";
		FieldNetwork->Text = computer->IsConnected() ? "Connected" : "Disconnected";



		// component list
        char buffer[10];
		for (int i = 0; i < computer->components.size(); ++i) {
			// update each sec
			computer->components[i].UpdateUsageComponent(computer->IsPoweredOn());

			// get the correspond item
			TListItem *item = ComponentListView->Items->Item[i];

			// power of component
			item->SubItems->Strings[0] = computer->components[i].IsPoweredOn() ? "On" : "Off";

			double cpuUsagePercentage = computer->components[i].GetCpuUsage(); // CPU 使用率已经是百分比
			double ramUsagePercentage = computer->components[i].GetRamUsage();


			snprintf(buffer, sizeof(buffer), "%.1f", cpuUsagePercentage);
			item->SubItems->Strings[1] = buffer; // CPU (%)

			snprintf(buffer, sizeof(buffer), "%.1f", ramUsagePercentage);
			item->SubItems->Strings[2] = buffer; // RAM (%)

		}


        computer->UpdateUsage();

		snprintf(buffer, sizeof(buffer), "%5.1f%%", computer->GetCpuUsage());
		FieldCPU->Text = buffer; // CPU (%)

		snprintf(buffer, sizeof(buffer), "%5.1f%%", computer->GetRamUsage());
		FieldRAM->Text = buffer; // RAM (%)

//		FieldCPU->Text = (std::to_string(computer->GetCpuUsage()) + "%").c_str();
//		FieldRAM->Text = (std::to_string(computer->GetRamUsage()) + "%").c_str();


    }
}
//---------------------------------------------------------------------------

//void __fastcall TDetailForm::FieldNameChange(TObject *Sender)
//{
//	this->computer->SetName(std::string(AnsiString(FieldName->Text).c_str()));
//
//}

//---------------------------------------------------------------------------

void __fastcall TDetailForm::ButtonSaveNameClick(TObject *Sender)
{
	this->computer->SetName(std::string(AnsiString(FieldName->Text).c_str()));
}
//---------------------------------------------------------------------------



void __fastcall TDetailForm::AddClick(TObject *Sender)
{
	TAddComponentForm *addComponentForm = new TAddComponentForm(this);
	if (addComponentForm->ShowModal() == mrOk) {

		// input
//		string ipAddress = addComputerForm->EditIpAddress->Text.c_str();
//		string name = addComputerForm->EditName->Text.c_str();
		string type = AnsiString(addComponentForm->EditType->Text).c_str();


        double ramUsage = StrToFloatDef(addComponentForm->EditRAMUsage->Text, 0.0);
        double cpuUsage = StrToFloatDef(addComponentForm->EditCPUUsage->Text, 0.0);

        Component newComponent(type, cpuUsage, ramUsage);
		computer->AddComponent(newComponent);



		// add to display

        TListItem *item = ComponentListView->Items->Add();
		item->Caption = newComponent.GetType().c_str();


		char buffer[10];
        snprintf(buffer, sizeof(buffer), "%.1f", newComponent.GetCpuUsage());
        item->SubItems->Add(buffer); // CPU 使用率

        snprintf(buffer, sizeof(buffer), "%.1f", newComponent.GetRamUsage());
		item->SubItems->Add(buffer); // RAM 使用率

		//
		item->SubItems->Add(newComponent.IsPoweredOn() ? "On" : "Off"); // 电源状态

		// using I/O function from Home
		if (homeForm) homeForm->SaveAll();

		ShowMessage("Component added successfully.");


	}

	delete addComponentForm;
}
//---------------------------------------------------------------------------

void __fastcall TDetailForm::ComponentListViewDblClick(TObject *Sender)
{
	int index = ComponentListView->ItemIndex;
	if (index != -1) {
		Component *PComponent = &computer->components[index];
		if(PComponent->IsPoweredOn())  PComponent->PowerOff();
		else PComponent->PowerOn();

		if (homeForm) homeForm->SaveAll();
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::urnonoff1Click(TObject *Sender)
{
	int index = ComponentListView->ItemIndex;
	if (index != -1) {
		Component *PComponent = &computer->components[index];
		if(PComponent->IsPoweredOn())  PComponent->PowerOff();
		else PComponent->PowerOn();

		if (homeForm) homeForm->SaveAll();
	}
}
//---------------------------------------------------------------------------


void __fastcall TDetailForm::Deletecomponent1Click(TObject *Sender)
{
	int selectedIndex = ComponentListView->ItemIndex;

	if (selectedIndex != -1) {

		int response = MessageDlg("Are you sure you want to delete this component?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);

		if (response == mrYes) {
			// delete from ListView
			ComponentListView->Items->Delete(selectedIndex);
			computer->components.erase(computer->components.begin() + selectedIndex);
			 // Save updated list to file
			if (homeForm) homeForm->SaveAll();

		}
	}
	else {
		ShowMessage("Please select an item to delete.");
	}
}
//---------------------------------------------------------------------------





void __fastcall TDetailForm::ButtonPowerClick(TObject *Sender)
{
	if(computer->IsPoweredOn())
		computer->PowerOff();
	else
		computer->PowerOn();

	if (homeForm) homeForm->SaveAll();
}
//---------------------------------------------------------------------------


void __fastcall TDetailForm::ButtonConnectClick(TObject *Sender)
{
	if(computer->IsConnected())
		computer->Disconnect();
	else
		computer->Connect();

	if (homeForm) homeForm->SaveAll();
}
//---------------------------------------------------------------------------


void __fastcall TDetailForm::BackClick(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TDetailForm::ButtonSaveIPClick(TObject *Sender)
{
	this->computer->SetIp(std::string(AnsiString(FieldIP->Text).c_str()));
}
//---------------------------------------------------------------------------

