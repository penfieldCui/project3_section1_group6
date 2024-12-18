//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Home.cpp", HomeForm);
USEFORM("AddComputer.cpp", AddComputerForm);
USEFORM("Detail.cpp", DetailForm);
USEFORM("AddComponent.cpp", AddComponentForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(THomeForm), &HomeForm);
		Application->CreateForm(__classid(TAddComputerForm), &AddComputerForm);
		Application->CreateForm(__classid(TDetailForm), &DetailForm);
		Application->CreateForm(__classid(TAddComponentForm), &AddComponentForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
