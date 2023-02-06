// CMyTreeView.cpp: файл реализации
//

#include "pch.h"
#include "GameKashirina.h"
#include "CMyTreeView.h"
#include "GameKashirinaDoc.h"


// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// Диагностика CMyTreeView

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CMyTreeView


int CMyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS
		| TVS_LINESATROOT | TVS_SHOWSELALWAYS;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания
	FillTree();
	return 0;
}

void CMyTreeView::FillTree() {
	
	CTreeCtrl& tree = GetTreeCtrl();
	tree.DeleteAllItems();

	m_hColor = tree.InsertItem(L"ColorLet", -1, -1, NULL, TVI_FIRST);
	ColorsLet = {
		{ tree.InsertItem (L"Red",-1, -1, m_hColor, TVI_FIRST), L"Red", RGB(255, 0, 0) },
		{ tree.InsertItem(L"Blue",-1, -1, m_hColor, TVI_FIRST), L"Blue", RGB(0, 0, 255)},
		{ tree.InsertItem(L"Green",-1, -1, m_hColor, TVI_FIRST), L"Green", RGB(0, 255, 0)}
	};

	m_hColorV = tree.InsertItem(L"ColorVictim", -1, -1, NULL, TVI_FIRST);

	ColorVictim = {
		{ tree.InsertItem(L"Red", -1, -1, m_hColorV, TVI_FIRST), L"Red", RGB(255, 0, 0)},
		{ tree.InsertItem(L"Blue", -1, -1, m_hColorV, TVI_FIRST), L"Blue", RGB(0, 0, 255)},
		{ tree.InsertItem(L"Green", -1, -1, m_hColorV, TVI_FIRST), L"Green", RGB(0, 255, 0)}
	};

	m_hLevel = tree.InsertItem(L"Level", -1, -1, NULL, TVI_FIRST);

	Level = {
		{ tree.InsertItem(L"Level1", -1, -1, m_hLevel, TVI_FIRST), L"1 lvl", 5},
		{ tree.InsertItem(L"Level2", -1, -1, m_hLevel, TVI_FIRST), L"2 lvl", 10},
		{ tree.InsertItem(L"Level3", -1, -1, m_hLevel, TVI_FIRST), L"3 lvl", 20}
	};

}

void CMyTreeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CTreeCtrl& tree = GetTreeCtrl();
	CRect rc;

	for (int i = 0; i < ColorsLet.size(); i++)
	{
		tree.GetItemRect(ColorsLet[i].h, &rc, false);

		if (rc.PtInRect(point)) {
		
			for (int j = 0; j < m_pDoc->bubbles.size(); j++) {
				//tree.DeleteAllItems();
				m_pDoc->bubbles[j].color = ColorsLet[i].number;
				//m_pDoc->bubbles[j].color = ColorsLet[i].number;
			}
		}
	}

	for (int i = 0; i < Level.size(); i++) {

		tree.GetItemRect(Level[i].h, &rc, false);
		if (rc.PtInRect(point)) {
			for (int j = 0; j < m_pDoc->bubbles.size(); j++) {
				//tree.DeleteAllItems();
				m_pDoc->bubbles[j].deltaY = Level[i].number;
				//m_pDoc->bubbles[j].color = ColorsLet[i].number;
			}
		}
	}

	CTreeView::OnLButtonDblClk(nFlags, point);
}

