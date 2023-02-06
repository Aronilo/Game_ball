
// GameKashirina.h: основной файл заголовка для приложения GameKashirina
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CGameKashirinaApp:
// Сведения о реализации этого класса: GameKashirina.cpp
//

class CGameKashirinaApp : public CWinApp
{
public:
	CGameKashirinaApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGameKashirinaApp theApp;
