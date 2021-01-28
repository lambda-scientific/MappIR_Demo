// FTIR8600.h : main header file for the FTIR8600 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFTIR8600App
// See FTIR8600.cpp for the implementation of this class
//

class CFTIR8600App : public CWinApp
{
public:
	CFTIR8600App();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
