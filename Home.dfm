object HomeForm: THomeForm
  Left = 0
  Top = 0
  Caption = 'Home'
  ClientHeight = 359
  ClientWidth = 706
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 706
    Height = 49
    Align = alTop
    Caption = 'Computer Cluster Manager'
    TabOrder = 0
    ExplicitWidth = 782
  end
  object ComputerListView: TListView
    AlignWithMargins = True
    Left = 3
    Top = 52
    Width = 700
    Height = 261
    Align = alClient
    Columns = <
      item
        Caption = 'Name of computer'
        MaxWidth = 200
        MinWidth = 130
        Width = 130
      end
      item
        Caption = 'IP'
        Width = 130
      end
      item
        Caption = 'CPU(%)'
        Width = 60
      end
      item
        Caption = 'RAM(%)'
        Width = 60
      end
      item
        Caption = 'Connect'
        Width = 70
      end
      item
        Caption = 'Power'
        Width = 70
      end>
    RowSelect = True
    PopupMenu = PopupMenu
    TabOrder = 1
    ViewStyle = vsReport
    OnDblClick = ComputerListViewDblClick
    ExplicitWidth = 778
    ExplicitHeight = 448
  end
  object Panel2: TPanel
    Left = 0
    Top = 316
    Width = 706
    Height = 43
    Align = alBottom
    TabOrder = 2
    ExplicitTop = 495
    ExplicitWidth = 782
    object Panel3: TPanel
      Left = 656
      Top = 1
      Width = 49
      Height = 41
      Align = alRight
      TabOrder = 0
      ExplicitLeft = 732
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 48
      Height = 41
      Align = alLeft
      TabOrder = 1
    end
    object Panel5: TPanel
      Left = 49
      Top = 1
      Width = 607
      Height = 41
      Align = alClient
      Caption = 'Add a computer, press here'
      TabOrder = 2
      OnClick = Panel5Click
      ExplicitWidth = 683
    end
  end
  object UpdateTimer: TTimer
    OnTimer = UpdateTimerTimer
    Left = 624
    Top = 8
  end
  object PopupMenu: TPopupMenu
    Left = 520
    Top = 8
    object Edit1: TMenuItem
      Caption = 'Edit'
      OnClick = Edit1Click
    end
    object MenuItemDelete: TMenuItem
      Caption = 'Delete'
      OnClick = MenuItemDeleteClick
    end
  end
end
