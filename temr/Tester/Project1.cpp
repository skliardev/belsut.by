//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", Form2);
USEFORM("Unit3.cpp", Form3);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 if(FileExists(ExtractFilePath(ParamStr(0))+"test.ft"))
                 {
                    Application->Initialize();
                    Application->CreateForm(__classid(TForm1), &Form1);
                    Application->CreateForm(__classid(TForm2), &Form2);
                    Application->CreateForm(__classid(TForm3), &Form3);
                    Application->Run();
                 }
                 else
                 {
                    ShowMessage("Отсутствует файл вопросов test.ft");
                    return 0;
                 }
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
