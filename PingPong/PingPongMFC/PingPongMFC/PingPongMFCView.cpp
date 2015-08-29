
// PingPongMFCView.cpp : implementation of the CPingPongMFCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PingPongMFC.h"
#endif

#include "PingPongMFCDoc.h"
#include "PingPongMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPingPongMFCView

IMPLEMENT_DYNCREATE(CPingPongMFCView, CView)

BEGIN_MESSAGE_MAP(CPingPongMFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CPingPongMFCView construction/destruction

CPingPongMFCView::CPingPongMFCView()
{
	// TODO: add construction code here
	WINDOWINFO WInfo;
	CWnd::GetWindowInfo(&WInfo);

	GM = GameMaster(WInfo);

}

CPingPongMFCView::~CPingPongMFCView()
{
}

BOOL CPingPongMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPingPongMFCView drawing

void CPingPongMFCView::OnDraw(CDC* pDC)
{
	CPingPongMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	pDC->Ellipse(GM.GetBall().GetPosition().x, GM.GetBall().GetPosition().y, GM.GetBall().GetPosition().x + GM.GetBall().GetBallSize(), GM.GetBall().GetPosition().y + GM.GetBall().GetBallSize());
	CView::Invalidate();

}


// CPingPongMFCView printing

BOOL CPingPongMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPingPongMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPingPongMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CPingPongMFCView diagnostics

#ifdef _DEBUG
void CPingPongMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CPingPongMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPingPongMFCDoc* CPingPongMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPingPongMFCDoc)));
	return (CPingPongMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CPingPongMFCView message handlers


void CPingPongMFCView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CView::OnPaint() for painting messages
	
}
