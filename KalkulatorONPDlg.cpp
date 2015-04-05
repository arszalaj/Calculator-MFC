// KalkulatorONPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KalkulatorONP.h"
#include "KalkulatorONPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/* deklaracja zmiennych globalnych */
CString expr;///< przechowuje aktualne wyra¿enie arytmetyczne do obliczenia
CString onp_expr;///< przechowuje aktualne wyra¿enie w ONP
CString result;///< przechowuje ³añcuch zawieraj¹cy wynik obliczeñ wyra¿enia
CString mem;///< ³añcuch pomocniczy

long double ld_result;///< przechowuje numeryczny wynik obliczenia wyra¿enia


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CKalkulatorONPDlg dialog




CKalkulatorONPDlg::CKalkulatorONPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKalkulatorONPDlg::IDD, pParent)
	, rbin(0)
	, roct(0)
	, rhex(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKalkulatorONPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_1, but_1);
	DDX_Control(pDX, IDC_2, but_2);
	DDX_Control(pDX, IDC_3, but_3);
	DDX_Control(pDX, IDC_4, but_4);
	DDX_Control(pDX, IDC_5, but_5);
	DDX_Control(pDX, IDC_6, but_6);
	DDX_Control(pDX, IDC_7, but_7);
	DDX_Control(pDX, IDC_8, but_8);
	DDX_Control(pDX, IDC_9, but_9);
	DDX_Control(pDX, IDC_PM, but_plusminus);
	DDX_Control(pDX, IDC_0, but_0);
	DDX_Control(pDX, IDC_DOT, but_dot);
	DDX_Control(pDX, IDC_EQUAL, but_eq);
	DDX_Control(pDX, IDC_PLUS, but_plus);
	DDX_Control(pDX, IDC_MINUS, but_minus);
	DDX_Control(pDX, IDC_MULT, but_multip);
	DDX_Control(pDX, IDC_DIV, but_div);
	DDX_Control(pDX, IDC_LB, but_lb);
	DDX_Control(pDX, IDC_RB, but_rb);
	DDX_Control(pDX, IDC_CE, but_ce);
	DDX_Control(pDX, IDC_PI, but_pi);
	DDX_Control(pDX, IDC_EDIT3, ed_result);
	DDX_Control(pDX, IDC_EDIT1, ed_onpexp);
	DDX_Control(pDX, IDC_EDIT2, ed_exp);
	DDX_Control(pDX, IDC_DEC_RAD, rdec);
	DDX_Control(pDX, IDC_A, but_a);
	DDX_Control(pDX, IDC_B, but_b);
	DDX_Control(pDX, IDC_C_HEx, but_c);
	DDX_Control(pDX, IDC_D, but_d);
	DDX_Control(pDX, IDC_E, but_e);
	DDX_Control(pDX, IDC_F, but_f);
	DDX_Control(pDX, IDC_DEG_RAD, deg_rad);
	DDX_Control(pDX, IDC_RAD_RAD, rad_rad);
	DDX_Control(pDX, IDC_INV_CB, InvCB);
	DDX_Control(pDX, IDC_SIN, but_sin);
	DDX_Control(pDX, IDC_COS, but_cos);
	DDX_Control(pDX, IDC_TG, but_tg);
	DDX_Control(pDX, IDC_EXP, but_exp);
	DDX_Control(pDX, IDC_LOG, but_log);
	DDX_Control(pDX, IDC_SQRT, but_sqrt);
	DDX_Control(pDX, IDC_POW, but_pow);
}

