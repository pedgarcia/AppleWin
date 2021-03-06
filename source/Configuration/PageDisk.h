#pragma once

#include "IPropertySheetPage.h"
#include "PropertySheetDefs.h"
class CPropertySheetHelper;

class CPageDisk : private IPropertySheetPage
{
public:
	CPageDisk(CPropertySheetHelper& PropertySheetHelper) :
		m_Page(PG_DISK),
		m_PropertySheetHelper(PropertySheetHelper)
	{
		CPageDisk::ms_this = this;

		hdd1Selection = -1;
		hdd2Selection = -1;
	}
	virtual ~CPageDisk(){}

	static BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);

protected:
	// IPropertySheetPage
	virtual BOOL DlgProcInternal(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);
	virtual void DlgOK(HWND hWnd);
	virtual void DlgCANCEL(HWND hWnd){}

private:
	void InitOptions(HWND hWnd);
	void EnableHDD(HWND hWnd, BOOL bEnable);
	void handleHDDCombo(HWND hWnd, UINT16 driveSelected, UINT16 comboSelected);
	void handleDiskCombo(HWND hWnd, UINT16 driveSelected, UINT16 comboSelected);
	int removalConfirmation(int iCommand);

	static CPageDisk* ms_this;
	static const TCHAR m_discchoices[];
	static const TCHAR m_defaultDiskOptions[];
	static const TCHAR m_defaultHDDOptions[];

	int  hdd1Selection;
	int  hdd2Selection;

	const PAGETYPE m_Page;
	CPropertySheetHelper& m_PropertySheetHelper;
};
