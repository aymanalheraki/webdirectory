//---------------------------------------------------------------------------
// Created by Ayman Al-Heraki to C++ Builder World Forums
// http://www.cppbuilder.net/vb to help beginners How to program in C++ Builder
// the great Rapid development tools.
// and discuss how to develop this small project in My forums
// My Email : webmaster@cppbuilder.net.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "publicf.h"
#include "Main.h"
#include "add.h"
#include "Edit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma resource "*.dfm"
TFMain *FMain;
//---------------------------------------------------------------------------
__fastcall TFMain::TFMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFMain::FormCreate(TObject *Sender)
{

	if(PixelsPerInch!=96)
	{
		  ScaleBy(96,PixelsPerInch);
	}


	if(!FileExists("data.db"))
	{
		TResourceStream* resFile = new TResourceStream((int)HInstance, L"datadb", L"RT_RCDATA");
		resFile->SaveToFile("data.db");
	}

	memSG->FixedCols = 1;
	memSG->FixedRows = 1;
	memSG->ColCount = 5;
	memSG->RowCount = 2;

	memSG->Cols[0]->Text = "ID";
	memSG->Cols[1]->Text = "Website Name";
	memSG->Cols[2]->Text = "URL";
	memSG->Cols[3]->Text = "MainIndex";
	memSG->Cols[4]->Text = "SubIndex";


	memSG->ColWidths[0] = 40;
	memSG->ColWidths[1] = memSG->Width - (memSG->ColWidths[0] + memSG->ColWidths[2] + memSG->ColWidths[3] + memSG->ColWidths[4]+15);
	memSG->ColWidths[2] = 250;
	memSG->ColWidths[3] = 120;
	memSG->ColWidths[4] = 120;

	fillMainCat();
	catClick = 0;
	runALL("");
}
//---------------------------------------------------------------------------
 void __fastcall TFMain::fillMainCat()
{
	 AnsiString sqlStr = "SELECT mainindex, count(mainindex) as ns FROM webdir GROUP BY mainindex ";
		TFDConnection *connDB = new TFDConnection(NULL);
		TFDQuery *Q = SelectQ(sqlStr,connDB);

		if(Q->RecordCount > 0)
		{
			mainB->Items->Clear();
			for(int i=0;i<Q->RecordCount;i++)
			{
				mainB->Items->Add(Q->FieldByName("mainindex")->AsString);
				Q->Next();
			}
			Q->Close();
			connDB->Close();
			mainB->ItemIndex = 0;
			fillSubCat(mainB->Items->Strings[mainB->ItemIndex]);
		}
 }
 //---------------------------------------------------------------------------

void __fastcall TFMain::fillSubCat(AnsiString sb)
{
		AnsiString sqlsub = "";
		sqlsub = "SELECT subindex, count(subindex) FROM webdir where mainindex = '" + sb + "' GROUP BY subindex ";
		TFDConnection *connDB = new TFDConnection(NULL);
		TFDQuery *Q = SelectQ(sqlsub,connDB);
		if(Q->RecordCount > 0)
		{
			  subB->Items->Clear();
			  for(int ii=0;ii < Q->RecordCount ;ii++)
			  {
				  subB->Items->Add(Q->FieldByName("subindex")->AsString);
				  Q->Next();
			  }
			Q->Close();
			connDB->Close();
			subB->ItemIndex = 0;
		}

}
 //--------------------------------------------------------------------------
 void __fastcall TFMain::runALL(AnsiString wo)
{
		AnsiString id,webtitle,url,mainindex,subindex,country;
		AnsiString sqlStr = "";

		AnsiString mCat = mainB->Items->Strings[mainB->ItemIndex];
		AnsiString sCat = subB->Items->Strings[subB->ItemIndex];

		sqlStr = "SELECT * FROM webdir where webtitle like '%" + wo + "%' ";

		if(catClick == 1)
		{
			sqlStr = sqlStr + " AND mainindex='" + mCat + "' and subindex = '" + sCat + "' ";
		}

		TFDConnection *connDB = new TFDConnection(NULL);
		TFDQuery *Q = SelectQ(sqlStr,connDB);
		SendMessage(memSG->Handle, WM_SETREDRAW, FALSE, 0);
		if(Q->RecordCount > 0)
		{
			memSG->RowCount = Q->RecordCount+1;
			lblRCount->Caption = Q->RecordCount;
			for(int i=0;i<Q->RecordCount;i++)
			{
				memSG->Cells[0][i+1] = Q->FieldByName("id")->AsString;
				memSG->Cells[1][i+1] = Q->FieldByName("webtitle")->AsString;
				memSG->Cells[2][i+1] = Q->FieldByName("url")->AsString;
				memSG->Cells[3][i+1] = Q->FieldByName("mainindex")->AsString;
				memSG->Cells[4][i+1] = Q->FieldByName("subindex")->AsString;
				Q->Next();
			}
			Q->Close();
			connDB->Close();
		}
		else
		{
			memSG->RowCount = 2;
			memSG->Rows[1]->Clear();
			lblRCount->Caption = "0";
		}
		SendMessage(memSG->Handle, WM_SETREDRAW, TRUE, 0);
		memSG->Invalidate();
}
//--------------------------------------------------------------------------

