//////////////////////////////////////////////////////////////////////////////
// Filename    : main.cpp
// Written by  : kim
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "DB.h"

#include <fstream>

#include "ServerItemInfo.h"
#include "OptionInfo.h"
#include "NPCShopTemplate.h"
#include "NPCScript.h"
#include "MonsterName.h"
#include "Guild.h"

int SkillDomainInfoFactory();
int SkillInfoFactory();
int VampireExpInfoFactory();
int SlayerRankExpFactory();
int VampireRankExpFactory();

int OustersExpInfoFactory();
int OustersRankExpFactory();

int STRBalanceInfoFactory();
int DEXBalanceInfoFactory();
int INTBalanceInfoFactory();

int AdvancementClassEXPInfoFactory();
int RankBonusInfoFactory();

int PetEXPInfoFactory();

int MonsterInfoFactory();

int CreatureSpriteInfoFactory();

int main(int argc, char* argv[])
{
	g_pConnection = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");


	if (argc == 2)
	{
		int argument = atoi(argv[1]);

		if (argument == 0)
		{
			//서버 아이템인포
			createServerItemInfoFile("./data/ServerItemInfo.inf");
		} 
		else if (argument == 1)
		{
			//옵션인포
			createOptionInfoFile("./data/info/itemOption.inf");
		} 
		else if (argument == 2)
		{
			// NPC  shop 템플릿
			createNPCShopTemplateFile("./data/info/NPC.inf", "./data/info/ShopTemplate.inf");
		} else if (argument == 3)
		{
			//npc 스크립트
			createNPCScriptFile("./data/info/NPCScript.inf");
		} else if (argument == 4)
		{
			// 몬스터 네임
			createMonsterNameFile("./data/info/MonsterName.inf");
		}
	}
	else
	{
			createServerItemInfoFile("./data/ServerItemInfo.inf");
			createOptionInfoFile("./data/info/itemOption.inf");
			createNPCScriptFile("./data/info/NPCScript.inf");
			createNPCShopTemplateFile("./data/info/NPC.inf", "./data/info/ShopTemplate.inf");
			createMonsterNameFile("./data/info/MonsterName.inf");

	}

	SkillDomainInfoFactory();
	SkillInfoFactory();
	VampireExpInfoFactory();
	SlayerRankExpFactory();
	VampireRankExpFactory();

	OustersExpInfoFactory();
	OustersRankExpFactory();

	STRBalanceInfoFactory();
	DEXBalanceInfoFactory();
	INTBalanceInfoFactory();

	AdvancementClassEXPInfoFactory();

	RankBonusInfoFactory();

	MonsterInfoFactory();

	PetEXPInfoFactory();
	
	CreatureSpriteInfoFactory();

	//   
	//createGuildfile("./inf/Guild.inf");

	SAFE_DELETE(g_pConnection);

	return 1;

}

