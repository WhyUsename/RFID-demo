// Demo1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo1.h"
#include "Demo1Dlg.h"
#include "ZM124U.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemo1Dlg dialog

CDemo1Dlg::CDemo1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemo1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemo1Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemo1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemo1Dlg)
	DDX_Control(pDX, IDC_EDIT2, m_balance);
	DDX_Control(pDX, IDC_COMBO_BLOCK2, m_block2);
	DDX_Control(pDX, IDC_COMBO_PAGE2, m_page2);
	DDX_Control(pDX, IDC_UID, m_uid);
	DDX_Control(pDX, IDC_open, m_open);
	DDX_Control(pDX, IDC_COMBO_BLOCK, m_block);
	DDX_Control(pDX, IDC_EDIT_CODE, m_code);
	DDX_Control(pDX, IDC_COMBO_PAGE, m_page);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemo1Dlg, CDialog)
	//{{AFX_MSG_MAP(CDemo1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTN_READ_BLOCK, OnButnReadBlock)
	ON_BN_CLICKED(IDC_BUTN_KEY, OnButnKey)
	ON_BN_CLICKED(IDC_BUTTON1_open, OnBUTTON1open)
	ON_BN_CLICKED(IDC_BUTTON2_uid, OnBUTTON2uid)
	ON_BN_CLICKED(IDC_BUTTON_wallet_init, OnBUTTONwalletinit)
	ON_BN_CLICKED(IDC_BUTTON_balance, OnBUTTONbalance)
	ON_BN_CLICKED(IDC_BUTTON_recharge, OnBUTTONrecharge)
	ON_BN_CLICKED(IDC_BUTTON_deduct, OnBUTTONdeduct)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemo1Dlg message handlers

BOOL CDemo1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDemo1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDemo1Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDemo1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDemo1Dlg::OnButnReadBlock() 
{
	// TODO: Add your control notification handler code here
	int page;
	int block;
	unsigned char pswtype;
	unsigned char psw[1024];
	unsigned char buff[1024];
	int buff_len;
	CString s0,s1,getcode,code;

	page = m_page.GetCurSel();
	block = m_block.GetCurSel();
	UINT Key = GetCheckedRadioButton(IDC_RADIO_A,IDC_RADIO_B);
	switch (Key)
	{
	case IDC_RADIO_A : pswtype = 0x0A;  break;
	case IDC_RADIO_B : pswtype = 0x0B;  break;
	default : break;
	}


	
UpdateData(TRUE);
m_code.GetWindowText(getcode);
stringtohex(getcode,psw);	
code="FFFFFFFFFFFF";

if(getcode == code)
{
		int j = read_block(page,block,pswtype,psw,buff,&buff_len);
		if(j == 0)
		{
			s0.Empty();
			for (int k=0;k<buff_len;k++)
			{
				char ch = buff[k];
				s1.Format("%02x",buff[k]);
				s0+=s1;
			}

			switch(block)
			{
			case 0: GetDlgItem(IDC_EDIT_B0)->SetWindowText(s0); break;
			case 1: GetDlgItem(IDC_EDIT_B1)->SetWindowText(s0); break;
			case 2: GetDlgItem(IDC_EDIT_B2)->SetWindowText(s0); break;
			case 3: GetDlgItem(IDC_EDIT_B3)->SetWindowText(s0); break;
			default: break;
			}
		}
		else
		{
		switch (block)
			{
			case 0: GetDlgItem(IDC_EDIT_B0)->SetWindowText("读取块0信息失败！"); break;
			case 1: GetDlgItem(IDC_EDIT_B1)->SetWindowText("读取块1信息失败！"); break;
			case 2: GetDlgItem(IDC_EDIT_B2)->SetWindowText("读取块2信息失败！"); break;
			case 3: GetDlgItem(IDC_EDIT_B3)->SetWindowText("读取块3信息失败！"); break;
			default:break;
			}
		}
}
else 	MessageBox("输入密码错误！");
		


}

void CDemo1Dlg::OnButnKey() 
{
	// TODO: Add your control notification handler code here
	m_code.SetWindowText("FFFFFFFFFFFF");
	
}


