#pragma once
#include "cocos2d.h"
#include "Rule.h"
#include "Player.h"
#include "Poker.h"

USING_NS_CC;

//������Ϸ
class GameLayer : public CCLayer
{
public:
	GameLayer(void);
	~GameLayer(void);
	virtual bool init();
	CREATE_FUNC(GameLayer);

	bool initBackGround();
	bool createPokers();
	Poker *selectPoker(int pokerType,int num);
	bool initPlayer();
	bool initButton();
	void ShowScore(CCPoint pt,int score);//��ʾ���� ����������
	void menuCallBackOneScore(CCObject* sender);
	void menuCallBackTwoScore(CCObject* sender);
	void menuCallBackThreeScore(CCObject* sender);
	void menuCallDiZhu(CCObject* sender);//���е���
	void menuNotHandle(CCObject* sender);//����
	void menuHandle(CCObject* sender);//����
	void menuSuccess(CCObject* sender);//ʤ��
	void menuLost(CCObject* sender);//ʧ��
	void reStart();//���¿�ʼ
	bool IsOutPkFinish();//�Ƿ������
	void sendPk();//����
	void MovePk(Player* play,Poker* pk);//������Ч
	void func(CCNode* pSender, void* pData);
	void update(float delta);
	void playerPkCanClick();
	void Call(float dt);//�е���
	void NpcCall(Player* npc,int index);//���Խ���
	void GiveDiZhuThreePk();//������������
	void ClearOutPks(bool is_player_pre =false);//������г���
	bool NpcOutPks(Player* m_npc,Player* m_npcOut);//NPC����
	bool NpcFollowPks(Player* m_npc,Player* m_npcOut);//NPC����
	void SplitPks(int type,Player* m_npc);//����npc��� 1��npc1 2:npc2
	bool GameOver();//������
	void OutPk(float delta);

private: 
	 CCArray* m_arrPokers;//���Ե���
	 CC_SYNTHESIZE(CCArray*,m_arrayPlayerOut,ArrayPlayerOut);//���ѡ�е���
	 CC_SYNTHESIZE(Player*,m_playerOut,PlayerOut);//��ҳ�����
	 CC_SYNTHESIZE(Player*,m_player,Player);//���

	 Player* m_npcOne;//����1
	 Player* m_npcTwo;//����2
	 Player* m_Three;//��ʾ����ʣ����
	 Player* m_npcOneOut;//����1������
	 Player* m_npcTwoOut;//����2������

	 Rule rule;//�ƹ���
	 StructCallPk m_call;//�������� (0 1 2:��� ����1 ����2)
	 int m_callTime;//�����е���
	 int m_outPk;//��ĳ�˳���

	 PkHandType old_handle_pks;//��һ�ѳ���
	 Menu* m_menu;//�е����˵�
	 Menu* m_handle_menu;//���Ʋ˵�
	 Menu* m_success_menu;//�ɹ��˵�
	 Menu* m_lost_menu;//���˲˵�
	 CCLabelTTF* m_lableDiZhu;//������ǩ
	 CCLabelTTF* showScore;//��ʾ���Ʒ���
	 int m_state;//״̬ 0 ���� 1ѡ���� 2����
	 int m_sendPk_num;//���� ���˶�������
	 bool is_split[3];
};