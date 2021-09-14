//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner), PING(false), sList(new TStringList)
{
    Form1->DoubleBuffered = true;
    PageControl1->ActivePage = TabSheet1;
    Edit5->Text = RandomPass(5);
    Sleep(1000);
    Edit6->Text = RandomPass(8);
    tr = new ThrFindDevice(false);
    rt = new TrRun(true);
    ADOQuery1->SQL->Text = "SELECT * FROM tTower";
    ADOQuery1->Active = true;
    while(!ADOQuery1->Eof)
    {
        ComboBox2->Items->Add(ADOQuery1->FieldByName("TOWER")->AsString);
        ADOQuery1->Next();
    }
    ADOQuery1->SQL->Text = "SELECT * FROM tName";
    ADOQuery1->Active = true;
    while(!ADOQuery1->Eof){
        ComboBox1->Items->Add(ADOQuery1->FieldByName("DEVICE")->AsString);
        ADOQuery1->Next();
    }

}
//---------------------------------------------------------------------------
bool TForm1::FindDevice()
{
    Edit1->Text = "0.0.0.0";
    // 1. Поиск IP
    try
    {
        if(!Ping("192.168.0.1"))
        {
            if(!Ping("192.168.0.1"))
            {
                Edit1->Color = clRed;
                return false;
            }
        }
    }
    catch(...)
    {
        Edit1->Color = clRed;
        return false;
    }

    dip = IcmpClient->Host;
    Edit1->Color = clGreen;
    Edit1->Text = dip;
    // 2. Распознать устройство
    dauth = Base64(Edit2->Text, Edit3->Text);
    try
    {
        if(!SendHTTP(dip, ADOQuery1->FieldByName("VER")->AsString, dauth).AnsiPos(ADOQuery1->FieldByName("WEB_VER")->AsString))
        {
            Edit2->Color = clRed;
            Edit3->Color = clRed;
            return false;
        }
    }
    catch(...)
    {
        Edit2->Color = clRed;
        Edit3->Color = clRed;
        return false;
    }
    Edit2->Color = clGreen;
    Edit3->Color = clGreen;
    // 3. Выбрать устройство
    ComboBox1->ItemIndex = ComboBox1->Items->IndexOf(ADOQuery1->FieldByName("DEVICE")->AsString);
    if(ComboBox1->ItemIndex) IStack = true;
    else IStack = false;
    Button1->Enabled = true;
    return true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Click(TObject *Sender)
{
    ComboBox1->Color = clWhite;
    if(ComboBox1->ItemIndex == 0)
        IDisable();
    else
        IEnable();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
    if(CheckBox1->Checked)
    {
        Button1->Enabled = false;
        ComboBox1->Enabled = false;
        ComboBox1->Color = clBtnFace;
        IPush();
        IDisable();
        tr->Resume();
    }
    else
    {
        Button1->Enabled = true;
        ComboBox1->Enabled = true;
        ComboBox1->Color = clWhite;
        IPop();
        tr->Suspend();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

    if(CheckBox1->Checked)
    {
        CheckBox1->Checked = false;
        PageControl1->ActivePage = TabSheet2;
    }
    else
    {
        if(!Ping(Edit1->Text))
        {
            ComboBox1->Color = clRed;
            Edit1->Color = clRed;
            Edit2->Color = clRed;
            Edit3->Color = clRed;
            return;
        }
        if(!SendHTTP(dip, ADOQuery1->FieldByName("VER")->AsString, dauth).AnsiPos(ADOQuery1->FieldByName("WEB_VER")->AsString))
        {
            ComboBox1->Color = clRed;
            Edit2->Color = clRed;
            Edit3->Color = clRed;
            return;
        }
        dip = Edit1->Text;
        dauth = Base64(Edit2->Text, Edit3->Text); 
        PageControl1->ActivePage = TabSheet2;
    }
    if(ComboBox1->ItemIndex)
    {
        ADOQuery1->SQL->Text = "SELECT * FROM tName WHERE DEVICE = '" + ComboBox1->Text+"';";
        ADOQuery1->Active = true;
        DEVICE = ADOQuery1->FieldByName("ID")->AsInteger;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    PageControl1->ActivePage = TabSheet1;
    ADOQuery1->SQL->Text = "SELECT * FROM tName";
    ADOQuery1->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    Edit4->Text = RandomName(Edit4->Text);
    Edit5->Text = RandomPass(5);
    Sleep(1000);
    Edit6->Text = RandomPass(8);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if(ComboBox1->ItemIndex)
    {
        ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE DEVICE = "+AnsiString(DEVICE)+";";
        ADOQuery1->Active = true;
        while(!ADOQuery1->Locate("NAME", "tMAC_ALL", S)) ADOQuery1->Next();
        GetMACList(SendHTTP(dip, ADOQuery1->FieldByName("WEB")->AsString, dauth));
        PageControl1->ActivePage = TabSheet3;
    }
    else
    {
        PageControl1->ActivePage = TabSheet4;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
    if(ComboBox2->Text.Length() && (Edit5->Text.Length() > 4) && Edit4->Text.Length() && (Edit6->Text.Length()> 7)) Button2->Enabled = true;
    else Button2->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
    ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE DEVICE = "+AnsiString(DEVICE)+";";
    ADOQuery1->Active = true;
    while(!ADOQuery1->Locate("NAME", "tMAC_ALL", S)) ADOQuery1->Next();
    GetMACList(SendHTTP(dip, ADOQuery1->FieldByName("WEB")->AsString, dauth));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    PageControl1->ActivePage = TabSheet4;
    rt->Resume();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7Change(TObject *Sender)
{
    if((Edit7->Text.Length() > 6) && (Edit10->Text.Length() > 4) && (ComboBox4->ItemIndex > -1)) Button4->Enabled = true;
    else Button4->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    PageControl1->ActivePage = TabSheet2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

