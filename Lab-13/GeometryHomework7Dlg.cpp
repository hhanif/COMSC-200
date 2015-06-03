// Lab 13, Geometrey Homework Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "GeometryHomework.h"

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();
    
    // Dialog Data
    enum { IDD = IDD_ABOUTBOX };
    
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    
    // Implementation
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()





MFCApplication1Dlg::MFCApplication1Dlg(CWnd* pParent /*=NULL*/)
: CDialogEx(MFCApplication1Dlg::IDD, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO1, Square);
}

BEGIN_MESSAGE_MAP(MFCApplication1Dlg, CDialogEx)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_CBN_SELCHANGE(IDC_COMBO1, &MFCApplication1Dlg::OnCbnSelchangeCombo1)
ON_BN_CLICKED(IDOK, &MFCApplication1Dlg::OnBnClickedOk)
END_MESSAGE_MAP()



BOOL MFCApplication1Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    
    // Add "About..." menu item to system menu.
    
    // IDM_ABOUTBOX must be in the system command range.
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);
    
    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
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
    
    CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
    pCombo->InsertString(0, "Square");
    pCombo->InsertString(1, "Rectangle");
    pCombo->InsertString(2, "Circle");
    pCombo->InsertString(3, "Cube");
    pCombo->InsertString(4, "Cylinder");
    pCombo->InsertString(5, "Prism");
    pCombo->SetCurSel(0);
    
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void MFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void MFCApplication1Dlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // device context for painting
        
        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
        
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
        CDialogEx::OnPaint();
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR MFCApplication1Dlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}



void MFCApplication1Dlg::OnCbnSelchangeCombo1()
{
    // TODO: Add your control notification handler code here
}


void MFCApplication1Dlg::OnBnClickedOk()
{
    
    CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC);
    
    ostringstream sout;
    CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
    
    CString edit1;

    
    CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
    CString edit3;
    pEdit3->GetWindowText(edit3);
    double width = _ttof(edit3);
    
    CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
    CString edit2;
    pEdit1->GetWindowText(edit2);
    double length = _ttof(edit2);
    
    CEdit* pEdit4 = (CEdit*)GetDlgItem(IDC_EDIT4);
    CString edit4;
    pEdit4->GetWindowText(edit4);
    double radius = _ttof(edit4);
    
    CEdit* pEdit5 = (CEdit*)GetDlgItem(IDC_EDIT5);
    CString edit5;
    pEdit5->GetWindowText(edit5);
    double height = _ttof(edit5);
    
    CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
    CString cs;
    
    const char* token[4];
    for(int i = 0; i<4; i++){
        token[i]=0;
        
    }
    
    switch(pCombo->GetCurSel())
    {
        case 0:
        {
            pEdit1->GetWindowText(edit1);
            string c = CStringA(edit1);
            token[1] = c.c_str();
            
            Squares s(token);
            sout<<&s;
            pStatic1->SetWindowText(CString(sout.str().c_str()));
            break;
        }
        case 1:
        {
            pEdit2->GetWindowText(edit2);
            string c1 = CStringA(edit2);
            token[1] = c1.c_str();
            
            pEdit3->GetWindowText(edit3);
            string c2 = CStringA(edit3);
            token[2] = c2.c_str();
            
            rec::Rectangle s(token);
            sout<<&s;
            pStatic1->SetWindowText(CString(sout.str().c_str()));
            break;
        }
        case 2:
        {
            pEdit4->GetWindowText(edit4);
            string c3 = CStringA(edit4);
            token[1] = c3.c_str();
            
            Circles s(token);
            sout<<&s;
            pStatic1->SetWindowText(CString(sout.str().c_str()));
            break;
        }
        case 3:
        {
            pEdit1->GetWindowText(edit1);
            string c4 = CStringA(edit1);
            token[1] = c4.c_str();
            
            Cubes s(token);
            sout<<&s;
            pStatic1->SetWindowText(CString(sout.str().c_str()));
            break;
        }
        case 4:
        {
            pEdit4->GetWindowText(edit4);
            string c5 = CStringA(edit4);
            token[1] = c5.c_str();	
            
            pEdit5->GetWindowText(edit5);
            string c6 = CStringA(edit5);
            token[2] = c6.c_str();	
            
            Cylinders s(token);
            sout<<&s;
            pStatic1->SetWindowText(CString(sout.str().c_str()));
            break;
        }		 
            
            
        case 5:
        {
            pEdit2->GetWindowText(edit2);
            string c1 = CStringA(edit2);
            token[1] = c1.c_str();	
            
            pEdit3->GetWindowText(edit3);
            string c2 = CStringA(edit3);
            token[2] = c2.c_str();
            
            pEdit5->GetWindowText(edit5);
            string c6 = CStringA(edit5);
            token[3] = c6.c_str();	
            Prisms s(token);
            
            sout<<&s;
            pStatic1->SetWindowText(CString(sout.str().c_str()));
            break;
        }
    }
    pEdit1->SetWindowText("");
    pEdit2->SetWindowText("");
    pEdit3->SetWindowText("");
    pEdit4->SetWindowText("");
    pEdit5->SetWindowText("");
}
