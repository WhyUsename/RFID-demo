// Demo1Dlg.h : header file
//

#if !defined(AFX_DEMO1DLG_H__F7E58D8A_4ADA_4F79_A60B_95C1DCBC767A__INCLUDED_)
#define AFX_DEMO1DLG_H__F7E58D8A_4ADA_4F79_A60B_95C1DCBC767A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CDemo1Dlg dialog

class CDemo1Dlg : public CDialog
{
// Construction
public:
	void stringtohex(CString str, unsigned char *buff);
	CDemo1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDemo1Dlg)
	enum { IDD = IDD_DEMO1_DIALOG };
	CEdit	m_uid;
	CEdit	m_open;
	CComboBox	m_block;
	CEdit	m_code;
	CComboBox	m_page;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemo1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDemo1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButnReadBlock();
	afx_msg void OnButnKey();
	afx_msg void OnBUTTON1open();
	afx_msg void OnBUTTON2uid();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO1DLG_H__F7E58D8A_4ADA_4F79_A60B_95C1DCBC767A__INCLUDED_)
