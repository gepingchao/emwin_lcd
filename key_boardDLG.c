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
#include "include.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0     (GUI_ID_USER + 0x00)
#define ID_BUTTON_0     (GUI_ID_USER + 0x01)
#define ID_BUTTON_1     (GUI_ID_USER + 0x02)
#define ID_EDIT_0     (GUI_ID_USER + 0x03)
#define ID_BUTTON_2     (GUI_ID_USER + 0x04)
#define ID_BUTTON_3     (GUI_ID_USER + 0x05)
#define ID_BUTTON_4     (GUI_ID_USER + 0x06)
#define ID_BUTTON_5     (GUI_ID_USER + 0x07)
#define ID_BUTTON_6     (GUI_ID_USER + 0x08)
#define ID_BUTTON_7     (GUI_ID_USER + 0x09)
#define ID_BUTTON_8     (GUI_ID_USER + 0x0A)
#define ID_TEXT_0     (GUI_ID_USER + 0x0D)
#define ID_BUTTON_9     (GUI_ID_USER + 0x0E)
#define ID_BUTTON_10     (GUI_ID_USER + 0x0F)
#define ID_BUTTON_11     (GUI_ID_USER + 0x10)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
S_Key_Glg_Info Dlg_key_value;

void disable_other_window(void)
{
    WM_DisableWindow(icon_view);
    //WM_DisableWindow(parameter_window);
}

void enable_other_window(void)
{
    WM_EnableWindow(icon_view);
    //WM_EnableWindow(parameter_window);
}

void updata_input(void)
{
    WM_HWIN hItem;
    char tmp_char[15] = {'*','*','*','*','*','*','*','*','*','*','*','*'};
    char loopx;
    hItem = WM_GetDialogItem(key_board, ID_EDIT_0);
    switch(Dlg_key_value.cur_function)
    {
    case 1:
        break;
    case 2:
        break;
    case 77:
        EDIT_SetDecMode(hItem,Dlg_key_value.int_key_value,Dlg_key_value.int_key_value,Dlg_key_value.int_key_value,0,0);
        EDIT_SetMaxLen(hItem,Dlg_key_value.max_input_length + 1);
        EDIT_SetTextAlign(hItem,GUI_TA_RIGHT);
        break;
    case 88:
        EDIT_SetTextMode(hItem);
        EDIT_SetMaxLen(hItem,Dlg_key_value.input_length);
        EDIT_SetText(hItem,tmp_char);
        break;
    default:
        EDIT_SetDecMode(hItem,Dlg_key_value.int_key_value,Dlg_key_value.int_key_value,Dlg_key_value.int_key_value,0,0);
        EDIT_SetTextAlign(hItem,GUI_TA_RIGHT);
    break;
    }
}


void show_psw_dlg(void)
{
    WM_HWIN hItem;
    FRAMEWIN_SetFont(key_board, HZ);
    //FRAMEWIN_SetText(key_board, "\u00C7\u00EB\u00CA\u00E4\u00C8\u00EB");
    FRAMEWIN_SetText(key_board, "������");
    FRAMEWIN_SetTextColor(key_board, (0x00FF0080));
    FRAMEWIN_SetMoveable(key_board,1);
    hItem = WM_GetDialogItem(key_board, ID_TEXT_0);
    TEXT_SetFont(hItem, HZ);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
    TEXT_SetText(hItem, "����:");
    //TEXT_SetText(hItem, "\u5BC6\u7801:");
    Dlg_key_value.cur_function = 88;
    Dlg_key_value.max_input_length = 7;
    WM_ShowWindow(key_board);
    disable_other_window();
    updata_input();
}

void show_key_board(const char* keyboard_name,unsigned char input_length)
{
    WM_HWIN hItem;
    FRAMEWIN_SetFont(key_board, HZ);
    //FRAMEWIN_SetText(key_board, "\u00C7\u00EB\u00CA\u00E4\u00C8\u00EB");
    FRAMEWIN_SetText(key_board, "������");
    FRAMEWIN_SetTextColor(key_board, (0x00FF0080));
    FRAMEWIN_SetMoveable(key_board,1);
    hItem = WM_GetDialogItem(key_board, ID_TEXT_0);
    TEXT_SetFont(hItem, HZ);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
    TEXT_SetText(hItem, keyboard_name);
    //TEXT_SetText(hItem, "\u5BC6\u7801:");
    Dlg_key_value.cur_function = 77;
    Dlg_key_value.max_input_length = input_length - 1;
    WM_ShowWindow(key_board);
    disable_other_window();
    updata_input();
}

void reset_key_value(void)
{
    Dlg_key_value.key_point = 0;
    Dlg_key_value.int_key_value = 0;
    Dlg_key_value.input_length = 0;
    Dlg_key_value.cur_function = 0;
    Dlg_key_value.max_input_length = 0;
    updata_input();
}