int SkillDomainInfoFactory() {

	ofstream file("./data/info/DomainExp.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT DomainType, Level, GoalExp, AccumExp FROM SkillDomainInfo");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in SkillDomainInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    DomainType      = pResult->getInt(1);
		int    Level		   = pResult->getInt(2);
		int    GoalExp         = pResult->getInt(3);
		unsigned int    AccumExp        = (unsigned int)pResult->getLongLong(4);

		file.write("&DomainType",    sizeof(int));
		file.write("&Level",         sizeof(int));
		file.write("&GoalExp",       sizeof(int));
		file.write("&AccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of Level is " << TotalLevelCount << "..." << endl;
	cout << "SkillDomainInfo.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}

int SkillInfoFactory() 
{
	ofstream file("SkillInfo.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Type, Level, Domain, Name, HName, MinDam, MaxDam, MinDelay, MaxDelay, MinDur, MaxDur, Mana, MinRange, MaxRange, SubExp FROM SkillBalance");
	//"SELECT Type, Level, Domain, Name, HName, MinDam, MaxDam, MinDelay, MaxDelay, MinDur, MaxDur, Mana, MinRange, MaxRange, SubExp,SkillPoint,LevelUpPoint,RequireSkill FROM SkillBalance");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in SkillInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{

		int    SkillType       = pResult->getInt(1);
		int    Level		   = pResult->getInt(2);
		int    DomainType      = pResult->getInt(3);
		string SkillName 	   = pResult->getString(4);
		string SkillHName 	   = pResult->getString(5);
		int	   minDamage	   = pResult->getInt(6);
		int    maxDamage       = pResult->getInt(7);
		int    minDelay        = pResult->getInt(8);
		int    maxDelay        = pResult->getInt(9);
		//int    minCastingTime  = pResult->getInt(10);
		//int    maxCastingTime  = pResult->getInt(11);
		int    minCastingTime  = 0;
		int    maxCastingTime  = 0;
		int    minDuration     = pResult->getInt(10);
		int    maxDuration     = pResult->getInt(11);
		int    ConsumeMP       = pResult->getInt(12);
		int    minRange        = pResult->getInt(13);
		int    maxRange        = pResult->getInt(14);
		int    maxExp          = pResult->getInt(15);

		int NameLength = SkillName.size();
		int HNameLength = SkillHName.size();

		file.write("&SkillType",     		 sizeof(int));
		file.write("&Level",			  	 sizeof(int));
		file.write("&DomainType",    		 sizeof(int));
	    	file.write("&NameLength",          sizeof(int));
	    	file.write("SkillName.c_str()",    sizeof(char)*NameLength);
	    	file.write("&HNameLength",          sizeof(int));
	    	file.write("SkillHName.c_str()",    sizeof(char)*HNameLength);

		file.write("&minDamage",    		 sizeof(int));
		file.write("&maxDamage",    		 sizeof(int));
		file.write("&minDelay",    		 sizeof(int));
		file.write("&maxDelay",    		 sizeof(int));
		//file.write(&minCastingTime,  	 sizeof(int));
		//file.write(&maxCastingTime,  	 sizeof(int));
		file.write("&minDuration",	  	 sizeof(int));
		file.write("&maxDuration",	  	 sizeof(int));
		file.write("&ConsumeMP",		  	 sizeof(int));
		file.write("&minRange",		  	 sizeof(int));
		file.write("&maxRange",		  	 sizeof(int));
		file.write("&maxExp",			  	 sizeof(int));


	}

	cout << "Total number of SkillDomainLevel is " << TotalLevelCount << "..." << endl;
	cout << "SkillInfo.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;


	return 1;
}

int VampireExpInfoFactory() {

	ofstream file("./data/info/VampireExp.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Level, GoalExp, AccumExp FROM VampEXPBalanceInfo");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in VampExpInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    Level		   = pResult->getInt(1);
		int    GoalExp         = pResult->getInt(2);
		unsigned int    AccumExp        = (unsigned int)pResult->getLongLong(3);

		file.write("&Level",         sizeof(int));
		file.write("&GoalExp",       sizeof(int));
		file.write("&AccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of Level is " << TotalLevelCount << "..." << endl;
	cout << "VampExpInfo.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}

int SlayerRankExpFactory()
{
	ofstream file("./data/info/SlayerRankExp.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Level, GoalExp, AccumExp FROM RankEXPInfo where RankType = 0");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in RankExpInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    Level		   = pResult->getInt(1);
		int    GoalExp         = pResult->getInt(2);
		unsigned int    AccumExp        = (unsigned int)pResult->getLongLong(3);

		file.write("&Level",         sizeof(int));
		file.write("&GoalExp",       sizeof(int));
		file.write("&AccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of Level is " << TotalLevelCount << "..." << endl;
	cout << "SlayerRankExpInfo.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}

int VampireRankExpFactory()
{
	ofstream file("./data/info/VampireRankExp.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Level, GoalExp, AccumExp FROM RankEXPInfo WHERE RankType = 1");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in VampExpInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    Level		   = pResult->getInt(1);
		int    GoalExp         = pResult->getInt(2);
		unsigned int    AccumExp        = (unsigned int)pResult->getLongLong(3);

		file.write("&Level",         sizeof(int));
		file.write("&GoalExp",       sizeof(int));
		file.write("&AccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of Level is " << TotalLevelCount << "..." << endl;
	cout << "VampireRankExpInfo.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}
//아우스터즈 경험치
int OustersExpInfoFactory() {

	ofstream file("./data/info/OustersExp.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Level, GoalExp, AccumExp FROM OustersEXPBalanceInfo");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in OustersEXPBalanceInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    Level		   = pResult->getInt(1);
		int    GoalExp         = pResult->getInt(2);
		unsigned int    AccumExp        = (unsigned int)pResult->getLongLong(3);

		file.write("&Level",         sizeof(int));
		file.write("&GoalExp",       sizeof(int));
		file.write("&AccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of Level is " << TotalLevelCount << "..." << endl;
	cout << "OustersExp.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}
//아우스터즈 계급 경험치
int OustersRankExpFactory()
{
	ofstream file("./data/info/OustersRankExp.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Level, GoalExp, AccumExp FROM RankEXPInfo WHERE RankType = 1");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in VampExpInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    Level		   = pResult->getInt(1);
		int    GoalExp         = pResult->getInt(2);
		unsigned int    AccumExp        = (unsigned int)pResult->getLongLong(3);

		file.write("&Level",         sizeof(int));
		file.write("&GoalExp",       sizeof(int));
		file.write("&AccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of Level is " << TotalLevelCount << "..." << endl;
	cout << "OustersRankExpInfo.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}

int STRBalanceInfoFactory() {

	ofstream file("./data/info/STRExp.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Level, GoalExp, AccumExp FROM STRBalanceInfo");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in STRInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    Level		   = pResult->getInt(1);
		int    GoalExp         = pResult->getInt(2);
		unsigned int    AccumExp        = (unsigned int)pResult->getLongLong(3);

		file.write("&Level",         sizeof(int));
		file.write("&GoalExp",       sizeof(int));
		file.write("&AccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of option is " << TotalLevelCount << "..." << endl;
	cout << "STRBalaceInfo.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}

int DEXBalanceInfoFactory() {

	ofstream file("./data/info/DEXExp.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Level, GoalExp, AccumExp FROM DEXBalanceInfo");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in DEXInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    Level		   = pResult->getInt(1);
		int    GoalExp         = pResult->getInt(2);
		unsigned int    AccumExp        = (unsigned int)pResult->getLongLong(3);

		file.write("&Level",         sizeof(int));
		file.write("&GoalExp",       sizeof(int));
		file.write("&AccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of option is " << TotalLevelCount << "..." << endl;
	cout << "DEXBalaceInfo.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}

int INTBalanceInfoFactory() {

	ofstream file("./data/info/INTExp.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Level, GoalExp, AccumExp FROM INTBalanceInfo");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in INTInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    Level		   = pResult->getInt(1);
		int    GoalExp         = pResult->getInt(2);
		unsigned int    AccumExp        = (unsigned int)pResult->getLongLong(3);

		file.write("&Level",         sizeof(int));
		file.write("&GoalExp",       sizeof(int));
		file.write("&AccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of option is " << TotalLevelCount << "..." << endl;
	cout << "INTBalaceInfo.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}
int AdvancementClassEXPInfoFactory() {

	ofstream file("./data/info/AdvancementClassEXP.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Level, GoalExp, AccumExp FROM AdvancementClassEXPInfo");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in AdvancementClassEXPInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    Level		   = pResult->getInt(1);
		int    GoalExp         = pResult->getInt(2);
		unsigned int    AccumExp        = (unsigned int)pResult->getLongLong(3);

		file.write("&Level",         sizeof(int));
		file.write("&GoalExp",       sizeof(int));
		file.write("&AccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of Level is " << TotalLevelCount << "..." << endl;
	cout << "AdvancementClassEXP.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}
int RankBonusInfoFactory()
{
	ofstream file("./data/ServerRankBonus.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT Type, Name, `Rank`, Race, Point FROM RankBonusInfo");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in VampExpInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int		Type			= pResult->getInt(1);
		string	Name			= pResult->getString(2);
		int		Rank			= pResult->getInt(3);
		int		Race			= pResult->getInt(4);
		int		Point			= pResult->getInt(5);

		int NameLength = Name.size();

		file.write("&Type",			sizeof(int));
		file.write("&NameLength",		sizeof(int));
		file.write("Name.c_str()",	sizeof(char)*NameLength);
		file.write("&Rank",			sizeof(int));
		file.write("&Race",			sizeof(int));
		file.write("&Point",			sizeof(int));
	}

	cout << "Total number of RankBonus is " << TotalLevelCount << "..." << endl;
	cout << "ServerRankBonus.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}

int MonsterInfoFactory() {

	ofstream file("./data/MonsterInfo.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT MType, Level FROM MonsterInfo");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in MonsterInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    MType		   = pResult->getInt(1);
		int    Level         = pResult->getInt(2);


		file.write("&MType",         sizeof(int));
		file.write("&Level",       sizeof(int));


	}

	cout << "Total number of Level is " << TotalLevelCount << "..." << endl;
	cout << "MonsterInfo.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}

int PetEXPInfoFactory() {

	ofstream file("./data/info/PetEXP.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT PetLevel, PetGoalExp, PetAccumExp FROM PetExpInfo");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in PetEXPInfo table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int    PetLevel		   = pResult->getInt(1);
		int    PetGoalExp         = pResult->getInt(2);
		unsigned int    PetAccumExp        = pResult->getInt(3);

		file.write("&PetLevel",         sizeof(int));
		file.write("&PetGoalExp",       sizeof(int));
		file.write("&PetAccumExp",      sizeof(unsigned int));

	}

	cout << "Total number of Level is " << TotalLevelCount << "..." << endl;
	cout << "PetEXP.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}



int CreatureSpriteInfoFactory() {

	ofstream file("./data/info/CreatureSprite.inf", ios::out | ios::binary | ios::trunc);

	if (!file)
	{
		cerr << "Could not open file for write...!" << endl;
		return -1;
	}

	Connection* pConn   = new Connection("127.0.0.1", "DARKEDEN669", "root", "123456");
	Statement*  pStmt   = pConn->createStatement();
	Result*     pResult = pStmt->executeQuery("SELECT FrameID, SpriteFilePosition, SpriteShadowFilePosition, FirstSpriteID, LastSpriteID, FirstShadowSpriteID, LastShadowSpriteID, CreatureType FROM CreatureSprite");
			
	//      .
	DWORD TotalLevelCount = pResult->getRowCount();
	if (TotalLevelCount == 0) 
	{
		cerr << "There's no data in CreatureSprite table..." << endl;
		return -1;
	}

	file.write("&TotalLevelCount", sizeof(DWORD));

	//    .
	while (pResult->next())
	{
		int		FrameID		   				= pResult->getInt(1);
		int		SpriteFilePosition			= pResult->getInt(2);
		int		SpriteShadowFilePosition	= pResult->getInt(3);
		int		FirstSpriteID				= pResult->getInt(4);
		int		LastSpriteID				= pResult->getInt(5);
		int		FirstShadowSpriteID			= pResult->getInt(6);
		int		LastShadowSpriteID			= pResult->getInt(7);
		int		CreatureType				= pResult->getInt(8);

		file.write("&FrameID",         sizeof(unsigned short));
		file.write("&SpriteFilePosition",       sizeof(int));
		file.write("&SpriteShadowFilePosition",      sizeof(int));
		file.write("&FirstSpriteID",      sizeof(unsigned short));
		file.write("&LastSpriteID",      sizeof(unsigned short));
		file.write("&FirstShadowSpriteID",      sizeof(unsigned short));
		file.write("&LastShadowSpriteID",      sizeof(unsigned short));
		file.write("&CreatureType",      sizeof(unsigned char));



	}

	cout << "Total number of CreatureSprite is " << TotalLevelCount << "..." << endl;
	cout << "CreatureSprite.inf file creation success..." << endl;

	if (pStmt) delete pStmt;
	if (pConn) delete pConn;

	return 1;
}
