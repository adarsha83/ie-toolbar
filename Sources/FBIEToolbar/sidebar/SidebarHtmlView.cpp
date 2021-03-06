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

#include "StdAfx.h"
#include "SidebarHtmlView.h"

#include "../resource.h"

#include "../system/RuntimeContext.h"
#include "../system/UserDataObserver.h"
#include "../../common/ResourceMessages.h"
#include "../../common/ToolbarMessages.h"

namespace facebook{

// ---------------------------------------------------------------------
// class SidebarHtmlView
// ---------------------------------------------------------------------



SidebarHtmlView::SidebarHtmlView() {
   actionHandler_ = &(SidebarHtmlView::handleHtmlLoad);
   messagesHook_ = SetWindowsHookEx(WH_GETMESSAGE, 
       (HOOKPROC)getMessageHook, AfxGetApp()->m_hInstance,
       GetCurrentThreadId());
}

SidebarHtmlView::~SidebarHtmlView() {
  if (messagesHook_) {
    UnhookWindowsHookEx(messagesHook_);
  }
}

int SidebarHtmlView::getFriendsListXslResource() {
  return ResourceMessages::isTextRightAligned() ?
    IDR_SIDEBAR_FRIEND_LIST_RTL_XSLT :
    IDR_SIDEBAR_FRIEND_LIST_XSLT;
}

bool SidebarHtmlView::handleHtmlLoad(LPCTSTR url, BOOL* cancelAction, CWnd* notifyWindow) {
   UNREFERENCED_PARAMETER(notifyWindow);

   // disable the backspace  in sidebar
   if (GetAsyncKeyState(VK_BACK) & 0x8000) {
      *cancelAction = TRUE;
      return true;
   }

   String viewAction = getViewAction(url);
   
   if (!viewAction.empty()) {
   
      if (!UserDataObserver::getInstance().isLoggedIn()) {
               UserDataObserver::getInstance().login();
         } else {
            SidebarHtmlView::processBrowserCommand(viewAction, false);
         }
      *cancelAction = TRUE; // cancel navigation for our custom notification
      return true;
   }
   return false;
}

LRESULT CALLBACK SidebarHtmlView::getMessageHook(int nCode, WPARAM wParam, LPARAM lParam) {
  if (nCode < 0) {
      return CallNextHookEx(NULL, nCode, wParam, lParam);
  }
  MSG* msg = (MSG*)lParam;
  if (msg->message == WM_KEYDOWN) {
    TRACE(_T("SidebarHtmlView::getMessageHook \n"));
    if (::SendMessage(RuntimeContext::getSidebarHwnd(), 
                      TBM_CUSTOM_KEY_PRESSED, msg->wParam, (LPARAM)msg->hwnd)) {
       //if we handle it then don't pass it to other windows
        TRACE(_T("SidebarHtmlView::getMessageHook don't pass\n"));
        //return TRUE;
    }
  }
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}

} //!namespace facebook










