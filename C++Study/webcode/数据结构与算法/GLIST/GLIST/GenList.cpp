//广义表

#include"GenList.h"

//广义表的初始化
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

//创建广义表：通过字符串str来创建广义表gl
void CreateGenList(GenList& gl, char* str)
{
	int n = strlen(str);//求解字符串长度
	//存储表内元素
	char* sub = (char*)malloc(sizeof(char) * (n - 2));
	//存储表头
	char* hsub = (char*)malloc(sizeof(char) * (n - 2));
	assert(sub != NULL && hsub != NULL);

	//"1,2,3"
	//去掉sub左右两边的括号
	strncpy(sub, str + 1, n - 2);
	sub[n - 2] = '\0';//加上结束符

	//判断广义表是否为空
	if (gl == NULL)
	{//为空
		//创建头结点(广义表的第一个结点为头结点，其余都为尾结点)
		gl = (GLNode*)malloc(sizeof(GLNode));
		assert(gl != NULL);
		gl->tag = HEAD; //结点标记为头结点
		gl->hp = gl->tp = NULL; //把子表指针和尾指针都指向空
	}

	GLNode* p = gl; //为了不丢失gl的指向，定义一个指针来操作
	//求子串长度，当sub长度不为零时，说明广义表还未创建完成
	while (strlen(sub) != 0)
	{
		//采用尾插法,在后面插入结点
		/*
			1、创建一个结点
			2、让p所指结点的尾指针指向新建的结点
			3、让p指向新建结点
		*/
		p = p->tp = (GLNode*)malloc(sizeof(GLNode));
		assert(p != NULL);
		p->hp = p->tp = NULL;//将新建结点的子表指针和尾指针都赋空

		//"1,2,3"  ==>  "1"  hsub="1", sub="2,3";
		//"(1,2),3,4" ==> hsub="(1,2)" sub="3,4"
		if (sever(sub, hsub))//sever函数分离表头，并将表头存入hsub中
		{//分离成功

			//对分离出来的表头进行判断，是否包含括号
			if (hsub[0] == '(')
			{//是
				//说明要创建的结点是子表类型
				p->tag = CHILDLIST;//设置子表标记
				CreateGenList(p->hp, hsub);//在p的表头结点处，创建hsub子表
			}
			else
			{//否
				//说明要创建的结点是原子类型
				p->tag = ATOM;//设置原子标记
				p->atom = atoi(hsub);//将表头字符串转换成整型数据，赋值给原子数据
			}
		}
	}
}

//"1,2,3"  ==>    hsub="1", sub="2,3";
//"(1,2),3,4" ==> hsub="(1,2)" sub="3,4"

//"" "()"

//"(1,2)"  ==> hsub ="(1,2)"  sub = ""
//广义表表头分割函数，将sub中的表头分割到hsub中
bool sever(char* sub, char* hsub)
{
	//判断sub是否为空
	if (*sub == '\0' || strcmp(sub, "()") == 0)
	{//是 情况：""  或  "()"
		hsub[0] = '\0';//将hsub赋空
		return true;
	}

	int n = strlen(sub);//求sub的长度
	int i = 0;
	char ch = sub[0];//获取第一个字符
	int k = 0;//表示括号的信息
	/*当sub还没遍历完成且还未检测到括号外的逗号，继续遍历
	  注：当检测到括号外的逗号时，说明找到表头分割点，如："(1,2),3,4" 表头即为(1,2)
	*/
	while (i < n && (ch != ',' || k != 0))
	{
		//判断是否运到左括号
		if (ch == '(')
			k++;//k++表示进入一层括号
		else if (ch == ')')//判断是否遇到右括号
			k--; //k--表示退出一层括号

		//获取下一个元素
		i++;
		ch = sub[i];
	}

	//判断是否是因为检测到括号外的逗号而结束的
	if (i < n)
	{//是
		//在i位置截断，前面部分就是表头
		sub[i] = '\0';
		//将取得的表头放入hsub中
		strcpy(hsub, sub);
		//更新sub的值：此时的sub应该去掉表头hsub
		strcpy(sub, sub + i + 1);
	}
	else if (k != 0) //判断是否是因为内部括号不匹配
		return false;//是，分割失败
	else//判断是否是因为i>=n而结束
	{//是，情况 "(1,2)"  ==> hsub ="(1,2)"  sub = ""
		//说明sub整个就是表头
		strcpy(hsub, sub);//把sub整个赋值给hsub
		sub[0] = '\0';//sub赋给hsub后，此时sub为空
	}

	return true;
}

//将整数转换成字符串
void NumToStr(int num, char* str, int& i)
{
	char temp[25];
	itoa(num, temp, 10);
	for (unsigned j = 0; j < strlen(temp); ++j)
		str[i++] = temp[j];
}


