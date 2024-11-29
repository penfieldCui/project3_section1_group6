//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Home.h"
#include "Detail.h"
#include "AddComputer.h"
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
		// update each sec
		computers[i].UpdateUsage();

		// get the correspond item
        TListItem *item = ComputerListView->Items->Item[i];

        double cpuUsagePercentage = computers[i].GetCpuUsage(); // CPU 使用率已经是百分比
        double ramUsagePercentage = computers[i].GetRamUsage();

		char buffer[10];
		snprintf(buffer, sizeof(buffer), "%.1f", cpuUsagePercentage);
		item->SubItems->Strings[1] = buffer; // CPU (%)

		snprintf(buffer, sizeof(buffer), "%.1f", ramUsagePercentage);
		item->SubItems->Strings[2] = buffer; // RAM (%)


		item->Caption = computers[i].GetName().c_str(); //

	}
}


void __fastcall THomeForm::FormCreate(TObject *Sender)
{


    // Check if the file exists and load computers from it if it does
	ifstream inFile("computer_list.txt");


    if (inFile) {
        try {
            size_t computerCount;
            inFile >> computerCount;

            for (size_t i = 0; i < computerCount; ++i) {
                Computer comp("", "");
                comp.LoadFromFile(inFile);
                computers.push_back(comp);

                // Add to display
                TListItem *item = ComputerListView->Items->Add();
                item->Caption = comp.GetName().c_str();
                item->SubItems->Add(comp.GetIpAddress().c_str());

                double cpuUsagePercentage = comp.GetCpuUsage();
                double ramUsagePercentage = comp.GetRamUsage();

                char buffer[10];
                snprintf(buffer, sizeof(buffer), "%.1f", cpuUsagePercentage);
                item->SubItems->Add(buffer);

                snprintf(buffer, sizeof(buffer), "%.1f", ramUsagePercentage);
                item->SubItems->Add(buffer);

                item->SubItems->Add(comp.IsConnected() ? "Connected" : "Disconnected");
                item->SubItems->Add(comp.IsPoweredOn() ? "On" : "Off");
            }
        } catch (...) {
            ShowMessage("Error reading computer list from file. Initializing default computers.");
        }
        inFile.close();
    } else {
        // Initialize default computers and save them to file
        for (int i = 0; i < 7; i++) {
            Computer comp("Computer " + std::to_string(i + 1), "192.168.0." + std::to_string(i + 1), 16384);
            comp.PowerOn();
            comp.Connect();
            computers.push_back(comp);

            // Add to display
            TListItem *item = ComputerListView->Items->Add();
            item->Caption = comp.GetName().c_str();
            item->SubItems->Add(comp.GetIpAddress().c_str());

            double cpuUsagePercentage = comp.GetCpuUsage();
            double ramUsagePercentage = comp.GetRamUsage();

            char buffer[10];
            snprintf(buffer, sizeof(buffer), "%.1f", cpuUsagePercentage);
            item->SubItems->Add(buffer);

            snprintf(buffer, sizeof(buffer), "%.1f", ramUsagePercentage);
            item->SubItems->Add(buffer);

            item->SubItems->Add(comp.IsConnected() ? "Connected" : "Disconnected");
            item->SubItems->Add(comp.IsPoweredOn() ? "On" : "Off");
        }

        // Save the initialized computers to file
        ofstream outFile("computer_list.txt");
        outFile << computers.size() << "\n";
        for (const auto &comp : computers) {
            comp.SaveToFile(outFile);
        }
        outFile.close();
	}

//	// 初始化 Computer 实例并显示在 ListView 中
//	for (int i = 0; i < 7; i++) {
//		// 创建虚拟的 Computer 实例
//		Computer comp("Computer " + std::to_string(i + 1), "192.168.0." + std::to_string(i + 1),   16384);
//		comp.PowerOn();  // 设置计算机为开机状态
//		comp.Connect();  // 设置计算机为联网状态
//		computers.push_back(comp);
//
//
//		//---------------------------------------------------------------------------
//		// ComputerListView
//		TListItem *item = ComputerListView->Items->Add();
//
//
//		item->Caption = comp.GetName().c_str(); //
//
//		item->SubItems->Add(comp.GetIpAddress().c_str()); //
//
//		// CPU RAM
//		double cpuUsagePercentage = comp.GetCpuUsage(); // %
//		double ramUsagePercentage = comp.GetRamUsage();     // %
//
//		char buffer[10];
//		snprintf(buffer, sizeof(buffer), "%.1f", cpuUsagePercentage);
//		item->SubItems->Add(buffer); // CPU (%)
//
//		snprintf(buffer, sizeof(buffer), "%.1f", ramUsagePercentage);
//		item->SubItems->Add(buffer); // RAM (%)
//
//
//
//		item->SubItems->Add(comp.IsConnected() ? "Connected" : "Disconnected"); // network
//		item->SubItems->Add(comp.IsPoweredOn() ? "On" : "Off"); // power status
//
//	}
}
//---------------------------------------------------------------------------


