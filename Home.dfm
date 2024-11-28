object HomeForm: THomeForm
  Left = 0
  Top = 0
  Caption = 'Home'
  ClientHeight = 519
  ClientWidth = 749
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Panel1: TPanel
    Left = 16
    Top = 24
    Width = 297
    Height = 49
    Caption = 'Computer Cluster Manager'
    TabOrder = 0
  end
  object ComputerListView: TListView
    AlignWithMargins = True
    Left = 47
    Top = 95
    Width = 619
    Height = 324
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
    TabOrder = 1
    ViewStyle = vsReport
    OnDblClick = ComputerListViewDblClick
  end
  object UpdateTimer: TTimer
    OnTimer = UpdateTimerTimer
    Left = 584
    Top = 8
  end
end
