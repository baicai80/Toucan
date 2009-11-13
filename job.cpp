/////////////////////////////////////////////////////////////////////////////////
// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2009 Steven Lamerton
// License:     GNU GPL 2 (See readme for more info)
/////////////////////////////////////////////////////////////////////////////////

#include "job.h"

Job::Job(JobData *Data) : m_Data(Data), wxThread(wxTHREAD_JOINABLE){
	;
}

Job::~Job(){
	delete m_Data;
}
