object HomeForm: THomeForm
  Left = 0
  Top = 0
  Caption = 'Home'
  ClientHeight = 393
  ClientWidth = 673
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 673
    Height = 49
    Align = alTop
    Caption = 'Computer Cluster Manager'
    TabOrder = 0
    ExplicitWidth = 704
  end
  object ComputerListView: TListView
    AlignWithMargins = True
    Left = 3
    Top = 52
    Width = 667
    Height = 295
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
        Width = 85
      end
      item
        Caption = 'Power'
        Width = 85
      end>
    RowSelect = True
    PopupMenu = PopupMenu
    TabOrder = 1
    ViewStyle = vsReport
    OnDblClick = ComputerListViewDblClick
    ExplicitLeft = -2
    ExplicitTop = 55
    ExplicitWidth = 700
    ExplicitHeight = 261
  end
  object Panel2: TPanel
    Left = 0
    Top = 350
    Width = 673
    Height = 43
    Align = alBottom
    TabOrder = 2
    ExplicitTop = 308
    ExplicitWidth = 704
    object Panel3: TPanel
      Left = 623
      Top = 1
      Width = 49
      Height = 41
      Align = alRight
      TabOrder = 0
      ExplicitLeft = 654
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
      Width = 574
      Height = 41
      Align = alClient
      Caption = 'Add a computer, press here'
      TabOrder = 2
      OnClick = Panel5Click
      ExplicitWidth = 605
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
    object urnonoff1: TMenuItem
      Caption = 'Turn on/off'
      OnClick = urnonoff1Click
    end
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
