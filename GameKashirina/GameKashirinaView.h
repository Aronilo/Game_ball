
// GameKashirinaView.h: интерфейс класса CGameKashirinaView
//
#include "GameKashirinaDoc.h"
#pragma once


class CGameKashirinaView : public CView
{
protected: // создать только из сериализации
	CGameKashirinaView() noexcept;
	DECLARE_DYNCREATE(CGameKashirinaView)

// Атрибуты
public:
	CGameKashirinaDoc* GetDocument() const;

	CGameKashirinaDoc* m_pDoc;

	void FeelTree();

	void Lose(CDC* pDC);
	bool freeze = false;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CGameKashirinaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // версия отладки в GameKashirinaView.cpp
inline CGameKashirinaDoc* CGameKashirinaView::GetDocument() const
   { return reinterpret_cast<CGameKashirinaDoc*>(m_pDocument); }
#endif

