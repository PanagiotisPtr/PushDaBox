#ifndef MUSICLIB_H
#define MUSICLIB_H

#include "SDL.h"

namespace MusicLib {

struct AudioData {
    Uint8* position;
    Uint32 length;
};

bool keepPlayingAudio = true;

void callback(void* userData, Uint8* stream, int streamLength) {
    AudioData* audio = (AudioData*)userData;

    if (audio->length == 0 || keepPlayingAudio == false) {
        audio->length = 0;
        keepPlayingAudio = false;
        return;
    }

    Uint32 length = (Uint32)streamLength;

    if (length > audio->length) {
        length = audio->length;
    }

    SDL_memcpy(stream, audio->position, length);

    audio->position += length;
    audio->length -= length;
}

void playMusic(std::string file) {
    SDL_Init(SDL_INIT_AUDIO);

    SDL_AudioSpec wavSpec;
    Uint8* wavStart;
    Uint32 wavLength;

    SDL_LoadWAV(file.c_str(), &wavSpec, &wavStart, &wavLength);

    AudioData audio;
    audio.position = wavStart;
    audio.length = wavLength;

    wavSpec.callback = callback;
    wavSpec.userdata = &audio;

    SDL_AudioDeviceID device;
    device = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);

    SDL_PauseAudioDevice(device, 0);

    while (audio.length > 0) {
        SDL_Delay(100);
    }

    SDL_CloseAudioDevice(device);
    SDL_FreeWAV(wavStart);
    SDL_Quit();
}

} // namespace MusicLib

#endif