/* Vaelora Bellhaven playable vertical slice: original Mode0 4bpp GBA engine.
 * Copyright (c) Vaelora project. Superpowers CC0 props via generated assets.c.
 */
#include "assets.h"
#include "save.h"
#define REG16(addr) (*(volatile unsigned short*)(addr))
#define DISPCNT REG16(0x04000000)
#define DISPSTAT REG16(0x04000004)
#define VCOUNT REG16(0x04000006)
#define BG0CNT REG16(0x04000008)
#define BG1CNT REG16(0x0400000A)
#define BG2CNT REG16(0x0400000C)
#define BG0HOFS REG16(0x04000010)
#define BG0VOFS REG16(0x04000012)
#define BG1HOFS REG16(0x04000014)
#define BG1VOFS REG16(0x04000016)
#define BG2HOFS REG16(0x04000018)
#define BG2VOFS REG16(0x0400001A)
#define KEYINPUT REG16(0x04000130)
#define BGPALETTE ((volatile unsigned short*)0x05000000)
#define OBJPALETTE ((volatile unsigned short*)0x05000200)
#define BGVRAM ((volatile unsigned short*)0x06000000)
#define OBJVRAM ((volatile unsigned short*)0x06010000)
#define OAM ((volatile unsigned short*)0x07000000)
#define SRAM ((volatile unsigned char*)0x0E000000)
#define K_A 1
#define K_B 2
#define K_START 8
#define K_RIGHT 16
#define K_LEFT 32
#define K_UP 64
#define K_DOWN 128
#define K_R 256
#define K_L 512
static const unsigned short *grounds[3]={vaelora_ground_0,vaelora_ground_1,vaelora_ground_2};
static const unsigned short *props[3]={vaelora_props_0,vaelora_props_1,vaelora_props_2};
static const unsigned char *solids[3]={vaelora_solid_0,vaelora_solid_1,vaelora_solid_2};
static int scene=0,px=256,py=253,dir=0,step=1,frame=0,hp=5,echo=5,quest=0,gate=0,enemy_hp=3,attack_timer=0,damage_timer=0,menu=0,coat=0,kx=275,ky=265,msgface=0;
static int msgtime=0;
static const char *msg1=0,*msg2=0;
static unsigned short oldkeys=0;
static int absn(int n){return n<0?-n:n;}
static int near(int x,int y,int d){return absn(px-x)+absn(py-y)<d;}
static void say(const char *a,const char *b){msg1=a;msg2=b;msgtime=145;msgface=0;}
static void saymaera(const char *a,const char *b){say(a,b);msgface=1;}
/* Size 0 = 16x16, 1 = 16x32, 2 = 32x32. All GBA hardware legal. */
static void oam(int id,int x,int y,int tile,int size,int pal){
 volatile unsigned short *p=OAM+id*4;
 int width=(size==2?32:16),height=(size==1||size==2?32:16);
 if(x<-width||x>239||y<-height||y>159){p[0]=0x0200;p[1]=0;p[2]=0;p[3]=0;return;}
 p[0]=(unsigned short)((y&255)|(size==1?0x8000:0));
 p[1]=(unsigned short)((x&511)|(size==0?0x4000:0x8000));
 p[2]=(unsigned short)((tile&1023)|(1<<10)|(pal<<12));p[3]=0;
}
static void copy16(volatile unsigned short *to,const unsigned short *from,int count){for(int i=0;i<count;i++)to[i]=from[i];}
static void loadmap(void){
 const unsigned short *g=grounds[scene],*f=props[scene];
 // 64x64 BG tilemaps use four screenblocks (32x32 each), not linear 64x64 VRAM.
 for(int y=0;y<64;y++)for(int x=0;x<64;x++){
  int pos=((y>>5)*2+(x>>5))*1024+(y&31)*32+(x&31);
  BGVRAM[24*1024+pos]=g[y*64+x];
  BGVRAM[28*1024+pos]=(scene==1&&gate&&y>=29&&y<=30&&x>=29&&x<35)?0:f[y*64+x];
 }
}
static void clearui(void){volatile unsigned short *ui=BGVRAM+16*1024;for(int i=0;i<1024;i++)ui[i]=0;}
static void box(int x,int y,int w,int h){volatile unsigned short *ui=BGVRAM+16*1024;for(int yy=y;yy<y+h;yy++)for(int xx=x;xx<x+w;xx++)if(xx>=0&&xx<32&&yy>=0&&yy<32)ui[yy*32+xx]=(unsigned short)((97)|(6<<12));}
static void writeat(int x,int y,const char *s){volatile unsigned short *ui=BGVRAM+16*1024;for(;*s&&x<30;s++,x++)if(x>=0&&y>=0&&y<32){int ch=(unsigned char)*s;if(ch<32||ch>127)ch='?';ui[y*32+x]=(unsigned short)((ch-32+1)|(6<<12));}}
static void num2(char *dst,int v){if(v<0)v=0;if(v>99)v=99;dst[0]=(char)('0'+v/10);dst[1]=(char)('0'+v%10);dst[2]=0;}
static void drawui(void){
 char buf[3];clearui();box(0,0,30,2);
 writeat(1,0,scene==0?"BELLHAVEN":scene==1?"REEDGLASS PATH":"GLAZIER WORKSHOP");
 writeat(1,1,"HP");num2(buf,hp);writeat(4,1,buf);writeat(9,1,"ECHO");num2(buf,echo);writeat(14,1,buf);
 writeat(20,1,"SHARD");writeat(27,1,quest>=2?"1":"0");
 if(menu){box(0,10,30,10);writeat(1,11,"WAYFARER / FIELD JOURNAL");writeat(1,13,"A SAVE SRAM    B LOAD SRAM");writeat(1,14,"L CHANGE COAT  R KITH SKILL");writeat(1,16,"D-PAD WALK    B ATTACK");writeat(1,18,"START CLOSE MENU");return;}
 if(msgtime>0){box(0,15,30,5);int tx=msgface?5:1;if(msg1)writeat(tx,16,msg1);if(msg2)writeat(tx,18,msg2);}
 else {box(0,19,30,1);writeat(1,19,quest==0?"FIND MAERA BY GLASS SHOP":quest==1?"REEDGLASS: FIND THE SHARD":quest==2?"RETURN SHARD TO MAERA":"BELLHAVEN SPIRE RESTORED");}
}
static void warp(int next,int x,int y){scene=next;px=x;py=y;kx=x+19;ky=y+12;loadmap();say(next==0?"BELLHAVEN":"NEW AREA",next==1?"REEDGLASS PATH":next==2?"GLAZIER WORKSHOP":"RETURN TO TOWN");}
static int solid_at(int x,int y){
 if(x<12||x>=500||y<12||y>=500)return 1;
 int tx=x>>3,ty=y>>3;
 if(scene==1&&gate&&(ty==29||ty==30)&&tx>=29&&tx<35)return 0;
 return solids[scene][ty*64+tx]!=0;
}
static int canmove(int x,int y){return !solid_at(x-5,y-2)&&!solid_at(x+5,y-2)&&!solid_at(x-5,y-8)&&!solid_at(x+5,y-8);}
static void interact(void){
 if(scene==0){
  if(near(145,234,45)){
   if(quest==0){quest=1;saymaera("MY SHARD IS LOST.","SEARCH REEDGLASS PATH.");}
   else if(quest==2){quest=3;saymaera("THE SPIRE SINGS AGAIN!","YOU RESTORED BELLHAVEN.");}
   else if(quest==1)saymaera("CROSS THE OLD BRIDGE.","SCUTTLE RESONATES STONE.");
   else saymaera("THE BELLS REMEMBER.","THANK YOU, WAYFARER.");
  }else if(near(128,202,30)){warp(2,256,425);}
  else if(near(310,246,40)){echo=5;hp=5;say("CHIME HEARTH RESONATES.","LANTERN AND HEALTH RESTORED.");}
  else say("BELLHAVEN IS LISTENING.","FIND MAERA OR THE NORTH ROAD.");
 }else if(scene==2){
  if(near(256,442,32)){warp(0,129,228);}
  else if(near(256,236,50)){echo=5;say("THE HEARTH WARMS THE PLATES.","SCUTTLE CHIMES CONTENTEDLY.");}
  else say("GLAZIER TOOLS SHIMMER.","THE GLASS NEEDS A TRUE NOTE.");
 }else{
  if(near(256,120,35)&&gate){
   if(enemy_hp<=0&&quest==1){quest=2;say("RESONANT SHARD RECOVERED!","RETURN TO MAERA IN BELLHAVEN.");}
   else if(enemy_hp>0)say("A HUSH SHADE GUARDS IT.","PRESS B NEAR THE SHADE.");
   else say("THE SHARD IS ALREADY SAFE.","RETURN TO MAERA.");
  }else say("WIND IN THE REEDS.","THE NORTH BANK HIDES A SHARD.");
 }
}
static void use_kith(void){
 if(scene==1&&near(256,240,60)&&!gate&&echo>=2){gate=1;echo-=2;loadmap();say("SCUTTLE RESONATES THE GATE!","THE STONE BARRIER OPENS.");}
 else if(echo<2)say("NOT ENOUGH LIQUID ECHO.","REST AT A CHIME HEARTH.");
 else say("SCUTTLE CHIMES SOFTLY.","NO RELIC SOCKET NEARBY.");
}
static void attack(void){
 attack_timer=12;
 if(scene==1&&enemy_hp>0&&near(256,183,43)){
  enemy_hp--;
  if(enemy_hp==0)say("HUSH SHADE DISPERSED.","THE SPIRIT RETURNS TO SILENCE.");
  else say("YOUR BLADE RINGS TRUE!","THE SHADE RECOILS.");
 }else say("YOUR BLADE SWINGS.","NO FOE WITHIN REACH.");
}
/* Cartridge SRAM saves. Codec also compiled and exercised in native host tests.
   The game never trusts unvalidated bytes from an uninitialized save chip. */
