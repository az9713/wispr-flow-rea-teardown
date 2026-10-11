
undefined8 FUN_140318320(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) && (iVar2 = *(int *)(param_2 + 8), 0 < iVar2)
     ) {
    puVar3 = (undefined8 *)(param_2 + 0x10);
    do {
      iVar1 = FUN_1401220a0(param_1,*puVar3,5);
      if (iVar1 != 0) {
        return 1;
      }
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}

