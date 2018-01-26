#include "Rule.h"
#include <iostream>
#include <ctime>
//#include <algorithm>
Rule::Rule(){

}

Rule::~Rule(){

}

void Rule::InitPks(){
	PkStruct struct_;
	for (int i=0;i<4;++i){
		for (int j=0;j<13;++j){
			struct_.pk_type = i;
			struct_.pk_num = j;
			pks.push_back(struct_);
	 
		}
	}

	struct_.pk_type = Joker;
	struct_.pk_num = BlackJoker;
	pks.push_back(struct_);

	struct_.pk_type = Joker;
	struct_.pk_num = RedJoker;
	pks.push_back(struct_);
}

void Rule::Shuffle() {
	srand(unsigned(time(0)));
	for (int i=0;i<54;i++){
		int a = rand()%54;
		int b = rand()%54;
		swap(pks[a],pks[b]);
	}

 
	PkStruct buff;
	for (int i=0;i<51;i++)
	{
		int index = i%3;
	 
		buff.pk_type = pks[i].pk_type;
		buff.pk_num = pks[i].pk_num;

		if (index == 0){
			pks_player.push_back(buff);
		}	

		if (index == 1){
			pks_npc1.push_back(buff);
		}
			
		if (index == 2){
			pks_npc2.push_back(buff);
		}	
	}

	pks_three.push_back( pks[51]);
	pks_three.push_back( pks[52]);
	pks_three.push_back( pks[53]);
}

void Rule::GiveDizhuPks(int type){
	switch (type)
	{
		case 0:
			 pks_player.push_back(pks_three[0]);
			 pks_player.push_back(pks_three[1]);
			 pks_player.push_back(pks_three[2]);
			break;
		case 1:
			pks_npc1.push_back(pks_three[0]);
			pks_npc1.push_back(pks_three[1]);
			pks_npc1.push_back(pks_three[2]);
			break;
		case 2:
			pks_npc2.push_back(pks_three[0]);
			pks_npc2.push_back(pks_three[1]);
			pks_npc2.push_back(pks_three[2]);
			break;
	default:
		break;
	}
}

bool Rule::SelectShort(const PkStruct& p1,const PkStruct& p2){
	return p1.pk_num > p2.pk_num;
}

int Rule::Plane(vector<PkStruct> pData){
	if ( pData[0].pk_num == RedJoker  && pData[1].pk_num == BlackJoker)
	{
		return 1;
	}
	return 0;
}

int Rule::Bomb(vector<PkStruct> pData){
	int count = pData.size();
	int bomb_num = 0;
	int pk_num1 = 0;//�Ƶĸ���
	int pk_num2 = 0;//�Ƶķ���
	for (int i = 0; i < count; i++){
		int buff = pData[i].pk_num;
		if (buff != pk_num2){
			pk_num2 = buff;
		}else{
			pk_num1+=1;
			if (pk_num1 == 4)
			{
				bomb_num+=1;
			}
		}
	}
	return bomb_num;
}

/*
����4�֣�С��3�֣�һ��2Ϊ2��
*/
int Rule::GetCallBigPks(vector<PkStruct> pData){
	int score = 0;
	int count = pData.size();
	for (int i=0;i<count;i++){
		if (pData[i].pk_num == RedJoker){
			score += 4;
		}
		if (pData[i].pk_num == BlackJoker){
			score += 3;
		}
		if (pData[i].pk_num == Er){
			score += 2;
		}
	}
	return score;
}

/*
�ٶ����Ϊ8�֣�ը��Ϊ6�֣�����4�֣�С��3�֣�һ��2Ϊ2�֣��򵱷���
���ڵ���7��ʱ��������
���ڵ���5��ʱ�ж�����
���ڵ���3��ʱ��һ����
С�����ֲ��С�
*/
int Rule::Call(int index){ //�е������� index 0,1,2 ��� npc1,npc2
	int plane_num = 0;
	int bomb_num = 0;
	int extra_num = 0;

	int double_one = 1;
	int double_two = 2;
	int double_three = 3;
	if (index == 0){
		sort(pks_player.begin(),pks_player.end(),Rule::SelectShort);
		plane_num = Plane(pks_player);
		bomb_num = Bomb(pks_player); 
		extra_num = GetCallBigPks(pks_player);
	}

	if (index == 1){
		sort(pks_npc1.begin(),pks_npc1.end(),Rule::SelectShort);
		plane_num = Plane(pks_npc1);
		bomb_num = Bomb(pks_npc1); 
		extra_num = GetCallBigPks(pks_npc1);
	}

	if (index == 2){
		sort(pks_npc2.begin(),pks_npc2.end(),Rule::SelectShort);
		plane_num = Plane(pks_npc2);
		bomb_num = Bomb(pks_npc2); 
		extra_num = GetCallBigPks(pks_npc2);
	}

	int total_score = plane_num*7 + bomb_num*6 + extra_num;
	if (total_score >= 7)
		return double_three;
	else if (total_score >= 5)
		return double_two;
	else if (total_score >= 3)
		return double_one;
	else
	return 0;
}

