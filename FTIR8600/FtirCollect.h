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
	void CollectBack(CString cstrParameters);
	void CollectSample(CString cstrParameters);
};


