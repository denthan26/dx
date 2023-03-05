//�����

#include"GenList.h"

//�����ĳ�ʼ��
void InitGenList(GenList& gl)
{
	gl = NULL;
}

//char *ga = "(1,2,3)";
//char *gb = "(1,(2,3))";
//char *gc = "(1,(2),3)";
//char *gd = "((1,2),3)";
//char *gd = "((1,2,3))";
//char *gd = "()";
//char *ge = "(1,(2,(3,4)),5)";

//���������ͨ���ַ���str�����������gl
void CreateGenList(GenList& gl, char* str)
{
	int n = strlen(str);//����ַ�������
	//�洢����Ԫ��
	char* sub = (char*)malloc(sizeof(char) * (n - 2));
	//�洢��ͷ
	char* hsub = (char*)malloc(sizeof(char) * (n - 2));
	assert(sub != NULL && hsub != NULL);

	//"1,2,3"
	//ȥ��sub�������ߵ�����
	strncpy(sub, str + 1, n - 2);
	sub[n - 2] = '\0';//���Ͻ�����

	//�жϹ�����Ƿ�Ϊ��
	if (gl == NULL)
	{//Ϊ��
		//����ͷ���(�����ĵ�һ�����Ϊͷ��㣬���඼Ϊβ���)
		gl = (GLNode*)malloc(sizeof(GLNode));
		assert(gl != NULL);
		gl->tag = HEAD; //�����Ϊͷ���
		gl->hp = gl->tp = NULL; //���ӱ�ָ���βָ�붼ָ���
	}

	GLNode* p = gl; //Ϊ�˲���ʧgl��ָ�򣬶���һ��ָ��������
	//���Ӵ����ȣ���sub���Ȳ�Ϊ��ʱ��˵�������δ�������
	while (strlen(sub) != 0)
	{
		//����β�巨,�ں��������
		/*
			1������һ�����
			2����p��ָ����βָ��ָ���½��Ľ��
			3����pָ���½����
		*/
		p = p->tp = (GLNode*)malloc(sizeof(GLNode));
		assert(p != NULL);
		p->hp = p->tp = NULL;//���½������ӱ�ָ���βָ�붼����

		//"1,2,3"  ==>  "1"  hsub="1", sub="2,3";
		//"(1,2),3,4" ==> hsub="(1,2)" sub="3,4"
		if (sever(sub, hsub))//sever���������ͷ��������ͷ����hsub��
		{//����ɹ�

			//�Է�������ı�ͷ�����жϣ��Ƿ��������
			if (hsub[0] == '(')
			{//��
				//˵��Ҫ�����Ľ�����ӱ�����
				p->tag = CHILDLIST;//�����ӱ���
				CreateGenList(p->hp, hsub);//��p�ı�ͷ��㴦������hsub�ӱ�
			}
			else
			{//��
				//˵��Ҫ�����Ľ����ԭ������
				p->tag = ATOM;//����ԭ�ӱ��
				p->atom = atoi(hsub);//����ͷ�ַ���ת�����������ݣ���ֵ��ԭ������
			}
		}
	}
}

//"1,2,3"  ==>    hsub="1", sub="2,3";
//"(1,2),3,4" ==> hsub="(1,2)" sub="3,4"

//"" "()"

