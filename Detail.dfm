object DetailForm: TDetailForm
  Left = 0
  Top = 0
  Caption = 'Detail'
  ClientHeight = 441
  ClientWidth = 650
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 650
    Height = 89
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 648
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 32
      Height = 15
      Caption = 'Name'
    end
    object Label2: TLabel
      Left = 16
      Top = 48
      Width = 10
      Height = 15
      Caption = 'IP'
    end
    object Label3: TLabel
      Left = 206
      Top = 16
      Width = 58
      Height = 15
      Caption = 'CPU Usage'
    end
    object Label4: TLabel
      Left = 206
      Top = 48
      Width = 61
      Height = 15
      Caption = 'RAM Usage'
    end
    object Label5: TLabel
      Left = 430
      Top = 16
      Width = 33
      Height = 15
      Caption = 'Power'
    end
    object Label6: TLabel
      Left = 428
      Top = 48
      Width = 62
      Height = 15
      Caption = 'Connection'
    end
    object FieldName: TEdit
      Left = 62
      Top = 13
      Width = 121
      Height = 23
      TabOrder = 0
      OnChange = FieldNameChange
    end
    object FieldIP: TEdit
      Left = 62
      Top = 42
      Width = 121
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 1
    end
    object FieldCPU: TEdit
      Left = 286
      Top = 13
      Width = 121
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 2
    end
    object FieldRAM: TEdit
      Left = 286
      Top = 45
      Width = 121
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 3
    end
    object FieldPower: TEdit
      Left = 504
      Top = 13
      Width = 95
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 4
    end
    object FieldNetwork: TEdit
      Left = 504
      Top = 42
      Width = 95
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 5
    end
  end
  object ComponentListView: TListView
    Left = 0
    Top = 89
    Width = 650
    Height = 263
    Align = alClient
    Columns = <>
    TabOrder = 1
    ViewStyle = vsReport
  end
  object Panel2: TPanel
    Left = 0
    Top = 352
    Width = 650
    Height = 89
    Align = alBottom
    Caption = 'Panel2'
    TabOrder = 2
    ExplicitTop = 344
    ExplicitWidth = 648
  end
  object UpdateTimerDetail: TTimer
    OnTimer = UpdateTimerDetailTimer
    Left = 576
    Top = 384
  end
end
