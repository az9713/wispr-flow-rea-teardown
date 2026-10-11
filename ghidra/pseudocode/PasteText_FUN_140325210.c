
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140325210(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
                  undefined8 param_5)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  undefined8 local_30;
  
  local_30 = 0;
  lVar3 = FUN_14079cf20(&DAT_140b44aa8);
  FUN_14079d180(lVar3 + 8,param_1);
  FUN_14079d180(lVar3 + 0x10,param_3);
  FUN_14079d180(lVar3 + 0x18,param_2);
  *(undefined1 *)(lVar3 + 0x28) = param_4;
  FUN_14079d180(lVar3 + 0x20,param_5);
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  lVar1 = DAT_1411d71f0;
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar6 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar6 = FUN_14064c440();
  }
  uVar4 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar4,0,0);
  lVar5 = FUN_14079cf20(&DAT_140b06c68);
  *(undefined4 *)(lVar5 + 8) = *(undefined4 *)(*(longlong *)(lVar3 + 8) + 8);
  FUN_1406aa8a0(uVar4,&PTR_DAT_1411ab480/*"textLength"*/,lVar5,2);
  lVar5 = FUN_14079cf20(&DAT_140b05cf0);
  *(undefined1 *)(lVar5 + 8) = *(undefined1 *)(lVar3 + 0x28);
  FUN_1406aa8a0(uVar4,&PTR_DAT_14119d2c0/*"hasDelimiters"*/,lVar5,2);
  FUN_140308320(uVar6,&PTR_DAT_14112b340/*"Attempting to paste text"*/,uVar4);
  if (*(char *)(lVar3 + 0x28) == '\0') {
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar6 = FUN_14064c440();
    }
    FUN_140308320(uVar6,&PTR_DAT_14118c4c8/*"Using delayed clipboard manager for paste"*/,0);
    if (*(longlong *)(DAT_1411d71c0 + 8) == 0) {
      if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
        uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
      }
      else {
        uVar6 = FUN_14064c440();
      }
      FUN_140308420(uVar6,&PTR_DAT_141135218/*"ClipboardManager is null, falling back to regular paste"*/,0);
    }
    else {
      iVar2 = FUN_1403186e0(*(longlong *)(DAT_1411d71c0 + 8),*(undefined8 *)(lVar3 + 8),
                            *(undefined8 *)(lVar3 + 0x10),*(undefined8 *)(lVar3 + 0x18));
      if (iVar2 == 0) {
        if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
          uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
        }
        else {
          uVar6 = FUN_14064c440();
        }
        FUN_140308420(uVar6,&PTR_DAT_1411452e0/*"Failed to load text into clipboard manager, falling back to regular paste"*/,0);
      }
      else {
        if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
          uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
        }
        else {
          uVar6 = FUN_14064c440();
        }
        FUN_140308320(uVar6,&PTR_DAT_141173698/*"Text loaded successfully into delayed clipboard manager, simulating paste"*/,0);
        FUN_14016a3e0(0x32);
        iVar2 = FUN_140324cc0(&local_30);
        if (iVar2 != 0) {
          FUN_1403187e0();
          if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
            uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
          }
          else {
            uVar6 = FUN_14064c440();
          }
          FUN_140308320(uVar6,&PTR_DAT_1411616c0/*"Pasted successfully using delayed clipboard manager. Returning from PasteText"*/,0);
          return;
        }
        if ((char)local_30 != '\0') {
          FUN_1403187e0();
          if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
            uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
          }
          else {
            uVar6 = FUN_14064c440();
          }
          FUN_140308420(uVar6,&PTR_DAT_1411614b8/*"Paste shortcut was already delivered but SimulatePaste reported failure, not falling back to regular paste to avoid a duplicate paste"*/,0);
          return;
        }
        if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
          uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
        }
        else {
          uVar6 = FUN_14064c440();
        }
        FUN_140308420(uVar6,&PTR_DAT_141145808/*"Failed to paste using delayed clipboard manager, falling back to regular paste"*/,0);
      }
    }
  }
  if (PTR_FUN_1411d0560 != (undefined *)0x0) {
    FUN_140771bf8();
  }
  DAT_1411d0568 = 0;
  DAT_1411d056c = 0;
  plVar7 = (longlong *)
           (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)__tls_index * 8) + 0x10);
  lVar5 = *plVar7;
  if (lVar5 == 0) {
    lVar5 = FUN_1401ccdc0(plVar7);
  }
  if (*(longlong *)(lVar5 + 0x70) == 0) {
    FUN_140168cc0();
  }
  iVar2 = FUN_140169b50();
  if (iVar2 == 0) {
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar6 = FUN_14064c440();
    }
    FUN_140308320(uVar6,&PTR_DAT_141127128/*"Already on STA thread, pasting text directly"*/,0);
    FUN_140325ec0(*(undefined8 *)(lVar3 + 8),*(undefined8 *)(lVar3 + 0x10),
                  *(undefined8 *)(lVar3 + 0x18),*(undefined1 *)(lVar3 + 0x28),
                  *(undefined8 *)(lVar3 + 0x20));
  }
  else {
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar6 = FUN_14064c440();
    }
    FUN_140308320(uVar6,&PTR_DAT_14115d9c0/*"Not on STA thread, creating new thread to paste text"*/,0);
    uVar6 = FUN_14079cf20(&DAT_140b0a8c8);
    FUN_140775fa8(uVar6,lVar3);
    uVar4 = FUN_14079cf60(&DAT_140b09c48);
    FUN_14016a190(uVar4,uVar6);
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar6 = FUN_14064c440();
    }
    FUN_140308320(uVar6,&PTR_DAT_14118bc90/*"Updating ApartmentState of new thread to STA"*/,0);
    FUN_140169bf0(uVar4,0,1);
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar6 = FUN_14064c440();
    }
    FUN_140308320(uVar6,&PTR_DAT_14116e6a0/*"Starting thread"*/,0);
    FUN_14016a3a0(uVar4,1);
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar6 = FUN_14064c440();
    }
    FUN_140308320(uVar6,&PTR_DAT_14112c630/*"Blocking current thread until STA thread exists"*/,0);
    FUN_1401690b0(uVar4,0xffffffff);
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar6 = FUN_14064c440();
    }
    FUN_140308320(uVar6,&PTR_DAT_141168f58/*"STA thread has finished"*/,0);
  }
  if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
    uVar6 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
  }
  else {
    uVar6 = FUN_14064c440();
  }
  FUN_140308320(uVar6,&PTR_DAT_141161458/*"Paste and keyboard restore complete"*/,0);
  return;
}