//"(1,2)"  ==> hsub ="(1,2)"  sub = ""
//������ͷ�ָ������sub�еı�ͷ�ָhsub��
bool sever(char* sub, char* hsub)
{
	//�ж�sub�Ƿ�Ϊ��
	if (*sub == '\0' || strcmp(sub, "()") == 0)
	{//�� �����""  ��  "()"
		hsub[0] = '\0';//��hsub����
		return true;
	}

	int n = strlen(sub);//��sub�ĳ���
	int i = 0;
	char ch = sub[0];//��ȡ��һ���ַ�
	int k = 0;//��ʾ���ŵ���Ϣ
	/*��sub��û��������һ�δ��⵽������Ķ��ţ���������
	  ע������⵽������Ķ���ʱ��˵���ҵ���ͷ�ָ�㣬�磺"(1,2),3,4" ��ͷ��Ϊ(1,2)
	*/
	while (i < n && (ch != ',' || k != 0))
	{
		//�ж��Ƿ��˵�������
		if (ch == '(')
			k++;//k++��ʾ����һ������
		else if (ch == ')')//�ж��Ƿ�����������
			k--; //k--��ʾ�˳�һ������

		//��ȡ��һ��Ԫ��
		i++;
		ch = sub[i];
	}

	//�ж��Ƿ�����Ϊ��⵽������Ķ��Ŷ�������
	if (i < n)
	{//��
		//��iλ�ýضϣ�ǰ�沿�־��Ǳ�ͷ
		sub[i] = '\0';
		//��ȡ�õı�ͷ����hsub��
		strcpy(hsub, sub);
		//����sub��ֵ����ʱ��subӦ��ȥ����ͷhsub
		strcpy(sub, sub + i + 1);
	}
	else if (k != 0) //�ж��Ƿ�����Ϊ�ڲ����Ų�ƥ��
		return false;//�ǣ��ָ�ʧ��
	else//�ж��Ƿ�����Ϊi>=n������
	{//�ǣ���� "(1,2)"  ==> hsub ="(1,2)"  sub = ""
		//˵��sub�������Ǳ�ͷ
		strcpy(hsub, sub);//��sub������ֵ��hsub
		sub[0] = '\0';//sub����hsub�󣬴�ʱsubΪ��
	}

	return true;
}

//������ת�����ַ���
void NumToStr(int num, char* str, int& i)
{
	char temp[25];
	itoa(num, temp, 10);
	for (unsigned j = 0; j < strlen(temp); ++j)
		str[i++] = temp[j];
}


/*
	�������ת�����ַ�����ʽ����(1,(2,3))
	�������ڵݹ��ȡ���ú���ת�����ڽ�β���һ�����ţ�
	����ʹ��GetGenListStr������а�װ��ȥ����
*/

void GetGenList(GenList gl, char* str, int& i)
{
	//��ȡ���׽�㵽���һ������Ԫ��
	GLNode* p = gl->tp;
	//����δ���������һ����㣬һֱ���б���
	while (p != NULL)
	{
		//�Խ�����ͽ����ж�
		if (p->tag == ATOM)
		{//�������Ϊԭ������
		//	char temp[25];
		//	itoa(p->atom, temp, 10);
		//	for(unsigned j=0;j<strlen(temp);++j)
		//		str[i++]=temp[j];
			NumToStr(p->atom, str, i);//������ת�����ַ�������str��
			if (p->tp != NULL)//�жϸý������Ƿ��н��
				str[i++] = ',';
			p = p->tp;//����
		}
		else if (p->tag == CHILDLIST)
		{//�������Ϊ�ӱ�
			str[i++] = '(';
			GetGenList(p->hp, str, i);//���ӱ�ı�ͷָ�뿪ʼ���ӱ���б���
			str[i++] = ')';
			if (p->tp != NULL)//�жϸý������Ƿ��н��
				str[i++] = ',';
			p = p->tp;//�ӱ������ɺ�����
		}
	}
}

//�������ת�����ַ�����ʽ����(1,(2,3))   type:0 ���ԭ�ӽ��  type:1 �����
char* GetGenListStr(GenList gl, int type)
{
	int i = 0;
	char* str = (char*)malloc(sizeof(char) * 1000);
	//str[i++]='(';//������
	if (type == 0)
	{
		NumToStr(gl->atom, str, i); //������ת�����ַ���	
	}
	else
	{
		GetGenList(gl, str, i);//���һ������
	}
	//str[i++]=')';//������
	str[i] = '\0';
	return str;
}

//ȡ��Ԫ��
char* GetHead(GenList gl)
{
	//�ж���Ԫ�صĽ������
	if (gl->tp->tag == ATOM) //ԭ�����������ԭ�ӽ���ַ
		return GetGenListStr(gl->tp, 0);
	else //�ӱ����������ӽڵ���׵�ַ
		return GetGenListStr(gl->hp, 1);
}

