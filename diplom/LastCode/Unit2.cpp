//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall ThrFindDevice::ThrFindDevice(bool CreateSuspended)
    : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall ThrFindDevice::Execute()
{
    while(true)
    {
        Sleep(1000);
        if(Form1->CheckBox1->Checked & !Form1->Button1->Enabled)
        {
            if(Form1->FindDevice()) Form1->ComboBox1->Color = clGreen;
            else Form1->ComboBox1->Color = clRed;
        }
    }
}
//---------------------------------------------------------------------------
 