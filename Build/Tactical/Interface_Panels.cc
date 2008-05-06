#include "Font.h"
#include "Isometric_Utils.h"
#include "Local.h"
#include "Soldier_Ani.h"
#include "Timer_Control.h"
#include "VObject.h"
#include "SysUtil.h"
#include "Overhead.h"
#include "MouseSystem.h"
#include "Button_System.h"
#include "Interface.h"
#include "VSurface.h"
#include "WCheck.h"
#include "Input.h"
#include "Handle_UI.h"
#include "RenderWorld.h"
#include "Cursors.h"
#include "Radar_Screen.h"
#include "Font_Control.h"
#include "Render_Dirty.h"
#include "Sound_Control.h"
#include "Interface_Panels.h"
#include "Animation_Control.h"
#include "Soldier_Control.h"
#include "PathAI.h"
#include "Weapons.h"
#include "Faces.h"
#include "MapScreen.h"
#include "Message.h"
#include "Text.h"
#include "Interface_Items.h"
#include "Interface_Control.h"
#include "Interface_Utils.h"
#include "Game_Clock.h"
#include "Soldier_Macros.h"
#include "StrategicMap.h"
#include "Soldier_Functions.h"
#include "GameScreen.h"
#include "Assignments.h"
#include "Points.h"
#include "Squads.h"
#include "Strategic.h"
#include "Map_Screen_Interface_Map.h"
#include "Overhead_Map.h"
#include "Map_Screen_Interface.h"
#include "Options_Screen.h"
#include "ShopKeeper_Interface.h"
#include "English.h"
#include "Keys.h"
#include "Soldier_Add.h"
#include "Vehicles.h"
#include "GameSettings.h"
#include "Dialogue_Control.h"
#include "Items.h"
#include "Drugs_And_Alcohol.h"
#include "LOS.h"
#include "OppList.h"
#include "VObject_Blitters.h"
#include "Finances.h"
#include "LaptopSave.h"
#include "Cursor_Control.h"
#include "MessageBoxScreen.h"
#include "WordWrap.h"
#include "Boxing.h"
#include "Video.h"
#include "Debug.h"
#include "JAScreens.h"
#include "ScreenIDs.h"


// DEFINES FOR VARIOUS PANELS
#define	SM_ITEMDESC_START_X					214
#define	SM_ITEMDESC_START_Y					1 + INV_INTERFACE_START_Y
#define	SM_ITEMDESC_HEIGHT					128
#define	SM_ITEMDESC_WIDTH					358

// SINGLE MERC SCREEN

#define SM_SELMERC_AP_X      67
#define SM_SELMERC_AP_Y      53
#define SM_SELMERC_AP_HEIGHT 10
#define SM_SELMERC_AP_WIDTH  17

#define SM_SELMERC_HEALTH_X 69
#define SM_SELMERC_HEALTH_Y 47

#define SM_SELMERCNAME_X      11
#define SM_SELMERCNAME_Y      53
#define SM_SELMERCNAME_WIDTH  53
#define SM_SELMERCNAME_HEIGHT 10

#define SM_SELMERC_FACE_X      13
#define SM_SELMERC_FACE_Y       6
#define SM_SELMERC_FACE_HEIGHT 42
#define SM_SELMERC_FACE_WIDTH  48

#define	SM_SELMERC_PLATE_X       4
#define	SM_SELMERC_PLATE_Y       2
#define	SM_SELMERC_PLATE_HEIGHT 65
#define	SM_SELMERC_PLATE_WIDTH  83


#define SM_BODYINV_X 244
#define SM_BODYINV_Y (INV_INTERFACE_START_Y + 6)


#define STATS_TITLE_FONT_COLOR				6
#define STATS_TEXT_FONT_COLOR					5


#define SM_TALKB_X       155
#define SM_TALKB_Y       108
#define SM_MUTEB_X        91
#define SM_MUTEB_Y       108
#define SM_STANCEUPB_X   187
#define SM_STANCEUPB_Y    40
#define SM_UPDOWNB_X      91
#define SM_UPDOWNB_Y      73
#define SM_CLIMBB_X      187
#define SM_CLIMBB_Y        8
#define SM_STANCEDOWNB_X 187
#define SM_STANCEDOWNB_Y 108
#define SM_HANDCURSORB_X 123
#define SM_HANDCURSORB_Y  73
#define SM_PREVMERCB_X     9
#define SM_PREVMERCB_Y    70
#define SM_NEXTMERCB_X    51
#define SM_NEXTMERCB_Y    70
#define SM_OPTIONSB_X      9
#define SM_OPTIONSB_Y    105
#define SM_BURSTMODEB_X  155
#define SM_BURSTMODEB_Y   73
#define SM_LOOKB_X       123
#define SM_LOOKB_Y       108
#define SM_STEALTHMODE_X 187
#define SM_STEALTHMODE_Y  73
#define SM_DONE_X        543
#define SM_DONE_Y          4
#define SM_MAPSCREEN_X   589
#define SM_MAPSCREEN_Y     4


#define SM_PERCENT_WIDTH    20
#define SM_PERCENT_HEIGHT   10
#define SM_ARMOR_X         347
#define SM_ARMOR_Y          79
#define SM_ARMOR_LABEL_X   363
#define SM_ARMOR_LABEL_Y    69
#define SM_ARMOR_PERCENT_X 368
#define SM_ARMOR_PERCENT_Y  79

#define SM_WEIGHT_LABEL_X   430
#define SM_WEIGHT_LABEL_Y   107
#define SM_WEIGHT_PERCENT_X 449
#define SM_WEIGHT_PERCENT_Y 106
#define SM_WEIGHT_X         428
#define SM_WEIGHT_Y         106

#define SM_CAMO_LABEL_X   430
#define SM_CAMO_LABEL_Y   122
#define SM_CAMO_PERCENT_X 449
#define SM_CAMO_PERCENT_Y 121
#define SM_CAMO_X         428
#define SM_CAMO_Y         121


#define SM_STATS_WIDTH   30
#define SM_STATS_HEIGHT   8
#define SM_AGI_X         99
#define SM_AGI_Y          7
#define SM_DEX_X         99
#define SM_DEX_Y         17
#define SM_STR_X         99
#define SM_STR_Y         27
#define SM_CHAR_X        99
#define SM_CHAR_Y        37
#define SM_WIS_X         99
#define SM_WIS_Y         47
#define SM_EXPLVL_X     148
#define SM_EXPLVL_Y       7
#define SM_MRKM_X       148
#define SM_MRKM_Y        17
#define SM_EXPL_X       148
#define SM_EXPL_Y        27
#define SM_MECH_X       148
#define SM_MECH_Y        37
#define SM_MED_X        148
#define SM_MED_Y         47

#define MONEY_X      460
#define MONEY_Y      105
#define MONEY_WIDTH   30
#define MONEY_HEIGHT  22

#define TM_FACE_X      14
#define TM_FACE_Y       6
#define TM_FACE_WIDTH  48
#define TM_FACE_HEIGHT 43

#define TM_ENDTURN_X    507
#define TM_ENDTURN_Y      9
#define TM_ROSTERMODE_X 507
#define TM_ROSTERMODE_Y  45
#define TM_DISK_X       507
#define TM_DISK_Y        81

#define TM_NAME_X      11
#define TM_NAME_Y      53
#define TM_NAME_WIDTH  53
#define TM_NAME_HEIGHT 10

#define TM_AP_X      67
#define TM_AP_Y      53
#define TM_AP_WIDTH  18
#define TM_AP_HEIGHT 10

#define TM_LIFEBAR_HEIGHT 42

#define TM_FACEHIGHTL_X        4
#define TM_FACEHIGHTL_Y        2
#define TM_FACEHIGHTL_WIDTH   84
#define TM_FACEHIGHTL_HEIGHT 114

#define TM_INV_WIDTH       58
#define TM_INV_HEIGHT      23
#define TM_INV_HAND1STARTX  8
#define TM_INV_HAND1STARTY 67
#define TM_INV_HAND_SEP    83
#define TM_INV_HAND_SEPY   24

#define TM_BARS_X      67
#define TM_BARS_Y       3
#define TM_BARS_WIDTH  19
#define TM_BARS_HEIGHT 47

#define INDICATOR_BOX_WIDTH  12
#define INDICATOR_BOX_HEIGHT 10


enum
{
	STANCEUP_IMAGES = 0,
	UPDOWN_IMAGES,
	CLIMB_IMAGES,
	STANCEDOWN_IMAGES,
	HANDCURSOR_IMAGES,
	PREVMERC_IMAGES,
	NEXTMERC_IMAGES,
	OPTIONS_IMAGES,
//BURSTMODE_IMAGES,
	LOOK_IMAGES,
	TALK_IMAGES,
	MUTE_IMAGES,
	STANCE_IMAGES,
	DONE_IMAGES,
	MAPSCREEN_IMAGES,
	NUM_SM_BUTTON_IMAGES
};



enum
{
	ENDTURN_IMAGES = 0,
	ROSTERMODE_IMAGES,
	DISK_IMAGES,
	NUM_TEAM_BUTTON_IMAGES
};


static BUTTON_PICS* iSMPanelImages[NUM_SM_BUTTON_IMAGES];
static BUTTON_PICS* iBurstButtonImages[NUM_WEAPON_MODES];
static BUTTON_PICS* iTEAMPanelImages[NUM_TEAM_BUTTON_IMAGES];

static BUTTON_PICS* giSMStealthImages;
INT32										giSMStealthButton = -1;

BOOLEAN									gfSwitchPanel = FALSE;
UINT8										gbNewPanel		= SM_PANEL;
SOLDIERTYPE* gNewPanelSoldier = NULL;

BOOLEAN									gfUIStanceDifferent = FALSE;
static BOOLEAN gfAllDisabled = FALSE;

BOOLEAN									gfSMDisableForItems = FALSE;

BOOLEAN									gfDisableTacticalPanelButtons = FALSE;

BOOLEAN	gfCheckForMouseOverItem = FALSE;
UINT32	guiMouseOverItemTime		= 0;
INT8		gbCheckForMouseOverItemPos = 0;
SOLDIERTYPE* gSelectSMPanelToMerc = NULL;
static BOOLEAN gfReEvaluateDisabledINVPanelButtons = FALSE;

SGPVObject* guiBrownBackgroundForTeamPanel;


UINT8 gubHandPos;
UINT16 gusOldItemIndex;
UINT16 gusNewItemIndex;
BOOLEAN gfDeductPoints;


// ARRAY FOR INV PANEL INTERFACE ITEM POSITIONS
static const INV_REGION_DESC gSMInvPocketXY[] =
{
	{ 344, INV_INTERFACE_START_Y +   6 }, // HELMETPOS
	{ 344, INV_INTERFACE_START_Y +  35 }, // VESTPOS
	{ 344, INV_INTERFACE_START_Y +  95 }, // LEGPOS,
	{ 226, INV_INTERFACE_START_Y +   6 }, // HEAD1POS
	{ 226, INV_INTERFACE_START_Y +  30 }, // HEAD2POS
	{ 226, INV_INTERFACE_START_Y +  84 }, // HANDPOS,
	{ 226, INV_INTERFACE_START_Y + 108 }, // SECONDHANDPOS
	{ 468, INV_INTERFACE_START_Y +   5 }, // BIGPOCK1
	{ 468, INV_INTERFACE_START_Y +  29 }, // BIGPOCK2
	{ 468, INV_INTERFACE_START_Y +  53 }, // BIGPOCK3
	{ 468, INV_INTERFACE_START_Y +  77 }, // BIGPOCK4
	{ 396, INV_INTERFACE_START_Y +   5 }, // SMALLPOCK1
	{ 396, INV_INTERFACE_START_Y +  29 }, // SMALLPOCK2
	{ 396, INV_INTERFACE_START_Y +  53 }, // SMALLPOCK3
	{ 396, INV_INTERFACE_START_Y +  77 }, // SMALLPOCK4
	{ 432, INV_INTERFACE_START_Y +   5 }, // SMALLPOCK5
	{ 432, INV_INTERFACE_START_Y +  29 }, // SMALLPOCK6
	{ 432, INV_INTERFACE_START_Y +  53 }, // SMALLPOCK7
	{ 432, INV_INTERFACE_START_Y +  77 }  // SMALLPOCK8
};

static const INV_REGION_DESC gSMCamoXY =
{
	SM_BODYINV_X, SM_BODYINV_Y // X, Y location of camo region
};


INT32					iSMPanelButtons[ NUM_SM_BUTTONS ];
INT32					iTEAMPanelButtons[ NUM_TEAM_BUTTONS ];

// Video Surface for Single Merc Panel
static SGPVObject* guiSMPanel;
static SGPVObject* guiSMObjects;
static SGPVObject* guiSMObjects2;
SGPVObject* guiSecItemHiddenVO;

static SGPVObject* guiTEAMPanel;
static SGPVObject* guiTEAMObjects;

// Globals for various mouse regions
static MOUSE_REGION gSM_SELMERCPanelRegion;
static MOUSE_REGION gSM_SELMERCBarsRegion;
MOUSE_REGION		gSM_SELMERCMoneyRegion;
static MOUSE_REGION gSM_SELMERCEnemyIndicatorRegion;
static MOUSE_REGION gTEAM_PanelRegion;
static MOUSE_REGION gTEAM_FaceRegions[NUM_TEAM_SLOTS];
static MOUSE_REGION gTEAM_BarsRegions[NUM_TEAM_SLOTS];
static MOUSE_REGION gTEAM_LeftBarsRegions[NUM_TEAM_SLOTS];
static MOUSE_REGION gTEAM_FirstHandInv[NUM_TEAM_SLOTS];
static MOUSE_REGION gTEAM_SecondHandInv[NUM_TEAM_SLOTS];
static MOUSE_REGION gTEAM_EnemyIndicator[NUM_TEAM_SLOTS];


// Globals - for one - the current merc here
SOLDIERTYPE			*gpSMCurrentMerc = NULL;

MOUSE_REGION gSMPanelRegion;


typedef struct TEAM_PANEL_SLOTS_TYPE
{
	SOLDIERTYPE* merc;
} TEAM_PANEL_SLOTS_TYPE;

static TEAM_PANEL_SLOTS_TYPE gTeamPanel[NUM_TEAM_SLOTS];


// Wraps up check for AP-s get from a different soldier for in a vehicle...
static INT8 GetUIApsToDisplay(const SOLDIERTYPE* s)
{
	if (s->uiStatusFlags & SOLDIER_DRIVER)
	{
		const SOLDIERTYPE* const v = GetSoldierStructureForVehicle(s->iVehicleId);
		return v == NULL ? 0 : v->bActionPoints;
	}
	else
	{
		return s->bActionPoints;
	}
}


void CheckForDisabledForGiveItem(void)
{
	const SOLDIERTYPE* const cur = gpSMCurrentMerc;
	Assert(cur != NULL);

	if (guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE)
	{
		gfSMDisableForItems = !CanMercInteractWithSelectedShopkeeper(cur);
		return;
	}

	// Default to true
	gfSMDisableForItems = TRUE;

	// ATE: Is the current merc unconscious.....
	if (cur->bLife < OKLIFE && gpItemPointer != NULL)
	{
		// Go through each merc and see if there is one closeby....
		CFOR_ALL_IN_TEAM(s, gbPlayerNum)
		{
			if (s->bLife >= OKLIFE && !(s->uiStatusFlags & SOLDIER_VEHICLE) && !AM_A_ROBOT(s) && s->bInSector && IsMercOnCurrentSquad(s))
			{
				const INT16 sDist        = PythSpacesAway(cur->sGridNo, s->sGridNo);
				const INT16 sDistVisible = DistanceVisible(s, DIRECTION_IRRELEVANT, DIRECTION_IRRELEVANT, cur->sGridNo, cur->bLevel);

				// Check LOS....
				if (SoldierTo3DLocationLineOfSightTest(s, cur->sGridNo, cur->bLevel, 3, sDistVisible, TRUE))
				{
					if (sDist <= PASSING_ITEM_DISTANCE_NOTOKLIFE)
					{
						gfSMDisableForItems = FALSE;
						break;	// found one, no need to keep looking
					}
				}
			}
		}
	}
	else
	{
		const SOLDIERTYPE* src = gpItemPointerSoldier;
		if (src == NULL)
		{
			src = GetSelectedMan();
			if (src == NULL)
			{
				gfSMDisableForItems = FALSE;
				return;
			}
		}

		// OK buddy, check our currently selected merc and disable/enable if not close enough...
		if (cur == src)
		{
			gfSMDisableForItems = FALSE;
			return;
		}

		const INT16 sDestGridNo = cur->sGridNo;
		const INT8  bDestLevel  = cur->bLevel;

		// Get distance....
		const INT16 sDist = PythSpacesAway(src->sGridNo, sDestGridNo);

		// is he close enough to see that gridno if he turns his head?
		const INT16 sDistVisible = DistanceVisible(src, DIRECTION_IRRELEVANT, DIRECTION_IRRELEVANT, sDestGridNo, bDestLevel);

		// Check LOS....
		if (SoldierTo3DLocationLineOfSightTest(src, sDestGridNo, bDestLevel, 3, sDistVisible, TRUE))
		{
			// UNCONSCIOUS GUYS ONLY 1 tile AWAY
			if (cur->bLife < CONSCIOUSNESS)
			{
				if (sDist <= PASSING_ITEM_DISTANCE_NOTOKLIFE)
				{
					gfSMDisableForItems = FALSE;
				}
			}
			else if (sDist <= PASSING_ITEM_DISTANCE_OKLIFE)
			{
				gfSMDisableForItems = FALSE;
			}
		}
	}
}


static void UpdateSMPanel(void);


void SetSMPanelCurrentMerc(SOLDIERTYPE* s)
{
	gSelectSMPanelToMerc = NULL;

	gpSMCurrentMerc = s;

	// Disable all faces
	SetAllAutoFacesInactive( );

	// Turn off compat ammo....
	if ( gpItemPointer == NULL )
	{
		HandleCompatibleAmmoUI(s, HANDPOS, FALSE);
		gfCheckForMouseOverItem = FALSE;
	}
	else
	{
		// Turn it all false first....
		InternalHandleCompatibleAmmoUI(s, gpItemPointer, FALSE);
		InternalHandleCompatibleAmmoUI(s, gpItemPointer, TRUE);
	}

	// Remove item desc panel if one up....
	if ( gfInItemDescBox )
	{
		DeleteItemDescriptionBox( );
	}

	if ( gfInItemPickupMenu )
	{
		gfSMDisableForItems = TRUE;
	}
	else
	{
		if (gpItemPointer != NULL || guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE || s->bLife < OKLIFE)
		{
			CheckForDisabledForGiveItem( );
		}
		else
		{
			gfSMDisableForItems = FALSE;
		}
	}

	if (gpItemPointer != NULL) ReevaluateItemHatches(s, FALSE);

	DisableInvRegions( gfSMDisableForItems );

	fInterfacePanelDirty = DIRTYLEVEL2;

	gfUIStanceDifferent = TRUE;

	UpdateSMPanel( );

}


static void HandleMouseOverSoldierFaceForContMove(SOLDIERTYPE* pSoldier, BOOLEAN fOn);
static BOOLEAN IsMouseInRegion(MOUSE_REGION* pRegion);


