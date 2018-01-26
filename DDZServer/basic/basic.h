////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2099, TQ Digital Entertainment, All Rights Reserved
// Author��  zhu
// Created�� 2017/07/10
// Describe��
////////////////////////////////////////////////////////////////////////

#ifndef BASIC_H
#define BASIC_H

//���Զ�λ�������ڴ�й¶ ���ڵ��ļ��;�����һ�У����ڼ�� malloc ������ڴ�  
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG //����new��������ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#define NEW  new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define NEW  new
#endif

#include "Exception.h"
#include "GameLog.h"

#define SAFE_DELETE(p)  if (p) { delete p; p = NULL;}
#define SAFE_DELETE_ARRAY(p)  if (p) { delete [] p; p = NULL;}

#endif