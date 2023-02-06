#pragma once
#include "afxcview.h"
#include <vector>

//#include "GameKashirinaDoc.h"

// Просмотр CMyTreeView
class CGameKashirinaDoc;


struct Item
{
	HTREEITEM h;
	CString name;
	int number;
};


class CMyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyTreeView();

public:

	CGameKashirinaDoc* m_pDoc;
	//CGameKashirinaDo
	void FillTree();

	HTREEITEM m_hLevel, m_hLevel1, m_hLevel2, m_hLevel3;
	HTREEITEM m_hColor, m_hColorRed, m_hColorBlue, m_hColorGreen, m_hColorV, m_hColorRedV, m_hColorBlueV, m_hColorGreenV;

	std::vector <Item> ColorsLet;
	std::vector <Item> ColorVictim;
	std::vector <Item> Level;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};