void UpdateForContOverPortrait( SOLDIERTYPE *pSoldier, BOOLEAN fOn )
{
	if ( gsCurInterfacePanel == SM_PANEL )
	{
		if ( gpSMCurrentMerc != NULL )
		{
			// Check if mouse is in region and if so, adjust...
			if ( IsMouseInRegion( &gSM_SELMERCPanelRegion ) )
			{
				HandleMouseOverSoldierFaceForContMove( gpSMCurrentMerc, fOn );
			}
		}
	}
	else
	{
		for (INT32 cnt = 0; cnt < NUM_TEAM_SLOTS; ++cnt)
		{
			if (gTeamPanel[cnt].merc == pSoldier &&
					IsMouseInRegion(&gTEAM_FaceRegions[cnt]))
			{
				HandleMouseOverSoldierFaceForContMove(pSoldier, fOn);
			}
		}
	}
}


static void SetButtonState(UINT idx, BOOLEAN clicked)
{
	GUI_BUTTON* const b = ButtonList[iSMPanelButtons[idx]];
	if (b->ubToggleButtonActivated) return;
	b->uiFlags &= ~BUTTON_CLICKED_ON;
	b->uiFlags |= (clicked ? BUTTON_CLICKED_ON : 0);
}


static void BtnStealthModeCallback(GUI_BUTTON* btn, INT32 reason);
static void CheckForReEvaluateDisabledINVPanelButtons(void);


static void UpdateSMPanel(void)
{
	BOOLEAN						fNearHeigherLevel;
	BOOLEAN						fNearLowerLevel;
	INT8							bDirection;
	UINT8							ubStanceState;

	if ( gpSMCurrentMerc->sGridNo == NOWHERE )
	{
		return;
	}

	// Stance
	ubStanceState = gpSMCurrentMerc->ubDesiredHeight;

	if ( ubStanceState == NO_DESIRED_HEIGHT )
	{
		ubStanceState = gAnimControl[ gpSMCurrentMerc->usAnimState ].ubEndHeight;
	}

	INT32 stance_gfx; // XXX HACK000E
	switch( ubStanceState )
	{
		case ANIM_STAND:
			stance_gfx = 11;
			DisableButton( iSMPanelButtons[ STANCEUP_BUTTON ] );
			EnableButton( iSMPanelButtons[ STANCEDOWN_BUTTON ] );

			// Disable if we cannot do this!
			if ( !IsValidStance( gpSMCurrentMerc, ANIM_CROUCH ) )
			{
				DisableButton( iSMPanelButtons[ STANCEDOWN_BUTTON ] );
			}
			break;

		case ANIM_PRONE:
			stance_gfx = 17;
			DisableButton( iSMPanelButtons[ STANCEDOWN_BUTTON ] );
			EnableButton( iSMPanelButtons[ STANCEUP_BUTTON ] );
			break;

		case ANIM_CROUCH:
			stance_gfx = 5;
			EnableButton( iSMPanelButtons[ STANCEUP_BUTTON ] );
			EnableButton( iSMPanelButtons[ STANCEDOWN_BUTTON ] );

			// Disable if we cannot do this!
			if ( !IsValidStance( gpSMCurrentMerc, ANIM_PRONE ) )
			{
				DisableButton( iSMPanelButtons[ STANCEDOWN_BUTTON ] );
			}
			break;

		default: abort(); // HACK000E
	}

	// Stance button done wether we're disabled or not...
	if ( gfUIStanceDifferent )
	{
		//Remove old
		if (giSMStealthButton != -1)   RemoveButton(giSMStealthButton);
		if (giSMStealthImages != NULL) UnloadButtonImage(giSMStealthImages);

		// Make new
		if (!gpSMCurrentMerc->bStealthMode) stance_gfx += 3;
		giSMStealthImages = UseLoadedButtonImage(iSMPanelImages[STANCE_IMAGES], stance_gfx + 2, stance_gfx, -1, stance_gfx + 1, -1);
		const INT32 dy = INV_INTERFACE_START_Y;
		giSMStealthButton = QuickCreateButton(giSMStealthImages, SM_STEALTHMODE_X, dy + SM_STEALTHMODE_Y, MSYS_PRIORITY_HIGH - 1, BtnStealthModeCallback);
		SetButtonFastHelpText(giSMStealthButton, TacticalStr[TOGGLE_STEALTH_MODE_POPUPTEXT]);

		gfUIStanceDifferent = FALSE;

		if (gfAllDisabled) DisableButton(giSMStealthButton);
	}

	if ( gfAllDisabled )
	{
		return;
	}


	CheckForReEvaluateDisabledINVPanelButtons( );

	// Check for any newly added items we need.....
	if ( gpSMCurrentMerc->fCheckForNewlyAddedItems )
	{
		// Startup any newly added items....
		CheckForAnyNewlyAddedItems( gpSMCurrentMerc );

		gpSMCurrentMerc->fCheckForNewlyAddedItems = FALSE;
	}

	// Set Disable /Enable UI based on buddy's stats
	GUI_BUTTON* const burst = ButtonList[iSMPanelButtons[BURSTMODE_BUTTON]];
	if (burst->image != iBurstButtonImages[gpSMCurrentMerc->bWeaponMode])
	{
		burst->image    = iBurstButtonImages[gpSMCurrentMerc->bWeaponMode];
		burst->uiFlags |= BUTTON_DIRTY;
	}

	/*
	SetButtonState(BURSTMODE_BUTTON, gpSMCurrentMerc->bDoBurst);
	*/

	// Toggle MUTE button...
	SetButtonState(MUTE_BUTTON, (gpSMCurrentMerc->uiStatusFlags & SOLDIER_MUTE) != 0);

	DisableButton( iSMPanelButtons[ CLIMB_BUTTON ] );

	GetMercClimbDirection(gpSMCurrentMerc, &fNearLowerLevel, &fNearHeigherLevel);

	if ( fNearLowerLevel || fNearHeigherLevel )
	{
		if ( fNearLowerLevel )
		{
			if ( EnoughPoints( gpSMCurrentMerc, GetAPsToClimbRoof( gpSMCurrentMerc, TRUE ), 0, FALSE ) )
			{
				EnableButton( iSMPanelButtons[ CLIMB_BUTTON ] );
			}
		}

		if ( fNearHeigherLevel )
		{
			if ( EnoughPoints( gpSMCurrentMerc, GetAPsToClimbRoof( gpSMCurrentMerc, FALSE ), 0, FALSE ) )
			{
				EnableButton( iSMPanelButtons[ CLIMB_BUTTON ] );
			}
		}
	}

	if ( FindFenceJumpDirection( gpSMCurrentMerc, gpSMCurrentMerc->sGridNo, gpSMCurrentMerc->bDirection, &bDirection ) )
	{
		EnableButton( iSMPanelButtons[ CLIMB_BUTTON ] );
	}

	if ( (gTacticalStatus.ubCurrentTeam != gbPlayerNum) || (gTacticalStatus.uiFlags & REALTIME ) || !(gTacticalStatus.uiFlags & INCOMBAT ) )
	{
		DisableButton( iSMPanelButtons[ SM_DONE_BUTTON ] );
	}
	else if ( !gfAllDisabled )
	{
		EnableButton( iSMPanelButtons[ SM_DONE_BUTTON ] );
	}

	SetButtonState(UPDOWN_BUTTON, gsInterfaceLevel > 0);

	SetButtonState(HANDCURSOR_BUTTON, gCurrentUIMode == HANDCURSOR_MODE);
	SetButtonState(TALK_BUTTON,       gCurrentUIMode == TALKCURSOR_MODE);
	SetButtonState(LOOK_BUTTON,       gCurrentUIMode == LOOKCURSOR_MODE);

	// If not selected ( or dead ), disable/gray some buttons
	if (gpSMCurrentMerc               != GetSelectedMan() ||
			gpSMCurrentMerc->bLife        <  OKLIFE           ||
			gTacticalStatus.ubCurrentTeam != gbPlayerNum      ||
			gfSMDisableForItems)
	{
		DisableButton( iSMPanelButtons[ CLIMB_BUTTON ] );
		DisableButton( iSMPanelButtons[ BURSTMODE_BUTTON ] );
		DisableButton( iSMPanelButtons[ STANCEUP_BUTTON ] );
		DisableButton( iSMPanelButtons[ STANCEDOWN_BUTTON ] );
		DisableButton( iSMPanelButtons[ LOOK_BUTTON ] );
		DisableButton( iSMPanelButtons[ UPDOWN_BUTTON ] );
		DisableButton( iSMPanelButtons[ HANDCURSOR_BUTTON ] );
		if ( giSMStealthButton != -1 )
		{
				DisableButton( giSMStealthButton );
		}
	}
	else
	{
		// Enable some buttons!
		if (IsGunBurstCapable(gpSMCurrentMerc, HANDPOS) || FindAttachment(&gpSMCurrentMerc->inv[HANDPOS], UNDER_GLAUNCHER) != ITEM_NOT_FOUND)
		{
			EnableButton( iSMPanelButtons[ BURSTMODE_BUTTON ] );
		}
		else
		{
			DisableButton( iSMPanelButtons[ BURSTMODE_BUTTON ] );
		}
		EnableButton( iSMPanelButtons[ LOOK_BUTTON ] );
		EnableButton( iSMPanelButtons[ UPDOWN_BUTTON ] );
		EnableButton( iSMPanelButtons[ HANDCURSOR_BUTTON ] );

		if ( giSMStealthButton != -1 )
		{
				EnableButton( giSMStealthButton );
		}
	}

	// CJC Dec 4 2002: or if item pickup menu is up
	if ( (gTacticalStatus.uiFlags & ENGAGED_IN_CONV) || gfInItemPickupMenu)
	{
		DisableButton( iSMPanelButtons[ SM_MAP_SCREEN_BUTTON ] );
	}
	else
	{
		EnableButton( iSMPanelButtons[ SM_MAP_SCREEN_BUTTON ] );
	}
}


void ReevaluateItemHatches(SOLDIERTYPE* pSoldier, BOOLEAN fAllValid)
{
	INT32	cnt;

	// if there's an item in the cursor and we're not supposed to just make them all valid
	if ( ( gpItemPointer != NULL ) && !fAllValid )
	{
		// check all inventory positions and mark the ones where cursor item won't fit as invalid
		for ( cnt = 0; cnt < NUM_INV_SLOTS; cnt++ )
		{
			gbInvalidPlacementSlot[ cnt ] = !CanItemFitInPosition( pSoldier, gpItemPointer, (INT8)cnt, FALSE );

			// !!! ATTACHING/MERGING ITEMS IN MAP SCREEN IS NOT SUPPORTED !!!
			// CJC: seems to be supported now...
			//if( guiCurrentScreen != MAP_SCREEN )
			{
				// Check attachments, override to valid placement if valid merge...
				if ( ValidAttachment( gpItemPointer->usItem, pSoldier->inv[ cnt ].usItem ) )
				{
					gbInvalidPlacementSlot[ cnt ] = FALSE;
				}

				if ( ValidMerge( gpItemPointer->usItem, pSoldier->inv[ cnt ].usItem ) )
				{
					gbInvalidPlacementSlot[ cnt ] = FALSE;
				}
			}
		}
	}
	else
	{
		// mark all inventory positions as valid
		for ( cnt = 0; cnt < NUM_INV_SLOTS; cnt++ )
		{
			gbInvalidPlacementSlot[ cnt ] = FALSE;
		}
	}

	fInterfacePanelDirty = DIRTYLEVEL2;
}


void EnableSMPanelButtons(BOOLEAN fEnable, BOOLEAN fFromItemPickup)
{
	if ( fFromItemPickup )
	{
		// If we have the item pointer up...
		// CJC Dec 4 2002: or if item pickup menu is up
		//if ( gpItemPointer != NULL )
		if ( gpItemPointer != NULL || gfInItemPickupMenu )
		{
			DisableTacticalTeamPanelButtons( TRUE );
		}
		else
		{
			DisableTacticalTeamPanelButtons( FALSE );
		}

		fInterfacePanelDirty = DIRTYLEVEL2;
	}


	if ( gsCurInterfacePanel == SM_PANEL )
	{
		if ( fFromItemPickup )
		{
			// If we have the item pointer up...
			if ( gpItemPointer != NULL )
			{
				ReevaluateItemHatches( gpSMCurrentMerc, fEnable );

				// Turn it all false first....
				InternalHandleCompatibleAmmoUI( gpSMCurrentMerc, gpItemPointer, FALSE );
				InternalHandleCompatibleAmmoUI( gpSMCurrentMerc, gpItemPointer, TRUE );

				gfCheckForMouseOverItem = FALSE;

				// Highlight guys ....
				HandleAnyMercInSquadHasCompatibleStuff(gpItemPointer);

			}
			else
			{
				//InternalHandleCompatibleAmmoUI( gpSMCurrentMerc, gpItemPointer, FALSE );
				gfCheckForMouseOverItem = FALSE;

				HandleAnyMercInSquadHasCompatibleStuff(NULL);
			}

			if ( fEnable )
			{
				ReevaluateItemHatches( gpSMCurrentMerc, fEnable );
			}

			fInterfacePanelDirty = DIRTYLEVEL2;
		}

		if ( fEnable )
		{
			// only enable the following if NOT in shopkeeper's interface
			if ( !(guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE ) )
			{
				EnableButton( iSMPanelButtons[ CLIMB_BUTTON ] );
				EnableButton( iSMPanelButtons[ BURSTMODE_BUTTON ] );
				EnableButton( iSMPanelButtons[ STANCEUP_BUTTON ] );
				EnableButton( iSMPanelButtons[ STANCEDOWN_BUTTON ] );
				EnableButton( iSMPanelButtons[ LOOK_BUTTON ] );
				EnableButton( iSMPanelButtons[ UPDOWN_BUTTON ] );
				EnableButton( iSMPanelButtons[ HANDCURSOR_BUTTON ] );
				if ( giSMStealthButton != -1 )
				{
					EnableButton( giSMStealthButton );
				}

				if ( gfDisableTacticalPanelButtons )
				{
					DisableButton( iSMPanelButtons[ OPTIONS_BUTTON ] );
					DisableButton( iSMPanelButtons[ SM_DONE_BUTTON ] );
					DisableButton( iSMPanelButtons[ SM_MAP_SCREEN_BUTTON ] );
				}
				else
				{
					EnableButton( iSMPanelButtons[ OPTIONS_BUTTON ] );
					EnableButton( iSMPanelButtons[ SM_DONE_BUTTON ] );
					EnableButton( iSMPanelButtons[ SM_MAP_SCREEN_BUTTON ] );
				}


				//enable the radar map region
				MSYS_EnableRegion(&gRadarRegion);

				gfSMDisableForItems = FALSE;

      	DisableInvRegions( gfSMDisableForItems );
			}

			if ( !fFromItemPickup )
			{
				EnableButton( iSMPanelButtons[ NEXTMERC_BUTTON ] );
				EnableButton( iSMPanelButtons[ PREVMERC_BUTTON ] );
			}
		}
		else
		{
			DisableButton( iSMPanelButtons[ CLIMB_BUTTON ] );
			DisableButton( iSMPanelButtons[ BURSTMODE_BUTTON ] );
			DisableButton( iSMPanelButtons[ STANCEUP_BUTTON ] );
			DisableButton( iSMPanelButtons[ STANCEDOWN_BUTTON ] );
			DisableButton( iSMPanelButtons[ LOOK_BUTTON ] );
			DisableButton( iSMPanelButtons[ UPDOWN_BUTTON ] );
			DisableButton( iSMPanelButtons[ HANDCURSOR_BUTTON ] );
			if ( giSMStealthButton != -1 )
			{
					DisableButton( giSMStealthButton );
			}

			if ( !fFromItemPickup )
			{
				DisableButton( iSMPanelButtons[ NEXTMERC_BUTTON ] );
				DisableButton( iSMPanelButtons[ PREVMERC_BUTTON ] );
			}

			DisableButton( iSMPanelButtons[ OPTIONS_BUTTON ] );
			DisableButton( iSMPanelButtons[ SM_DONE_BUTTON ] );
			DisableButton( iSMPanelButtons[ SM_MAP_SCREEN_BUTTON ] );

			//disable the radar map
			MSYS_DisableRegion(&gRadarRegion);
		}

		gfAllDisabled = !fEnable;

	}
}


static void InvPanelButtonClickCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void SMInvClickCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void SMInvClickCamoCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void SMInvMoneyButtonCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void SMInvMoveCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void SMInvMoveCamoCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void SelectedMercButtonCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void SelectedMercButtonMoveCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void SelectedMercEnemyIndicatorCallback(MOUSE_REGION* pRegion, INT32 iReason);


BOOLEAN InitializeSMPanel(void)
{
	// failing the CHECKF after this will cause you to lose your mouse
	guiSMPanel = AddVideoObjectFromFile("INTERFACE/inventory_bottom_panel.STI");
	CHECKF(guiSMPanel != NO_VOBJECT);
	guiSMObjects = AddVideoObjectFromFile("INTERFACE/inventory_gold_front.sti");
	CHECKF(guiSMObjects != NO_VOBJECT);
	guiSMObjects2 = AddVideoObjectFromFile("INTERFACE/inv_frn.sti");
	CHECKF(guiSMObjects2 != NO_VOBJECT);
	guiSecItemHiddenVO = AddVideoObjectFromFile("INTERFACE/secondary_gun_hidden.sti");
	CHECKF(guiSecItemHiddenVO != NO_VOBJECT);
	guiBrownBackgroundForTeamPanel = AddVideoObjectFromFile("INTERFACE/Bars.sti");
	CHECKF(guiBrownBackgroundForTeamPanel != NO_VOBJECT);

	// INit viewport region
	// Set global mouse regions
	// Define region for viewport
	MSYS_DefineRegion(&gViewportRegion, 0, 0, gsVIEWPORT_END_X, gsVIEWPORT_WINDOW_END_Y, MSYS_PRIORITY_NORMAL, VIDEO_NO_CURSOR, MSYS_NO_CALLBACK, MSYS_NO_CALLBACK);

	// Create buttons
	CHECKF(CreateSMPanelButtons());

	// Set viewports
	// Define region for panel
	MSYS_DefineRegion(&gSMPanelRegion, 0, INV_INTERFACE_START_Y, SCREEN_WIDTH, SCREEN_HEIGHT, MSYS_PRIORITY_NORMAL, CURSOR_NORMAL, MSYS_NO_CALLBACK, InvPanelButtonClickCallback);

	const INT32 dy = INV_INTERFACE_START_Y;

	INT32 x;
	INT32 y;

	x = SM_SELMERC_FACE_X;
	y = dy + SM_SELMERC_FACE_Y;

	//DEfine region for selected guy panel
	MSYS_DefineRegion(&gSM_SELMERCPanelRegion, x, y, x + SM_SELMERC_FACE_WIDTH, y + SM_SELMERC_FACE_HEIGHT, MSYS_PRIORITY_NORMAL, MSYS_NO_CURSOR, SelectedMercButtonMoveCallback, SelectedMercButtonCallback);

	//DEfine region for selected guy panel
	MSYS_DefineRegion(&gSM_SELMERCEnemyIndicatorRegion, x + 1, y + 1, x + INDICATOR_BOX_WIDTH, y + INDICATOR_BOX_HEIGHT, MSYS_PRIORITY_NORMAL, MSYS_NO_CURSOR, MSYS_NO_CALLBACK, SelectedMercEnemyIndicatorCallback);

	//DEfine region for money button
	x = MONEY_X;
	y = dy + MONEY_Y;
	MSYS_DefineRegion(&gSM_SELMERCMoneyRegion, x, y, x + MONEY_WIDTH, y + MONEY_HEIGHT, MSYS_PRIORITY_HIGH, MSYS_NO_CURSOR, MSYS_NO_CALLBACK, SMInvMoneyButtonCallback);
	SetRegionFastHelpText(&gSM_SELMERCMoneyRegion, TacticalStr[MONEY_BUTTON_HELP_TEXT]);

	// Check if mouse is in region and if so, adjust...
	if (IsMouseInRegion(&gSM_SELMERCPanelRegion))
	{
		HandleMouseOverSoldierFaceForContMove(gpSMCurrentMerc, TRUE);
	}

	//DEfine region for selected guy panel
	MSYS_DefineRegion(&gSM_SELMERCBarsRegion, 62, 342, 85, 391, MSYS_PRIORITY_NORMAL, MSYS_NO_CURSOR, MSYS_NO_CALLBACK, SelectedMercButtonCallback);

	InitInvSlotInterface(gSMInvPocketXY, &gSMCamoXY, SMInvMoveCallback, SMInvClickCallback, SMInvMoveCamoCallback, SMInvClickCamoCallback);
	InitKeyRingInterface(KeyRingItemPanelButtonCallback);

	// this is important! It will disable buttons like SM_MAP_SCREEN_BUTTON when they're supposed to be disabled - the previous
	// disabled state is lost everytime panel is reinitialized, because all the buttons are created from scratch!
	if (gpItemPointer == NULL)
	{
		// empty cursor - enable, not from item pickup
		EnableSMPanelButtons(TRUE, FALSE);
	}
	else
	{
		// full cursor - disable, from item pickup
		EnableSMPanelButtons(FALSE, TRUE);
	}

	return TRUE;
}


