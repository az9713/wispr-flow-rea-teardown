
void FUN_1403196b0(longlong param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  uVar2 = FUN_140318210();
  uVar1 = FUN_140318270(uVar2);
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  if (PTR_FUN_1411d0740 != (undefined *)0x0) {
    FUN_14077371c();
  }
  uVar2 = *(undefined8 *)(DAT_1411d7350 + 0x20);
  uVar1 = FUN_140318380(uVar2);
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = FUN_1403183f0(uVar2);
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar3 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar3 = FUN_14064c440();
  }
  uVar4 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar4,0,0);
  FUN_1406aa8a0(uVar4,&PTR_DAT_1411a4fb0/*"pasteId"*/,*(undefined8 *)(param_1 + 0x18),2);
  FUN_1406aa8a0(uVar4,&PTR_DAT_1411aa958/*"targetProcess"*/,uVar2,2);
  lVar5 = FUN_14079cf20(&DAT_140b06c68);
  *(undefined4 *)(lVar5 + 8) = *(undefined4 *)(param_1 + 0x44);
  FUN_1406aa8a0(uVar4,&PTR_DAT_1411a7060/*"restoreDelayMs"*/,lVar5,2);
  lVar5 = FUN_14079cf20(&DAT_140b06c68);
  *(undefined4 *)(lVar5 + 8) = *(undefined4 *)(param_1 + 0x48);
  FUN_1406aa8a0(uVar4,&PTR_DAT_14119bde0/*"failureTimeoutMs"*/,lVar5,2);
  FUN_140308320(uVar3,&PTR_DAT_141134180/*"Captured paste target"*/,uVar4);
  return;
}

