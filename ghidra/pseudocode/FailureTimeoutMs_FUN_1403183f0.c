
undefined8 FUN_1403183f0(undefined8 param_1)

{
  longlong lVar1;
  int iVar2;
  
  if (PTR_FUN_1411d04f0 != (undefined *)0x0) {
    FUN_140773396();
  }
  lVar1 = DAT_1411d71f8;
  iVar2 = FUN_140318320(param_1,*(undefined8 *)(DAT_1411d71f8 + 8));
  if (iVar2 == 0) {
    iVar2 = FUN_140318320(param_1,*(undefined8 *)(lVar1 + 0x10));
    if (iVar2 == 0) {
      return 1000;
    }
  }
  return 3000;
}

