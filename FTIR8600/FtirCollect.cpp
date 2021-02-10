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
	ftirCollect.CollectSample(cstrFilename);
	CoUninitialize();
}

void CFtirCollect::CollectBack(CString cstrParameters)
{
	AfxMessageBox(_T("Testing : CollectBack."));
	LRESULT copyDataResult;			//copyDataResult has value returned by other app

	CString cstrWindow0 =  _T("MILAS");
	CString cstrWindow1;

	CWnd * pWndMilas = CWnd::FindWindow(NULL, cstrWindow0);
	for (int i = 1; i < 20 && !pWndMilas; i++)
	{
		cstrWindow1.Format(_T("MILAS - [´°¿Ú-%d]"), i);
		pWndMilas = CWnd::FindWindow(NULL, cstrWindow1);
	}
	if (!pWndMilas)
	{
		AfxMessageBox(_T("Error : Please check if FTIR8600 (MILAS) is running."));
		return;
	}
	
	COPYDATASTRUCT cpd;
	cpd.dwData = 0;
	cpd.cbData = cstrParameters.GetLength() + sizeof(wchar_t);             //data length
	cpd.lpData = (void *)cstrParameters.GetBuffer(cpd.cbData); //data buffer
	copyDataResult = pWndMilas->SendMessage(WM_COPYDATA, (WPARAM)AfxGetApp()->m_pMainWnd->GetSafeHwnd(), (LPARAM)&cpd);
	//cstrFilename.ReleaseBuffer();
}

void CFtirCollect::CollectSample(CString cstrParameters)
{
	AfxMessageBox(_T("Testing : CollectSample."));
	LRESULT copyDataResult;			//copyDataResult has value returned by other app

	CString cstrWindow0 =  _T("MILAS");
	CString cstrWindow1;

	CWnd * pWndMilas = CWnd::FindWindow(NULL, cstrWindow0);
	for (int i = 1; i < 20 && !pWndMilas; i++)
	{
		cstrWindow1.Format(_T("MILAS - [´°¿Ú-%d]"), i);
		pWndMilas = CWnd::FindWindow(NULL, cstrWindow1);
	}
	if (!pWndMilas)
	{
		AfxMessageBox(_T("Error : Please check if FTIR8600 (MILAS) is running."));
		return;
	}
	COPYDATASTRUCT cpd;
	cpd.dwData = 0;
	cpd.cbData = cstrParameters.GetLength() + sizeof(wchar_t);             //data length
	cpd.lpData = (void*)cstrParameters.GetBuffer(cpd.cbData); //data buffer
	copyDataResult = pWndMilas->SendMessage(WM_COPYDATA, (WPARAM)AfxGetApp()->m_pMainWnd->GetSafeHwnd(), (LPARAM)&cpd);
	//cstrFilename.ReleaseBuffer();
}

