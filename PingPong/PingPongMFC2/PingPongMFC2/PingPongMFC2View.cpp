
// PingPongMFC2View.cpp : implementation of the CPingPongMFC2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PingPongMFC2.h"
#endif

#include "PingPongMFC2Doc.h"
#include "PingPongMFC2View.h"

#include<string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPingPongMFC2View

IMPLEMENT_DYNCREATE(CPingPongMFC2View, CView)

BEGIN_MESSAGE_MAP(CPingPongMFC2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_NEW, &CPingPongMFC2View::OnFileNew)
	ON_WM_KEYDOWN()
	ON_WM_GETMINMAXINFO()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CPingPongMFC2View construction/destruction

CPingPongMFC2View::CPingPongMFC2View()
{
	// TODO: add construction code here


}

CPingPongMFC2View::~CPingPongMFC2View()
{

}

BOOL CPingPongMFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style &= ~WS_THICKFRAME;
	cs.cx = 800;
	cs.cy = 600;

	return CView::PreCreateWindow(cs);
}

// CPingPongMFC2View drawing

void CPingPongMFC2View::OnDraw(CDC* pDC)
{
	CPingPongMFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	CRect rect;
	GetClientRect(rect);

	CRect position = CRect(0, 0, 550, 15);

	CString s; s.LoadStringW(IDS_PREGAMEINFO);

	if (!GM.Status())
	{
		pDC->DrawText(s, position, DT_LEFT);
	}

	if (GM.Status() || GM.Won())
	{
		COLORREF back_color = pDC->GetBkColor();
		pDC->FillSolidRect(GM.GetPaddle(1), COLORREF RGB(0, 0, 0));
		pDC->FillSolidRect(GM.GetPaddle(2), COLORREF RGB(0, 0, 0));
		pDC->Ellipse(GM.GetBallPosition());
		pDC->SetBkColor(back_color);
		s.LoadStringW(IDS_PLAYER1);
		pDC->DrawText(s, CRect(0, 0, 80, 15), DT_LEFT);
		s.LoadStringW(IDS_PLAYER2);
		pDC->DrawText(s, CRect(100, 0, 170, 15), DT_LEFT);
		int score1, score2;
		score1 = GM.GetScore(1);
		score2 = GM.GetScore(2);
		CString string1;
		string1.Format(_T("%d"), score1);
		pDC->DrawText(string1, CRect(70, 0, 80, 15), DT_LEFT);
		string1.Format(_T("%d"), score2);
		pDC->DrawText(string1, CRect(180, 0, 265, 15), DT_LEFT);
	}

	if (GM.GetScore(1) >= 5)
	{
		GM.SetWon();
		KillTimer(Timer);
		s.LoadStringW(IDS_PLAYER1WON);
		pDC->DrawText(s, CRect(50, 50, 550, 215), DT_LEFT);
	}
	else if (GM.GetScore(2) >= 5)
	{
		GM.SetWon();
		KillTimer(Timer);
		s.LoadStringW(IDS_PLAYER2WON);
		pDC->DrawText(s, CRect(50, 50, 550, 215), DT_LEFT);

	}
}


// CPingPongMFC2View printing

BOOL CPingPongMFC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPingPongMFC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPingPongMFC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CPingPongMFC2View diagnostics

#ifdef _DEBUG
void CPingPongMFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CPingPongMFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPingPongMFC2Doc* CPingPongMFC2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPingPongMFC2Doc)));
	return (CPingPongMFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CPingPongMFC2View message handlers


void CPingPongMFC2View::OnFileNew()
{
	// TODO: Add your command handler code here
	RECT Client;
	GetClientRect(&Client);

	if (Timer)
		KillTimer(Timer);
	GM = GameMaster(Client);
	GM.SetStatus();
	GM.SetPlaying();
	Invalidate();
}


void CPingPongMFC2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	if (nChar == 0x53)
		GM.PlayerMove(1, 1);
	else if (nChar == 0x58)
		GM.PlayerMove(1, 2); 
	else if (nChar == 0x4B)
		GM.PlayerMove(2, 1);
	else if (nChar == 0x4D)
		GM.PlayerMove(2, 2);
	else if (nChar == VK_SPACE)
	{
		if (!GM.Won())
		{
			Timer = SetTimer(1, 1, 0);

		}
		
	}
	Invalidate();
}


void CPingPongMFC2View::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: Add your message handler code here and/or call default
	lpMMI->ptMinTrackSize.x = 800;
	lpMMI->ptMinTrackSize.y = 600;

	lpMMI->ptMaxTrackSize.x = 800;
	lpMMI->ptMaxTrackSize.x = 600;
	

	CView::OnGetMinMaxInfo(lpMMI);
}


void CPingPongMFC2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	if (GM.BallMove())
	{
		KillTimer(Timer);
	}

	Invalidate();
	CView::OnTimer(nIDEvent);
	
}


void CPingPongMFC2View::OnSize(UINT nType, int cx, int cy)
{

	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	CRect window;
	GetClientRect(window);

	if (!GM.PlayingStatus())
		return;

	GM.SetBallSize(window);
	GM.SetPlayerSize(window, 1);
	GM.SetPlayerSize(window, 2);


	GM.SetClient(window);
	GM.SetPosition(window);
	

	Invalidate();
}


int CPingPongMFC2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	lpCreateStruct->cx = 800;
	lpCreateStruct->cy = 600;

	return 0;
}
