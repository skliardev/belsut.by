object FormEdit: TFormEdit
  Left = 405
  Top = 206
  BorderStyle = bsToolWindow
  Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1074#1086#1087#1088#1086#1089#1072
  ClientHeight = 289
  ClientWidth = 688
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label: TLabel
    Left = 8
    Top = 114
    Width = 122
    Height = 15
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1074#1086#1087#1088#1086#1089#1086#1074':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object L1: TLabel
    Left = 8
    Top = 139
    Width = 11
    Height = 18
    Caption = '1)'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object L2: TLabel
    Left = 8
    Top = 160
    Width = 13
    Height = 18
    Caption = '2)'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object L3: TLabel
    Left = 8
    Top = 181
    Width = 13
    Height = 18
    Caption = '3)'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object L4: TLabel
    Left = 8
    Top = 202
    Width = 13
    Height = 18
    Caption = '4)'
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object L5: TLabel
    Left = 8
    Top = 223
    Width = 13
    Height = 18
    Caption = '5)'
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object L6: TLabel
    Left = 8
    Top = 244
    Width = 13
    Height = 18
    Caption = '6)'
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object L7: TLabel
    Left = 8
    Top = 265
    Width = 13
    Height = 18
    Caption = '7)'
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object Lb1: TLabel
    Left = 328
    Top = 139
    Width = 7
    Height = 18
    Caption = #1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object Lb2: TLabel
    Left = 328
    Top = 160
    Width = 7
    Height = 18
    Caption = #1073
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object Lb3: TLabel
    Left = 328
    Top = 181
    Width = 7
    Height = 18
    Caption = #1074
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object Lb4: TLabel
    Left = 328
    Top = 202
    Width = 6
    Height = 18
    Caption = #1075
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object Lb5: TLabel
    Left = 328
    Top = 223
    Width = 8
    Height = 18
    Caption = #1076
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object Lb6: TLabel
    Left = 328
    Top = 244
    Width = 7
    Height = 18
    Caption = #1077
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object Lb7: TLabel
    Left = 328
    Top = 265
    Width = 9
    Height = 18
    Caption = #1078
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object T1: TMemo
    Left = 8
    Top = 8
    Width = 673
    Height = 97
    Alignment = taCenter
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnKeyPress = T1KeyPress
  end
  object B1: TComboBox
    Left = 344
    Top = 139
    Width = 41
    Height = 21
    AutoComplete = False
    AutoDropDown = True
    ItemHeight = 13
    TabOrder = 1
    Text = ' - '
    OnChange = B1Change
    Items.Strings = (
      ' - '
      '1)'
      '2)'
      '3)'
      '4)'
      '5)'
      '6)'
      '7)')
  end
  object B2: TComboBox
    Left = 344
    Top = 160
    Width = 41
    Height = 21
    AutoComplete = False
    AutoDropDown = True
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 2
    Text = ' - '
    OnChange = B1Change
    Items.Strings = (
      ' - '
      '1)'
      '2)'
      '3)'
      '4)'
      '5)'
      '6)'
      '7)')
  end
  object B3: TComboBox
    Left = 344
    Top = 181
    Width = 41
    Height = 21
    AutoComplete = False
    AutoDropDown = True
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 3
    Text = ' - '
    OnChange = B1Change
    Items.Strings = (
      ' - '
      '1)'
      '2)'
      '3)'
      '4)'
      '5)'
      '6)'
      '7)')
  end
  object B4: TComboBox
    Left = 344
    Top = 202
    Width = 41
    Height = 21
    AutoComplete = False
    AutoDropDown = True
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 4
    Text = ' - '
    OnChange = B1Change
    Items.Strings = (
      ' - '
      '1)'
      '2)'
      '3)'
      '4)'
      '5)'
      '6)'
      '7)')
  end
  object B5: TComboBox
    Left = 344
    Top = 223
    Width = 41
    Height = 21
    AutoComplete = False
    AutoDropDown = True
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 5
    Text = ' - '
    OnChange = B1Change
    Items.Strings = (
      ' - '
      '1)'
      '2)'
      '3)'
      '4)'
      '5)'
      '6)'
      '7)')
  end
  object B6: TComboBox
    Left = 344
    Top = 244
    Width = 41
    Height = 21
    AutoComplete = False
    AutoDropDown = True
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 6
    Text = ' - '
    OnChange = B1Change
    Items.Strings = (
      ' - '
      '1)'
      '2)'
      '3)'
      '4)'
      '5)'
      '6)'
      '7)')
  end
  object B7: TComboBox
    Left = 344
    Top = 265
    Width = 41
    Height = 21
    AutoComplete = False
    AutoDropDown = True
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 7
    Text = ' - '
    OnChange = B1Change
    Items.Strings = (
      ' - '
      '1)'
      '2)'
      '3)'
      '4)'
      '5)'
      '6)'
      '7)')
  end
  object K: TCSpinEdit
    Left = 136
    Top = 112
    Width = 33
    Height = 22
    MaxValue = 7
    MinValue = 2
    TabOrder = 8
    Value = 3
    OnChange = KChange
    OnKeyPress = KKeyPress
  end
  object T3o: TEdit
    Left = 176
    Top = 112
    Width = 105
    Height = 21
    MaxLength = 50
    TabOrder = 9
    Visible = False
    OnKeyPress = T3oKeyPress
  end
  object Le1: TEdit
    Left = 24
    Top = 139
    Width = 300
    Height = 21
    TabOrder = 10
    OnKeyPress = Le1KeyPress
  end
  object Le2: TEdit
    Left = 24
    Top = 160
    Width = 300
    Height = 21
    TabOrder = 11
    OnKeyPress = Le1KeyPress
  end
  object Le4: TEdit
    Left = 24
    Top = 202
    Width = 300
    Height = 21
    Enabled = False
    TabOrder = 12
    OnKeyPress = Le1KeyPress
  end
  object Le3: TEdit
    Left = 24
    Top = 181
    Width = 300
    Height = 21
    TabOrder = 13
    OnKeyPress = Le1KeyPress
  end
  object Le6: TEdit
    Left = 24
    Top = 244
    Width = 300
    Height = 21
    Enabled = False
    TabOrder = 14
    OnKeyPress = Le1KeyPress
  end
  object Le5: TEdit
    Left = 24
    Top = 223
    Width = 300
    Height = 21
    Enabled = False
    TabOrder = 15
    OnKeyPress = Le1KeyPress
  end
  object Le7: TEdit
    Left = 24
    Top = 265
    Width = 300
    Height = 21
    Enabled = False
    TabOrder = 16
    OnKeyPress = Le1KeyPress
  end
  object Be1: TEdit
    Left = 392
    Top = 139
    Width = 290
    Height = 21
    TabOrder = 17
    OnKeyPress = Le1KeyPress
  end
  object Be2: TEdit
    Left = 392
    Top = 160
    Width = 290
    Height = 21
    TabOrder = 18
    OnKeyPress = Le1KeyPress
  end
  object Be3: TEdit
    Left = 392
    Top = 181
    Width = 290
    Height = 21
    TabOrder = 19
    OnKeyPress = Le1KeyPress
  end
  object Be4: TEdit
    Left = 392
    Top = 202
    Width = 290
    Height = 21
    Enabled = False
    TabOrder = 20
    OnKeyPress = Le1KeyPress
  end
  object Be5: TEdit
    Left = 392
    Top = 223
    Width = 290
    Height = 21
    Enabled = False
    TabOrder = 21
    OnKeyPress = Le1KeyPress
  end
  object Be6: TEdit
    Left = 392
    Top = 244
    Width = 290
    Height = 21
    Enabled = False
    TabOrder = 22
    OnKeyPress = Le1KeyPress
  end
  object Be7: TEdit
    Left = 392
    Top = 265
    Width = 290
    Height = 21
    Enabled = False
    TabOrder = 23
    OnKeyPress = Le1KeyPress
  end
end
