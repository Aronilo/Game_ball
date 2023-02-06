
// GameKashirinaDoc.cpp: реализация класса CGameKashirinaDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "GameKashirina.h"
#endif

#include "GameKashirinaDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGameKashirinaDoc

IMPLEMENT_DYNCREATE(CGameKashirinaDoc, CDocument)

BEGIN_MESSAGE_MAP(CGameKashirinaDoc, CDocument)
	ON_COMMAND(ID_LEVEL_1, &CGameKashirinaDoc::OnLevel1)
	ON_COMMAND(ID_LEVEL_2, &CGameKashirinaDoc::OnLevel2)
	ON_COMMAND(ID_LEVEL_3, &CGameKashirinaDoc::OnLevel3)
END_MESSAGE_MAP()

CMyLet::CMyLet() {
	m_x = 0;
	m_y = 0;
	m_r = 0;
	deltaY = 0;
}

void CMyLet::Create(int height, int width) {
	m_r = 10 + rand() % 20;
	m_y = m_r - (height - 2 * m_r);
	m_x = m_r + rand() % (width - 2 * m_r);
	deltaY = 10;
}

CMyVictim::CMyVictim() {
	srand(time(NULL));
	m_xV = 0;
	m_yV = 0;
	m_rV = 0;
}

void CMyVictim::CreateV(int height, int width) {
	m_rV = 20;
	m_yV = height - 70;
	m_xV = width / 2.0;
}

void CMyLet::Draw(CDC* pDC) {
	CPen pen(PS_SOLID, 2, color);
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(m_x + m_r, m_y);
	pDC->AngleArc(m_x, m_y, m_r, 0, 360);
}

void CMyVictim::Draw(CDC* pDC) {
	CPen pen(PS_SOLID, 2, colorV);
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->SelectObject(&pen);
	pDC->MoveTo(m_xV + m_rV, m_yV);
	pDC->AngleArc(m_xV, m_yV, m_rV, 0, 360);
}

void CMyLet::Traffic(int height, int width) {
	m_y += deltaY;
	if (m_y > height) {
		m_y = 0;
		m_x = m_r + rand() % (width - 2 * m_r);
	}
}

bool CMyVictim::Bumb(CMyLet& let) {
	double distance = sqrt(pow(m_xV - let.m_x, 2.0) + pow(m_yV - let.m_y, 2.0));
	return distance < (m_rV + let.m_r);
}

// Создание или уничтожение CGameKashirinaDoc

bool CGameKashirinaDoc::СheckСollision() {
	for (int i = 0; i < bubbles.size(); i++) {
		if (victim.Bumb(bubbles[i])) {
			return TRUE;
		}
	}
	return FALSE;
}

CGameKashirinaDoc::CGameKashirinaDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CGameKashirinaDoc::~CGameKashirinaDoc()
{
}

BOOL CGameKashirinaDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CGameKashirinaDoc

void CGameKashirinaDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CGameKashirinaDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CGameKashirinaDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CGameKashirinaDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CGameKashirinaDoc

#ifdef _DEBUG
void CGameKashirinaDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGameKashirinaDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CGameKashirinaDoc


void CGameKashirinaDoc::OnLevel1()
{
	for (int i = 0; i < bubbles.size(); i++) {
		//tree.DeleteAllItems();
		bubbles[i].deltaY = 5;
		//m_pDoc->bubbles[j].color = ColorsLet[i].number;
	}
}


void CGameKashirinaDoc::OnLevel2()
{
	// TODO: добавьте свой код обработчика команд
	for (int i = 0; i < bubbles.size(); i++) {
		//tree.DeleteAllItems();
		bubbles[i].deltaY = 10;
		//m_pDoc->bubbles[j].color = ColorsLet[i].number;
	}
}


void CGameKashirinaDoc::OnLevel3()
{
	for (int i = 0; i < bubbles.size(); i++) {
		//tree.DeleteAllItems();
		bubbles[i].deltaY = 20;
		//m_pDoc->bubbles[j].color = ColorsLet[i].number;
	}
}