void __fastcall THomeForm::ComputerListViewDblClick(TObject *Sender)
{
	int index = ComputerListView->ItemIndex;
	if (index != -1) {
		TDetailForm *detailForm = new TDetailForm(this, &computers[index]);
//		detailForm->SetComputer(computers[index]);
		detailForm->ShowModal();
		delete detailForm;
	}
}
//---------------------------------------------------------------------------





void __fastcall THomeForm::MenuItemDeleteClick(TObject *Sender)
{
	int selectedIndex = ComputerListView->ItemIndex;

	if (selectedIndex != -1) {

		int response = MessageDlg("Are you sure you want to delete this computer?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0);

		if (response == mrYes) {
			// delete from ListView
			ComputerListView->Items->Delete(selectedIndex);
			computers.erase(computers.begin() + selectedIndex);

			 // Save updated list to file
			ofstream outFile("computer_list.txt");
			outFile << computers.size() << "\n";
			for (const auto &comp : computers) {
				comp.SaveToFile(outFile);
			}
			outFile.close();


    	}
	}
	else {
        ShowMessage("Please select an item to delete.");
	}
}
//---------------------------------------------------------------------------



void __fastcall THomeForm::Panel5Click(TObject *Sender)
{
	TAddComputerForm *addComputerForm = new TAddComputerForm(this);
	if (addComputerForm->ShowModal() == mrOk) {

		// input
//		string ipAddress = addComputerForm->EditIpAddress->Text.c_str();
//		string name = addComputerForm->EditName->Text.c_str();
		string ipAddress = AnsiString(addComputerForm->EditIpAddress->Text).c_str();
		string name = AnsiString(addComputerForm->EditName->Text).c_str();



		Computer newComputer(name, ipAddress); //
		newComputer.PowerOn(); //
		newComputer.Connect(); //
		computers.push_back(newComputer);

		// add to display

		TListItem *item = ComputerListView->Items->Add();
		item->Caption = newComputer.GetName().c_str(); //    name
		item->SubItems->Add(newComputer.GetIpAddress().c_str()); // IP 地址


		newComputer.UpdateUsage();

		double cpuUsagePercentage = newComputer.GetCpuUsage(); // CPU
		double ramUsagePercentage = newComputer.GetRamUsage();

		char buffer[10];
		snprintf(buffer, sizeof(buffer), "%.1f", cpuUsagePercentage);
		item->SubItems->Add(buffer); // CPU (%)

		snprintf(buffer, sizeof(buffer), "%.1f", ramUsagePercentage);
		item->SubItems->Add(buffer); // RAM (%)

		//
		item->SubItems->Add(newComputer.IsConnected() ? "Connected" : "Disconnected"); //
		item->SubItems->Add(newComputer.IsPoweredOn() ? "On" : "Off"); // power

        ofstream outFile("computer_list.txt");
        outFile << computers.size() << "\n";
        for (const auto &comp : computers) {
            comp.SaveToFile(outFile);
        }
        outFile.close();

	}
}
//---------------------------------------------------------------------------

void __fastcall THomeForm::Edit1Click(TObject *Sender)
{
	int index = ComputerListView->ItemIndex;
	if (index != -1) {
		TDetailForm *detailForm = new TDetailForm(this, &computers[index]);
//		detailForm->SetComputer(computers[index]);
		detailForm->ShowModal();
		delete detailForm;
	}
}
//---------------------------------------------------------------------------