void __fastcall TFMain::memSGDblClick(TObject *Sender)
{
	AnsiString wb = "http://" + (AnsiString)memSG->Cells[2][memSG->Row];
	ShellExecute(NULL,"open", wb.c_str(),0,0,1);
}


//---------------------------------------------------------------------------

void __fastcall TFMain::FormResize(TObject *Sender)
{
		memSG->ColWidths[1] = memSG->Width - (memSG->ColWidths[0] + memSG->ColWidths[2] + memSG->ColWidths[3] + memSG->ColWidths[4]+15);
}
//---------------------------------------------------------------------------
void __fastcall TFMain::txtSearchWordKeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key == 13)
	{
		catClick = 0;
		runALL("");
    }
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnSearchClick(TObject *Sender)
{
    catClick = 0;
	runALL(txtSearchWord->Text.Trim());
}
//---------------------------------------------------------------------------

void __fastcall TFMain::mainBClick(TObject *Sender)
{
	fillSubCat(mainB->Items->Strings[mainB->ItemIndex]);
    subBClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::subBClick(TObject *Sender)
{
	catClick = 1;
	runALL(txtSearchWord->Text.Trim());
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnNewClick(TObject *Sender)
{
	TFAdd *add = new TFAdd(this);
	add->ShowModal();
	delete add;
	runALL("");
}
//---------------------------------------------------------------------------

void __fastcall TFMain::memSGClick(TObject *Sender)
{
	if (memSG->Cells[0][memSG->Row] != "" && memSG->Row != 0)
	{
		id = memSG->Cells[0][memSG->Row];

		AnsiString sqlStr = "SELECT * FROM webdir where id = " + id;
		TFDConnection *connDB = new TFDConnection(NULL);
		TFDQuery *Q = SelectQ(sqlStr,connDB);
		txtDesc->Text = Q->FieldByName("webdesc")->AsString;
		Q->Close();
		connDB->Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnEditClick(TObject *Sender)
{
	TFEdit *ed = new TFEdit(this);
	ed->id = id;
	ed->ShowModal();
	delete ed;
	runALL("");
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnDeleteClick(TObject *Sender)
{
	WideString DelMsg = "Will Delete Record No : " + id  + L" Are you sure ?";
	if (MessageBoxW(NULL,DelMsg.c_bstr(),L"Delete Record",MB_YESNO | MB_ICONQUESTION | MB_RIGHT ) == IDYES)
	{
		try
		{
			CommandSQL("DELETE FROM webdir where id =" + id);
			runALL(txtSearchWord->Text.Trim());
		}catch(Exception &e)
		{
			ShowMessage(e.Message);
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TFMain::Image1DblClick(TObject *Sender)
{
	ShellExecute(NULL,"open","http://www.cppbuilder.net",0,0,1);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::Panel9DblClick(TObject *Sender)
{
   ShellExecute(NULL,"open","http://www.cppbuilder.net",0,0,1);
}
//---------------------------------------------------------------------------

