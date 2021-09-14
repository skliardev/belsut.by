//---------------------------------------------------------------------------

#include <vcl.h>
#include <inifiles.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma resource "*.dfm"
#define PUT ExtractFilePath(ParamStr(0))+"test.ft"
TForm1 *Form1;
__int8 h=0,m=0,s=0;/*Переменные для таймера отсчета времени*/
__int8 KOLV=0,KOLV1=0/*Кол-во оставшихся вопросов*/,vopr=0;/*Номер текущего вопроса*/
__int8 rnd[255]/*Массив для рандома вопросов*/,rnd1[255];/*Для пропущенных; Кол-во == KOLV1 */
__int8 vopr_ndx=0,/*Индекс текущей ячейки*/ans[8][2];/*Массив для сравнения ответов*/
__int8 draw[8]={0};
//Переменные для статистики
__int8 kolv=0/*Задано вопросов*/,vKOLV=0;/*Всего вопросов*/
__int8 skip=0/*Пропущено*/,error=0/*Неправильно*/;// + kolv, vKOLV
TIniFile* ini=new TIniFile(PUT);

//Multistring
//SetWindowLong(a->Handle,GWL_STYLE,GetWindowLong(a->Handle,GWL_STYLE)|BS_MULTILINE);

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClearValues()
{
__int8 i;
KOLV=StrToInt(ini->ReadString("Info","K",""));
KOLV1=0;
vKOLV=KOLV;
Progr->Progress=0;
Progr->MaxValue=1;
kolv=0;
skip=0;
error=0;
Stat->Caption=IntToStr(Progr->Progress)+" / "+IntToStr(vKOLV);
for(i=0; i<KOLV-1; i++) rnd[i]=0;
//Next->Glyph=0;
IconList->GetBitmap(0,Next->Glyph);
Abort->Caption="Прервать"+AnsiString((char)13)+"тест";
Next->Caption="Пропустить"+AnsiString((char)13)+"вопрос";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ProgressBarRepaint()
{
__int8 value;
value=Progr->Progress*100/Progr->MaxValue;
if (value<=50)
{
 value=(510*value)/100;
 Progr->ForeColor=RGB(255,value,0);
}
else
{
 value=(int)(255-(510*value/100-255));
 Progr->ForeColor=RGB(value,255,0);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GetUserName()
{
Form2->ShowModal();
if (Form1->Timer->Enabled != true) Form1->Close();
else
{
if (Form2->NEdit->Text != "") ini->WriteString("Info","LastUser",Form2->NEdit->Text);
Form1->AlphaBlendValue=255;

TestStart(Form1);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TestStart(TObject *Sender)
{
TimeLabel->Caption="0:0:0";
ClearValues();
h=0;
m=0;
s=0;
Form1->AlphaBlendValue=255;
Abort->Enabled=true;
NextClick(Form1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
if (ini->ReadString("Info","LastUser","")!="") Form2->NEdit->Text=ini->ReadString("Info","LastUser","");
GetUserName();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
   Resize=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerTimer(TObject *Sender)
{
   Timer->Enabled=false;
   if (s < 60) s++;
   else
   {
      s=0;
      if (m < 60) m++;
      else
      {
         m=0;
         h++;
      }
   }
   TimeLabel->Caption=IntToStr(h)+":"+IntToStr(m)+":"+IntToStr(s);
   Timer->Enabled=true;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
ClearValues();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Func_CheckForEnd()
{
if (KOLV==0)
    if(KOLV1==0)
    {
        Form3->Stat->Items->Item[2]->SubItems->Clear();
        Form3->Stat->Items->Item[2]->SubItems->Add("Тест окончен");
        Next->Caption="Закончить"+AnsiString((char)13)+"тест";
        Next->Glyph=0;
        IconList->GetBitmap(4,Next->Glyph);
        Next->OnClick=EndClick;
        Abort->Enabled=false;
    }
    else
    {
        KOLV=KOLV1;
        for(int i=0;i<KOLV1;i++)
        {
            rnd[i]=rnd1[i];
            //ShowMessage("rnd1["+IntToStr(i)+"] = "+IntToStr(rnd1[i]));
            rnd1[i]=0;
        }
        KOLV1=0;

        Next->Caption="Пропустить"+AnsiString((char)13)+"вопрос";
        Next->OnClick=SkipClick;
        Next->Glyph=0;
        IconList->GetBitmap(0,Next->Glyph);
    }
else
{
        Next->Caption="Пропустить"+AnsiString((char)13)+"вопрос";
        Next->OnClick=SkipClick;
        Next->Glyph=0;
        IconList->GetBitmap(0,Next->Glyph);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NextClick(TObject *Sender)
{
__int8 i=0,itmp,akolv;
bool rep=0;

Memo->Clear();
List->Clear();
List->Enabled=true;
List2->Clear();

AnsiString answ;

//Рандом
do
{
    rep=0;
    randomize();
    vopr_ndx=random(KOLV);
    if(rnd[vopr_ndx]==0)
        if(vopr==vopr_ndx+1) rep=1;
        else vopr=vopr_ndx+1;
    else
        if(vopr==rnd[vopr_ndx]) rep=1;
        else vopr=rnd[vopr_ndx];
}
while(rep==1 && KOLV>1);
//______

akolv=StrToInt(ini->ReadString(IntToStr(vopr),"K",""));
Memo->Lines->Strings[0]=ini->ReadString(IntToStr(vopr),"Q","");
for (i=0;i<akolv;i++)
{
        List->Items->Add();
        List->Items->Item[List->Items->Count-1]->Caption=ini->ReadString(IntToStr(vopr),"Q"+IntToStr(i+1),"");
}
for (i=0;i<akolv;i++) List2->Items->Add(ini->ReadString(IntToStr(vopr),"A"+IntToStr(i+1),""));
answ=Code(ini->ReadString(IntToStr(vopr),"A","").c_str());
for (i=0;i<akolv;i++) ans[i][1]=StrToInt(answ[i+1]);//ini->ReadString(IntToStr(vopr),"A","")[i+1]);
/////////////////////////////////////////////////Вот здесь расшифровка ответа...

//Индикатор ответов
Edit2->Text="";
for (i=0;i<akolv;i++) Edit2->Text=Edit2->Text+IntToStr(ans[i][1]);
//_________________

/*//Практичный Resize колонок
akolv=0;
itmp=0;
for (i=0;i<List->Items->Count;i++)
        if (akolv<List->Items->Item[i]->Caption.Length())
                akolv=List->Items->Item[i]->Caption.Length();
for (i=0;i<List2->Items->Count;i++)
        if (akolv<List2->Items->Strings[i].Length())
                itmp=List2->Items->Strings[i].Length();
List->Columns->Items[0]->Width=(List->Width*akolv)/itmp;
List->Columns->Items[1]->Width=List->Width-List->Columns->Items[0]->Width;
//_________________________
*/

kolv++;
//Stat->Caption=IntToStr(Progr->Progress)+" / "+IntToStr(vKOLV);//+" = "+IntToStr((int)((float)right/vKOLV*100))+"%";
Func_CheckForEnd();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::List2Click(TObject *Sender)
{
if ((List->ItemIndex!=-1)&&(List->Items->Item[List->ItemIndex]->SubItems->Count==0))
        {
        ans[(unsigned char)List2->Items->Strings[List2->ItemIndex][1]-224][0]=List->ItemIndex+1;
        List->Items->Item[List->ItemIndex]->SubItems->Add(List2->Items->Strings[List2->ItemIndex]);
        List2->Items->Delete(List2->ItemIndex);
        if (List2->Items->Count==0)
                {
                Next->Glyph=0;
                IconList->GetBitmap(1,Next->Glyph);
                Next->Caption="Проверить"+AnsiString((char)13)+"ответ";
                Next->OnClick=CheckClick;
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EndClick(TObject *Sender)
{
Timer->Enabled=false;

List->ItemIndex=-1;
List->Enabled=false;
List2->Enabled=false;

Progr->MaxValue++;
if (kolv==1) Progr->MaxValue--;

if (KOLV=1) //Если ответ был непроверен и пропущен, то...
{
        rnd1[KOLV1]=vopr;
        if(rnd[KOLV-1]==0) rnd[vopr_ndx]=KOLV;
        else rnd[vopr_ndx]=rnd[KOLV-1];
        KOLV--;
        KOLV1++;
        skip++;
        //Progr->MaxValue++;
}

Form1->AlphaBlendValue=0;
Form3->Again->Caption="Пройти"+AnsiString((char)13)+"заново";

Form3->Progr->Progress=Progr->Progress;
Form3->Progr->MaxValue=Progr->MaxValue;
//Form3->Progr->ForeColor=Progr->ForeColor;

//Передача параметров форме с результатом
//Изменять Form3->Status->Items->Item[n]->SubItems не нужно
Form3->Stat->Items->Item[0]->SubItems->Clear();
Form3->Stat->Items->Item[0]->SubItems->Add(Form2->NEdit->Text);
Form3->Stat->Items->Item[3]->SubItems->Clear();
Form3->Stat->Items->Item[3]->SubItems->Add(IntToStr(Progr->Progress));
Form3->Stat->Items->Item[4]->SubItems->Clear();
Form3->Stat->Items->Item[4]->SubItems->Add(IntToStr(error));
Form3->Stat->Items->Item[5]->SubItems->Clear();
Form3->Stat->Items->Item[5]->SubItems->Add(IntToStr(skip));
Form3->Stat->Items->Item[6]->SubItems->Clear();
Form3->Stat->Items->Item[6]->SubItems->Add(TimeLabel->Caption);

Form3->ShowModal();
if (Form1->Timer->Enabled != true) Form1->Close();
else
{
        TestStart(Form3);
        Timer->Enabled=false;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckClick(TObject *Sender)//Проверка правильности
{
__int8 i;
bool righ=false;

List->ItemIndex=-1;
List->Enabled=false;
List2->Enabled=false;

Progr->MaxValue++;
if (kolv==1) Progr->MaxValue--;

for (i=0;i<List->Items->Count;i++) if (ans[i][0]!=ans[i][1]) righ=true;
else draw[ans[i][1]-1]=1;

List->Repaint();
if (righ==false) //Если ответ правильный, то...
{
        if(rnd[KOLV-1]==0) rnd[vopr_ndx]=KOLV;
        else rnd[vopr_ndx]=rnd[KOLV-1];
        Progr->Progress++;
        Next->Glyph=0;
        Stat->Caption=IntToStr(Progr->Progress)+" / "+IntToStr(vKOLV);
        IconList->GetBitmap(2,Next->Glyph);
}
else //...значит все-таки неправильный...
{
        rnd1[KOLV1]=vopr;
        if(rnd[KOLV-1]==0) rnd[vopr_ndx]=KOLV;
        else rnd[vopr_ndx]=rnd[KOLV-1];
        error++;
        KOLV1++;
        Next->Glyph=0;
        IconList->GetBitmap(3,Next->Glyph);
}
KOLV--;
ProgressBarRepaint();
for (i=0;i<List->Items->Count;i++) ans[i][0]=0;

if (KOLV==0)
    if(KOLV1==0)
    {
        Form3->Stat->Items->Item[2]->SubItems->Clear();
        Form3->Stat->Items->Item[2]->SubItems->Add("Тест окончен");
        Next->Caption="Закончить"+AnsiString((char)13)+"тест";
        Next->OnClick=EndClick;
    }
    else
    {
        KOLV=KOLV1;
        for(int i=0;i<KOLV1;i++)
        {
            rnd[i]=rnd1[i];
            //ShowMessage("rnd1["+IntToStr(i)+"] = "+IntToStr(rnd1[i]));
            rnd1[i]=0;
        }
        KOLV1=0;
        Next->Caption="Следующий"+AnsiString((char)13)+"вопрос";
        Next->OnClick=NextClick;
    }
else
{
        Next->Caption="Следующий"+AnsiString((char)13)+"вопрос";
        Next->OnClick=NextClick;
}
for(i=0;i<8;i++)draw[i]=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SkipClick(TObject *Sender)//Пропустить вопрос
                                                  //Записывает вопрос во 2-ой
                                                  //массив, удаляя из первого
{
rnd1[KOLV1]=vopr;
if(rnd[KOLV-1]==0) rnd[vopr_ndx]=KOLV;
else rnd[vopr_ndx]=rnd[KOLV-1];
KOLV--;
KOLV1++;
skip++;
//Progr->MaxValue++;
NextClick(Form1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if (List->GetItemAt(X,Y)!=0)
        {
        //---//ShowMessage(List->GetItemAt(X,Y)->Caption);
        List2->Enabled=true;
        List2->ItemIndex=-1;
        if (List->GetItemAt(X,Y)->SubItems->Count==1)
                {
                List2->Items->Add(List->GetItemAt(X,Y)->SubItems->Strings[0]);
                ans[(unsigned char)List->GetItemAt(X,Y)->SubItems->Strings[0][1]-224][0]=0;
                List->GetItemAt(X,Y)->SubItems->Delete(0);
                Func_CheckForEnd();
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AbortClick(TObject *Sender)
{
Form3->Stat->Items->Item[2]->SubItems->Clear();
Form3->Stat->Items->Item[2]->SubItems->Add("Прервано пользователем");
//ShowMessage(IntToStr(Form3->Stat->Items->Count));
EndClick(Form1);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ListCustomDrawItem(TCustomListView *Sender,
      TListItem *Item, TCustomDrawState State, bool &DefaultDraw)
{
 if(draw[Item->Index]==1) List->Canvas->Brush->Color = clLime;
 else List->Canvas->Brush->Color = clWhite;
}
//---------------------------------------------------------------------------