static BOOLEAN MakeButtonN(const UINT idx, BUTTON_PICS* const image, const INT16 x, const INT16 y, const GUI_CALLBACK click, const wchar_t* const help)
{
	INT32 btn = QuickCreateButtonToggle(image, x, y, MSYS_PRIORITY_HIGH - 1, click);
	iSMPanelButtons[idx] = btn;
	if (btn == -1)
	{
		DebugMsg(TOPIC_JA2, DBG_LEVEL_3, "Cannot create Interface button");
		return FALSE;
	}
	SetButtonFastHelpText(btn, help);
	return TRUE;
}


static BOOLEAN MakeButtonT(const UINT idx, BUTTON_PICS* const image, const INT16 x, const INT16 y, const GUI_CALLBACK click, const wchar_t* const help)
{
	INT32 btn = QuickCreateButton(image, x, y, MSYS_PRIORITY_HIGH - 1, click);
	iSMPanelButtons[idx] = btn;
	if (btn == -1)
	{
		DebugMsg(TOPIC_JA2, DBG_LEVEL_3, "Cannot create Interface button");
		return FALSE;
	}
	SetButtonFastHelpText(btn, help);
	return TRUE;
}


static void BtnBurstModeCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnClimbCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnHandCursorCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnLookCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnMapScreenCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnMuteCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnNextMercCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnOptionsCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnPrevMercCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnSMDoneCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnStanceDownCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnStanceUpCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnTalkCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnUpdownCallback(GUI_BUTTON* btn, INT32 reason);


BOOLEAN CreateSMPanelButtons(void)
{
	giSMStealthImages = NULL;
	giSMStealthButton = -1;
	gfUIStanceDifferent = TRUE;
	gfAllDisabled	= FALSE;

	// Load button Graphics
  iSMPanelImages[STANCEUP_IMAGES]   = LoadButtonImage("INTERFACE/inventory_buttons.sti", -1, 0, -1, 10, -1);

	iSMPanelImages[UPDOWN_IMAGES]     = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1,  9, -1, 19, -1);
	iSMPanelImages[CLIMB_IMAGES]      = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1,  3, -1, 13, -1);
	iSMPanelImages[STANCEDOWN_IMAGES] = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1,  8, -1, 18, -1);
	iSMPanelImages[HANDCURSOR_IMAGES] = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1,  1, -1, 11, -1);
	iSMPanelImages[PREVMERC_IMAGES]   = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1, 20, -1, 22, -1);
	iSMPanelImages[NEXTMERC_IMAGES]   = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1, 21, -1, 23, -1);
#if 0
	iSMPanelImages[BURSTMODE_IMAGES]  = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1,  7, -1, 17, -1);
#endif
	iSMPanelImages[LOOK_IMAGES]       = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1,  2, -1, 12, -1);
	iSMPanelImages[TALK_IMAGES]       = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1,  6, -1, 16, -1);
	iSMPanelImages[MUTE_IMAGES]       = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1,  5, -1, 15, -1);
	iSMPanelImages[OPTIONS_IMAGES]    = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1, 24, -1, 25, -1);

	iBurstButtonImages[WM_NORMAL]     = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1,  7, -1,  7, -1);
	iBurstButtonImages[WM_BURST]      = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1, 17, -1, 17, -1);
#ifndef JA2DEMO
	iBurstButtonImages[WM_ATTACHED]   = UseLoadedButtonImage(iSMPanelImages[STANCEUP_IMAGES], -1, 26, -1, 26, -1);
#endif

	iSMPanelImages[STANCE_IMAGES]     = LoadButtonImage("INTERFACE/invadd-ons.sti",            0,  0, -1,  2, -1);

	iSMPanelImages[DONE_IMAGES]       = LoadButtonImage("INTERFACE/inventory_buttons_2.sti",  -1,  1, -1,  3, -1);
	iSMPanelImages[MAPSCREEN_IMAGES]  = UseLoadedButtonImage(iSMPanelImages[DONE_IMAGES],     -1,  0, -1,  2, -1);


	// Create buttons

	// SET BUTTONS TO -1
	memset( iSMPanelButtons, -1, sizeof( iSMPanelButtons ) );

	const INT32 dy = INV_INTERFACE_START_Y;

	if (!MakeButtonT(SM_MAP_SCREEN_BUTTON, iSMPanelImages[MAPSCREEN_IMAGES],  SM_MAPSCREEN_X,   dy + SM_MAPSCREEN_Y,   BtnMapScreenCallback,  TacticalStr[MAPSCREEN_POPUPTEXT]))          return FALSE;
	if (!MakeButtonT(SM_DONE_BUTTON,       iSMPanelImages[DONE_IMAGES],       SM_DONE_X,        dy + SM_DONE_Y,        BtnSMDoneCallback,     TacticalStr[END_TURN_POPUPTEXT]))           return FALSE;
	if (!MakeButtonN(TALK_BUTTON,          iSMPanelImages[TALK_IMAGES],       SM_TALKB_X,       dy + SM_TALKB_Y,       BtnTalkCallback,       TacticalStr[TALK_CURSOR_POPUPTEXT]))        return FALSE;
	if (!MakeButtonN(MUTE_BUTTON,          iSMPanelImages[MUTE_IMAGES],       SM_MUTEB_X,       dy + SM_MUTEB_Y,       BtnMuteCallback,       TacticalStr[TOGGLE_MUTE_POPUPTEXT]))        return FALSE;
	if (!MakeButtonT(STANCEUP_BUTTON,      iSMPanelImages[STANCEUP_IMAGES],   SM_STANCEUPB_X,   dy + SM_STANCEUPB_Y,   BtnStanceUpCallback,   TacticalStr[CHANGE_STANCE_UP_POPUPTEXT]))   return FALSE;
	if (!MakeButtonN(UPDOWN_BUTTON,        iSMPanelImages[UPDOWN_IMAGES],     SM_UPDOWNB_X,     dy + SM_UPDOWNB_Y,     BtnUpdownCallback,     TacticalStr[CURSOR_LEVEL_POPUPTEXT]))       return FALSE;
	if (!MakeButtonT(CLIMB_BUTTON,         iSMPanelImages[CLIMB_IMAGES],      SM_CLIMBB_X,      dy + SM_CLIMBB_Y,      BtnClimbCallback,      TacticalStr[JUMPCLIMB_POPUPTEXT]))          return FALSE;
	if (!MakeButtonT(STANCEDOWN_BUTTON,    iSMPanelImages[STANCEDOWN_IMAGES], SM_STANCEDOWNB_X, dy + SM_STANCEDOWNB_Y, BtnStanceDownCallback, TacticalStr[CHANGE_STANCE_DOWN_POPUPTEXT])) return FALSE;
	if (!MakeButtonN(HANDCURSOR_BUTTON,    iSMPanelImages[HANDCURSOR_IMAGES], SM_HANDCURSORB_X, dy + SM_HANDCURSORB_Y, BtnHandCursorCallback, TacticalStr[EXAMINE_CURSOR_POPUPTEXT]))     return FALSE;
	if (!MakeButtonT(PREVMERC_BUTTON,      iSMPanelImages[PREVMERC_IMAGES],   SM_PREVMERCB_X,   dy + SM_PREVMERCB_Y,   BtnPrevMercCallback,   TacticalStr[PREV_MERC_POPUPTEXT]))          return FALSE;
	if (!MakeButtonT(NEXTMERC_BUTTON,      iSMPanelImages[NEXTMERC_IMAGES],   SM_NEXTMERCB_X,   dy + SM_NEXTMERCB_Y,   BtnNextMercCallback,   TacticalStr[NEXT_MERC_POPUPTEXT]))          return FALSE;
	if (!MakeButtonT(OPTIONS_BUTTON,       iSMPanelImages[OPTIONS_IMAGES],    SM_OPTIONSB_X,    dy + SM_OPTIONSB_Y,    BtnOptionsCallback,    TacticalStr[CHANGE_OPTIONS_POPUPTEXT]))     return FALSE;
#if 0
	if (!MakeButtonN(BURSTMODE_BUTTON,     iSMPanelImages[BURSTMODE_IMAGES],  SM_BURSTMODEB_X,  dy + SM_BURSTMODEB_Y,  BtnBurstModeCallback,  TacticalStr[TOGGLE_BURSTMODE_POPUPTEXT]))   return FALSE;
#endif
	if (!MakeButtonT(BURSTMODE_BUTTON,     iBurstButtonImages[WM_NORMAL],     SM_BURSTMODEB_X,  dy + SM_BURSTMODEB_Y,  BtnBurstModeCallback,  TacticalStr[TOGGLE_BURSTMODE_POPUPTEXT]))   return FALSE;
	if (!MakeButtonN(LOOK_BUTTON,          iSMPanelImages[LOOK_IMAGES],       SM_LOOKB_X,       dy + SM_LOOKB_Y,       BtnLookCallback,       TacticalStr[LOOK_CURSOR_POPUPTEXT]))        return FALSE;

	return TRUE;
}


void RemoveSMPanelButtons(void)
{
	for (UINT32 cnt = 0; cnt < NUM_SM_BUTTONS; ++cnt)
	{
		if (iSMPanelButtons[cnt] != -1) RemoveButton(iSMPanelButtons[cnt]);
	}

	for (UINT32 cnt = 0; cnt < NUM_SM_BUTTON_IMAGES; ++cnt)
	{
		UnloadButtonImage(iSMPanelImages[cnt]);
	}

	if (giSMStealthButton != -1)   RemoveButton(giSMStealthButton);
	if (giSMStealthImages != NULL) UnloadButtonImage(giSMStealthImages);

	UnloadButtonImage(iBurstButtonImages[WM_NORMAL]);
	UnloadButtonImage(iBurstButtonImages[WM_BURST]);
#ifndef JA2DEMO
	UnloadButtonImage(iBurstButtonImages[WM_ATTACHED]);
#endif
}


BOOLEAN ShutdownSMPanel(void)
{
	// All buttons and regions and video objects and video surfaces will be deleted at shutddown of SGM
	// We may want to delete them at the interm as well, to free up room for other panels
	DeleteVideoObject(guiSMPanel);
	DeleteVideoObject(guiSMObjects);
	DeleteVideoObject(guiSMObjects2);
	DeleteVideoObject(guiSecItemHiddenVO);
	DeleteVideoObject(guiBrownBackgroundForTeamPanel);

	gSelectSMPanelToMerc = NULL;

	// CJC: delete key ring if open
	DeleteKeyRingPopup(); // function will abort if key ring is not up

	// ATE: Delete desc panel if it was open....
	if (gfInItemDescBox)
	{
		DeleteItemDescriptionBox();
	}

	ShutdownInvSlotInterface();
	ShutdownKeyRingInterface();

	MSYS_RemoveRegion(&gSMPanelRegion);
	MSYS_RemoveRegion(&gSM_SELMERCPanelRegion);
	MSYS_RemoveRegion(&gSM_SELMERCBarsRegion);
	MSYS_RemoveRegion(&gSM_SELMERCMoneyRegion);
	MSYS_RemoveRegion(&gSM_SELMERCEnemyIndicatorRegion);

	HandleMouseOverSoldierFaceForContMove(gpSMCurrentMerc, FALSE);

	MSYS_RemoveRegion(&gViewportRegion);

	RemoveSMPanelButtons();

	return TRUE;
}


static void PrintAP(SOLDIERTYPE* s, INT16 x, INT16 y, INT16 w, INT16 h)
{
	if (!(gTacticalStatus.uiFlags & TURNBASED) ||
			!(gTacticalStatus.uiFlags & INCOMBAT) ||
			s->bLife < OKLIFE)
	{
		return;
	}

	SetFont(TINYFONT1);

	const INT8 ap = GetUIApsToDisplay(s);

	if (!EnoughPoints(s, MinAPsToAttack(s, s->sLastTarget, TRUE), 0, FALSE) || ap < 0)
	{
		SetFontForeground(FONT_MCOLOR_DKRED);
	}
	else
	{
		if (MercUnderTheInfluence(s))
		{
			SetFontForeground(FONT_MCOLOR_LTBLUE);
		}
		else if (s->bStealthMode)
		{
			SetFontForeground(FONT_MCOLOR_LTYELLOW);
		}
		else
		{
			SetFontForeground(FONT_MCOLOR_LTGRAY);
		}
	}
	SetFontBackground(FONT_MCOLOR_BLACK);

	RestoreExternBackgroundRect(x, y, w, h);
	wchar_t buf[16];
	swprintf(buf, lengthof(buf), L"%d", ap);
	INT16 sFontX;
	INT16 sFontY;
	FindFontCenterCoordinates(x, y, w, h, buf, TINYFONT1, &sFontX, &sFontY);
	mprintf(sFontX, sFontY, buf);
}


static void SetStatsHelp(MOUSE_REGION* r, const SOLDIERTYPE* s)
{
	if (s->bLife != 0)
	{
		wchar_t text[200];
		if (s->uiStatusFlags & SOLDIER_VEHICLE)
		{
			swprintf(text, lengthof(text), TacticalStr[VEHICLE_VITAL_STATS_POPUPTEXT], s->bLife, s->bLifeMax, s->bBreath, s->bBreathMax);
		}
		else if (s->uiStatusFlags & SOLDIER_ROBOT)
		{
			swprintf(text, lengthof(text), gzLateLocalizedString[16], s->bLife, s->bLifeMax);
		}
		else
		{
			const wchar_t* Morale = GetMoraleString(s);
			swprintf(text, lengthof(text), TacticalStr[MERC_VITAL_STATS_POPUPTEXT], s->bLife, s->bLifeMax, s->bBreath, s->bBreathMax, Morale);
		}
		SetRegionFastHelpText(r, text);
	}
	else
	{
		SetRegionFastHelpText(r, L"");
	}
}


static void UpdateStatColor(UINT32 uiTimer, BOOLEAN fIncrease);


static void PrintStat(UINT32 change_time, UINT16 stat_bit, INT8 stat_val, INT16 x, INT16 y)
{
	UpdateStatColor(change_time, (gpSMCurrentMerc->usValueGoneUp & stat_bit) != 0);
	wchar_t str[9];
	swprintf(str, lengthof(str), L"%2d", stat_val);
	INT16 usX;
	INT16 usY;
	FindFontRightCoordinates(x, y, SM_STATS_WIDTH, SM_STATS_HEIGHT, str, BLOCKFONT2, &usX, &usY);
	mprintf(usX, usY, str);
}


