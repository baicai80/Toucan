/////////////////////////////////////////////////////////////////////////////////
// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2009 - 2010 Steven Lamerton
// License:     GNU GPL 2 http://www.gnu.org/licenses/gpl-2.0.html
/////////////////////////////////////////////////////////////////////////////////

#include "securejob.h"
#include "../toucan.h"
#include "../rules.h"
#include "../path.h"
#include "../basicfunctions.h"
#include "../data/securedata.h"
#include "../forms/frmmain.h"

#include <wx/filefn.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/stdpaths.h>

SecureJob::SecureJob(SecureData *Data) : Job(Data){
	;
}

void* SecureJob::Entry(){
	SecureData *data = static_cast<SecureData*>(GetData());

	wxArrayString locations = data->GetLocations();

	for(unsigned int i = 0; i < locations.GetCount(); i++){
        data->SetLocation(i, Path::Normalise(data->GetLocation(i)));
	}

	//Iterate through the entries in the array
	for(unsigned int i = 0; i < locations.Count(); i++)
	{
		if(wxGetApp().GetAbort()){
			return NULL;
		}
		//Need to add normalisation to SecureData
		if(locations.Item(i) != wxEmptyString){
			if(wxDirExists(locations.Item(i))){
				CryptDir(locations.Item(i), data);
			}
			else{
				CryptFile(locations.Item(i), data);
			}
		}
	}
	return NULL;
}

bool SecureJob::CryptDir(const wxString &path, SecureData *data)
{   
	if(wxGetApp().GetAbort()){
		return true;
	}
	wxDir dir(path);
	wxString filename;
	bool blDir = dir.GetFirst(&filename);
	if (blDir)
	{
		do {
			if(wxGetApp().GetAbort()){
				return true;
			}
			if (wxDirExists(path + wxFILE_SEP_PATH + filename) ){
				CryptDir(path + wxFILE_SEP_PATH + filename, data);
			}
			else{
				CryptFile(path + wxFILE_SEP_PATH + filename, data);
			}
		}
		while (dir.GetNext(&filename) );
	}   
	return true;
}


bool SecureJob::CryptFile(const wxString &path, SecureData *data)
{
	if(wxGetApp().GetAbort()){
		return true;
	}
	//Check to see it the file should be excluded	
	if(data->GetRules()->ShouldExclude(path, false)){
		return true;
	}
	//Make sure that it is a 'real' file
	wxFileName filename(path);
	if(filename.IsOk() == true){
		wxString size = filename.GetHumanReadableSize();
		if(size == wxT("Not available")){
			return false;
		}
	}

	//Ensure that we are not encrypting an already encrypted file or decrypting a non encrypted file
	if(filename.GetExt() == wxT("cpt") && data->GetFunction() == _("Encrypt")){
		return false;
	}
	if(filename.GetExt() != wxT("cpt") && data->GetFunction() == _("Decrypt")){
		return false;
	}	

	//Set the file attributes to normal
#ifdef __WXMSW__   
		int filearrtibs = GetFileAttributes(path);
		SetFileAttributes(path, FILE_ATTRIBUTE_NORMAL);  
#endif

	wxString command;
	const wxString exepath = wxPathOnly(wxStandardPaths::Get().GetExecutablePath()) + wxFILE_SEP_PATH + "ccrypt ";
	if(data->GetFunction() == _("Encrypt")){
		if(wxFileExists(path + wxT(".cpt"))){
			//We have a file with the encrypted name already there, skip it
			OutputProgress(_("Failed to encrypt ") + path, Error);
			return true;
		}
		//Create and execute the command
		command = exepath + wxT("-f -e -K\"") + data->GetPassword() + wxT("\" \"") + path + wxT("\"");
	}
	//Decryption
	else{
		if(wxFileExists(path.Left(path.Length() - 4))){
			//We have a file with the decryped name already there, skip it
			OutputProgress(_("Failed to decrypt ") + path, Error);
			return true;
		}
		command = exepath + wxT("-f -d -K\"") + data->GetPassword() + wxT("\" \"") + path + wxT("\"");
	}

	int id = wxDateTime::Now().GetTicks();
	wxCommandEvent *event = new wxCommandEvent(wxEVT_COMMAND_BUTTON_CLICKED, ID_SECUREPROCESS);
	event->SetInt(id);
	event->SetString(command);
	wxGetApp().QueueEvent(event);
	//If we are in console then we yield to make sure the event is processed
	if(!wxGetApp().IsGui()){
		wxGetApp().Yield();
	}
	while(wxGetApp().m_StatusMap[id] != true){
		wxMilliSleep(100);
		if(!wxGetApp().IsGui()){
			wxGetApp().Yield();
		}
	}
	long lgReturn = wxGetApp().m_ProcessStatusMap[id];
	IncrementGauge();

	//Put the old attributed back
#ifdef __WXMSW__
	SetFileAttributes(path, filearrtibs);
#endif

	if(data->GetFunction() == _("Encrypt")){
		if(lgReturn == 0){        
            OutputProgress(_("Encrypted ") + path, Message);
		}
		else{
			OutputProgress(_("Failed to encrypt ") + path + wxString::Format(wxT(" : %i"), lgReturn), Error);
		}
	}
	else{
		if(lgReturn == 0){       
 			OutputProgress(_("Decrypted ") + path, Message);
		}
		else{
 			OutputProgress(_("Failed to decrypt ") + path + wxString::Format(wxT(" : %i"), lgReturn), Error);
		}
	}
	return true;
}
