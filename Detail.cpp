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
    // 设置计算机详细信息到 UI 控件
//    EditIpAddress->Text = computer.GetIpAddress().c_str();
//    EditPowerState->Text = computer.IsPoweredOn() ? "On" : "Off";
//    EditCpuUsage->Text = (std::to_string(computer.GetCpuUsage()) + "%").c_str();
//    EditRamUsage->Text = (std::to_string(computer.GetRamUsage()) + "MB").c_str();
}