void RenderSMPanel(BOOLEAN* pfDirty)
{
	wchar_t sString[9];
	UINT32	cnt;

	// Give him the panel!
	if (gSelectSMPanelToMerc != NULL) SetSMPanelCurrentMerc(gSelectSMPanelToMerc);

	// ATE: Don't do anything if we are in stack popup and are refreshing stuff....
	if ( ( InItemStackPopup( ) || ( InKeyRingPopup( ) ) ) && (*pfDirty) == DIRTYLEVEL1 )
	{
		return;
	}

	if ( gfCheckForMouseOverItem )
	{
		if ( ( GetJA2Clock( ) - guiMouseOverItemTime ) > 100 )
		{
			if ( HandleCompatibleAmmoUI( gpSMCurrentMerc, (INT8)gbCheckForMouseOverItemPos, TRUE ) )
			{
				(*pfDirty) = DIRTYLEVEL2;
			}

			gfCheckForMouseOverItem = FALSE;
		}
	}

	HandleNewlyAddedItems( gpSMCurrentMerc, pfDirty );

	if ( InItemDescriptionBox( ) )
	{
		HandleItemDescriptionBox( pfDirty );
	}

	const INT32 dy = INV_INTERFACE_START_Y;

	if ( *pfDirty == DIRTYLEVEL2 )
	{
		BltVideoObject(guiSAVEBUFFER, guiSMPanel, 0, INTERFACE_START_X, dy);

		if (gfSMDisableForItems)
		{
			const INT32 x = SM_SELMERC_PLATE_X;
			const INT32 y = dy + SM_SELMERC_PLATE_Y;
			BltVideoObject(guiSAVEBUFFER, guiSMObjects2, 0, x, y);
			RestoreExternBackgroundRect(x, y, SM_SELMERC_PLATE_WIDTH, SM_SELMERC_PLATE_HEIGHT);
		}
		else if (gTacticalStatus.ubCurrentTeam == OUR_TEAM &&
				gpSMCurrentMerc == GetSelectedMan()            &&
				OK_INTERRUPT_MERC(gpSMCurrentMerc))
		{
			const INT32 x = SM_SELMERC_PLATE_X;
			const INT32 y = dy + SM_SELMERC_PLATE_Y;
			BltVideoObject(guiSAVEBUFFER, guiSMObjects, 0, x, y);
			RestoreExternBackgroundRect(x, y, SM_SELMERC_PLATE_WIDTH, SM_SELMERC_PLATE_HEIGHT);
		}

		RenderSoldierFace(gpSMCurrentMerc, SM_SELMERC_FACE_X, dy + SM_SELMERC_FACE_Y);

		if (InItemDescriptionBox())
		{
			RenderItemDescriptionBox();
		}
		else
		{
			RenderInvBodyPanel(gpSMCurrentMerc, SM_BODYINV_X, SM_BODYINV_Y);

			SetFont( BLOCKFONT2 );

			// Render Values for stats!
			// Set font drawing to saved buffer
			SetFontDestBuffer(guiSAVEBUFFER, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

			SetFontBackground( FONT_MCOLOR_BLACK );
			SetFontForeground( STATS_TITLE_FONT_COLOR );
			for( cnt = 0; cnt < 5; cnt++ )
			{
				const INT32 y = dy + 7 + cnt * 10;
				mprintf( 92, y, pShortAttributeStrings[cnt]);
				mprintf(137, y, pShortAttributeStrings[cnt + 5]);
			}

			mprintf(SM_ARMOR_LABEL_X - StringPixLength(pInvPanelTitleStrings[0], BLOCKFONT2) / 2, dy + SM_ARMOR_LABEL_Y, pInvPanelTitleStrings[0]);
			mprintf(SM_ARMOR_PERCENT_X, dy + SM_ARMOR_PERCENT_Y, L"%%");

			mprintf(SM_WEIGHT_LABEL_X - StringPixLength(pInvPanelTitleStrings[1], BLOCKFONT2), dy + SM_WEIGHT_LABEL_Y, pInvPanelTitleStrings[1]);
			mprintf(SM_WEIGHT_PERCENT_X, dy + SM_WEIGHT_PERCENT_Y, L"%%");

			mprintf(SM_CAMO_LABEL_X - StringPixLength(pInvPanelTitleStrings[2], BLOCKFONT2), dy + SM_CAMO_LABEL_Y, pInvPanelTitleStrings[2]);
			mprintf(SM_CAMO_PERCENT_X, dy + SM_CAMO_PERCENT_Y, L"%%");

			const SOLDIERTYPE* const s = gpSMCurrentMerc;
			PrintStat(s->uiChangeAgilityTime,      AGIL_INCREASE,     s->bAgility,      SM_AGI_X,    dy + SM_AGI_Y);
			PrintStat(s->uiChangeDexterityTime,    DEX_INCREASE,      s->bDexterity,    SM_DEX_X,    dy + SM_DEX_Y);
			PrintStat(s->uiChangeStrengthTime,     STRENGTH_INCREASE, s->bStrength,     SM_STR_X,    dy + SM_STR_Y);
			PrintStat(s->uiChangeLeadershipTime,   LDR_INCREASE,      s->bLeadership,   SM_CHAR_X,   dy + SM_CHAR_Y);
			PrintStat(s->uiChangeWisdomTime,       WIS_INCREASE,      s->bWisdom,       SM_WIS_X,    dy + SM_WIS_Y);
			PrintStat(s->uiChangeLevelTime,        LVL_INCREASE,      s->bExpLevel,     SM_EXPLVL_X, dy + SM_EXPLVL_Y);
			PrintStat(s->uiChangeMarksmanshipTime, MRK_INCREASE,      s->bMarksmanship, SM_MRKM_X,   dy + SM_MRKM_Y);
			PrintStat(s->uiChangeExplosivesTime,   EXP_INCREASE,      s->bExplosive,    SM_EXPL_X,   dy + SM_EXPL_Y);
			PrintStat(s->uiChangeMechanicalTime,   MECH_INCREASE,     s->bMechanical,   SM_MECH_X,   dy + SM_MECH_Y);
			PrintStat(s->uiChangeMedicalTime,      MED_INCREASE,      s->bMedical,      SM_MED_X,    dy + SM_MED_Y);

			if ( gpSMCurrentMerc->bLife >= OKLIFE )
			{
				SetFontForeground(STATS_TEXT_FONT_COLOR);
			}
			else
			{
				SetFontForeground(FONT_MCOLOR_DKGRAY);
			}
			SetFontBackground(FONT_MCOLOR_BLACK);

			INT16 usX;
			INT16 usY;

			// Display armour value!
			swprintf( sString, lengthof(sString), L"%3d", ArmourPercent( gpSMCurrentMerc ) );
			FindFontRightCoordinates(SM_ARMOR_X, dy + SM_ARMOR_Y, SM_PERCENT_WIDTH, SM_PERCENT_HEIGHT, sString, BLOCKFONT2, &usX, &usY);
			mprintf( usX, usY , sString );

			// Display wieght value!
			swprintf( sString, lengthof(sString), L"%3d", CalculateCarriedWeight( gpSMCurrentMerc ) );
			FindFontRightCoordinates(SM_WEIGHT_X, dy + SM_WEIGHT_Y, SM_PERCENT_WIDTH, SM_PERCENT_HEIGHT, sString, BLOCKFONT2, &usX, &usY);
			mprintf( usX, usY , sString );

			// Display camo value!
			swprintf( sString, lengthof(sString), L"%3d", gpSMCurrentMerc->bCamo );
			FindFontRightCoordinates(SM_CAMO_X, dy + SM_CAMO_Y, SM_PERCENT_WIDTH, SM_PERCENT_HEIGHT, sString, BLOCKFONT2, &usX, &usY);
			mprintf( usX, usY , sString );


			// reset to frame buffer!
			SetFontDestBuffer(FRAME_BUFFER, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

			RestoreExternBackgroundRect(INTERFACE_START_X, INV_INTERFACE_START_Y, SCREEN_WIDTH - INTERFACE_START_X, SCREEN_HEIGHT - INV_INTERFACE_START_Y);
		}

		// Render Name!
		SetFont( BLOCKFONT2 );

		if ( gpSMCurrentMerc->bStealthMode )
		{
			SetFontForeground(FONT_MCOLOR_LTYELLOW);
		}
		else
		{
			SetFontForeground(FONT_MCOLOR_LTGRAY);
		}
		SetFontBackground(FONT_MCOLOR_BLACK);

		const INT32 x = SM_SELMERCNAME_X;
		const INT32 y = dy + SM_SELMERCNAME_Y;
		const INT32 w = SM_SELMERCNAME_WIDTH;
		const INT32 h = SM_SELMERCNAME_HEIGHT;
		RestoreExternBackgroundRect(x, y, w, h);
		INT16 sFontX;
		INT16 sFontY;
		FindFontCenterCoordinates(x, y, w, h, gpSMCurrentMerc->name, BLOCKFONT2, &sFontX, &sFontY);
		mprintf(sFontX, sFontY, L"%ls", gpSMCurrentMerc->name);
	}

	if (*pfDirty != DIRTYLEVEL0)
	{
		SetStatsHelp(&gSM_SELMERCBarsRegion, gpSMCurrentMerc);

		// display AP
		if (!(gpSMCurrentMerc->uiStatusFlags & SOLDIER_DEAD))
		{
			PrintAP(gpSMCurrentMerc, SM_SELMERC_AP_X, dy + SM_SELMERC_AP_Y, SM_SELMERC_AP_WIDTH, SM_SELMERC_AP_HEIGHT);
			DrawSoldierUIBars(gpSMCurrentMerc, SM_SELMERC_HEALTH_X, dy + SM_SELMERC_HEALTH_Y, TRUE, FRAME_BUFFER);
		}
	}

	UpdateSMPanel( );


	//HandlePanelFaceAnimations( gpSMCurrentMerc );

	// Render items in guy's hand!
	HandleRenderInvSlots( gpSMCurrentMerc, *pfDirty );

	if ( gfSMDisableForItems && (*pfDirty) != DIRTYLEVEL0 )
	{
		SGPRect ClipRect;

		ClipRect.iLeft	 = 87;
		ClipRect.iRight  = 536;
		ClipRect.iTop		 = INV_INTERFACE_START_Y;
		ClipRect.iBottom = SCREEN_HEIGHT;
		SGPVSurface::Lock l(FRAME_BUFFER);
		Blt16BPPBufferHatchRect(l.Buffer<UINT16>(), l.Pitch(), &ClipRect);
	}

}


static void UpdateStatColor(UINT32 uiTimer, BOOLEAN fIncrease)
{
	if ( gpSMCurrentMerc->bLife >= OKLIFE )
	{
		if( ( GetJA2Clock()  < CHANGE_STAT_RECENTLY_DURATION + uiTimer) && ( uiTimer != 0 ) )
		{
			if( fIncrease )
			{
				SetFontForeground( FONT_LTGREEN );
			}
			else
			{
				SetFontForeground( FONT_RED );
			}
		}
		else
		{
			SetFontBackground( FONT_MCOLOR_BLACK );
			SetFontForeground( STATS_TEXT_FONT_COLOR );
		}
	}
	else
	{
		SetFontBackground( FONT_MCOLOR_BLACK );
		SetFontForeground( FONT_MCOLOR_DKGRAY );
	}
}


static void SMInvMoveCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	UINT32 uiHandPos;

	uiHandPos = MSYS_GetRegionUserData( pRegion, 0 );

	if ( gpSMCurrentMerc->inv[ uiHandPos ].usItem == NOTHING )
		return;

	if (iReason == MSYS_CALLBACK_REASON_GAIN_MOUSE)
	{
		if ( gpItemPointer == NULL )
		{
			// Setup a timer....
			guiMouseOverItemTime = GetJA2Clock( );
			gfCheckForMouseOverItem = TRUE;
			gbCheckForMouseOverItemPos = (INT8)uiHandPos;
		}
	}
	if (iReason == MSYS_CALLBACK_REASON_LOST_MOUSE )
	{
		if ( gpItemPointer == NULL )
		{
			HandleCompatibleAmmoUI( gpSMCurrentMerc, (INT8)uiHandPos, FALSE );
			gfCheckForMouseOverItem = FALSE;
			fInterfacePanelDirty		= DIRTYLEVEL2;
		}
	}
}


static void InvPanelButtonClickCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
}


static void SMInvMoveCamoCallback(MOUSE_REGION* const pRegion, const INT32 iReason)
{
	if (iReason == MSYS_CALLBACK_REASON_GAIN_MOUSE )
	{
		// Setup a timer....
		guiMouseOverItemTime = GetJA2Clock( );
		gfCheckForMouseOverItem = TRUE;
		gbCheckForMouseOverItemPos = NO_SLOT;
	}
	if (iReason == MSYS_CALLBACK_REASON_LOST_MOUSE )
	{
		HandleCompatibleAmmoUI( gpSMCurrentMerc, (INT8)NO_SLOT, FALSE );
		gfCheckForMouseOverItem = FALSE;
	}
}


static void SMInvClickCamoCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_DWN)
	{
		// Apply camo (if we have something in cursor...)
		// If we do not have an item in hand, start moving it
		OBJECTTYPE* const obj = gpItemPointer;
		if (obj == NULL) return;

		SOLDIERTYPE* const s = gpSMCurrentMerc;
		if (s->bLife < CONSCIOUSNESS) return;

		BOOLEAN fGoodAPs;
		// Try to apply camo....
		if (ApplyCamo(s, obj, &fGoodAPs))
		{
			if (!fGoodAPs) return;

			// Say OK acknowledge....
			DoMercBattleSound(s, BATTLE_SOUND_COOL1);
		}
		else if (ApplyCanteen(s, obj, &fGoodAPs))
		{
			if (!fGoodAPs) return;
		}
		else if (ApplyElixir(s, obj, &fGoodAPs))
		{
			if (!fGoodAPs) return;

			// Say OK acknowledge....
			DoMercBattleSound(s, BATTLE_SOUND_COOL1);
		}
		else if (ApplyDrugs(s, obj))
		{
			// Say OK acknowledge....
			DoMercBattleSound(s, BATTLE_SOUND_COOL1);
		}
		else
		{
			ScreenMsg(FONT_MCOLOR_LTYELLOW, MSG_UI_FEEDBACK, TacticalStr[CANNOT_DO_INV_STUFF_STR]);
			return;
		}

		fInterfacePanelDirty = DIRTYLEVEL2;

		// Check if it's the same now!
		if (obj->ubNumberOfObjects == 0)
		{
			gbCompatibleApplyItem = FALSE;
			EndItemPointer();
		}
	}
}


BOOLEAN HandleNailsVestFetish(const SOLDIERTYPE* const s, const UINT32 uiHandPos, const UINT16 usReplaceItem)
{
	if (s->ubProfile != NAILS) return FALSE;
	if (uiHandPos != VESTPOS)  return FALSE;

	switch (usReplaceItem)
	{
		case LEATHER_JACKET:
		case LEATHER_JACKET_W_KEVLAR:
		case LEATHER_JACKET_W_KEVLAR_18:
		case LEATHER_JACKET_W_KEVLAR_Y:
		case COMPOUND18:
		case JAR_QUEEN_CREATURE_BLOOD:
			return FALSE;

		default:
			TacticalCharacterDialogue(s, 61);
			return TRUE;
	}
}


static BOOLEAN UIHandleItemPlacement(UINT8 ubHandPos, UINT16 usOldItemIndex, UINT16 usNewItemIndex, BOOLEAN fDeductPoints)
{
	if ( _KeyDown(CTRL) )
	{
		CleanUpStack( &( gpSMCurrentMerc->inv[ ubHandPos ] ), gpItemPointer );
		if ( gpItemPointer->ubNumberOfObjects == 0 )
		{
			EndItemPointer( );
		}
		return( TRUE );
	}

	// Try to place here
	if ( PlaceObject( gpSMCurrentMerc, ubHandPos, gpItemPointer ) )
	{
		if ( fDeductPoints )
		{
			// Deduct points
			if ( gpItemPointerSoldier->bLife >= CONSCIOUSNESS )
			{
				DeductPoints( gpItemPointerSoldier,  2, 0 );
			}
			if ( gpSMCurrentMerc->bLife >= CONSCIOUSNESS )
			{
				DeductPoints( gpSMCurrentMerc,  2, 0 );
			}
		}

		HandleTacticalEffectsOfEquipmentChange( gpSMCurrentMerc, ubHandPos, usOldItemIndex, usNewItemIndex );

		// Dirty
		fInterfacePanelDirty = DIRTYLEVEL2;

		// Check if cursor is empty now
		if ( gpItemPointer->ubNumberOfObjects == 0 )
		{
			EndItemPointer( );
		}

		if ( gpItemPointerSoldier != gpSMCurrentMerc )
		{
			ScreenMsg( FONT_MCOLOR_LTYELLOW, MSG_INTERFACE, pMessageStrings[ MSG_ITEM_PASSED_TO_MERC ], ShortItemNames[ usNewItemIndex ], gpSMCurrentMerc->name );
		}

		// UPDATE ITEM POINTER.....
		gpItemPointerSoldier = gpSMCurrentMerc;

		if ( gpItemPointer != NULL )
		{
			ReevaluateItemHatches( gpSMCurrentMerc, FALSE );
		}

		// Set cursor back to normal mode...
		guiPendingOverrideEvent = A_CHANGE_TO_MOVE;

		return( TRUE );

	}
	else
	{
		return( FALSE );
	}

}


static void MergeMessageBoxCallBack(UINT8 ubExitValue);