void Rule::AiSplitPks(std::vector<PkStruct> my_pks){ //0 1 2 ��� npc1 npc2 

	vec_pk_hand_type_struct.clear();
	vec_pk_hands.clear();

	//����
	sort(my_pks.begin(),my_pks.end(),Rule::SelectShort);

	vector<PkHandleTypeStruct> vec_pk_handle_struct_;
	//��ȡ˫��
	if (my_pks[0].pk_type == Joker && my_pks[1].pk_type == Joker){	
		PkHandleTypeStruct pk_handle_typestruct;
		pk_handle_typestruct.type = PLANE_PK;
		pk_handle_typestruct.pk_structs.push_back(my_pks[0]);
		pk_handle_typestruct.pk_structs.push_back(my_pks[1]);
		vec_pk_hand_type_struct.push_back(pk_handle_typestruct);

		my_pks.erase(my_pks.begin());
		my_pks.erase(my_pks.begin());
	}

	//��������
	vector<int> boom_score;
	for (vector<PkStruct>::iterator iter=my_pks.begin();iter!=my_pks.end();iter++) {
		PkHandleTypeStruct pk_handle_typestruct;
		pk_handle_typestruct.pk_structs.push_back(*iter);
		for (vector<PkStruct>::iterator iter_next = iter+1; iter_next != my_pks.end();iter_next++){
			if (iter->pk_num == iter_next->pk_num){
				pk_handle_typestruct.pk_structs.push_back(*iter_next);
				++iter;
			}else{
				break;
			}
		}

		if (pk_handle_typestruct.pk_structs.size() == 4){//��ȡը��
			pk_handle_typestruct.type = BOMB_PK;
			vec_pk_hand_type_struct.push_back(pk_handle_typestruct);
			boom_score.push_back(pk_handle_typestruct.pk_structs[0].pk_num);
			break;
		}

		if (pk_handle_typestruct.pk_structs.size() == 3){ //��ȡ����
			pk_handle_typestruct.type = THREE_NO_ADD_PK;
			vec_pk_handle_struct_.push_back(pk_handle_typestruct);
		}
		if (pk_handle_typestruct.pk_structs.size() == 2)
			pk_handle_typestruct.type = DOUBLE_PK;
		if (pk_handle_typestruct.pk_structs.size() == 1)
			pk_handle_typestruct.type = SINGLE_PK;
	}

	//�Ƴ�ը����ص���
	for (vector<PkStruct>::iterator iter=my_pks.begin();iter!=my_pks.end();iter++) {
		for (std::vector<int>::iterator inter2=boom_score.begin();inter2!=boom_score.end();inter2++){
			if (iter->pk_num == *inter2){
				my_pks.erase(iter);
				iter=my_pks.begin();
				inter2=boom_score.begin();
			}
		}
	}

	//�Ʒ���
	//a) ��ȷ��������ж��Ƿ��д�С����
	//b) ��ȷ��ը���������Ƿ�����ͷ��
	//c) ��ȷ���������ڳ���ը������������ж��Ƿ����������
	//d) ��ȷ����˳�����Ѿ�ȷ�����������ж��Ƿ�������ڵ�����������У����������˳��ע�⣬Ӧ��ʹ��˳�����������ܴ󡣼������444555666������ϳ�һ����˳�������Ƿֳ�444555һ����˳��666һ��������
	//e) ��ȷ����˳���жϵ�˳ʱ����ȥ���ĸ�2���������ը���������ж��Ƿ���ڳ��������ƣ������������ָ���е���������������ƣ�����У�������ȡ��������Σ���ʣ�������ÿһ����������������˳����������ϣ�����ܹ�������ɵ�˳�Ͷ��ӣ���ԭ�е�����ȡ����������ϳ����ƺ͵�˳������4566678�������45678��66������󣬽���֪�����ơ���������������˳����ʣ�µ�����������ϣ���������45678����֪�����ƣ�999��������10J�����ƣ���������ϳ�45678910J��99��ͨ�����ϵķ��������ܽ����ƺ������ܺõ�������ϡ�
	//f) ��ȷ��˫˳�����ȣ��������˳����ȫ�غϣ�����������ϳ�˫˳����Σ��ڳ�ը������˳����������˳��������м���Ƿ����˫˳������У�������ȡ������
	//g) ��ȷ�����ӣ���ը������˳�����������ơ�˫˳��������м���Ƿ���ڶ��ӣ�������ڽ�����ȡ������
	//h) ��ȷ������

	std::vector<PkStruct> pks_erase_three = AiThreePks(vec_pk_handle_struct_,my_pks);//��ȡ3��

	std::vector<PkStruct> pks_erase_shunzi = AiSingleShunzhi(pks_erase_three);//��ȡ����

	std::vector<PkStruct> pks_erase_double = AiDouble(pks_erase_shunzi);//��ȡ����

	AiLianDui();

	AiSingle(pks_erase_double);//����

	//����
	AiHandPksType(vec_pk_hand_type_struct);

}

