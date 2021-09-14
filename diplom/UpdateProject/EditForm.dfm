object EditSelect: TEditSelect
  Left = 317
  Top = 585
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077
  ClientHeight = 176
  ClientWidth = 329
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 136
    Top = 8
    Width = 25
    Height = 13
    Caption = #1048#1084#1103':'
  end
  object Label2: TLabel
    Left = 136
    Top = 56
    Width = 75
    Height = 13
    Caption = #1042#1099#1073#1086#1088' '#1080#1082#1086#1085#1082#1080':'
  end
  object Shape1: TShape
    Left = 8
    Top = 8
    Width = 120
    Height = 120
  end
  object Image: TImage
    Left = 8
    Top = 8
    Width = 120
    Height = 120
    Stretch = True
  end
  object Edit: TEdit
    Left = 136
    Top = 24
    Width = 185
    Height = 21
    TabOrder = 0
  end
  object ComboBox: TComboBox
    Left = 136
    Top = 72
    Width = 185
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 1
    OnChange = ComboBoxChange
  end
  object Panel1: TPanel
    Left = 8
    Top = 136
    Width = 321
    Height = 2
    TabOrder = 2
  end
  object bthExec: TButton
    Left = 128
    Top = 144
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 3
    OnClick = bthExecClick
  end
  object CheckWLAN: TCheckBox
    Left = 136
    Top = 104
    Width = 89
    Height = 17
    Caption = #1047#1072#1087#1088#1086#1089' WiFi'
    TabOrder = 4
    Visible = False
  end
  object CheckVPN: TCheckBox
    Left = 232
    Top = 104
    Width = 89
    Height = 17
    Caption = #1047#1072#1087#1088#1086#1089' VPN'
    TabOrder = 5
    Visible = False
  end
  object ODialog: TOpenPictureDialog
    Filter = 'Bitmaps (*.bmp)|*.bmp'
    Left = 8
    Top = 144
  end
end
