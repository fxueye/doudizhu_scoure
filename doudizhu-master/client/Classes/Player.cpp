#include "Player.h"

Player::Player():m_isCall(false),m_isDizhu(false),m_CallScore(0),m_isOutPk(false) {
	m_arrPk = CCArray::create();
	m_arrPk->retain();
}

Player::~ Player(){
	CC_SAFE_DELETE(m_arrPk);
}

void Player::updatePkPosion(){ //�������:0Ϊ��ң�1Ϊ���ԣ�2Ϊ��ʾ��������,3Ϊ���Ҫ�����ƣ�4Ϊ����1Ҫ�����ƣ�5Ϊ����2Ҫ������
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	int x,y;
	if(m_HandleType == PLAYER_ARRAY_PK || m_HandleType == PLAYER_HAND_PK){
		x = size.width/2-((m_arrPk->count()-1)*pkDistance + pkWidth) / 2;
		y = m_startLocation.y;
	}
	else if(m_HandleType == COMPUTER_ARRAY_PK || m_HandleType == COMPUTER_1_HANDLE_PK ||  m_HandleType == COMPUTER_2_HANDLE_PK ){ //������ҷ��Ƴ���λ��
		x = m_startLocation.x;
		y = m_startLocation.y;
	}
	else if(m_HandleType == THREE_PK){//������λ��
		 x = size.width/2 - (m_arrPk->count()*pkWidth + (m_arrPk->count()-1)*pkDistance)/2;
		 y = m_startLocation.y;
	}

	//���ƽ�������
	if (m_HandleType == PLAYER_ARRAY_PK || m_HandleType == COMPUTER_ARRAY_PK || m_HandleType == THREE_PK){
		for (int i=0; i<m_arrPk->count()!=0 && i<(m_arrPk->count()-1); ++i){
			for (int j=0;j<m_arrPk->count()-1-i;++j){
				Poker* pk1 = (Poker*)m_arrPk->objectAtIndex(j);
				Poker* pk2 = (Poker*)m_arrPk->objectAtIndex(j+1);
				if (pk1->getPkNum() < pk2->getPkNum())
					m_arrPk->exchangeObject(pk1,pk2);	
			}
		}
	}

// 	int count = m_arrPk->count();
// 	for (int i=0;i<count;i++)
// 	{
// 		Poker* pk1 = (Poker*)m_arrPk->objectAtIndex(i);
// 		CCLog("pk1->getPkNum() = %d",pk1->getPkNum());
// 	}
	//����λ��
	int index = 0;
	CCObject* object;
	CCARRAY_FOREACH(m_arrPk,object){
		Poker* pk = (Poker*)object;
		if (m_HandleType == PLAYER_ARRAY_PK || m_HandleType == PLAYER_HAND_PK){ 
			pk->showFront();
			pk->setPosition(ccp(x+index*pkDistance + pkWidth/2,y));
		}

		else if (m_HandleType == COMPUTER_ARRAY_PK){
			pk->showBack();
			pk->setPosition(ccp(x,y-index*pkDistance));
		}

		else if (m_HandleType == COMPUTER_1_HANDLE_PK || m_HandleType == COMPUTER_2_HANDLE_PK){
			pk->showFront();
			pk->setPosition(ccp(x,y-index*pkDistance));
		}

		else if (m_HandleType == THREE_PK){
			pk->setPosition(ccp(x+index*pkDistance+index*pkWidth + pkWidth/2,y));
		}
		++index;
	}

	//�ı�����z��˳��
	int i=m_arrPk->count()-1;
	CCARRAY_FOREACH(m_arrPk,object){
		Poker* pk = (Poker*)object;
		if (m_HandleType == COMPUTER_ARRAY_PK || m_HandleType == COMPUTER_1_HANDLE_PK || m_HandleType == COMPUTER_2_HANDLE_PK)
			pk->setZOrder(size.height - pk->getPositionY());
		if (m_HandleType == PLAYER_ARRAY_PK || m_HandleType == PLAYER_HAND_PK)
			pk->setZOrder(pk->getPositionX()); 
	}
}