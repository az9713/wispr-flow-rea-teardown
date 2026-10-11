
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_140322420(longlong param_1,int param_2,undefined1 *param_3)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  longlong lVar12;
  undefined8 uVar13;
  longlong lVar14;
  uint uVar15;
  ulonglong uVar16;
  uint uVar17;
  longlong *plVar18;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 uStack_248;
  uint local_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined8 local_230;
  undefined8 local_228;
  undefined8 uStack_220;
  uint local_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined8 local_208;
  undefined8 local_200;
  undefined8 uStack_1f8;
  uint local_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  uint local_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  uint local_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  uint local_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  longlong local_168;
  undefined8 local_160;
  undefined8 uStack_158;
  uint local_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 uStack_130;
  uint local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  uint local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  uint local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined8 local_c8;
  undefined8 local_b8;
  undefined8 uStack_b0;
  uint local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  uint local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  uint local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  longlong local_48;
  
  local_278 = 0;
  uStack_270 = 0;
  local_268 = 0;
  uStack_260 = 0;
  lVar12 = -0x210;
  do {
    *(undefined8 *)((longlong)&local_48 + lVar12) = 0;
    *(undefined8 *)(&stack0xffffffffffffffc0 + lVar12) = 0;
    *(undefined8 *)(&stack0xffffffffffffffc8 + lVar12) = 0;
    *(undefined8 *)(&stack0xffffffffffffffd0 + lVar12) = 0;
    *(undefined8 *)(&stack0xffffffffffffffd8 + lVar12) = 0;
    *(undefined8 *)(&stack0xffffffffffffffe0 + lVar12) = 0;
    lVar12 = lVar12 + 0x30;
  } while (lVar12 != 0);
  *param_3 = 0;
  local_48 = lVar12;
  if ((param_1 == 0) || (uVar4 = *(uint *)(param_1 + 8), uVar4 == 0)) {
    FUN_140321cd0(&PTR_DAT_14116a048/*"SendMultipleKeyEvents called with null or empty array"*/);
    return 0;
  }
  uVar11 = FUN_140738c40();
  FUN_1401a6cd0(&local_188,0x38,2);
  local_68 = local_188;
  uStack_60 = uStack_180;
  local_58 = local_178;
  uStack_54 = uStack_174;
  uStack_50 = uStack_170;
  uStack_4c = uStack_16c;
  local_48 = local_168;
  lVar12 = local_48;
  local_48._0_4_ = (uint)local_168;
  uVar13 = local_140;
  uVar6 = local_118;
  uVar7 = local_f0;
  uVar8 = local_c8;
  uVar9 = local_98;
  uVar10 = local_70;
  if (local_178 <= (uint)local_48) {
    local_48 = lVar12;
    if ((uint)local_48 - local_178 < 0x24) {
      FUN_1401a7120(&local_68,&PTR_DAT_14116a1b0/*"Sending atomic key combination with "*/);
    }
    else {
      FUN_1401485c0(CONCAT44(uStack_16c,uStack_170) + (ulonglong)local_178 * 2,
                    u_Sending_atomic_key_combination_w_14116a1bc,0x48);
      local_58 = local_58 + 0x24;
    }
    FUN_1406fc640(&local_68,uVar4);
    uVar13 = local_140;
    uVar6 = local_118;
    uVar7 = local_f0;
    uVar8 = local_c8;
    uVar9 = local_98;
    uVar10 = local_70;
    lVar12 = local_48;
    if (local_58 <= (uint)local_48) {
      puVar1 = (undefined8 *)(CONCAT44(uStack_4c,uStack_50) + (ulonglong)local_58 * 2);
      if ((uint)local_48 - local_58 < 0x12) {
        FUN_1401a7120(&local_68,&PTR_DAT_141117b28/*" keys, wait time: "*/);
      }
      else {
        *puVar1 = 0x790065006b0020;
        puVar1[1] = 0x770020002c0073;
        *(undefined4 *)(puVar1 + 2) = 0x690061;
        *(undefined4 *)((longlong)puVar1 + 0x14) = 0x200074;
        *(undefined4 *)(puVar1 + 3) = 0x690074;
        *(undefined4 *)((longlong)puVar1 + 0x1c) = 0x65006d;
        *(undefined4 *)(puVar1 + 4) = 0x20003a;
        local_58 = local_58 + 0x12;
      }
      FUN_1406fc640(&local_68,param_2);
      uVar13 = local_140;
      uVar6 = local_118;
      uVar7 = local_f0;
      uVar8 = local_c8;
      uVar9 = local_98;
      uVar10 = local_70;
      lVar12 = local_48;
      if (local_58 <= (uint)local_48) {
        if ((uint)local_48 - local_58 < 2) {
          FUN_1401a7120(&local_68,&PTR_DAT_1411a28b0/*"ms"*/);
        }
        else {
          *(undefined4 *)(CONCAT44(uStack_4c,uStack_50) + (ulonglong)local_58 * 2) = 0x73006d;
          local_58 = local_58 + 2;
        }
        uVar13 = FUN_1401a6e70(&local_68);
        FUN_140321c60(uVar13);
        lVar12 = FUN_14079d040(&DAT_140ed0d60,uVar4);
        uVar16 = 0;
        if (0 < (int)uVar4) {
          do {
            if (*(uint *)(lVar12 + 8) <= (uint)uVar16) goto LAB_140322ffa;
            puVar2 = (undefined4 *)(lVar12 + 0x10 + uVar16 * 0x28);
            *puVar2 = 1;
            sVar3 = *(short *)(param_1 + 0x10 + uVar16 * 2);
            *(short *)(puVar2 + 2) = sVar3;
            *(undefined2 *)((longlong)puVar2 + 10) = 0;
            puVar2[3] = 0;
            if (sVar3 == 0x2d) {
              puVar2[3] = puVar2[3] | 1;
            }
            puVar2[4] = 0;
            *(undefined8 *)(puVar2 + 6) = 0;
            uVar15 = (uint)uVar16 + 1;
            uVar16 = (ulonglong)uVar15;
          } while ((int)uVar15 < (int)uVar4);
        }
        uVar15 = FUN_140321de0(uVar4,lVar12,uVar11);
        FUN_1401a6cd0(&local_1b0,0x29,2);
        local_90 = local_1b0;
        uStack_88 = uStack_1a8;
        local_80 = local_1a0;
        uStack_7c = uStack_19c;
        uStack_78 = uStack_198;
        uStack_74 = uStack_194;
        local_70 = local_190;
        uVar10 = local_70;
        local_70._0_4_ = (uint)local_190;
        uVar13 = local_140;
        uVar6 = local_118;
        uVar7 = local_f0;
        uVar8 = local_c8;
        uVar9 = local_98;
        lVar12 = local_48;
        if (local_1a0 <= (uint)local_70) {
          puVar1 = (undefined8 *)(CONCAT44(uStack_194,uStack_198) + (ulonglong)local_1a0 * 2);
          local_70 = uVar10;
          if ((uint)local_70 - local_1a0 < 0x1f) {
            FUN_1401a7120(&local_90,&PTR_DAT_141169d08/*"SendInput (key down) returned: "*/);
          }
          else {
            *puVar1 = 0x64006e00650053;
            puVar1[1] = 0x750070006e0049;
            puVar1[2] = 0x6b002800200074;
            puVar1[3] = 0x64002000790065;
            *(undefined4 *)(puVar1 + 4) = 0x77006f;
            *(undefined4 *)((longlong)puVar1 + 0x24) = 0x29006e;
            *(undefined4 *)(puVar1 + 5) = 0x720020;
            *(undefined4 *)((longlong)puVar1 + 0x2c) = 0x740065;
            puVar1[6] = 0x65006e00720075;
            *(undefined4 *)(puVar1 + 7) = 0x3a0064;
            *(undefined2 *)((longlong)puVar1 + 0x3c) = 0x20;
            local_80 = local_1a0 + 0x1f;
          }
          FUN_14070bae0(&local_90,uVar15);
          uVar13 = local_140;
          uVar6 = local_118;
          uVar7 = local_f0;
          uVar8 = local_c8;
          uVar9 = local_98;
          uVar10 = local_70;
          lVar12 = local_48;
          if (local_80 <= (uint)local_70) {
            puVar1 = (undefined8 *)(CONCAT44(uStack_74,uStack_78) + (ulonglong)local_80 * 2);
            if ((uint)local_70 - local_80 < 5) {
              FUN_1401a7120(&local_90,&PTR_DAT_141117900/*" for "*/);
            }
            else {
              *puVar1 = 0x72006f00660020;
              *(undefined2 *)(puVar1 + 1) = 0x20;
              local_80 = local_80 + 5;
            }
            FUN_1406fc640(&local_90,uVar4);
            uVar13 = local_140;
            uVar6 = local_118;
            uVar7 = local_f0;
            uVar8 = local_c8;
            uVar9 = local_98;
            uVar10 = local_70;
            lVar12 = local_48;
            if (local_80 <= (uint)local_70) {
              puVar1 = (undefined8 *)(CONCAT44(uStack_74,uStack_78) + (ulonglong)local_80 * 2);
              if ((uint)local_70 - local_80 < 5) {
                FUN_1401a7120(&local_90,&PTR_DAT_141117ac8/*" keys"*/);
              }
              else {
                *puVar1 = 0x790065006b0020;
                *(undefined2 *)(puVar1 + 1) = 0x73;
                local_80 = local_80 + 5;
              }
              uVar13 = FUN_1401a6e70(&local_90);
              FUN_140321c60(uVar13);
              if (uVar15 == 0) {
                plVar18 = (longlong *)
                          (*(longlong *)
                            ((longlong)ThreadLocalStoragePointer + (ulonglong)__tls_index * 8) +
                          0x10);
                lVar12 = *plVar18;
                if (lVar12 == 0) {
                  lVar12 = FUN_1401ccdc0(plVar18);
                }
                uVar11 = *(undefined4 *)(lVar12 + 0xe8);
                FUN_1401a6cd0(&local_278,0x2d,1);
                local_b8 = local_278;
                uStack_b0 = uStack_270;
                local_a8 = (uint)local_268;
                uStack_a4 = local_268._4_4_;
                uStack_a0 = (undefined4)uStack_260;
                uStack_9c = uStack_260._4_4_;
                local_98 = local_258;
                uVar9 = local_98;
                local_98._0_4_ = (uint)local_258;
                uVar13 = local_140;
                uVar6 = local_118;
                uVar7 = local_f0;
                uVar8 = local_c8;
                uVar10 = local_70;
                lVar12 = local_48;
                if ((uint)local_268 <= (uint)local_98) {
                  local_98 = uVar9;
                  if ((uint)local_98 - (uint)local_268 < 0x2d) {
                    FUN_1401a7120(&local_b8,&PTR_DAT_141169c98/*"SendInput (key down) failed with error code: "*/);
                  }
                  else {
                    FUN_1401485c0(uStack_260 + (local_268 & 0xffffffff) * 2,
                                  u_SendInput__key_down__failed_with_141169ca4,0x5a);
                    local_a8 = local_a8 + 0x2d;
                  }
                  FUN_1406fc640(&local_b8,uVar11);
                  uVar13 = FUN_1401a6e70(&local_b8);
                  FUN_140321cd0(uVar13);
                  return 0;
                }
              }
              else {
                *param_3 = uVar4 == uVar15;
                if (0 < param_2) {
                  FUN_14016a3e0(param_2);
                }
                lVar14 = FUN_14079d040(&DAT_140ed0d60,uVar4);
                uVar16 = 0;
                if (0 < (int)uVar4) {
                  do {
                    uVar15 = (uint)uVar16;
                    uVar17 = (uVar4 - 1) - uVar15;
                    if (*(uint *)(lVar14 + 8) <= uVar15) {
LAB_140322ffa:
                    /* WARNING: Subroutine does not return */
                      FUN_1401d08c0();
                    }
                    puVar2 = (undefined4 *)(lVar14 + 0x10 + uVar16 * 0x28);
                    *puVar2 = 1;
                    if (uVar4 <= uVar17) goto LAB_140322ffa;
                    sVar3 = *(short *)(param_1 + 0x10 + (ulonglong)uVar17 * 2);
                    *(short *)(puVar2 + 2) = sVar3;
                    *(undefined2 *)((longlong)puVar2 + 10) = 0;
                    puVar2[3] = 2;
                    if (sVar3 == 0x2d) {
                      puVar2[3] = puVar2[3] | 1;
                    }
                    puVar2[4] = 0;
                    *(undefined8 *)(puVar2 + 6) = 0;
                    uVar16 = (ulonglong)(uVar15 + 1);
                  } while ((int)(uVar15 + 1) < (int)uVar4);
                }
                uVar15 = FUN_140321de0(uVar4,lVar14,uVar11);
                FUN_1401a6cd0(&local_1d8,0x27,2);
                local_e8 = local_1d8;
                uStack_e0 = uStack_1d0;
                local_d8 = local_1c8;
                uStack_d4 = uStack_1c4;
                uStack_d0 = uStack_1c0;
                uStack_cc = uStack_1bc;
                local_c8 = local_1b8;
                uVar8 = local_c8;
                local_c8._0_4_ = (uint)local_1b8;
                uVar13 = local_140;
                uVar6 = local_118;
                uVar7 = local_f0;
                uVar9 = local_98;
                uVar10 = local_70;
                lVar12 = local_48;
                if (local_1c8 <= (uint)local_c8) {
                  puVar1 = (undefined8 *)
                           (CONCAT44(uStack_1bc,uStack_1c0) + (ulonglong)local_1c8 * 2);
                  local_c8 = uVar8;
                  if ((uint)local_c8 - local_1c8 < 0x1d) {
                    FUN_1401a7120(&local_e8,&PTR_DAT_141169e90/*"SendInput (key up) returned: "*/);
                  }
                  else {
                    *puVar1 = 0x64006e00650053;
                    puVar1[1] = 0x750070006e0049;
                    puVar1[2] = 0x6b002800200074;
                    puVar1[3] = 0x75002000790065;
                    *(undefined4 *)(puVar1 + 4) = 0x290070;
                    *(undefined4 *)((longlong)puVar1 + 0x24) = 0x720020;
                    *(undefined4 *)(puVar1 + 5) = 0x740065;
                    *(undefined4 *)((longlong)puVar1 + 0x2c) = 0x720075;
                    puVar1[6] = 0x3a00640065006e;
                    *(undefined2 *)(puVar1 + 7) = 0x20;
                    local_d8 = local_1c8 + 0x1d;
                  }
                  FUN_14070bae0(&local_e8,uVar15);
                  uVar13 = local_140;
                  uVar6 = local_118;
                  uVar7 = local_f0;
                  uVar8 = local_c8;
                  uVar9 = local_98;
                  uVar10 = local_70;
                  lVar12 = local_48;
                  if (local_d8 <= (uint)local_c8) {
                    puVar1 = (undefined8 *)(CONCAT44(uStack_cc,uStack_d0) + (ulonglong)local_d8 * 2)
                    ;
                    if ((uint)local_c8 - local_d8 < 5) {
                      FUN_1401a7120(&local_e8,&PTR_DAT_141117900/*" for "*/);
                    }
                    else {
                      *puVar1 = 0x72006f00660020;
                      *(undefined2 *)(puVar1 + 1) = 0x20;
                      local_d8 = local_d8 + 5;
                    }
                    FUN_1406fc640(&local_e8,uVar4);
                    uVar13 = local_140;
                    uVar6 = local_118;
                    uVar7 = local_f0;
                    uVar8 = local_c8;
                    uVar9 = local_98;
                    uVar10 = local_70;
                    lVar12 = local_48;
                    if (local_d8 <= (uint)local_c8) {
                      puVar1 = (undefined8 *)
                               (CONCAT44(uStack_cc,uStack_d0) + (ulonglong)local_d8 * 2);
                      if ((uint)local_c8 - local_d8 < 5) {
                        FUN_1401a7120(&local_e8,&PTR_DAT_141117ac8/*" keys"*/);
                      }
                      else {
                        *puVar1 = 0x790065006b0020;
                        *(undefined2 *)(puVar1 + 1) = 0x73;
                        local_d8 = local_d8 + 5;
                      }
                      uVar13 = FUN_1401a6e70(&local_e8);
                      FUN_140321c60(uVar13);
                      if (uVar15 == 0) {
                        plVar18 = (longlong *)
                                  (*(longlong *)
                                    ((longlong)ThreadLocalStoragePointer +
                                    (ulonglong)__tls_index * 8) + 0x10);
                        lVar12 = *plVar18;
                        if (lVar12 == 0) {
                          lVar12 = FUN_1401ccdc0(plVar18);
                        }
                        uVar5 = *(undefined4 *)(lVar12 + 0xe8);
                        FUN_1401a6cd0(&local_250,0x2b,1);
                        local_110 = local_250;
                        uStack_108 = uStack_248;
                        local_100 = local_240;
                        uStack_fc = uStack_23c;
                        uStack_f8 = uStack_238;
                        uStack_f4 = uStack_234;
                        local_f0 = local_230;
                        uVar7 = local_f0;
                        local_f0._0_4_ = (uint)local_230;
                        uVar13 = local_140;
                        uVar6 = local_118;
                        uVar8 = local_c8;
                        uVar9 = local_98;
                        uVar10 = local_70;
                        lVar12 = local_48;
                        if ((uint)local_f0 < local_240) goto LAB_140322ff4;
                        local_f0 = uVar7;
                        if ((uint)local_f0 - local_240 < 0x2b) {
                          FUN_1401a7120(&local_110,&PTR_DAT_141169d60/*"SendInput (key up) failed with error code: "*/);
                        }
                        else {
                          FUN_1401485c0(CONCAT44(uStack_234,uStack_238) + (ulonglong)local_240 * 2,
                                        u_SendInput__key_up__failed_with_e_141169d6c,0x56);
                          local_100 = local_100 + 0x2b;
                        }
                        FUN_1406fc640(&local_110,uVar5);
                        uVar13 = FUN_1401a6e70(&local_110);
                        FUN_140321cd0(uVar13);
                      }
                      if (uVar4 == uVar15) {
                        FUN_1401a6cd0(&local_200,0x33,1);
                        local_160 = local_200;
                        uStack_158 = uStack_1f8;
                        local_150 = local_1f0;
                        uStack_14c = uStack_1ec;
                        uStack_148 = uStack_1e8;
                        uStack_144 = uStack_1e4;
                        local_140 = local_1e0;
                        uVar13 = local_140;
                        local_140._0_4_ = (uint)local_1e0;
                        uVar6 = local_118;
                        uVar7 = local_f0;
                        uVar8 = local_c8;
                        uVar9 = local_98;
                        uVar10 = local_70;
                        lVar12 = local_48;
                        if (local_1f0 <= (uint)local_140) {
                          local_140 = uVar13;
                          if ((uint)local_140 - local_1f0 < 0x2e) {
                            FUN_1401a7120(&local_160,&PTR_DAT_14116fdb8/*"Successfully sent atomic key combination with "*/);
                          }
                          else {
                            FUN_1401485c0(CONCAT44(uStack_1e4,uStack_1e8) + (ulonglong)local_1f0 * 2
                                          ,u_Successfully_sent_atomic_key_com_14116fdc4,0x5c);
                            local_150 = local_150 + 0x2e;
                          }
                          FUN_1406fc640(&local_160,uVar4);
                          uVar13 = local_140;
                          uVar6 = local_118;
                          uVar7 = local_f0;
                          uVar8 = local_c8;
                          uVar9 = local_98;
                          uVar10 = local_70;
                          lVar12 = local_48;
                          if (local_150 <= (uint)local_140) {
                            puVar1 = (undefined8 *)
                                     (CONCAT44(uStack_144,uStack_148) + (ulonglong)local_150 * 2);
                            if ((uint)local_140 - local_150 < 5) {
                              FUN_1401a7120(&local_160,&PTR_DAT_141117ac8/*" keys"*/);
                            }
                            else {
                              *puVar1 = 0x790065006b0020;
                              *(undefined2 *)(puVar1 + 1) = 0x73;
                              local_150 = local_150 + 5;
                            }
                            uVar13 = FUN_1401a6e70(&local_160);
                            FUN_140321c60(uVar13);
                            return 1;
                          }
                        }
                      }
                      else {
                        uVar15 = FUN_140321de0(uVar4,lVar14,uVar11);
                        if (uVar4 == uVar15) {
                          FUN_140321c60(&PTR_DAT_141169e30/*"SendInput (key up) retry succeeded"*/);
                          return 0;
                        }
                        plVar18 = (longlong *)
                                  (*(longlong *)
                                    ((longlong)ThreadLocalStoragePointer +
                                    (ulonglong)__tls_index * 8) + 0x10);
                        lVar12 = *plVar18;
                        if (lVar12 == 0) {
                          lVar12 = FUN_1401ccdc0(plVar18);
                        }
                        uVar11 = *(undefined4 *)(lVar12 + 0xe8);
                        FUN_1401a6cd0(&local_228,0x3b,3);
                        local_138 = local_228;
                        uStack_130 = uStack_220;
                        local_128 = local_218;
                        uStack_124 = uStack_214;
                        uStack_120 = uStack_210;
                        uStack_11c = uStack_20c;
                        local_118 = local_208;
                        uVar6 = local_118;
                        local_118._0_4_ = (uint)local_208;
                        uVar13 = local_140;
                        uVar7 = local_f0;
                        uVar8 = local_c8;
                        uVar9 = local_98;
                        uVar10 = local_70;
                        lVar12 = local_48;
                        if (local_218 <= (uint)local_118) {
                          local_118 = uVar6;
                          if ((uint)local_118 - local_218 < 0x23) {
                            FUN_1401a7120(&local_138,&PTR_DAT_141169dd0/*"SendInput (key up) retry returned: "*/);
                          }
                          else {
                            FUN_1401485c0(CONCAT44(uStack_20c,uStack_210) + (ulonglong)local_218 * 2
                                          ,u_SendInput__key_up__retry_returne_141169ddc,0x46);
                            local_128 = local_128 + 0x23;
                          }
                          FUN_14070bae0(&local_138,uVar15);
                          uVar13 = local_140;
                          uVar6 = local_118;
                          uVar7 = local_f0;
                          uVar8 = local_c8;
                          uVar9 = local_98;
                          uVar10 = local_70;
                          lVar12 = local_48;
                          if (local_128 <= (uint)local_118) {
                            puVar1 = (undefined8 *)
                                     (CONCAT44(uStack_11c,uStack_120) + (ulonglong)local_128 * 2);
                            if ((uint)local_118 - local_128 < 5) {
                              FUN_1401a7120(&local_138,&PTR_DAT_141117900/*" for "*/);
                            }
                            else {
                              *puVar1 = 0x72006f00660020;
                              *(undefined2 *)(puVar1 + 1) = 0x20;
                              local_128 = local_128 + 5;
                            }
                            FUN_1406fc640(&local_138,uVar4);
                            uVar13 = local_140;
                            uVar6 = local_118;
                            uVar7 = local_f0;
                            uVar8 = local_c8;
                            uVar9 = local_98;
                            uVar10 = local_70;
                            lVar12 = local_48;
                            if (local_128 <= (uint)local_118) {
                              puVar1 = (undefined8 *)
                                       (CONCAT44(uStack_11c,uStack_120) + (ulonglong)local_128 * 2);
                              if ((uint)local_118 - local_128 < 0x13) {
                                FUN_1401a7120(&local_138,&PTR_DAT_141117ae8/*" keys, error code: "*/);
                              }
                              else {
                                *puVar1 = 0x790065006b0020;
                                puVar1[1] = 0x650020002c0073;
                                *(undefined4 *)(puVar1 + 2) = 0x720072;
                                *(undefined4 *)((longlong)puVar1 + 0x14) = 0x72006f;
                                *(undefined4 *)(puVar1 + 3) = 0x630020;
                                *(undefined4 *)((longlong)puVar1 + 0x1c) = 0x64006f;
                                *(undefined4 *)(puVar1 + 4) = 0x3a0065;
                                *(undefined2 *)((longlong)puVar1 + 0x24) = 0x20;
                                local_128 = local_128 + 0x13;
                              }
                              FUN_1406fc640(&local_138,uVar11);
                              uVar13 = FUN_1401a6e70(&local_138);
                              FUN_140321cd0(uVar13);
                              return 0;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_140322ff4:
  local_48 = lVar12;
  local_70 = uVar10;
  local_98 = uVar9;
  local_c8 = uVar8;
  local_f0 = uVar7;
  local_118 = uVar6;
  local_140 = uVar13;
                    /* WARNING: Subroutine does not return */
  FUN_140149d20();
}

