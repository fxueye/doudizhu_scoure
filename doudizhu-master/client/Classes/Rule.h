//��������Ϸ����
#pragma once

#include "cocos2d.h"
#include "Global.h"
#include <vector>

USING_NS_CC;
using namespace  std;

//npc AI �Լ� ��Ϸ�����ж�
struct PkHandleTypeStruct//��������
{
	CARD_TYPE type;
	std::vector<PkStruct> pk_structs;
};

class Rule 
{
public:
	Rule();
	~Rule();

	void InitPks();//��ʼ��
	void Shuffle();//ϴ��
	void GiveDizhuPks(int type);//������
	int Call(int index);//����npc�ǵڼ���
	void AiSplitPks(int type);//��������
	void AiSplitPks(vector<PkStruct> vec_pks);//��������
	int PlayerRule(vector<PkStruct> my_vec_pks,PkHandleTypeStruct pk_handle_type_struct);//����Ƿ�Ϸ�����
	//�ж��Ƿ�Ϸ�����
	bool IsFindPk(PkStruct pk,std::vector<PkHandleTypeStruct> pk_handle);//�����Ƿ��и�pk
	bool IsPlane(vector<PkStruct> vec_pks);//�Ƿ�Ϊ�ɻ�
	bool IsBomb(vector<PkStruct> vec_pks);//�Ƿ�Ϊը�����ƹ���
	bool IsThreeAddNoPk(vector<PkStruct> vec_pks);//�Ƿ�Ϊ������
	bool IsThreeAddOnePk(vector<PkStruct> vec_pks);//�Ƿ�Ϊ����һ
	bool IsThreeAddDoublePk(vector<PkStruct> vec_pks);//�Ƿ�Ϊ����һ��
	bool IsSingleShunzhiPk(vector<PkStruct> vec_pks);//��˳
	bool IsDoubleShunzhiPk(vector<PkStruct> vec_pks);//˫˳
	bool IsThreeShunZhi(vector<PkStruct> vec_pks);//��˳
	bool IsPlaneAddSingleWings(vector<PkStruct> vec_pks);//�ɻ������
	bool IsPlaneAddDoubleWings(vector<PkStruct> vec_pks);//�ɻ������
	bool BombAddSinglePk(vector<PkStruct> vec_pks);//�Ĵ�������
	bool BombAddDoublePk(vector<PkStruct> vec_pks);//�Ĵ���˫��
private:
	int Plane(vector<PkStruct> pData);//�ɻ���1����0
	int Bomb(vector<PkStruct> pData);//ը���м���
	int GetCallBigPks(vector<PkStruct> pData);//��ȡ����2�Ľ��Ʒ���
	static bool SelectShort(const PkStruct& p1,const PkStruct& p2);

	std::vector<PkStruct> AiThreePks(vector<PkHandleTypeStruct> vec_pk_handle_struct_,std::vector<PkStruct> &vec_pks);//��ȡ��˳
	std::vector<PkStruct> AiSingleShunzhi(std::vector<PkStruct> &vec_pks);//��ȡ˳��
	void AiLianDui();//��ȡ����
	void GetOneAiLianDui();//��ȡ���е�һ������
	std::vector<PkStruct> AiDouble(std::vector<PkStruct> &vec_pks);//��ȡ����
	void AiSingle(std::vector<PkStruct> &vec_pks);//���ƻ�ȡ
	void AiHandPksType(std::vector<PkHandleTypeStruct> vec_pk_hand_type_struct);//��������

public:
	std::vector<PkStruct> pks;//������
	std::vector<PkStruct> pks_player;
	std::vector<PkStruct> pks_npc1;
	std::vector<PkStruct> pks_npc2;
	std::vector<PkStruct> pks_three;
	std::vector<PkHandleTypeStruct> vec_pk_hand_type_struct;//�����������
	std::vector<PkHandleTypeStruct> vec_pk_hands;//Ҫ������
};
