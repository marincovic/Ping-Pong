
// PingPongMFCView.h : interface of the CPingPongMFCView class
//

#pragma once

#include "Game.cpp"

class CPingPongMFCView : public CView
{
protected: // create from serialization only
	CPingPongMFCView();
	DECLARE_DYNCREATE(CPingPongMFCView)

// Attributes
public:
	CPingPongMFCDoc* GetDocument() const;
	GameMaster GM;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CPingPongMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // debug version in PingPongMFCView.cpp
inline CPingPongMFCDoc* CPingPongMFCView::GetDocument() const
   { return reinterpret_cast<CPingPongMFCDoc*>(m_pDocument); }
#endif

