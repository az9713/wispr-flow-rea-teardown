
void FUN_140326e60(longlong param_1)

{
  longlong lVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined **ppuVar9;
  undefined1 auVar10 [16];
  longlong lStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  undefined **local_48;
  undefined **ppuStack_40;
  
  lStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (undefined **)0x0;
  ppuStack_40 = (undefined **)0x0;
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  lVar1 = DAT_1411d71f0;
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar7 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar7 = FUN_14064c440();
  }
  FUN_140308320(uVar7,&PTR_DAT_1411383b0/*"Copying with formatting"*/,0);
  uVar7 = 0;
  local_48 = (undefined **)0x0;
  ppuStack_40 = (undefined **)0x0;
  local_58 = (ulonglong)*(uint *)(param_1 + 0x44);
  uStack_50 = 2;
  ppuVar9 = (undefined **)0x0;
  lStack_60 = param_1;
  do {
    iVar4 = FUN_1406acca0(&lStack_60,&DAT_140baca88);
    ppuVar3 = ppuStack_40;
    ppuVar2 = local_48;
    if (iVar4 == 0) {
      if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
        uVar8 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
      }
      else {
        uVar8 = FUN_14064c440();
      }
      FUN_140308320(uVar8,&PTR_DAT_141148718/*"Finished preparing formats, writing to clipboard"*/,0);
      if (ppuVar9 == (undefined **)0x0) {
        ppuVar9 = &PTR_DAT_141115cb8;
      }
      FUN_140327100(ppuVar9,uVar7);
      return;
    }
    if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
      uVar8 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
    }
    else {
      uVar8 = FUN_14064c440();
    }
    uVar5 = FUN_14079cf20(&DAT_140bab288);
    FUN_1406a9e20(uVar5,0,0);
    FUN_1406aa8a0(uVar5,&PTR_DAT_14119c760/*"formatKey"*/,ppuVar2,2);
    lVar6 = FUN_14079cf20(&DAT_140b06c68);
    *(undefined4 *)(lVar6 + 8) = *(undefined4 *)(ppuVar3 + 1);
    FUN_1406aa8a0(uVar5,&PTR_DAT_1411ad4c8/*"valueLength"*/,lVar6,2);
    FUN_140308320(uVar8,&PTR_DAT_141162980/*"Preparing clipboard format"*/);
    if (ppuVar2 == &PTR_DAT_14114c258/*"HTML Format"*/) {
LAB_140326fe3:
      uVar7 = FUN_1403274e0(ppuVar3);
      if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
        uVar8 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
      }
      else {
        uVar8 = FUN_14064c440();
      }
      FUN_140308320(uVar8,&PTR_DAT_1411628e0/*"Prepared HTML format"*/);
    }
    else if ((ppuVar2 != (undefined **)0x0) && (*(int *)(ppuVar2 + 1) == 0xb)) {
      auVar10._0_4_ =
           -(uint)(*(int *)((longlong)ppuVar2 + 0xc) == 0x540048 &&
                  *(int *)((longlong)ppuVar2 + 0x12) == 0x20004c);
      auVar10._4_4_ =
           -(uint)(*(int *)(ppuVar2 + 2) == 0x4c004d &&
                  *(int *)((longlong)ppuVar2 + 0x16) == 0x6f0046);
      auVar10._8_4_ =
           -(uint)(*(int *)((longlong)ppuVar2 + 0x14) == 0x460020 &&
                  *(int *)((longlong)ppuVar2 + 0x1a) == 0x6d0072);
      auVar10._12_4_ =
           -(uint)(*(int *)(ppuVar2 + 3) == 0x72006f &&
                  *(int *)((longlong)ppuVar2 + 0x1e) == 0x740061);
      if ((ushort)((ushort)(SUB161(auVar10 >> 7,0) & 1) |
                   (ushort)(SUB161(auVar10 >> 0xf,0) & 1) << 1 |
                   (ushort)(SUB161(auVar10 >> 0x17,0) & 1) << 2 |
                   (ushort)(SUB161(auVar10 >> 0x1f,0) & 1) << 3 |
                   (ushort)(SUB161(auVar10 >> 0x27,0) & 1) << 4 |
                   (ushort)(SUB161(auVar10 >> 0x2f,0) & 1) << 5 |
                   (ushort)(SUB161(auVar10 >> 0x37,0) & 1) << 6 |
                   (ushort)(SUB161(auVar10 >> 0x3f,0) & 1) << 7 |
                   (ushort)(SUB161(auVar10 >> 0x47,0) & 1) << 8 |
                   (ushort)(SUB161(auVar10 >> 0x4f,0) & 1) << 9 |
                   (ushort)(SUB161(auVar10 >> 0x57,0) & 1) << 10 |
                   (ushort)(SUB161(auVar10 >> 0x5f,0) & 1) << 0xb |
                   (ushort)((byte)(auVar10._12_4_ >> 7) & 1) << 0xc |
                   (ushort)((byte)(auVar10._12_4_ >> 0xf) & 1) << 0xd |
                   (ushort)((byte)(auVar10._12_4_ >> 0x17) & 1) << 0xe |
                  (ushort)(byte)(auVar10._12_4_ >> 0x1f) << 0xf) == 0xffff) goto LAB_140326fe3;
    }
    if ((ppuVar2 == &PTR_DAT_141173678/*"Text"*/) ||
       (((ppuVar2 != (undefined **)0x0 && (*(int *)(ppuVar2 + 1) == 4)) &&
        (*(longlong *)((longlong)ppuVar2 + 0xc) == 0x74007800650054)))) {
      if (*(longlong *)(*(longlong *)(lVar1 + 8) + 8) == 0) {
        uVar8 = *(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x18);
      }
      else {
        uVar8 = FUN_14064c440();
      }
      FUN_140308320(uVar8,&PTR_DAT_141162920/*"Prepared Text and UnicodeText formats"*/);
      ppuVar9 = ppuVar3;
    }
  } while( true );
}

