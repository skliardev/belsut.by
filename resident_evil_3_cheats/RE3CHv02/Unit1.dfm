object Form1: TForm1
  Left = 308
  Top = 202
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Resident Evil '
  ClientHeight = 330
  ClientWidth = 529
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 55
    Height = 13
    Caption = #1048#1085#1074#1077#1085#1090#1072#1088#1100
  end
  object Label2: TLabel
    Left = 8
    Top = 48
    Width = 33
    Height = 13
    Caption = #1057#1083#1086#1090' 1'
  end
  object Label3: TLabel
    Left = 8
    Top = 72
    Width = 33
    Height = 13
    Caption = #1057#1083#1086#1090' 2'
  end
  object Label4: TLabel
    Left = 8
    Top = 96
    Width = 33
    Height = 13
    Caption = #1057#1083#1086#1090' 3'
  end
  object Label5: TLabel
    Left = 8
    Top = 120
    Width = 33
    Height = 13
    Caption = #1057#1083#1086#1090' 4'
  end
  object Label6: TLabel
    Left = 8
    Top = 144
    Width = 33
    Height = 13
    Caption = #1057#1083#1086#1090' 5'
  end
  object Label7: TLabel
    Left = 8
    Top = 168
    Width = 33
    Height = 13
    Caption = #1057#1083#1086#1090' 6'
  end
  object Label8: TLabel
    Left = 8
    Top = 192
    Width = 33
    Height = 13
    Caption = #1057#1083#1086#1090' 7'
  end
  object Label9: TLabel
    Left = 8
    Top = 216
    Width = 33
    Height = 13
    Caption = #1057#1083#1086#1090' 8'
  end
  object Label10: TLabel
    Left = 8
    Top = 240
    Width = 33
    Height = 13
    Caption = #1057#1083#1086#1090' 9'
    Visible = False
  end
  object Label11: TLabel
    Left = 8
    Top = 264
    Width = 39
    Height = 13
    Caption = #1057#1083#1086#1090' 10'
    Visible = False
  end
  object Label12: TLabel
    Left = 344
    Top = 8
    Width = 29
    Height = 13
    Caption = #1071#1097#1080#1082
  end
  object Label13: TLabel
    Left = 288
    Top = 24
    Width = 34
    Height = 13
    Caption = #1050#1086#1083'-'#1074#1086
  end
  object ComboBox1: TComboBox
    Left = 56
    Top = 48
    Width = 120
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 0
    OnChange = ComboBox1Change
  end
  object ComboBox2: TComboBox
    Tag = 1
    Left = 56
    Top = 72
    Width = 120
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 1
    OnChange = ComboBox1Change
  end
  object ComboBox3: TComboBox
    Tag = 2
    Left = 56
    Top = 96
    Width = 120
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 2
    OnChange = ComboBox1Change
  end
  object ComboBox4: TComboBox
    Tag = 3
    Left = 56
    Top = 120
    Width = 120
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 3
    OnChange = ComboBox1Change
  end
  object ComboBox5: TComboBox
    Tag = 4
    Left = 56
    Top = 144
    Width = 120
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 4
    OnChange = ComboBox1Change
  end
  object ComboBox6: TComboBox
    Tag = 5
    Left = 56
    Top = 168
    Width = 120
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 5
    OnChange = ComboBox1Change
  end
  object ComboBox7: TComboBox
    Tag = 6
    Left = 56
    Top = 192
    Width = 120
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 6
    OnChange = ComboBox1Change
  end
  object ComboBox8: TComboBox
    Tag = 7
    Left = 56
    Top = 216
    Width = 120
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 7
    OnChange = ComboBox1Change
  end
  object ComboBox9: TComboBox
    Tag = 8
    Left = 56
    Top = 240
    Width = 120
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 8
    Visible = False
    OnChange = ComboBox1Change
  end
  object ComboBox10: TComboBox
    Tag = 9
    Left = 56
    Top = 264
    Width = 120
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 9
    Visible = False
    OnChange = ComboBox1Change
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 24
    Width = 273
    Height = 17
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' 9 '#1080' 10 '#1089#1083#1086#1090#1099
    Enabled = False
    TabOrder = 10
    OnClick = CheckBox1Click
  end
  object ListBox1: TListBox
    Left = 345
    Top = 24
    Width = 177
    Height = 217
    Enabled = False
    ItemHeight = 13
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '21'
      '22'
      '23'
      '24'
      '25'
      '26'
      '27'
      '28'
      '29'
      '30'
      '31'
      '32'
      '33'
      '34'
      '35'
      '36'
      '37'
      '38'
      '39'
      '40'
      '41'
      '42'
      '43'
      '44'
      '45'
      '46'
      '47'
      '48'
      '49'
      '50'
      '51'
      '52'
      '53'
      '54'
      '55'
      '56'
      '57'
      '58'
      '59'
      '60'
      '61'
      '62'
      '63'
      '64')
    TabOrder = 11
    OnClick = ListBox1Click
  end
  object ComboBox11: TComboBox
    Left = 345
    Top = 240
    Width = 177
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 12
    OnChange = ComboBox11Change
  end
  object CheckBox2: TCheckBox
    Left = 184
    Top = 48
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 13
    OnClick = CheckBox2Click
  end
  object CheckBox3: TCheckBox
    Tag = 1
    Left = 184
    Top = 72
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 14
    OnClick = CheckBox2Click
  end
  object CheckBox4: TCheckBox
    Tag = 2
    Left = 184
    Top = 96
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 15
    OnClick = CheckBox2Click
  end
  object CheckBox5: TCheckBox
    Tag = 3
    Left = 184
    Top = 120
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 16
    OnClick = CheckBox2Click
  end
  object CheckBox6: TCheckBox
    Tag = 4
    Left = 184
    Top = 144
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 17
    OnClick = CheckBox2Click
  end
  object CheckBox7: TCheckBox
    Tag = 5
    Left = 184
    Top = 168
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 18
    OnClick = CheckBox2Click
  end
  object CheckBox8: TCheckBox
    Tag = 6
    Left = 184
    Top = 192
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 19
    OnClick = CheckBox2Click
  end
  object CheckBox9: TCheckBox
    Tag = 7
    Left = 184
    Top = 216
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 20
    OnClick = CheckBox2Click
  end
  object CheckBox10: TCheckBox
    Tag = 8
    Left = 184
    Top = 240
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 21
    Visible = False
    OnClick = CheckBox2Click
  end
  object CheckBox11: TCheckBox
    Tag = 9
    Left = 184
    Top = 264
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 22
    Visible = False
    OnClick = CheckBox2Click
  end
  object CheckBox12: TCheckBox
    Left = 344
    Top = 272
    Width = 97
    Height = 17
    AllowGrayed = True
    Caption = #1055#1088#1077#1076#1084#1077#1090
    Enabled = False
    TabOrder = 23
    OnClick = CheckBox12Click
  end
  object Button1: TButton
    Left = 16
    Top = 296
    Width = 105
    Height = 25
    Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' Jill'
    TabOrder = 24
    OnClick = N1Click
  end
  object Button2: TButton
    Tag = 1
    Left = 128
    Top = 296
    Width = 105
    Height = 25
    Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' Carlos'
    TabOrder = 25
    OnClick = N1Click
  end
  object Edit11: TEdit
    Left = 480
    Top = 264
    Width = 41
    Height = 21
    Enabled = False
    MaxLength = 3
    TabOrder = 26
    OnChange = Edit11Change
    OnKeyPress = Edit11KeyPress
  end
end