//��ȡ����һ������
std::vector<PkStruct> Rule::AiThreePks(vector<PkHandleTypeStruct> vec_pk_handle_struct_,std::vector<PkStruct> &vec_pks){
	if (vec_pk_handle_struct_.size() == 0)
		return vec_pks;
	if (vec_pk_handle_struct_.size() == 1)
	{
		vec_pk_hand_type_struct.push_back(vec_pk_handle_struct_[0]);
	}

	//�ϲ���˳
	PkHandleTypeStruct pk_handle_type_struct_;
	int oldScore = 0;
	if (vec_pk_handle_struct_.size() >= 2){
		for (vector<PkHandleTypeStruct>::iterator iter = vec_pk_handle_struct_.begin();iter!= vec_pk_handle_struct_.end();iter++){
			oldScore = iter->pk_structs[0].pk_num;
			pk_handle_type_struct_= *iter;
			for (vector<PkHandleTypeStruct>::iterator iter2 = iter+1;iter2!= vec_pk_handle_struct_.end();iter2++){
				if (oldScore-1 == iter2->pk_structs[0].pk_num && (iter2->pk_structs[0].pk_num < Er && oldScore < Er)){
					oldScore = iter2->pk_structs[0].pk_num;
					pk_handle_type_struct_.type = THREE_SHUNZHI_PK;
					for (int i=0;i<3;i++){
						pk_handle_type_struct_.pk_structs.push_back(iter2->pk_structs[i]);
					}
					++iter;
				}
			}
			vec_pk_hand_type_struct.push_back(pk_handle_type_struct_);
		}
	}

	//�Ƴ�������
	for (vector<PkStruct>::iterator inter = vec_pks.begin();inter != vec_pks.end();inter++){
		for (vector<PkHandleTypeStruct>::iterator inter2 = vec_pk_handle_struct_.begin();inter2 != vec_pk_handle_struct_.end();inter2++){
			for (vector<PkStruct>::iterator inter3 = inter2->pk_structs.begin();inter3 != inter2->pk_structs.end();)
			{
				if ( inter->pk_type == inter3->pk_type  && inter->pk_num == inter3->pk_num){
					inter = vec_pks.erase(inter);
					inter2 = vec_pk_handle_struct_.begin();
					inter3 = inter2->pk_structs.begin();
					if (inter == vec_pks.end())
					{
						return vec_pks;
					}
				}else{
					inter3++;
				}
			}
			
		}
	}

	return vec_pks;

}

void Rule::AiSplitPks(int type){ //0 1 2 ��� npc1 npc2 

	vec_pk_hand_type_struct.clear();
	vec_pk_hands.clear();

	std::vector<PkStruct> my_pks;
	switch (type)
	{
	case 0:
		for (vector<PkStruct>::iterator iter=pks_player.begin();iter!=pks_player.end();iter++) {
			my_pks.push_back(*iter);
		}
		break;
	case 1:
		for (vector<PkStruct>::iterator iter=pks_npc1.begin();iter!=pks_npc1.end();iter++) {
			my_pks.push_back(*iter);
		}
		break;
	case 2:
		for (vector<PkStruct>::iterator iter=pks_npc2.begin();iter!=pks_npc2.end();iter++) {
			my_pks.push_back(*iter);
		}
		break;
	default:
		break;
	}

	AiSplitPks(my_pks);
}


//��ȡ˳��
std::vector<PkStruct> Rule::AiSingleShunzhi(std::vector<PkStruct> &vec_pks){
	if (vec_pks.size() < 5){
		return vec_pks;
	}

	std::vector<PkHandleTypeStruct> vec_pk_hand_type_struct_;

	//��˳��ȡ
	for (std::vector<PkStruct>::iterator inter = vec_pks.begin();inter!=vec_pks.end();inter++){
		PkHandleTypeStruct result;
		if (inter->pk_num == Er || inter->pk_type == Joker){
			continue;
		}

		result.type = SINGLE_SHUNZHI_PK;
		result.pk_structs.push_back(*inter);
		int single_num = 1;

		if (inter+1 == vec_pks.end()){
			break;
		}
		for (std::vector<PkStruct>::iterator inter2 = inter+1;inter2!=vec_pks.end();++inter2){
			if (inter2->pk_num == inter->pk_num){

				if (inter2+1 == vec_pks.end()){
					break;
				}
				++inter2;
				++inter;
			}

			if ( (inter->pk_num)-1 == inter2->pk_num){
				++inter;
				++single_num;
				result.pk_structs.push_back(*inter2);
				if (single_num == 5){
					vec_pk_hand_type_struct_.push_back(result);
				}
			}else {
				break;
			}
		}
	}

	//�Ƴ�˳���е���
	for (std::vector<PkStruct>::iterator inter = vec_pks.begin();inter!=vec_pks.end();){
		bool result = IsFindPk(*inter,vec_pk_hand_type_struct_);
		if (result)
		{
			inter = vec_pks.erase(inter);
		}else
		{
			inter++;
		}
	}

	//��չ˳��
	for (std::vector<PkStruct>::iterator inter = vec_pks.begin();inter!=vec_pks.end();inter++){
		bool is_add_extra = false;
		sort(pks_npc1.begin(),pks_npc1.end(),Rule::SelectShort);

		if (inter->pk_num == Er || inter->pk_type == Joker){
			continue;
		}

		for (std::vector<PkHandleTypeStruct>::iterator inter2=vec_pk_hand_type_struct_.begin();inter2!=vec_pk_hand_type_struct_.end();inter2++){
			if (inter->pk_num-1 == inter2->pk_structs[0].pk_num){//��չ���
				inter2->pk_structs.insert(inter2->pk_structs.begin(),*inter);
				is_add_extra = true;
				break;
			}

			int len = inter2->pk_structs.size();
			if (inter->pk_num+1 == inter2->pk_structs[len-1].pk_num){ //��չ�ұ�
				inter2->pk_structs.push_back(*inter);
				is_add_extra = true;
				break;
			}
		} 


		if (is_add_extra)//���õ�����
		{
			vec_pks.erase(inter);
			inter = vec_pks.begin();
		}
	}

	//�ϲ�˳��
	if (vec_pk_hand_type_struct_.size() == 2){
		if (vec_pk_hand_type_struct_[0].pk_structs.size() == vec_pk_hand_type_struct_[1].pk_structs.size())
		{
			int len = vec_pk_hand_type_struct_[0].pk_structs.size();
			if ( vec_pk_hand_type_struct_[0].pk_structs[0].pk_num == vec_pk_hand_type_struct_[1].pk_structs[0].pk_num  && vec_pk_hand_type_struct_[0].pk_structs[len-1].pk_num == vec_pk_hand_type_struct_[1].pk_structs[len-1].pk_num  ){
				for (std::vector<PkStruct>::iterator inter = vec_pk_hand_type_struct_[1].pk_structs.begin();inter!=vec_pk_hand_type_struct_[1].pk_structs.end();inter++){
					vec_pk_hand_type_struct_[0].pk_structs.push_back(*inter);
				}
				vec_pk_hand_type_struct_[0].type = DOUBLE_SHUNZHI_PK;
				vec_pk_hand_type_struct_.erase(vec_pk_hand_type_struct_.end());
			}
		}
	}
	 
	//��ֵ
	for (std::vector<PkHandleTypeStruct>::iterator inter=vec_pk_hand_type_struct_.begin();inter!=vec_pk_hand_type_struct_.end();inter++){
		vec_pk_hand_type_struct.push_back(*inter);
	}
	
	return vec_pks;
}

