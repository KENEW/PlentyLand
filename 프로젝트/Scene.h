#pragma once
class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	int Stage;
	CObject *Bg, *Temp;

	virtual void Process() = 0;
	virtual void Render() = 0;
};
