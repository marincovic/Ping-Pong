
// PingPongMFC.h : main header file for the PingPongMFC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPingPongMFCApp:
// See PingPongMFC.cpp for the implementation of this class
//

class CPingPongMFCApp : public CWinApp
{
public:
	CPingPongMFCApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPingPongMFCApp theApp;