BEGIN_MESSAGE_MAP(CKalkulatorONPDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_1, &CKalkulatorONPDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CKalkulatorONPDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CKalkulatorONPDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CKalkulatorONPDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CKalkulatorONPDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CKalkulatorONPDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CKalkulatorONPDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CKalkulatorONPDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CKalkulatorONPDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_0, &CKalkulatorONPDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_DOT, &CKalkulatorONPDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_PLUS, &CKalkulatorONPDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_MINUS, &CKalkulatorONPDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_7, &CKalkulatorONPDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MULT, &CKalkulatorONPDlg::OnBnClickedMult)
	ON_BN_CLICKED(IDC_DIV, &CKalkulatorONPDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_PM, &CKalkulatorONPDlg::OnBnClickedPlusMinus)
	ON_BN_CLICKED(IDC_CE, &CKalkulatorONPDlg::OnBnClickedCE)
	ON_BN_CLICKED(IDC_LB, &CKalkulatorONPDlg::OnBnClickedLeftBracket)
	ON_BN_CLICKED(IDC_RB, &CKalkulatorONPDlg::OnBnClickedRightBracket)
	ON_BN_CLICKED(IDC_C, &CKalkulatorONPDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_EQUAL, &CKalkulatorONPDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_SIN, &CKalkulatorONPDlg::OnBnClickedSin)
	ON_BN_CLICKED(IDC_LN, &CKalkulatorONPDlg::OnBnClickedLn)
	ON_BN_CLICKED(IDC_COS, &CKalkulatorONPDlg::OnBnClickedCos)
	ON_BN_CLICKED(IDC_TG, &CKalkulatorONPDlg::OnBnClickedTg)
	ON_BN_CLICKED(IDC_CTG, &CKalkulatorONPDlg::OnBnClickedCtg)
	ON_BN_CLICKED(IDC_EXP, &CKalkulatorONPDlg::OnBnClickedExp)
	ON_BN_CLICKED(IDC_POW, &CKalkulatorONPDlg::OnBnClickedPow)
	ON_BN_CLICKED(IDC_LOG, &CKalkulatorONPDlg::OnBnClickedLog)
	ON_BN_CLICKED(IDC_PI, &CKalkulatorONPDlg::OnBnClickedPI)
	ON_BN_CLICKED(IDC_ASIN, &CKalkulatorONPDlg::OnBnClickedAsin)
	ON_BN_CLICKED(IDC_ACOS, &CKalkulatorONPDlg::OnBnClickedAcos)
	ON_BN_CLICKED(IDC_ATG, &CKalkulatorONPDlg::OnBnClickedAtg)
	ON_BN_CLICKED(IDC_SQRT, &CKalkulatorONPDlg::OnBnClickedSqrt)
	ON_BN_CLICKED(IDC_DEC_RAD, &CKalkulatorONPDlg::OnBnClickedDecRad)
	ON_BN_CLICKED(IDC_BIN_RAD, &CKalkulatorONPDlg::OnBnClickedBinRad)
	ON_BN_CLICKED(IDC_OCT_RAD, &CKalkulatorONPDlg::OnBnClickedOctRad)
	ON_BN_CLICKED(IDC_HEX_RAD, &CKalkulatorONPDlg::OnBnClickedHexRad)
	ON_BN_CLICKED(IDC_X, &CKalkulatorONPDlg::OnBnClickedX)
	ON_BN_CLICKED(IDC_A, &CKalkulatorONPDlg::OnBnClickedA)
	ON_BN_CLICKED(IDC_B, &CKalkulatorONPDlg::OnBnClickedB)
	ON_BN_CLICKED(IDC_C_HEx, &CKalkulatorONPDlg::OnBnClickedCHex)
	ON_BN_CLICKED(IDC_D, &CKalkulatorONPDlg::OnBnClickedD)
	ON_BN_CLICKED(IDC_E, &CKalkulatorONPDlg::OnBnClickedE)
	ON_BN_CLICKED(IDC_F, &CKalkulatorONPDlg::OnBnClickedF)
	ON_BN_CLICKED(IDC_DEG_RAD, &CKalkulatorONPDlg::OnBnClickedDegRad)
	ON_BN_CLICKED(IDC_RAD_RAD, &CKalkulatorONPDlg::OnBnClickedRadRad)
	ON_BN_CLICKED(IDC_INV_CB, &CKalkulatorONPDlg::OnBnClickedInvCb)
END_MESSAGE_MAP()


// CKalkulatorONPDlg message handlers

BOOL CKalkulatorONPDlg::OnInitDialog()
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
	ed_exp.SetFocus();
	//Make sure this is here so you can use XP Styles
	InitCommonControls(); // potrzebne do wygl¹du a'la xp
	rdec.SetCheck(1);
	rad_rad.SetCheck(1);
	this->actSys = CONP::dec;
	this->actTrig = CONP::rad;
	this->OnBnClickedDecRad();


	return FALSE;  // return TRUE  unless you set the focus to a control
}

void CKalkulatorONPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CKalkulatorONPDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKalkulatorONPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CKalkulatorONPDlg::PreTranslateMessage(MSG* pMsg)

