// tibiaauto_util.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "tibiaauto_util.h"
#include "tibiaauto_utilfun.h"

#include "MemReader.h"
#include "PackSender.h"
#include "MemConstData.h"
#include "TibiaMapPoint.h"
#include "TibiaMiniMapPoint.h"
#include "TibiaMap.h"
#include "TAMiniMap.h"
#include "TibiaItem.h"
#include "IPCBackPipe.h"
#include "TibiaTile.h"
#include "tileReader.h"
#include "CreaturesReader.h"
#include "VariableStore.h"
#include "../md5class.h"


#include "MemUtil.h"
#include "TibiaContainer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = "C:/temp/testfdkls.txt";
#endif

CTibiaMap tibiaMap;
CTAMiniMap taMiniMap;
CMemReader *reader=NULL;

void startMemReader()
{
	if (reader==NULL)
		reader=new CMemReader();
}

extern HANDLE hPipe;


/////////////////////////////////////////////////////////////////////////////
// CTibiaauto_utilApp

BEGIN_MESSAGE_MAP(CTibiaauto_utilApp, CWinApp)
	//{{AFX_MSG_MAP(CTibiaauto_utilApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTibiaauto_utilApp construction

CTibiaauto_utilApp::CTibiaauto_utilApp()
{
	;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTibiaauto_utilApp object

CTibiaauto_utilApp theApp;
CRITICAL_SECTION ItemsInitCriticalSection;

	



BOOL CTibiaauto_utilApp::InitInstance()
{
	InitializeCriticalSection(&ItemsInitCriticalSection);
	return CWinApp::InitInstance();

}

 CTibiaauto_utilApp::ExitInstance()
{	

	return CWinApp::ExitInstance();

}



void setProcessId(int processId)
{
	CMemUtil::setGlobalProcessId(processId);
}

int getProcessId()
{
	return CMemUtil::getGlobalProcessId();
}


 
void setPipeHandle(HANDLE hPipePar)
{	
	hPipe=hPipePar;
}

CTibiaContainer *memReadContainer(int containerNr)
{
	startMemReader();
	return reader->readContainer(containerNr);
};

void memReadWriteSelfLightPower(int value)
{
	startMemReader();
	reader->writeSelfLightPower(value);
}

void memReadWriteSelfLightColor(int value)
{
	startMemReader();
	reader->writeSelfLightColor(value);
}

int memReadReadSelfLightPower()
{
	startMemReader();
	return reader->readSelfLightPower();
}

int memReadReadSelfLightColor()
{
	startMemReader();
	return reader->readSelfLightColor();
}



void memReadWriteCreatureLightPower(int creatureNr,int value)
{
	startMemReader();
	reader->writeCreatureLightPower(creatureNr,value);
}

void memReadWriteCreatureLightColor(int creatureNr,int value)
{
	startMemReader();
	reader->writeCreatureLightColor(creatureNr,value);
}

int memReadReadCreatureLightPower(int creatureNr)
{
	startMemReader();
	return reader->readCreatureLightPower(creatureNr);
}

int memReadReadCreatureLightColor(int creatureNr)
{
	startMemReader();
	return reader->readCreatureLightColor(creatureNr);
}



void memReadCancelAttackCoords()
{
	startMemReader();
	reader->cancelAttackCoords();
}
void memReadWriteGotoCoords(int x,int y,int z)
{
	startMemReader();
	reader->writeGotoCoords(x,y,z);
}
int memReadGetLoggedCharNr()
{
	startMemReader();
	return reader->getLoggedCharNr();
}
int memReadGetSelfEventFlags()
{
	startMemReader();
	return reader->getSelfEventFlags();
}
void memReadWriteVisibleCreatureName(int chNr,char *name)
{
	startMemReader();
	reader->writeVisibleCreatureName(chNr,name);
}
CTibiaItem * memReadGetTradeItemPartner(int nr)
{
	startMemReader();
	return reader->getTradeItemPartner(nr);
}
CTibiaItem * memReadGetTradeItemSelf(int nr)
{
	startMemReader();
	return reader->getTradeItemSelf(nr);
}
int memReadGetTradeCountPartner()
{
	startMemReader();
	return reader->getTradeCountPartner();
}
int memReadGetTradeCountSelf()
{
	startMemReader();
	return reader->getTradeCountSelf();
}
int memReadGetAttackedCreature()
{
	startMemReader();
	return reader->getAttackedCreature();
}
char * memReadGetLoggedChar(int processId)
{
	startMemReader();
	return reader->GetLoggedChar(processId);
}
int memReadReadBattleListMax()
{
	startMemReader();
	return reader->readBattleListMax();
} 


int memReadReadBattleListMin()
{	
	startMemReader();
	return reader->readBattleListMin();	
}
CTibiaCharacter * memReadReadVisibleCreature(int nr)
{
	startMemReader();
	return reader->readVisibleCreature(nr);
}
CTibiaItem * memReadReadItem(int locationAddress)
{
	startMemReader();
	return reader->readItem(locationAddress);
}
CTibiaCharacter *memReadReadSelfCharacter()
{
	startMemReader();
	return reader->readSelfCharacter();
}
CTibiaCharacter *memReadGetCharacterByTibiaId(int tibiaId)
{
	startMemReader();
	return reader->getCharacterByTibiaId(tibiaId);
}


void packSenderUseWithObjectFromFloorOnFloor(int sourceObjectId,int sourceX,int sourceY,int sourceZ,int targetObjectId,int targetX,int targetY,int targetZ, int method=2)
{
	CPackSender sender;
	sender.useWithObjectFromFloorOnFloor(sourceObjectId, sourceX, sourceY, sourceZ, targetObjectId, targetX, targetY, targetZ,  method);
}

void packSenderUseWithObjectFromFloorInContainer(int sourceObjectId,int sourceX,int sourceY,int sourceZ,int targetObjectId,int targetContNr,int targetPos, int method=2)
{
	CPackSender sender;
	sender.useWithObjectFromFloorInContainer(sourceObjectId, sourceX, sourceY, sourceZ, targetObjectId, targetContNr, targetPos,  method);
}

void packSenderUseWithObjectFromContainerInContainer(int sourceObjectId,int sourceContNr,int sourcePos,int targetObjectId,int targetContNr,int targetPos, int method=2)
{
	CPackSender sender;
	sender.useWithObjectFromContainerInContainer(sourceObjectId, sourceContNr, sourcePos, targetObjectId, targetContNr, targetPos,  method);
}

void packSenderUseWithObjectFromContainerOnFloor(int sourceObjectId,int sourceContNr,int sourcePos,int targetObjectId,int targetX,int targetY,int targetZ, int method=2)
{
	CPackSender sender;
	sender.useWithObjectFromContainerOnFloor(sourceObjectId, sourceContNr, sourcePos, targetObjectId, targetX, targetY, targetZ,  method);
}

void packSenderUseWithObjectOnFloor(int sourceObjectId,int targetObjectId,int targetX,int targetY,int targetZ, int method=2)
{
	CPackSender sender;
	sender.useWithObjectOnFloor(sourceObjectId,targetObjectId,targetX,targetY,targetZ, method);
}

void packSenderUseWithObjectInContainer(int sourceObjectId,int targetObjectId,int contNr,int itemPos, int method=2)
{
	CPackSender sender;
	sender.useWithObjectInContainer(sourceObjectId,targetObjectId,contNr,itemPos, method);
}

CMemConstData getMemConstData()
{	
	return CMemConstData();
}

void packSenderMoveObjectFromFloorToFloor(int objectId, int srcX, int srcY, int srcZ, int destX, int destY, int destZ,int quantity)
{
	CPackSender sender;
	sender.moveObjectFromFloorToFloor(objectId, srcX, srcY, srcZ, destX, destY, destZ,quantity);
}

void packSenderMoveObjectFromFloorToContainer(int objectId,int sourceX,int sourceY,int sourceZ,int targetContNr,int targetPos,int quantity)
{
	CPackSender sender;
	sender.moveObjectFromFloorToContainer(objectId,sourceX,sourceY,sourceZ,targetContNr,targetPos,quantity);
}

void packSenderMoveObjectBetweenContainers(int objectId,int  sourceContNr,int  sourcePos, int targetContNr, int targetPos,int  qty)
{	
	CPackSender sender;
	sender.moveObjectBetweenContainers(objectId, sourceContNr, sourcePos, targetContNr, targetPos, qty);
}

void packSenderMoveObjectFromContainerToFloor(int objectId, int contNr, int pos, int x, int y, int z,int quantity)
{
	CPackSender sender;
	sender.moveObjectFromContainerToFloor(objectId,contNr,pos,x,y,z,quantity);
}
void packSenderCastRuneAgainstCreature(int contNr, int itemPos, int runeObjectId, int creatureId, int method)
{
	CPackSender sender;
	sender.castRuneAgainstCreature(contNr,itemPos,runeObjectId,creatureId,method);
}
void packSenderCastRuneAgainstHuman(int contNr, int itemPos, int runeObjectId, int targetX, int targetY, int targetZ, int method)
{
	CPackSender sender;
	sender.castRuneAgainstHuman(contNr,itemPos,runeObjectId,targetX,targetY,targetZ, method);
}

void packSenderUseItemOnCreature(int objectId, int creatureId)
{
	CPackSender sender;
	sender.useItemOnCreature(objectId, creatureId);
}
void packSenderUseItemFromContainerOnCreature(int objectId, int contNr, int itemPos, int creatureId)
{
	CPackSender sender;
	sender.useItemFromContainerOnCreature(objectId, contNr, itemPos, creatureId);
}
void packSenderUseItemFromFloorOnCreature(int objectId, int x, int y, int z, int creatureId)
{
	CPackSender sender;
	sender.useItemFromFloorOnCreature(objectId, x, y, z, creatureId);
}

void packSenderSendTAMessage(char *msg)
{
	CPackSender sender;
	sender.sendTAMessage(msg);
}

void packSenderUseItem(int objectId)
{
	CPackSender sender;
	sender.useItem(objectId);
}
void packSenderUseItemOnFloor(int objectId, int x, int y, int z)
{
	CPackSender sender;
	sender.useItemOnFloor(objectId,x,y,z);
}
void packSenderUseItemInContainer(int objectId, int contNr, int pos)
{
	CPackSender sender;
	sender.useItemInContainer(objectId,contNr,pos);
}
void packSenderOpenContainerFromFloor(int objectId,int x,int y,int z,int targetBag)
{
	CPackSender sender;
	sender.openContainerFromFloor(objectId,x,y,z,targetBag);
}
int packSenderOpenAutoContainerFromFloor(int objectId,int x,int y,int z)
{
	CPackSender sender;
	return sender.openAutoContainerFromFloor(objectId,x,y,z);
}
void packSenderOpenContainerFromContainer(int objectId, int contNrFrom, int contPosFrom, int targetBag)
{
	CPackSender sender;
	sender.openContainerFromContainer(objectId,contNrFrom,contPosFrom,targetBag);
}

int packSenderOpenAutoContainerFromContainer(int objectId, int contNrFrom, int contPosFrom)
{
	CPackSender sender;
	return sender.openAutoContainerFromContainer(objectId,contNrFrom,contPosFrom);
}

void packSenderSendAttackedCreatureToAutoAim(int attackedCreature)
{
	CPackSender sender;
	sender.sendAttackedCreatureToAutoAim(attackedCreature);
}

void packSenderSay(char *msg)
{
	CPackSender sender;
	sender.say(msg);
}

void packSenderSayWhisper(char *msg)
{
	CPackSender sender;
	sender.sayWhisper(msg);
}

void packSenderSayYell(char *msg)
{
	CPackSender sender;
	sender.sayYell(msg);
}

void packSenderTell(char *msg, char *playerName)
{
	CPackSender sender;
	sender.tell(msg,playerName);
}

void packSenderSayOnChan(char *msg, int channelId1,int channelId2)
{
	CPackSender sender;
	sender.sayOnChan(msg,channelId1,channelId2);
}

void packSenderSayNPC(char *msg)
{
	CPackSender sender;
	sender.sayNPC(msg);
}

void packSenderNpcSell(int objectId,int qty)
{
	CPackSender sender;
	sender.npcSell(objectId, qty);
}

void packSenderNpcBuy(int objectId,int qty, int ignoreCap, int withBackpack)
{
	CPackSender sender;
	sender.npcBuy(objectId,qty, ignoreCap, withBackpack);
}

void memReadSetMemIntValue(int address,int value)
{
	CMemUtil::SetMemIntValue(address,value);
}

int memReadGetMemIntValue(int address)
{
	return CMemUtil::GetMemIntValue(address);
}

void memReadSetMemRange(DWORD memAddressStart,DWORD memAddressEnd, char *data)
{
	CMemUtil::SetMemRange(memAddressStart,memAddressEnd,data);
}

void memReadGetMemRange(DWORD memAddressStart,DWORD memAddressEnd, char *data)
{
	CMemUtil::SetMemRange(memAddressStart,memAddressEnd,data);
}

void tibiaMapRemovePointAvailable(int x,int y,int z)
{
	tibiaMap.removePointAvailable(x,y,z);
}
void tibiaMapProhPointClear()
{
	tibiaMap.prohPointClear();
}
void tibiaMapProhPointAdd(int x, int y, int z)
{
	tibiaMap.prohPointAdd(x,y,z);
}
int tibiaMapGetPointUpDown(int x,int y,int z)
{
	return tibiaMap.getPointUpDown(x,y,z);
}
int tibiaMapGetPointUpDownNoProh(int x,int y,int z)
{
	return tibiaMap.getPointUpDownNoProh(x,y,z);
}
void tibiaMapSetPointUpDown(int x,int y,int z,int updown)
{
	tibiaMap.setPointUpDown(x,y,z,updown);
}
int tibiaMapGetPrevPointZ(int x,int y, int z)
{
	return tibiaMap.getPrevPointZ(x,y,z);
}
int tibiaMapGetPrevPointY(int x,int y, int z)
{
	return tibiaMap.getPrevPointY(x,y,z);
}
int tibiaMapGetPrevPointX(int x,int y, int z)
{
	return tibiaMap.getPrevPointX(x,y,z);
}
void tibiaMapClearPrevPoint()
{
	tibiaMap.clearPrevPoint();
}
void tibiaMapClearLocalPrevPoint(int x,int y,int z,int radius)
{
	tibiaMap.clearLocalPrevPoint(x,y,z,radius);
}
void tibiaMapSetPrevPoint(int x,int y,int z,int prevX, int prevY, int prevZ)
{
	tibiaMap.setPrevPoint(x,y,z,prevX,prevY,prevZ);
}
void tibiaMapSetBestPrevPoint(int x,int y,int z,int prevX, int prevY, int prevZ)
{
	tibiaMap.setBestPrevPoint(x,y,z,prevX,prevY,prevZ);
}
struct point tibiaMapGetRandomPoint()
{
	return tibiaMap.getRandomPoint();
}
void tibiaMapClear()
{
	tibiaMap.clear();
}
void tibiaMapSetPointAsAvailable(int x,int y,int z)
{
	tibiaMap.setPointAsAvailable(x,y,z);
}
int tibiaMapIsPointAvailable(int x,int y,int z)
{
	return tibiaMap.isPointAvailable(x,y,z);
}

int tibiaMapIsPointAvailableNoProh(int x,int y,int z)
{
	return tibiaMap.isPointAvailableNoProh(x,y,z);
}

int tibiaMapSize()
{
	return tibiaMap.size();
}

struct point tibiaMapGetPointByNr(int nr)
{
	return tibiaMap.getPointByNr(nr);
}

point tibiaMapGetDestPoint(int x,int y, int z)
{
	return tibiaMap.getDestPoint(x,y,z);
}

void tibiaMapSetDestPoint(int x,int y, int z, int destX, int destY, int destZ)
{
	tibiaMap.setDestPoint(x, y, z, destX, destY, destZ);
}

int tibiaMapGetPointSpeed(int x,int y, int z)
{
	return tibiaMap.getPointSpeed(x,y,z);
}

void tibiaMapSetPointSpeed(int x,int y, int z, int speed)
{
	tibiaMap.setPointSpeed(x, y, z, speed);
}

int tibiaMapIsPointInMiniMap(int x,int y,int z)
{
	return taMiniMap.isPointInMiniMap(x,y,z);
}

CTibiaMiniMapPoint* tibiaMapGetMiniMapPoint(int x,int y,int z)
{
	return taMiniMap.getMiniMapPoint(x,y,z);
}

void tibiaMapSetMiniMapPoint(int x,int y,int z,int col,int spd)
{
	taMiniMap.setMiniMapPoint(x,y,z,col,spd);
}

CUIntArray * tibiaMapFindPathOnMiniMap(int x,int y,int z,int x2,int y2,int z2)
{
	return taMiniMap.findPathOnMiniMap(x, y, z, x2, y2, z2);
}

void tibiaMapFindPathStop()
{
	taMiniMap.findPathStop();
}

bool tibiaMapIsFindPathStopped()
{
	return taMiniMap.isFindPathStopped();
}

int tibiaMapGetCurrentDistance()
{
	return taMiniMap.getCurrentDistance();
}

int tibiaItemGetIndex(int objectId, int type)
{
	return CTibiaItem::getIndex(objectId, type);
}

char * tibiaItemGetName(int objectId)
{
	return CTibiaItem::getName(objectId);
}

int tibiaItemGetObjectId(char *name)
{
	return CTibiaItem::getObjectId(name);
}
int tibiaItemGetFoodId(char *name)
{
	return CTibiaItem::getFoodId(name);
}
int tibiaItemGetLootItemId(char *name) {
	return CTibiaItem::getLootItemId(name);
}
int tibiaItemGetExtraInfo(int index, int type) {
	if (type == 1) {
		return CTibiaItem::itemsItemsExtra[index];
	}
	if (type == 2) {
		return CTibiaItem::itemsFoodTime[index];
	}
	if (type == 3) {
		return CTibiaItem::itemsLootedExtra[index];
	}
	return 0;
}

void tibiaItemSetItemName(int index, char *name) {
	CTibiaItem::setName(index, name, 1);
}
void tibiaItemSetFoodName(int index, char *name) {
	CTibiaItem::setName(index, name, 2);
}
void tibiaItemSetLootName(int index, char *name) {
	CTibiaItem::setName(index, name, 3);
}
void tibiaItemSetExtraInfo(int index, int info, int type) {
	CTibiaItem::setExtraInfo(index, info, type);
}

void tibiaItemSetItemObjectId(int index, int objectId) {
	CTibiaItem::setObjectId(index, objectId, 1);
}
void tibiaItemSetFoodObjectId(int index, int objectId) {
	CTibiaItem::setObjectId(index, objectId, 2);
}
void tibiaItemSetLootObjectId(int index, int objectId) {
	CTibiaItem::setObjectId(index, objectId, 3);
}

void tibiaItemRefreshItemLists()
{	
	CTibiaItem::itemListsFresh=0;
	CTibiaItem::refreshItemLists();
}

void tibiaItemSaveItemLists() {	
	CTibiaItem::saveItemLists();
}

void tibiaItemAddItem(char *name, int objectId) {	
	CTibiaItem::addItem(name, objectId, NULL, 1);
}
void tibiaItemAddFood(char *name, int objectId, int time) {	
	CTibiaItem::addItem(name, objectId, time, 2);
}
void tibiaItemAddLoot(char *name, int objectId) {	
	CTibiaItem::addItem(name, objectId, NULL, 3);
}

int tibiaItemGetCorpseIdByCreatureName(char *name)
{
	return CTibiaItem::getCorpseIdByCreatureName(name);
}

CUIntArray * tibiaItemGetItemsFoodArray()
{
	return CTibiaItem::getItemsFood();
}


char *tibiaItemGetItemsItems(int nr)
{
	return CTibiaItem::itemsItems[nr];
}
int tibiaItemGetItemsItemsId(int nr)
{
	return CTibiaItem::itemsItemsId[nr];
}
int tibiaItemGetItemsItemsCount()
{
	return CTibiaItem::itemsItemsCount;
}
void tibiaItemSetItemsItemsCount(int newCount) {
	CTibiaItem::setCount(1, newCount);
}
void tibiaItemSetItemsFoodCount(int newCount) {
	CTibiaItem::setCount(2, newCount);
}
void tibiaItemSetItemsLootCount(int newCount) {
	CTibiaItem::setCount(3, newCount);
}
char *tibiaItemGetItemsFood(int nr)
{
	return CTibiaItem::itemsFood[nr];
}
int tibiaItemGetItemsFoodId(int nr)
{
	return CTibiaItem::itemsFoodId[nr];
}
int tibiaItemGetItemsFoodCount()
{
	return CTibiaItem::itemsFoodCount;
}
char *tibiaItemGetItemsCorpses(int nr)
{
	return CTibiaItem::itemsCorpses[nr];
}
int tibiaItemGetItemsCorpsesId(int nr)
{
	return CTibiaItem::itemsCorpsesId[nr];
}
int tibiaItemGetItemsCorpsesCount()
{
	return CTibiaItem::itemsCorpsesCount;
}
char *tibiaItemGetItemsLooted(int nr)
{
	return CTibiaItem::itemsLooted[nr];
}
int tibiaItemGetItemsLootedId(int nr)
{
	return CTibiaItem::itemsLootedId[nr];
}
int tibiaItemGetItemsLootedCount()
{
	return CTibiaItem::itemsLootedCount;
}

int tibiaItemGetValueForConst(char *code)
{
	return CTibiaItem::getValueForConst(code);
}

void packSenderLogout()
{
	CPackSender sender;
	sender.logout();
}

void packSenderStepMulti(int *direction,int size)
{
	CPackSender sender;
	sender.stepMulti(direction,size);
}

void packSenderCloseContainer(int contNr)
{
	CPackSender sender;
	sender.closeContainer(contNr);
}

void packSenderAttackMode(int mode,int follow)
{
	CPackSender sender;
	sender.attackMode(mode,follow);
}

void packSenderAttack(int tibiaCharId)
{
	CPackSender sender;
	sender.attack(tibiaCharId);
}

void packSenderFollow(int tibiaCharId)
{
	CPackSender sender;
	sender.follow(tibiaCharId);
}

int memReadMapGetSelfCellNr()
{
	startMemReader();
	return reader->mapGetSelfCellNr();
}
int memReadMapGetPointItemsCount(point p,int relToCell=-1)
{
	startMemReader();
	return reader->mapGetPointItemsCount(p,relToCell);
}
int memReadMapGetPointItemId(point p, int stackNr,int relToCell=-1)
{
	startMemReader();
	return reader->mapGetPointItemId(p,stackNr,relToCell);
}

int memReadMapGetPointItemExtraInfo(point p, int stackNr,int extraPos,int relToCell=-1)
{
	startMemReader();
	return reader->mapGetPointItemExtraInfo(p,stackNr,extraPos,relToCell);
}

int memReadMapGetPointStackIndex(point p, int stackNr,int relToCell=-1)
{
	startMemReader();
	return reader->mapGetPointStackIndex(p,stackNr,relToCell);
}

void memReadMapSetPointItemsCount(point p, int count,int relToCell=-1)
{
	startMemReader();
	reader->mapSetPointItemsCount(p,count,relToCell);
}
void memReadMapSetPointItemId(point p, int stackNr, int tileId,int relToCell=-1)
{
	startMemReader();
	reader->mapSetPointItemId(p,stackNr,tileId,relToCell);
}

void packSenderTurnLeft()
{
	CPackSender sender;
	sender.turnLeft();
}

void packSenderTurnRight()
{
	CPackSender sender;
	sender.turnRight();
}

void packSenderTurnUp()
{
	CPackSender sender;
	sender.turnUp();
}

void packSenderTurnDown()
{
	CPackSender sender;
	sender.turnDown();
}

void packSenderStopAll()
{
	CPackSender sender;
	sender.stopAll();
}

long memReadGetCurrentTm()
{
	startMemReader();
	return reader->getCurrentTm();
}


int ipcBackPipeReadFromPipe(struct ipcMessage *mess,int expectedType)
{
	CIPCBackPipe backPipe;
	return backPipe.readFromPipe(mess,expectedType);
}

void ipcBackPipeInitialiseIPC()
{
	CIPCBackPipe backPipe;
	backPipe.InitialiseIPC();
}

void packSenderSendCreatureInfo(char *name, char *info1, char *info2)
{
	CPackSender sender;
	sender.sendCreatureInfo(name,info1,info2);
}

void packSenderLook(int x,int y, int z,int objectId)
{
	CPackSender sender;
	sender.look(x,y,z,objectId);
}

void packSenderIgnoreLook(int end)
{
	CPackSender sender;
	sender.ignoreLook(end);
}

long memReadGetCurrenTm()
{
	startMemReader();
	return reader->getCurrentTm();
}

void packSenderSendAutoAimConfig(int active, int onlyCreatures, int aimPlayersFromBattle)
{
	CPackSender sender;
	sender.sendAutoAimConfig(active,onlyCreatures,aimPlayersFromBattle);
}


void packSenderSendClearCreatureInfo()
{
	CPackSender sender;
	sender.sendClearCreatureInfo();
}

void memReadWriteEnableRevealCName ()
{
	startMemReader();
	reader->writeEnableRevealCName();
}

void memReadWriteDisableRevealCName ()
{
	startMemReader();
	reader->writeDisableRevealCName();
}

int getKernelMainVersion()
{
	return 3;
}

int getKernelPatchVersion()
{
	return 0;
}

CTibiaTile *getTibiaTile(int tileNr)
{
	CTileReader tileReader;
	return tileReader.getTile(tileNr);
}

void setTibiaTile(int tileNr, CTibiaTile *newTile)
{
	CTileReader tileReader;
	tileReader.setTile(tileNr, newTile);
}

void memReadSetRemainingTilesToGo(int val)
{
	startMemReader();
	reader->setRemainingTilesToGo(val);
}

void packSenderEnableCName(int enable)
{
	CPackSender sender;
	sender.enableCName(enable);
}

void variableStoreSetVariable(char *name, char *value)
{
	CVariableStore::setVariable(name,value);
}

char *variableStoreGetVariable(char *name)
{
	return CVariableStore::getVariable(name);
}

CTibiaMiniMap *memReadReadMiniMap(int nr)
{
	startMemReader();
	return reader->readMiniMap(nr);
}

CTibiaMiniMapLabel *memReadReadMiniMapLabel(int mapNr,int pointNr)
{
	startMemReader();
	return reader->readMiniMapLabel(mapNr,pointNr);
}

CTibiaMiniMapPoint *memReadReadMiniMapPoint(int x,int y,int z)
{
	startMemReader();
	return reader->readMiniMapPoint(x,y,z);
}

void memReadWriteMiniMapPoint(int x, int y, int z,int col,int spd)
{
	startMemReader();
	reader->writeMiniMapPoint(x,y,z,col,spd);
}

int crFindCreatureStatForLocationTibiaId(int x, int y, int z, int pos)
{
	CCreaturesReader cReader;
	return cReader.findCreatureStatForLocationTibiaId(x,y,z,pos);
}

int crFindCreatureStatForLocationCount(int x, int y, int z)
{
	CCreaturesReader cReader;
	return cReader.findCreatureStatForLocationCount(x,y,z);
}

char *crFindCreatureStatForLocationName(int x, int y, int z, int pos)
{
	CCreaturesReader cReader;
	return cReader.findCreatureStatForLocationName(x,y,z,pos);
}


char ** crFindCreatureStatInArea(int x, int y, int z, int rangeXY, int rangeZ)
{
	CCreaturesReader cReader;
	return cReader.findCreatureStatInArea(x,y,z,rangeXY,rangeZ);
}

void memReadSetMainWindowText(char *text)
{
	startMemReader();
	reader->setMainWindowText(text);
};

void memReadSetMainTrayText(char *text)
{
	startMemReader();
	reader->setMainTrayText(text);
};


int memReadGetPlayerModeAttackPlayers()
{
	startMemReader();
	return reader->getPlayerModeAttackPlayers();
}
int memReadGetPlayerModeFollow()
{
	startMemReader();
	return reader->getPlayerModeFollow();
}

int memReadGetPlayerModeAttackType()
{
	startMemReader();
	return reader->getPlayerModeAttackType();
}

char *memReadGetOpenWindowName()
{
	startMemReader();
	return reader->getOpenWindowName();
}

int memReadGetConnectionState()
{
	startMemReader();
	return reader->getConnectionState();
}

void memReadSetXRayValues(int v1,int v2)
{
	startMemReader();
	reader->setXRayValues(v1,v2);
}

int memReadGetXRayValue1()
{
	startMemReader();
	return reader->getXRayValue1();
}

int memReadGetXRayValue2()
{
	startMemReader();
	return reader->getXRayValue2();
}

void memReadWriteCreatureDeltaXY(int creatureNr, int deltaX, int deltaY)
{	
	startMemReader();
	reader->writeCreatureDeltaXY(creatureNr,deltaX,deltaY);	
}

void memReadSetAttackedCreature(int tibiaId)
{	
	startMemReader();
	reader->setAttackedCreature(tibiaId);	
}

int memReadGetCreatureDeltaX(int creatureNr)
{
	startMemReader();
	return reader->getCreatureDeltaX(creatureNr);
}

int memReadGetCreatureDeltaY(int creatureNr)
{
	startMemReader();
	return reader->getCreatureDeltaY(creatureNr);
}
CTibiaVIPEntry *memReadReadVIPEntry(int nr)
{
	startMemReader();
	return reader->readVIPEntry(nr);
}