static void SMInvClickCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	UINT32 uiHandPos;
	// Copyies of values
	UINT16 usOldItemIndex, usNewItemIndex;
	UINT16 usItemPrevInItemPointer;
	BOOLEAN fNewItem = FALSE;
	static BOOLEAN	fRightDown = FALSE;
	static BOOLEAN	fLeftDown = FALSE;


	uiHandPos = MSYS_GetRegionUserData( pRegion, 0 );

	if ( (guiTacticalInterfaceFlags & INTERFACE_MAPSCREEN ) )
	{
		return;
	}

	//if we are in the shop keeper interface
	if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
	{
		// and this inventory slot is hatched out
		if( ShouldSoldierDisplayHatchOnItem( gpSMCurrentMerc->ubProfile, (INT16)uiHandPos ) )
		{
			// it means that item is a copy of one in the player's offer area, so we treat it as if the slot was empty (ignore)
			// if the cursor has an item in it, we still ignore the click, because handling swaps in this situation would be
			// ugly, we'd have to the the swap, then make the bOwnerSlot of the item just picked up a -1 in its offer area spot.
			return;
		}
	}


	//if (iReason & MSYS_CALLBACK_REASON_LBUTTON_DWN )
	//{
	//	fLeftDown = TRUE;
	//}
	//else if (iReason & MSYS_CALLBACK_REASON_LBUTTON_UP && fLeftDown )
	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_DWN )
	{
		fLeftDown = FALSE;

		// If we do not have an item in hand, start moving it
		if ( gpItemPointer == NULL )
		{

			// Return if empty
			if ( gpSMCurrentMerc->inv[ uiHandPos ].usItem == NOTHING )
				return;

			SelectSoldier(gpSMCurrentMerc, SELSOLDIER_NONE);

			// OK, check if this is Nails, and we're in the vest position , don't allow it to come off....
			if ( HandleNailsVestFetish( gpSMCurrentMerc, uiHandPos, NOTHING ) )
			{
				return;
			}

			if ( _KeyDown(CTRL) )
			{
				CleanUpStack( &( gpSMCurrentMerc->inv[ uiHandPos ] ), NULL );
				return;
			}

			// Turn off new item glow!
			gpSMCurrentMerc->bNewItemCount[ uiHandPos ] = 0;

			usOldItemIndex = gpSMCurrentMerc->inv[ uiHandPos ].usItem;

			// move item into the mouse cursor
			BeginItemPointer( gpSMCurrentMerc, (UINT8)uiHandPos );

			//if we are in the shopkeeper interface
			if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
			{
				// pick up item from regular inventory slot into cursor OR try to sell it ( unless CTRL is held down )
				BeginSkiItemPointer( PLAYERS_INVENTORY, ( INT8 ) uiHandPos, ( BOOLEAN )!gfKeyState[ CTRL ] );
			}

			HandleTacticalEffectsOfEquipmentChange( gpSMCurrentMerc, uiHandPos, usOldItemIndex, NOTHING );

			// HandleCompatibleAmmoUI( gpSMCurrentMerc, (INT8)uiHandPos, FALSE );
		}
		else	// item in cursor
		{
			BOOLEAN		fOKToGo = FALSE;
			BOOLEAN		fDeductPoints = FALSE;

			// ATE: OK, get source, dest guy if different... check for and then charge appropriate APs
			if (gpSMCurrentMerc == gpItemPointerSoldier)
			{
				// We are doing this ourselve, continue
				fOKToGo = TRUE;
			}
			else
			{
				// These guys are different....
				fDeductPoints = TRUE;

				// First check points for src guy
				if ( gpItemPointerSoldier->bLife >= CONSCIOUSNESS )
				{
					if ( EnoughPoints( gpItemPointerSoldier, 3, 0, TRUE ) )
					{
						fOKToGo = TRUE;
					}
				}
				else
				{
					fOKToGo = TRUE;
				}

				// Should we go on?
				if ( fOKToGo )
				{
					if ( gpSMCurrentMerc->bLife >= CONSCIOUSNESS )
					{
						if ( EnoughPoints( gpSMCurrentMerc, 3, 0, TRUE ) )
						{
							fOKToGo = TRUE;
						}
						else
						{
							fOKToGo = FALSE;
						}
					}
				}
			}

			if ( fOKToGo )
			{
				// OK, check if this is Nails, and we're in the vest position , don't allow it to come off....
				if ( HandleNailsVestFetish( gpSMCurrentMerc, uiHandPos, gpItemPointer->usItem ) )
				{
					return;
				}

				usOldItemIndex = gpSMCurrentMerc->inv[ uiHandPos ].usItem;
				usNewItemIndex = gpItemPointer->usItem;

				if ( uiHandPos == HANDPOS || uiHandPos == SECONDHANDPOS || uiHandPos == HELMETPOS || uiHandPos == VESTPOS || uiHandPos == LEGPOS )
				{
					//if ( ValidAttachmentClass( usNewItemIndex, usOldItemIndex ) )
					if ( ValidAttachment( usNewItemIndex, usOldItemIndex ) )
					{
						// it's an attempt to attach; bring up the inventory panel
						if ( !InItemDescriptionBox( ) )
						{
							InitItemDescriptionBox( gpSMCurrentMerc, (UINT8)uiHandPos, SM_ITEMDESC_START_X, SM_ITEMDESC_START_Y, 0 );
						}
						return;
					}
					else if ( ValidMerge( usNewItemIndex, usOldItemIndex ) )
					{
						// bring up merge requestor
						gubHandPos = (UINT8) uiHandPos;
						gusOldItemIndex = usOldItemIndex;
						gusNewItemIndex = usNewItemIndex;
						gfDeductPoints = fDeductPoints;

						if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
						{
							//the only way to merge items is to pick them up.  In SKI when you pick up an item, the cursor is
							//locked in a region, free it up.
							FreeMouseCursor();

							DoMessageBox( MSG_BOX_BASIC_STYLE, Message[ STR_MERGE_ITEMS ], SHOPKEEPER_SCREEN, ( UINT8 )MSG_BOX_FLAG_YESNO, MergeMessageBoxCallBack, NULL );
						}
						else
							DoMessageBox( MSG_BOX_BASIC_STYLE, Message[ STR_MERGE_ITEMS ], GAME_SCREEN, ( UINT8 )MSG_BOX_FLAG_YESNO, MergeMessageBoxCallBack, NULL );
						return;
					}
					// else handle normally
				}


				// remember the item type currently in the item pointer
				usItemPrevInItemPointer = gpItemPointer->usItem;

				if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
				{
					// If it's just been purchased or repaired, mark it as a "new item"
					fNewItem = ( BOOLEAN ) ( gMoveingItem.uiFlags & ( ARMS_INV_JUST_PURCHASED | ARMS_INV_ITEM_REPAIRED ) );
				}

				// try to place the item in the cursor into this inventory slot
				if ( UIHandleItemPlacement( (UINT8) uiHandPos, usOldItemIndex, usNewItemIndex, fDeductPoints ) )
				{
					// it worked!  if we're in the SKI...
					if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
					{
						SetNewItem( gpSMCurrentMerc, ( UINT8 ) uiHandPos, fNewItem );

						// and the cursor is now empty
						if( gpItemPointer == NULL )
						{
							// clean up
							memset( &gMoveingItem, 0, sizeof( INVENTORY_IN_SLOT ) );
							SetSkiCursor( CURSOR_NORMAL );
						}
						else
						{
							// if we're holding something else in the pointer now
							if ( usItemPrevInItemPointer != gpItemPointer->usItem )
							{
								// pick up item swapped out of inventory slot into cursor (don't try to sell)
								BeginSkiItemPointer( PLAYERS_INVENTORY, -1, FALSE );
							}
							else
							{
								// otherwise, leave the cursor as is, means more items were picked up at once than can be placed in this slot
								// we deal with this by leaving the remainder in the cursor, to be put down elsewhere using subsequent clicks
							}
						}
					}

					// Setup a timer....
					//guiMouseOverItemTime = GetJA2Clock( );
					//gfCheckForMouseOverItem = TRUE;
					//gbCheckForMouseOverItemPos = (INT8)uiHandPos;
				}

				/*
				// Try to place here
				if ( PlaceObject( gpSMCurrentMerc, (UINT8)uiHandPos, gpItemPointer ) )
				{

					if ( fDeductPoints )
					{
						// Deduct points
						if ( gpItemPointerSoldier->bLife >= CONSCIOUSNESS )
						{
							DeductPoints( gpItemPointerSoldier,  2, 0 );
						}
						if ( gpSMCurrentMerc->bLife >= CONSCIOUSNESS )
						{
							DeductPoints( gpSMCurrentMerc,  2, 0 );
						}
					}

					HandleTacticalEffectsOfEquipmentChange( gpSMCurrentMerc, uiHandPos, usOldItemIndex, usNewItemIndex );

					// Dirty
					fInterfacePanelDirty = DIRTYLEVEL2;

					// Check if it's the same now!
					if ( gpItemPointer->ubNumberOfObjects == 0 )
					{
						EndItemPointer( );
					}

					// Setup a timer....
					guiMouseOverItemTime = GetJA2Clock( );
					gfCheckForMouseOverItem = TRUE;
					gbCheckForMouseOverItemPos = (INT8)uiHandPos;

				}
				*/
			}
		}
	}
	else if (iReason & MSYS_CALLBACK_REASON_RBUTTON_DWN)
	{
		fRightDown = TRUE;
	}
	else if (iReason & MSYS_CALLBACK_REASON_RBUTTON_UP && fRightDown )
	{
		fRightDown = FALSE;

		// Return if empty
		if ( gpSMCurrentMerc->inv[ uiHandPos ].usItem == NOTHING )
			return;

		// Turn off new item glow!
		gpSMCurrentMerc->bNewItemCount[ uiHandPos ] = 0;

		// Some global stuff here - for esc, etc
		// Check for # of slots in item
		if( ( gpSMCurrentMerc->inv[ uiHandPos ].ubNumberOfObjects > 1 && ItemSlotLimit( gpSMCurrentMerc->inv[ uiHandPos ].usItem, (UINT8)uiHandPos ) > 0 ) && ( guiCurrentScreen != MAP_SCREEN ) )
		{
			if ( !InItemStackPopup( )  )
			{
				//InitItemStackPopup( gpSMCurrentMerc, (UINT8)uiHandPos, SM_ITEMDESC_START_X, SM_ITEMDESC_START_Y, SM_ITEMDESC_WIDTH, SM_ITEMDESC_HEIGHT );
				InitItemStackPopup(gpSMCurrentMerc, (UINT8)uiHandPos, 216, INV_INTERFACE_START_Y, 314, SCREEN_HEIGHT - INV_INTERFACE_START_Y);
			}
		}
		else
		{
			if ( !InItemDescriptionBox( ) )
			{
				InitItemDescriptionBox( gpSMCurrentMerc, (UINT8)uiHandPos, SM_ITEMDESC_START_X, SM_ITEMDESC_START_Y, 0 );
			}
		}
	}
	else if (iReason & MSYS_CALLBACK_REASON_LOST_MOUSE )
	{
		fRightDown = FALSE;
		fLeftDown = FALSE;
	}

}


static void MergeMessageBoxCallBack(UINT8 ubExitValue)
{
	if ( ubExitValue == MSG_BOX_RETURN_YES )
	{
		AttachObject( gpItemPointerSoldier, &( gpSMCurrentMerc->inv[ gubHandPos ] ), gpItemPointer );

		// re-evaluate repairs
		gfReEvaluateEveryonesNothingToDo = TRUE;

		if (gpItemPointer->usItem == NOTHING)
		{
			// merge item consumed
			EndItemPointer();
			fInterfacePanelDirty = DIRTYLEVEL2;
		}
	}
	else
	{
		UIHandleItemPlacement( gubHandPos, gusOldItemIndex, gusNewItemIndex, gfDeductPoints );
	}
}


static void HandleMouseOverSoldierFaceForContMove(SOLDIERTYPE* pSoldier, BOOLEAN fOn)
{
	INT16			sGridNo;

	if ( pSoldier == NULL )
	{
		return;
	}

	if ( fOn )
	{
		// Check if we are waiting to continue move...
		if ( CheckForMercContMove( pSoldier ) )
		{
			// Display 'cont' on face....
			// Get face
			FACETYPE* const pFace = pSoldier->face;

			pFace->fDisplayTextOver = FACE_DRAW_TEXT_OVER;
			wcscpy( pFace->zDisplayText, TacticalStr[ CONTINUE_OVER_FACE_STR ] );

			sGridNo = pSoldier->sFinalDestination;

			if ( pSoldier->bGoodContPath )
			{
				sGridNo = pSoldier->sContPathLocation;
			}

			// While our mouse is here, draw a path!
			PlotPath(pSoldier, sGridNo, NO_COPYROUTE, PLOT, pSoldier->usUIMovementMode, pSoldier->bActionPoints);
		}
	}
	else
	{
		// Remove 'cont' on face....
		// Get face
		FACETYPE* const pFace = pSoldier->face;

		pFace->fDisplayTextOver = FACE_ERASE_TEXT_OVER;

		// Erase path!
		ErasePath( TRUE );
	}

	fInterfacePanelDirty = DIRTYLEVEL2;
}


static void SelectedMercButtonMoveCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	if ( gpSMCurrentMerc == NULL )
	{
		return;
	}

	if (iReason & MSYS_CALLBACK_REASON_MOVE )
	{
		HandleMouseOverSoldierFaceForContMove( gpSMCurrentMerc, TRUE );
	}
	else if ( iReason & MSYS_CALLBACK_REASON_LOST_MOUSE )
	{
		HandleMouseOverSoldierFaceForContMove( gpSMCurrentMerc, FALSE );
	}
}


static void SelectedMercButtonCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	if ( gpSMCurrentMerc == NULL )
	{
		return;
	}

	//if we are in the shop keeper interface
	if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
		return;

	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		// ATE: Don't if this guy can't....
		if ( !gfSMDisableForItems )
		{
			if ( gpSMCurrentMerc->uiStatusFlags & ( SOLDIER_DRIVER | SOLDIER_PASSENGER ) )
			{
				SOLDIERTYPE* const v = GetSoldierStructureForVehicle(gpSMCurrentMerc->iVehicleId);
				HandleLocateSelectMerc(v, 0);
			}
			else
			{
				if ( CheckForMercContMove( gpSMCurrentMerc ) )
				{
					// Continue
					ContinueMercMovement( gpSMCurrentMerc );
					ErasePath( TRUE );
				}
				else
				{
					HandleLocateSelectMerc(gpSMCurrentMerc, 0);
				}
			}
		}
	}
	else if (iReason & MSYS_CALLBACK_REASON_RBUTTON_DWN)
	{
		// ATE: Cannot get out by right clicking...
		//if ( gpItemPointer == NULL )
		{
			//if ( !gfSMDisableForItems || ( gfSMDisableForItems && gpItemPointer == NULL ) )
			{
				// Delete desc
				if ( InItemDescriptionBox( ) )
				{
					DeleteItemDescriptionBox( );
				}

				gfSwitchPanel = TRUE;
				gbNewPanel		= TEAM_PANEL;
			}
		}
	}
}


static void SelectedMercEnemyIndicatorCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	if ( gpSMCurrentMerc == NULL )
	{
		return;
	}

	//if we are in the shop keeper interface
	if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
		return;

	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		// ATE: Don't if this guy can't....
		if ( !gfSMDisableForItems )
		{
			if ( gpSMCurrentMerc->uiStatusFlags & ( SOLDIER_DRIVER | SOLDIER_PASSENGER ) )
			{
			}
			else
			{
				if ( gpSMCurrentMerc->bOppCnt > 0 )
				{
					CycleVisibleEnemies( gpSMCurrentMerc );
				}
				else
				{
					SelectedMercButtonCallback( pRegion, iReason );
				}
			}
		}
	}
}


static void BtnStanceUpCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		INT8 bNewStance = gAnimControl[gpSMCurrentMerc->usAnimState].ubEndHeight;
		switch (bNewStance)
		{
			case ANIM_CROUCH: bNewStance = ANIM_STAND;  break;
			case ANIM_PRONE:  bNewStance = ANIM_CROUCH; break;
		}
		UIHandleSoldierStanceChange(gpSMCurrentMerc, bNewStance);
	}
}


void BtnUpdownCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		// Change interface level via HandleUI handler
		UIHandleChangeLevel(NULL);
	}
}


static void BtnClimbCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		BOOLEAN fNearHeigherLevel;
		BOOLEAN fNearLowerLevel;
		GetMercClimbDirection(gpSMCurrentMerc, &fNearLowerLevel, &fNearHeigherLevel);
		if (fNearLowerLevel)   BeginSoldierClimbDownRoof(gpSMCurrentMerc);
		if (fNearHeigherLevel) BeginSoldierClimbUpRoof(gpSMCurrentMerc);

		INT8 bDirection;
		if (FindFenceJumpDirection(gpSMCurrentMerc, gpSMCurrentMerc->sGridNo, gpSMCurrentMerc->bDirection, &bDirection))
		{
			BeginSoldierClimbFence(gpSMCurrentMerc);
		}
	}
}


static void BtnStanceDownCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		INT8 bNewStance = gAnimControl[gpSMCurrentMerc->usAnimState].ubEndHeight;
		switch (bNewStance)
		{
			case ANIM_STAND:  bNewStance = ANIM_CROUCH; break;
			case ANIM_CROUCH: bNewStance = ANIM_PRONE;  break;
		}
		UIHandleSoldierStanceChange(gpSMCurrentMerc, bNewStance);
	}
}


static void BtnStealthModeCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		gpSMCurrentMerc->bStealthMode = !gpSMCurrentMerc->bStealthMode;
		gfUIStanceDifferent		= TRUE;
		gfPlotNewMovement			= TRUE;
		fInterfacePanelDirty	= DIRTYLEVEL2;
	}
}


static void BtnHandCursorCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		ToggleHandCursorMode(&guiCurrentEvent);
	}
}


static void BtnTalkCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		ToggleTalkCursorMode(&guiCurrentEvent);
	}
}


static void BtnMuteCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		gpSMCurrentMerc->uiStatusFlags ^= SOLDIER_MUTE;
		const wchar_t* msg = (gpSMCurrentMerc->uiStatusFlags & SOLDIER_MUTE ? TacticalStr[MUTE_ON_STR] : TacticalStr[MUTE_OFF_STR]);
		ScreenMsg(FONT_MCOLOR_LTYELLOW, MSG_INTERFACE, msg, gpSMCurrentMerc->name);
	}
}


static void SelectMerc(SOLDIERTYPE* const s)
{
	gSelectSMPanelToMerc = s;

	if (!gfInItemPickupMenu)
	{
		BOOLEAN set_locator;
		if (guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE)
		{
			// Refresh background for player slots (in case item values change due to Flo's discount)
			gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;
			set_locator = DONTSETLOCATOR;
		}
		else
		{
			set_locator = SETLOCATOR;
		}
		LocateSoldier(s, set_locator);
	}

	// If the user is in the shop keeper interface and is in the item desc
	if (guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE &&
			InItemDescriptionBox())
	{
		DeleteItemDescriptionBox();
	}
}


static void BtnPrevMercCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		SelectMerc(FindPrevActiveAndAliveMerc(gpSMCurrentMerc, TRUE, TRUE));
	}
}


static void BtnNextMercCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		SelectMerc(FindNextActiveAndAliveMerc(gpSMCurrentMerc, TRUE, TRUE));
	}
}


static void BtnOptionsCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		guiPreviousOptionScreen = guiCurrentScreen;
		LeaveTacticalScreen(OPTIONS_SCREEN);
	}
}


static void BtnSMDoneCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		gfBeginEndTurn = TRUE;
	}
}


static void BtnMapScreenCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		// Enter mapscreen...
		//gfEnteringMapScreen = TRUE;
		GoToMapScreenFromTactical();
	}
}


static void BtnBurstModeCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		ChangeWeaponMode(gpSMCurrentMerc);
	}
}


static void BtnLookCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		ToggleLookCursorMode(NULL);
	}
}


static void EnemyIndicatorClickCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void MercFacePanelCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void MercFacePanelMoveCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void TMClickFirstHandInvCallback(MOUSE_REGION* pRegion, INT32 iReason);
static void TMClickSecondHandInvCallback(MOUSE_REGION* pRegion, INT32 iReason);


BOOLEAN InitializeTEAMPanel(void)
{
	// INit viewport region
	// Set global mouse regions
	// Define region for viewport
	MSYS_DefineRegion(&gViewportRegion, 0, 0, gsVIEWPORT_END_X, gsVIEWPORT_END_Y, MSYS_PRIORITY_NORMAL, VIDEO_NO_CURSOR, MSYS_NO_CALLBACK, MSYS_NO_CALLBACK);

	guiTEAMPanel = AddVideoObjectFromFile("INTERFACE/bottom_bar.sti");
	CHECKF(guiTEAMPanel != NO_VOBJECT);
	guiTEAMObjects = AddVideoObjectFromFile("INTERFACE/gold_front.sti");
	CHECKF(guiTEAMObjects != NO_VOBJECT);
	guiBrownBackgroundForTeamPanel = AddVideoObjectFromFile("INTERFACE/Bars.sti");
	CHECKF(guiBrownBackgroundForTeamPanel != NO_VOBJECT);

	// Create buttons
	CHECKF(CreateTEAMPanelButtons());

	// Set viewports
	// Define region for panel
	MSYS_DefineRegion(&gTEAM_PanelRegion, 0, gsVIEWPORT_END_Y, SCREEN_WIDTH, SCREEN_HEIGHT, MSYS_PRIORITY_NORMAL, CURSOR_NORMAL, MSYS_NO_CALLBACK, MSYS_NO_CALLBACK);

	for (UINT32 i = 0; i < NUM_TEAM_SLOTS; ++i)
	{
		const INT32 dx = TM_INV_HAND_SEP * i;
		const INT32 dy = INTERFACE_START_Y;

		INT32 x;
		INT32 y;

		x = dx + TM_FACE_X;
		y = dy + TM_FACE_Y;
		MSYS_DefineRegion(&gTEAM_FaceRegions[i], x, y , x + TM_FACE_WIDTH, y + TM_FACE_HEIGHT, MSYS_PRIORITY_NORMAL, MSYS_NO_CURSOR, MercFacePanelMoveCallback, MercFacePanelCallback);
		MSYS_SetRegionUserData(&gTEAM_FaceRegions[i], 0, i);

		MSYS_DefineRegion(&gTEAM_EnemyIndicator[i], x + 1, y + 1, x + INDICATOR_BOX_WIDTH, y + INDICATOR_BOX_HEIGHT, MSYS_PRIORITY_NORMAL, MSYS_NO_CURSOR, MSYS_NO_CALLBACK, EnemyIndicatorClickCallback);
		MSYS_SetRegionUserData(&gTEAM_EnemyIndicator[i], 0, i);

		if (IsMouseInRegion(&gTEAM_FaceRegions[i]))
		{
			SOLDIERTYPE* const s = gTeamPanel[i].merc;
			if (s != NULL) HandleMouseOverSoldierFaceForContMove(s, TRUE);
		}

		x = dx + TM_BARS_X;
		y = dy + TM_BARS_Y;
		MSYS_DefineRegion(&gTEAM_BarsRegions[i], x, y , x + TM_BARS_WIDTH, y + TM_BARS_HEIGHT, MSYS_PRIORITY_NORMAL, MSYS_NO_CURSOR, MSYS_NO_CALLBACK, MercFacePanelCallback);
		MSYS_SetRegionUserData(&gTEAM_BarsRegions[i], 0, i);

		x = dx + TM_FACE_X;
		y = dy + TM_FACE_Y;
		MSYS_DefineRegion(&gTEAM_LeftBarsRegions[i], x - 8, y, x, y + TM_BARS_HEIGHT, MSYS_PRIORITY_NORMAL, MSYS_NO_CURSOR, MSYS_NO_CALLBACK, MercFacePanelCallback);
		MSYS_SetRegionUserData(&gTEAM_LeftBarsRegions[i], 0, i);

		x = dx + TM_INV_HAND1STARTX;
		y = dy + TM_INV_HAND1STARTY;
		MSYS_DefineRegion(&gTEAM_FirstHandInv[i], x, y, x + TM_INV_WIDTH, y + TM_INV_HEIGHT, MSYS_PRIORITY_NORMAL, MSYS_NO_CURSOR, MSYS_NO_CALLBACK, TMClickFirstHandInvCallback);
		MSYS_SetRegionUserData(&gTEAM_FirstHandInv[i], 0, i);

		y += TM_INV_HAND_SEPY;
		MSYS_DefineRegion(&gTEAM_SecondHandInv[i], x, y, x + TM_INV_WIDTH, y + TM_INV_HEIGHT, MSYS_PRIORITY_NORMAL, MSYS_NO_CURSOR, MSYS_NO_CALLBACK, TMClickSecondHandInvCallback);
		MSYS_SetRegionUserData(&gTEAM_SecondHandInv[i], 0, i);
	}

	return TRUE;
}