{
	int x = pMsg->wParam;
	if(pMsg->message == WM_KEYDOWN) // jezeli wcisnieto klawisz
	{
		ed_exp.SetFocus(); // ustaw aktywny wyswietlacz
		if(x == VK_RETURN) // jezeli byl to ENTER
		{
			OnBnClickedEqual(); // zasymuluj wcisniecie =
			pMsg->wParam = 0; // wyzeruj komunikat aby nie mial dalszych skutkow
		}
		if(x == VK_DELETE) // jezeli byl to CE
		{
			OnBnClickedCE(); // zasymuluj wcisniecie =
			pMsg->wParam = 0; // wyzeruj komunikat aby nie mial dalszych skutkow
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

/** 
* Do³¹cza podany tekst do wyra¿enia i wyœwietla go w odpowiedniej kontrolce.
* @param *text ³añcuch do do³¹czenia
*/
void CKalkulatorONPDlg::appendTextToExp(char *text)
{
	CString buffer;
	string s;
	int start,end;
	ed_exp.GetSel(start,end);
	ed_exp.GetWindowTextA(buffer); 
	s = buffer;
	if(start == end)
	{
		s.insert(start,text);
	}
	else
	{
		s.replace(start,end-start,text);
	}
	expr.Empty(); 
	expr.Append(s.c_str()); 
	ed_exp.SetWindowTextA(expr); 
	ed_exp.SetSel(start+(int)strlen(text),start+(int)strlen(text));
	ed_exp.SetFocus();
}


	
/** 
* Przenosi kuror na koniec kontrolki CEdit.
* @param edit kontrolka, której kursor chcemy umieœciæ na koñcu.
*/
void CKalkulatorONPDlg::moveCursorToEnd(CEdit &edit)
{
	CString buffer;
	edit.GetWindowTextA(buffer);
	edit.SetSel(buffer.GetLength(),buffer.GetLength(),0); // ustawienie pozycji kursora na koniec
	edit.SetFocus();
}

/**
* Obs³uga przycisku "1"
*/
void CKalkulatorONPDlg::OnBnClicked1()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("1");
	

}



/**
* Obs³uga przycisku "2"
*/
void CKalkulatorONPDlg::OnBnClicked2()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("2");
}


/**
* Obs³uga przycisku "3"
*/
void CKalkulatorONPDlg::OnBnClicked3()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("3");
}

/**
* Obs³uga przycisku "4"
*/
void CKalkulatorONPDlg::OnBnClicked4()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("4");
}

/**
* Obs³uga przycisku "5"
*/
void CKalkulatorONPDlg::OnBnClicked5()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("5");
}

/**
* Obs³uga przycisku "6"
*/
void CKalkulatorONPDlg::OnBnClicked6()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("6");
}

/**
* Obs³uga przycisku "7"
*/
void CKalkulatorONPDlg::OnBnClicked7()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("7");
}

/**
* Obs³uga przycisku "8"
*/
void CKalkulatorONPDlg::OnBnClicked8()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("8");
}

/**
* Obs³uga przycisku "9"
*/
void CKalkulatorONPDlg::OnBnClicked9()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("9");
}

/**
* Obs³uga przycisku "0"
*/
void CKalkulatorONPDlg::OnBnClicked0()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("0");
}

/**
* Obs³uga przycisku "."
*/
void CKalkulatorONPDlg::OnBnClickedDot()
{
	// TODO: Add your control notification handler code here
	appendTextToExp(".");
}

/**
* Obs³uga przycisku "+"
*/
void CKalkulatorONPDlg::OnBnClickedPlus()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("+");
}

/**
* Obs³uga przycisku "-"
*/
void CKalkulatorONPDlg::OnBnClickedMinus()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("-");
}

/**
* Obs³uga przycisku "*"
*/
void CKalkulatorONPDlg::OnBnClickedMult()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("*");
}

/**
* Obs³uga przycisku "/"
*/
void CKalkulatorONPDlg::OnBnClickedDiv()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("/");
}

/**
* Obs³uga przycisku "+/-"
*/
void CKalkulatorONPDlg::OnBnClickedPlusMinus()
{
	// TODO: Add your control notification handler code here
	if(expr[0] == '-') // jezeli na poczatku stoi minus
		expr = expr.Mid(1,expr.GetLength()-1); // to obcinamy go
	else
	{
		string buffer;
		buffer = expr.GetString();
		buffer = '-' + buffer;
		expr = buffer.c_str();
	}
	ed_exp.SetWindowTextA(expr);
	moveCursorToEnd(ed_exp);
}

