//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EditForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditSelect *EditSelect;
//---------------------------------------------------------------------------
__fastcall TEditSelect::TEditSelect(TComponent* Owner)
    : TForm(Owner), IQuery(SelectForm->IQuery), Query(SelectForm->Query),
    mem(new TMemoryStream)
{
    mem->Clear();
}
//---------------------------------------------------------------------------
AnsiString TEditSelect::GetFileName(AnsiString strPath)
{
    return ExtractFileName(strPath.Delete(strPath.AnsiPos('.'), strPath.Length() - strPath.AnsiPos('.') + 1));
}
//---------------------------------------------------------------------------
void __fastcall TEditSelect::ComboBoxChange(TObject *Sender)
{
    if(ComboBox->ItemIndex == (ComboBox->Items->Count-1))
    {
        if(ODialog->Execute())
        {
            Image->Picture->LoadFromFile(ODialog->FileName);
            Image->Picture->Graphic->SaveToStream(mem);
            if(!IQuery->Locate("Name",GetFileName(ODialog->FileName).UpperCase(), SelectForm->S))
            {
                if(MessageBox(NULL, "Хотите отметить изображение как системное?\nСистемное изображение не может применяться к профилям!", "Выбор типа изображения", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                    IQuery->SQL->Text = "INSERT INTO tImage(Name, System) VALUES ('"+GetFileName(ODialog->FileName).UpperCase()+"','1')";
                else
                    IQuery->SQL->Text = "INSERT INTO tImage(Name, System) VALUES ('"+GetFileName(ODialog->FileName).UpperCase()+"','0')";
                IQuery->ExecSQL();
            }
            IQuery->SQL->Text = "SELECT * FROM tImage WHERE Name='"+GetFileName(ODialog->FileName).UpperCase()+"'";
            IQuery->Active = true;
            IQuery->Edit();
            ((TGraphicField*)IQuery->FieldByName("Image"))->LoadFromStream(mem);
            IQuery->Post();
            mem->Clear();
            ReLoadBox();
            ComboBox->ItemIndex = ComboBox->Items->IndexOf(GetFileName(ODialog->FileName).UpperCase());
        }
        else
        {
            Image->Picture->Bitmap->FreeImage();
            Image->Picture->Bitmap = NULL;
            ComboBox->ItemIndex = -1;
        }
    }
    else
    {
        IQuery->Locate("Name", ComboBox->Items->Strings[ComboBox->ItemIndex], SelectForm->S);
        ((TGraphicField*)IQuery->FieldByName("Image"))->SaveToStream(mem);
        mem->Seek(0,0);
        Image->Picture->Bitmap->LoadFromStream(mem);
        mem->Clear();
    }
}
//---------------------------------------------------------------------------
void TEditSelect::ReLoadBox()
{
    IQuery->SQL->Text = "SELECT * FROM tImage";
    IQuery->Active = true;
    ComboBox->Clear();
    while(!IQuery->Eof)
    {
        if(!IQuery->FieldByName("System")->Value)
            ComboBox->Items->Add(IQuery->FieldByName("Name")->AsString);
        IQuery->Next();
    }
    ComboBox->Items->Add("Загрузить...");
}
//---------------------------------------------------------------------------
void __fastcall TEditSelect::FormDestroy(TObject *Sender)
{
    delete mem;
}
//---------------------------------------------------------------------------
void __fastcall TEditSelect::bthExecClick(TObject *Sender)
{
    switch(status)
    {
      case 0:   //Add Device
        Query->SQL->Text = "INSERT INTO tName(Label, DevCode, ImgCode, FormWiFi, FormVPN) VALUES ('"+Edit->Text+"','0','"+IQuery->FieldByName("Code")->AsInteger+"','0','0')";
        Query->ExecSQL();
      break;
      case 1:   //Edit Device
        IQuery->Locate("Name", ComboBox->Text, SelectForm->S);
        Query->SQL->Text = "UPDATE tName SET Label='"+Edit->Text+"', ImgCode="+IQuery->FieldByName("Code")->AsString+" WHERE Label='"+Query->FieldByName("Label")->AsString+"' AND DevCode=0";
        Query->ExecSQL();
      break;
      case 2:   //Add Config
        Query->SQL->Text = "INSERT INTO tName(Label, DevCode, ImgCode, FormWiFi, FormVPN) VALUES ('"+Edit->Text+"','"+AnsiString(SelectForm->GetDevice())+"','"+IQuery->FieldByName("Code")->AsInteger+"','"+((CheckWLAN->Checked)?'1':'0')+"','"+((CheckVPN->Checked)?'1':'0')+"')";
        Query->ExecSQL();
      break;
      case 3:   //Edit Config
        IQuery->Locate("Name", ComboBox->Text, SelectForm->S);
        Query->SQL->Text = "UPDATE tName SET Label='"+Edit->Text+"', ImgCode="+IQuery->FieldByName("Code")->AsString+", FormWiFi="+(CheckWLAN->Checked?'1':'0')+", FormVPN="+(CheckVPN->Checked?'1':'0')+" WHERE Label='"+Query->FieldByName("Label")->AsString+"' AND DevCode="+AnsiString(SelectForm->GetDevice());
        Query->ExecSQL();
      break;
    }
    Close();
}
//---------------------------------------------------------------------------

