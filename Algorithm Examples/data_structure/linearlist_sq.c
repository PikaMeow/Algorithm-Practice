//线性表的顺序表示C语言实现(使用了C++的引用调用的参数传递方式)
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//Status是函数的类型
typedef int Status;

//线性表的动态分配存储结构
#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10 //线性表存储空间的分配增量

//定义数据元素类型ElemType
typedef ElemType *SqList;

//定义顺序线性表的结构体
typedef struct {
	ElemType *elem;//存储空间基址
	int length;//当前长度
	int listsize;//当前分配的存储容量（以sizeof(ElemType)为单位）
}Sqlist;

//操作结果：构造一个空的线性表L
Status InitList_Sq (SqList &L) {
	//构造一个空的线性表L
	L.elem = (ElemType*) malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);//存储分配失败
	L.length=0;//空表长度为0
	L.listsize=LIST_INIT_SIZE;//初始存储常量
	return OK;
}//InitList_Sq

//初始条件：线性表L已存在
//操作结果：销毁线性表L
Status DestoryList_Sq(SqList &L) {
	
}

//初始条件：线性表L已存在
//操作结果：将L充值为空表
Status ClearList_Sq(SqList &L) {
	
}

//初始条件：线性表L已存在
//操作结果：若L为空表，返回TRUE，否则返回FALSE
Status ListEmpty_Sq(SqList L) {
	
}

//初始条件：线性表L已存在
//操作结果：返回L中数据元素个数
Status ListLength_Sq(SqList L) {
	
}

//初始条件：线性表L已存在，1<=i<=ListLength(L)
//操作结果：用e返回L中第i个数据元素的值
Status GetElem_Sq(SqList L,int i,ElemType &e) {
	
}

//初始条件：线性表L已存在，compare()是数据元素判定函数
//操作结果：返回L中第一个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0
Status LocateElem_Sq(SqList L,ElemType e,Status(* compare)(ElemType,ElemType)) {
	//在顺序线性表L中第一个值与e满足compare()的元素的位序
	//若找到，则返回其在L中的位序，否则返回0
	i=1;
	p=L.elem;
	while(!<=L.length && !(*compare)(*p++,e)) ++i;
	if(i<=L.length) return i;
	else return 0;
}//LocateElem_Sq

//初始条件：线性表L已存在
//操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
Status PriorElem_Sq(SqList L,ElemType cur_e,ElemType &pre_e) {
	
}

//初始条件：线性表L已存在
//操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义
Status NextElem_Sq(SqList L;ElemType cur_e,ElemType &next_e) {
	
}

//初始条件：线性表L已存在，1<=i<=ListLength(L)+1
//操作结果：在L中第i个位置之前插入新的数据e，L的长度加1
Status ListInsert_Sq(SqList &L,int i,ElemType e) {
	//在顺序线性表L中第i个位置之前插入新的元素e
	//i的合法值为1<=i<=ListLength(L)+1
	if(i<1 || i>ListLength_Sq(L)) return ERROR;//i值不合法
	if(L.length>=L.listsize) {//当前存储空间已满，增加分配
		newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit OVERFLOW;//存储分配失败
		L.elem=newbase;//新基址
		L.listsize+=LISTINCREMENT;//增加存储容量
	}
	q=&(L.elem[i-1]);//q为插入位置
	for (p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;//插入位置及之后的元素后移
	*q=e;//插入e
	++L.length;//表长增1
	return OK;
}//ListInsert_Sq

//初始条件：线性表L已存在，1<=i<=ListLength(L)
//操作结果：删除L中第i个数据元素，并用e返回其值，L的长度减1
Status ListDelete_Sq(SqList &L,int i,ElemType &e) {
	//在顺序表L中删除第i个元素，并用e返回其值
	//i的合法值为1<=i<=ListLength_Sq(L)
	if ((i<1)||(i>L.length)) return ERROR;//i值不合法
	p=&(L.elem[i-1]);//p为被删除元素的位置
	e=*p;//被删除元素的值赋给e
	q=L.elem+L.length-1;//表尾元素的位置
	for (++p;p<=q;++p)
		*(p-1)=*p;//被删除元素后的元素位置左移
	--L.length;//表长减1
	return OK:
}//ListDelete_Sq

//初始条件：线性表L已存在
//操作结果：依次对L的每个数据元素调用函数visit().一旦visit()失败，则操作失败
Status ListTraverse_Sq(SqList L,Status(*visit)(ElemType)) {
	
}