bool Rule::IsFindPk(PkStruct pk,std::vector<PkHandleTypeStruct> vec_pk_hand_type_struct_){
	for (std::vector<PkHandleTypeStruct>::iterator inter2=vec_pk_hand_type_struct_.begin();inter2!=vec_pk_hand_type_struct_.end();inter2++){
		for (std::vector<PkStruct>::iterator inter3 = inter2->pk_structs.begin();inter3 != inter2->pk_structs.end();inter3++){
			if (pk.pk_num == inter3->pk_num && pk.pk_type == inter3->pk_type){
				return true;
			}
		}
	}
	return false;
}

void Rule::AiLianDui(){
	for (int i=0;i<3;i++)//���Ϊ3������
	{
		GetOneAiLianDui();
	}
}

void Rule::GetOneAiLianDui(){
	int count = 0;
	int pk_num_old = 0;
	PkHandleTypeStruct buff;
	buff.type = DOUBLE_SHUNZHI_PK;

	for (std::vector<PkHandleTypeStruct>::iterator iter = vec_pk_hand_type_struct.begin();iter != vec_pk_hand_type_struct.end();iter++){
		if (iter->type == DOUBLE_PK){

			if (iter->pk_structs[0].pk_num >= Er)
				continue;

			if (count == 0)
			{
				pk_num_old = iter->pk_structs[0].pk_num;
				buff.pk_structs.push_back(iter->pk_structs[0]);
				buff.pk_structs.push_back(iter->pk_structs[1]);
				count = 1;
			}else{
				if (pk_num_old - 1 == iter->pk_structs[0].pk_num){
					count+=1;
					pk_num_old = iter->pk_structs[0].pk_num;
					buff.pk_structs.push_back(iter->pk_structs[0]);
					buff.pk_structs.push_back(iter->pk_structs[1]);
				}else{
					if (count >= 3)
					{
						count = 0;
						vec_pk_hand_type_struct.push_back(buff);
						break;
					}else{
						count = 1;
						pk_num_old = iter->pk_structs[0].pk_num;
						buff.pk_structs.clear();
						buff.pk_structs.push_back(iter->pk_structs[0]);
						buff.pk_structs.push_back(iter->pk_structs[1]);
					}
				}
			}
		}
	}

	//һֱ�������
	if (count >= 3)
	{
		vec_pk_hand_type_struct.push_back(buff);
	}

	if (buff.pk_structs.size() < 6)
	{
		return;
	}

	//ɾ����ȡ�������
	for (std::vector<PkStruct>::iterator iter = buff.pk_structs.begin();iter != buff.pk_structs.end();iter++){
		for (std::vector<PkHandleTypeStruct>::iterator iter2 = vec_pk_hand_type_struct.begin();iter2 != vec_pk_hand_type_struct.end();){
			if (iter2->type == DOUBLE_PK){
				if (iter2->pk_structs[0].pk_num == iter->pk_num){
					iter2 = vec_pk_hand_type_struct.erase(iter2);
				}else{
					iter2++;
				}
			}else{
				iter2++;
			}
		}
	}

}

//��ȡ����
std::vector<PkStruct> Rule::AiDouble(std::vector<PkStruct> &vec_pks){

	for (std::vector<PkStruct>::iterator inter = vec_pks.begin();inter!=vec_pks.end();){

		bool is_can_add = false;
		if (inter+1 == vec_pks.end()){
			break;
		}

		for (std::vector<PkStruct>::iterator inter2 = inter+1;inter2!=vec_pks.end();){
			if (inter->pk_num == inter2->pk_num){
				PkHandleTypeStruct type_struct;
				type_struct.type = DOUBLE_PK;
				type_struct.pk_structs.push_back(*inter);
				type_struct.pk_structs.push_back(*inter2);
				vec_pk_hand_type_struct.push_back(type_struct);
				
				inter2 = vec_pks.erase(inter2);
				inter = vec_pks.erase(inter);
				is_can_add = true;
				break;
			}else{
				inter2++;
			}
		}

		if (!is_can_add){
			++inter;
		}
	}
	
	return vec_pks;
}

