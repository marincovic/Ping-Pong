
// PingPongMFC2.h : main header file for the PingPongMFC2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPingPongMFC2App:
// See PingPongMFC2.cpp for the implementation of this class
//

class CPingPongMFC2App : public CWinApp
{
public:
	CPingPongMFC2App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPingPongMFC2App theApp;