/*
	将广义表转换成字符串形式：如(1,(2,3))
	但是由于递归获取，该函数转换后在结尾会多一个逗号，
	所以使用GetGenListStr对其进行包装消去逗号
*/

void GetGenList(GenList gl, char* str, int& i)
{
	//获取从首结点到最后一个结点的元素
	GLNode* p = gl->tp;
	//当还未遍历到最后一个结点，一直进行遍历
	while (p != NULL)
	{
		//对结点类型进行判断
		if (p->tag == ATOM)
		{//结点类型为原子类型
		//	char temp[25];
		//	itoa(p->atom, temp, 10);
		//	for(unsigned j=0;j<strlen(temp);++j)
		//		str[i++]=temp[j];
			NumToStr(p->atom, str, i);//将数字转换成字符串存入str中
			if (p->tp != NULL)//判断该结点后面是否还有结点
				str[i++] = ',';
			p = p->tp;//下移
		}
		else if (p->tag == CHILDLIST)
		{//结点类型为子表
			str[i++] = '(';
			GetGenList(p->hp, str, i);//从子表的表头指针开始对子表进行遍历
			str[i++] = ')';
			if (p->tp != NULL)//判断该结点后面是否还有结点
				str[i++] = ',';
			p = p->tp;//子表遍历完成后下移
		}
	}
}

//将广义表转换成字符串形式：如(1,(2,3))   type:0 输出原子结点  type:1 输出表
char* GetGenListStr(GenList gl, int type)
{
	int i = 0;
	char* str = (char*)malloc(sizeof(char) * 1000);
	//str[i++]='(';//左括号
	if (type == 0)
	{
		NumToStr(gl->atom, str, i); //将数字转换成字符串	
	}
	else
	{
		GetGenList(gl, str, i);//会多一个逗号
	}
	//str[i++]=')';//右括号
	str[i] = '\0';
	return str;
}

//取首元素
char* GetHead(GenList gl)
{
	//判断首元素的结点类型
	if (gl->tp->tag == ATOM) //原子类型则传入该原子结点地址
		return GetGenListStr(gl->tp, 0);
	else //子表类型则传入子节点的首地址
		return GetGenListStr(gl->hp, 1);
}

//取尾元素
char* GetTail(GenList gl)
{
	GLNode* p = gl->tp;
	if (p->tp != NULL)//判断是否存在尾元素
	{//存在
		//取尾元素（取后面的一串值）
		return GetGenListStr(p, 1);
	}
	return NULL;
}

//取最后一个元素
char* GetLast(GenList gl)
{
	GLNode* p = gl->tp;
	while (p->tp != NULL)
		p = p->tp;
	//判断首元素的结点类型
	if (p->tag == ATOM)//原子类型则传入该原子结点地址
		return GetGenListStr(p, 0);
	else   //子表类型则传入子节点的首地址
		return GetGenListStr(p->hp, 1);

}

//遍历广义表
/*
void ShowGenList(GenList gl)
{
	//由头结点指向下一个结点（头结点不存放数据）
	GLNode *p = gl->tp;
	printf("(");
	//当还未遍历到最后一个结点，一直进行遍历
	while(p != NULL)
	{
		//对结点类型进行判断
		if(p->tag == ATOM)
		{//结点类型为原子类型
			printf("%d",p->atom);//打印原子数据
			if(p->tp != NULL)//判断该结点后面是否还有结点
				printf(",");//有，打印"，"
			p = p->tp;//下移
		}
		else if(p->tag == CHILDLIST)
		{//结点类型为子表
			ShowGenList(p->hp);//从子表的表头指针开始对子表进行遍历
			p = p->tp;//子表遍历完成后下移
		}
	}
	printf("),");//遍历结束补上括号
}*/


//打印广义表
void ShowGenList(GenList gl)
{
	//调用GetGenListStr函数将广义表转换成字符串
	printf("(%s)", GetGenListStr(gl, 1));
}


//判断广义表是否为空
bool GenListEmpty(GenList gl)
{
	return gl->tp == NULL; //判断表头结点尾指针的指向是否为空
}

//求解广义表的长度
int  GenListLength(GenList gl)
{
	int length = 0;//记录长度
	GLNode* p = gl->tp;//从头结点的下一个结点开始统计(因为头结点不存数据)
	//当广义表还有元素，就继续遍历
	while (p != NULL)
	{
		length++;//运到结点长度就加一
		p = p->tp;//后移
	}
	return length; //返回广义表长度
}

