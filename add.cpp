//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "publicf.h"

#include "add.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFAdd *FAdd;
//---------------------------------------------------------------------------
__fastcall TFAdd::TFAdd(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFAdd::btnCancelClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::FormCreate(TObject *Sender)
{
		AnsiString sqlStr = "SELECT mainindex, count(mainindex) FROM webdir GROUP BY mainindex ";
		TFDConnection *connDB = new TFDConnection(NULL);
		TFDQuery *Q = SelectQ(sqlStr,connDB);
		if(Q->RecordCount > 0)
		{
			for(int i=0;i<Q->RecordCount;i++)
			{
				cmbMainIndex->Items->Add(Q->FieldByName("mainindex")->AsString);
				Q->Next();
			}
			  Q->Close();
			  connDB->Close();
		}
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::cmbMainIndexChange(TObject *Sender)
{
		AnsiString sqlsub = "SELECT subindex, count(subindex) as nss FROM webdir where mainindex = '";
		sqlsub = sqlsub + cmbMainIndex->Items->Strings[cmbMainIndex->ItemIndex]+ "' GROUP BY subindex ";
		TFDConnection *connDB = new TFDConnection(NULL);
		TFDQuery *Q = SelectQ(sqlsub,connDB);
		if(Q->RecordCount > 0)
		{
			  cmbSubIndex->Items->Clear();
			  for(int ii=0;ii < Q->RecordCount ;ii++)
			  {
				  cmbSubIndex->Items->Add(Q->FieldByName("subindex")->AsString);
				  Q->Next();
			  }
			  Q->Close();
			  connDB->Close();
		}
		txtMainIndex->Text = cmbMainIndex->Items->Strings[cmbMainIndex->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TFAdd::cmbSubIndexChange(TObject *Sender)
{
		txtSubIndex->Text = cmbSubIndex->Items->Strings[cmbSubIndex->ItemIndex];
}
//---------------------------------------------------------------------------


void __fastcall TFAdd::btnSaveClick(TObject *Sender)
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

	strSql = strSql + "INSERT INTO webdir (webtitle,url,mainindex,subindex,webdesc) VALUES ('";
	strSql = strSql + txtWebtitle->Text.Trim() + "','" + txtURL->Text.Trim() + "','";
	strSql = strSql + txtMainIndex->Text.Trim() + "','" + txtSubIndex->Text.Trim() + "','";
	strSql = strSql + txtDesc->Text.Trim() + "')";

    CommandSQL(strSql);
	Close();


}
//---------------------------------------------------------------------------

void __fastcall TFAdd::FormShow(TObject *Sender)
{
	if(PixelsPerInch!=96)
	{
		  ScaleBy(96,PixelsPerInch);
	}
}
//---------------------------------------------------------------------------

