#include "MyTextFieldTTF.h"

CCScene* MyTextFieldTTF::scene()
{
	CCScene* scene = CCScene::create();
	MyTextFieldTTF* layer = MyTextFieldTTF::create();
	scene->addChild(layer);
	return scene;
}


bool MyTextFieldTTF::init()
{
	CCLayer::init();
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	text_name = CCTextFieldTTF::textFieldWithPlaceHolder("<click here for name>",
		"Arial", 30);
	//�����ı����λ��
	text_name->setPosition(ccp(winSize.width / 2 - 50, winSize.height / 2+20));
	//����ı��򵽲���
	addChild(text_name);

	text_pwd = CCTextFieldTTF::textFieldWithPlaceHolder("<click here for pwd>",
		"Arial", 30);
	//�����ı����λ��
	text_pwd->setPosition(ccp(winSize.width / 2-50, winSize.height / 2-20));
	//����ı��򵽲���
	addChild(text_pwd);

	//���������ؼ���ʱ�򵯳������
	setTouchMode(kCCTouchesOneByOne);
	setTouchEnabled(true);

	return true;
}
