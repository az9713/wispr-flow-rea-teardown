
void FUN_140319cf0(longlong param_1,int param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar1 = FUN_14079cf20(&DAT_140b44600);
  FUN_14079d180(lVar1 + 8,param_1);
  FUN_140319e60(param_1 + 0x28);
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar4 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar4 = FUN_14064c440();
  }
  uVar2 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar2,0,0);
  FUN_1406aa8a0(uVar2,&PTR_DAT_1411a4fb0/*"pasteId"*/,*(undefined8 *)(param_1 + 0x18),2);
  lVar3 = FUN_14079cf20(&DAT_140b06c68);
  *(int *)(lVar3 + 8) = param_2;
  FUN_1406aa8a0(uVar2,&PTR_DAT_141199568/*"delayMs"*/,lVar3,2);
  FUN_140308320(uVar4,&PTR_DAT_1411694c0/*"Scheduled clipboard restoration"*/,uVar2);
  FUN_14079d180(lVar1 + 0x10,*(undefined8 *)(param_1 + 0x18));
  uVar4 = FUN_14079cf20(&DAT_140b0a9f0);
  FUN_140775ea0(uVar4,lVar1);
  uVar2 = FUN_14079cf20(&DAT_140b0aba8);
  if (-2 < param_2) {
    FUN_1401731f0(uVar2,uVar4,0,param_2,0xffffffff,1);
    FUN_14079d180(param_1 + 0x28,uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1406fbd20(param_2,0xffffffff,&PTR_DAT_14119a408/*"dueTime"*/);
}

