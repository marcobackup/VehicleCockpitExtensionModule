#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool settingsIsOpen READ settingsIsOpen WRITE setSettingsIsOpen NOTIFY settingsIsOpenChanged)
    Q_PROPERTY(bool settingsDiagnosysOpen READ settingsDiagnosysOpen WRITE setSettingsDiagnosysOpen NOTIFY settingsDiagnosysOpenChanged)
    Q_PROPERTY(int settingsViewId READ settingsViewId WRITE setSettingsViewId NOTIFY settingsViewIdChanged)

    Q_PROPERTY(int theme READ theme WRITE setTheme NOTIFY themeChanged)
    Q_PROPERTY(int language READ language WRITE setLanguage NOTIFY languageChanged)
    Q_PROPERTY(bool audioStatus READ audioStatus WRITE setAudioStatus NOTIFY audioStatusChanged)

    Q_PROPERTY(int ambientLightSource READ ambientLightSource WRITE setAmbientLightSource NOTIFY ambientLightSourceChanged)
    Q_PROPERTY(int ambientLightLRSeatLevel READ ambientLightLRSeatLevel WRITE setAmbientLightLRSeatLevel NOTIFY ambientLightLRSeatLevelChanged)
    Q_PROPERTY(int ambientLightRRSeatLevel READ ambientLightRRSeatLevel WRITE setAmbientLightRRSeatLevel NOTIFY ambientLightRRSeatLevelChanged)
public:
    explicit Settings(QObject *parent = nullptr);

    bool settingsIsOpen() const;
    void setSettingsIsOpen(bool newSettingsIsOpen);

    bool settingsDiagnosysOpen() const;
    void setSettingsDiagnosysOpen(bool newSettingsDiagnosysOpen);

    int settingsViewId() const;
    void setSettingsViewId(int newSettingsViewId);

    int theme() const;
    void setTheme(int newTheme);

    int language() const;
    void setLanguage(int newLanguage);

    bool audioStatus() const;
    void setAudioStatus(bool newAudioStatus);

    int ambientLightSource() const;
    void setAmbientLightSource(int newAmbientLightSource);

    int ambientLightLRSeatLevel() const;
    void setAmbientLightLRSeatLevel(int newAmbientLightLRSeatLevel);

    int ambientLightRRSeatLevel() const;
    void setAmbientLightRRSeatLevel(int newAmbientLightRRSeatLevel);

signals:

    void settingsIsOpenChanged();
    void settingsDiagnosysOpenChanged();

    void settingsViewIdChanged();

    void themeChanged();

    void languageChanged();

    void audioStatusChanged();

    void ambientLightSourceChanged();

    void ambientLightLRSeatLevelChanged();

    void ambientLightRRSeatLevelChanged();

    void settingsConfigLoaded();

private:
    bool m_settingsIsOpen;
    bool m_settingsDiagnosysOpen;
    int m_settingsViewId;
    int m_theme;
    int m_language;
    bool m_audioStatus;
    int m_ambientLightSource;
    int m_ambientLightLRSeatLevel;
    int m_ambientLightRRSeatLevel;
};

#endif // SETTINGS_H
