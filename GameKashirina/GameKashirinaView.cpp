
// GameKashirinaView.cpp: реализация класса CGameKashirinaView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "GameKashirina.h"
#endif

#include "GameKashirinaDoc.h"
#include "GameKashirinaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>

// CGameKashirinaView

IMPLEMENT_DYNCREATE(CGameKashirinaView, CView)

BEGIN_MESSAGE_MAP(CGameKashirinaView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Создание или уничтожение CGameKashirinaView

CGameKashirinaView::CGameKashirinaView() noexcept
{
	// TODO: добавьте код создания

}

CGameKashirinaView::~CGameKashirinaView()
{
}

BOOL CGameKashirinaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CGameKashirinaView

void CGameKashirinaView::OnDraw(CDC* pDC)
{
	CGameKashirinaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(&rect);

	for (int i = 0; i < pDoc->bubbles.size(); i++) {
		pDoc->bubbles[i].Draw(pDC);
	}

	pDoc->victim.Draw(pDC);

	Lose(pDC);

	// TODO: добавьте здесь код отрисовки для собственных данных
}

void CGameKashirinaView::Lose(CDC* pDC) {
	CGameKashirinaDoc* pDoc = GetDocument();
	if (pDoc->СheckСollision()) {
		CRect rect;
		GetClientRect(&rect);

		CString str;
		str.Format(L"You Lose!");
		pDC->TextOutW(rect.Width() / 2 - 11, rect.Height() / 2, str);
		for (int i = 0; i < pDoc->bubbles.size(); i++) {
			pDoc-> bubbles[i].Traffic(rect.Height(), rect.Width());
		}
	}
}


// Печать CGameKashirinaView

BOOL CGameKashirinaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CGameKashirinaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CGameKashirinaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CGameKashirinaView

#ifdef _DEBUG
void CGameKashirinaView::AssertValid() const
{
	CView::AssertValid();
}

void CGameKashirinaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGameKashirinaDoc* CGameKashirinaView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGameKashirinaDoc)));
	return (CGameKashirinaDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CGameKashirinaView

void CGameKashirinaView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	SetTimer(0, 10, NULL);
	CGameKashirinaDoc* pDoc = GetDocument();

	int amount = 1 + rand() % 8;

	pDoc->bubbles.resize(amount);

	CRect rect;
	GetClientRect(&rect);

	pDoc->victim.CreateV(rect.Height(), rect.Width());

	for (int i = 0; i < pDoc->bubbles.size(); i++) {
		pDoc->bubbles[i].Create(rect.Height(), rect.Width());
	}

	
	// TODO: добавьте специализированный код или вызов базового класса
}

void CGameKashirinaView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CGameKashirinaDoc* pDoc = GetDocument();

	CRect rect;
	GetClientRect(&rect);
	if (!freeze) {
		for (int i = 0; i < pDoc->bubbles.size(); i++) {
			pDoc->bubbles[i].Traffic(rect.Height(), rect.Width());
			//pDoc->bubbles[i].Traffic(200, 400);
			if (pDoc->СheckСollision()) {
				//чтобы не стопалось закоментируй
				//freeze = true;
			}
		}
	}

	Invalidate();

	CView::OnTimer(nIDEvent);
}


void CGameKashirinaView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CGameKashirinaDoc* pDoc = GetDocument();

	if (!freeze) {
		if (nChar == VK_LEFT)
			pDoc->victim.m_xV -= 10;
		if (nChar == VK_RIGHT)
			pDoc->victim.m_xV += 10;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
