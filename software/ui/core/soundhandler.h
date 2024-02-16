#ifndef SOUNDHANDLER_H
#define SOUNDHANDLER_H

#include <QObject>
#include <QSoundEffect>

class SoundHandler : public QObject
{
public:
    explicit SoundHandler(QObject *parent = nullptr);
    void playButtonMenuSoundEffect();
    void playBlinkerSoundEffect();
    void playWarningChimeSoundEffect(int times = 1);
signals:
    void buttonMenuSoundEffectPlayed();
    void blinkerSoundEffectPlayed();
    void warningChimeSoundEffectPlayed();
private:
    QSoundEffect buttonMenuSoundEffect;
    QSoundEffect blinkerSoundEffect;
    QSoundEffect warningChimeSoundEffect;
};

#endif // SOUNDHANDLER_H
