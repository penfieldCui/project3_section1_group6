object DetailForm: TDetailForm
  Left = 0
  Top = 0
  Caption = 'Detail'
  ClientHeight = 527
  ClientWidth = 335
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
    Width = 335
    Height = 297
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 42
      Top = 35
      Width = 35
      Height = 15
      Caption = 'Name:'
    end
    object Label2: TLabel
      Left = 64
      Top = 68
      Width = 13
      Height = 15
      Caption = 'IP:'
    end
    object Label3: TLabel
      Left = 40
      Top = 109
      Width = 61
      Height = 15
      Caption = 'CPU Usage:'
    end
    object Label4: TLabel
      Left = 37
      Top = 138
      Width = 64
      Height = 15
      Caption = 'RAM Usage:'
    end
    object Label5: TLabel
      Left = 107
      Top = 215
      Width = 35
      Height = 15
      Caption = 'Status:'
    end
    object Label6: TLabel
      Left = 107
      Top = 256
      Width = 35
      Height = 15
      Caption = 'Status:'
    end
    object Label7: TLabel
      Left = 17
      Top = 176
      Width = 209
      Height = 15
      Caption = 'Press the button below to switch status.'
    end
    object Label8: TLabel
      Left = 17
      Top = 11
      Width = 88
      Height = 15
      Caption = 'Name is editable'
    end
    object FieldName: TEdit
      Left = 86
      Top = 32
      Width = 121
      Height = 23
      TabOrder = 0
    end
    object FieldIP: TEdit
      Left = 86
      Top = 61
      Width = 121
      Height = 23
      TabOrder = 1
    end
    object FieldCPU: TEdit
      Left = 107
      Top = 106
      Width = 75
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 2
    end
    object FieldRAM: TEdit
      Left = 107
      Top = 135
      Width = 75
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 3
    end
    object FieldPower: TEdit
      Left = 148
      Top = 212
      Width = 59
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 4
    end
    object FieldNetwork: TEdit
      Left = 148
      Top = 252
      Width = 83
      Height = 23
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 5
    end
    object ButtonSaveName: TButton
      Left = 224
      Top = 31
      Width = 79
      Height = 24
      Align = alCustom
      Caption = 'Save name'
      TabOrder = 6
      OnClick = ButtonSaveNameClick
    end
    object ButtonPower: TButton
      Left = 20
      Top = 211
      Width = 65
      Height = 26
      Caption = 'Power'
      TabOrder = 7
      OnClick = ButtonPowerClick
    end
    object ButtonConnect: TButton
      Left = 20
      Top = 251
      Width = 65
      Height = 26
      Caption = 'Connect'
      TabOrder = 8
      OnClick = ButtonConnectClick
    end
    object ButtonSaveIP: TButton
      Left = 224
      Top = 61
      Width = 79
      Height = 24
      Caption = 'Save IP'
      TabOrder = 9
      OnClick = ButtonSaveIPClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 499
    Width = 335
    Height = 28
    Align = alBottom
    TabOrder = 1
    object Back: TButton
      Left = 213
      Top = 1
      Width = 112
      Height = 26
      Align = alRight
      Caption = 'Back to Home'
      TabOrder = 0
      OnClick = BackClick
    end
    object Panel3: TPanel
      Left = 325
      Top = 1
      Width = 9
      Height = 26
      Align = alRight
      TabOrder = 1
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 9
      Height = 26
      Align = alLeft
      TabOrder = 2
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
    end
  end
  object PanelComponentList: TPanel
    Left = 0
    Top = 297
    Width = 335
    Height = 202
    Align = alClient
    TabOrder = 2
    object ComponentListView: TListView
      Left = 1
      Top = 1
      Width = 333
      Height = 200
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
      PopupMenu = PopupMenu1
      TabOrder = 0
      ViewStyle = vsReport
      OnDblClick = ComponentListViewDblClick
    end
  end
  object UpdateTimerDetail: TTimer
    OnTimer = UpdateTimerDetailTimer
    Left = 592
    Top = 320
  end
  object PopupMenu1: TPopupMenu
    Left = 280
    Top = 248
    object urnonoff1: TMenuItem
      Caption = 'Turn on/off'
      OnClick = urnonoff1Click
    end
    object Deletecomponent1: TMenuItem
      Caption = 'Delete component'
      OnClick = Deletecomponent1Click
    end
  end
end
