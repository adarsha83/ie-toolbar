/**
* Facebook Internet Explorer Toolbar Software License 
* Copyright (c) 2009 Facebook, Inc. 
*
* Permission is hereby granted, free of charge, to any person or organization
* obtaining a copy of the software and accompanying documentation covered by
* this license (which, together with any graphical images included with such
* software, are collectively referred to below as the "Software") to (a) use,
* reproduce, display, distribute, execute, and transmit the Software, (b)
* prepare derivative works of the Software (excluding any graphical images
* included with the Software, which may not be modified or altered), and (c)
* permit third-parties to whom the Software is furnished to do so, all
* subject to the following:
*
* The copyright notices in the Software and this entire statement, including
* the above license grant, this restriction and the following disclaimer,
* must be included in all copies of the Software, in whole or in part, and
* all derivative works of the Software, unless such copies or derivative
* works are solely in the form of machine-executable object code generated by
* a source language processor.  
*
* Facebook, Inc. retains ownership of the Software and all associated
* intellectual property rights.  All rights not expressly granted in this
* license are reserved by Facebook, Inc.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*/ 

#ifndef SETUPDLG_H
#define SETUPDLG_H

#include "afxwin.h"

#include "LocaleUtils.h"

#include "../util/StringUtils.h"

namespace facebook {

/**
 * Welcome dialog for installation process
 * Include language selection for further installation
 */
class SetupDlg : public CDialog {
public:
	SetupDlg(CWnd* pParent = NULL);

	enum { IDD = IDD_SETUP_DIALOG };

  /**
   * Ok button click event
   */
  afx_msg void OnBnClickedOk();
  
  /**
   * Cancel button click event
   */
  afx_msg void OnBnClickedCancel();

  /**
   * Show window event
   * @param isShown is window being shown
   * @param status specifies status of the window
   */
  afx_msg void OnShowWindow(BOOL isShown, UINT status);

protected:
	HICON icon_;

  virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
  /**
   * Fill map this the locales description
   */
  void initLocaleMap();
  /**
   * Fill combo box this the languages
   */
  void loadLanguageNames();
  /**
   * Select current language in the combo box
   */
  void selectCurrentLang();

private:
  CComboBox langCombo_;
  LocaleMap locale_; // Locale description map
};

} // !namespace facebook

#endif // SETUPDLG_H