//��ȡ����
void Rule::AiSingle(std::vector<PkStruct> &vec_pks){
	for (std::vector<PkStruct>::iterator inter = vec_pks.begin();inter!=vec_pks.end();inter++){
		PkHandleTypeStruct type_struct;
		type_struct.type = SINGLE_PK;
		type_struct.pk_structs.push_back(*inter);
		vec_pk_hand_type_struct.push_back(type_struct);
	}
}

//AIҪ������
void Rule::AiHandPksType(std::vector<PkHandleTypeStruct> vec_pk_hand_type_struct){
	std::vector<PkHandleTypeStruct> bomb_vec;
	std::vector<PkHandleTypeStruct> three_vec;
	std::vector<PkHandleTypeStruct> single_vec;
	std::vector<PkHandleTypeStruct> double_vec;
	std::vector<PkHandleTypeStruct> three_shunzhi_vec; 


	reverse(vec_pk_hand_type_struct.begin(),vec_pk_hand_type_struct.end());
	
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();){
		bool is_next = false;
		//�ɻ� ˫˳ ��˳
		if (inter->type == PLANE_PK || inter->type == DOUBLE_SHUNZHI_PK || inter->type == SINGLE_SHUNZHI_PK ){
			vec_pk_hands.push_back(*inter);
			inter = vec_pk_hand_type_struct.erase(inter);
			if (inter == vec_pk_hand_type_struct.end())
			{
				break;
			}
		}

		//ը��
		if (inter->type == BOMB_PK){
			bomb_vec.push_back(*inter);
			inter = vec_pk_hand_type_struct.erase(inter);
			if (inter == vec_pk_hand_type_struct.end())
			{
				break;
			}
		}

		//������
		if (inter->type == THREE_NO_ADD_PK){
			three_vec.push_back(*inter);
			inter = vec_pk_hand_type_struct.erase(inter);
			if (inter == vec_pk_hand_type_struct.end())
			{
				break;
			}
		}
		
		//����
		if (inter->type == SINGLE_PK){
			if (inter->pk_structs[0].pk_num < Er)
			{
				single_vec.push_back(*inter);
				inter = vec_pk_hand_type_struct.erase(inter);
				if (inter == vec_pk_hand_type_struct.end())
				{
					break;
				}
			}else{
				is_next = true;
			}		
		}
		
		//˫��
		if (inter->type == DOUBLE_PK){
			if (inter->pk_structs[0].pk_num < Er)
			{
				double_vec.push_back(*inter);
				inter = vec_pk_hand_type_struct.erase(inter);
				if (inter == vec_pk_hand_type_struct.end())
				{
					break;
				}
			}else{
				is_next = true;
			}
		}
		
		//����
		if (inter->type == THREE_SHUNZHI_PK){
			three_shunzhi_vec.push_back(*inter);
			inter = vec_pk_hand_type_struct.erase(inter);
			if (inter == vec_pk_hand_type_struct.end())
			{
				break;
			}
		}	

		if (is_next)
		{
			++inter;
		}
	}

	//�ɻ������ 
	for (int i=0;i<three_shunzhi_vec.size();i++){
		int three_num = three_shunzhi_vec[i].pk_structs.size()/3;

		if (single_vec.size() >= three_num || double_vec.size() >= three_num)//�����˫���������Ҫ��
		{
			if( single_vec.size() >= double_vec.size() ){
					//�����ƿ�����three_shunzhi_vec��
					for(int j=0;j<three_num;j++){
						three_shunzhi_vec[i].type = PLANE_ADD_WINGS_SINGLE_PK;
						three_shunzhi_vec[i].pk_structs.push_back(single_vec[j].pk_structs[0]);
					}

				}else{
					//�����ӿ�����three_shunzhi_vec��
					for(int j=0;j<three_num;j++){
						three_shunzhi_vec[i].type = PLANE_ADD_WINGS_DOUBLE_PK;
						three_shunzhi_vec[i].pk_structs.push_back(double_vec[j].pk_structs[0]);
					}
				}
				//�Ƴ�����
				for (int k=0;k<three_num;k++)
					single_vec.erase(single_vec.begin());
		}

		else if (single_vec.size() + double_vec.size()*2 > three_num){
			int a = (three_num-single_vec.size()) % 2;
			int b = (three_num-single_vec.size()) / 2;

			//������
			if (a == 1){
				for(int k=0;k<(single_vec.size()-1);k++){
					three_shunzhi_vec[i].type = PLANE_ADD_WINGS_SINGLE_PK;
					three_shunzhi_vec[i].pk_structs.push_back(single_vec[k].pk_structs[0]);
				}
			}

			//��˫��
			for(int j=0;j<= b;j++){
				three_shunzhi_vec[i].type = PLANE_ADD_WINGS_SINGLE_PK;
				three_shunzhi_vec[i].pk_structs.push_back(double_vec[j].pk_structs[0]);
				three_shunzhi_vec[i].pk_structs.push_back(double_vec[j].pk_structs[1]);
			}

			//�Ƴ�����
			if (a == 1){
				PkHandleTypeStruct buff_struct = *single_vec.end();
				single_vec.clear();
				single_vec.push_back(buff_struct);
			}else{
				single_vec.clear();
			}

			//�Ƴ�˫��
			for (int i=0;i<= b;i++)
				double_vec.erase(double_vec.begin());
		}
		vec_pk_hands.push_back(three_shunzhi_vec[i]);
	}
	//����һ
	for (std::vector<PkHandleTypeStruct>::iterator iter = three_vec.begin();iter != three_vec.end();iter++){
		//�����ƻ���˫��
		bool is_add_single = false;
		bool is_add_double = false;

		if (single_vec.size() > 0 && double_vec.size() > 0){
			is_add_double = true;
			is_add_single = true;
		}

		if (single_vec.size() > 0 && double_vec.size() ==  0)
		{
			is_add_single = true;
		}
		if (single_vec.size() == 0 && double_vec.size() >  0)
		{
			is_add_double = true;
		}

		//����˫�ƶ����Դ���
		if ( is_add_double &&  is_add_single)
		{
			if (single_vec[0].pk_structs[0].pk_num < double_vec[0].pk_structs[0].pk_num)
			{
				iter->pk_structs.push_back(single_vec[0].pk_structs[0]);
				single_vec.erase(single_vec.begin());
				iter->type = THREE_ONE_PK;
				vec_pk_hands.push_back(*iter);

			}else{
				iter->pk_structs.push_back(double_vec[0].pk_structs[0]);
				iter->pk_structs.push_back(double_vec[0].pk_structs[1]);
				double_vec.erase(double_vec.begin());
				iter->type = THREE_DOUBLE_PK;
				vec_pk_hands.push_back(*iter);
			}
		}
		//ֻ�ܴ�����
		if (is_add_single && !is_add_double)
		{
			iter->pk_structs.push_back(single_vec[0].pk_structs[0]);
			single_vec.erase(single_vec.begin());
			iter->type = THREE_ONE_PK;
			vec_pk_hands.push_back(*iter);
		}
		//ֻ�ܴ�˫��
		if (!is_add_single && is_add_double)
		{
			iter->pk_structs.push_back(double_vec[0].pk_structs[0]);
			iter->pk_structs.push_back(double_vec[0].pk_structs[1]);
			double_vec.erase(double_vec.begin());
			iter->type = THREE_DOUBLE_PK;
			vec_pk_hands.push_back(*iter);
		}
		//������
		if (!is_add_single && !is_add_double)
		{
			vec_pk_hands.push_back(*iter);
		}
	}
	
	//�ж�ը�����ƻ�������
	for (int i=0;i<bomb_vec.size();i++){
		if (single_vec.size() + double_vec.size() >= 4){
			if (double_vec.size() >= 2 && single_vec.size() >= 2)
			{
				if( double_vec[0].pk_structs[0].pk_num >  single_vec[0].pk_structs[0].pk_num){
					bomb_vec[i].type = BOMB_TWO_PK;
					bomb_vec[i].pk_structs.push_back(single_vec[0].pk_structs[0]);
					bomb_vec[i].pk_structs.push_back(single_vec[1].pk_structs[0]);
					single_vec.erase(single_vec.begin());
					single_vec.erase(single_vec.begin());
				}else  
				{
					bomb_vec[i].type = BOMB_DOUBLE_TWO_PK;
					bomb_vec[i].pk_structs.push_back(double_vec[0].pk_structs[0]);
					bomb_vec[i].pk_structs.push_back(double_vec[0].pk_structs[1]);
					bomb_vec[i].pk_structs.push_back(double_vec[1].pk_structs[0]);
					bomb_vec[i].pk_structs.push_back(double_vec[1].pk_structs[1]);
					double_vec.erase(double_vec.begin());
					double_vec.erase(double_vec.begin());
				}
			}
		}
		vec_pk_hands.push_back(bomb_vec[i]);
	}

	//��ʣ�������ӵ�handle vector ��
	int single_len = single_vec.size()-1;
	int double_len = double_vec.size()-1;
	
	for (int i=0;i<=double_len;i++)
		vec_pk_hands.push_back(double_vec[double_len - i]);

	for (int i=0;i<=single_len;i++)
		vec_pk_hands.push_back(single_vec[single_len - i]);

	reverse(vec_pk_hands.begin(),vec_pk_hands.end());

	//������ �� 2��ӽ���
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->pk_structs[0].pk_num >= Er)
			vec_pk_hands.push_back(*inter);
	}
}


