//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <IdBaseComponent.hpp>
#include <IdCoder.hpp>
#include <IdCoder3To4.hpp>
#include <ComCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdIcmpClient.hpp>
#include <IdRawBase.hpp>
#include <IdRawClient.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <ScktComp.hpp>
#include "Unit2.h"
#include "Unit3.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TIdBase64Encoder *IdBase64Encoder1;
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TComboBox *ComboBox1;
    TEdit *Edit1;
    TEdit *Edit2;
    TEdit *Edit3;
    TButton *Button1;
    TCheckBox *CheckBox1;
    TTabSheet *TabSheet2;
    TIdIcmpClient *IcmpClient;
    TClientSocket *ClientSocket1;
    TADOConnection *ADOConnection1;
    TADOQuery *ADOQuery1;
    TButton *Button2;
    TButton *Button3;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *Edit5;
    TComboBox *ComboBox2;
    TComboBox *ComboBox3;
    TLabel *Label7;
    TLabel *Label8;
    TEdit *Edit4;
    TLabel *Label9;
    TEdit *Edit6;
    TCheckBox *CheckBox2;
    TCheckBox *CheckBox3;
    TTabSheet *TabSheet3;
    TLabel *Label10;
    TLabel *Label11;
    TEdit *Edit7;
    TLabel *Label13;
    TButton *Button4;
    TButton *Button5;
    TEdit *Edit10;
    TComboBox *ComboBox4;
    TLabel *Label12;
    TLabel *Label14;
    TTabSheet *TabSheet4;
    TLabel *Label15;
    TButton *Button6;
    TLabel *Label16;
    TLabel *Label17;
    TLabel *Label18;
    TLabel *Label19;
    TLabel *Label20;
    TLabel *Label21;
    TLabel *Label22;
    TLabel *Label23;
    TLabel *Label24;
    TLabel *Label26;
    TLabel *Label27;
    TLabel *Label28;
    TLabel *Label29;
    TLabel *Label30;
    TLabel *Label31;
    TLabel *Label32;
    TLabel *Label33;
    TLabel *Label34;
    TLabel *Label35;
    TLabel *Label36;
    TLabel *Label38;
    TLabel *Label39;
    TLabel *Label40;
    TLabel *Label41;
    TButton *Button7;
    TLabel *Label42;
    TPanel *Panel1;
    TPanel *Panel2;
    TLabel *Label43;
    TButton *Button8;
    TLabel *Label25;
    void __fastcall ComboBox1Click(TObject *Sender);
    void __fastcall CheckBox1Click(TObject *Sender);
    void __fastcall IcmpClientReply(TComponent *ASender,
          const TReplyStatus &AReplyStatus);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button7Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall ComboBox2Change(TObject *Sender);
    void __fastcall Button8Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Edit7Change(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
private:	// User declarations

public:		// User declarations
    int DEVICE;
    AnsiString dip, dauth;
    bool IStatus, IStack;
    bool PING;
    __fastcall TForm1(TComponent* Owner);
    AnsiString Base64(AnsiString login, AnsiString password);
    AnsiString SendHTTP(AnsiString ip, AnsiString text, AnsiString auth);
    AnsiString RandomName(AnsiString name);
    AnsiString TForm1::RandomPass(short count);
    void GetMACList(AnsiString text);
    void IEnable();
    void IDisable();
    void IPush();
    void IPop();
    bool FindDevice();
    bool Ping(AnsiString ip);
    ThrFindDevice *tr;
    TrRun *rt;
    TLocateOptions S;
    TStringList *sList;
    AnsiString GetMac(AnsiString text, int index = -1);
    void SetLabel25(AnsiString text);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
void __fastcall TForm1::IcmpClientReply(TComponent *ASender,
      const TReplyStatus &AReplyStatus)
{
    if(AReplyStatus.BytesReceived > 0) PING = true;
    else PING = false;
}
//---------------------------------------------------------------------------
void TForm1::IEnable()
{
    IStatus = true;
    Edit1->Enabled = true;
    Edit2->Enabled = true;
    Edit3->Enabled = true;
    Edit1->Color = clWhite;
    Edit2->Color = clWhite;
    Edit3->Color = clWhite;
}
//---------------------------------------------------------------------------
void TForm1::IDisable()
{
    IStatus = false;
    Edit1->Enabled = false;
    Edit2->Enabled = false;
    Edit3->Enabled = false;
    Edit1->Color = clBtnFace;
    Edit2->Color = clBtnFace;
    Edit3->Color = clBtnFace;
}
//---------------------------------------------------------------------------
void TForm1::IPush()
{
    IStack = IStatus;
}
//---------------------------------------------------------------------------
void TForm1::IPop()
{
    if(IStack) IEnable();
    else IDisable();
}
//---------------------------------------------------------------------------
AnsiString TForm1::SendHTTP(AnsiString ip, AnsiString text, AnsiString auth)
{
    AnsiString ret;
    ClientSocket1->Host = ip;
    ClientSocket1->Port = 80;
    ClientSocket1->Open();
    ClientSocket1->Socket->SendText("GET "+text+" HTTP/1.1\r\nHost: "+ip+"\r\nAuthorization: "+auth+"\r\nReferer: http://"+ip+"\r\n\r\n");
    Sleep(1000);
    ret = ClientSocket1->Socket->ReceiveText();
    ClientSocket1->Close();
    return ret;
}
//---------------------------------------------------------------------------
AnsiString TForm1::Base64(AnsiString login, AnsiString password)
{
    IdBase64Encoder1->AddCRLF = false;
    IdBase64Encoder1->UseEvent = false;
    IdBase64Encoder1->Reset();
    IdBase64Encoder1->CodeString(login + ":" + password);
    return "Basic " + IdBase64Encoder1->CompletedInput().Delete(1,2);
}
//---------------------------------------------------------------------------
bool TForm1::Ping(AnsiString ip)
{
    PING = false;
    IcmpClient->ReceiveTimeout = 1000;
    IcmpClient->Host = ip;
    IcmpClient->Ping();
    return PING;
}
//---------------------------------------------------------------------------
AnsiString TForm1::RandomName(AnsiString name)
{
    AnsiString tmp="";
    short n;
    
    while(name.Length())
    {
        randomize();
        n = random(name.Length() - 1);
        tmp =  tmp + name.SubString(n + 1, 1);
        name = name.Delete(n + 1, 1);
    }
    return tmp;    
}
//---------------------------------------------------------------------------
AnsiString TForm1::RandomPass(short count)
{
    AnsiString tmp="";
    unsigned __int8 a[9], i, n;

    for(i = 0; i < 9; i++) a[i] = i;

    for(i = 9; i > 0; i--)
    {
        randomize();
        n = random(i-1);
        tmp = tmp + AnsiString(a[n]);
        a[n] = a[i-1];
        if((i-1) == (9 - count)) break; //“ак как без этого будет бесконечный чикл!
    }
    return tmp;
}
//---------------------------------------------------------------------------
void TForm1::GetMACList(AnsiString text)
{
   ComboBox4->Clear();
    while(text.AnsiPos('-') > 0)
    {
        text = text.Delete(1, text.AnsiPos('-')-3);
        if(text.SubString(1,17).SubString(3,1) == '-' &&
            text.SubString(1,17).SubString(6,1) == '-' &&
            text.SubString(1,17).SubString(9,1) == '-' &&
            text.SubString(1,17).SubString(12,1) == '-' &&
            text.SubString(1,17).SubString(15,1) == '-')
        {
            ComboBox4->Items->Add(text.SubString(1,17));
            text.Delete(1,17);
        }
        else text = text.Delete(1,3);
    }
}
//---------------------------------------------------------------------------
AnsiString TForm1::GetMac(AnsiString text, int index)
{
    sList->Clear();
    while(text.AnsiPos('-') > 0)
    {
        text = text.Delete(1, text.AnsiPos('-')-3);
        if(text.SubString(1,17).SubString(3,1) == '-' &&
            text.SubString(1,17).SubString(6,1) == '-' &&
            text.SubString(1,17).SubString(9,1) == '-' &&
            text.SubString(1,17).SubString(12,1) == '-' &&
            text.SubString(1,17).SubString(15,1) == '-')
        {
            sList->Add(text.SubString(1,17));
            text.Delete(1,17);
        }
        else text = text.Delete(1,3);
    }

    return sList->Strings[index];
}
//---------------------------------------------------------------------------
void TForm1::SetLabel25(AnsiString text)
{
    Label25->Caption = text;
}
#endif
