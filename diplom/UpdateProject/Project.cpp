//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainForm.cpp", SelectForm);
USEFORM("AboutForm.cpp", AboutMe);
USEFORM("EditForm.cpp", EditSelect);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TSelectForm), &SelectForm);
         Application->CreateForm(__classid(TAboutMe), &AboutMe);
         Application->CreateForm(__classid(TEditSelect), &EditSelect);
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