//求解广义表的深度
int  GenListDepth(GenList gl)
{
	//判断广义表是否为空
	if (gl->tp == NULL)
		return 1;//空表深度为1
	GLNode* p = gl->tp; //指向头结点的下一个结点
	int maxdepth = 0; //记录深度

	int dep;
	//当广义表还未遍历完成，就一直遍历求取深度
	while (p != NULL)
	{
		//判断结点类型是否为子表结点
		if (p->tag == CHILDLIST)
		{//为子表结点
			//求取子表的深度
			dep = GenListDepth(p->hp);
			if (dep > maxdepth)//判断此时求得的深度是否比当前的最大深度大
				maxdepth = dep;//是，将dep赋给maxdepth
		}
		p = p->tp;//后移
	}
	return maxdepth + 1;//返回深度(该层的深度=该层以下的最大深度+加上当前层的深度1)
}

//广义表的复制：gl复制到T
void CopyGenList(GenList gl, GenList& T)
{

	//判断广义表是否为空
	if (gl == NULL)
	{//为空
		return;
	}
	//如果原来的广义表T已经存放数据
	if (T != NULL)
	{
		DestroyGenList(T);
	}

	//创建头结点(广义表的第一个结点为头结点，其余都为尾结点)
	T = (GLNode*)malloc(sizeof(GLNode));
	assert(T != NULL);
	T->tag = gl->tag; //结点标记为头结点
	T->hp = gl->hp;
	T->tp = gl->tp; //把子表指针和尾指针都指向空


	//由头结点指向下一个结点（头结点不存放数据）
	GLNode* p = gl->tp; //为了不丢失gl的指向，定义一个指针来操作
	GLNode* q = T; //为了不丢失T的指向，定义一个指针来操作

	//当还未遍历到最后一个结点，一直进行遍历
	while (p != NULL)
	{

		//创建结点
		q = q->tp = (GLNode*)malloc(sizeof(GLNode));
		assert(q != NULL);
		q->tag = p->tag; //结点标记为头结点
		q->hp = q->tp = NULL;//将新建结点的子表指针和尾指针都赋空

		//对结点类型进行判断
		if (p->tag == ATOM)
		{//结点类型为原子类型
			q->atom = p->atom;//赋值
			p = p->tp;//下移
		}
		else if (p->tag == CHILDLIST)
		{//结点类型为子表
			CopyGenList(p->hp, q->hp);//从子表的表头指针开始对子表进行遍历
			p = p->tp;//子表遍历完成后下移
		}
	}
}


//插入元素str( 广义表的字符表示，如：((1,2),3)  )作为广义表的第一元素
void InsertFirstGenList(GenList& gl, char* str)
{
	GenList t;
	InitGenList(t);
	CreateGenList(t, str);

	//由头结点指向下一个结点（头结点不存放数据）
	GLNode* p = t->tp;
	//往后移动，一直移动到最后一个结点
	while (p->tp != NULL)
	{
		p = p->tp;
	}

	//将新创建的广义表t放到gl的前面
	p->tp = gl->tp;

	//将gl的头结点连上广义表t
	gl->tp = t->tp;

	free(t);//t的头结点无用，释放
}

//删除广义表第一个位置的元素
void DeleteFirstGenList(GenList& gl, char*& str)
{
	GenList t;
	InitGenList(t);
	t = gl->tp; //将第一个元素地址传给t
	//将第一个元素从广义表中断开
	gl->tp = gl->tp->tp;

	//判断要释放的结点是什么类型
	if (t->tag == CHILDLIST)
	{//子表结点
		//保存要删除的值
		str = GetGenListStr(t->hp, 1);
		//释放子表
		DestroyGenList(t->hp);
	}
	else if (t->tag == ATOM)
	{//原子结点
		//保存值
		str = GetGenListStr(t, 0);
	}
	free(t);
}


//清空广义表
void ClearGenList(GenList& gl)
{
	//由头结点指向下一个结点（头结点不存放数据）
	GLNode* p = gl->tp;
	//当还未遍历到最后一个结点，一直进行遍历
	while (p != NULL)
	{
		//对结点类型进行判断
		if (p->tag == ATOM)
		{//结点类型为原子类型

			gl->tp = p->tp;//将原子结点从广义表中取下
			free(p); //释放原子结点的内存空间
			p = gl->tp;//指向下一个结点
		}
		else if (p->tag == CHILDLIST)
		{//结点类型为子表
			ClearGenList(p->hp);//从子表的表头指针开始对子表进行清空
			p = p->tp;//子表遍历完成后下移
		}
	}

}

//销毁广义表
void DestroyGenList(GenList& gl)
{
	//清空广义表
	ClearGenList(gl);
	free(gl);//释放广义表
	gl = NULL;
}