/**
* Obs³uga przycisku "CE"
*/
void CKalkulatorONPDlg::OnBnClickedCE()
{
	// TODO: Add your control notification handler code here
	expr.Empty(); // czyscimy wyrazenie
	onp_expr.Empty(); // czyscimy wyrazenie ONP
	result.Empty();
	ed_onpexp.SetWindowTextA("");
	ed_exp.SetWindowTextA("");
	ed_result.SetWindowTextA("");
}

/**
* Obs³uga przycisku "("
*/
void CKalkulatorONPDlg::OnBnClickedLeftBracket()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("(");
}

/**
* Obs³uga przycisku ")"
*/
void CKalkulatorONPDlg::OnBnClickedRightBracket()
{
	// TODO: Add your control notification handler code here
	appendTextToExp(")");
}

/**
* Obs³uga przycisku "C"
*/
void CKalkulatorONPDlg::OnBnClickedC()
{
	// TODO: Add your control notification handler code here
	expr = expr.Mid(0,expr.GetLength()-1);
	ed_exp.SetWindowTextA(expr);
	moveCursorToEnd(ed_exp);
}
/**
* Obs³uga przycisku "="
*/
void CKalkulatorONPDlg::OnBnClickedEqual()
{
	COLORREF qCircleColor = RGB(255,0,0);
	CPen qCirclePen(PS_SOLID, 7, qCircleColor);
	CDC* pDC = GetDC();
	CPen* pqOrigPen = pDC->SelectObject(&qCirclePen);
	pDC->Ellipse(100, 100, 500, 500);

	COLORREF qLineColor = RGB(0,0,255);
	CPen qLinePen(PS_SOLID, 7, qLineColor); 
	pDC->SelectObject(&qLinePen);

	pDC->SetPixel(200, 200, qLineColor);

	pDC->MoveTo(100, 100);
	pDC->LineTo(200, 200);
	pDC->LineTo(300, 100);
	pDC->LineTo(500, 500);
	pDC->TextOutA(200,400,"cdscdscscd");
	pDC->SelectObject(pqOrigPen);


	CString buffer;
	string wyn;
	ed_exp.GetWindowTextA(buffer);

	string infix_expr = buffer.GetString();
	infix_expr = onp.convert(infix_expr,this->actSys,CONP::dec);
	string onp_ex;
	char buf[256];
	if(onp.infixToONP(infix_expr,onp_ex) == -1)
	{
		buffer = "Nieprawidlowe lub nieobslugiwane wyrazenie";
		ed_exp.SetWindowTextA(buffer);
		ed_onpexp.SetWindowTextA(buffer);
		return ;
	}
	else
	{
		onp_ex = onp.convert(onp_ex,CONP::dec,this->actSys);
		ed_onpexp.SetWindowTextA(onp_ex.c_str());
		onp_ex = onp.convert(onp_ex,this->actSys,CONP::dec);
		if(onp.evaluateONP(onp_ex,ld_result,actTrig) == -1)
		{
			ed_result.SetWindowTextA("Nie mozna obliczyc wyrazenia");
		return ;
		}
		else
		{
			sprintf(buf,"%.15Lf",ld_result);
			wyn = buf;
			wyn = onp.convert(wyn,CONP::dec,this->actSys);
			ed_result.SetWindowTextA(wyn.c_str());
		}
	}
	moveCursorToEnd(ed_exp);
}
/**
* Obs³uga przycisku "sin"
*/
void CKalkulatorONPDlg::OnBnClickedSin()
{
	// TODO: Add your control notification handler code here
	if(InvCB.GetCheck())
		appendTextToExp("asin(");
	else
		appendTextToExp("sin(");
}
/**
* Obs³uga przycisku "ln"
*/
void CKalkulatorONPDlg::OnBnClickedLn()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("ln(");
}
/**
* Obs³uga przycisku "cos"
*/
void CKalkulatorONPDlg::OnBnClickedCos()
{
	// TODO: Add your control notification handler code here
	if(InvCB.GetCheck())
		appendTextToExp("acos(");
	else
		appendTextToExp("cos(");
}
/**
* Obs³uga przycisku "tg"
*/
void CKalkulatorONPDlg::OnBnClickedTg()
{
	// TODO: Add your control notification handler code here
	if(InvCB.GetCheck())
		appendTextToExp("atan(");
	else
		appendTextToExp("tan(");
}
/**
* Obs³uga przycisku "ctg"
*/
void CKalkulatorONPDlg::OnBnClickedCtg()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("ctg(");
}
/**
* Obs³uga przycisku "exp"
*/
void CKalkulatorONPDlg::OnBnClickedExp()
{
	// TODO: Add your control notification handler code here
	if(InvCB.GetCheck())
		appendTextToExp("exp(");
	else
		appendTextToExp("ln(");
}
/**
* Obs³uga przycisku "^"
*/
void CKalkulatorONPDlg::OnBnClickedPow()
{
	// TODO: Add your control notification handler code here
	if(InvCB.GetCheck())
		appendTextToExp("fac(");
	else
		appendTextToExp("^");

}
/**
* Obs³uga przycisku "log"
*/
void CKalkulatorONPDlg::OnBnClickedLog()
{
	// TODO: Add your control notification handler code here
	if(InvCB.GetCheck())
		appendTextToExp("10^");
	else
		appendTextToExp("log(");
}
/**
* Obs³uga przycisku "PI"
*/
void CKalkulatorONPDlg::OnBnClickedPI()
{
	// TODO: Add your control notification handler code here
	if(InvCB.GetCheck())
		appendTextToExp("2*3.14159265");
	else
		appendTextToExp("3.14159265");
}
/**
* Obs³uga przycisku "asin"
*/
void CKalkulatorONPDlg::OnBnClickedAsin()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("asin(");
}
/**
* Obs³uga przycisku "acos"
*/
void CKalkulatorONPDlg::OnBnClickedAcos()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("acos(");
}
/**
* Obs³uga przycisku "atg"
*/
void CKalkulatorONPDlg::OnBnClickedAtg()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("atan(");
}
/**
* Obs³uga przycisku "sqrt"
*/
void CKalkulatorONPDlg::OnBnClickedSqrt()
{
	// TODO: Add your control notification handler code here
	if(InvCB.GetCheck())
		appendTextToExp("^2");
	else
		appendTextToExp("sqrt(");
}
/**
* Obs³uga radiobuttona Dec
*/

