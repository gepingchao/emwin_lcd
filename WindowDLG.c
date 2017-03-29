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
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)
#define ID_BUTTON_0     (GUI_ID_USER + 0x01)
#define ID_ICONVIEW_0     (GUI_ID_USER + 0x03)


// USER START (Optionally insert additional defines)
#include "include.h"
#include "protocol.h"
void show_main_windows(void)
{
    WM_HideWindow(parameter_window);
    WM_ShowWindow(window);
}

// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
ICONVIEW_Handle icon_view;
unsigned char button_stat[5] = {0};
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 800, 480, 0, 0x0, 0 },
  //{ BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 712, 451, 80, 20, 0, 0x0, 0 },
  //{ ICONVIEW_CreateIndirect, "Iconview", ID_ICONVIEW_0, 90, 160, 640, 140, 0, 0x0, 0 },
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
  int     NCode;
  int     Id;
  char pull_info[30];
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Window'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, (0Xbdfb86));


    icon_view = ICONVIEW_CreateEx(90,130,640,180,hItem,WM_CF_SHOW| WM_CF_HASTRANS,0,ID_ICONVIEW_0,120,180);

    //hItem = WM_GetDialogItem(pMsg->hWin, ID_ICONVIEW_0);
    hItem = icon_view;
    //WINDOW_SetBkColor(hItem, (0x00C08000));
    //ICONVIEW_SetBkColor(hItem,(0Xbdfb86),(0Xbdfb86));
    ICONVIEW_SetBkColor(hItem,ICONVIEW_CI_BK,GUI_GREEN);
    ICONVIEW_SetBkColor(hItem,ICONVIEW_CI_SEL,0XE8AB97);
    ICONVIEW_SetIconAlign(hItem, ICONVIEW_IA_TOP);
    ICONVIEW_SetTextColor(hItem, ICONVIEW_CI_UNSEL, GUI_GRAY);
    ICONVIEW_SetTextColor(hItem, ICONVIEW_CI_SEL, GUI_GRAY);
    ICONVIEW_SetFrame(hItem, GUI_COORD_X, 0);
    ICONVIEW_SetFrame(hItem, GUI_COORD_Y, 0);
    ICONVIEW_SetSpace(hItem, GUI_COORD_X, 10);//设置图标和图标之间的间距
    ICONVIEW_SetSpace(hItem, GUI_COORD_Y, 20);

    ICONVIEW_SetFont(hItem, HZ32_32);
    //ICONVIEW_SetFont(hItem, GUI_FONT_20_ASCII);


    ICONVIEW_AddBitmapItem(hItem, &bmbeer, "酿酒");//添加图标项
    ICONVIEW_AddBitmapItem(hItem, &bmpaishui, "排水");
    ICONVIEW_AddBitmapItem(hItem, &bmwater, "加水");
    ICONVIEW_AddBitmapItem(hItem, &bmshower, "冲洗");
    ICONVIEW_AddBitmapItem(hItem, &bmseting, "设置");

    //hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    //BUTTON_SetFont(hItem, HZ);
    //BUTTON_SetText(hItem, "返回");

    //ICONVIEW_SetItemText(icon_view,0,"酿酒");
    //ICONVIEW_SetItemText(icon_view,1,"排水");
    //ICONVIEW_SetItemText(icon_view,2,"加水");
    //ICONVIEW_SetItemText(icon_view,3,"冲洗");

    //ICONVIEW_AddBitmapItem(hItem, &bmbeer, "help");//添加图标项
    //ICONVIEW_AddBitmapItem(hItem, &bmpaishui, "ll");
    //ICONVIEW_AddBitmapItem(hItem, &bmwater, "js");
    //ICONVIEW_AddBitmapItem(hItem, &bmshower, "cs");

    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_ICONVIEW_0: // Notifications sent by 'Iconview'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        //printf("node = %d\n",NCode);




        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
         switch(ICONVIEW_GetSel(icon_view))
        {
        case 0 :
            //ICONVIEW_SetItemText(icon_view,0,"nj");
            show_parameter_window();
            break;
        case 1 :
            //ICONVIEW_SetItemText(icon_view,1,"ss");
            if(button_stat[0] == 0)
            {
                button_stat[0]= 1;
                ICONVIEW_SetFont(icon_view, HZ32_32);
                ICONVIEW_SetItemText(icon_view,1,"排水中");
                send_start_drain();
            }
            else
            {
                button_stat[0]= 0;
                ICONVIEW_SetFont(icon_view, HZ32_32);
                ICONVIEW_SetItemText(icon_view,1,"排水");
                send_stop_drain();
            }
            break;

        case 2 :
            //ICONVIEW_SetItemText(icon_view,1,"ss");
            if(button_stat[1] == 0)
            {
                button_stat[1]= 1;
                ICONVIEW_SetFont(icon_view, HZ32_32);
                ICONVIEW_SetItemText(icon_view,2,"加水中");
              send_start_watering();
            }
            else
            {
                button_stat[1]= 0;
                ICONVIEW_SetFont(icon_view, HZ32_32);
                ICONVIEW_SetItemText(icon_view,2,"加水");
              send_stop_watering();
            }
            break;

        case 3 :
            //ICONVIEW_SetItemText(icon_view,1,"ss");
            if(button_stat[2] == 0)
            {
                button_stat[2]= 1;
                ICONVIEW_SetFont(icon_view, HZ32_32);
                ICONVIEW_SetItemText(icon_view,3,"冲洗中");
              send_start_wash();
            }
            else
            {
                button_stat[2]= 0;
                ICONVIEW_SetFont(icon_view, HZ32_32);
                ICONVIEW_SetItemText(icon_view,3,"冲洗");
              send_stop_wash();
            }
            break;
        case 4:
            {
                reset_key_value();
                //hItem = WM_GetDialogItem(key_board, (GUI_ID_USER + 0x0D));
                //ICONVIEW_SetFont(icon_view, HZ);
                //TEXT_SetText(hItem,"pswd");
                //FRAMEWIN_SetText(key_board, "PSWD");
                //WM_ShowWindow(key_board);
                show_psw_dlg();
            }
            }
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SCROLL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
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
*       CreateWindow
*/
WM_HWIN CreateWindow(void);
WM_HWIN CreateWindow(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