BOOLEAN ShutdownTEAMPanel(void)
{
	// All buttons and regions and video objects and video surfaces will be deleted at shutddown of SGM
	// We may want to delete them at the interm as well, to free up room for other panels
	DeleteVideoObject(guiTEAMPanel);
	DeleteVideoObject(guiTEAMObjects);
	DeleteVideoObject(guiBrownBackgroundForTeamPanel);

	MSYS_RemoveRegion(&gTEAM_PanelRegion);
	MSYS_RemoveRegion(&gViewportRegion);

	for (UINT32 i = 0; i < NUM_TEAM_SLOTS; ++i)
	{
		MSYS_RemoveRegion(&gTEAM_EnemyIndicator[i]);
		MSYS_RemoveRegion(&gTEAM_FaceRegions[i]);
		MSYS_RemoveRegion(&gTEAM_BarsRegions[i]);
		MSYS_RemoveRegion(&gTEAM_LeftBarsRegions[i]);
		MSYS_RemoveRegion(&gTEAM_FirstHandInv[i]);
		MSYS_RemoveRegion(&gTEAM_SecondHandInv[i]);

		SOLDIERTYPE* const s = gTeamPanel[i].merc;
		if (s != NULL) HandleMouseOverSoldierFaceForContMove(s, FALSE);
	}

	RemoveTEAMPanelButtons();

	// start rendering radar region again,
	fRenderRadarScreen = TRUE;
	return TRUE;
}


static void RenderSoldierTeamInv(SOLDIERTYPE* pSoldier, INT16 sX, INT16 sY, UINT8 ubPanelNum, BOOLEAN fDirty);
static void UpdateTEAMPanel(void);


void RenderTEAMPanel(BOOLEAN fDirty)
{
	if (fDirty == DIRTYLEVEL2)
	{
		MarkAButtonDirty(iTEAMPanelButtons[TEAM_DONE_BUTTON]);
		MarkAButtonDirty(iTEAMPanelButtons[TEAM_MAP_SCREEN_BUTTON]);
		MarkAButtonDirty(iTEAMPanelButtons[CHANGE_SQUAD_BUTTON]);

		BltVideoObject(guiSAVEBUFFER, guiTEAMPanel, 0, INTERFACE_START_X, INTERFACE_START_Y);

		// LOOP THROUGH ALL MERCS ON TEAM PANEL
		for (UINT32 i = 0; i < NUM_TEAM_SLOTS; ++i)
		{
			const INT32 dx = TM_INV_HAND_SEP * i;
			const INT32 dy = INTERFACE_START_Y;

			const SOLDIERTYPE* const s = gTeamPanel[i].merc;
			if (s == NULL)
			{
				//BLIT CLOSE PANEL
				BltVideoObject(guiSAVEBUFFER, guiCLOSE, 5, dx + TM_FACE_X, dy + TM_FACE_Y);

				if (gTacticalStatus.ubCurrentTeam != OUR_TEAM || INTERRUPT_QUEUED)
				{
					// Hatch out...
					const INT32 x = dx + TM_FACEHIGHTL_X;
					const INT32 y = dy + TM_FACEHIGHTL_Y;
					BltVideoObject(guiSAVEBUFFER, guiTEAMObjects, 1, x, y);
				}
			}
			else
			{
				const wchar_t* help;
				wchar_t        help_buf[200];

				// Add text for first hand popup
				if (s->uiStatusFlags & SOLDIER_DRIVER)
				{
					// Get soldier pointer for vehicle.....
					const SOLDIERTYPE* const v = GetSoldierStructureForVehicle(s->iVehicleId);
					swprintf(help_buf, lengthof(help_buf), TacticalStr[DRIVER_POPUPTEXT], v->bLife, v->bLifeMax, v->bBreath, v->bBreathMax);
					help = help_buf;
				}
				else if (s->uiStatusFlags & SOLDIER_DEAD)
				{
					help = L"";
				}
				else
				{
					GetHelpTextForItem(help_buf, lengthof(help_buf), &s->inv[HANDPOS]);
					help = help_buf;
				}
				SetRegionFastHelpText(&gTEAM_FirstHandInv[i], help);

				// Add text for seonc hand popup
				if (s->uiStatusFlags & (SOLDIER_PASSENGER | SOLDIER_DRIVER))
				{
					help = TacticalStr[EXIT_VEHICLE_POPUPTEXT];
				}
				else if (s->uiStatusFlags & SOLDIER_DEAD)
				{
					help = L"";
				}
				else
				{
					GetHelpTextForItem(help_buf, lengthof(help_buf), &s->inv[SECONDHANDPOS]);
					help = help_buf;
				}
				SetRegionFastHelpText(&gTEAM_SecondHandInv[i], help);

				// Render Selected guy if selected
				if (GetSelectedMan() == s && gTacticalStatus.ubCurrentTeam == OUR_TEAM && OK_INTERRUPT_MERC(s))
				{
					const INT32 x = dx + TM_FACEHIGHTL_X;
					const INT32 y = dy + TM_FACEHIGHTL_Y;
					BltVideoObject(guiSAVEBUFFER, guiTEAMObjects, 0, x, y);
				}
				else if (gTacticalStatus.ubCurrentTeam != OUR_TEAM || !OK_INTERRUPT_MERC(s))
				{
					const INT32 x = dx + TM_FACEHIGHTL_X;
					const INT32 y = dy + TM_FACEHIGHTL_Y;
					BltVideoObject(guiSAVEBUFFER, guiTEAMObjects, 1, x, y);
				}

				RenderSoldierFace(s, dx + TM_FACE_X, dy + TM_FACE_Y);

				// Restore AP/LIFE POSIITONS

				// Render name!
				SetFont(BLOCKFONT2);

				if (s->bStealthMode)
				{
					SetFontForeground(FONT_MCOLOR_LTYELLOW);
				}
				else
				{
					SetFontForeground(FONT_MCOLOR_LTGRAY);
				}
				SetFontBackground(FONT_MCOLOR_BLACK);

				// RENDER ON SAVE BUFFER!
				SetFontDestBuffer(guiSAVEBUFFER, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
				INT16 sFontX;
				INT16 sFontY;
				FindFontCenterCoordinates(dx + TM_NAME_X, dy + TM_NAME_Y, TM_NAME_WIDTH, TM_NAME_HEIGHT, s->name, BLOCKFONT2, &sFontX, &sFontY);
				mprintf(sFontX, sFontY, L"%ls", s->name);
				// reset to frame buffer!
				SetFontDestBuffer(FRAME_BUFFER, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			}
		}

		RestoreExternBackgroundRect(INTERFACE_START_X, INTERFACE_START_Y, SCREEN_WIDTH - INTERFACE_START_X, SCREEN_HEIGHT - INTERFACE_START_Y);

		RenderTownIDString();
	}

	// Loop through all mercs and make go
	for (UINT32 i = 0; i < NUM_TEAM_SLOTS; ++i)
	{
		SOLDIERTYPE* const s = gTeamPanel[i].merc;
		if (s == NULL) continue;

		// Update animations....
		if (s->fClosePanel || s->fClosePanelToDie)
		{
			s->sPanelFaceX = s->face->usFaceX;
			s->sPanelFaceY = s->face->usFaceY;
		}

		const INT32 dx = TM_INV_HAND_SEP * i;
		const INT32 dy = INTERFACE_START_Y;

		if (fDirty != DIRTYLEVEL0)
		{
			// UPdate stats!
			if (fDirty == DIRTYLEVEL2)
			{
				SetStatsHelp(&gTEAM_BarsRegions[i], s);
			}

			const INT32 x = dx + TM_AP_X;
			const INT32 y = dy + TM_AP_Y;
			const INT32 w = TM_AP_WIDTH;
			const INT32 h = TM_AP_HEIGHT;
			if (!(s->uiStatusFlags & SOLDIER_DEAD))
			{
				PrintAP(s, x, y, w, h);
				DrawSoldierUIBars(s, dx + TM_BARS_X + 2, dy + TM_BARS_Y + 2 + TM_LIFEBAR_HEIGHT, TRUE, FRAME_BUFFER);
			}
			else
			{
				// Erase APs
				RestoreExternBackgroundRect(x, y, w, h);
			}
		}

		RenderSoldierTeamInv(s, dx + TM_INV_HAND1STARTX, dy + TM_INV_HAND1STARTY, i, fDirty);
	}
	UpdateTEAMPanel();

	if (fRenderRadarScreen)
	{
		CreateMouseRegionForPauseOfClock();
	}
	else
	{
		RemoveMouseRegionForPauseOfClock();
	}
}


static BOOLEAN MakeButtonTeam(const UINT idx, BUTTON_PICS* const image, const INT16 x, const INT16 y, const GUI_CALLBACK click, const wchar_t* const help)
{
	INT32 btn = QuickCreateButton(image, x, y, MSYS_PRIORITY_HIGH - 1, click);
	iTEAMPanelButtons[idx] = btn;
	if (btn == BUTTON_NO_SLOT)
	{
		DebugMsg(TOPIC_JA2, DBG_LEVEL_3, "Cannot create Interface button");
		return FALSE;
	}
	SetButtonFastHelpText(btn, help);
	return TRUE;
}


static void BtnEndTurnCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnRostermodeCallback(GUI_BUTTON* btn, INT32 reason);
static void BtnSquadCallback(GUI_BUTTON* btn, INT32 reason);


BOOLEAN CreateTEAMPanelButtons(void)
{
	// Load button Graphics
	iTEAMPanelImages[ENDTURN_IMAGES]    = LoadButtonImage("INTERFACE/bottom_bar_buttons.sti",    -1, 0, -1, 3, -1);
	iTEAMPanelImages[ROSTERMODE_IMAGES] = UseLoadedButtonImage(iTEAMPanelImages[ENDTURN_IMAGES], -1, 1, -1, 4, -1);
	iTEAMPanelImages[DISK_IMAGES]       = UseLoadedButtonImage(iTEAMPanelImages[ENDTURN_IMAGES], -1, 2, -1, 5, -1);

	const INT32 dy = INTERFACE_START_Y;
	if (!MakeButtonTeam(TEAM_DONE_BUTTON,       iTEAMPanelImages[ENDTURN_IMAGES],    TM_ENDTURN_X,    dy + TM_ENDTURN_Y,    BtnEndTurnCallback,    TacticalStr[END_TURN_POPUPTEXT]))     return FALSE;
	if (!MakeButtonTeam(TEAM_MAP_SCREEN_BUTTON, iTEAMPanelImages[ROSTERMODE_IMAGES], TM_ROSTERMODE_X, dy + TM_ROSTERMODE_Y, BtnRostermodeCallback, TacticalStr[MAPSCREEN_POPUPTEXT]))    return FALSE;
	if (!MakeButtonTeam(CHANGE_SQUAD_BUTTON,    iTEAMPanelImages[DISK_IMAGES],       TM_DISK_X,       dy + TM_DISK_Y,       BtnSquadCallback,      TacticalStr[CHANGE_SQUAD_POPUPTEXT])) return FALSE;

	return TRUE;
}


void RemoveTEAMPanelButtons(void)
{
	for (UINT32 i = 0; i < NUM_TEAM_BUTTONS; ++i)
	{
		RemoveButton(iTEAMPanelButtons[i]);
		UnloadButtonImage(iTEAMPanelImages[i]);
	}
}


static void BtnEndTurnCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		UIHandleEndTurn(NULL);
	}
}


static void BtnRostermodeCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		if (guiCurrentScreen == GAME_SCREEN) GoToMapScreenFromTactical();
	}
}


// callback to handle squad switching callback
static void BtnSquadCallback(GUI_BUTTON* btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		ToggleRadarScreenRender();
	}
}


void SetTEAMPanelCurrentMerc(void)
{
	fInterfacePanelDirty = DIRTYLEVEL2;
	UpdateTEAMPanel();
}


static void UpdateTEAMPanel(void)
{
	if (gTacticalStatus.ubCurrentTeam != gbPlayerNum ||
			gTacticalStatus.uiFlags & REALTIME ||
			!(gTacticalStatus.uiFlags & INCOMBAT))
	{
		DisableButton(iTEAMPanelButtons[TEAM_DONE_BUTTON]);
	}
	else
	{
		EnableButton(iTEAMPanelButtons[TEAM_DONE_BUTTON]);
	}

	if (gTacticalStatus.uiFlags & ENGAGED_IN_CONV)
	{
		DisableButton(iTEAMPanelButtons[TEAM_MAP_SCREEN_BUTTON]);
	}
	else
	{
		EnableButton(iTEAMPanelButtons[TEAM_MAP_SCREEN_BUTTON]);
	}


	if (gfDisableTacticalPanelButtons)
	{
		DisableButton(iTEAMPanelButtons[TEAM_DONE_BUTTON]);
		DisableButton(iTEAMPanelButtons[TEAM_MAP_SCREEN_BUTTON]);
		DisableButton(iTEAMPanelButtons[CHANGE_SQUAD_BUTTON]);

		// OK, disable item regions.......
		for (INT32 i = 0; i < NUM_TEAM_SLOTS; ++i)
		{
			MSYS_DisableRegion(&gTEAM_EnemyIndicator[i]);
			MSYS_DisableRegion(&gTEAM_FirstHandInv[i]);
			MSYS_DisableRegion(&gTEAM_SecondHandInv[i]);
		}

		//disable the radar map region
		// If NOT in overhead map
		if (!InOverheadMap())
		{
			MSYS_DisableRegion(&gRadarRegion);
		}
	}
	else
	{
		EnableButton(iTEAMPanelButtons[CHANGE_SQUAD_BUTTON]);

		for (INT32 i = 0; i < NUM_TEAM_SLOTS; ++i)
		{
			MSYS_EnableRegion(&gTEAM_EnemyIndicator[i]);
			MSYS_EnableRegion(&gTEAM_FirstHandInv[i]);
			MSYS_EnableRegion(&gTEAM_SecondHandInv[i]);
		}

		//Enable the radar map region
		MSYS_EnableRegion(&gRadarRegion);
	}
}


static void MercFacePanelMoveCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	// If our flags are set to do this, gofoit!
	if (guiTacticalInterfaceFlags & INTERFACE_MAPSCREEN) return;

	const UINT8 ubID     = MSYS_GetRegionUserData(pRegion, 0);
	SOLDIERTYPE* const s = gTeamPanel[ubID].merc;
	if (s == NULL || !s->bActive) return;

	if (iReason & MSYS_CALLBACK_REASON_MOVE)
	{
		HandleMouseOverSoldierFaceForContMove(s, TRUE);
	}
	else if (iReason & MSYS_CALLBACK_REASON_LOST_MOUSE)
	{
		HandleMouseOverSoldierFaceForContMove(s, FALSE);
	}
}


static void EnemyIndicatorClickCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	const UINT8 ubID     = MSYS_GetRegionUserData(pRegion, 0);
	SOLDIERTYPE* const s = gTeamPanel[ubID].merc;
	if (s == NULL || !s->bActive) return;

	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_DWN)
	{
		if (!(s->uiStatusFlags & (SOLDIER_DRIVER | SOLDIER_PASSENGER)))
		{
			if (s->bOppCnt > 0)
			{	// Cycle....
				CycleVisibleEnemies(s);
			}
			else
			{
				MercFacePanelCallback(pRegion, iReason);
			}
		}
	}
}


static void MercFacePanelCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	const UINT8 ubID     = MSYS_GetRegionUserData(pRegion, 0);
	SOLDIERTYPE* const s = gTeamPanel[ubID].merc;
	if (s == NULL || !s->bActive) return;

	// If our flags are set to do this, gofoit!
	if (guiTacticalInterfaceFlags & INTERFACE_MAPSCREEN)
	{
		if (iReason & MSYS_CALLBACK_REASON_LBUTTON_DWN) SetInfoChar(s);
		return;
	}

	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_DWN)
	{
		if (!gfInItemPickupMenu && gpItemPointer == NULL)
		{
			if (s->uiStatusFlags & (SOLDIER_DRIVER | SOLDIER_PASSENGER))
			{
				SOLDIERTYPE* const v = GetSoldierStructureForVehicle(s->iVehicleId);
				HandleLocateSelectMerc(v, 0);
			}
			else
			{
				if (!InOverheadMap())
				{
					// If we can continue a move, do so!
					if (CheckForMercContMove(s))
					{
						// Continue
						ContinueMercMovement(s);
						ErasePath(TRUE);
					}
					else
					{
						HandleLocateSelectMerc(s, 0);
					}
				}
				else
				{
					SelectSoldier(s, SELSOLDIER_ACKNOWLEDGE);
				}
			}
		}
	}
	else if (iReason & MSYS_CALLBACK_REASON_RBUTTON_DWN)
	{
		if (!InOverheadMap())
		{
			// Only if guy is not dead!
			if (!(s->uiStatusFlags & SOLDIER_DEAD) &&
					!AM_AN_EPC(s) &&
					!(s->uiStatusFlags & (SOLDIER_DRIVER | SOLDIER_PASSENGER)))
			{
				gfSwitchPanel = TRUE;
				gbNewPanel = SM_PANEL;
				gNewPanelSoldier = s;
			}
		}
	}
}