//�ɻ�
bool Rule::IsPlane(vector<PkStruct> vec_pks){
	if (vec_pks.size() != 2)
		return false;

	if(vec_pks[0].pk_type ==Joker && vec_pks[0].pk_type == Joker)
		return true;
	return false;
}

//ը��
bool  Rule::IsBomb(vector<PkStruct> vec_pks){
	if (vec_pks.size() != 4)
		return false;

	AiSplitPks(vec_pks);
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == BOMB_PK)
			return true;
	}
	return false;
}

//�Ƿ�Ϊ������
bool Rule::IsThreeAddNoPk(vector<PkStruct> vec_pks){
	if (vec_pks.size() != 3)
		return false;

	AiSplitPks(vec_pks);
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == THREE_NO_ADD_PK)
			return true;
	}
	return false;
}

//�Ƿ�Ϊ����һ
bool Rule::IsThreeAddOnePk(vector<PkStruct> vec_pks){
	if (vec_pks.size() != 4)
	{
		return false;
	}

	AiSplitPks(vec_pks);
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == THREE_NO_ADD_PK){
			return true;
		}	
	}
	return false;
}

//�Ƿ�Ϊ����һ��
bool Rule::IsThreeAddDoublePk(vector<PkStruct> vec_pks) {
	if ( vec_pks.size() != 5 ){
		return false;
	}

	AiSplitPks(vec_pks);
	bool is_bomb = false;
	int double_num = 0;
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == THREE_NO_ADD_PK){
			is_bomb = true;
		}
		else if (inter->type == DOUBLE_PK){
			++double_num;
		}
	}

	if (is_bomb && double_num == 1)
	{
		return true;
	}

	return false;
}

