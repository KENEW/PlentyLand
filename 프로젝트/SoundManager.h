#pragma once

class CSoundManager {
private:
	FMOD_SYSTEM* m_pSystem;
	FMOD_SOUND* m_pSound[SOUND_MAX];
	FMOD_CHANNEL* m_pChannel[SOUND_MAX];

public:
	CSoundManager();
	~CSoundManager();
	void Init();
	void Update(int nParam); // playsound
	void Stop(int nParam);
	void Release();
	void System_Update();
};