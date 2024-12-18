object AddComponentForm: TAddComponentForm
  Left = 0
  Top = 0
  Caption = 'AddComponent'
  ClientHeight = 273
  ClientWidth = 406
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label3: TLabel
    Left = 8
    Top = 21
    Width = 383
    Height = 30
    Caption = 
      'Please enter the Type, Maximum CPU Usage, and Maximum RAM Usage ' +
      #13#10'for the new component.'
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 87
    Top = 77
    Width = 27
    Height = 15
    Caption = 'Type:'
  end
  object Label2: TLabel
    Left = 67
    Top = 155
    Width = 47
    Height = 15
    Caption = 'RAM(%):'
  end
  object Label4: TLabel
    Left = 70
    Top = 115
    Width = 44
    Height = 15
    Caption = 'CPU(%):'
  end
  object ButtonOk: TButton
    Left = 87
    Top = 209
    Width = 75
    Height = 25
    Caption = 'Ok'
    TabOrder = 0
    OnClick = ButtonOkClick
  end
  object ButtonCancel: TButton
    Left = 238
    Top = 209
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = ButtonCancelClick
  end
  object EditType: TEdit
    Left = 148
    Top = 74
    Width = 173
    Height = 23
    TabOrder = 2
    Text = 'Ex: Camera'
  end
  object EditRAMUsage: TEdit
    Left = 148
    Top = 152
    Width = 173
    Height = 23
    TabOrder = 3
    Text = 'Ex: 20'
  end
  object EditCPUUsage: TEdit
    Left = 148
    Top = 112
    Width = 173
    Height = 23
    TabOrder = 4
    Text = 'Ex: 15'
  end
end
