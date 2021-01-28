#pragma once


// CFtirCollect

class CFtirCollect : public CWnd
{
	DECLARE_DYNAMIC(CFtirCollect)

public:
	CFtirCollect();
	virtual ~CFtirCollect();

protected:
	DECLARE_MESSAGE_MAP()

public :
	void CollectBack(CString cstrFilename);
	void CollectSample(CString cstrFilename, CString cstrPath);
};


