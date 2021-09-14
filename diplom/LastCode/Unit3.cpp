//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TrRun::TrRun(bool CreateSuspended)
    : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TrRun::Execute()
{

    GetEnvironmentVariableA("USERPROFILE", dir.c_str(), 256);
    mem = new TStringList;
    mem->Clear();
    mem->Add("Доступ к беспроводной точке доступа WiFi");
    mem->Add("----------------------------------------");
    mem->Add("Имя wifi: " + Form1->Edit4->Text);
    mem->Add("Пароль  : " + Form1->Edit6->Text);
    mem->Add("");
    mem->Add("");
    mem->Add("Доступ к личному кабинету абонента");
    mem->Add("----------------------------------");
    mem->Add("Сайт    : garant-tv.by");
    mem->Add("Логин   : " + Form1->ComboBox2->Text);
    mem->Add("Пароль  : " + Form1->Edit5->Text);
    mem->SaveToFile(AnsiString(dir.c_str()) + "\\Desktop\garant.txt");
    
    if(Form1->ComboBox1->ItemIndex)
    {
        //QSS
        Form1->ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE NAME = 'tQSS' AND DEVICE = " + AnsiString(Form1->DEVICE)+";";
        Form1->ADOQuery1->Active = true;

        if(Form1->ADOQuery1->RecordCount)
        {
            while(!Form1->ADOQuery1->Eof){
                Form1->SendHTTP(Form1->dip, Form1->ADOQuery1->FieldByName("WEB")->AsString, Form1->dauth);
                Form1->ADOQuery1->Next();
            }
            Form1->Label28->Caption = "+";
        }
        else
        {
            Form1->Label28->Caption = "N";
        }

        Form1->Repaint();

        if(Form1->ComboBox3->ItemIndex)
        {
            //VPN
            Form1->ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE NAME = 'tVPN' AND DEVICE = " + AnsiString(Form1->DEVICE)+";";
            Form1->ADOQuery1->Active = true;
            if(Form1->ADOQuery1->RecordCount)
            {
                while(!Form1->ADOQuery1->Eof){
                    //Выполнить замену полей
                    tmp = StringReplace(Form1->ADOQuery1->FieldByName("WEB")->AsString,"!NAMEVPN",Form1->ComboBox2->Text,TReplaceFlags()<<rfReplaceAll);
                    tmp = StringReplace(tmp,"!PASSVPN",Form1->Edit5->Text,TReplaceFlags()<<rfReplaceAll);
                    tmp = StringReplace(tmp,"!SERVERNAMEVPN",Form1->ComboBox3->Text,TReplaceFlags()<<rfReplaceAll);
                    Form1->SendHTTP(Form1->dip, tmp, Form1->dauth);
                    Form1->ADOQuery1->Next();
                }
                Form1->Label34->Caption = "+";
            }
            else
            {
                Form1->Label34->Caption = "N";
            }
        }
        else
        {
            Form1->Label22->Font->Style = TFontStyles() << fsStrikeOut;    
        }

        Form1->Repaint();

        //WIFI
        Form1->ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE NAME = 'tWIFI' AND DEVICE = " + AnsiString(Form1->DEVICE)+";";
        Form1->ADOQuery1->Active = true;
        if(Form1->ADOQuery1->RecordCount)
        {
            while(!Form1->ADOQuery1->Eof){
                //Выполнить замену полей
                tmp = StringReplace(Form1->ADOQuery1->FieldByName("WEB")->AsString,"!WIFINAME",Form1->Edit4->Text,TReplaceFlags()<<rfReplaceAll);
                tmp = StringReplace(tmp,"!WIFIPASS",Form1->Edit6->Text,TReplaceFlags()<<rfReplaceAll);
                Form1->SendHTTP(Form1->dip, tmp, Form1->dauth);
                Form1->ADOQuery1->Next();
            }
            Form1->Label29->Caption = "+";
            Sleep(500);
            Form1->Label30->Caption = "+";

        }
        else
        {
            Form1->Label29->Caption = "N";
            Sleep(500);
            Form1->Label30->Caption = "N";
        }

        Form1->Repaint();

        //РЕЗЕРВАЦИЯ
        Form1->ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE NAME = 'tIPRES' AND DEVICE = " + AnsiString(Form1->DEVICE)+";";
        Form1->ADOQuery1->Active = true;
        if(Form1->ADOQuery1->RecordCount)
        {
            while(!Form1->ADOQuery1->Eof){
                //Выполнить замену полей
                tmp = StringReplace(Form1->ADOQuery1->FieldByName("WEB")->AsString,"!MYMAC",Form1->ComboBox4->Text,TReplaceFlags()<<rfReplaceAll);
                tmp = StringReplace(tmp,"!MYIP",Form1->Edit7->Text,TReplaceFlags()<<rfReplaceAll);
                //Исполнить
                Form1->SendHTTP(Form1->dip, tmp, Form1->dauth);
                Form1->ADOQuery1->Next();
            }
            Form1->Label32->Caption = "+";
        }
        else
        {
            Form1->Label32->Caption = "N";
        }

        Form1->Repaint();

        //Проброс портов
        Form1->ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE NAME = 'tPORTRES' AND DEVICE = " + AnsiString(Form1->DEVICE)+";";
        Form1->ADOQuery1->Active = true;
        if(Form1->ADOQuery1->RecordCount)
        {
            while(!Form1->ADOQuery1->Eof){
                //Выполнить замену полей
                tmp = StringReplace(Form1->ADOQuery1->FieldByName("WEB")->AsString,"!IPPORT",Form1->Edit10->Text,TReplaceFlags()<<rfReplaceAll);
                tmp = StringReplace(tmp,"!MYIP",Form1->Edit7->Text,TReplaceFlags()<<rfReplaceAll);
                //Исполнить
                Form1->SendHTTP(Form1->dip, tmp, Form1->dauth);
                Form1->ADOQuery1->Next();
            }
            Form1->Label33->Caption = "+";
        }
        else
        {
            Form1->Label33->Caption = "N";
        }

        Form1->Repaint();

        if(Form1->CheckBox3->Checked)
        {
            //Клонирование MAC
            Form1->ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE NAME = 'tFINDMYMAC' AND DEVICE = " + AnsiString(Form1->DEVICE)+";";
            Form1->ADOQuery1->Active = true;
            if(Form1->ADOQuery1->RecordCount)
            {
                tmp = Form1->GetMac(Form1->SendHTTP(Form1->dip,Form1->ADOQuery1->FieldByName("WEB")->AsString, Form1->dauth), Form1->ADOQuery1->FieldByName("INFO")->AsInteger);

                Form1->SetLabel25(tmp);

                //Form1->Label25->Caption = tmp;

                Form1->ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE NAME = 'tCLONEMAC' AND DEVICE = " + AnsiString(Form1->DEVICE)+";";
                Form1->ADOQuery1->Active = true;

                if(Form1->ADOQuery1->RecordCount)
                {
                    while(!Form1->ADOQuery1->Eof){
                        //Выполнить замену полей
                        tmp = StringReplace(Form1->ADOQuery1->FieldByName("WEB")->AsString,"!CLONEMAC",tmp,TReplaceFlags()<<rfReplaceAll);
                        //Исполнить
                        Form1->SendHTTP(Form1->dip, tmp, Form1->dauth);
                        Form1->ADOQuery1->Next();
                    }
                    Form1->Label31->Caption = "+";
                }
                else
                {
                    Form1->Label31->Caption = "N";
                }
            }
            else
            {
                Form1->Label31->Caption = "N";
            }
        }
        else
        {
            Form1->Label19->Font->Style = TFontStyles() << fsStrikeOut;
        }

        Form1->Repaint();

        if(Form1->CheckBox2->Checked)
        {
            //IPTV
            Form1->ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE NAME = 'tIPTV4' AND DEVICE = " + AnsiString(Form1->DEVICE)+";";
            Form1->ADOQuery1->Active = true;
            if(Form1->ADOQuery1->RecordCount)
            {
                while(!Form1->ADOQuery1->Eof){
                    //Исполнить
                    Form1->SendHTTP(Form1->dip, Form1->ADOQuery1->FieldByName("WEB")->AsString, Form1->dauth);
                    Form1->ADOQuery1->Next();
                }
                Form1->Label35->Caption = "+";
                Sleep(500);
                Form1->Label36->Caption = "+";
            }
            else
            {
                Form1->Label35->Caption = "N";
            }
        }
        else
        {
            Form1->Label23->Font->Style = TFontStyles() << fsStrikeOut;
            //Перезапуск
            Form1->ADOQuery1->SQL->Text = "SELECT * FROM tWeb WHERE NAME = 'tRESET' AND DEVICE = " + AnsiString(Form1->DEVICE)+";";
            Form1->ADOQuery1->Active = true;
            if(Form1->ADOQuery1->RecordCount)
            {
                while(!Form1->ADOQuery1->Eof){
                    //Исполнить
                    Form1->SendHTTP(Form1->dip, Form1->ADOQuery1->FieldByName("WEB")->AsString, Form1->dauth);
                    Form1->ADOQuery1->Next();
                }
                Form1->Label36->Caption = "+";
            }
            else
            {
                Form1->Label36->Caption = "N";
            }
        }

        Form1->Repaint();

        while(system("c:\Windows\System32\cmd.exe garant-tv.by | find /i \"TTL=\""));
        Form1->Label38->Caption = "+";

        Form1->Repaint();

        system("script1.bat");
        Form1->Label39->Caption = "+";

        Form1->Update();
    }
    else
    {
        Form1->Label16->Font->Style = TFontStyles() << fsStrikeOut;
        Form1->Label17->Font->Style = TFontStyles() << fsStrikeOut;
        Form1->Label18->Font->Style = TFontStyles() << fsStrikeOut;
        Form1->Label19->Font->Style = TFontStyles() << fsStrikeOut;
        Form1->Label20->Font->Style = TFontStyles() << fsStrikeOut;
        Form1->Label21->Font->Style = TFontStyles() << fsStrikeOut;
        Form1->Label22->Font->Style = TFontStyles() << fsStrikeOut;
        Form1->Label23->Font->Style = TFontStyles() << fsStrikeOut;
        Form1->Label24->Font->Style = TFontStyles() << fsStrikeOut;

        Form1->Repaint();

        while(system("c:\Windows\System32\cmd.exe garant-tv.by | find /i \"TTL=\""));
        Form1->Label38->Caption = "+";

        Form1->Repaint();

        system("script2.bat");
        Form1->Label39->Caption = "+";

        Form1->Repaint();   
    }
    Form1->Label40->Caption = "+";
    Form1->Button6->Enabled = true;

    Form1->Repaint();
}
//---------------------------------------------------------------------------
