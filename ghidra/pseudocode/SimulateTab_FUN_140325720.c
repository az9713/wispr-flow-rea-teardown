
void FUN_140325720(void)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 local_10 [8];
  
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  lVar1 = DAT_1411d71f0;
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar3 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar3 = FUN_14064c440();
  }
  FUN_140308320(uVar3,&PTR_DAT_14116bf08/*"Simulating tab key press using SimulateKeyboardInput"*/,0);
  lVar2 = FUN_14079d040(&DAT_140ec5e78,1);
  *(undefined2 *)(lVar2 + 0x10) = 9;
  local_10[0] = 0;
  FUN_140322420(lVar2,0x32,local_10);
  if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
    uVar3 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
  }
  else {
    uVar3 = FUN_14064c440();
  }
  FUN_140308320(uVar3,&PTR_DAT_141148858/*"Finished simulating tab key press"*/,0);
  return;
}