//ȡβԪ��
char* GetTail(GenList gl)
{
	GLNode* p = gl->tp;
	if (p->tp != NULL)//�ж��Ƿ����βԪ��
	{//����
		//ȡβԪ�أ�ȡ�����һ��ֵ��
		return GetGenListStr(p, 1);
	}
	return NULL;
}

//ȡ���һ��Ԫ��
char* GetLast(GenList gl)
{
	GLNode* p = gl->tp;
	while (p->tp != NULL)
		p = p->tp;
	//�ж���Ԫ�صĽ������
	if (p->tag == ATOM)//ԭ�����������ԭ�ӽ���ַ
		return GetGenListStr(p, 0);
	else   //�ӱ����������ӽڵ���׵�ַ
		return GetGenListStr(p->hp, 1);

}

//���������
/*
void ShowGenList(GenList gl)
{
	//��ͷ���ָ����һ����㣨ͷ��㲻������ݣ�
	GLNode *p = gl->tp;
	printf("(");
	//����δ���������һ����㣬һֱ���б���
	while(p != NULL)
	{
		//�Խ�����ͽ����ж�
		if(p->tag == ATOM)
		{//�������Ϊԭ������
			printf("%d",p->atom);//��ӡԭ������
			if(p->tp != NULL)//�жϸý������Ƿ��н��
				printf(",");//�У���ӡ"��"
			p = p->tp;//����
		}
		else if(p->tag == CHILDLIST)
		{//�������Ϊ�ӱ�
			ShowGenList(p->hp);//���ӱ�ı�ͷָ�뿪ʼ���ӱ���б���
			p = p->tp;//�ӱ������ɺ�����
		}
	}
	printf("),");//����������������
}*/


//��ӡ�����
void ShowGenList(GenList gl)
{
	//����GetGenListStr�����������ת�����ַ���
	printf("(%s)", GetGenListStr(gl, 1));
}


//�жϹ�����Ƿ�Ϊ��
bool GenListEmpty(GenList gl)
{
	return gl->tp == NULL; //�жϱ�ͷ���βָ���ָ���Ƿ�Ϊ��
}

//�������ĳ���
int  GenListLength(GenList gl)
{
	int length = 0;//��¼����
	GLNode* p = gl->tp;//��ͷ������һ����㿪ʼͳ��(��Ϊͷ��㲻������)
	//���������Ԫ�أ��ͼ�������
	while (p != NULL)
	{
		length++;//�˵���㳤�Ⱦͼ�һ
		p = p->tp;//����
	}
	return length; //���ع������
}

//�����������
int  GenListDepth(GenList gl)
{
	//�жϹ�����Ƿ�Ϊ��
	if (gl->tp == NULL)
		return 1;//�ձ����Ϊ1
	GLNode* p = gl->tp; //ָ��ͷ������һ�����
	int maxdepth = 0; //��¼���

	int dep;
	//�������δ������ɣ���һֱ������ȡ���
	while (p != NULL)
	{
		//�жϽ�������Ƿ�Ϊ�ӱ���
		if (p->tag == CHILDLIST)
		{//Ϊ�ӱ���
			//��ȡ�ӱ�����
			dep = GenListDepth(p->hp);
			if (dep > maxdepth)//�жϴ�ʱ��õ�����Ƿ�ȵ�ǰ�������ȴ�
				maxdepth = dep;//�ǣ���dep����maxdepth
		}
		p = p->tp;//����
	}
	return maxdepth + 1;//�������(�ò�����=�ò����µ�������+���ϵ�ǰ������1)
}

