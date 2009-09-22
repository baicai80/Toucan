/////////////////////////////////////////////////////////////////////////////////
// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2007-2009 Steven Lamerton
// License:     GNU GPL 2 (See readme for more info)
/////////////////////////////////////////////////////////////////////////////////

#ifndef _FRMMAIN_H_
#define _FRMMAIN_H_

class wxFrame;
class wxTreeCtrl;
class wxDirCtrl;
class wxListCtrl;
class wxListEvent;
class wxHtmlHelpWindow;
class wxFontPickerCtrl;
class wxVirtualDirTreeCtrl;
class wxTreeEvent;
class wxComboBox;
class wxTextCtrl;
class wxCheckBox;
class wxStaticText;
class wxListBox;
class wxRadioBox;
class wxSlider;

class Settings;
class ExtendedDirCtrl;

#include <wx/aui/framemanager.h>
#include <wx/aui/auibook.h>

//Main controls 10000-10049
#define ID_AUIFRAME 10000
#define ID_AUINOTEBOOK 10001

//Sync 10050-10099
#define ID_PANEL_SYNC 10050
#define ID_SYNC_OK 10051
#define ID_SYNC_PREVIEW 10052
#define ID_SYNC_JOB_SELECT 11053
#define ID_SYNC_JOB_SAVE 10054
#define ID_SYNC_JOB_ADD 10055
#define ID_SYNC_JOB_REMOVE 10056
#define ID_SYNC_RULES 10057
#define ID_SYNC_SOURCE_TXT 10058
#define ID_SYNC_SOURCE_BTN 10059
#define ID_SYNC_SOURCE_TREE 10060
#define ID_SYNC_SOURCE_EXPAND 10061
#define ID_SYNC_DEST_TXT 10062
#define ID_SYNC_DEST_BTN 10063
#define ID_SYNC_DEST_TREE 10064
#define ID_SYNC_DEST_EXPAND 10065
#define ID_SYNC_FUNCTION 10066
#define ID_SYNC_TIMESTAMP 10067
#define ID_SYNC_ATTRIB 10068
#define ID_SYNC_IGNORERO 10069
#define ID_SYNC_IGNOREDS 10070
#define ID_SYNC_MOVE 10071
#define ID_SYNC_SOURCE_INSERT 10072
#define ID_SYNC_DEST_INSERT 10073
#define ID_SYNC_SOURCE_REFRESH 10074
#define ID_SYNC_DEST_REFRESH 10075

//Backup 10100-10149
#define ID_PANEL_BACKUP 10100
#define ID_BACKUP_OK 10101
#define ID_BACKUP_PREVIEW 10102
#define ID_BACKUP_JOB_SELECT 10104
#define ID_BACKUP_JOB_SAVE 10105
#define ID_BACKUP_JOB_ADD 10106
#define ID_BACKUP_JOB_REMOVE 10107
#define ID_BACKUP_RULES 10108
#define ID_BACKUP_LOCATION_TEXT 10109
#define ID_BACKUP_STATIC 10110
#define ID_BACKUP_LOCATION 10111
#define ID_BACKUP_DIRCTRL 10112
#define ID_BACKUP_ADD 10113
#define ID_BACKUP_REMOVE 10114
#define ID_BACKUP_TREECTRL 10115
#define ID_BACKUP_ADDVAR 10116
#define ID_BACKUP_FUNCTION 10117
#define ID_BACKUP_FORMAT 10118
#define ID_BACKUP_RATIO 10119
#define ID_BACKUP_ISPASS 10120
#define ID_BACKUP_EXPAND 10121
#define ID_BACKUP_LOCATIONSTATIC 10122
#define ID_BACKUP_FILESSTATIC 10123
#define ID_BACKUP_DIR_REFRESH 10124
#define ID_BACKUP_TREE_REFRESH 10125