void HandleLocateSelectMerc(SOLDIERTYPE* const s, const INT8 bFlag)
{
	if (!s->bActive) return;

	if (gpItemPointer != NULL)
	{
		// ATE: Disable for feel purposes....
		//return;
	}

	// ATE: No matter what we do... if below OKLIFE, just locate....
	if (s->bLife < OKLIFE)
	{
		LocateSoldier(s, SETLOCATOR);
		return;
	}

	if (_KeyDown(ALT))
	{
		if (gGameSettings.fOptions[TOPTION_OLD_SELECTION_METHOD])
		{
			// Select merc
			SelectSoldier(s, SELSOLDIER_ACKNOWLEDGE | SELSOLDIER_FROM_UI);
			s->fFlashLocator = FALSE;
			ResetMultiSelection();
		}
		else
		{
			// Just locate....
			LocateSoldier(s, SETLOCATOR);
		}
	}
	else
	{
		BOOLEAN fSelect = FALSE;

		if (s->fFlashLocator == FALSE)
		{
			// If we are currently selected, slide to location
			if (s == GetSelectedMan())
			{
				SlideTo(s, SETLOCATOR);
			}
			else
			{
				if (gGameSettings.fOptions[TOPTION_OLD_SELECTION_METHOD])
				{
					LocateSoldier(s, SETLOCATOR);
				}
				else
				{
					fSelect = TRUE;
				}
			}
		}
		else
		{
			if (gGameSettings.fOptions[TOPTION_OLD_SELECTION_METHOD])
			{
				// If we are currently selected, slide to location
				if (s == GetSelectedMan())
				{
					SlideTo(s, DONTSETLOCATOR);
				}
				else
				{
					LocateSoldier(s, DONTSETLOCATOR);
				}

				fSelect = TRUE;
			}
			else
			{
				if (s == GetSelectedMan())
				{
					LocateSoldier(s, DONTSETLOCATOR);
				}
				else
				{
					fSelect = TRUE;
				}
			}
		}

		if (bFlag == LOCATEANDSELECT_MERC) fSelect = TRUE;

		if (fSelect)
		{
			// Select merc, only if alive!
			if (!(s->uiStatusFlags & SOLDIER_DEAD))
			{
				SelectSoldier(s, SELSOLDIER_ACKNOWLEDGE | SELSOLDIER_FROM_UI);
			}
		}
	}

	ResetMultiSelection();

	// Handle locate select merc....
	HandleMouseOverSoldierFaceForContMove(s, TRUE);
}


void ShowRadioLocator(SOLDIERTYPE* s, UINT8 ubLocatorSpeed)
{
	//LocateSoldier(s, FALSE); // IC - this is already being done outside of this function :)
	s->fFlashLocator = TRUE;
	s->sLocatorFrame = 0;

	if ( ubLocatorSpeed == SHOW_LOCATOR_NORMAL )
	{
		// If we are an AI guy, and we have the baton, make lower...
		// (s->uiStatusFlags & SOLDIER_UNDERAICONTROL && s->bTeam != gbPlayerNum)
		//
		//s->ubNumLocateCycles = 3;
		//
		//se
		//
			s->ubNumLocateCycles = 5;
		//
	}
	else
	{
		s->ubNumLocateCycles = 3;
	}
}


void EndRadioLocator(SOLDIERTYPE* s)
{
	s->fFlashLocator = FALSE;
	s->fShowLocator = FALSE;
}


void FinishAnySkullPanelAnimations(void)
{
	FOR_ALL_IN_TEAM(s, gbPlayerNum)
	{
		if (s->bLife == 0 &&
				(s->fUIdeadMerc || s->fClosePanelToDie))
		{
			HandlePlayerTeamMemberDeathAfterSkullAnimation(s);

			s->fUIdeadMerc      = FALSE;
			s->fClosePanelToDie = FALSE;
		}
	}
}


void HandlePanelFaceAnimations(SOLDIERTYPE* pSoldier)
{
	if ( pSoldier->bTeam != gbPlayerNum )
	{
		return;
	}


	if ( !pSoldier->bActive )
	{
		return;
	}

	if ( pSoldier->uiStatusFlags & SOLDIER_VEHICLE )
	{
		// Don't do this for a vehice.
		return;
	}

	if ( pSoldier->fUICloseMerc )
	{
		pSoldier->fUICloseMerc = FALSE;
	}

	if ( pSoldier->fUIdeadMerc  )
	{
		pSoldier->sPanelFaceX = pSoldier->face->usFaceX;
		pSoldier->sPanelFaceY = pSoldier->face->usFaceY;

		pSoldier->fUIdeadMerc = FALSE;
		pSoldier->fClosePanel		= TRUE;
		pSoldier->fClosePanelToDie = TRUE;
		pSoldier->ubClosePanelFrame = 0;
		pSoldier->ubDeadPanelFrame = 0;
		RESETTIMECOUNTER( pSoldier->PanelAnimateCounter, 160 );
	}

	if ( pSoldier->fClosePanel )
	{
		 if ( TIMECOUNTERDONE( pSoldier->PanelAnimateCounter, 160 ) )
		 {
				pSoldier->ubClosePanelFrame++;

				if ( pSoldier->ubClosePanelFrame > 5 )
				{
					pSoldier->fClosePanel = FALSE;
					pSoldier->ubClosePanelFrame = 5;

					if ( pSoldier->fClosePanelToDie )
					{
						pSoldier->fDeadPanel = TRUE;
						//PlayJA2Sample(HEADCR_1, HIGHVOLUME, 1, MIDDLEPAN);
					}
					else
					{
						if (!pSoldier->face->fDisabled)
						{
							RestoreExternBackgroundRect( pSoldier->sPanelFaceX, pSoldier->sPanelFaceY, TM_FACE_WIDTH, TM_FACE_HEIGHT );
						}
					}
				}
				RESETTIMECOUNTER( pSoldier->PanelAnimateCounter, 160 );
		 }
	}

	if ( pSoldier->fClosePanel )
	{
		if (!pSoldier->face->fDisabled)
		{
			RestoreExternBackgroundRect(pSoldier->sPanelFaceX, pSoldier->sPanelFaceY, TM_FACE_WIDTH, TM_FACE_HEIGHT);
			BltVideoObject(FRAME_BUFFER, guiCLOSE, pSoldier->ubClosePanelFrame, pSoldier->sPanelFaceX, pSoldier->sPanelFaceY);
			InvalidateRegion(pSoldier->sPanelFaceX, pSoldier->sPanelFaceY, pSoldier->sPanelFaceX + TM_FACE_WIDTH, pSoldier->sPanelFaceY + TM_FACE_HEIGHT);
		}
	}


	if ( pSoldier->fDeadPanel )
	{
		 if ( TIMECOUNTERDONE(  pSoldier->PanelAnimateCounter, 160 ) )
		 {
				pSoldier->ubDeadPanelFrame++;

				if ( pSoldier->ubDeadPanelFrame == 4 )
				{
					ScreenMsg(FONT_RED, MSG_SKULL_UI_FEEDBACK, pMercDeadString, pSoldier->name);

					PlayJA2Sample(DOORCR_1, HIGHVOLUME, 1, MIDDLEPAN);
					PlayJA2Sample(HEADCR_1, HIGHVOLUME, 1, MIDDLEPAN);
				}

				if ( pSoldier->ubDeadPanelFrame > 5 )
				{
					pSoldier->fDeadPanel = FALSE;
					pSoldier->ubDeadPanelFrame = 5;
					pSoldier->fClosePanelToDie = FALSE;

					// Finish!
					if (!pSoldier->face->fDisabled)
					{
						BltVideoObject(guiSAVEBUFFER, guiDEAD, pSoldier->ubDeadPanelFrame, pSoldier->sPanelFaceX, pSoldier->sPanelFaceY);

						// Blit hatch!
						BltVideoObject(guiSAVEBUFFER, guiHATCH, 0, pSoldier->sPanelFaceX, pSoldier->sPanelFaceY);

						RestoreExternBackgroundRect( pSoldier->sPanelFaceX, pSoldier->sPanelFaceY, TM_FACE_WIDTH, TM_FACE_HEIGHT );
					}
					HandlePlayerTeamMemberDeathAfterSkullAnimation( pSoldier );

				}
				RESETTIMECOUNTER( pSoldier->PanelAnimateCounter, 160 );
		 }
	}

	if ( pSoldier->fDeadPanel )
	{
		// Render panel!
		if (!pSoldier->face->fDisabled)
		{
			BltVideoObject(FRAME_BUFFER, guiDEAD, pSoldier->ubDeadPanelFrame, pSoldier->sPanelFaceX, pSoldier->sPanelFaceY);

			// Blit hatch!
			BltVideoObject(guiSAVEBUFFER, guiHATCH, 0, pSoldier->sPanelFaceX, pSoldier->sPanelFaceY);

			InvalidateRegion(pSoldier->sPanelFaceX, pSoldier->sPanelFaceY, pSoldier->sPanelFaceX + TM_FACE_WIDTH, pSoldier->sPanelFaceY + TM_FACE_HEIGHT);
		}
	}
}


static void RenderSoldierTeamInv(SOLDIERTYPE* pSoldier, INT16 sX, INT16 sY, UINT8 ubPanelNum, BOOLEAN fDirty)
{
	if ( pSoldier->bActive && !(pSoldier->uiStatusFlags & SOLDIER_DEAD ) )
	{
		if ( pSoldier->uiStatusFlags & SOLDIER_DRIVER )
		{
			BltVideoObject(guiSAVEBUFFER, guiVEHINV, 0, sX, sY);
			RestoreExternBackgroundRect( sX, sY, (INT16)( TM_INV_WIDTH ) , (INT16)( TM_INV_HEIGHT ) );
		}
		else
		{
			// Look in primary hand
			INVRenderItem(guiSAVEBUFFER, pSoldier, &pSoldier->inv[HANDPOS], sX, sY, TM_INV_WIDTH, TM_INV_HEIGHT, fDirty, 0, TRANSPARENT);
		}

		if ( pSoldier->uiStatusFlags & ( SOLDIER_PASSENGER | SOLDIER_DRIVER ) )
		{
			BltVideoObject(guiSAVEBUFFER, guiVEHINV, 1, sX, sY + TM_INV_HAND_SEPY);
			RestoreExternBackgroundRect( sX, (INT16)(sY + TM_INV_HAND_SEPY), (INT16)(TM_INV_WIDTH ) , (INT16)( TM_INV_HEIGHT ) );
		}
		else
		{
			// Do secondary hand
			INVRenderItem(guiSAVEBUFFER, pSoldier, &pSoldier->inv[SECONDHANDPOS], sX, sY + TM_INV_HAND_SEPY, TM_INV_WIDTH, TM_INV_HEIGHT, fDirty, 0, TRANSPARENT);
		}
	}
}


static void TMClickFirstHandInvCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	const UINT8 ubID     = MSYS_GetRegionUserData(pRegion, 0);
	SOLDIERTYPE* const s = gTeamPanel[ubID].merc;
	if (s == NULL) return;

	if (iReason == MSYS_CALLBACK_REASON_LBUTTON_UP )
	{
		// Change to use cursor mode...
		guiPendingOverrideEvent = A_ON_TERRAIN;
	}

	if (iReason == MSYS_CALLBACK_REASON_RBUTTON_UP )
	{
		if (!AM_A_ROBOT(s))
		{
			const UINT16 usOldHandItem = s->inv[HANDPOS].usItem;
			SwapHandItems(s);
			ReLoadSoldierAnimationDueToHandItemChange(s, usOldHandItem, s->inv[HANDPOS].usItem);
			fInterfacePanelDirty = DIRTYLEVEL2;
		}
	}
}


static void TMClickSecondHandInvCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	const UINT8 ubID     = MSYS_GetRegionUserData(pRegion, 0);
	SOLDIERTYPE* const s = gTeamPanel[ubID].merc;
	if (s == NULL) return;

	if (iReason == MSYS_CALLBACK_REASON_LBUTTON_UP )
	{
		if (s->uiStatusFlags & (SOLDIER_PASSENGER | SOLDIER_DRIVER))
		{
			ExitVehicle(s);
		}
	}

	if (iReason == MSYS_CALLBACK_REASON_RBUTTON_UP )
	{
		if (s->uiStatusFlags & (SOLDIER_PASSENGER | SOLDIER_DRIVER))
		{
		}
		else
		{
			if (!AM_A_ROBOT(s))
			{
				const UINT16 usOldHandItem = s->inv[HANDPOS].usItem;
				SwapHandItems(s);
				ReLoadSoldierAnimationDueToHandItemChange(s, usOldHandItem, s->inv[HANDPOS].usItem);
				fInterfacePanelDirty = DIRTYLEVEL2;
			}
		}
	}
}


static BOOLEAN PlayerExistsInSlot(const SOLDIERTYPE* const s)
{
	INT32 cnt;

	for ( cnt = 0; cnt < NUM_TEAM_SLOTS; cnt++ )
	{
		if (gTeamPanel[cnt].merc == s) return TRUE;
	}

	return( FALSE );
}


static INT8 GetTeamSlotFromPlayer(const SOLDIERTYPE* const s)
{
	INT8 cnt;

	for ( cnt = 0; cnt < NUM_TEAM_SLOTS; cnt++ )
	{
		if (gTeamPanel[cnt].merc == s) return cnt;
	}

	return( -1 );
}


static BOOLEAN RemovePlayerFromInterfaceTeamSlot(UINT8 ubPanelSlot);


BOOLEAN RemovePlayerFromTeamSlot(const SOLDIERTYPE* const s)
{
	INT32 cnt;

	for ( cnt = 0; cnt < NUM_TEAM_SLOTS; cnt++ )
	{
		if (gTeamPanel[cnt].merc == s)
		{
			RemovePlayerFromInterfaceTeamSlot(cnt);
			return TRUE;
		}
	}

	return( FALSE );
}


void AddPlayerToInterfaceTeamSlot(SOLDIERTYPE* const s)
{
	// If we are a vehicle don't ever add.....
	if (s->uiStatusFlags & SOLDIER_VEHICLE) return;

	if (PlayerExistsInSlot(s)) return;

	// Find a free slot
	for (INT32 cnt = 0; cnt < NUM_TEAM_SLOTS; ++cnt)
	{
		if (gTeamPanel[cnt].merc == NULL)
		{
			gTeamPanel[cnt].merc = s;

			// DIRTY INTERFACE
			fInterfacePanelDirty = DIRTYLEVEL2;
			break;
		}
	}
}


BOOLEAN InitTEAMSlots(void)
{
	for (INT32 i = 0; i < NUM_TEAM_SLOTS; i++) gTeamPanel[i].merc = NULL;
	return( TRUE );
}


SOLDIERTYPE* GetPlayerFromInterfaceTeamSlot(UINT8 ubPanelSlot)
{
	if (ubPanelSlot >= NUM_TEAM_SLOTS) return NULL;
	return gTeamPanel[ubPanelSlot].merc;
}


void RemoveAllPlayersFromSlot(void)
{
	int cnt;

	for ( cnt = 0; cnt < NUM_TEAM_SLOTS; cnt++ )
	{
		RemovePlayerFromInterfaceTeamSlot( (UINT8)cnt );
	}
}


static BOOLEAN RemovePlayerFromInterfaceTeamSlot(UINT8 ubPanelSlot)
{
	if ( ubPanelSlot >= NUM_TEAM_SLOTS )
	{
		return( FALSE );
	}

	SOLDIERTYPE* const s = gTeamPanel[ubPanelSlot].merc;
	if (s == NULL) return FALSE;

	if (!(s->uiStatusFlags & SOLDIER_DEAD))
	{
		// Set Id to close
		s->fUICloseMerc = TRUE;
	}

	// Set face to inactive...
	SetAutoFaceInActive(s->face);

	gTeamPanel[ubPanelSlot].merc = NULL;

	// DIRTY INTERFACE
	fInterfacePanelDirty = DIRTYLEVEL2;

	return TRUE;
}


void RenderTownIDString(void)
{
	CHAR16	zTownIDString[80];
	INT16 sFontX, sFontY;

	// Render town, position
	SetFont( COMPFONT );
	SetFontForeground( 183 );
	SetFontBackground( FONT_BLACK );

	GetSectorIDString( gWorldSectorX, gWorldSectorY, gbWorldSectorZ, zTownIDString, lengthof(zTownIDString), TRUE );
	ReduceStringLength( zTownIDString, lengthof(zTownIDString), 80, COMPFONT );
	FindFontCenterCoordinates(548, SCREEN_HEIGHT - 55, 80, 16, zTownIDString, COMPFONT, &sFontX, &sFontY);
	mprintf( sFontX, sFontY, L"%ls", zTownIDString );
}


void CheckForAndAddMercToTeamPanel(SOLDIERTYPE* pSoldier)
{

	if ( pSoldier->bActive  )
	{
		// Add to interface if the are ours
		if ( pSoldier->bTeam == gbPlayerNum )
		{
			// Are we in the loaded sector?
			if ( pSoldier->sSectorX == gWorldSectorX && pSoldier->sSectorY == gWorldSectorY && pSoldier->bSectorZ == gbWorldSectorZ && !pSoldier->fBetweenSectors && pSoldier->bInSector )
			{
				// IF on duty....
				if( ( pSoldier->bAssignment ==  CurrentSquad( ) )|| ( SoldierIsDeadAndWasOnSquad( pSoldier, ( INT8 )( CurrentSquad( ) ) ) ) )
				{

					if( pSoldier->bAssignment == ASSIGNMENT_DEAD )
					{
						pSoldier->fUICloseMerc = FALSE;
					}
					// ATE: ALrighty, if we have the insertion code of helicopter..... don't add just yet!
					/// ( will add in heli code )
					if ( pSoldier->ubStrategicInsertionCode != INSERTION_CODE_CHOPPER )
					{
						AddPlayerToInterfaceTeamSlot(pSoldier);
					}

					// ARE WE A VEHICLE.....
					if ( pSoldier->uiStatusFlags & SOLDIER_VEHICLE )
					{
						AddPassangersToTeamPanel( pSoldier->bVehicleID );
					}
				}
			}
			else
			{
				// Make sure we are NOT in this world!
				// Set gridno to one that's not visib;l
				RemoveSoldierFromGridNo( pSoldier );

				// Remove slot from tactical
				RemoveMercSlot( pSoldier );

			}
		}
	}
}


SOLDIERTYPE* FindNextMercInTeamPanel(SOLDIERTYPE* const prev)
{
	INT32 cnt;
  INT32 bFirstID;

	bFirstID = GetTeamSlotFromPlayer(prev);
	if (bFirstID == -1) return prev;

	for ( cnt = ( bFirstID + 1 ); cnt < NUM_TEAM_SLOTS; cnt++ )
	{
		SOLDIERTYPE* const next = gTeamPanel[cnt].merc;
		if (next != NULL &&
				OK_CONTROLLABLE_MERC(next) &&
				OK_INTERRUPT_MERC(next) &&
				prev->bAssignment == next->bAssignment)
		{
			return next;
		}
  }

	// none found,
	// Now loop back
	for ( cnt = 0; cnt < bFirstID; cnt++ )
	{
		SOLDIERTYPE* const next = gTeamPanel[cnt].merc;
		if (next != NULL &&
				OK_CONTROLLABLE_MERC(next) &&
				OK_INTERRUPT_MERC(next) &&
				prev->bAssignment == next->bAssignment)
		{
			return next;
		}
	}

	// IF we are here, keep as we always were!
	return prev;
}


void DisableTacticalTeamPanelButtons(BOOLEAN fDisable)
{
	gfDisableTacticalPanelButtons = fDisable;
}