void CKalkulatorONPDlg::OnBnClickedDecRad()
{
	// TODO: Add your control notification handler code here
	CString buffer;
	string exp;
	ed_exp.GetWindowTextA(buffer);
	exp = buffer;
	ed_exp.SetWindowTextA(onp.convert(exp,this->actSys,CONP::dec).c_str());
	this->actSys = CONP::dec;
	this->OnBnClickedEqual();
	this->OnChangeTrigGroup();

}
/**
* Obs³uga radiobuttona Bin
*/
void CKalkulatorONPDlg::OnBnClickedBinRad()
{
	// TODO: Add your control notification handler code here
	CString buffer;
	string exp;
	ed_exp.GetWindowTextA(buffer);
	exp = buffer;
	ed_exp.SetWindowTextA(onp.convert(exp,this->actSys,CONP::bin).c_str());
	this->actSys = CONP::bin;
	this->OnBnClickedEqual();
	this->OnChangeTrigGroup();
}
/**
* Obs³uga radiobuttona Oct
*/
void CKalkulatorONPDlg::OnBnClickedOctRad()
{
	// TODO: Add your control notification handler code here
	CString buffer;
	string exp;
	ed_exp.GetWindowTextA(buffer);
	exp = buffer;
	ed_exp.SetWindowTextA(onp.convert(exp,this->actSys,CONP::oct).c_str());
	this->actSys = CONP::oct;
	this->OnBnClickedEqual();
	this->OnChangeTrigGroup();
}

/**
* Obs³uga radiobuttona Hex
*/
void CKalkulatorONPDlg::OnBnClickedHexRad()
{
	// TODO: Add your control notification handler code here
	CString buffer;
	string exp;
	ed_exp.GetWindowTextA(buffer);
	exp = buffer;
	ed_exp.SetWindowTextA(onp.convert(exp,this->actSys,CONP::hex).c_str());
	this->actSys = CONP::hex;
	this->OnBnClickedEqual();
	this->OnChangeTrigGroup();
}

