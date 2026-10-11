
int FUN_140324cc0(undefined8 param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  lVar1 = DAT_1411d71f0;
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar7 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar7 = FUN_14064c440();
  }
  FUN_140308320(uVar7,&PTR_DAT_14116bed0/*"Simulating paste"*/,0);
  lVar4 = FUN_140323bf0();
  iVar2 = *(int *)(lVar4 + 8);
  if (iVar2 == 0) {
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar7 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar7 = FUN_14064c440();
    }
    FUN_140308320(uVar7,&PTR_DAT_14115c900/*"No modifier keys are currently pressed during SimulatePaste"*/,0);
  }
  else {
    lVar5 = *(longlong *)(DAT_1411d73a0 + 8);
    if (lVar5 == 0) {
      lVar5 = FUN_14079cf20(&DAT_140bd82d8);
      FUN_1407833b0(lVar5,0);
      FUN_14079d180(DAT_1411d73a0 + 8,lVar5);
    }
    uVar7 = FUN_1407011f0(&PTR_DAT_140a867d8,lVar4,lVar5);
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar8 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar8 = FUN_14064c440();
    }
    uVar6 = FUN_14079cf20(&DAT_140bab288);
    FUN_1406a9e20(uVar6,0,0);
    uVar7 = FUN_140123b20(&PTR_DAT_14111cdc8/*", "*/,uVar7);
    FUN_1406aa8a0(uVar6,&PTR_DAT_1411a23f0/*"modifierKeys"*/,uVar7,2);
    FUN_140308520(uVar8,&PTR_DAT_141190d90/*"[PasteFailureCause] 2 Modifier keys are currently pressed during SimulatePaste"*/,uVar6);
    if (PTR_FUN_1411d0550 != (undefined *)0x0) {
      FUN_140773404();
    }
    if (*(longlong *)(*(longlong *)(DAT_1411d7220 + 8) + 8) != 0) {
      FUN_14064c440();
    }
    lVar5 = FUN_1403206b0();
    if (*(char *)(*(longlong *)(lVar5 + 0xb0) + 8) == '\0') {
      if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
        uVar7 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
      }
      else {
        uVar7 = FUN_14064c440();
      }
      FUN_140308320(uVar7,&PTR_DAT_14118e0f8/*"Windows key up simulation feature flag is disabled, skipping key up simulation"*/,0);
    }
    else {
      if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
        uVar7 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
      }
      else {
        uVar7 = FUN_14064c440();
      }
      FUN_140308320(uVar7,&PTR_DAT_14118e1b0/*"Windows key up simulation feature flag is enabled, performing key up simulation"*/,0);
      uVar10 = 0;
      do {
        uVar9 = *(uint *)(lVar4 + 0x10 + uVar10 * 4);
        if ((((uVar9 == 0xa4) || (uVar9 == 0xa5)) || (uVar9 == 0x12)) ||
           ((uVar9 == 0x5b || (uVar9 == 0x5c)))) {
          if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
            uVar7 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
          }
          else {
            uVar7 = FUN_14064c440();
          }
          uVar8 = FUN_14079cf20(&DAT_140bab288);
          FUN_1406a9e20(uVar8,0,0);
          uVar6 = FUN_140323e00(uVar9);
          FUN_1406aa8a0(uVar8,&PTR_DAT_1411a0378/*"keyName"*/,uVar6,2);
          FUN_140308320(uVar7,&PTR_DAT_14115a0a0/*"Modifier key is pressed, using SendMaskingSequence to simulate key up"*/);
          FUN_140323170(uVar9 & 0xffff,0x11,0,0);
        }
        uVar9 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar9;
      } while ((int)uVar9 < iVar2);
    }
  }
  if (PTR_FUN_1411d0740 != (undefined *)0x0) {
    FUN_14077371c();
  }
  lVar4 = DAT_1411d7350;
  uVar7 = *(undefined8 *)(DAT_1411d7350 + 0x20);
  if (PTR_FUN_1411d0550 != (undefined *)0x0) {
    FUN_140773404();
  }
  if (*(longlong *)(*(longlong *)(DAT_1411d7220 + 8) + 8) != 0) {
    FUN_14064c440();
  }
  lVar5 = FUN_1403206b0();
  if ((*(char *)(*(longlong *)(lVar5 + 0x98) + 8) == '\0') ||
     (iVar2 = FUN_1406530e0(*(undefined8 *)(lVar4 + 8),uVar7), iVar2 == 0)) {
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar7 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar7 = FUN_14064c440();
    }
    FUN_140308320(uVar7,&PTR_DAT_14116a0c8/*"Sending Ctrl+V using SimulateKeyboardInput"*/,0);
    lVar4 = FUN_14079d040(&DAT_140ec5e78,2);
    *(undefined4 *)(lVar4 + 0x10) = 0x560011;
    iVar2 = FUN_140322420(lVar4,0x32,param_1);
  }
  else {
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar8 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar8 = FUN_14064c440();
    }
    uVar6 = FUN_14079cf20(&DAT_140bab288);
    FUN_1406a9e20(uVar6,0,0);
    FUN_1406aa8a0(uVar6,&PTR_DAT_141198680/*"currentProcessName"*/,uVar7,2);
    FUN_140308320(uVar8,&PTR_DAT_14116a138/*"Sending Shift+Insert using SimulateKeyboardInput"*/,uVar6);
    lVar4 = FUN_14079d040(&DAT_140ec5e78,2);
    *(undefined4 *)(lVar4 + 0x10) = 0x2d0010;
    iVar2 = FUN_140322420(lVar4,0x32,param_1);
  }
  iVar3 = FUN_140322010();
  if (iVar3 != 0) {
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar7 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar7 = FUN_14064c440();
    }
    FUN_140308520(uVar7,&PTR_DAT_141191000/*"[PasteFailureCause] 4 Cannot simulate paste due to UIPI restrictions - active window has higher privilege level"*/,0);
    FUN_1403f6bb0(&PTR_DAT_1411893a8/*"UIPI_RESTRICTIONS"*/);
    if (PTR_FUN_1411d0560 != (undefined *)0x0) {
      FUN_140771bf8();
    }
    DAT_1411d056c = 1;
    return 0;
  }
  if (iVar2 == 0) {
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar7 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar7 = FUN_14064c440();
    }
    uVar8 = FUN_14079cf20(&DAT_140bab288);
    FUN_1406a9e20(uVar8,0,0);
    FUN_1406aa8a0(uVar8,&PTR_DAT_1411ade00/*"windowInfo"*/,&PTR_DAT_1411ac910/*"unknown"*/,2);
    FUN_140308520(uVar7,&PTR_DAT_14116be10/*"SimulatePaste failed"*/,uVar8);
  }
  else {
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar7 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar7 = FUN_14064c440();
    }
    FUN_140308320(uVar7,&PTR_DAT_14116fa08/*"Succesfully finished simulating paste event"*/,0);
  }
  return iVar2;
}

