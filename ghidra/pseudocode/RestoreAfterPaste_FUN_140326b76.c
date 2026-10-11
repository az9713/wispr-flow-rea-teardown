
void FUN_140326b76(void)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  longlong unaff_RBP;
  double dVar6;
  
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  *(undefined8 *)(unaff_RBP + -0xf0) = DAT_1411d71f0;
  lVar3 = *(longlong *)(*(longlong *)(unaff_RBP + -0xf0) + 8);
  if (*(longlong *)(lVar3 + 8) == 0) {
    uVar2 = *(undefined8 *)(lVar3 + 0x18);
  }
  else {
    uVar2 = FUN_14064c440();
  }
  FUN_140308320(uVar2,&PTR_DAT_141148698/*"Finished paste timeout, restoring clipboard contents"*/,0);
  if (PTR_FUN_1411d0550 != (undefined *)0x0) {
    FUN_140773404();
  }
  if (*(longlong *)(*(longlong *)(DAT_1411d7220 + 8) + 8) != 0) {
    FUN_14064c440();
  }
  lVar3 = FUN_1403206b0();
  if (*(char *)(*(longlong *)(lVar3 + 0x20) + 8) == '\0') {
    if (*(longlong *)(unaff_RBP + -0xd8) == 0) {
      lVar3 = *(longlong *)(*(longlong *)(unaff_RBP + -0xf0) + 8);
      if (*(longlong *)(lVar3 + 8) == 0) {
        uVar2 = *(undefined8 *)(lVar3 + 0x18);
      }
      else {
        uVar2 = FUN_14064c440();
      }
      FUN_140308320(uVar2,&PTR_DAT_141169240/*"Saved clipboard was null, nothing to restore"*/,0);
    }
    else {
      uVar2 = FUN_140131ed0();
      lVar3 = *(longlong *)(*(longlong *)(unaff_RBP + -0xf0) + 8);
      if (*(longlong *)(lVar3 + 8) == 0) {
        uVar4 = *(undefined8 *)(lVar3 + 0x18);
      }
      else {
        uVar4 = FUN_14064c440();
      }
      FUN_140308320(uVar4,&PTR_DAT_14116e4e8/*"Starting clipboard restoration process"*/,0);
      FUN_14032b400(*(undefined8 *)(unaff_RBP + -0xd8),0);
      uVar4 = FUN_140131ed0();
      uVar2 = FUN_140132360(uVar4,uVar2);
      *(undefined8 *)(unaff_RBP + -0x70) = uVar2;
      uVar2 = FUN_14014bb90(unaff_RBP + -0x70);
      *(undefined8 *)(unaff_RBP + -0x68) = uVar2;
      lVar3 = *(longlong *)(*(longlong *)(unaff_RBP + -0xf0) + 8);
      if (*(longlong *)(lVar3 + 8) == 0) {
        uVar2 = *(undefined8 *)(lVar3 + 0x18);
      }
      else {
        uVar2 = FUN_14064c440();
      }
      uVar4 = FUN_14079cf20(&DAT_140bab288);
      FUN_1406a9e20(uVar4,0,0);
      dVar6 = *(double *)(unaff_RBP + -0x68);
      if (ABS(dVar6) <= 1e+16 && ABS(dVar6) != 1e+16) {
        dVar6 = (double)FUN_14011ef10(dVar6 * 100.0);
        dVar6 = dVar6 / 100.0;
      }
      lVar3 = FUN_14079cf20(&DAT_140b064b8);
      *(double *)(lVar3 + 8) = dVar6;
      FUN_1406aa8a0(uVar4,&PTR_DAT_1411abc28/*"totalRestorationTimeMs"*/,lVar3,2);
      FUN_140308320(uVar2,&PTR_DAT_141148790/*"Finished restoring clipboard contents"*/,uVar4);
    }
  }
  else {
    lVar3 = *(longlong *)(*(longlong *)(unaff_RBP + -0xf0) + 8);
    if (*(longlong *)(lVar3 + 8) == 0) {
      uVar2 = *(undefined8 *)(lVar3 + 0x18);
    }
    else {
      uVar2 = FUN_14064c440();
    }
    FUN_140308320(uVar2,&PTR_DAT_14113d048/*"DisableClipboardRestore is enabled, not restoring clipboard contents"*/,0);
  }
  iVar1 = FUN_14032b050();
  if (iVar1 == 0) {
    uVar5 = 0;
  }
  else {
    lVar3 = FUN_14032b090();
    uVar5 = *(undefined4 *)(lVar3 + 8);
  }
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  *(undefined8 *)(unaff_RBP + -0xf0) = DAT_1411d71f0;
  lVar3 = *(longlong *)(*(longlong *)(unaff_RBP + -0xf0) + 8);
  if (*(longlong *)(lVar3 + 8) == 0) {
    uVar2 = *(undefined8 *)(lVar3 + 0x18);
  }
  else {
    uVar2 = FUN_14064c440();
  }
  uVar4 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar4,0,0);
  lVar3 = FUN_14079cf20(&DAT_140b06c68);
  *(undefined4 *)(lVar3 + 8) = uVar5;
  FUN_1406aa8a0(uVar4,&PTR_DAT_141196ce0/*"clipboardLenAfterRestore"*/,lVar3,2);
  FUN_140308320(uVar2,&PTR_DAT_141191988/*"[paste board debug] 5/5 Clipboard text length after restore"*/,uVar4);
  return;
}