void pop_key(unsigned char key_num)
{
    if((Dlg_key_value.key_point > MAX_KEY_LENGTH)||(Dlg_key_value.input_length > Dlg_key_value.max_input_length))
    {
        return;
    }

    Dlg_key_value.key_value_arry[Dlg_key_value.key_point++] = key_num;
    Dlg_key_value.int_key_value = Dlg_key_value.int_key_value*10 + key_num;
    Dlg_key_value.input_length ++;
    updata_input();
}
void push_key(void)
{
    //Dlg_key_value.key_value_arry[Dlg_key_value.key_point++] = key_num;
    Dlg_key_value.key_point = Dlg_key_value.key_point == 0? 1: Dlg_key_value.key_point;
    Dlg_key_value.key_point --;
    Dlg_key_value.input_length = Dlg_key_value.input_length == 0? 1: Dlg_key_value.input_length;
    Dlg_key_value.input_length -- ;
    Dlg_key_value.int_key_value = Dlg_key_value.int_key_value/10;
    updata_input();
}

void deal_button_ok(void)
{
    WM_HWIN hItem;
    if(Dlg_key_value.cur_function == 77)
    {
        hItem = WM_GetDialogItem(key_board, ID_EDIT_0);
        //Dlg_key_value.key_board_value = EDIT_GetValue(hItem);
        //display_value_on_edit(Dlg_key_value.key_board_value,Dlg_key_value.cur_cursor);
        display_value_on_edit(Dlg_key_value.int_key_value,Dlg_key_value.cur_cursor);
    }
    if(Dlg_key_value.cur_function == 88)//����
    {
        if((Dlg_key_value.input_length == 8)&&(Dlg_key_value.int_key_value == 88888888))
        {
            enable_button_save();
            enable_set_parameter();
        }
    }
    WM_HideWindow(key_board);
    enable_other_window();
    reset_key_value();
}

// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "key_board", ID_FRAMEWIN_0, 356, 123, 203, 307, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "Button_1", ID_BUTTON_0, 25, 65, 40, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button_2", ID_BUTTON_1, 75, 65, 40, 40, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "input_value", ID_EDIT_0, 79, 19, 90, 25, 0, 0x8, 0 },
  { BUTTON_CreateIndirect, "Button_3", ID_BUTTON_2, 125, 65, 40, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button_4", ID_BUTTON_3, 25, 115, 40, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button_5", ID_BUTTON_4, 75, 115, 40, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button_6", ID_BUTTON_5, 125, 115, 40, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button_7", ID_BUTTON_6, 25, 165, 40, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button_8", ID_BUTTON_7, 75, 165, 40, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button_9", ID_BUTTON_8, 125, 165, 40, 40, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "input", ID_TEXT_0, 5, 20, 65, 30, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "Button_0", ID_BUTTON_9, 75, 215, 40, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button_BC", ID_BUTTON_10, 25, 215, 40, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button_OK", ID_BUTTON_11, 125, 215, 40, 40, 0, 0x0, 0 },
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
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'key_board'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetText(hItem, "INPUT");
    FRAMEWIN_SetTextColor(hItem, (0x00FF0080));
    FRAMEWIN_SetMoveable(hItem,1);
    //
    // Initialization of 'Button_1'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "1");
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    //
    // Initialization of 'Button_2'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "2");
    //
    // Initialization of 'input_value'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
    EDIT_SetText(hItem, "");
    EDIT_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'Button_3'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "3");
    //
    // Initialization of 'Button_4'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "4");
    //
    // Initialization of 'Button_5'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "5");
    //
    // Initialization of 'Button_6'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "6");
    //
    // Initialization of 'Button_7'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "7");
    //
    // Initialization of 'Button_8'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "8");
    //
    // Initialization of 'Button_9'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "9");
    //
    // Initialization of 'input'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "IN PUT:");
    TEXT_SetFont(hItem, GUI_FONT_16B_ASCII);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER);
    //
    // Initialization of 'Button_0'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "0");
    //
    // Initialization of 'Button_BC'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_10);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "DEL");
    //
    // Initialization of 'Button_OK'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_11);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "OK");
    // USER START (Optionally insert additional code for further widget initialization)
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
    EDIT_SetTextAlign(hItem,GUI_TA_RIGHT);
    //EDIT_SetDecMode(hItem,Dlg_key_value.int_key_value,0,999999999,0,0);

    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'Button_1'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        pop_key(1);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'Button_2'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        pop_key(2);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_0: // Notifications sent by 'input_value'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_2: // Notifications sent by 'Button_3'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        pop_key(3);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_3: // Notifications sent by 'Button_4'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        pop_key(4);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_4: // Notifications sent by 'Button_5'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        pop_key(5);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_5: // Notifications sent by 'Button_6'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        pop_key(6);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_6: // Notifications sent by 'Button_7'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        pop_key(7);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_7: // Notifications sent by 'Button_8'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        pop_key(8);
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
    case ID_BUTTON_8: // Notifications sent by 'Button_9'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        pop_key(9);
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
    case ID_BUTTON_9: // Notifications sent by 'Button_0'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        pop_key(0);
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
    case ID_BUTTON_10: // Notifications sent by 'Button_BC'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        push_key();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_11: // Notifications sent by 'Button_OK'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        deal_button_ok();
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
*       Createkey_board
*/
WM_HWIN Createkey_board(void);
WM_HWIN Createkey_board(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