void CDemo1Dlg::stringtohex(CString str, unsigned char *buff)
{
	CString s1;
	int len=str.GetLength();
	unsigned char buf[1024];
	int j;
	char ch;
	
	str.MakeUpper();
	
	for (int i=0;i<len;i++)  //检测到A-F的情况
	{
		ch=str[i];
		
		if (ch>0x40)
		{
			buf[i]=(unsigned char)ch-0x37;
		} 
		else
		{
			buf[i]=(unsigned char)atoi(&ch); //将字符窜转换为整数   atoi(char *p)
		}
	}
	
	for (i=0;i<1024;i++)
	{
		buff[i]=0;
	}
	len+=1;
	
	for (j=0,i=0;j<len/2;)
	{
		buff[j]=(unsigned char)(buf[i++]<<4);
		buff[j++]|=buf[i++];
	}
}

void CDemo1Dlg::OnBUTTON1open() 
{
	// TODO: Add your control notification handler code here
	int i=IDD_PowerOn();
	if(i==0)
		m_open.SetWindowText("开启设备成功！");
	else
		m_open.SetWindowText("开启设备失败！");
}

void CDemo1Dlg::OnBUTTON2uid() 
{
	// TODO: Add your control notification handler code here
	CString s,s1;
	unsigned char buff[1024];
	int buff_len;
	int j=find_14443(buff,&buff_len);
	if(j==0)
	{
		s.Empty();
		for(int i=0;i<buff_len;i++)
		{
			s1.Format("%02x",buff[i]);
			s+=s1;
		}
		m_uid.SetWindowText(s);
	}
	else
		m_uid.SetWindowText("获取序列号失败！");
	
}

void CDemo1Dlg::OnBUTTONwalletinit() 
{
	// TODO: Add your control notification handler code here
	int page;
	int block;
	unsigned char pswtype;
	unsigned char psw[1024];
	long account=0;
	page = m_page2.GetCurSel();
	block = m_block2.GetCurSel();
	UINT Key = GetCheckedRadioButton(IDC_RADIO_A,IDC_RADIO_B);
	switch (Key)
	{
	case IDC_RADIO_A : pswtype = 0x0A;  break;
	case IDC_RADIO_B : pswtype = 0x0B;  break;
	default : break;
	}
	write_account(page,block,pswtype,psw,account);
	m_wallet_init.SetWindowText(account);
}

void CDemo1Dlg::OnBUTTONbalance() 
{
	// TODO: Add your control notification handler code here
	int page;
	int block;
	unsigned char pswtype;
	unsigned char psw[1024];
	long account[1024];
	page = m_page2.GetCurSel();
	block = m_block2.GetCurSel();
	UINT Key = GetCheckedRadioButton(IDC_RADIO_A,IDC_RADIO_B);
	switch (Key)
	{
	case IDC_RADIO_A : pswtype = 0x0A;  break;
	case IDC_RADIO_B : pswtype = 0x0B;  break;
	default : break;
	}
	read_account(page,block,pswtype,psw,account);   //account为指针，暂时为找出指针，函数错误，待修改；
	m_balance.SetWindowText(account);	
}

void CDemo1Dlg::OnBUTTONrecharge() 
{
	// TODO: Add your control notification handler code here
	int page;
	int block;
	unsigned char pswtype;
	unsigned char psw[1024];
	long add_account;
	page = m_page2.GetCurSel();
	block = m_block2.GetCurSel();
	UINT Key = GetCheckedRadioButton(IDC_RADIO_A,IDC_RADIO_B);
	switch (Key)
	{
	case IDC_RADIO_A : pswtype = 0x0A;  break;
	case IDC_RADIO_B : pswtype = 0x0B;  break;
	default : break;
	}
	add_account=GetDlgItem(IDC_amout1)
	add_account(page,block,pswtype,psw,add_account);	
}

void CDemo1Dlg::OnBUTTONdeduct() 
{
	// TODO: Add your control notification handler code here
	int page;
	int block;
	unsigned char pswtype;
	unsigned char psw[1024];
	long sub_account;
	page = m_page2.GetCurSel();
	block = m_block2.GetCurSel();
	UINT Key = GetCheckedRadioButton(IDC_RADIO_A,IDC_RADIO_B);
	switch (Key)
	{
	case IDC_RADIO_A : pswtype = 0x0A;  break;
	case IDC_RADIO_B : pswtype = 0x0B;  break;
	default : break;
	}
	sub_account=GetDlgItem(IDC_amout2)
	sub_account(page,block,pswtype,psw,sub_account);	
}
