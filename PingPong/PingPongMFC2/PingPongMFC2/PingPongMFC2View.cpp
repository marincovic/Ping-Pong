
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

	return CView::PreCreateWindow(cs);
}

// CPingPongMFC2View drawing

void CPingPongMFC2View::OnDraw(CDC* pDC)
{
	CPingPongMFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDC dc;
	dc.CreateCompatibleDC(pDC);
	dc.SelectObject(CPen(PS_SOLID, 2, RGB(0, 0, 0)));
	// TODO: add draw code for native data here


	if (GM.stauts())
	{
		dc.FillSolidRect(GM.GetPaddle(1), COLORREF RGB(0, 0, 0));
		dc.FillSolidRect(GM.GetPaddle(2), COLORREF RGB(0, 0, 0));
		dc.Ellipse(GM.GetBallPosition());
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

	GM = GameMaster(Client);
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
	else if (nChar == 0x4B)
		GM.PlayerMove(2, 2);
	//else if ()
}
