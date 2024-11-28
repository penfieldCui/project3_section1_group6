#ifndef DetailH
#define DetailH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Computer.h"
#include <Vcl.ComCtrls.hpp>

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

private:    // User declarations

public:     // User declarations
    __fastcall TDetailForm(TComponent* Owner);
    void SetComputer(const Computer &computer); // 设置计算机的详细信息
};

extern PACKAGE TDetailForm *DetailForm;

#endif

