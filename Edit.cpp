//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "publicf.h"

#include "Edit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "add"
#pragma resource "*.dfm"
TFEdit *FEdit;
//---------------------------------------------------------------------------
__fastcall TFEdit::TFEdit(TComponent* Owner)
	: TFAdd(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFEdit::FormShow(TObject *Sender)
{
	if(PixelsPerInch!=96)
	{
		ScaleBy(96,PixelsPerInch);
	}

	AnsiString sqlStr = "SELECT * FROM webdir where id = " + id;
	TFDConnection *connDB = new TFDConnection(NULL);
	TFDQuery *Q = SelectQ(sqlStr,connDB);

	txtWebtitle->Text = Q->FieldByName("webtitle")->AsString;
	txtURL->Text = Q->FieldByName("url")->AsString;
	txtMainIndex->Text = Q->FieldByName("mainindex")->AsString;
	txtSubIndex->Text = Q->FieldByName("subindex")->AsString;
	txtDesc->Text = Q->FieldByName("webdesc")->AsString;
	Q->Close();
	connDB->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFEdit::btnSaveClick(TObject *Sender)
{
	AnsiString strSql = "";

	if(txtWebtitle->Text.Trim() == "")
	{
	   ShowMessage("Please complete Web Title field the try again.");
	   return;
	}

	if(txtURL->Text.Trim() == "")
	{
	   ShowMessage("Please complete URL field the try again.");
	   return;
	}

	strSql = strSql + "UPDATE webdir set webtitle='" + txtWebtitle->Text.Trim();
	strSql = strSql + "',url='" + txtURL->Text.Trim();
	strSql = strSql + "',mainindex='" + txtMainIndex->Text.Trim();
	strSql = strSql + "',subindex='" + txtSubIndex->Text.Trim();
	strSql = strSql + "',webdesc='" + txtDesc->Text.Trim();
	strSql = strSql + "' WHERE id = " + id;
	CommandSQL(strSql);
	Close();


}
//---------------------------------------------------------------------------

