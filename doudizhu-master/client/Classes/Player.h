#pragma once
#include "cocos2d.h"
#include "Poker.h"
USING_NS_CC;

//���з��ƺ��������
struct PkHandType
{
	CARD_TYPE type;
	std::vector<Poker*> vec_poker;
};


class  Player : public CCObject
{
public:
	 Player();
	~ Player();
	void updatePkPosion();//�����Ƶ�λ

	public:
	std::vector<PkHandType> m_vec_types;
private:
	CC_SYNTHESIZE(bool,m_isDizhu,IsDiZhu);//�Ƿ�Ϊ����
	CC_SYNTHESIZE(bool,m_isCall,Call);//�Ƿ��Ѿ��е�����
	CC_SYNTHESIZE(int,m_CallScore,CallScore);//�����з�
	CC_SYNTHESIZE(CCArray*,m_arrPk,ArrPK);//���е���
	CC_SYNTHESIZE(CCPoint,m_startLocation,StartLocation);//�������еĳ�ʼλ��
	CC_SYNTHESIZE(int,m_HandleType,HandleType);
	CC_SYNTHESIZE(bool,m_isOutPk,IsOutPk);//�����Ƿ�������
 
};

 