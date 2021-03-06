
// PingPongMFC2View.h : interface of the CPingPongMFC2View class
//

#pragma once
#include"Game.h"

class CPingPongMFC2View : public CView
{
protected: // create from serialization only
	CPingPongMFC2View();
	DECLARE_DYNCREATE(CPingPongMFC2View)

// Attributes
public:
	CPingPongMFC2Doc* GetDocument() const;
	GameMaster GM;
	UINT_PTR Timer = 0;


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
	virtual ~CPingPongMFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileNew();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnFileAbout();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // debug version in PingPongMFC2View.cpp
inline CPingPongMFC2Doc* CPingPongMFC2View::GetDocument() const
   { return reinterpret_cast<CPingPongMFC2Doc*>(m_pDocument); }
#endif