void BeginKeyPanelFromKeyShortcut(void)
{
	SOLDIERTYPE *pSoldier = NULL;
	INT16 sStartYPosition = 0;
	INT16 sWidth = 0, sHeight = 0;

	if ( gsCurInterfacePanel != SM_PANEL )
	{
		return;
	}

	if ( gpSMCurrentMerc == NULL )
	{
		return;
	}

	if ( gfInKeyRingPopup )
	{
		return;
	}


	sStartYPosition = INV_INTERFACE_START_Y;
	sWidth  = SCREEN_WIDTH;
	sHeight = SCREEN_HEIGHT - INV_INTERFACE_START_Y;
	pSoldier = gpSMCurrentMerc;

	//if we are in the shop keeper interface
	if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
		return;

	InitKeyRingPopup( pSoldier, 0, sStartYPosition, sWidth, sHeight );
}


void KeyRingItemPanelButtonCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	SOLDIERTYPE *pSoldier = NULL;
	INT16 sStartYPosition = 0;
	INT16 sWidth = 0, sHeight = 0;

	if( guiCurrentScreen == MAP_SCREEN )
	{
		pSoldier = GetSelectedInfoChar();
		if (pSoldier == NULL) return;

		sStartYPosition = MAP_START_KEYRING_Y;
		sWidth = 261;
		sHeight = ( 359 - 107 );
	}
	else
	{
		if ( gpSMCurrentMerc == NULL )
		{
			return;
		}

		sStartYPosition = INV_INTERFACE_START_Y;
		sWidth   = SCREEN_WIDTH;
		sHeight  = SCREEN_HEIGHT - INV_INTERFACE_START_Y;
		pSoldier = gpSMCurrentMerc;
	}

	//if we are in the shop keeper interface
	if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
		return;

	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		if( guiCurrentScreen == MAP_SCREEN )
		{
			// shade the background
			ShadowVideoSurfaceRect( FRAME_BUFFER , 0, 107, 261, 359 );
			InvalidateRegion( 0, 107, 261, 359 );
		}

		InitKeyRingPopup( pSoldier, 0, sStartYPosition, sWidth, sHeight );
	}
}

void KeyRingSlotInvClickCallback( MOUSE_REGION * pRegion, INT32 iReason )
{
	UINT32 uiKeyRing;
	// Copyies of values
	UINT16	usOldItemIndex;
	static BOOLEAN	fRightDown = FALSE;
	static BOOLEAN	fLeftDown = FALSE;
	INT32 iNumberOfKeysTaken = 0;

	uiKeyRing = MSYS_GetRegionUserData( pRegion, 0 );

	//if (iReason & MSYS_CALLBACK_REASON_LBUTTON_DWN )
	//{
	//	fLeftDown = TRUE;
	//}
	//else if (iReason & MSYS_CALLBACK_REASON_LBUTTON_UP && fLeftDown )
	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_DWN )
	{
		fLeftDown = FALSE;

		//if we are in the shop keeper interface
		if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
		{
			INVENTORY_IN_SLOT InvSlot;

			if( gMoveingItem.sItemIndex == 0 )
			{
				//Delete the contents of the item cursor
				memset( &gMoveingItem, 0, sizeof( INVENTORY_IN_SLOT ) );
			}
			else
			{
				memset( &InvSlot, 0, sizeof( INVENTORY_IN_SLOT ) );

				// Return if empty
				//if ( gpSMCurrentMerc->inv[ uiHandPos ].usItem == NOTHING )
				//	return;


				// Fill out the inv slot for the item
				//InvSlot.sItemIndex = gpSMCurrentMerc->inv[ uiHandPos ].usItem;
//			InvSlot.ubNumberOfItems = gpSMCurrentMerc->inv[ uiHandPos ].ubNumberOfObjects;
//			InvSlot.ubItemQuality = gpSMCurrentMerc->inv[ uiHandPos ].bGunStatus;
				//InvSlot.ItemObject = gpSMCurrentMerc->inv[uiHandPos];
				//InvSlot.ubLocationOfObject = PLAYERS_INVENTORY;

				//InvSlot.ubIdOfMercWhoOwnsTheItem = gpSMCurrentMerc->ubProfile;


				//Add the item to the Players Offer Area
				//AddItemToPlayersOfferArea( gpSMCurrentMerc->ubProfile, &InvSlot, (UINT8)uiHandPos );

				// Dirty
				fInterfacePanelDirty = DIRTYLEVEL2;
			}
			return;
		}

		// If we do not have an item in hand, start moving it
		if ( gpItemPointer == NULL )
		{
			// Return if empty
			if( ( gpItemPopupSoldier->pKeyRing[ uiKeyRing ].ubKeyID == INVALID_KEY_NUMBER ) || ( gpItemPopupSoldier->pKeyRing[ uiKeyRing ].ubNumber == 0 ) )
				return;

			// If our flags are set to do this, gofoit!
			if ( (guiTacticalInterfaceFlags & INTERFACE_MAPSCREEN ) )
			{
			}
			else
			{
				SelectSoldier(gpItemPopupSoldier, SELSOLDIER_NONE);
			}

			usOldItemIndex =  ( UINT16 )uiKeyRing ;

			BeginKeyRingItemPointer( gpItemPopupSoldier, (UINT8)usOldItemIndex );
			//BeginItemPointer( gpSMCurrentMerc, (UINT8)uiHandPos );

		}
		else
		{
			BOOLEAN		fOKToGo = FALSE;
			BOOLEAN		fDeductPoints = FALSE;

			if( ( gpItemPointer ->usItem < FIRST_KEY ) || ( gpItemPointer ->usItem > KEY_32 ) )
			{
				return;
			}

			// ATE: OK, get source, dest guy if different... check for and then charge appropriate APs
			if (gpItemPointerSoldier == NULL ||
					gpItemPointerSoldier == GetSelectedInfoChar())
			{
				// We are doing this ourselve, continue
				fOKToGo = TRUE;
			}
			else
			{
				// These guys are different....
				fDeductPoints = TRUE;

				// First check points for src guy
				if ( gpItemPointerSoldier->bLife >= CONSCIOUSNESS )
				{
					if ( EnoughPoints( gpItemPointerSoldier, 2, 0, TRUE ) )
					{
						fOKToGo = TRUE;
					}
				}
				else
				{
					fOKToGo = TRUE;
				}

				// Should we go on?
				if ( fOKToGo )
				{
					if ( gpSMCurrentMerc->bLife >= CONSCIOUSNESS )
					{
						if ( EnoughPoints( gpSMCurrentMerc, 2, 0, TRUE ) )
						{
							fOKToGo = TRUE;
						}
						else
						{
							fOKToGo = FALSE;
						}
					}
				}
			}

			if ( fOKToGo )
			{
				//usOldItemIndex = gpSMCurrentMerc->inv[ uiHandPos ].usItem;
				//usNewItemIndex = gpItemPointer->usItem;

				if ( gpItemPopupSoldier->pKeyRing[ uiKeyRing ].ubKeyID == INVALID_KEY_NUMBER || gpItemPopupSoldier->pKeyRing[ uiKeyRing ].ubKeyID == gpItemPointer->ubKeyID)
				{
					// Try to place here
					if ( ( iNumberOfKeysTaken = AddKeysToSlot( gpItemPopupSoldier, ( INT8 )uiKeyRing, gpItemPointer ) ) )
					{

						if ( fDeductPoints )
						{
							// Deduct points
							if ( gpItemPointerSoldier->bLife >= CONSCIOUSNESS )
							{
								DeductPoints( gpItemPointerSoldier,  2, 0 );
							}
							if ( gpItemPopupSoldier->bLife >= CONSCIOUSNESS )
							{
								DeductPoints( gpItemPopupSoldier,  2, 0 );
							}
						}

						// Dirty
						fInterfacePanelDirty = DIRTYLEVEL2;

						gpItemPointer->ubNumberOfObjects -= ( UINT8 )iNumberOfKeysTaken;

						// Check if it's the same now!
						if ( gpItemPointer->ubNumberOfObjects == 0 )
						{
							if ( guiTacticalInterfaceFlags & INTERFACE_MAPSCREEN )
							{
								MAPEndItemPointer();
							}
							else
							{
								EndItemPointer();
							}
						}

						// Setup a timer....
						//guiMouseOverItemTime = GetJA2Clock( );
						//gfCheckForMouseOverItem = TRUE;
						//gbCheckForMouseOverItemPos = (INT8)uiHandPos;

					}
				}
				else
				{
					// Swap!
					SwapKeysToSlot( gpItemPopupSoldier, (INT8) uiKeyRing, gpItemPointer );

					if ( fDeductPoints )
					{
						// Deduct points
						if ( gpItemPointerSoldier && gpItemPointerSoldier->bLife >= CONSCIOUSNESS )
						{
							DeductPoints( gpItemPointerSoldier,  2, 0 );
						}
						if ( gpSMCurrentMerc->bLife >= CONSCIOUSNESS )
						{
							DeductPoints( gpSMCurrentMerc,  2, 0 );
						}
					}

					// Dirty
					fInterfacePanelDirty = DIRTYLEVEL2;

				}
			}
		}

		UpdateItemHatches();
	}
	else if (iReason & MSYS_CALLBACK_REASON_RBUTTON_DWN)
	{
		fRightDown = TRUE;
	}
	else if (iReason & MSYS_CALLBACK_REASON_RBUTTON_UP && fRightDown )
	{
		fRightDown = FALSE;

		// Return if empty
		if( ( gpItemPopupSoldier->pKeyRing[ uiKeyRing ].ubKeyID == INVALID_KEY_NUMBER ) || ( gpItemPopupSoldier->pKeyRing[ uiKeyRing ].ubNumber == 0 ) )
		{
			DeleteKeyRingPopup( );
			fTeamPanelDirty = TRUE;
			return;
		}
		// Some global stuff here - for esc, etc
		// Check for # of slots in item
		if ( !InItemDescriptionBox( ) )
		{
			if ( guiTacticalInterfaceFlags & INTERFACE_MAPSCREEN )
			{
				//InitKeyItemDescriptionBox(gpItemPopupSoldier, (UINT8)uiKeyRing, MAP_ITEMDESC_START_X, MAP_ITEMDESC_START_Y);
      }
      else
      {
				InitKeyItemDescriptionBox(gpItemPopupSoldier, (UINT8)uiKeyRing, SM_ITEMDESC_START_X, SM_ITEMDESC_START_Y);
      }
		}
	}
	else if (iReason & MSYS_CALLBACK_REASON_LOST_MOUSE )
	{
		fRightDown = FALSE;
		fLeftDown = FALSE;
	}

}


void DisableSMPpanelButtonsWhenInShopKeeperInterface(void)
{
	//Go through the buttons that will be under the ShopKeepers ATM panel and disable them
	DisableButton( iSMPanelButtons[ STANCEUP_BUTTON ] );
	DisableButton( iSMPanelButtons[ UPDOWN_BUTTON ] );
	DisableButton( iSMPanelButtons[ CLIMB_BUTTON ] );
	DisableButton( iSMPanelButtons[ STANCEDOWN_BUTTON ] );
	DisableButton( iSMPanelButtons[ HANDCURSOR_BUTTON ] );
	DisableButton( iSMPanelButtons[ BURSTMODE_BUTTON ] );
	DisableButton( iSMPanelButtons[ LOOK_BUTTON ] );
	DisableButton( iSMPanelButtons[ TALK_BUTTON ] );
	DisableButton( iSMPanelButtons[ MUTE_BUTTON ] );

	DisableButton( giSMStealthButton );

	//Make sure the options button is disabled
	DisableButton( iSMPanelButtons[ OPTIONS_BUTTON ] );

	//Make sure the mapscreen button is disabled
	DisableButton( iSMPanelButtons[ SM_MAP_SCREEN_BUTTON ] );

	DisableButton( iSMPanelButtons[ STANCEUP_BUTTON ] );
	DisableButton( iSMPanelButtons[ UPDOWN_BUTTON ] );
	DisableButton( iSMPanelButtons[ CLIMB_BUTTON ] );
	DisableButton( iSMPanelButtons[ STANCEDOWN_BUTTON ] );
	DisableButton( iSMPanelButtons[ HANDCURSOR_BUTTON ] );
	DisableButton( iSMPanelButtons[ BURSTMODE_BUTTON ] );
	DisableButton( iSMPanelButtons[ LOOK_BUTTON ] );
	DisableButton( iSMPanelButtons[ TALK_BUTTON ] );
	DisableButton( iSMPanelButtons[ MUTE_BUTTON ] );

	DisableButton( giSMStealthButton );
}


static BOOLEAN IsMouseInRegion(MOUSE_REGION* pRegion)
{
	if ( (gusMouseXPos >= pRegion->RegionTopLeftX ) && (gusMouseXPos <= pRegion->RegionBottomRightX ) && (gusMouseYPos >= pRegion->RegionTopLeftY ) && (gusMouseYPos <= pRegion->RegionBottomRightY ) )
	{
		return( TRUE );
	}
	else
	{
		return( FALSE );
	}
}


static void ConfirmationToDepositMoneyToPlayersAccount(UINT8 ubExitValue);


static void SMInvMoneyButtonCallback(MOUSE_REGION* pRegion, INT32 iReason)
{
	if (iReason == MSYS_CALLBACK_REASON_LBUTTON_DWN )
	{
		//If the current merc is to far away, dont allow anything to be done
		if( gfSMDisableForItems )
			return;

		//if the player has an item in his hand,
		if( gpItemPointer != NULL )
		{
			//and the item is money
			if( Item[ gpItemPointer->usItem ].usItemClass == IC_MONEY )
			{
				CHAR16	zText[512];
				CHAR16	zMoney[64];

        // Make sure we go back to movement mode...
		    guiPendingOverrideEvent = A_CHANGE_TO_MOVE;
		    HandleTacticalUI( );

				SPrintMoney(zMoney, gpItemPointer->uiMoneyAmount);

				//ask the user if they are sure they want to deposit the money
				swprintf( zText, lengthof(zText), gzMoneyWithdrawMessageText[ CONFIRMATION_TO_DEPOSIT_MONEY_TO_ACCOUNT ], zMoney );

				if( guiCurrentScreen == SHOPKEEPER_SCREEN )
				{
					//if we are in the shop keeper interface, free the cursor
					if( guiTacticalInterfaceFlags & INTERFACE_SHOPKEEP_INTERFACE )
					{
						FreeMouseCursor();
					}

					DoMessageBox( MSG_BOX_BASIC_STYLE, zText, SHOPKEEPER_SCREEN, ( UINT8 )MSG_BOX_FLAG_YESNO, ConfirmationToDepositMoneyToPlayersAccount, NULL );
				}
				else
					DoMessageBox( MSG_BOX_BASIC_STYLE, zText, GAME_SCREEN, ( UINT8 )MSG_BOX_FLAG_YESNO, ConfirmationToDepositMoneyToPlayersAccount, NULL );
			}
		}

		//else bring up the money item description box to remove money from the players account
		else
		{
			//set the flag indicating we are removing money from the players account
			gfAddingMoneyToMercFromPlayersAccount = TRUE;

			//create the temp object from the players account balance
//			if( LaptopSaveInfo.iCurrentBalance > MAX_MONEY_PER_SLOT )
//				CreateMoney( MAX_MONEY_PER_SLOT, &gItemPointer );
//			else
				CreateMoney( LaptopSaveInfo.iCurrentBalance, &gItemPointer );

			InternalInitItemDescriptionBox( &gItemPointer, SM_ITEMDESC_START_X, SM_ITEMDESC_START_Y, 0, gpSMCurrentMerc );
		}
	}
}


static void ConfirmationToDepositMoneyToPlayersAccount(UINT8 ubExitValue)
{
	if ( ubExitValue == MSG_BOX_RETURN_YES )
	{
		//add the money to the players account
		AddTransactionToPlayersBook( MERC_DEPOSITED_MONEY_TO_PLAYER_ACCOUNT, gpSMCurrentMerc->ubProfile, GetWorldTotalMin(), gpItemPointer->uiMoneyAmount );

		// dirty shopkeeper
		gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;

		EndItemPointer( );
	}
}


void ReEvaluateDisabledINVPanelButtons(void)
{
	gfReEvaluateDisabledINVPanelButtons = TRUE;
}


static void CheckForReEvaluateDisabledINVPanelButtons(void)
{
	// OK, if we currently have an item pointer up....
	if ( gfReEvaluateDisabledINVPanelButtons )
	{
		if ( gpItemPointer || gfInItemPickupMenu )
		{
			EnableSMPanelButtons( FALSE, TRUE );
		}
		else
		{
			EnableSMPanelButtons( TRUE, TRUE );
		}

		gfReEvaluateDisabledINVPanelButtons = FALSE;
	}
}


static void AbandonBoxingCallback(UINT8 ubExitValue)
{
	if ( ubExitValue == MSG_BOX_RETURN_YES )
	{
		// ok, proceed!
		SetBoxingState( NOT_BOXING );
		gfEnteringMapScreen = TRUE;
	}
	// otherwise do nothing
}


void GoToMapScreenFromTactical(void)
{
	if ( gTacticalStatus.bBoxingState != NOT_BOXING )
	{
		// pop up dialogue asking whether the player wants to abandon the fight
		DoMessageBox( MSG_BOX_BASIC_STYLE, Message[ STR_ABANDON_FIGHT ], GAME_SCREEN, ( UINT8 )MSG_BOX_FLAG_YESNO, AbandonBoxingCallback, NULL );
		return;
	}
	// ok, proceed!
	gfEnteringMapScreen = TRUE;
}


void HandleTacticalEffectsOfEquipmentChange(SOLDIERTYPE* pSoldier, UINT32 uiInvPos, UINT16 usOldItem, UINT16 usNewItem)
{
	// if in attached weapon mode and don't have weapon with GL attached in hand, reset weapon mode
	if ( pSoldier->bWeaponMode == WM_ATTACHED && FindAttachment( &(pSoldier->inv[ HANDPOS ]), UNDER_GLAUNCHER ) == NO_SLOT )
	{
		pSoldier->bWeaponMode = WM_NORMAL;
		pSoldier->bDoBurst = FALSE;
	}

	// if he is loaded tactically
	if ( pSoldier->bInSector )
	{
		// If this is our main hand
		if ( uiInvPos == HANDPOS || uiInvPos == SECONDHANDPOS )
		{
			// check if we need to change animation!
			ReLoadSoldierAnimationDueToHandItemChange( pSoldier, usOldItem, usNewItem );
		}

		// if this is head gear
		if ( uiInvPos == HEAD1POS || uiInvPos == HEAD2POS )
		{
			// Could be because of GOGGLES change...  Re-create light...
			DeleteSoldierLight( pSoldier );
			PositionSoldierLight( pSoldier );
		}
	}
	else
	{
		// as a minimum
		if ( (Item[ pSoldier->inv[ HANDPOS ].usItem ].usItemClass & IC_WEAPON) && Weapon[ pSoldier->inv[ HANDPOS ].usItem ].ubShotsPerBurst == 0 )
		{
			pSoldier->bDoBurst		= FALSE;
			pSoldier->bWeaponMode = WM_NORMAL;
		}
	}
}