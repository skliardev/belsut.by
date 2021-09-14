object SelectForm: TSelectForm
  Left = 317
  Top = 156
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1057#1077#1088#1074#1080#1089#1043#1072#1088#1072#1085#1090' - 2014'
  ClientHeight = 365
  ClientWidth = 377
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object List: TListBox
    Left = 0
    Top = 0
    Width = 377
    Height = 365
    Style = lbOwnerDrawVariable
    Align = alClient
    ExtendedSelect = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = []
    IntegralHeight = True
    ItemHeight = 60
    ParentFont = False
    TabOrder = 0
    OnDblClick = ListDblClick
    OnDrawItem = ListDrawItem
    OnKeyDown = ListKeyDown
  end
  object MainMenu: TMainMenu
    Left = 328
    Top = 8
    object Mode: TMenuItem
      Caption = #1044#1086#1089#1090#1091#1087
      object GodMode: TMenuItem
        AutoCheck = True
        Caption = #1040#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1086#1088
        OnClick = GodModeClick
      end
    end
    object About: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      object Author: TMenuItem
        Caption = #1054#1073' '#1072#1074#1090#1086#1088#1077
        OnClick = AuthorClick
      end
    end
  end
  object IList: TImageList
    BlendColor = clWhite
    Height = 50
    ShareImages = True
    Width = 50
    Left = 296
    Top = 8
  end
  object Connect: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=data\base.mdb;Persi' +
      'st Security Info=False'
    LoginPrompt = False
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 328
    Top = 40
  end
  object Query: TADOQuery
    Connection = Connect
    Parameters = <>
    Left = 232
    Top = 40
  end
  object IQuery: TADOQuery
    Connection = Connect
    Parameters = <>
    Left = 264
    Top = 40
  end
end