//Secure 10150-10199
#define ID_PANEL_SECURE 10150
#define ID_SECURE_OK 10151
#define ID_SECURE_PREVIEW 10152
#define ID_SECURE_RULES 10153
#define ID_SECURE_JOB_SELECT 10154
#define ID_SECURE_JOB_SAVE 10155
#define ID_SECURE_JOB_ADD 10156
#define ID_SECURE_JOB_REMOVE 10157
#define ID_SECURE_DIRCTRL 10158
#define ID_SECURE_ADD 10159
#define ID_SECURE_REMOVE 10160
#define ID_SECURE_TREECTRL 10161
#define ID_SECURE_ADDVAR 10162
#define ID_SECURE_MAKERELATIVE 10163
#define ID_SECURE_FUNCTION 10164
#define ID_SECURE_PASS 10165
#define ID_SECURE_REPASS 10166
#define ID_SECURE_EXPAND 10167
#define ID_SECURE_DIR_REFRESH 10168
#define ID_SECURE_TREE_REFRESH 10169

//Rules 10200-10249
#define ID_PANEL_RULES 10200
#define ID_RULES_COMBO 10201
#define ID_RULES_SAVE 10202
#define ID_RULES_ADD 10203
#define ID_RULES_REMOVE 10204
#define ID_RULES_LIST 10205
#define ID_RULES_ADDITEM 10206
#define ID_RULES_REMOVEITEM 10207

//Variables 10250-10299
#define ID_PANEL_VARIABLES 10250
#define ID_VARIABLES_NAME 10251
#define ID_VARIABLES_LIST 10252
#define ID_VARIABLES_ADD 10253
#define ID_VARIABLES_REMOVE 10254
#define ID_VARIABLES_ADDITEM 10255
#define ID_VARIABLES_REMOVEITEM 10256
#define ID_VARIABLES_SAVE 10257

//Script 10300-10349
#define ID_PANEL_SCRIPT 10301
#define ID_SCRIPT_NAME 10302
#define ID_SCRIPT_SAVE 10303
#define ID_SCRIPT_ADD 10304
#define ID_SCRIPT_REMOVE 10305
#define ID_SCRIPT_RICH 10306
#define ID_SCRIPT_CHECK 10307
#define ID_SCRIPT_EXECUTE 10308

//Settings 10350-10399
#define ID_PANEL_SETTINGS 10350
#define ID_SETTINGS_TABSTYLE 10351
#define ID_SETTINGS_LANGUAGE 10352
#define ID_SETTINGS_FONT 10353
#define ID_SETTINGS_REMEMBERSYNC 10354
#define ID_SETTINGS_REMEMBERBACKUP 10355
#define ID_SETTINGS_REMEMBERSECURE 10356
#define ID_SETTINGS_ENABLETOOLTIPS 10357
#define ID_SETTINGS_SMALLBORDERS 10358

//Menu 10400-10449
#define ID_MENU_FILEEXCLUDE_EXTENSION 10400
#define ID_MENU_FILEEXCLUDE_NAME 10401
#define ID_MENU_FOLDEREXCLUDE_NAME 10402
#define ID_MENU_LOCATIONINCLUDE_NAME 10403
#define ID_MENU_LOCATIONINCLUDE_EXTENSION 10404

//Other 10450-10499

//Help 10500-10549
#define ID_PANEL_HELP 10500
#define ID_HELP 10501
#define ID_HELP_TESTS 10502

class frmMain: public wxFrame
{
	DECLARE_EVENT_TABLE()

public:
	// Constructor
	frmMain();

	//Destructor, for uninitialising AUI
	~frmMain();

	//Sets up all of the member vaiables
	void Init();

	// Creates the controls and sizers
	void CreateControls();
	
	//Set up the title bar test
	void SetTitleBarText();

	//Sync
	void OnSyncOKClick(wxCommandEvent& event);
	void OnSyncPreviewClick(wxCommandEvent& event);
	void OnSyncJobSelectSelected(wxCommandEvent& event);	
	void OnSyncJobSaveClick(wxCommandEvent& event);
	void OnSyncJobAddClick(wxCommandEvent& event);
	void OnSyncJobRemoveClick(wxCommandEvent& event);
	void OnSyncSourceExpandClick(wxCommandEvent& event);
	void OnSyncSourceBtnClick(wxCommandEvent& event);
	void OnSyncDestExpandClick(wxCommandEvent& event);
	void OnSyncDestBtnClick(wxCommandEvent& event);
	void OnSyncSourceTreeRightClick(wxTreeEvent& event);
	void OnSyncDestTreeRightClick(wxTreeEvent& event);
	void OnSyncTreeCtrlTooltip(wxTreeEvent& event);
	void OnSyncSourceInsertClick(wxCommandEvent& event);
	void OnSyncDestInsertClick(wxCommandEvent& event);
	void OnSyncSourceTxtEnter(wxCommandEvent& event);
	void OnSyncDestTxtEnter(wxCommandEvent& event);
	void OnSyncSourceRefresh(wxCommandEvent& event);
	void OnSyncDestRefresh(wxCommandEvent& event);
	
