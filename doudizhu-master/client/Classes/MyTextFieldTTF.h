#ifndef __TextFieldTTF_H__
#define __TextFieldTTF_H__

#include "cocos2d.h"
USING_NS_CC;

class MyTextFieldTTF : public CCLayer
{
public:
	bool init();  

	static CCScene* scene();

	//�����ڳ����д���һ���ı��ؼ�
	CCTextFieldTTF* text_name;
	CCTextFieldTTF* text_pwd;

	CREATE_FUNC(MyTextFieldTTF);
};

#endif // __HELLOWORLD_SCENE_H__