//��˳ 1 2 3 4 5
bool Rule::IsSingleShunzhiPk(vector<PkStruct> vec_pks){
	if ( vec_pks.size() < 5 ){
		return false;
	}

	AiSplitPks(vec_pks);
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == SINGLE_SHUNZHI_PK){
			return true;
		} 
	}

	return false;
}

//˫˳ 33 44 55
bool Rule::IsDoubleShunzhiPk(vector<PkStruct> vec_pks){
	if ( vec_pks.size() < 6){
		return false;
	}

	AiSplitPks(vec_pks);
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == DOUBLE_SHUNZHI_PK){
			return true;
		} 
	}
	return false;
}
	
//��˳
bool Rule::IsThreeShunZhi(vector<PkStruct> vec_pks){
	if (vec_pks.size() < 6){
		return false;
	}

	AiSplitPks(vec_pks);
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == THREE_SHUNZHI_PK){
			return true;
		} 
	}
	return false;
}

//�ɻ������ ��
bool Rule::IsPlaneAddSingleWings(vector<PkStruct> vec_pks){
	if (vec_pks.size() < 6)
		return false;

	int single_num =0;
	int plane_num = 0;
	bool is_plane = false;
	AiSplitPks(vec_pks);

	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == THREE_SHUNZHI_PK){
			plane_num  = inter->pk_structs.size()/3;
			is_plane = true;
		}
		else if (inter->type == SINGLE_PK)
			single_num += 1;
	}

	if (is_plane && (plane_num ==single_num))
		return true;
	return false;
}



//�ɻ������ ˫
bool Rule::IsPlaneAddDoubleWings(vector<PkStruct> vec_pks){
	if (vec_pks.size() < 8)
		return false;

	int double_num =0;
	int plane_num = 0;
	bool is_plane = false;
	AiSplitPks(vec_pks);

	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == BOMB_PK){
			plane_num  = inter->pk_structs.size()/3;
			is_plane = true;
		}
		else if (inter->type == DOUBLE_PK)
			double_num += 1;
	}

	if (is_plane && (plane_num ==double_num))
		return true;
	return false;
}

//�Ĵ��� ��
bool Rule::BombAddSinglePk(vector<PkStruct> vec_pks){
	if ( (vec_pks.size() != 6) )
		return false;

	AiSplitPks(vec_pks);
	bool is_bomb = false;
	int single_num = 0;
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == BOMB_PK){
			is_bomb = true;
		}else if(inter->type == SINGLE_PK){
			++single_num;
		}
	}

	if (is_bomb && (single_num == 2))
		return true;

	return false;
}

//�Ĵ��� ˫
bool Rule::BombAddDoublePk(vector<PkStruct> vec_pks){
	if ( (vec_pks.size() != 10) )
		return false;

	AiSplitPks(vec_pks);
	bool is_bomb = false;
	int double_num = 0;
	for (std::vector<PkHandleTypeStruct>::iterator inter = vec_pk_hand_type_struct.begin();inter!=vec_pk_hand_type_struct.end();inter++){
		if (inter->type == BOMB_PK){
			is_bomb = true;
		}else if(inter->type == DOUBLE_PK){
			++double_num;
		}
	}

	if (is_bomb && (double_num == 2))
		return true;

	return false;
}

