object DetailForm: TDetailForm
  Left = 0
  Top = 0
  Caption = 'Detail'
  ClientHeight = 473
  ClientWidth = 333
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
    Width = 333
    Height = 209
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 316
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 32
      Height = 15
      Caption = 'Name'
    end
    object Label2: TLabel
      Left = 38
      Top = 45
      Width = 10
      Height = 15
      Caption = 'IP'
    end
    object Label3: TLabel
      Left = 16
      Top = 87
      Width = 58
      Height = 15
      Caption = 'CPU Usage'
    end
    object Label4: TLabel
      Left = 13
      Top = 116
      Width = 61
      Height = 15
      Caption = 'RAM Usage'
    end
    object Label5: TLabel
      Left = 38
      Top = 145
      Width = 36
      Height = 23
      Caption = 'Power'
    end
    object Label6: TLabel
      Left = 12
      Top = 174
      Width = 62
      Height = 15
      Caption = 'Connection'
    end
    object FieldName: TEdit
      Left = 86
      Top = 13
      Width = 121
      Height = 23
      TabOrder = 0
    end
    object FieldIP: TEdit
      Left = 86
      Top = 42
      Width = 121
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 1
    end
    object FieldCPU: TEdit
      Left = 94
      Top = 113
      Width = 113
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 2
    end
    object FieldRAM: TEdit
      Left = 94
      Top = 84
      Width = 113
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 3
    end
    object FieldPower: TEdit
      Left = 94
      Top = 171
      Width = 113
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 4
    end
    object FieldNetwork: TEdit
      Left = 94
      Top = 142
      Width = 113
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 5
    end
    object Save: TButton
      Left = 257
      Top = 1
      Width = 75
      Height = 207
      Align = alRight
      Caption = 'Save'
      TabOrder = 6
      OnClick = SaveClick
      ExplicitLeft = 240
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 445
    Width = 333
    Height = 28
    Align = alBottom
    TabOrder = 1
    ExplicitTop = 443
    ExplicitWidth = 316
    object Back: TButton
      Left = 211
      Top = 1
      Width = 112
      Height = 26
      Align = alRight
      Caption = 'Back to Home'
      TabOrder = 0
      ExplicitLeft = 442
      ExplicitTop = 6
      ExplicitHeight = 31
    end
    object Panel3: TPanel
      Left = 323
      Top = 1
      Width = 9
      Height = 26
      Align = alRight
      TabOrder = 1
      ExplicitLeft = 304
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 9
      Height = 26
      Align = alLeft
      TabOrder = 2
      ExplicitHeight = 31
    end
    object Add: TButton
      Left = 10
      Top = 1
      Width = 135
      Height = 26
      Align = alLeft
      Caption = 'Add new component'
      TabOrder = 3
      OnClick = AddClick
      ExplicitLeft = 90
      ExplicitHeight = 31
    end
  end
  object PanelComponentList: TPanel
    Left = 0
    Top = 209
    Width = 333
    Height = 236
    Align = alClient
    TabOrder = 2
    ExplicitTop = 83
    ExplicitWidth = 772
    ExplicitHeight = 353
    object ComponentListView: TListView
      Left = 1
      Top = 1
      Width = 331
      Height = 234
      Align = alClient
      Columns = <
        item
          AutoSize = True
          Caption = 'Type'
        end
        item
          Caption = 'Power'
          Width = 70
        end
        item
          Caption = 'CPU(%)'
          Width = 60
        end
        item
          Caption = 'RAM(%)'
          Width = 60
        end>
      RowSelect = True
      TabOrder = 0
      ViewStyle = vsReport
    end
  end
  object UpdateTimerDetail: TTimer
    OnTimer = UpdateTimerDetailTimer
    Left = 592
    Top = 320
  end
end