	//Backup
	void OnBackupOKClick(wxCommandEvent& event);
	void OnBackupRulesSelected(wxCommandEvent& event);
	void OnBackupLocationClick(wxCommandEvent& event);
	void OnBackupAddClick(wxCommandEvent& event);
	void OnBackupRemoveClick(wxCommandEvent& event);
	void OnBackupJobAddClick(wxCommandEvent& event);
	void OnBackupJobRemoveClick(wxCommandEvent& event);
	void OnBackupJobSelectSelected(wxCommandEvent& event);	
	void OnBackupJobSaveClick(wxCommandEvent& event);
	void OnBackupFunctionSelected(wxCommandEvent& event);
	void OnBackupExpandClick(wxCommandEvent& event);
	void OnBackupRatioChanged(wxScrollEvent& event);	
	void OnBackupAddVarClick(wxCommandEvent& event);
	void OnBackupTreeCtrlTooltip(wxTreeEvent& event);
	void OnBackupTreeRightClick(wxTreeEvent& event);
	void OnBackupDirRefresh(wxCommandEvent& event);
	void OnBackupTreeRefresh(wxCommandEvent& event);

	//Secure
	void OnSecureOKClick(wxCommandEvent& event);
	void OnSecureRulesSelected(wxCommandEvent& event);
	void OnSecureJobSelectSelected(wxCommandEvent& event);
	void OnSecureJobSaveClick(wxCommandEvent& event);
	void OnSecureJobAddClick(wxCommandEvent& event);
	void OnSecureJobRemoveClick(wxCommandEvent& event);
	void OnSecureAddClick(wxCommandEvent& event);
	void OnSecureRemoveClick(wxCommandEvent& event);
	void OnSecureAddVarClick(wxCommandEvent& event);
	void OnSecureExpandClick(wxCommandEvent& event);
	void OnSecureTreeCtrlTooltip(wxTreeEvent& event);
	void OnSecureTreeRightClick(wxTreeEvent& event);
	void OnSecureDirRefresh(wxCommandEvent& event);
	void OnSecureTreeRefresh(wxCommandEvent& event);
	
	//Rules
	void OnRulesComboSelected(wxCommandEvent& event);
	void OnRulesSaveClick(wxCommandEvent& event);
	void OnRulesAddClick(wxCommandEvent& event);
	void OnRulesRemoveClick(wxCommandEvent& event);
	void OnRulesAddItemClick(wxCommandEvent& event);
	void OnRulesRemoveItemClick(wxCommandEvent& event);
	void OnRulesItemActivated(wxListEvent& event);
	
	//Variables
	void OnVariablesSaveClick(wxCommandEvent& event);
	void OnVariablesAddClick(wxCommandEvent& event);
	void OnVariablesRemoveClick(wxCommandEvent& event);	
	void OnVariablesAddItemClick(wxCommandEvent& event);
	void OnVariablesRemoveItemClick(wxCommandEvent& event);
	void OnVariablesNameSelected(wxCommandEvent& event);
	void OnVariablesListActivated(wxListEvent& event);
	
	//Script
	void OnScriptExecute(wxCommandEvent& event);	
	void OnScriptSelected(wxCommandEvent& event);
	void OnScriptSaveClick(wxCommandEvent& event);	
	void OnScriptAddClick(wxCommandEvent& event);
	void OnScriptRemoveClick(wxCommandEvent& event);
		
	//Other
	void OnCloseWindow(wxCloseEvent& event);
	void OnAboutClick(wxCommandEvent& event);
	void OnSettingsFontClick(wxCommandEvent& event);
	void OnTabChanged(wxAuiNotebookEvent& event); 
	void OnSettingsApplyClick(wxCommandEvent& event);
	
