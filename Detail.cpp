#include <vcl.h>
#pragma hdrstop

#include "Detail.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TDetailForm *DetailForm;

__fastcall TDetailForm::TDetailForm(TComponent* Owner)
    : TForm(Owner)
{
}

void TDetailForm::SetComputer(const Computer &computer) {
    // ���ü������ϸ��Ϣ�� UI �ؼ�
//    EditIpAddress->Text = computer.GetIpAddress().c_str();
//    EditPowerState->Text = computer.IsPoweredOn() ? "On" : "Off";
//    EditCpuUsage->Text = (std::to_string(computer.GetCpuUsage()) + "%").c_str();
//    EditRamUsage->Text = (std::to_string(computer.GetRamUsage()) + "MB").c_str();
}
