//---------------------------------------------------------------------------

#ifndef addH
#define addH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFAdd : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TEdit *txtWebtitle;
	TLabel *Label1;
	TEdit *txtURL;
	TLabel *Label2;
	TPanel *Panel1;
	TEdit *txtMainIndex;
	TLabel *Label3;
	TEdit *txtSubIndex;
	TLabel *Label4;
	TButton *btnSave;
	TButton *btnCancel;
	TComboBox *cmbMainIndex;
	TComboBox *cmbSubIndex;
	TMemo *txtDesc;
	TLabel *Label5;
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cmbMainIndexChange(TObject *Sender);
	void __fastcall cmbSubIndexChange(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFAdd(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAdd *FAdd;
//---------------------------------------------------------------------------
#endif
