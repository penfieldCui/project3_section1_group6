#include <vcl.h>
#pragma hdrstop

#include "Detail.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TDetailForm *DetailForm;

__fastcall TDetailForm::TDetailForm(TComponent* Owner, Computer* RComputer)
    : TForm(Owner)
{
	UpdateTimerDetail->Interval = 1000;
	UpdateTimerDetail->Enabled = true;

	this->computer = RComputer;

	FieldName->Text = computer->GetName().c_str();
	FieldIP->Text = computer->GetIpAddress().c_str();

    char buffer[10];
	snprintf(buffer, sizeof(buffer), "%6.1f%%", computer->GetCpuUsage());
	FieldCPU->Text = buffer; // CPU (%)

	snprintf(buffer, sizeof(buffer), "%6.1f%%", computer->GetRamUsage());
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

		// 组件类型
//		switch (component.GetType()) {
//            case Component::MICROPHONE:
//                item->Caption = "Microphone";
//                break;
//            case Component::CAMERA:
//                item->Caption = "Camera";
//                break;
//            case Component::CPU:
//                item->Caption = "CPU";
//                break;
//            case Component::RAM:
//                item->Caption = "RAM";
//				break;
//		}

//		item->SubItems->Add(std::to_string(component.GetType()).c_str());

		// CPU 使用率
		item->SubItems->Add(std::to_string(component.GetCpuUsage()).c_str());

		// RAM 使用率
		item->SubItems->Add(std::to_string(component.GetRamUsage()).c_str());

		// 电源状态
		item->SubItems->Add(component.IsPoweredOn() ? "On" : "Off");
	}

}

//void TDetailForm::SetComputer() {
//
//
//
//	//    EditRamUsage->Text = (std::to_string(computer.GetRamUsage()) + "MB").c_str();
//}


void __fastcall TDetailForm::UpdateTimerDetailTimer(TObject *Sender)
{
	//

	if (this->computer != nullptr)
	  for (int i = 0; i < computer->components.size(); ++i) {
		// update each sec
		computer->components[i].UpdateUsageComponent();

//		// get the correspond item
//        TListItem *item = ComputerListView->Items->Item[i];
//
//        double cpuUsagePercentage = computers[i].GetCpuUsage(); // CPU 使用率已经是百分比
//        double ramUsagePercentage = computers[i].GetRamUsage();
//
//		char buffer[10];
//		snprintf(buffer, sizeof(buffer), "%.1f", cpuUsagePercentage);
//		item->SubItems->Strings[1] = buffer; // CPU (%)
//
//		snprintf(buffer, sizeof(buffer), "%.1f", ramUsagePercentage);
//		item->SubItems->Strings[2] = buffer; // RAM (%)

		}
}
//---------------------------------------------------------------------------

void __fastcall TDetailForm::FieldNameChange(TObject *Sender)
{
	this->computer->SetName(std::string(AnsiString(FieldName->Text).c_str()));

}
//---------------------------------------------------------------------------

