//---------------------------------------------------------------------------

#ifndef EditH
#define EditH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "add.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFEdit : public TFAdd
{
__published:	// IDE-managed Components
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFEdit(TComponent* Owner);
	AnsiString id;
};
//---------------------------------------------------------------------------
extern PACKAGE TFEdit *FEdit;
//---------------------------------------------------------------------------
#endif
