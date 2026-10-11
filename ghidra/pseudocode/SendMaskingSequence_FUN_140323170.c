
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_140323170(undefined2 param_1,undefined2 param_2,undefined1 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong *plVar9;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  uint local_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  uint local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  uint local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  uint local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined8 local_c0;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 uStack_a8;
  uint local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  uint local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  uint local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined8 local_40;
  
  local_180 = 0;
  uStack_178 = 0;
  uStack_170 = 0;
  uStack_168 = 0;
  uStack_160 = 0;
  lVar7 = -0x120;
  do {
    *(undefined8 *)(&stack0xffffffffffffffc8 + lVar7) = 0;
    *(undefined8 *)(&stack0xffffffffffffffd0 + lVar7) = 0;
    *(undefined8 *)(&stack0xffffffffffffffd8 + lVar7) = 0;
    *(undefined8 *)(&stack0xffffffffffffffe0 + lVar7) = 0;
    *(undefined8 *)(&stack0xffffffffffffffe8 + lVar7) = 0;
    *(undefined8 *)(&stack0xfffffffffffffff0 + lVar7) = 0;
    lVar7 = lVar7 + 0x30;
  } while (lVar7 != 0);
  uVar5 = FUN_140738c40();
  FUN_1401a6cd0(&local_108,0x3a,2);
  local_60 = local_108;
  uStack_58 = uStack_100;
  local_50 = local_f8;
  uStack_4c = uStack_f4;
  uStack_48 = uStack_f0;
  uStack_44 = uStack_ec;
  local_40 = local_e8;
  uVar4 = local_40;
  local_40._0_4_ = (uint)local_e8;
  uVar8 = local_c0;
  uVar2 = local_90;
  uVar3 = local_68;
  if (local_f8 <= (uint)local_40) {
    local_40 = uVar4;
    if ((uint)local_40 - local_f8 < 0x28) {
      FUN_1401a7120(&local_60,&PTR_DAT_14116a210/*"Sending atomic masking sequence for key "*/);
    }
    else {
      FUN_1401485c0(CONCAT44(uStack_ec,uStack_f0) + (ulonglong)local_f8 * 2,
                    u_Sending_atomic_masking_sequence_f_14116a21c,0x50);
      local_50 = local_50 + 0x28;
    }
    FUN_140709600(&local_60,param_1);
    uVar8 = local_c0;
    uVar2 = local_90;
    uVar3 = local_68;
    uVar4 = local_40;
    if (local_50 <= (uint)local_40) {
      puVar1 = (undefined8 *)(CONCAT44(uStack_44,uStack_48) + (ulonglong)local_50 * 2);
      if ((uint)local_40 - local_50 < 0x12) {
        FUN_1401a7120(&local_60,&PTR_DAT_141117db0/*" with masking key "*/);
      }
      else {
        *puVar1 = 0x74006900770020;
        puVar1[1] = 0x61006d00200068;
        *(undefined4 *)(puVar1 + 2) = 0x6b0073;
        *(undefined4 *)((longlong)puVar1 + 0x14) = 0x6e0069;
        *(undefined4 *)(puVar1 + 3) = 0x200067;
        *(undefined4 *)((longlong)puVar1 + 0x1c) = 0x65006b;
        *(undefined4 *)(puVar1 + 4) = 0x200079;
        local_50 = local_50 + 0x12;
      }
      FUN_140709600(&local_60,param_2);
      uVar8 = FUN_1401a6e70(&local_60);
      FUN_140321c60(uVar8);
      lVar7 = FUN_1403230a0(param_1,param_2,param_3,param_4);
      iVar6 = FUN_140321de0(*(undefined4 *)(lVar7 + 8),lVar7,uVar5);
      FUN_1401a6cd0(&local_130,0x27,1);
      local_88 = local_130;
      uStack_80 = uStack_128;
      local_78 = local_120;
      uStack_74 = uStack_11c;
      uStack_70 = uStack_118;
      uStack_6c = uStack_114;
      local_68 = local_110;
      uVar3 = local_68;
      local_68._0_4_ = (uint)local_110;
      uVar8 = local_c0;
      uVar2 = local_90;
      uVar4 = local_40;
      if (local_120 <= (uint)local_68) {
        local_68 = uVar3;
        if ((uint)local_68 - local_120 < 0x27) {
          FUN_1401a7120(&local_88,&PTR_DAT_141169f60/*"SendInput (masking sequence) returned: "*/);
        }
        else {
          FUN_1401485c0(CONCAT44(uStack_114,uStack_118) + (ulonglong)local_120 * 2,
                        u_SendInput__masking_sequence__ret_141169f6c,0x4e);
          local_78 = local_78 + 0x27;
        }
        FUN_14070bae0(&local_88,iVar6);
        uVar8 = FUN_1401a6e70(&local_88);
        FUN_140321c60(uVar8);
        if (*(int *)(lVar7 + 8) == iVar6) {
          FUN_1401a6cd0(&local_158,0x32,1);
          local_e0 = local_158;
          uStack_d8 = uStack_150;
          local_d0 = local_148;
          uStack_cc = uStack_144;
          uStack_c8 = uStack_140;
          uStack_c4 = uStack_13c;
          local_c0 = local_138;
          uVar8 = local_c0;
          local_c0._0_4_ = (uint)local_138;
          uVar2 = local_90;
          uVar3 = local_68;
          uVar4 = local_40;
          if ((uint)local_c0 < local_148) goto LAB_1403235a9;
          local_c0 = uVar8;
          if ((uint)local_c0 - local_148 < 0x32) {
            FUN_1401a7120(&local_e0,&PTR_DAT_14116fe30/*"Successfully sent atomic masking sequence for key "*/);
          }
          else {
            FUN_1401485c0(CONCAT44(uStack_13c,uStack_140) + (ulonglong)local_148 * 2,
                          u_Successfully_sent_atomic_masking_14116fe3c,100);
            local_d0 = local_d0 + 0x32;
          }
          FUN_140709600(&local_e0,param_1);
          uVar8 = FUN_1401a6e70(&local_e0);
          FUN_140321c60(uVar8);
          local_b4 = 1;
        }
        else {
          plVar9 = (longlong *)
                   (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)__tls_index * 8)
                   + 0x10);
          lVar7 = *plVar9;
          if (lVar7 == 0) {
            lVar7 = FUN_1401ccdc0(plVar9);
          }
          uVar5 = *(undefined4 *)(lVar7 + 0xe8);
          FUN_1401a6cd0(&local_180,0x35,1);
          local_b0 = local_180;
          uStack_a8 = uStack_178;
          local_a0 = (uint)uStack_170;
          uStack_9c = uStack_170._4_4_;
          uStack_98 = (undefined4)uStack_168;
          uStack_94 = uStack_168._4_4_;
          local_90 = uStack_160;
          uVar2 = local_90;
          local_90._0_4_ = (uint)uStack_160;
          uVar8 = local_c0;
          uVar3 = local_68;
          uVar4 = local_40;
          if ((uint)local_90 < (uint)uStack_170) goto LAB_1403235a9;
          local_90 = uVar2;
          if ((uint)local_90 - (uint)uStack_170 < 0x35) {
            FUN_1401a7120(&local_b0,&PTR_DAT_141169ee0/*"SendInput (masking sequence) failed with error code: "*/);
          }
          else {
            FUN_1401485c0(uStack_168 + (uStack_170 & 0xffffffff) * 2,
                          u_SendInput__masking_sequence__fai_141169eec,0x6a);
            local_a0 = local_a0 + 0x35;
          }
          FUN_1406fc640(&local_b0,uVar5);
          uVar8 = FUN_1401a6e70(&local_b0);
          FUN_140321cd0(uVar8);
          local_b4 = 0;
        }
        return local_b4;
      }
    }
  }
LAB_1403235a9:
  local_40 = uVar4;
  local_68 = uVar3;
  local_90 = uVar2;
  local_c0 = uVar8;
                    /* WARNING: Subroutine does not return */
  FUN_140149d20();
}