int Rule::PlayerRule(vector<PkStruct> my_vec_pks,PkHandleTypeStruct pk_handle_type_struct){
	bool is_find = false;

	if (pk_handle_type_struct.pk_structs.size() == 0)
	{
		bool is_bomb = false;
		bool is_single = false;
		bool is_double = false;
		bool is_three_no_add = false;
		bool is_three_add_one = false;
		bool is_three_add_double = false;
		bool is_single_shunzhi = false;
		bool is_double_shunzhi =false;
		bool is_three_shunzhi = false;
		bool is_plane_add_single = false;
		bool is_plane_add_double = false;
		bool is_bomb_add_two_single = false;
		bool is_bomb_add_two_double = false;

		is_bomb = IsBomb(my_vec_pks);
		if (is_bomb)
		{
			return BOMB_PK;
		}

		if (my_vec_pks.size() == 1)
			is_single = true;
		if (is_single)
		{
			return SINGLE_PK;
		}

		if (my_vec_pks.size() == 2 && (my_vec_pks[0].pk_num == my_vec_pks[1].pk_num) )
			is_double = true;
		if (is_double )
		{
			return DOUBLE_PK;
		}

		is_three_no_add = IsThreeAddNoPk(my_vec_pks);
		if (is_three_no_add)
		{
			return THREE_NO_ADD_PK;
		}

		is_three_add_one = IsThreeAddOnePk(my_vec_pks);
		if (is_three_add_one)
		{
			return THREE_ONE_PK;
		}

		is_three_add_double = IsThreeAddDoublePk(my_vec_pks);
		if (is_three_add_double)
		{
			return THREE_DOUBLE_PK;
		}

		is_single_shunzhi = IsSingleShunzhiPk(my_vec_pks);
		if (is_single_shunzhi)
		{
			return SINGLE_SHUNZHI_PK;
		}

		is_double_shunzhi = IsDoubleShunzhiPk(my_vec_pks);
		if (is_double_shunzhi)
		{
			return DOUBLE_SHUNZHI_PK;
		}

		is_three_shunzhi = IsThreeShunZhi(my_vec_pks);
		if (is_three_shunzhi)
		{
			return THREE_SHUNZHI_PK;
		}

		is_plane_add_single = IsPlaneAddSingleWings(my_vec_pks);
		if (is_plane_add_single)
		{
			return PLANE_ADD_WINGS_SINGLE_PK;
		}

		is_plane_add_double = IsPlaneAddDoubleWings(my_vec_pks);
		if (is_plane_add_double)
		{
			return PLANE_ADD_WINGS_DOUBLE_PK;
		}

		is_bomb_add_two_single = BombAddSinglePk(my_vec_pks);
		if (is_bomb_add_two_single)
		{
			return BOMB_TWO_PK;
		}

		is_bomb_add_two_double = BombAddDoublePk(my_vec_pks);
		if (is_bomb_add_two_double)
		{
			return BOMB_DOUBLE_TWO_PK;
		}
		
	}else{

		switch (pk_handle_type_struct.type)
		{
		case BOMB_PK://ը��
			is_find = IsBomb(my_vec_pks);
			if (is_find)
			{
				if (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num)
					return BOMB_PK;
			}
			break;

		case SINGLE_PK://����
			if (my_vec_pks.size() == 1 && pk_handle_type_struct.pk_structs.size() == 1)
			{
				if (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num)
					return SINGLE_PK;
			}
			break;

		case DOUBLE_PK://˫��
			if (my_vec_pks.size() == 2 && pk_handle_type_struct.pk_structs.size() == 2)
			{
				if ( (my_vec_pks[0].pk_num == my_vec_pks[1].pk_num) && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
					return DOUBLE_PK;
			}
			break;

		case THREE_NO_ADD_PK://�ж�������
			is_find = IsThreeAddNoPk(my_vec_pks);
			if (is_find && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
				return THREE_NO_ADD_PK;
			break;
		case THREE_ONE_PK://�ж�����һ
			is_find = IsThreeAddOnePk(my_vec_pks);
			if (is_find && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
				return true;
			break;

		case THREE_DOUBLE_PK://�ж�����һ��
			is_find = IsThreeAddDoublePk(my_vec_pks);
			if (is_find && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
				return THREE_ONE_PK;
			break;

		case SINGLE_SHUNZHI_PK://�ж��Ƿ�Ϊ����
			is_find = IsSingleShunzhiPk(my_vec_pks);
			if (is_find && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
				return SINGLE_SHUNZHI_PK;
			break;
		case DOUBLE_SHUNZHI_PK://˫��
			is_find = IsDoubleShunzhiPk(my_vec_pks);
			if (is_find && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
				return DOUBLE_SHUNZHI_PK;
			break;
		case THREE_SHUNZHI_PK://��˳
			is_find = IsThreeShunZhi(my_vec_pks);
			if (is_find && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
				return THREE_SHUNZHI_PK;
			break;
		case PLANE_ADD_WINGS_SINGLE_PK://�ɻ��������
			is_find = IsPlaneAddSingleWings(my_vec_pks);
			if (is_find && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
				return PLANE_ADD_WINGS_SINGLE_PK;
			break;
		case PLANE_ADD_WINGS_DOUBLE_PK://�ɻ���˫���
			is_find = IsPlaneAddDoubleWings(my_vec_pks);
			if (is_find && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
				return PLANE_ADD_WINGS_DOUBLE_PK;
			break;
		case BOMB_TWO_PK://�Ĵ�������
			is_find = BombAddSinglePk(my_vec_pks);
			if (is_find && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
				return BOMB_TWO_PK;
			break;
		case BOMB_DOUBLE_TWO_PK://�Ĵ���˫��
			is_find = BombAddDoublePk(my_vec_pks);
			if (is_find && (my_vec_pks[0].pk_num > pk_handle_type_struct.pk_structs[0].pk_num) )
				return BOMB_DOUBLE_TWO_PK;
			break;

		default:
			break;
		}

		//��ը��
		if (pk_handle_type_struct.type != PLANE_PK || pk_handle_type_struct.type != BOMB_PK){
			is_find = IsBomb(my_vec_pks);
			if (is_find)
				return BOMB_PK;

			is_find = IsPlane(my_vec_pks);
			if (is_find)
				return PLANE_PK;
			
			return ERROR_PK;
		}
	}

	return ERROR_PK;
 
}

	
 