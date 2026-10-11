
undefined1 FUN_1403186e0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = FUN_14079cf20(&DAT_140b44560);
  FUN_14079d180(lVar1 + 8,param_1);
  FUN_14079d180(lVar1 + 0x10,param_2);
  FUN_14079d180(lVar1 + 0x18,param_3);
  FUN_14079d180(lVar1 + 0x20,param_4);
  if ((*(longlong *)(param_1 + 0x10) != 0) && (*(longlong *)(param_1 + 0x18) != 0)) {
    *(undefined1 *)(lVar1 + 0x28) = 0;
    uVar2 = FUN_14079cf20(&DAT_140b056d0);
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    FUN_140775e7c(uVar2,lVar1);
    FUN_14032a230(uVar3,uVar2);
    return *(undefined1 *)(lVar1 + 0x28);
  }
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar3 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar3 = FUN_14064c440();
  }
  FUN_140308520(uVar3,&PTR_DAT_141135100/*"Clipboard window not initialized yet"*/,0);
  return 0;
}

