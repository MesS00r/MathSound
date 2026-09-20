#include "wav.h"

static struct __attribute__((packed)) {
    char     chunk_id[4];
    uint32_t chunk_size;      
    char     format[8];
    uint32_t subchunk1_size;  
    uint16_t audio_format;    
    uint16_t num_channels;    
    uint32_t sample_rate;     
    uint32_t byte_rate;       
    uint16_t block_align;     
    uint16_t bits_per_sample; 
    char     subchunk2_id[4];
    uint32_t subchunk2_size;  
} wav_header = {
    .chunk_id        = {'R', 'I', 'F', 'F'},
    .chunk_size      = 0xFFFFFFFF,
    .format          = {'W', 'A', 'V', 'E', 'f', 'm', 't', ' '},
    .subchunk1_size  = 16,
    .audio_format    = 1,
    .num_channels    = 1,
    .sample_rate     = 44100,
    .byte_rate       = 88200,
    .block_align     = 2,
    .bits_per_sample = 16,
    .subchunk2_id    = {'d', 'a', 't', 'a'},
    .subchunk2_size  = 0xFFFFFFFF
};

bool wav_init(FILE *file) {
    if (sizeof(wav_header) != 44) return false;

    fwrite(&wav_header, sizeof(wav_header), 1, file);

    return true;
}

void wav_add(FILE *file) {
    //TODO:
    (void)file;
}