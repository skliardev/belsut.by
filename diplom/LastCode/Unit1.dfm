object Form1: TForm1
  Left = 274
  Top = 124
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1057#1086#1077#1076#1080#1085#1077#1085#1080#1077
  ClientHeight = 265
  ClientWidth = 327
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 327
    Height = 265
    ActivePage = TabSheet1
    Align = alClient
    Style = tsButtons
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1057#1086#1077#1076#1080#1085#1077#1085#1080#1077
      TabVisible = False
      object Label1: TLabel
        Left = 40
        Top = 64
        Width = 69
        Height = 13
        Caption = #1059#1089#1090#1088#1086#1081#1089#1090#1074#1086' : '
      end
      object Label2: TLabel
        Left = 40
        Top = 88
        Width = 52
        Height = 13
        Caption = 'IP '#1072#1076#1088#1077#1089' : '
      end
      object Label3: TLabel
        Left = 40
        Top = 128
        Width = 40
        Height = 13
        Caption = #1051#1086#1075#1080#1085' : '
      end
      object Label4: TLabel
        Left = 40
        Top = 152
        Width = 47
        Height = 13
        Caption = #1055#1072#1088#1086#1083#1100' : '
      end
      object ComboBox1: TComboBox
        Left = 112
        Top = 64
        Width = 145
        Height = 21
        BevelKind = bkSoft
        Style = csDropDownList
        Color = clBtnFace
        Ctl3D = True
        Enabled = False
        ItemHeight = 13
        ParentCtl3D = False
        TabOrder = 1
        OnClick = ComboBox1Click
        Items.Strings = (
          '('#1085#1077#1090')')
      end
      object Edit1: TEdit
        Left = 112
        Top = 88
        Width = 121
        Height = 19
        Color = clBtnFace
        Ctl3D = False
        Enabled = False
        ParentCtl3D = False
        TabOrder = 2
        Text = '192.168.0.1'
      end
      object Edit2: TEdit
        Left = 112
        Top = 128
        Width = 121
        Height = 19
        Color = clBtnFace
        Ctl3D = False
        Enabled = False
        ParentCtl3D = False
        TabOrder = 3
        Text = 'admin'
      end
      object Edit3: TEdit
        Left = 112
        Top = 152
        Width = 121
        Height = 19
        Color = clBtnFace
        Ctl3D = False
        Enabled = False
        ParentCtl3D = False
        TabOrder = 4
        Text = 'admin'
      end
      object Button1: TButton
        Left = 240
        Top = 224
        Width = 75
        Height = 25
        Caption = #1044#1072#1083#1077#1077
        Enabled = False
        TabOrder = 5
        OnClick = Button1Click
      end
      object CheckBox1: TCheckBox
        Left = 40
        Top = 24
        Width = 113
        Height = 17
        Caption = #1040#1074#1090#1086#1086#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077
        Checked = True
        State = cbChecked
        TabOrder = 0
        OnClick = CheckBox1Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1051#1080#1095'. '#1076#1072#1085#1085#1099#1077
      ImageIndex = 1
      TabVisible = False
      object Label5: TLabel
        Left = 56
        Top = 32
        Width = 40
        Height = 13
        Caption = #1051#1086#1075#1080#1085' : '
      end
      object Label6: TLabel
        Left = 56
        Top = 56
        Width = 47
        Height = 13
        Caption = #1055#1072#1088#1086#1083#1100' : '
      end
      object Label7: TLabel
        Left = 56
        Top = 88
        Width = 46
        Height = 13
        Caption = #1057#1077#1088#1074#1077#1088' : '
      end
      object Label8: TLabel
        Left = 56
        Top = 120
        Width = 31
        Height = 13
        Caption = #1048#1084#1103' : '
      end
      object Label9: TLabel
        Left = 56
        Top = 144
        Width = 47
        Height = 13
        Caption = #1055#1072#1088#1086#1083#1100' : '
      end
      object Label14: TLabel
        Left = 8
        Top = 0
        Width = 112
        Height = 13
        Caption = #1051#1080#1095#1085#1099#1077' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label42: TLabel
        Left = 8
        Top = 132
        Width = 21
        Height = 13
        Caption = 'WiFi'
      end
      object Label43: TLabel
        Left = 8
        Top = 38
        Width = 28
        Height = 26
        Caption = #1050#1072#1073'. (VPN)'
        WordWrap = True
      end
      object Button2: TButton
        Left = 240
        Top = 224
        Width = 75
        Height = 25
        Caption = #1044#1072#1083#1077#1077
        Enabled = False
        TabOrder = 7
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 8
        Top = 224
        Width = 75
        Height = 25
        Caption = #1053#1072#1079#1072#1076
        TabOrder = 8
        OnClick = Button3Click
      end
      object Edit5: TEdit
        Left = 112
        Top = 56
        Width = 129
        Height = 19
        BevelInner = bvNone
        BevelOuter = bvNone
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 1
        OnChange = ComboBox2Change
      end
      object ComboBox2: TComboBox
        Left = 112
        Top = 32
        Width = 145
        Height = 21
        BevelKind = bkSoft
        Style = csSimple
        Ctl3D = False
        ItemHeight = 13
        ParentCtl3D = False
        TabOrder = 0
        OnChange = ComboBox2Change
      end
      object ComboBox3: TComboBox
        Left = 112
        Top = 88
        Width = 145
        Height = 21
        BevelKind = bkSoft
        Style = csDropDownList
        Ctl3D = False
        ItemHeight = 13
        ItemIndex = 0
        ParentCtl3D = False
        TabOrder = 2
        Text = '('#1085#1077#1090')'
        Items.Strings = (
          '('#1085#1077#1090')'
          'unlim.vpn'
          'vpn.vpn')
      end
      object Edit4: TEdit
        Left = 112
        Top = 120
        Width = 129
        Height = 19
        BevelInner = bvNone
        BevelOuter = bvNone
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 3
        Text = 'garantwf'
        OnChange = ComboBox2Change
      end
      object Edit6: TEdit
        Left = 112
        Top = 144
        Width = 129
        Height = 19
        BevelInner = bvNone
        BevelOuter = bvNone
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 4
        OnChange = ComboBox2Change
      end
      object CheckBox2: TCheckBox
        Left = 112
        Top = 168
        Width = 81
        Height = 17
        Caption = #1050#1086#1084#1092#1086#1088#1090' '#1058#1042
        TabOrder = 5
      end
      object CheckBox3: TCheckBox
        Left = 112
        Top = 184
        Width = 121
        Height = 17
        Caption = #1050#1083#1072#1085#1080#1088#1086#1074#1072#1085#1080#1077' MAC'
        TabOrder = 6
      end
      object Button7: TButton
        Left = 136
        Top = 224
        Width = 57
        Height = 25
        Caption = #1056#1072#1085#1076#1086#1084
        TabOrder = 9
        OnClick = Button7Click
      end
      object Panel1: TPanel
        Left = 45
        Top = 120
        Width = 2
        Height = 41
        TabOrder = 10
      end
      object Panel2: TPanel
        Left = 45
        Top = 32
        Width = 2
        Height = 41
        TabOrder = 11
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1056#1077#1079#1077#1088#1074#1072#1094#1080#1103
      ImageIndex = 2
      TabVisible = False
      object Label10: TLabel
        Left = 56
        Top = 72
        Width = 19
        Height = 13
        Caption = 'IP : '
      end
      object Label11: TLabel
        Left = 56
        Top = 96
        Width = 34
        Height = 13
        Caption = #1055#1086#1088#1090' : '
      end
      object Label13: TLabel
        Left = 56
        Top = 120
        Width = 32
        Height = 13
        Caption = 'MAC : '
      end
      object Label12: TLabel
        Left = 8
        Top = 0
        Width = 297
        Height = 13
        Caption = #1056#1077#1079#1077#1088#1074#1080#1088#1086#1074#1072#1085#1080#1077' '#1072#1076#1088#1077#1089#1072' '#1080' '#1087#1077#1088#1077#1072#1076#1088#1077#1089#1072#1094#1080#1103' '#1087#1086#1088#1090#1086#1074
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Edit7: TEdit
        Left = 112
        Top = 72
        Width = 129
        Height = 19
        BevelInner = bvNone
        BevelOuter = bvNone
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 0
        Text = '192.168.0.100'
        OnChange = Edit7Change
      end
      object Button4: TButton
        Left = 240
        Top = 224
        Width = 75
        Height = 25
        Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100
        Enabled = False
        TabOrder = 5
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 8
        Top = 224
        Width = 75
        Height = 25
        Caption = #1053#1072#1079#1072#1076
        TabOrder = 3
        OnClick = Button5Click
      end
      object Edit10: TEdit
        Left = 112
        Top = 96
        Width = 129
        Height = 19
        BevelInner = bvNone
        BevelOuter = bvNone
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 1
        Text = '11111'
        OnChange = Edit7Change
      end
      object ComboBox4: TComboBox
        Left = 112
        Top = 120
        Width = 145
        Height = 21
        BevelKind = bkSoft
        Style = csDropDownList
        Ctl3D = False
        ItemHeight = 13
        ParentCtl3D = False
        TabOrder = 2
        OnChange = Edit7Change
      end
      object Button8: TButton
        Left = 136
        Top = 224
        Width = 57
        Height = 25
        Caption = #1054#1073#1085#1086#1074#1080#1090#1100
        TabOrder = 4
        OnClick = Button8Click
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1042#1099#1087#1086#1083#1085#1077#1085#1080#1077
      ImageIndex = 3
      TabVisible = False
      object Label15: TLabel
        Left = 8
        Top = 0
        Width = 158
        Height = 13
        Caption = #1061#1086#1076' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103' '#1085#1072#1089#1090#1088#1086#1077#1082
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label16: TLabel
        Left = 40
        Top = 24
        Width = 80
        Height = 13
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' QSS'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label17: TLabel
        Left = 40
        Top = 40
        Width = 46
        Height = 13
        Caption = #1048#1084#1103' WiFi'
      end
      object Label18: TLabel
        Left = 40
        Top = 56
        Width = 63
        Height = 13
        Caption = #1047#1072#1097#1080#1090#1072' WiFi'
      end
      object Label19: TLabel
        Left = 40
        Top = 72
        Width = 99
        Height = 13
        Caption = #1050#1083#1086#1085#1080#1088#1086#1074#1072#1085#1080#1077' MAC'
      end
      object Label20: TLabel
        Left = 40
        Top = 88
        Width = 143
        Height = 13
        Caption = #1056#1077#1079#1077#1088#1074#1080#1088#1086#1074#1072#1085#1080#1077' IP - '#1072#1076#1088#1077#1089#1072
      end
      object Label21: TLabel
        Left = 40
        Top = 104
        Width = 118
        Height = 13
        Caption = #1055#1077#1088#1077#1072#1076#1088#1077#1089#1072#1094#1080#1103' '#1087#1086#1088#1090#1086#1074
      end
      object Label22: TLabel
        Left = 40
        Top = 120
        Width = 80
        Height = 13
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' VPN'
      end
      object Label23: TLabel
        Left = 40
        Top = 136
        Width = 82
        Height = 13
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' IPTV'
      end
      object Label24: TLabel
        Left = 40
        Top = 152
        Width = 72
        Height = 13
        Caption = #1055#1077#1088#1077#1079#1072#1075#1088#1091#1079#1082#1072
      end
      object Label26: TLabel
        Left = 40
        Top = 168
        Width = 133
        Height = 13
        Caption = #1057#1086#1077#1076#1080#1085#1077#1085#1080#1077' '#1089' '#1080#1085#1090#1077#1088#1085#1077#1090#1086#1084
      end
      object Label27: TLabel
        Left = 40
        Top = 184
        Width = 82
        Height = 13
        Caption = #1047#1072#1087#1091#1089#1082' script.bat'
      end
      object Label28: TLabel
        Left = 24
        Top = 24
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label29: TLabel
        Left = 24
        Top = 40
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label30: TLabel
        Left = 24
        Top = 56
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label31: TLabel
        Left = 24
        Top = 72
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label32: TLabel
        Left = 24
        Top = 88
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label33: TLabel
        Left = 24
        Top = 104
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label34: TLabel
        Left = 24
        Top = 120
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label35: TLabel
        Left = 24
        Top = 136
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label36: TLabel
        Left = 24
        Top = 152
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label38: TLabel
        Left = 24
        Top = 168
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label39: TLabel
        Left = 24
        Top = 184
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label40: TLabel
        Left = 24
        Top = 200
        Width = 6
        Height = 13
        Caption = '0'
      end
      object Label41: TLabel
        Left = 40
        Top = 200
        Width = 63
        Height = 13
        Caption = #1047#1072#1074#1077#1088#1096#1077#1085#1085#1086
      end
      object Label25: TLabel
        Left = 152
        Top = 72
        Width = 3
        Height = 13
      end
      object Button6: TButton
        Left = 240
        Top = 224
        Width = 75
        Height = 25
        Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100
        Enabled = False
        TabOrder = 0
        OnClick = Button6Click
      end
    end
  end
  object IdBase64Encoder1: TIdBase64Encoder
    Left = 296
    Top = 136
  end
  object IcmpClient: TIdIcmpClient
    OnReply = IcmpClientReply
    Left = 296
    Top = 104
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctBlocking
    Port = 0
    Left = 296
    Top = 40
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=dbase.mdb;Persist S' +
      'ecurity Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 296
    Top = 72
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 296
    Top = 192
  end
end
