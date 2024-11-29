object AddComputerForm: TAddComputerForm
  Left = 0
  Top = 0
  Caption = 'AddComputer'
  ClientHeight = 231
  ClientWidth = 369
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 55
    Top = 69
    Width = 35
    Height = 15
    Caption = 'Name:'
  end
  object Label2: TLabel
    Left = 32
    Top = 107
    Width = 58
    Height = 15
    Caption = 'IP Address:'
  end
  object Label3: TLabel
    Left = 8
    Top = 16
    Width = 342
    Height = 15
    Caption = 'Please enter the IP Address of the computer you want to connect'
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 32
    Width = 144
    Height = 15
    Caption = 'And how you gonna call it?'
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object EditIpAddress: TEdit
    Left = 116
    Top = 104
    Width = 173
    Height = 23
    TabOrder = 0
    Text = 'Ex: 10.2.2.5'
  end
  object EditName: TEdit
    Left = 116
    Top = 66
    Width = 173
    Height = 23
    TabOrder = 1
    Text = 'Ex: Client'
  end
  object ButtonOk: TButton
    Left = 77
    Top = 161
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 2
    OnClick = ButtonOkClick
  end
  object ButtonCancel: TButton
    Left = 214
    Top = 161
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = ButtonCancelClick
  end
end
