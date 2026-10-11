
void FUN_140409240(void)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = FUN_14079cf20(&DAT_140ba5958);
  *(undefined ***)(lVar3 + 8) = &PTR_DAT_1411c8de8;
  *(int *)(lVar3 + 0x14) = *(int *)(lVar3 + 0x14) + 1;
  FUN_140652e50(lVar3,&PTR_DAT_14113a090/*"Cursor"*/);
  *(int *)(lVar3 + 0x14) = *(int *)(lVar3 + 0x14) + 1;
  uVar1 = *(uint *)(lVar3 + 0x10);
  if (uVar1 < *(uint *)(*(longlong *)(lVar3 + 8) + 8)) {
    *(uint *)(lVar3 + 0x10) = uVar1 + 1;
    *(undefined ***)(*(longlong *)(lVar3 + 8) + 0x10 + (ulonglong)uVar1 * 8) = &PTR_DAT_14118e5a8/*"Windsurf"*/;
  }
  else {
    FUN_140652e50(lVar3,&PTR_DAT_14118e5a8/*"Windsurf"*/);
  }
  *(int *)(lVar3 + 0x14) = *(int *)(lVar3 + 0x14) + 1;
  uVar1 = *(uint *)(lVar3 + 0x10);
  if (uVar1 < *(uint *)(*(longlong *)(lVar3 + 8) + 8)) {
    *(uint *)(lVar3 + 0x10) = uVar1 + 1;
    *(undefined ***)(*(longlong *)(lVar3 + 8) + 0x10 + (ulonglong)uVar1 * 8) = &PTR_DAT_141135400/*"Code"*/;
  }
  else {
    FUN_140652e50(lVar3,&PTR_DAT_141135400/*"Code"*/);
  }
  if (PTR_FUN_1411d0740 != (undefined *)0x0) {
    FUN_14077371c();
  }
  lVar2 = DAT_1411d7350;
  FUN_14079d180(DAT_1411d7350 + 8,lVar3);
  lVar3 = FUN_14079d0b0(&DAT_140ec4c78,5);
  *(undefined ***)(lVar3 + 0x10) = &PTR_DAT_141196920/*"chrome"*/;
  *(undefined ***)(lVar3 + 0x18) = &PTR_DAT_1411a2950/*"msedge"*/;
  *(undefined ***)(lVar3 + 0x20) = &PTR_DAT_14119c2d8/*"firefox"*/;
  *(undefined ***)(lVar3 + 0x28) = &PTR_DAT_1411a4510/*"opera"*/;
  *(undefined ***)(lVar3 + 0x30) = &PTR_DAT_141195978/*"brave"*/;
  FUN_14079d180(lVar2 + 0x10,lVar3);
  lVar3 = FUN_14079cf20(&DAT_140b37e18);
  *(undefined ***)(lVar3 + 8) = &PTR_DAT_1411ac910/*"unknown"*/;
  *(undefined ***)(lVar3 + 0x10) = &PTR_DAT_1411ac910/*"unknown"*/;
  *(undefined ***)(lVar3 + 0x18) = &PTR_DAT_1411ac910/*"unknown"*/;
  FUN_14079d180(lVar2 + 0x18,lVar3);
  *(undefined ***)(lVar2 + 0x20) = &PTR_DAT_1411ac910/*"unknown"*/;
  lVar3 = FUN_14079d0b0(&DAT_140ec4c78,2);
  *(undefined ***)(lVar3 + 0x10) = &PTR_DAT_1411a1ac8/*"meet.google.com"*/;
  *(undefined ***)(lVar3 + 0x18) = &PTR_DAT_141199f38/*"discord.com"*/;
  FUN_14079d180(lVar2 + 0x28,lVar3);
  lVar3 = FUN_14079d0b0(&DAT_140ec4c78,1);
  *(undefined ***)(lVar3 + 0x10) = &PTR_DAT_1411ae918/*"zoom.us"*/;
  FUN_14079d180(lVar2 + 0x30,lVar3);
  return;
}

