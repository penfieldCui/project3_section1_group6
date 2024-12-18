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

		TListItem *item = ComputerListView->Items->Item[i];

		item->Caption = computers[i].GetName().c_str(); //

		if(!computers[i].IsPoweredOn()){
			item->SubItems->Strings[1] = "0.0" ;
			item->SubItems->Strings[2] = "0.0" ;

		} else if (!computers[i].IsConnected()) {
			item->SubItems->Strings[1] = "Unknown" ;
			item->SubItems->Strings[2] = "Unknown" ;

		} else{
            // update each sec
			computers[i].UpdateUsage();

			// get the correspond item

			double cpuUsagePercentage = computers[i].GetCpuUsage(); // CPU 使用率已经是百分比
			double ramUsagePercentage = computers[i].GetRamUsage();

			char buffer[10];
			snprintf(buffer, sizeof(buffer), "%.1f", cpuUsagePercentage);
			item->SubItems->Strings[1] = buffer; // CPU (%)

			snprintf(buffer, sizeof(buffer), "%.1f", ramUsagePercentage);
			item->SubItems->Strings[2] = buffer; // RAM (%)
		}

		item->SubItems->Strings[3] = (computers[i].IsConnected() ? "Connected" : "Disconnected");
		item->SubItems->Strings[4] = (computers[i].IsPoweredOn() ? "On" : "Off");



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
        SaveAll() ;
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
			SaveAll()  ;


    	}
	}
	else {
        ShowMessage("Please select an item to delete.");
	}
}
//---------------------------------------------------------------------------


// Add computer to list
void __fastcall THomeForm::Panel5Click(TObject *Sender)
{
	TAddComputerForm *addComputerForm = new TAddComputerForm(this);
	if (addComputerForm->ShowModal() == mrOk) {

		// input
//		string ipAddress = addComputerForm->EditIpAddress->Text.c_str();
//		string name = addComputerForm->EditName->Text.c_str();
		string ipAddress = AnsiString(addComputerForm->EditIpAddress->Text).c_str();
		string name = AnsiString(addComputerForm->EditName->Text).c_str();


		Computer newComputer = Computer(name, ipAddress); //
//		newComputer.PowerOn(); //
//		newComputer.Connect(); //
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

		SaveAll();

	}
}
//---------------------------------------------------------------------------
void THomeForm::edit(TObject *Sender){
	int index = ComputerListView->ItemIndex;
	if (index != -1) {
		TDetailForm *detailForm = new TDetailForm(this, &computers[index], this);
//		detailForm->SetComputer(computers[index]);
		detailForm->ShowModal();
		delete detailForm;
	}
}

void __fastcall THomeForm::ComputerListViewDblClick(TObject *Sender)
{
	edit(Sender);
}
//---------------------------------------------------------------------------

void __fastcall THomeForm::Edit1Click(TObject *Sender)
{
    edit(Sender);
}


// IO
//---------------------------------------------------------------------------
void THomeForm::SaveAll(){
	ofstream outFile("computer_list.txt");
	outFile << computers.size() << "\n";
	for (const auto &comp : computers) {
		comp.SaveToFile(outFile);
	}
	outFile.close();
}

void __fastcall THomeForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    SaveAll();
}
//---------------------------------------------------------------------------

void __fastcall THomeForm::urnonoff1Click(TObject *Sender)
{
	int index = ComputerListView->ItemIndex;
	if (index != -1) {

		Computer *computer = &computers[index];

		if(computer->IsPoweredOn())
			computer->PowerOff();
		else
			computer->PowerOn();

		SaveAll();
    }
}
//---------------------------------------------------------------------------

