object Form3: TForm3
  Left = 541
  Top = 322
  AlphaBlend = True
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsToolWindow
  Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1090#1077#1089#1090#1072
  ClientHeight = 205
  ClientWidth = 350
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Progr: TCGauge
    Left = 5
    Top = 8
    Width = 340
    Height = 17
    ForeColor = 43520
    BackColor = 70375
    MaxValue = 1
  end
  object Stat: TListView
    Left = 5
    Top = 32
    Width = 340
    Height = 129
    Color = clBtnFace
    Columns = <
      item
        Caption = 'Property'
        Width = 150
      end
      item
        AutoSize = True
        Caption = 'Value'
      end>
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    Items.Data = {
      0B0100000700000000000000FFFFFFFFFFFFFFFF01000000000000000BD2E5F1
      F2E8F0F3E5ECFBE9037C3D2900000000FFFFFFFFFFFFFFFF0000000000000000
      0000000000FFFFFFFFFFFFFFFF000000000000000012CFF0E8F7E8EDE020EEEA
      EEEDF7E0EDE8FF3A00000000FFFFFFFFFFFFFFFF000000000000000013CFF0E0
      E2E8EBFCEDFBF520EEF2E2E5F2EEE23A00000000FFFFFFFFFFFFFFFF00000000
      0000000015CDE5EFF0E0E2E8EBFCEDFBF520EEF2E2E5F2EEE23A00000000FFFF
      FFFFFFFFFFFF000000000000000013CFF0EEEFF3F9E5EDEE20E2EEEFF0EEF1EE
      E23A00000000FFFFFFFFFFFFFFFF000000000000000012C7E0F2F0E0F7E5EDEE
      20E2F0E5ECE5EDE83AFFFF}
    ReadOnly = True
    ParentFont = False
    ShowColumnHeaders = False
    TabOrder = 0
    ViewStyle = vsReport
  end
  object Again: TBitBtn
    Left = 64
    Top = 168
    Width = 89
    Height = 33
    Caption = #1055#1088#1086#1081#1090#1080' '#1079#1072#1085#1086#1074#1086
    TabOrder = 1
    OnClick = AgainClick
  end
  object Exit: TBitBtn
    Left = 200
    Top = 168
    Width = 89
    Height = 33
    Caption = #1042#1099#1081#1090#1080
    TabOrder = 2
    OnClick = ExitClick
  end
end
