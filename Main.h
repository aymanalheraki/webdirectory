//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ButtonGroup.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel15;
	TPanel *Panel4;
	TPanel *Panel5;
	TButton *btnSearch;
	TPanel *Panel6;
	TPanel *Panel9;
	TButton *btnNew;
	TImage *Image1;
	TPanel *Panel1;
	TPanel *Panel7;
	TPanel *Panel11;
	TPanel *Panel12;
	TPanel *Panel2;
	TLabel *lblMainCat;
	TPanel *Panel3;
	TLabel *Label1;
	TPanel *Panel13;
	TListBox *subB;
	TPanel *Panel14;
	TListBox *mainB;
	TPanel *Panel8;
	TStringGrid *memSG;
	TEdit *txtSearchWord;
	TMemo *txtDesc;
	TStatusBar *StatusBar1;
	TButton *btnEdit;
	TButton *btnDelete;
	TLabel *lblRCount;
	TLabel *lblDbClickMessage;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall fillSubCat(AnsiString sb);
	void __fastcall runALL(AnsiString wo);
	void __fastcall fillMainCat();
	void __fastcall memSGDblClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall txtSearchWordKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall btnSearchClick(TObject *Sender);
	void __fastcall mainBClick(TObject *Sender);
	void __fastcall subBClick(TObject *Sender);
	void __fastcall btnNewClick(TObject *Sender);
	void __fastcall memSGClick(TObject *Sender);
	void __fastcall btnEditClick(TObject *Sender);
	void __fastcall btnDeleteClick(TObject *Sender);
	void __fastcall Image1DblClick(TObject *Sender);
	void __fastcall Panel9DblClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TFMain(TComponent* Owner);
  AnsiString id;
  AnsiString mainCat;
  AnsiString subCat;
  int catClick;
};
//---------------------------------------------------------------------------
extern PACKAGE TFMain *FMain;
//---------------------------------------------------------------------------
#endif
