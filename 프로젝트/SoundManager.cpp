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
	FMOD_System_Init(m_pSystem, SOUND_MAX, FMOD_INIT_NORMAL, NULL);	//ä�� 10��¥�� �ý��� ���� �ʱ�ȭ


	//�ؿ��� �޸� ���� �ſ� ũ�� ������ CreateSound �Լ� ��� Create 
	//FMOD_System_CreateSound(m_pSystem, "./Sound/background.mp3", FMOD_LOOP_NORMAL, 0, &m_pSound[0]); //����_��� ->������ �ݺ� ��� (��׶��� ����) ���� �Ҵ�
	
	//Create -> Stream ���� , ���� �� ���� �ٶ�
	FMOD_System_CreateStream(m_pSystem, "./Sound/Background.mp3", FMOD_LOOP_NORMAL, 0, &m_pSound[0]); //����_��� ->������ �ݺ� ��� (��׶��� ����) ���� �Ҵ�
	FMOD_System_CreateSound(m_pSystem, "./Sound/swap.wav", FMOD_DEFAULT, 0, &m_pSound[1]);	//���һ���
	FMOD_System_CreateSound(m_pSystem, "./Sound/re_swap.wav", FMOD_DEFAULT, 0, &m_pSound[2]); //���л���
	FMOD_System_CreateSound(m_pSystem, "./Sound/match.wav", FMOD_DEFAULT, 0, &m_pSound[3]);	//3���� �̾������ ���� �Ҹ�
	FMOD_System_CreateSound(m_pSystem, "./Sound/Reset.wav", FMOD_DEFAULT, 0, &m_pSound[4]); //���� �Ҹ�
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
	- FMOD_DEFAULT : FMOD_LOOP_OFF | FMOD_2D | FMOD_HARDWARE�� �̷���� ����Ʈ �ɼ��Դϴ�.

	- FMOD_LOOP_OFF : ������ �ݺ��� OFF�մϴ�.

	- FMOD_LOOP_NORMAL : ������ �ݺ��� ON�մϴ�.
	*/

	FMOD_System_PlaySound(m_pSystem, FMOD_CHANNEL_FREE, m_pSound[0], 0, &m_pChannel[0]);	//����� ���
	
	//FMOD_System_PlaySound(m_pSystem, FMOD_BOOL, m_pSound[0], 0, &m_pChannel[0]);	//�Ͻ������ڵ�
	//FMOD_Channel_Stop(&m_pSound[1]); //���� ����, ä�� ����
	///Pause = true;

}

void CSoundManager::Update(int nParam)
{
	FMOD_Channel_SetVolume(m_pChannel[nParam], 2.0f); //�޾ƿ� ���� ���忡 ���� ���� ������ �Ҽ�ǥ�� ����
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
		FMOD_Sound_Release(m_pSound[i]);	//���� ����
	}

	FMOD_System_Close(m_pSystem);		//fmod �ý����� ����
	FMOD_System_Release(m_pSystem);		//fmod �ý��� ����
}

void CSoundManager::System_Update()
{
	FMOD_System_Update(m_pSystem);	//���� �����͸� ��Ʈ���� ������� ����
}