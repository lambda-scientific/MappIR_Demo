// FtirCollect.cpp : implementation file
//

#include "stdafx.h"
#include "FTIR8600.h"
#include "FtirCollect.h"


// CFtirCollect

IMPLEMENT_DYNAMIC(CFtirCollect, CWnd)

CFtirCollect::CFtirCollect()
{

}

CFtirCollect::~CFtirCollect()
{
}


BEGIN_MESSAGE_MAP(CFtirCollect, CWnd)
END_MESSAGE_MAP()



// CFtirCollect message handlers
extern "C" __declspec(dllexport) void CallCollectBack()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CoInitialize(NULL);
	AfxEnableControlContainer();
	CString cstrFilename = _T("background.txt");
	CFtirCollect ftirCollect;
	ftirCollect.CollectBack(cstrFilename);
	CoUninitialize();
}


extern "C" __declspec(dllexport) void CallCollectSample()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CoInitialize(NULL);
	AfxEnableControlContainer();
	CString cstrFilename = _T("background.txt");
	CString cstrPath = _T("C:\\");
	CFtirCollect ftirCollect;
	ftirCollect.CollectSample(cstrFilename, cstrPath);
	CoUninitialize();
}

void CFtirCollect::CollectBack(CString cstrFilename)
{
	AfxMessageBox(_T("Testing : CollectBack."));
}

void CFtirCollect::CollectSample(CString cstrFilename, CString cstrPath)
{
	AfxMessageBox(_T("Testing : CollectSample."));
}

