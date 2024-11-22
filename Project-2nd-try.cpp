//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("PC4page.cpp", PC4pageform);
USEFORM("PC3page.cpp", PC3pageform);
USEFORM("MainPage.cpp", Mainpageform);
USEFORM("PC1page.cpp", PC1pageform);
USEFORM("PC2page.cpp", PC2pageform);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TMainpageform), &Mainpageform);
		Application->CreateForm(__classid(TPC1pageform), &PC1pageform);
		Application->CreateForm(__classid(TPC2pageform), &PC2pageform);
		Application->CreateForm(__classid(TPC3pageform), &PC3pageform);
		Application->CreateForm(__classid(TPC4pageform), &PC4pageform);
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
