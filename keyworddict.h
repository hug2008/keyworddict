
#ifndef KEYWORD_DICT_H
#define KEYWORD_DICT_H

#include <stdint.h>

class KeywordNode;
class KeywordDict
{
public :
	KeywordDict();
	~KeywordDict();

public :

	bool init();
	void final();
	
	// ���ӹؼ���
	int32_t add( char * words, int32_t len = 0 );
	
	// ����ַ������Ƿ��йؼ���
	bool check( char * words, int32_t len );

	// ������Ϣ(Ĭ��ÿ���ؼ�����*����, ֱ���޸�Դ�ַ���)
	//		words		- ��Ҫ���˵���Ϣ
	//		len			- ������Ϣ�ĳ���
	int32_t filter( char * words, int32_t len );
	
	// ������Ϣ
	//		src			- ��Ҫ���˵��ַ���
	// 		srclen		- ��Ҫ���˵��ַ�������
	//		dst			- ���˺���ַ���
	//		dstlen		- ��Ź��˺��ַ����Ŀռ䳤��
	// 		replace		- �ؼ�����replace���滻
	//		replacelen	- �滻�ַ����ĳ���
	int32_t filter( char * src, int32_t srclen, char * dst, int32_t dstlen, char * replace, int32_t replacelen );

private :
	
	KeywordNode * find( KeywordNode * node, char c );
	int32_t matching( char * words, int32_t index, int32_t len, int32_t & count );
	void insert( KeywordNode * node, char * words, int32_t len, int32_t index );

private :

	KeywordNode * m_RootNode;
}; 


#endif
