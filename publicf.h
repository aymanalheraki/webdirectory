#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>

//#include "Main.h"

//----------------------------------------------------------------------------
TFDQuery* SelectQ(AnsiString strSql,TFDConnection *connDB)
{
	try
	{
		connDB->DriverName = "SQLite";
		connDB->Connected = true;
		connDB->Params->Add("Database=data.db");
		connDB->Params->Add("Unicode=true");

		connDB->Connected = true;
		TFDQuery *Q = new TFDQuery(Application);

		Q->Connection = connDB;
		Q->SQL->Text = strSql;
		Q->Open(strSql);

		return Q;

	 }
	 catch(Exception *e)
	 {
		ShowMessage("error during connect to database");
	 }
	 return 0;
}
//----------------------------------------------------------------------------
long int CommandSQL(AnsiString strSql)
{
	try
	{
		TFDConnection *connDB2 = new TFDConnection(Application);
		connDB2->DriverName = "SQLite";
		connDB2->Connected = true;
		connDB2->Params->Add("Database=data.db");
		connDB2->Connected = true;
		TFDQuery *stdQ = new TFDQuery(Application);

		stdQ->Connection = connDB2;
		stdQ->SQL->Add(strSql);
		stdQ->ExecSQL();

		stdQ->Open("SELECT LAST_INSERT_ROWID() AS rowid");
		long int clID;
		if(stdQ->FindFirst())
		{
			clID = stdQ->FieldByName("rowid")->AsLargeInt;
		}

		connDB2->Connected = false;


		return clID;
	   }
	   catch(Exception *e)
	  {
		ShowMessage("error during connect to database");
	  }
      return 0;
}

//----------------------------------------------------------------------------


