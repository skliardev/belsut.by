//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "AboutForm.h"
#include "EditForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSelectForm *SelectForm;
//---------------------------------------------------------------------------
__fastcall TSelectForm::TSelectForm(TComponent* Owner)
    : TForm(Owner), selLevel(1), selDevice(0), selConfig(0), stdSelect(false),
    bmp(new Graphics::TBitmap), bSelect(new TPicture), mem(new TMemoryStream)
{
    Connect->Connected = true;
    //Информация о базе данных
    Query->SQL->Text = "SELECT Update FROM tUpdate";
    Query->Active = true;
    lastUpdate = Query->FieldByName("Update")->AsString;
    Caption = "СервисГарант - обн. " + lastUpdate;
    //Загрузка таблиц
    IQuery->SQL->Text = "SELECT * FROM tImage";
    IQuery->Active = true;
    //Загрузка курсора
    if(IQuery->Locate("Name", "SYSSELECT", S) && !(TBlobField*)IQuery->FieldByName("Image")->IsNull && (IQuery->FieldByName("System")->AsString == "True"))
    {
        ((TGraphicField*)IQuery->FieldByName("Image"))->SaveToStream(mem);
        mem->Seek(0,0);
        bSelect->Bitmap->LoadFromStream(mem);
        mem->Clear();
        stdSelect = false;
    }
    else stdSelect = true;
    LoadList();
    List->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSelectForm::AuthorClick(TObject *Sender)
{
    //Об авторе
    AboutMe->SetUpdateProgram("12.03.2014");
    AboutMe->SetUpdateVer("1.0 BETA");
    AboutMe->SetAuthor("Скляр Дмитрий Алексеевич");
    AboutMe->SetMail("dima.1888420@mail.ru");
    AboutMe->SetUpdateBase(lastUpdate);
    AboutMe->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TSelectForm::ListDblClick(TObject *Sender)
{
    //Выбор device/config
    switch(selLevel)
    {
      case 1:
        if((List->ItemIndex == (List->Count - 1)) && GodMode->Checked)
        {
            EditSelect->AddDevice();
            LoadList();
            List->ItemIndex = List->Count - 2;
        }
        else
        {
            selLevel++;
            Query->Locate("Label", List->Items->Strings[List->ItemIndex], S);
            selDevice = Query->FieldByName("Code")->AsInteger;
            LoadList();
            List->ItemIndex = 0;
        }
      break;
      case 2:
        if(List->ItemIndex == 0)
        {
            selLevel--;
            selDevice = 0;
            LoadList();
            List->ItemIndex = 0;
        }
        else if((List->ItemIndex == (List->Count - 1)) && GodMode->Checked)
        {
            EditSelect->AddConfig();
            LoadList();
            List->ItemIndex = List->Count - 2;
        }
        else
        {
            selLevel++;
            Query->Locate("Label", List->Items->Strings[List->ItemIndex], S);
            selConfig = Query->FieldByName("Code")->AsInteger;
            LoadList();
            List->ItemIndex = 0;
        }
      break;
      case 3:
        if(List->ItemIndex == 0)
        {
            selLevel--;
            selConfig = 0;
            LoadList();
            List->ItemIndex = 0;
        }
        else if((List->ItemIndex == (List->Count - 1)) && GodMode->Checked)
        {
            //EditSelect->AddConfig();
            LoadList();
            List->ItemIndex = List->Count - 2;
        }
        else if(List->ItemIndex == 1)
        {
            LoadList();
            List->ItemIndex = 1;
        }
        else List->ItemIndex = 1;
      break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TSelectForm::ListDrawItem(TWinControl *Control, int Index,
      TRect &Rect, TOwnerDrawState State)
{
    //Перересовка списка
    TCanvas *pCanvas = ((TListBox *)Control)->Canvas;

    if(State.Contains(odSelected))
    {
        if(stdSelect)
        {
            pCanvas->Brush->Color = clBlack;
        }
        else
        {
            pCanvas->Brush->Style = bsClear;
            pCanvas->StretchDraw(Rect, bSelect->Graphic);
            DrawFocusRect(pCanvas->Handle, &Rect);
        }
    }
    pCanvas->FillRect(Rect);
    if((selLevel < 3) || (Index == 0) || (GodMode->Checked && (Index == (List->Count - 1))))
    {
        pCanvas->TextOut(Rect.left + 60, Rect.top + 19, List->Items->Strings[Index]);
        IList->Draw(pCanvas, Rect.left + 5, Rect.top + 5, Index, true);
    }
    else
    {

        pCanvas->TextOut(Rect.left + 15, Rect.top + 19, List->Items->Strings[Index]);
        IList->Draw(pCanvas, Rect.Right - 55, Rect.top + 5, Index, true);
    }
}
//---------------------------------------------------------------------------
void TSelectForm::LoadList()
{
    List->Clear();
    IList->Clear();
    if(selLevel > 1)
    {
        if(IQuery->Locate("Name", "SYSBACK", S) && !(TBlobField*)IQuery->FieldByName("Image")->IsNull && (IQuery->FieldByName("System")->AsString == "True"))
        {
            ((TGraphicField*)IQuery->FieldByName("Image"))->SaveToStream(mem);
            mem->Seek(0,0);
            bmp->LoadFromStream(mem);
            IList->Add(bmp, bmp);
            mem->Clear();
        }
        else IList->Add(NULL, NULL);
        List->Items->Add("..");
        if(selLevel > 2)
        {
            if(IQuery->Locate("Name", "SYSPROCESS", S) && !(TBlobField*)IQuery->FieldByName("Image")->IsNull && (IQuery->FieldByName("System")->AsString == "True"))
            {
                ((TGraphicField*)IQuery->FieldByName("Image"))->SaveToStream(mem);
                mem->Seek(0,0);
                bmp->LoadFromStream(mem);
                IList->Add(bmp, bmp);
                mem->Clear();
            }
            else IList->Add(NULL, NULL);
            List->Items->Add("Выполнить скрипт!");
        }
    }
    
    switch(selLevel)
    {
      case 1:
      case 2:
        Query->SQL->Text = "SELECT * FROM tName WHERE DevCode="+AnsiString(selDevice);
        Query->Active = true;
        while(!Query->Eof)
        {
            if(IQuery->Locate("Code", Query->FieldByName("ImgCode")->Value, S) && !(TBlobField*)IQuery->FieldByName("Image")->IsNull)
            {
                ((TGraphicField*)IQuery->FieldByName("Image"))->SaveToStream(mem);
                mem->Seek(0,0);
                bmp->LoadFromStream(mem);
                IList->Add(bmp, bmp);
                mem->Clear();
            }
            else IList->Add(NULL, NULL);
            List->Items->Add(Query->FieldByName("Label")->AsString);
            Query->Next();
        }
      break;
      case 3:
        Query->SQL->Text = "SELECT * FROM tCmdList WHERE Std=0 AND DevCode="+AnsiString(selConfig);
        Query->Active = true;
        while(!Query->Eof)
        {
            IList->Add(NULL, NULL);
            List->Items->Add(Query->FieldByName("Name")->AsString);
            Query->Next();
        }
      break;
    }

    if(GodMode->Checked)
    {
        if(IQuery->Locate("Name", "SYSADD", S) && !(TBlobField*)IQuery->FieldByName("Image")->IsNull && (IQuery->FieldByName("System")->AsString == "True"))
        {
            ((TGraphicField*)IQuery->FieldByName("Image"))->SaveToStream(mem);
            mem->Seek(0,0);
            bmp->LoadFromStream(mem);
            IList->Add(bmp, bmp);
            mem->Clear();
        }
        else IList->Add(NULL, NULL);
        List->Items->Add("Добавить");    
    }
}
//---------------------------------------------------------------------------
void __fastcall TSelectForm::FormDestroy(TObject *Sender)
{
    Connect->Close();
    delete mem;
    delete bmp;
    delete bSelect;
}
//---------------------------------------------------------------------------
void __fastcall TSelectForm::GodModeClick(TObject *Sender)
{
    LoadList();
    List->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSelectForm::ListKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    int saveindex = 0;
    if((Key == VK_RETURN) && (List->ItemIndex > -1)) List->OnDblClick(this);
    if(Key == VK_F2 && GodMode->Checked)
    {
        switch(selLevel)
        {
          case 1:
            if(List->ItemIndex != (List->Count - 1))
            {
                saveindex = List->ItemIndex;
                EditSelect->EditDevice();
                LoadList();
                List->ItemIndex = saveindex;
            }
          break;
          case 2:
            if((List->ItemIndex != (List->Count - 1)) &&(List->ItemIndex != 0))
            {
                saveindex = List->ItemIndex;
                EditSelect->EditConfig();
                LoadList();
                List->ItemIndex = saveindex;
            }
          break;
          case 3:
          break;
        }
    }
}
//---------------------------------------------------------------------------