//�����ĸ��ƣ�gl���Ƶ�T
void CopyGenList(GenList gl, GenList& T)
{

	//�жϹ�����Ƿ�Ϊ��
	if (gl == NULL)
	{//Ϊ��
		return;
	}
	//���ԭ���Ĺ����T�Ѿ��������
	if (T != NULL)
	{
		DestroyGenList(T);
	}

	//����ͷ���(�����ĵ�һ�����Ϊͷ��㣬���඼Ϊβ���)
	T = (GLNode*)malloc(sizeof(GLNode));
	assert(T != NULL);
	T->tag = gl->tag; //�����Ϊͷ���
	T->hp = gl->hp;
	T->tp = gl->tp; //���ӱ�ָ���βָ�붼ָ���


	//��ͷ���ָ����һ����㣨ͷ��㲻������ݣ�
	GLNode* p = gl->tp; //Ϊ�˲���ʧgl��ָ�򣬶���һ��ָ��������
	GLNode* q = T; //Ϊ�˲���ʧT��ָ�򣬶���һ��ָ��������

	//����δ���������һ����㣬һֱ���б���
	while (p != NULL)
	{

		//�������
		q = q->tp = (GLNode*)malloc(sizeof(GLNode));
		assert(q != NULL);
		q->tag = p->tag; //�����Ϊͷ���
		q->hp = q->tp = NULL;//���½������ӱ�ָ���βָ�붼����

		//�Խ�����ͽ����ж�
		if (p->tag == ATOM)
		{//�������Ϊԭ������
			q->atom = p->atom;//��ֵ
			p = p->tp;//����
		}
		else if (p->tag == CHILDLIST)
		{//�������Ϊ�ӱ�
			CopyGenList(p->hp, q->hp);//���ӱ�ı�ͷָ�뿪ʼ���ӱ���б���
			p = p->tp;//�ӱ������ɺ�����
		}
	}
}


//����Ԫ��str( �������ַ���ʾ���磺((1,2),3)  )��Ϊ�����ĵ�һԪ��
void InsertFirstGenList(GenList& gl, char* str)
{
	GenList t;
	InitGenList(t);
	CreateGenList(t, str);

	//��ͷ���ָ����һ����㣨ͷ��㲻������ݣ�
	GLNode* p = t->tp;
	//�����ƶ���һֱ�ƶ������һ�����
	while (p->tp != NULL)
	{
		p = p->tp;
	}

	//���´����Ĺ����t�ŵ�gl��ǰ��
	p->tp = gl->tp;

	//��gl��ͷ������Ϲ����t
	gl->tp = t->tp;

	free(t);//t��ͷ������ã��ͷ�
}

//ɾ��������һ��λ�õ�Ԫ��
void DeleteFirstGenList(GenList& gl, char*& str)
{
	GenList t;
	InitGenList(t);
	t = gl->tp; //����һ��Ԫ�ص�ַ����t
	//����һ��Ԫ�شӹ�����жϿ�
	gl->tp = gl->tp->tp;

	//�ж�Ҫ�ͷŵĽ����ʲô����
	if (t->tag == CHILDLIST)
	{//�ӱ���
		//����Ҫɾ����ֵ
		str = GetGenListStr(t->hp, 1);
		//�ͷ��ӱ�
		DestroyGenList(t->hp);
	}
	else if (t->tag == ATOM)
	{//ԭ�ӽ��
		//����ֵ
		str = GetGenListStr(t, 0);
	}
	free(t);
}


//��չ����
void ClearGenList(GenList& gl)
{
	//��ͷ���ָ����һ����㣨ͷ��㲻������ݣ�
	GLNode* p = gl->tp;
	//����δ���������һ����㣬һֱ���б���
	while (p != NULL)
	{
		//�Խ�����ͽ����ж�
		if (p->tag == ATOM)
		{//�������Ϊԭ������

			gl->tp = p->tp;//��ԭ�ӽ��ӹ������ȡ��
			free(p); //�ͷ�ԭ�ӽ����ڴ�ռ�
			p = gl->tp;//ָ����һ�����
		}
		else if (p->tag == CHILDLIST)
		{//�������Ϊ�ӱ�
			ClearGenList(p->hp);//���ӱ�ı�ͷָ�뿪ʼ���ӱ�������
			p = p->tp;//�ӱ������ɺ�����
		}
	}

}

//���ٹ����
void DestroyGenList(GenList& gl)
{
	//��չ����
	ClearGenList(gl);
	free(gl);//�ͷŹ����
	gl = NULL;
}