	//Menu
	void OnMenuFileExcludeExtensionClick(wxCommandEvent& event);
	void OnMenuFileExcludeNameClick(wxCommandEvent& event);
	void OnMenuLocationIncludeExtensionClick(wxCommandEvent& event);
	void OnMenuLocationIncludeNameClick(wxCommandEvent& event);
	void OnMenuFolderExcludeNameClick(wxCommandEvent& event);
	
	//Job functions
	void JobAdd(wxComboBox* box);
	void JobRemove(wxComboBox* box);
	void JobSave(const wxString &name, const wxString &type);
	void JobLoad(const wxString &name, const wxString &type);
	
	//Reset the form to its empty state
	void ClearToDefault();
	
	//Run a job
	void Run(const wxString &type);
	
	//Create the popup menu for rules
	void CreateMenu(wxTreeEvent& event);
	
	//Update the backup compression slider
	void SetSliderText();
	
	//Language functions
	wxArrayString GetLanguages();
	wxArrayString GetTranslatorNames();

	// Retrieves bitmap resources
	wxBitmap GetBitmapResource(const wxString& name);
	
	//Force a sizer to update its layout and then refresh the window
	void UpdateSizer(wxSizer *sizer);
	
	//General
	wxAuiManager m_auiManager;
	wxAuiNotebook* m_Notebook;
	
	//Sync
	wxBoxSizer* SyncTopSizer;
	wxComboBox* m_Sync_Job_Select;
	wxComboBox* m_Sync_Rules;
	wxTextCtrl* m_Sync_Source_Txt;
	wxTextCtrl* m_Sync_Dest_Txt;
	wxVirtualDirTreeCtrl* m_Sync_Source_Tree;
	wxVirtualDirTreeCtrl* m_Sync_Dest_Tree;
	wxRadioBox* m_Sync_Function;
	wxCheckBox* m_Sync_Timestamp;
	wxCheckBox* m_Sync_Attributes;
	wxCheckBox* m_Sync_Ignore_Readonly;
	wxCheckBox* m_Sync_Ignore_DaylightS;
	
	//Backup
	wxBoxSizer* BackupTopSizer;
	wxComboBox* m_Backup_Job_Select;
	wxComboBox* m_Backup_Rules;
	wxStaticText* m_Backup_Location_Txt;
	wxStaticText* m_Backup_Ratio_Text;
	wxTextCtrl* m_Backup_Location;
	wxTextCtrl* m_Backup_Pass;
	wxTextCtrl* m_Backup_Repass;
	ExtendedDirCtrl* m_Backup_DirCtrl;
	wxVirtualDirTreeCtrl* m_Backup_TreeCtrl;
	wxRadioBox* m_Backup_Function;
	wxRadioBox* m_Backup_Format;
	wxSlider* m_Backup_Ratio;
	wxCheckBox* m_Backup_IsPass;
	
	//Secure
	wxBoxSizer* SecureTopSizer;
	wxComboBox* m_Secure_Rules;
	wxComboBox* m_Secure_Job_Select;
	ExtendedDirCtrl* m_Secure_DirCtrl;
	wxVirtualDirTreeCtrl* m_Secure_TreeCtrl;
	wxRadioBox* m_Secure_Function;
	wxTextCtrl* m_Secure_Pass;
	wxTextCtrl* m_Secure_Repass;
	
	//Rules
	wxComboBox* m_Rules_Name;
	wxListCtrl* m_RulesList;
	
	//Variables
	wxComboBox* m_Variables_Name;
	wxListCtrl* m_Variables_List;
	
	//Script
	wxTextCtrl* m_Script_Rich;
	wxComboBox* m_Script_Name;
	
	//Settings
	wxRadioBox* m_Settings_TabStyle;
	wxComboBox* m_Settings_Language;
 	wxButton* m_Settings_Font;
	wxCheckBox* m_Settings_RememberSync;
	wxCheckBox* m_Settings_RememberBackup;
	wxCheckBox* m_Settings_RememberSecure;
	wxCheckBox* m_Settings_EnableTooltips;
	wxCheckBox* m_Settings_SmallBorders;

	//Other
	wxArrayString* m_SecureLocations;
	wxArrayString* m_BackupLocations;
	wxVirtualDirTreeCtrl* menuTree;
	wxComboBox* menuRules;
	wxFont* m_Font;
	
	//Help
	wxHtmlHelpWindow* m_HelpWindow;
};

#endif
