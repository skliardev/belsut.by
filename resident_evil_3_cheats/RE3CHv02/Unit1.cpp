//---------------------------------------------------------------------------
// Вечные глюки в логике, если используем Edit[i]
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner), file("bu00.sav")
{
    ListBox1->Clear();
    Actor[0].Name = "Jill Valentine";
    Actor[0].Inventory.Offset   = 0x240C;
    Actor[0].ItemBox.Offset     = 0x2434;
    Actor[0].SidePack.Offset    = 0x2536;
    Actor[1].Name = "Carlos";
    Actor[1].Inventory.Offset   = 0x254C;
    Actor[1].ItemBox.Offset     = 0x2574;
    Actor[1].SidePack.Offset    = 0x2676;

    for(int i=0; i<=9; ++i)
    {
        Edit[i] = new TEdit(this);
        Edit[i]->Parent = this;
        Edit[i]->Width = 41;
        Edit[i]->Height = 21;
        Edit[i]->MaxLength = 3;
        Edit[i]->Left = 288;
        Edit[i]->Top = 48 + i*(Edit[i]->Height+3);
        Edit[i]->Enabled = false;
        if(i > 7) Edit[i]->Visible = false;
        Edit[i]->OnChange = Edit10Change;
        Edit[i]->OnKeyPress = Edit11KeyPress;
        Edit[i]->Tag = i;    
    }
    ComboBox1->Items->LoadFromFile("Items.lst");
    ComboBox2->Items->Text = ComboBox1->Items->Text;
    ComboBox3->Items->Text = ComboBox1->Items->Text;
    ComboBox4->Items->Text = ComboBox1->Items->Text;
    ComboBox5->Items->Text = ComboBox1->Items->Text;
    ComboBox6->Items->Text = ComboBox1->Items->Text;
    ComboBox7->Items->Text = ComboBox1->Items->Text;
    ComboBox8->Items->Text = ComboBox1->Items->Text;
    ComboBox9->Items->Text = ComboBox1->Items->Text;
    ComboBox10->Items->Text = ComboBox1->Items->Text;
    ComboBox11->Items->Text = ComboBox1->Items->Text;
}
//---------------------------------------------------------------------------
void TForm1::LoadCheckBox()
{
    //1
        if(Actor[selActor].Inventory.Slot[0].Attrib == 0x0F) CheckBox2->State = cbChecked;
        else if(Actor[selActor].Inventory.Slot[0].Attrib == 0x01) CheckBox2->State = cbGrayed;
        else CheckBox2->State = cbUnchecked;
        //2
        if(Actor[selActor].Inventory.Slot[1].Attrib == 0x0F) CheckBox3->State = cbChecked;
        else if(Actor[selActor].Inventory.Slot[1].Attrib == 0x01) CheckBox3->State = cbGrayed;
        else CheckBox3->State = cbUnchecked;
        //3
        if(Actor[selActor].Inventory.Slot[2].Attrib == 0x0F) CheckBox4->State = cbChecked;
        else if(Actor[selActor].Inventory.Slot[2].Attrib == 0x01) CheckBox4->State = cbGrayed;
        else CheckBox4->State = cbUnchecked;
        //4
        if(Actor[selActor].Inventory.Slot[3].Attrib == 0x0F) CheckBox5->State = cbChecked;
        else if(Actor[selActor].Inventory.Slot[3].Attrib == 0x01) CheckBox5->State = cbGrayed;
        else CheckBox5->State = cbUnchecked;
        //5
        if(Actor[selActor].Inventory.Slot[4].Attrib == 0x0F) CheckBox6->State = cbChecked;
        else if(Actor[selActor].Inventory.Slot[4].Attrib == 0x01) CheckBox6->State = cbGrayed;
        else CheckBox6->State = cbUnchecked;
        //6
        if(Actor[selActor].Inventory.Slot[5].Attrib == 0x0F) CheckBox7->State = cbChecked;
        else if(Actor[selActor].Inventory.Slot[5].Attrib == 0x01) CheckBox7->State = cbGrayed;
        else CheckBox7->State = cbUnchecked;
        //7
        if(Actor[selActor].Inventory.Slot[6].Attrib == 0x0F) CheckBox8->State = cbChecked;
        else if(Actor[selActor].Inventory.Slot[6].Attrib == 0x01) CheckBox8->State = cbGrayed;
        else CheckBox8->State = cbUnchecked;
        //8
        if(Actor[selActor].Inventory.Slot[7].Attrib == 0x0F) CheckBox9->State = cbChecked;
        else if(Actor[selActor].Inventory.Slot[7].Attrib == 0x01) CheckBox9->State = cbGrayed;
        else CheckBox9->State = cbUnchecked;
        //9
        if(Actor[selActor].Inventory.Slot[8].Attrib == 0x0F) CheckBox10->State = cbChecked;
        else if(Actor[selActor].Inventory.Slot[8].Attrib == 0x01) CheckBox10->State = cbGrayed;
        else CheckBox10->State = cbUnchecked;
        //10
        if(Actor[selActor].Inventory.Slot[9].Attrib == 0x0F) CheckBox11->State = cbChecked;
        else if(Actor[selActor].Inventory.Slot[9].Attrib == 0x01) CheckBox11->State = cbGrayed;
        else CheckBox11->State = cbUnchecked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
    selActor = ((TButton*)Sender)->Tag;
    if((fi = fopen(file.c_str(), "rb"))!=NULL)
    {
        fseek(fi,Actor[selActor].Inventory.Offset,SEEK_SET);
        fread(&Actor[selActor].Inventory.Slot,sizeof(unsigned char),40,fi);

        Label1->Caption = "Инвентарь " + Actor[selActor].Name;
        Label12->Caption = "Ящик " + Actor[selActor].Name;;
        ComboBox1->ItemIndex  = Actor[selActor].Inventory.Slot[0].ID;
        ComboBox2->ItemIndex  = Actor[selActor].Inventory.Slot[1].ID;
        ComboBox3->ItemIndex  = Actor[selActor].Inventory.Slot[2].ID;
        ComboBox4->ItemIndex  = Actor[selActor].Inventory.Slot[3].ID;
        ComboBox5->ItemIndex  = Actor[selActor].Inventory.Slot[4].ID;
        ComboBox6->ItemIndex  = Actor[selActor].Inventory.Slot[5].ID;
        ComboBox7->ItemIndex  = Actor[selActor].Inventory.Slot[6].ID;
        ComboBox8->ItemIndex  = Actor[selActor].Inventory.Slot[7].ID;
        ComboBox9->ItemIndex  = Actor[selActor].Inventory.Slot[8].ID;
        ComboBox10->ItemIndex = Actor[selActor].Inventory.Slot[9].ID;

        fseek(fi,Actor[selActor].ItemBox.Offset,SEEK_SET);
        fread(&Actor[selActor].ItemBox.Slot,sizeof(unsigned char),256,fi);

        ListBox1->Clear();
        for(short j = 0; j <= 63; ++j)
            ListBox1->Items->Add(IntToStr(j+1) + ": " + ComboBox11->Items->Strings[Actor[selActor].ItemBox.Slot[j].ID]);

        fseek(fi,Actor[selActor].SidePack.Offset,SEEK_SET);
        fread(&Actor[selActor].SidePack.State,sizeof(unsigned char),1,fi);

        CheckBox1->Checked = (Actor[selActor].SidePack.State == 0x0A)? true : false;
        if(CheckBox1->Checked)
        {
            Label10->Visible = true;
            ComboBox9->Visible = true;
            CheckBox10->Visible = true;
            Label11->Visible = true;
            ComboBox10->Visible = true;
            CheckBox11->Visible = true;
        }

        fclose(fi);

        LoadCheckBox();
        
        ComboBox1->Enabled = true;
        ComboBox2->Enabled = true;
        ComboBox3->Enabled = true;
        ComboBox4->Enabled = true;
        ComboBox5->Enabled = true;
        ComboBox6->Enabled = true;
        ComboBox7->Enabled = true;
        ComboBox8->Enabled = true;
        ComboBox9->Enabled = true;
        ComboBox10->Enabled = true;
        ComboBox11->Enabled = true;
        CheckBox1->Enabled = true;
        CheckBox2->Enabled = true;
        CheckBox3->Enabled = true;
        CheckBox4->Enabled = true;
        CheckBox5->Enabled = true;
        CheckBox6->Enabled = true;
        CheckBox7->Enabled = true;
        CheckBox8->Enabled = true;
        CheckBox9->Enabled = true;
        CheckBox10->Enabled = true;
        CheckBox11->Enabled = true;
        CheckBox12->Enabled = true;
        ListBox1->Enabled = true;
        Edit11->Enabled = true;

        for(int i=0; i<=9; ++i)
        {
            Edit[i]->Enabled = true;
            if((i > 7) && (CheckBox1->Checked)) Edit[i]->Visible = true;
            Edit[i]->Text = Actor[selActor].Inventory.Slot[i].Number;
        }
    }
    else
    {
        ComboBox1->Enabled = false;
        ComboBox2->Enabled = false;
        ComboBox3->Enabled = false;
        ComboBox4->Enabled = false;
        ComboBox5->Enabled = false;
        ComboBox6->Enabled = false;
        ComboBox7->Enabled = false;
        ComboBox8->Enabled = false;
        ComboBox9->Enabled = false;
        ComboBox10->Enabled = false;
        ComboBox11->Enabled = false;
        CheckBox1->Enabled = false;
        CheckBox2->Enabled = false;
        CheckBox3->Enabled = false;
        CheckBox4->Enabled = false;
        CheckBox5->Enabled = false;
        CheckBox6->Enabled = false;
        CheckBox7->Enabled = false;
        CheckBox8->Enabled = false;
        CheckBox9->Enabled = false;
        CheckBox10->Enabled = false;
        CheckBox11->Enabled = false;
        ListBox1->Enabled = false;
        CheckBox12->Enabled = false;
        Edit11->Enabled = false;
        for(int i=0; i<=9; ++i) Edit[i]->Enabled = false;
        ShowMessage("Не найден \'bu00.sav\' файл в папке с программой.");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
    Label10->Visible = ((TCheckBox*)Sender)->Checked;
    ComboBox9->Visible = Label10->Visible;
    CheckBox10->Visible = Label10->Visible;
    Label11->Visible = Label10->Visible;
    ComboBox10->Visible = Label10->Visible;
    CheckBox11->Visible = Label10->Visible;
    if((fi = fopen(file.c_str(), "rb+"))!=NULL)
    {
        if(Label10->Visible) Actor[selActor].SidePack.State = 0x0A;
        else Actor[selActor].SidePack.State = 0x08;
        fseek(fi,Actor[selActor].SidePack.Offset, SEEK_SET);
        fwrite(&Actor[selActor].SidePack.State,sizeof(unsigned char),1,fi);
    }
    else
    {
        ((TCheckBox*)Sender)->Checked = !((TCheckBox*)Sender)->Checked;
        ShowMessage("Не найден \'bu00.sav\' файл в папке с программой.");
    }
    fclose(fi);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
    TComboBox *ComboBox = ((TComboBox*)Sender);
    if((fi = fopen(file.c_str(), "rb+"))!= NULL)
    {

        if(ComboBox->ItemIndex != 0)
        {
            Actor[selActor].Inventory.Slot[ComboBox->Tag].ID = ComboBox->ItemIndex;
            Actor[selActor].Inventory.Slot[ComboBox->Tag].Number = 0x01;
            Actor[selActor].Inventory.Slot[ComboBox->Tag].Attrib = 0x00;
            Actor[selActor].Inventory.Slot[ComboBox->Tag].zByte = 0x00;
        }
        else
        {
            Actor[selActor].Inventory.Slot[ComboBox->Tag].ID = 0x00;
            Actor[selActor].Inventory.Slot[ComboBox->Tag].Number = 0x00;
            Actor[selActor].Inventory.Slot[ComboBox->Tag].Attrib = 0x00;
            Actor[selActor].Inventory.Slot[ComboBox->Tag].zByte = 0x00;
        }
        fseek(fi,Actor[selActor].Inventory.Offset + (ComboBox->Tag*4), SEEK_SET);
        fwrite(&Actor[selActor].Inventory.Slot[ComboBox->Tag],sizeof(char),4,fi);
    }
    else ShowMessage("Не найден \'bu00.sav\' файл в папке с программой.");
    fclose(fi);
    Edit[ComboBox->Tag]->Text = Actor[selActor].Inventory.Slot[ComboBox->Tag].Number;
    LoadCheckBox();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
    TCheckBox *CheckBox = ((TCheckBox*)Sender);
    if((fi = fopen(file.c_str(), "rb+"))!= NULL)
    {
        if(CheckBox->Checked) //Unlimited
        {
            CheckBox->Caption ="Бесконечно!";
            Actor[selActor].Inventory.Slot[CheckBox->Tag].Number = 0xFA;
            Actor[selActor].Inventory.Slot[CheckBox->Tag].Attrib = 0x0F;
        }
        else if(CheckBox->State == cbGrayed) //Limited
        {
            CheckBox->Caption ="Лимити-но!";
            Actor[selActor].Inventory.Slot[CheckBox->Tag].Attrib = 0x01;
        }
        else //For use only
        {
            CheckBox->Caption ="Предмет!";
            Actor[selActor].Inventory.Slot[CheckBox->Tag].Number = 0x01;
            Actor[selActor].Inventory.Slot[CheckBox->Tag].Attrib = 0x00;
        }
        fseek(fi,Actor[selActor].Inventory.Offset + (CheckBox->Tag*4), SEEK_SET);
        fwrite(&Actor[selActor].Inventory.Slot[CheckBox->Tag],sizeof(char),4,fi);
    }
    else ShowMessage("Не найден \'bu00.sav\' файл в папке с программой.");
    fclose(fi);
    Edit[CheckBox->Tag]->Text = Actor[selActor].Inventory.Slot[CheckBox->Tag].Number;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
   ComboBox11->ItemIndex = Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].ID;
   if(Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Attrib == 0x0F) CheckBox12->State = cbChecked;
   else if(Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Attrib == 0x01) CheckBox12->State = cbGrayed;
   else CheckBox12->State = cbUnchecked;
   Edit11->Text = Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Number;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox11Change(TObject *Sender)
{
    TComboBox *ComboBox = ((TComboBox*)Sender);
    if((fi = fopen(file.c_str(), "rb+"))!= NULL)
    {

        if(ComboBox->ItemIndex != 0)
        {
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].ID = ComboBox->ItemIndex;
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Number = 0x01;
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Attrib = 0x00;
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].zByte = 0x00;
        }
        else
        {
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].ID = 0x00;
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Number = 0x00;
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Attrib = 0x00;
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].zByte = 0x00;
        }
        fseek(fi,Actor[selActor].ItemBox.Offset + (ListBox1->ItemIndex*4), SEEK_SET);
        fwrite(&Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex],sizeof(char),4,fi);
    }
    else ShowMessage("Не найден \'bu00.sav\' файл в папке с программой.");
    fclose(fi);
    int sl = ListBox1->ItemIndex;
    ListBox1->Clear();
    for(short j = 0; j <= 63; ++j)
        ListBox1->Items->Add(IntToStr(j+1) + ": " + ComboBox11->Items->Strings[Actor[selActor].ItemBox.Slot[j].ID]);
    ListBox1->ItemIndex = sl;
    if(Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Attrib == 0x0F) CheckBox12->State = cbChecked;
    else if(Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Attrib == 0x01) CheckBox12->State = cbGrayed;
    else CheckBox12->State = cbUnchecked;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox12Click(TObject *Sender)
{
    TCheckBox *CheckBox = ((TCheckBox*)Sender);
    if((fi = fopen(file.c_str(), "rb+"))!= NULL)
    {
        if(CheckBox->Checked) //Unlimited
        {
            CheckBox->Caption ="Бесконечно!";
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Number = 0xFA;
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Attrib = 0x0F;
        }
        else if(CheckBox->State == cbGrayed) //Limited
        {
            CheckBox->Caption ="Лимити-но!";
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Attrib = 0x01;
        }
        else //For use only
        {
            CheckBox->Caption ="Предмет!";
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Number = 0x01;
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Attrib = 0x00;
        }

        fseek(fi,Actor[selActor].ItemBox.Offset + (ListBox1->ItemIndex*4), SEEK_SET);
        fwrite(&Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex],sizeof(char),4,fi);
    }
    else ShowMessage("Не найден \'bu00.sav\' файл в папке с программой.");
    fclose(fi);
    Edit11->Text = Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Number;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit10Change(TObject *Sender)
{
    TEdit *tEdit = ((TEdit*)Sender);
    if((Actor[selActor].Inventory.Slot[tEdit->Tag].ID > 0) && (tEdit->Text.Length())) //&& (Actor[selActor].Inventory.Slot[tEdit->Tag].Attrib == 0x01))
    {
        if((fi = fopen(file.c_str(), "rb+"))!= NULL)
        {
            Actor[selActor].Inventory.Slot[tEdit->Tag].Number = (unsigned char)tEdit->Text.ToInt();
            fseek(fi,Actor[selActor].Inventory.Offset + (tEdit->Tag*4) + 1, SEEK_SET);
            fwrite(&Actor[selActor].Inventory.Slot[tEdit->Tag].Number,sizeof(unsigned char),1,fi);
        }
        else ShowMessage("Не найден \'bu00.sav\' файл в папке с программой.");
        fclose(fi);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit11KeyPress(TObject *Sender, char &Key)
{
    TEdit *tEdit = ((TEdit*)Sender);
    int sum;
    if(Key == 8) return;
    if((Key >= '0') && (Key <= '9'))
    {
        if(tEdit->Text.Length() && (tEdit->Text.Length()!=3))
        {
            sum = tEdit->Text.ToInt()*10;
            if((sum + StrToInt(Key)) > 255)
                tEdit->Text = "255";
        }
    }
    else Key=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit11Change(TObject *Sender)
{
    if((ListBox1->ItemIndex > -1) && (Edit11->Text.Length()))
    {
        if((fi = fopen(file.c_str(), "rb+"))!= NULL)
        {
            Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Number = (unsigned char)Edit11->Text.ToInt();
            fseek(fi,Actor[selActor].ItemBox.Offset + (ListBox1->ItemIndex*4) + 1, SEEK_SET);
            fwrite(&Actor[selActor].ItemBox.Slot[ListBox1->ItemIndex].Number,sizeof(char),1,fi);
        }
        else ShowMessage("Не найден \'bu00.sav\' файл в папке с программой.");
        fclose(fi);
    }
}
//---------------------------------------------------------------------------


