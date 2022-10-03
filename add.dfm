object FAdd: TFAdd
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 252
  ClientWidth = 471
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 7
    Top = 30
    Width = 458
    Height = 187
    Color = 15395562
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    object Label1: TLabel
      Left = 13
      Top = 11
      Width = 52
      Height = 13
      Caption = 'Web Title :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 8404992
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 39
      Top = 36
      Width = 26
      Height = 13
      Caption = 'URL :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 8404992
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 5
      Top = 59
      Width = 60
      Height = 13
      Caption = 'Main Index :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 8404992
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 9
      Top = 83
      Width = 56
      Height = 13
      Caption = 'Sub Index :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 8404992
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 5
      Top = 107
      Width = 60
      Height = 13
      Caption = 'Describtion :'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 8404992
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object txtWebtitle: TEdit
      Left = 68
      Top = 8
      Width = 381
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 0
    end
    object txtURL: TEdit
      Left = 68
      Top = 32
      Width = 381
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 1
    end
    object txtMainIndex: TEdit
      Left = 251
      Top = 56
      Width = 198
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 2
    end
    object txtSubIndex: TEdit
      Left = 251
      Top = 81
      Width = 198
      Height = 19
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 3
    end
    object cmbMainIndex: TComboBox
      Left = 68
      Top = 55
      Width = 174
      Height = 21
      Style = csDropDownList
      TabOrder = 5
      OnChange = cmbMainIndexChange
    end
    object cmbSubIndex: TComboBox
      Left = 68
      Top = 80
      Width = 174
      Height = 21
      Style = csDropDownList
      TabOrder = 6
      OnChange = cmbSubIndexChange
    end
    object txtDesc: TMemo
      Left = 68
      Top = 106
      Width = 381
      Height = 71
      Lines.Strings = (
        '')
      TabOrder = 4
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 471
    Height = 25
    Align = alTop
    BevelKind = bkFlat
    BevelOuter = bvNone
    Caption = 'Add New Website'
    Color = 16772033
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 9527808
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 3
  end
  object btnSave: TButton
    Left = 301
    Top = 223
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 1
    OnClick = btnSaveClick
  end
  object btnCancel: TButton
    Left = 382
    Top = 223
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = btnCancelClick
  end
end