static void savegame(void){
 VaeloraState state={(unsigned short)px,(unsigned short)py,(unsigned char)scene,
  (unsigned char)hp,(unsigned char)echo,(unsigned char)quest,(unsigned char)gate,
  (unsigned char)enemy_hp,(unsigned char)coat};
 unsigned char buf[VAELORA_SAVE_BYTES];vaelora_encode_save(buf,&state);
 volatile char marker=vaelora_sram_marker[0];(void)marker;
 for(int i=0;i<VAELORA_SAVE_BYTES;i++)SRAM[i]=buf[i];
 say("JOURNEY SAVED TO SRAM.","YOUR KITH WILL REMEMBER.");
}
static void loadgame(void){
 unsigned char buf[VAELORA_SAVE_BYTES];
 for(int i=0;i<VAELORA_SAVE_BYTES;i++)buf[i]=SRAM[i];
 VaeloraState state;
 if(!vaelora_decode_save(&state,buf)){say("NO VALID SAVED JOURNEY.","START A NEW ADVENTURE.");return;}
 scene=state.scene;px=state.x;py=state.y;hp=state.hp;echo=state.echo;
 quest=state.quest;gate=state.gate;enemy_hp=state.enemy_hp;coat=state.coat;
 kx=px+19;ky=py+12;loadmap();say("JOURNEY RESTORED.","THE LANTERN REMEMBERS.");
}
static void update(void){
 unsigned short keys=(unsigned short)((~KEYINPUT)&1023),pressed=keys&~oldkeys;oldkeys=keys;
 if(pressed&K_START){menu=!menu;msgtime=0;}
 if(menu){
  if(pressed&K_A){menu=0;savegame();}
  else if(pressed&K_B){menu=0;loadgame();}
  else if(pressed&K_L){coat=(coat+1)%3;menu=0;say("NEW WAYFARER COAT.","YOUR STYLE, YOUR JOURNEY.");}
  return;
 }
 if(pressed&K_A)interact();
 if(pressed&K_B)attack();
 if(pressed&K_R)use_kith();
 if(pressed&K_L){coat=(coat+1)%3;say("NEW WAYFARER COAT.","THE LANTERN GLOWS ON.");}
 int dx=0,dy=0;
 if(keys&K_LEFT){dx=-1;dir=3;}
 else if(keys&K_RIGHT){dx=1;dir=2;}
 if(keys&K_UP){dy=-1;dir=1;}
 else if(keys&K_DOWN){dy=1;dir=0;}
 if(dx||dy){if(canmove(px+dx,py))px+=dx;if(canmove(px,py+dy))py+=dy;step=(frame/9)%3;}
 else step=1;
 /* Smooth delayed companion movement, maintaining a grounded shell silhouette. */
 int tx=px+(dir==3?17:-17),ty=py+11;
 if(kx<tx-2)kx++;else if(kx>tx+2)kx--;
 if(ky<ty-2)ky++;else if(ky>ty+2)ky--;
 if(scene==0&&py<25&&px>230&&px<286)warp(1,256,470);
 if(scene==1&&py>493&&px>224&&px<288)warp(0,256,31);
 if(scene==1&&enemy_hp>0&&near(256,183,27)&&damage_timer==0){hp--;damage_timer=90;if(hp<=0){hp=5;echo=5;warp(0,306,247);say("THE HEARTH DREW YOU HOME.","YOUR KITH IS SAFE.");}}
 if(damage_timer)damage_timer--;
 if(attack_timer)attack_timer--;
 if(msgtime)msgtime--;
 frame++;
}
static void drawactors(void){
 int camx=px-120,camy=py-80;if(camx<0)camx=0;if(camy<0)camy=0;if(camx>272)camx=272;if(camy>352)camy=352;
 BG0HOFS=(unsigned short)camx;BG0VOFS=(unsigned short)camy;
 BG1HOFS=(unsigned short)camx;BG1VOFS=(unsigned short)camy;
 oam(0,px-8-camx,py-29-camy,OBJ_WAYFARER+(dir*3+step)*8,1,coat==0?0:coat+2);
 oam(1,kx-16-camx,ky-27-camy,OBJ_KITH+((frame/12)%4)*16,2,0);
 if(scene==0)oam(2,145-8-camx,234-29-camy,OBJ_MAERA,1,1);else oam(2,-64,-64,0,1,1);
 if(scene==1&&enemy_hp>0)oam(3,256-8-camx,183-15-camy,OBJ_SHADE+((frame/20)%2)*4,0,2);else oam(3,-64,-64,0,0,0);
 if(attack_timer){
  int ax=px-camx-8,ay=py-camy-22;
  if(dir==2)ax+=14;else if(dir==3)ax-=14;else if(dir==1)ay-=15;else ay+=10;
  oam(4,ax,ay,OBJ_SLASH+((attack_timer/4)%2)*4,0,0);
 }else oam(4,-64,-64,0,0,0);
 if(msgtime>0&&msgface){
  oam(5,4,124,OBJ_MAERA_PORTRAIT+((quest>=3)?1:(quest==1?2:0))*16,2,1);
  /* Priority zero: the portrait must appear in front of BG2 dialogue panel. */
  OAM[5*4+2]&=(unsigned short)~0x0c00;
 }else oam(5,-64,-64,0,2,1);
 for(int i=6;i<128;i++)OAM[i*4]=0x0200;
}
int main(void){
 DISPCNT=0;
 for(int i=0;i<112;i++)BGPALETTE[i]=vaelora_bg_palette[i];
 for(int i=0;i<80;i++)OBJPALETTE[i]=vaelora_obj_palette[i];
 copy16(BGVRAM,vaelora_bg_tiles,BG_TILE_COUNT*16);
 copy16(BGVRAM+8192,vaelora_ui_tiles,UI_TILE_COUNT*16); // charblock1 = 0x4000 = 8192 halfwords
 copy16(OBJVRAM,vaelora_obj_tiles,OBJ_TILE_COUNT*16);
 BG0CNT=(3)|(0<<2)|(24<<8)|(3<<14);
 BG1CNT=(2)|(0<<2)|(28<<8)|(3<<14);
 BG2CNT=(0)|(1<<2)|(16<<8)|(0<<14);
 BG2HOFS=0;BG2VOFS=0;
 for(int i=0;i<128;i++)OAM[i*4]=0x0200;
 loadmap();say("WELCOME TO BELLHAVEN.","TALK TO MAERA BY THE SHOP.");drawui();
 DISPCNT=(1<<6)|(1<<8)|(1<<9)|(1<<10)|(1<<12); // Mode0, OBJ 1D, BG0/1/2 and OBJ
 for(;;){while(VCOUNT>=160){}while(VCOUNT<160){}update();drawactors();drawui();}
 return 0;
}