/**
* Obs³uga przycisku 'x'
*/
void CKalkulatorONPDlg::OnBnClickedX()
{
	// TODO: Add your control notification handler code here
	this->appendTextToExp("x");
	
}
/**
* Obs³uga przycisku 'A'
*/
void CKalkulatorONPDlg::OnBnClickedA()
{
	// TODO: Add your control notification handler code here
	this->appendTextToExp("A");
}
/**
* Obs³uga przycisku 'B'
*/
void CKalkulatorONPDlg::OnBnClickedB()
{
	// TODO: Add your control notification handler code here
	this->appendTextToExp("B");
}
/**
* Obs³uga przycisku 'C'
*/
void CKalkulatorONPDlg::OnBnClickedCHex()
{
	// TODO: Add your control notification handler code here
	this->appendTextToExp("C");
}
/**
* Obs³uga przycisku 'D'
*/
void CKalkulatorONPDlg::OnBnClickedD()
{
	// TODO: Add your control notification handler code here
	this->appendTextToExp("D");

}
/**
* Obs³uga przycisku 'E'
*/
void CKalkulatorONPDlg::OnBnClickedE()
{
	// TODO: Add your control notification handler code here
	this->appendTextToExp("E");
}
/**
* Obs³uga przycisku 'F'
*/
void CKalkulatorONPDlg::OnBnClickedF()
{
	// TODO: Add your control notification handler code here
	this->appendTextToExp("F");
}
/**
* Obs³uga radiobuttona 'stopnie'
*/
void CKalkulatorONPDlg::OnBnClickedDegRad()
{
	// TODO: Add your control notification handler code here
	this->actTrig = CONP::deg;
}
/**
* Obs³uga radiobuttona 'radiany'
*/
void CKalkulatorONPDlg::OnBnClickedRadRad()
{
	// TODO: Add your control notification handler code here
	this->actTrig = CONP::rad;
}
/**
* Wywo³ywana przy zmianie systemu liczbowego dec/bin/oct/hex
* Dezaktywuje mo¿liwoœæ zmiany stopni/radianów dla innych systemów ni¿ dziesiêtny
*/
void CKalkulatorONPDlg::OnChangeTrigGroup()
{
	this->OnBnClickedRadRad();
	deg_rad.SetCheck(0);
	rad_rad.SetCheck(1);
	if(this->actSys != CONP::dec)
	{
		GetDlgItem(IDC_DEG_RAD)->EnableWindow(false);
		GetDlgItem(IDC_RAD_RAD)->EnableWindow(false);

	}
	else
	{
		GetDlgItem(IDC_DEG_RAD)->EnableWindow(true);
		GetDlgItem(IDC_RAD_RAD)->EnableWindow(true);
	}
	if(this->actSys != CONP::hex)
	{
		GetDlgItem(IDC_X)->EnableWindow(false);
		GetDlgItem(IDC_A)->EnableWindow(false);
		GetDlgItem(IDC_B)->EnableWindow(false);
		GetDlgItem(IDC_C_HEx)->EnableWindow(false);
		GetDlgItem(IDC_D)->EnableWindow(false);
		GetDlgItem(IDC_E)->EnableWindow(false);
		GetDlgItem(IDC_F)->EnableWindow(false);

	}
	else
	{
		GetDlgItem(IDC_X)->EnableWindow(true);
		GetDlgItem(IDC_A)->EnableWindow(true);
		GetDlgItem(IDC_B)->EnableWindow(true);
		GetDlgItem(IDC_C_HEx)->EnableWindow(true);
		GetDlgItem(IDC_D)->EnableWindow(true);
		GetDlgItem(IDC_E)->EnableWindow(true);
		GetDlgItem(IDC_F)->EnableWindow(true);
	}
}


void CKalkulatorONPDlg::OnBnClickedInvCb()
{
	// TODO: Add your control notification handler code here
	if(InvCB.GetCheck() == 1)
	{
		but_sin.SetWindowTextA("asin");
		but_cos.SetWindowTextA("acos");
		but_exp.SetWindowTextA("exp");
		but_tg.SetWindowTextA("atan");
		but_sqrt.SetWindowTextA("x^2");
		but_log.SetWindowTextA("10^x");
		but_pi.SetWindowTextA("2pi");
		but_pow.SetWindowTextA("fac");
	}
	else if(InvCB.GetCheck() == 0)
	{
		but_sin.SetWindowTextA("sin");
		but_cos.SetWindowTextA("cos");
		but_exp.SetWindowTextA("ln");
		but_tg.SetWindowTextA("tan");
		but_sqrt.SetWindowTextA("sqrt");
		but_log.SetWindowTextA("log");
		but_pi.SetWindowTextA("pi");
		but_pow.SetWindowTextA("^");
	}

}
