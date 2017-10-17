#include "stdafx.h"
#include "SoundManager.h"

CSoundManager::CSoundManager()
{
	Init();
}
CSoundManager::~CSoundManager()
{
	Release();
}

void CSoundManager::Init()
{ 
	FMOD_System_Create(&m_pSystem);
	FMOD_System_Init(m_pSystem, SOUND_MAX, FMOD_INIT_NORMAL, NULL);	//채녈 10개짜리 시스템 사운드 초기화


	//밑에건 메모리 낭비가 매우 크기 때문에 CreateSound 함수 대신 Create 
	//FMOD_System_CreateSound(m_pSystem, "./Sound/background.mp3", FMOD_LOOP_NORMAL, 0, &m_pSound[0]); //루프_모드 ->끝날시 반복 재생 (백그라운드 뮤직) 사운드 할당
	
	//Create -> Stream 변경 , 문제 시 복구 바람
	FMOD_System_CreateStream(m_pSystem, "./Sound/Background.mp3", FMOD_LOOP_NORMAL, 0, &m_pSound[0]); //루프_모드 ->끝날시 반복 재생 (백그라운드 뮤직) 사운드 할당
	FMOD_System_CreateSound(m_pSystem, "./Sound/swap.wav", FMOD_DEFAULT, 0, &m_pSound[1]);	//스왑사운드
	FMOD_System_CreateSound(m_pSystem, "./Sound/re_swap.wav", FMOD_DEFAULT, 0, &m_pSound[2]); //실패사운드
	FMOD_System_CreateSound(m_pSystem, "./Sound/match.wav", FMOD_DEFAULT, 0, &m_pSound[3]);	//3명이 이어맞을때 나는 소리
	FMOD_System_CreateSound(m_pSystem, "./Sound/Reset.wav", FMOD_DEFAULT, 0, &m_pSound[4]); //리셋 소리
	//FMOD_System_CreateSound(m_pSystem, "./Sound/match.wav", FMOD_DEFAULT, 0, &m_pSound[5]);
	//FMOD_System_CreateSound(m_pSystem, "./Sound/Stage_1.wav", FMOD_DEFAULT, 0, &m_pSound[6]);
	//FMOD_System_CreateSound(m_pSystem, "./Sound/Stage_2.wav", FMOD_DEFAULT, 0, &m_pSound[7]);
	//FMOD_System_CreateSound(m_pSystem, "./Sound/Stage_3.wav", FMOD_DEFAULT, 0, &m_pSound[8]);
	//FMOD_System_CreateSound(m_pSystem, "./Sound/Stage_4.wav", FMOD_DEFAULT, 0, &m_pSound[9]);
	//FMOD_System_CreateSound(m_pSystem, "./Sound/Stage_5.wav", FMOD_DEFAULT, 0, &m_pSound[10]);
	//FMOD_System_CreateSound(m_pSystem, "./Sound/Stage_6.wav", FMOD_DEFAULT, 0, &m_pSound[11]);
	//FMOD_System_CreateSound(m_pSystem, "./Sound/Skill_Effect_1.wav", FMOD_DEFAULT, 0, &m_pSound[12]);
	//FMOD_System_CreateSound(m_pSystem, "./Sound/Skill_Effect_2.wav", FMOD_DEFAULT, 0, &m_pSound[13]);
	//FMOD_System_CreateSound(m_pSystem, "./Sound/Skill_Effect_3.wav", FMOD_DEFAULT, 0, &m_pSound[14]);

	/*
	- FMOD_DEFAULT : FMOD_LOOP_OFF | FMOD_2D | FMOD_HARDWARE로 이루어진 디폴트 옵션입니다.

	- FMOD_LOOP_OFF : 사운드의 반복을 OFF합니다.

	- FMOD_LOOP_NORMAL : 사운드의 반복을 ON합니다.
	*/

	FMOD_System_PlaySound(m_pSystem, FMOD_CHANNEL_FREE, m_pSound[0], 0, &m_pChannel[0]);	//배경음 재생
	
	//FMOD_System_PlaySound(m_pSystem, FMOD_BOOL, m_pSound[0], 0, &m_pChannel[0]);	//일시정지코드
	//FMOD_Channel_Stop(&m_pSound[1]); //사운드 정지, 채널 정지
	///Pause = true;

}

void CSoundManager::Update(int nParam)
{
	FMOD_Channel_SetVolume(m_pChannel[nParam], 2.0f); //받아온 숫자 사운드에 볼륨 조절 형식은 소수표현 형식
	FMOD_System_PlaySound(m_pSystem, FMOD_CHANNEL_FREE, m_pSound[nParam], 0, &m_pChannel[nParam]);
}

void CSoundManager::Stop(int nParam)
{
	FMOD_Channel_Stop(m_pChannel[nParam]);
	//FMOD_System_P
}

void CSoundManager::Release()
{
	for (int i = 0; i < SOUND_MAX; i++)
	{
		FMOD_Sound_Release(m_pSound[i]);	//사운드 종료
	}

	FMOD_System_Close(m_pSystem);		//fmod 시스템을 삭제
	FMOD_System_Release(m_pSystem);		//fmod 시스템 종료
}

void CSoundManager::System_Update()
{
	FMOD_System_Update(m_pSystem);	//사운드 데이터를 스트리밍 방식으로 갱신
}