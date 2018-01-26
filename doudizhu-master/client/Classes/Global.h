#pragma once
#include <vector>
#include "MySocket.h"

using namespace std;
const int pkWidth = 71;//�ƵĿ��
const int pkHeight = 96;//�Ƶĸ߶�
const int pkDistance = 20;//�����Ƶļ��
const int pkTopHeight = 10;//�Ƶ�������ƶ�����
const int menu_score_top = 88;//�з�����λ�ø߶�
const int menu_score_distance = 20;//�зּ��


//��ɫ
enum PKType
{
	Spade = 0,//����
	Heart,//����
	Club,//÷��
	Dianmond,//����
	Joker,//��
	PKBack = 4,//��ɫ����
};

enum PKNum {
	Num = 0,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,Ace,Er,BlackJoker,RedJoker,
	PkBackNum = 2 //��������ͼƬλ��
};

enum Table {
	Score,
	NpcOneNotPlay,
	NpcTwoNotPlay
};

enum CARD_TYPE{
	PLANE_PK = 1,			//�ɻ�
	BOMB_PK,				//ը��
	SINGLE_PK,				//����
	DOUBLE_PK,				//˫��
	THREE_NO_ADD_PK,		//3����
	THREE_ONE_PK,			//3��1-
	THREE_DOUBLE_PK,		//3��2-
	SINGLE_SHUNZHI_PK,		//����
	DOUBLE_SHUNZHI_PK,      //˫��
	THREE_SHUNZHI_PK,       //����
	PLANE_ADD_WINGS_SINGLE_PK,//�ɻ������
	PLANE_ADD_WINGS_DOUBLE_PK,//�ɻ������
	BOMB_TWO_PK,			//�ĸ���2�ŵ���
	BOMB_DOUBLE_TWO_PK,		//�ĸ���2��
	ERROR_PK				//���������
};


enum PLAYER_HANDLE_TYPE //�������:0Ϊ������ڵ��ƣ�1Ϊ�����У�2Ϊ��ʾ��������,3Ϊ���Ҫ�����ƣ�4Ϊ����1Ҫ�����ƣ�5Ϊ����2Ҫ������
{
	PLAYER_ARRAY_PK = 0,
	COMPUTER_ARRAY_PK,
	THREE_PK,
	PLAYER_HAND_PK,
	COMPUTER_1_HANDLE_PK,
	COMPUTER_2_HANDLE_PK
};


enum SCORE{
	score_zero,
	score_one ,
	score_two,
	score_three
};
struct AIR_ADD_CARD_TYPE //�ɻ�����
{
	std::vector<int> single_card;//����
	std::vector<int> double_card;//˫��
	std::vector<int> three_card;//����
	std::vector<int> four_card;//����
};

struct StructCallPk
{
	int People;
	int CallScore;
};

struct PkStruct //�� ���� ��С
{
	int pk_type;
	int pk_num;
};

enum TypeId{
	GetTypeID = 0,
	LoginInfoID = 1,
	RegisterInfoID = 2,
	RequestID = 3,
	ResultChatMsgID = 4,
	ResultInfoID = 5,
};

enum Result{
	REGISTERSUCCESS = 0, //ע��ɹ�
	REGISTERERROR   = 1, //ע�����
	LOGINERROR      = 2, //��½����
	PASSWDERROR     = 3, //�������
	SAMENICK        = 4, //ע��������ͬ
	LOGINSUCCESS    = 5, //��½�ɹ�
};