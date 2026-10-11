
void FUN_1403259d0(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  double dVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined4 uVar9;
  undefined **ppuVar10;
  undefined **ppuVar11;
  undefined1 local_90 [8];
  double local_88;
  undefined1 local_80 [8];
  double local_78;
  undefined8 local_70 [6];
  
  local_70[0] = 0;
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  lVar8 = DAT_1411d71f0;
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar5 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar5 = FUN_14064c440();
  }
  uVar3 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar3,0,0);
  lVar4 = FUN_14079cf20(&DAT_140b06c68);
  *(undefined4 *)(lVar4 + 8) = *(undefined4 *)(param_1 + 8);
  FUN_1406aa8a0(uVar3,&PTR_DAT_1411ab480/*"textLength"*/,lVar4,2);
  FUN_140308320(uVar5,&PTR_DAT_141161870/*"Pasting text helper immediate clipboard"*/,uVar3);
  FUN_14032b010();
  if ((param_2 == 0) || (*(int *)(param_2 + 8) == 0)) {
    uVar5 = FUN_14079cf20(&DAT_140bac7d0);
    FUN_1406a9e20(uVar5,0,0);
    FUN_1406aa8a0(uVar5,&PTR_DAT_141173678/*"Text"*/,param_1,1);
    FUN_140326e60(uVar5);
  }
  else {
    uVar5 = FUN_14079cf20(&DAT_140bac7d0);
    FUN_1406a9e20(uVar5,0,0);
    FUN_1406aa8a0(uVar5,&PTR_DAT_14114c258/*"HTML Format"*/,param_2,1);
    FUN_1406aa8a0(uVar5,&PTR_DAT_141173678/*"Text"*/,param_1,1);
    FUN_140326e60(uVar5);
  }
  if (*(longlong *)(*(longlong *)(lVar8 + 8) + 8) == 0) {
    uVar5 = *(undefined8 *)(*(longlong *)(lVar8 + 8) + 0x18);
  }
  else {
    uVar5 = FUN_14064c440();
  }
  FUN_140308320(uVar5,&PTR_DAT_1411485b0/*"Finished copying clipboard contents"*/,0);
  iVar2 = FUN_14032b050();
  if (iVar2 == 0) {
    uVar9 = 0;
  }
  else {
    lVar4 = FUN_14032b090();
    uVar9 = *(undefined4 *)(lVar4 + 8);
  }
  if (*(longlong *)(*(longlong *)(lVar8 + 8) + 8) == 0) {
    uVar5 = *(undefined8 *)(*(longlong *)(lVar8 + 8) + 0x18);
  }
  else {
    uVar5 = FUN_14064c440();
  }
  uVar3 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar3,0,0);
  lVar4 = FUN_14079cf20(&DAT_140b06c68);
  *(undefined4 *)(lVar4 + 8) = uVar9;
  FUN_1406aa8a0(uVar3,&PTR_DAT_141196d28/*"clipboardLenBeforePaste"*/,lVar4,2);
  FUN_140308320(uVar5,&PTR_DAT_141191870/*"[paste board debug] 3/5 Clipboard text length before paste"*/,uVar3);
  uVar5 = FUN_140323bf0();
  lVar4 = FUN_140318880();
  FUN_140324cc0(local_70);
  iVar2 = FUN_14032b050();
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    lVar6 = FUN_14032b090();
    iVar2 = *(int *)(lVar6 + 8);
  }
  if (*(longlong *)(*(longlong *)(lVar8 + 8) + 8) == 0) {
    uVar3 = *(undefined8 *)(*(longlong *)(lVar8 + 8) + 0x18);
  }
  else {
    uVar3 = FUN_14064c440();
  }
  uVar7 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar7,0,0);
  lVar6 = FUN_14079cf20(&DAT_140b06c68);
  *(int *)(lVar6 + 8) = iVar2;
  FUN_1406aa8a0(uVar7,&PTR_DAT_141196c98/*"clipboardLenAfterPaste"*/,lVar6,2);
  FUN_140308320(uVar3,&PTR_DAT_141191900/*"[paste board debug] 4/5 Clipboard text length after paste"*/,uVar7);
  if (*(longlong *)(*(longlong *)(lVar8 + 8) + 8) == 0) {
    uVar3 = *(undefined8 *)(*(longlong *)(lVar8 + 8) + 0x18);
  }
  else {
    uVar3 = FUN_14064c440();
  }
  uVar7 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar7,0,0);
  FUN_1406aa8a0(uVar7,&PTR_DAT_1411ade00/*"windowInfo"*/,&PTR_DAT_1411ac910/*"unknown"*/,2);
  FUN_140308320(uVar3,&PTR_DAT_141161770/*"Pasted text in window, now sleeping for 50 ms for paste to complete"*/,uVar7);
  FUN_14016a3e0(0x32);
  FUN_140323720(param_4);
  if (PTR_FUN_1411d0560 != (undefined *)0x0) {
    FUN_140771bf8();
  }
  dVar1 = (double)DAT_1411d0568;
  ppuVar11 = *(undefined ***)(lVar4 + 8);
  if (ppuVar11 == (undefined **)0x0) {
    ppuVar11 = &PTR_DAT_1411ac910/*"unknown"*/;
  }
  ppuVar10 = *(undefined ***)(lVar4 + 0x10);
  if (ppuVar10 == (undefined **)0x0) {
    ppuVar10 = &PTR_DAT_141115cb8;
  }
  lVar8 = *(longlong *)(DAT_1411d73a0 + 8);
  if (lVar8 == 0) {
    lVar8 = FUN_14079cf20(&DAT_140bd82d8);
    FUN_1407833b0(lVar8,0);
    FUN_14079d180(DAT_1411d73a0 + 8,lVar8);
  }
  uVar5 = FUN_1407011f0(&PTR_DAT_140a867d8,uVar5,lVar8);
  uVar5 = FUN_140758b00(&PTR_DAT_140a85628,uVar5);
  local_80[0] = 1;
  local_90[0] = 1;
  local_88 = (double)iVar2;
  local_78 = dVar1;
  FUN_1403f6c60(param_3,0x101,local_80,local_90,ppuVar11,ppuVar10,uVar5,1,1);
  return;
}

