/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.30                          *
*        Compiled Jul  1 2015, 10:50:32                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_TEXT_0 (GUI_ID_USER + 0x02)
#define ID_TEXT_1 (GUI_ID_USER + 0x03)
#define ID_TEXT_2 (GUI_ID_USER + 0x04)


// USER START (Optionally insert additional defines)
#include "include.h"
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)

void show_runing_window(void)
{
    WM_ShowWindow(runing_window);
    WM_HideWindow(window);
    WM_HideWindow(parameter_window);
}

void hide_runing_window(void)
{
    WM_HideWindow(runing_window);
    WM_HideWindow(parameter_window);
}

void set_runing_window_beer_name(const char* name)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(runing_window, ID_TEXT_1);
    TEXT_SetFont(hItem, HZ24_24);
    TEXT_SetText(hItem, name);
    //TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
}

// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "runing_windows", ID_WINDOW_0, 0, 0, 800, 480, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "title", ID_TEXT_0, 80, 20, 640, 150, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "state", ID_TEXT_1, 80, 180, 640, 80, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "runing_stat", ID_TEXT_2, 80, 300, 640, 80, 0, 0x64, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'runing_windows'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, (0x00BDFB86));
    //
    // Initialization of 'title'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, HZ32_32);
    TEXT_SetText(hItem, "��ƽ�����");
    //
    // Initialization of 'state'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetText(hItem, "states");
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, HZ24_24);
    //
    // Initialization of 'runing_stat'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetText(hItem, "״̬:");
    TEXT_SetFont(hItem, HZ24_24);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       Createruning_windows
*/
WM_HWIN Createruning_windows(void);
WM_HWIN Createruning_windows(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/