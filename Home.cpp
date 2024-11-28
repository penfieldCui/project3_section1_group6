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

	// �����Ĵ�������
	// ���ö�ʱ��
    UpdateTimer->Interval = 1000;
	UpdateTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall THomeForm::UpdateTimerTimer(TObject *Sender)
{
for (int i = 0; i < computers.size(); ++i) {
        // ����ÿ̨�������ʹ�����
        computers[i].UpdateUsage();

        // ��ȡ��Ӧ�� ListView ��
        TListItem *item = ComputerListView->Items->Item[i];

        // ���� CPU �� RAM ʹ������ʾ
        double cpuUsagePercentage = computers[i].GetCpuUsage(); // CPU ʹ�����Ѿ��ǰٷֱ�
        double ramUsagePercentage = computers[i].GetRamUsage();

		item->SubItems->Strings[1] = std::to_string(cpuUsagePercentage).c_str(); // ���� CPU ʹ���� (%)
        item->SubItems->Strings[2] = std::to_string(ramUsagePercentage).c_str(); // ���� RAM ʹ���� (%)
    }
}


void __fastcall THomeForm::FormCreate(TObject *Sender)
{
    // ��ʼ�� Computer ʵ������ʾ�� ListView ��
    for (int i = 0; i < 7; i++) {
        // ��������� Computer ʵ��
        Computer comp("Computer " + std::to_string(i + 1), "192.168.0." + std::to_string(i + 1),   16384);
        comp.PowerOn();  // ���ü����Ϊ����״̬
        comp.Connect();  // ���ü����Ϊ����״̬
        computers.push_back(comp);


		//---------------------------------------------------------------------------
		// ComputerListView
        TListItem *item = ComputerListView->Items->Add();
		item->SubItems->Add(comp.GetName().c_str()); // ����
		item->Caption = comp.GetIpAddress().c_str(); // IP ��ַ

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
