#include "soundhandler.h"
#include <QSoundEffect>

SoundHandler::SoundHandler(QObject *parent)
    : QObject{parent} {
    buttonMenuSoundEffect.setSource(QUrl("qrc:/resource/sound/resource/sound/button_menu.wav"));
    buttonMenuSoundEffect.setVolume(0.5);
    warningChimeSoundEffect.setSource(QUrl("qrc:/resource/sound/resource/sound/warning_chime.wav"));
    warningChimeSoundEffect.setVolume(1.0);
}

void SoundHandler::playButtonMenuSoundEffect() {
    buttonMenuSoundEffect.play();
}

void SoundHandler::playBlinkerSoundEffect() {
}

void SoundHandler::playWarningChimeSoundEffect(int times) {
    warningChimeSoundEffect.setLoopCount(times);
    warningChimeSoundEffect.play();
}
