//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Home.h"
#include "Detail.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THomeForm *HomeForm;
//---------------------------------------------------------------------------
__fastcall THomeForm::THomeForm(TComponent* Owner)
	: TForm(Owner)
{

	// 基本的窗体设置
	// 设置定时器
    UpdateTimer->Interval = 1000;
	UpdateTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall THomeForm::UpdateTimerTimer(TObject *Sender)
{
for (int i = 0; i < computers.size(); ++i) {
        // 更新每台计算机的使用情况
        computers[i].UpdateUsage();

        // 获取对应的 ListView 项
        TListItem *item = ComputerListView->Items->Item[i];

        // 更新 CPU 和 RAM 使用率显示
        double cpuUsagePercentage = computers[i].GetCpuUsage(); // CPU 使用率已经是百分比
        double ramUsagePercentage = computers[i].GetRamUsage();

		item->SubItems->Strings[1] = std::to_string(cpuUsagePercentage).c_str(); // 更新 CPU 使用率 (%)
        item->SubItems->Strings[2] = std::to_string(ramUsagePercentage).c_str(); // 更新 RAM 使用率 (%)
    }
}


void __fastcall THomeForm::FormCreate(TObject *Sender)
{
    // 初始化 Computer 实例并显示在 ListView 中
    for (int i = 0; i < 7; i++) {
        // 创建虚拟的 Computer 实例
        Computer comp("Computer " + std::to_string(i + 1), "192.168.0." + std::to_string(i + 1),   16384);
        comp.PowerOn();  // 设置计算机为开机状态
        comp.Connect();  // 设置计算机为联网状态
        computers.push_back(comp);


		//---------------------------------------------------------------------------
		// ComputerListView
        TListItem *item = ComputerListView->Items->Add();
		item->SubItems->Add(comp.GetName().c_str()); // 名称
		item->Caption = comp.GetIpAddress().c_str(); // IP 地址

		// CPU RAM
		double cpuUsagePercentage = comp.GetCpuUsage(); // %
		double ramUsagePercentage = comp.GetRamUsage();     // %

		item->SubItems->Add(std::to_string(cpuUsagePercentage).c_str()); // CPU (%)
		item->SubItems->Add(std::to_string(ramUsagePercentage).c_str()); // RAM (%)

		item->SubItems->Add(comp.IsConnected() ? "Connected" : "Disconnected"); // network
		item->SubItems->Add(comp.IsPoweredOn() ? "On" : "Off"); // power status

	}
}
//---------------------------------------------------------------------------


void __fastcall THomeForm::ComputerListViewDblClick(TObject *Sender)
{
	int index = ComputerListView->ItemIndex;
	if (index != -1) {
		TDetailForm *detailForm = new TDetailForm(this);
		detailForm->SetComputer(computers[index]);
		detailForm->ShowModal();
		delete detailForm;
	}
}
//---------------------------------------------------------------------------

