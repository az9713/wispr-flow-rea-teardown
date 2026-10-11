
void FUN_140411990(longlong param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar1 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar1 = FUN_14064c440();
  }
  uVar2 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar2,0,0);
  FUN_1406aa8a0(uVar2,&PTR_DAT_1411a4fb0/*"pasteId"*/,*(undefined8 *)(param_1 + 0x10),2);
  lVar3 = FUN_14079cf20(&DAT_140b06c68);
  *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(param_1 + 0x20);
  FUN_1406aa8a0(uVar2,&PTR_DAT_1411ab8b0/*"timeoutMs"*/,lVar3,2);
  FUN_140308320(uVar1,&PTR_DAT_141134f90/*"Clipboard not read within timeout -- paste likely failed"*/,uVar2);
  if (DAT_1411fa8a0 != '\0') {
    if (*(char *)(*(longlong *)(param_1 + 8) + 0x4c) == '\0') {
      *(undefined1 *)(*(longlong *)(param_1 + 8) + 0x4c) = 1;
      FUN_1403f6ae0(0,0xbff0000000000000,*(undefined8 *)(param_1 + 0x10));
    }
  }
  *(undefined8 *)(*(longlong *)(param_1 + 8) + 0x20) = 0;
  return;
}

