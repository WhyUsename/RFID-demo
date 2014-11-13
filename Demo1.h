// Demo1.h : main header file for the DEMO1 application
//

#if !defined(AFX_DEMO1_H__524DFAD0_B8C9_4FF3_AB5A_E804FB93BF26__INCLUDED_)
#define AFX_DEMO1_H__524DFAD0_B8C9_4FF3_AB5A_E804FB93BF26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDemo1App:
// See Demo1.cpp for the implementation of this class
//

class CDemo1App : public CWinApp
{
public:
	CDemo1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDemo1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO1_H__524DFAD0_B8C9_4FF3_AB5A_E804FB93BF26__INCLUDED_)
