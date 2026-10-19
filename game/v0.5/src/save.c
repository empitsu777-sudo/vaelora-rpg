#include "save.h"
/* SRAM autodetection signature used by GBA emulators and flashcart tooling. */
const char vaelora_sram_marker[]="SRAM_V113";
static uint16_t crc16(const uint8_t *data,int len){
 uint16_t crc=0xffff;
 for(int i=0;i<len;i++){
  crc^=(uint16_t)data[i]<<8;
  for(int b=0;b<8;b++)crc=(uint16_t)((crc&0x8000)?(crc<<1)^0x1021:(crc<<1));
 }
 return crc;
}
void vaelora_encode_save(uint8_t out[VAELORA_SAVE_BYTES],const VaeloraState *s){
 out[0]='V';out[1]='L';out[2]='R';out[3]='5';out[4]=VAELORA_SAVE_VERSION;
 out[5]=s->scene;out[6]=(uint8_t)s->x;out[7]=(uint8_t)(s->x>>8);
 out[8]=(uint8_t)s->y;out[9]=(uint8_t)(s->y>>8);
 out[10]=s->hp;out[11]=s->echo;out[12]=s->quest;out[13]=s->gate;
 out[14]=s->enemy_hp;out[15]=s->coat;
 uint16_t crc=crc16(out,16);out[16]=(uint8_t)crc;out[17]=(uint8_t)(crc>>8);
}
int vaelora_decode_save(VaeloraState *s,const uint8_t in[VAELORA_SAVE_BYTES]){
 if(in[0]!='V'||in[1]!='L'||in[2]!='R'||in[3]!='5'||in[4]!=VAELORA_SAVE_VERSION)return 0;
 uint16_t expected=(uint16_t)in[16]|((uint16_t)in[17]<<8);
 if(crc16(in,16)!=expected)return 0;
 VaeloraState t;
 t.scene=in[5];t.x=(uint16_t)in[6]|((uint16_t)in[7]<<8);
 t.y=(uint16_t)in[8]|((uint16_t)in[9]<<8);
 t.hp=in[10];t.echo=in[11];t.quest=in[12];t.gate=in[13];t.enemy_hp=in[14];t.coat=in[15];
 if(t.scene>2||t.x<12||t.x>=500||t.y<12||t.y>=500||t.hp<1||t.hp>5||t.echo>5||t.quest>3||t.gate>1||t.enemy_hp>3||t.coat>2)return 0;
 *s=t;
 return 1;
}
