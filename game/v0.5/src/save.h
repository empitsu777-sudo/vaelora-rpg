#ifndef VAELORA_SAVE_H
#define VAELORA_SAVE_H
#include <stdint.h>
#define VAELORA_SAVE_BYTES 18
#define VAELORA_SAVE_VERSION 1
extern const char vaelora_sram_marker[];
/* Portable state serializer: byte format is independent of C struct padding. */
typedef struct {
 uint16_t x,y;
 uint8_t scene,hp,echo,quest,gate,enemy_hp,coat;
} VaeloraState;
void vaelora_encode_save(uint8_t out[VAELORA_SAVE_BYTES],const VaeloraState *state);
int vaelora_decode_save(VaeloraState *out,const uint8_t in[VAELORA_SAVE_BYTES]);
#endif
