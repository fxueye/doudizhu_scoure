#pragma once
#include "cocos2d.h"
#include "GameLayer.h"
#include "NetGameLayer.h"
USING_NS_CC;

//ѡ�񵥻� ��������
class ChoosePlayTypeLayer : public CCLayer
{
public:
	ChoosePlayTypeLayer(void);
	~ChoosePlayTypeLayer(void);
	virtual bool init();
	void menuAloneHandle(CCObject* sender);//����
	void menuNetHandle(CCObject* sender);//����

	CREATE_FUNC(ChoosePlayTypeLayer);

private: 
	Menu* m_handle_menu;//ѡ��˵�
};