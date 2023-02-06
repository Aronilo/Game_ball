
// GameKashirinaDoc.h: интерфейс класса CGameKashirinaDoc 
//

#include <vector>
#include "CMyTreeView.h"

#pragma once

class CMyLet {
public:
	int m_x, m_y, m_r, deltaX, deltaY;
	CMyLet();

	COLORREF color;

	
	void Draw(CDC* pDC);
	void Create(int, int);
	void Traffic(int, int);
};

class CMyVictim {
public:
	CMyVictim();
	int m_xV, m_yV, m_rV;

	COLORREF colorV;

	void Draw(CDC* pDC);
	void CreateV(int, int);

	bool Bumb(CMyLet&);
};

class CGameKashirinaDoc : public CDocument
{
protected: // создать только из сериализации
	CGameKashirinaDoc() noexcept;
	DECLARE_DYNCREATE(CGameKashirinaDoc)

// Атрибуты
public:

	std::vector <CMyLet> bubbles;
	CMyVictim victim;

	int n_bubbles;

	CGameKashirinaDoc* m_pDoc;
	//CGameKashirinaView* m_pTreeView;

	bool СheckСollision();
	//void lose();

	CMyTreeView* m_pTreeView;


// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CGameKashirinaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnLevel1();
	afx_msg void OnLevel2();
	afx_msg void OnLevel3();
};
