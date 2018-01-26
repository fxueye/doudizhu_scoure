#pragma once

#include "cocos2d.h"
#include "Global.h"
class GameLayer;

USING_NS_CC;

class Poker : public Sprite
{
public:
	Poker();
	~Poker();

	static Poker* create(const char *poker_name,const CCRect& rect);
	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

	void showFront();//��ʾ����
	void showBack();//��ʾ����
	Poker* copy(); 
	void setTouchPriority(int num);//���ô������ȼ�
	void selectPkTop();//ѡ������
	void selectPkDown();//ѡ������


private:
	CC_SYNTHESIZE(bool,m_isSelect,Select);//CC_SYNTHESIZE ����private�����ⲿ���� ������
	CC_SYNTHESIZE(GameLayer*,m_gameMain,GameMain);
	CC_SYNTHESIZE(bool,m_isClick,Click);
	CC_SYNTHESIZE(int,m_PkType,PkType);
	CC_SYNTHESIZE(int,m_PkNum,PkNum);

	EventListenerTouchOneByOne* touchListener;
};

 