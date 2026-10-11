
undefined8
FUN_140319890(longlong param_1,undefined8 param_2,int param_3,longlong param_4,undefined8 param_5)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  int iVar5;
  undefined8 local_38;
  
  local_38 = 0;
  if (param_3 != 0x305) {
    if (param_3 == 0x306) {
      if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
        FUN_140773380();
      }
      if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
        uVar2 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
      }
      else {
        uVar2 = FUN_14064c440();
      }
      FUN_140308320(uVar2,&PTR_DAT_141162c70/*"Process being killed - doing nothing"*/,0);
    }
    uVar2 = FUN_1403299d0(param_2,param_3,param_4,param_5);
    return uVar2;
  }
  uVar2 = FUN_140318180();
  uVar1 = FUN_140318270(uVar2);
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar2 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar2 = FUN_14064c440();
  }
  uVar3 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar3,0,0);
  FUN_1406aa8a0(uVar3,&PTR_DAT_1411a4fb0/*"pasteId"*/,*(undefined8 *)(param_1 + 0x18),2);
  lVar4 = FUN_14079cf20(&DAT_140b08580);
  *(undefined4 *)(lVar4 + 8) = uVar1;
  FUN_1406aa8a0(uVar3,&PTR_DAT_1411a68b8/*"readerProcessId"*/,lVar4,2);
  lVar4 = FUN_14079cf20(&DAT_140b08580);
  *(undefined4 *)(lVar4 + 8) = *(undefined4 *)(param_1 + 0x40);
  FUN_1406aa8a0(uVar3,&PTR_DAT_1411aa988/*"targetProcessId"*/,lVar4,2);
  FUN_140308320(uVar2,&PTR_DAT_141135018/*"Clipboard read detected! Rendering delayed data..."*/,uVar3);
  FUN_140319e60(param_1 + 0x30);
  *(undefined1 *)(param_1 + 0x4d) = 1;
  iVar5 = (int)param_4;
  if (param_4 != iVar5) {
                    /* WARNING: Subroutine does not return */
    FUN_1401d08f0();
  }
  if (iVar5 == 0xd) {
    FUN_14031a230(param_1,*(undefined8 *)(param_1 + 8));
  }
  else if (iVar5 == 1) {
    FUN_14031a390(param_1,*(undefined8 *)(param_1 + 8));
  }
  else {
    if (PTR_FUN_1411d04f8 != (undefined *)0x0) {
      FUN_140771bc8();
    }
    if (DAT_1411d0500 != iVar5) goto LAB_140319a6e;
    FUN_14031a4f0(param_1,*(undefined8 *)(param_1 + 0x10));
  }
  FUN_140319cf0(param_1,*(undefined4 *)(param_1 + 0x44));
LAB_140319a6e:
  if ((DAT_1411fa8a0 != '\0') && (*(char *)(param_1 + 0x4c) == '\0')) {
    *(undefined1 *)(param_1 + 0x4c) = 1;
    uVar2 = FUN_140131ed0();
    local_38 = FUN_140132360(uVar2,*(undefined8 *)(param_1 + 0x50));
    uVar1 = FUN_14014bb90(&local_38);
    FUN_1403f6ae0(1,uVar1,*(undefined8 *)(param_1 + 0x18));
  }
  return 0;
}

