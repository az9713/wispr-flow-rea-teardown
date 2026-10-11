
void FUN_140325ec0(longlong param_1,longlong param_2,undefined8 param_3,char param_4,
                  undefined8 param_5)

{
  undefined **ppuVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  longlong lVar10;
  undefined4 uVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong lVar14;
  undefined1 auVar15 [16];
  
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  lVar2 = DAT_1411d71f0;
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar9 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar9 = FUN_14064c440();
  }
  uVar4 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar4,0,0);
  lVar5 = FUN_14079cf20(&DAT_140b06c68);
  *(undefined4 *)(lVar5 + 8) = *(undefined4 *)(param_1 + 8);
  FUN_1406aa8a0(uVar4,&PTR_DAT_1411ab480/*"textLength"*/,lVar5,2);
  FUN_140308320(uVar9,&PTR_DAT_14115dd30/*"Now inside PasteTextInternal, pasting text"*/,uVar4);
  if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
    uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
  }
  else {
    uVar9 = FUN_14064c440();
  }
  FUN_140308320(uVar9,&PTR_DAT_14114b5b8/*"Getting clipboard snapshot"*/,0);
  lVar5 = FUN_14032b1a0();
  if (lVar5 == 0) {
    if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
      uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
    }
    else {
      uVar9 = FUN_14064c440();
    }
    FUN_140308320(uVar9,&PTR_DAT_141165420/*"Received null clipboard snapshot"*/,0);
  }
  else {
    if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
      uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
    }
    else {
      uVar9 = FUN_14064c440();
    }
    FUN_140308320(uVar9,&PTR_DAT_14116fb28/*"Successfully got non null clipboard snapshot"*/,0);
    lVar10 = FUN_14079cf20(&DAT_140b419d0);
    uVar9 = FUN_14079cf20(&DAT_140bab288);
    FUN_1406a9e20(uVar9,0,0);
    FUN_14079d180(lVar10 + 8,uVar9);
    uVar9 = FUN_1406aa1d0();
    lVar6 = FUN_140758b00(&PTR_DAT_140a85628,uVar9);
    for (uVar13 = 0; (int)uVar13 < *(int *)(lVar6 + 8); uVar13 = (ulonglong)((int)uVar13 + 1)) {
      uVar9 = *(undefined8 *)(lVar6 + 0x10 + uVar13 * 8);
      if (PTR_FUN_1411d0560 != (undefined *)0x0) {
        FUN_140773430();
      }
      lVar14 = DAT_1411d7238;
      iVar3 = FUN_1406519c0(*(undefined8 *)(DAT_1411d7238 + 8),uVar9);
      if (iVar3 < 0) {
        iVar3 = FUN_1406519c0(*(undefined8 *)(lVar14 + 0x10),uVar9);
        if (iVar3 < 0) {
          if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
            uVar4 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
          }
          else {
            uVar4 = FUN_14064c440();
          }
          uVar8 = FUN_14079cf20(&DAT_140bab288);
          FUN_1406a9e20(uVar8,0,0);
          FUN_1406aa8a0(uVar8,&PTR_DAT_14119c738/*"format"*/,uVar9,2);
          FUN_140308420(uVar4,&PTR_DAT_14114a198/*"Found unknown clipboard format - not in FormatsToIgnore or FormatsToRestore"*/);
        }
        else {
          plVar7 = (longlong *)FUN_1406aa700(*(undefined8 *)(lVar5 + 8),uVar9);
          if (plVar7 == (longlong *)0x0) {
            lVar14 = 0;
          }
          else {
            lVar14 = *plVar7;
          }
          if (lVar14 != 0) {
            if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
              uVar4 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
            }
            else {
              uVar4 = FUN_14064c440();
            }
            uVar8 = FUN_14079cf20(&DAT_140bab288);
            FUN_1406a9e20(uVar8,0,0);
            FUN_1406aa8a0(uVar8,&PTR_DAT_14119c738/*"format"*/,uVar9,2);
            FUN_140308320(uVar4,&PTR_DAT_141138368/*"Copying clipboard format"*/,uVar8);
            FUN_1406aa8a0(*(undefined8 *)(lVar10 + 8),uVar9,lVar14,1);
            if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
              uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
            }
            else {
              uVar9 = FUN_14064c440();
            }
            FUN_140308320(uVar9,&PTR_DAT_14116fcd0/*"Successfully saved clipboard, now computing data size"*/);
          }
        }
      }
      else {
        if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
          uVar4 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
        }
        else {
          uVar4 = FUN_14064c440();
        }
        uVar8 = FUN_14079cf20(&DAT_140bab288);
        FUN_1406a9e20(uVar8,0,0);
        FUN_1406aa8a0(uVar8,&PTR_DAT_14119c738/*"format"*/,uVar9,2);
        FUN_140308320(uVar4,&PTR_DAT_14116c100/*"Skipping copying clipboard format"*/);
      }
    }
  }
  if (PTR_FUN_1411d04e8 != (undefined *)0x0) {
    FUN_140773380();
  }
  lVar2 = DAT_1411d71f0;
  if (*(longlong *)(*(longlong *)(DAT_1411d71f0 + 8) + 8) == 0) {
    uVar9 = *(undefined8 *)(*(longlong *)(DAT_1411d71f0 + 8) + 0x18);
  }
  else {
    uVar9 = FUN_14064c440();
  }
  FUN_140308320(uVar9,&PTR_DAT_1411487f0/*"Finished saving old clipboard contents"*/,0);
  iVar3 = FUN_14032b050();
  if (iVar3 == 0) {
    uVar11 = 0;
  }
  else {
    lVar5 = FUN_14032b090();
    uVar11 = *(undefined4 *)(lVar5 + 8);
  }
  if (PTR_FUN_1411d0560 != (undefined *)0x0) {
    FUN_140771bf8();
  }
  DAT_1411d0568 = uVar11;
  if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
    uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
  }
  else {
    uVar9 = FUN_14064c440();
  }
  uVar4 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar4,0,0);
  lVar5 = FUN_14079cf20(&DAT_140b06c68);
  *(undefined4 *)(lVar5 + 8) = DAT_1411d0568;
  FUN_1406aa8a0(uVar4,&PTR_DAT_141196df0/*"clipboardLengthBeforeOverwrite"*/,lVar5,2);
  FUN_140308320(uVar9,&PTR_DAT_141191748/*"[paste board debug] 1/5 Clipboard text length before overwrite"*/,uVar4);
  if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
    uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
  }
  else {
    uVar9 = FUN_14064c440();
  }
  FUN_140308320(uVar9,&PTR_DAT_141134bf0/*"Clearing clipboard"*/,0);
  FUN_14032b010();
  if ((param_2 == 0) || (*(int *)(param_2 + 8) == 0)) {
    uVar9 = FUN_14079cf20(&DAT_140bac7d0);
    FUN_1406a9e20(uVar9,0,0);
    FUN_1406aa8a0(uVar9,&PTR_DAT_141173678/*"Text"*/,param_1,1);
    FUN_140326e60(uVar9);
  }
  else {
    uVar9 = FUN_14079cf20(&DAT_140bac7d0);
    FUN_1406a9e20(uVar9,0,0);
    FUN_1406aa8a0(uVar9,&PTR_DAT_14114c258/*"HTML Format"*/,param_2,1);
    FUN_1406aa8a0(uVar9,&PTR_DAT_141173678/*"Text"*/,param_1,1);
    FUN_140326e60(uVar9);
  }
  if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
    uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
  }
  else {
    uVar9 = FUN_14064c440();
  }
  FUN_140308320(uVar9,&PTR_DAT_1411485b0/*"Finished copying clipboard contents"*/,0);
  iVar3 = FUN_14032b050();
  if (iVar3 == 0) {
    uVar11 = 0;
  }
  else {
    lVar5 = FUN_14032b090();
    uVar11 = *(undefined4 *)(lVar5 + 8);
  }
  if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
    uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
  }
  else {
    uVar9 = FUN_14064c440();
  }
  uVar4 = FUN_14079cf20(&DAT_140bab288);
  FUN_1406a9e20(uVar4,0,0);
  lVar5 = FUN_14079cf20(&DAT_140b06c68);
  *(undefined4 *)(lVar5 + 8) = uVar11;
  FUN_1406aa8a0(uVar4,&PTR_DAT_141196c48/*"clipboardLenAfterOverwrite"*/,lVar5,2);
  FUN_140308320(uVar9,&PTR_DAT_1411917e0/*"[paste board debug] 2/5 Clipboard text length after overwrite"*/,uVar4);
  if (param_4 == '\0') {
    if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
      uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
    }
    else {
      uVar9 = FUN_14064c440();
    }
    FUN_140308320(uVar9,&PTR_DAT_1411664a8/*"Regular case of paste"*/,0);
    FUN_1403259d0(param_1,param_2,param_3,param_5);
  }
  else {
    lVar5 = FUN_1403257e0(param_1);
    if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
      uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
    }
    else {
      uVar9 = FUN_14064c440();
    }
    uVar4 = FUN_14079cf20(&DAT_140bab288);
    FUN_1406a9e20(uVar4,0,0);
    lVar10 = FUN_14079cf20(&DAT_140b06c68);
    *(undefined4 *)(lVar10 + 8) = *(undefined4 *)(lVar5 + 0x10);
    FUN_1406aa8a0(uVar4,&PTR_DAT_1411a7d98/*"sectionCount"*/,lVar10,2);
    FUN_140308320(uVar9,&PTR_DAT_14116cf48/*"Special case of paste with delimiters"*/,uVar4);
    uVar13 = 0;
    while( true ) {
      uVar12 = (uint)uVar13;
      if ((int)*(uint *)(lVar5 + 0x10) <= (int)uVar12) break;
      if (*(uint *)(lVar5 + 0x10) <= uVar12) {
                    /* WARNING: Subroutine does not return */
        FUN_140149de0();
      }
      if (*(uint *)(*(longlong *)(lVar5 + 8) + 8) <= uVar12) {
                    /* WARNING: Subroutine does not return */
        FUN_1401d08c0();
      }
      ppuVar1 = *(undefined ***)(*(longlong *)(lVar5 + 8) + 0x10 + uVar13 * 8);
      iVar3 = FUN_1401220a0(ppuVar1,&PTR_DAT_1411b00c0/*"{{"*/);
      if ((iVar3 == 0) || (iVar3 = FUN_1401214b0(ppuVar1,&PTR_DAT_1411b02b0/*"}}"*/), iVar3 == 0)) {
        if (*(int *)(ppuVar1 + 1) != 0) {
          FUN_1403259d0(ppuVar1,0,param_3,param_5);
        }
LAB_14032667c:
        if ((int)uVar12 < *(int *)(lVar5 + 0x10) + -1) {
          FUN_14016a3e0(0x32);
        }
      }
      else {
        if ((ppuVar1 == &PTR_DAT_1411b01d8/*"{{TAB}}"*/) ||
           ((*(int *)(ppuVar1 + 1) == 7 &&
            (*(longlong *)((longlong)ppuVar1 + 0xc) == 0x410054007b007b &&
             *(longlong *)((longlong)ppuVar1 + 0x12) == 0x7d007d00420041)))) {
          FUN_14016a3e0(0x96);
          FUN_140325720();
          goto LAB_14032667c;
        }
        if (ppuVar1 != &PTR_DAT_1411b01b0/*"{{BREAK}}"*/) {
          if (*(int *)(ppuVar1 + 1) == 9) {
            auVar15._0_4_ =
                 -(uint)(*(int *)((longlong)ppuVar1 + 0xc) == 0x7b007b &&
                        *(int *)((longlong)ppuVar1 + 0xe) == 0x42007b);
            auVar15._4_4_ =
                 -(uint)(*(int *)(ppuVar1 + 2) == 0x520042 &&
                        *(int *)((longlong)ppuVar1 + 0x12) == 0x450052);
            auVar15._8_4_ =
                 -(uint)(*(int *)((longlong)ppuVar1 + 0x14) == 0x410045 &&
                        *(int *)((longlong)ppuVar1 + 0x16) == 0x4b0041);
            auVar15._12_4_ =
                 -(uint)(*(int *)(ppuVar1 + 3) == 0x7d004b &&
                        *(int *)((longlong)ppuVar1 + 0x1a) == 0x7d007d);
            if ((ushort)((ushort)(SUB161(auVar15 >> 7,0) & 1) |
                         (ushort)(SUB161(auVar15 >> 0xf,0) & 1) << 1 |
                         (ushort)(SUB161(auVar15 >> 0x17,0) & 1) << 2 |
                         (ushort)(SUB161(auVar15 >> 0x1f,0) & 1) << 3 |
                         (ushort)(SUB161(auVar15 >> 0x27,0) & 1) << 4 |
                         (ushort)(SUB161(auVar15 >> 0x2f,0) & 1) << 5 |
                         (ushort)(SUB161(auVar15 >> 0x37,0) & 1) << 6 |
                         (ushort)(SUB161(auVar15 >> 0x3f,0) & 1) << 7 |
                         (ushort)(SUB161(auVar15 >> 0x47,0) & 1) << 8 |
                         (ushort)(SUB161(auVar15 >> 0x4f,0) & 1) << 9 |
                         (ushort)(SUB161(auVar15 >> 0x57,0) & 1) << 10 |
                         (ushort)(SUB161(auVar15 >> 0x5f,0) & 1) << 0xb |
                         (ushort)((byte)(auVar15._12_4_ >> 7) & 1) << 0xc |
                         (ushort)((byte)(auVar15._12_4_ >> 0xf) & 1) << 0xd |
                         (ushort)((byte)(auVar15._12_4_ >> 0x17) & 1) << 0xe |
                        (ushort)(byte)(auVar15._12_4_ >> 0x1f) << 0xf) == 0xffff)
            goto LAB_14032668f;
          }
          goto LAB_14032667c;
        }
      }
LAB_14032668f:
      uVar13 = (ulonglong)(uVar12 + 1);
    }
  }
  FUN_14016a3e0(500);
  FUN_140326b76();
  if (*(longlong *)(*(longlong *)(lVar2 + 8) + 8) == 0) {
    uVar9 = *(undefined8 *)(*(longlong *)(lVar2 + 8) + 0x18);
  }
  else {
    uVar9 = FUN_14064c440();
  }
  FUN_140308320(uVar9,&PTR_DAT_141148648/*"Finished paste text internal"*/,0);
  return;
}

