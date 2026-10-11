
void FUN_14016a3e0(undefined8 param_1)

{
  undefined1 local_68 [40];
  
  if (-2 < (int)(DWORD)param_1) {
    FUN_14079ea70(local_68);
    Sleep((DWORD)param_1);
    FUN_14079eac0(local_68);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_1406fbd20(param_1,0xffffffff,&PTR_DAT_1411a20d0/*"millisecondsTimeout"*/);
}

