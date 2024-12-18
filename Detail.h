#ifndef DetailH
#define DetailH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Computer.h"
#include "Home.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>

class TDetailForm : public TForm
{
__published:    // IDE-managed Components
//	TLabel *LabelIpAddress;
//	TEdit *EditIpAddress;
//	TLabel *LabelPowerState;
//	TEdit *EditPowerState;
//	TLabel *LabelCpuUsage;
//	TEdit *EditCpuUsage;
//	TLabel *LabelRamUsage;
//	TEdit *EditRamUsage;
//	TLabel *Label1;
//	TEdit *Edit1;
	TPanel *Panel1;
	TListView *ComponentListView;
	TPanel *Panel2;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *FieldName;
	TEdit *FieldIP;
	TLabel *Label3;
	TEdit *FieldCPU;
	TEdit *FieldRAM;
	TLabel *Label4;
	TEdit *FieldPower;
	TEdit *FieldNetwork;
	TTimer *UpdateTimerDetail;
	TButton *Back;
	TButton *ButtonSaveName;
	TPanel *Panel3;
	TPanel *Panel4;
	TButton *Add;
	TPanel *PanelComponentList;
	TPopupMenu *PopupMenu1;
	TMenuItem *Deletecomponent1;
	TButton *ButtonPower;
	TButton *ButtonConnect;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TMenuItem *urnonoff1;
	TButton *ButtonSaveIP;
	void __fastcall UpdateTimerDetailTimer(TObject *Sender);
	void __fastcall ButtonSaveNameClick(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall ComponentListViewDblClick(TObject *Sender);
	void __fastcall Deletecomponent1Click(TObject *Sender);
	void __fastcall ButtonPowerClick(TObject *Sender);
	void __fastcall ButtonConnectClick(TObject *Sender);
	void __fastcall urnonoff1Click(TObject *Sender);
	void __fastcall BackClick(TObject *Sender);
	void __fastcall ButtonSaveIPClick(TObject *Sender);

private:    // User declarations

//	std::vector<Component> components;
	Computer *computer;
	THomeForm* homeForm;

public:     // User declarations
	__fastcall TDetailForm(TComponent* Owner, Computer* RComputer, THomeForm* RHomeForm);
//	void SetComputer(const Computer &computer);
};

extern PACKAGE TDetailForm *DetailForm;

#endif

