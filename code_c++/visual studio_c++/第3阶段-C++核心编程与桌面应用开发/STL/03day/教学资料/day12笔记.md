## 02.函数对象适配（了解）

1.什么是函数对象适配：当函数对象的参数不够用，那么可以用适配器来配置函数对象。

2.函数适配器：bind1st,bind2nd,将二元函数对象配置为一元函数对象

```
//第一步:继承binary_function<参数1，参数2，返回类型>
struct Myfunc:public binary_function<int,int,void>
{
	void operator()(int v1,int v2)const //第二步：加上const成为常函数，参数变2个
	{
		//cout << v1 << " " << endl;
		cout << v1 + v2 << endl;//第三步：实现函数体
	}

};
//需求：打印时，每个元素加100然后打印出来
void test()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//for_each(v.begin(), v.end(), Myfunc());
	//第四步：用bind2nd来绑定函数对象
	for_each(v.begin(), v.end(), bind2nd(Myfunc(),100));
}
```

3.bind1st和bind2nd的区别
bind1st把100绑定给第一个参数，bind2nd把100绑定给第二个参数

4.函数对象适配器 not1 not2 取反

1.not1和not2的区别：not1针对一元函数对象，not2针对二元函数对象

2.使用not1和not2

```


//第一步：继承
struct MyNotfunc:public unary_function<int,bool>
{
	bool operator()(int v)const //第二步：变为常函数
	{
		return v >= 20;
	}
	 
};
//not1 和not2 
void myPrint(int val)
{
	cout << val << " ";
}

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//find_if()

	/*
	_InIt _Find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
		for (; _First != _Last; ++_First)
		if (_Pred(*_First))
			break;
		return (_First);
	}
	*/
	//第三步：适配
	vector<int>::iterator it=find_if(v.begin(), v.end(), not1(MyNotfunc()));
	if (it == v.end())
	{
		cout << "查找失败" << endl;
	}
	else
	{
		cout << "查找成功=" << *it << endl;
	}

	//not2的使用
	//less 二元函数对象
	vector<int> v2;
	v2.push_back(10);
	v2.push_back(50);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);
	//release模式下可以
	sort(v2.begin(), v2.end(),not2(less<int>()));
	for_each(v2.begin(), v2.end(), myPrint);
}
```

5.普通函数进行适配

```
//普通函数进行适配 ptr_fun
//第一步:把一个参数变为二个参数
void myprint2(int val,int val2)
{
	cout << val+val2<< " ";
}
void test03()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//第二步：把普通函数变为函数对象 ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myprint2),100));
}

```

6.成员函数适配

1.mem_fun : 如果存储的是对象指针，需要使用mem_fun

2.mem_fun_ref : 如果存储的是对象，需要使用mem_fun_ref

```
class Maker
{
public:
	Maker(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	//成员函数
	void MyprintMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	string name;
	int age;
};
//void MyprintMaker(Maker m)
//{
//	cout << "Name:" << m.name << " Age:" << m.age << endl;
//}
void test04()
{
	vector<Maker> v;
	v.push_back(Maker("aaa", 10));
	v.push_back(Maker("bbb", 20));
	v.push_back(Maker("ccc", 30));
	//当容器存储的是对象，用mem_fun_ref适配他的成员函数
	for_each(v.begin(), v.end(), mem_fun_ref(&Maker::MyprintMaker));
	cout << "-------------" << endl;
	vector<Maker*> vp;
	vp.push_back(new Maker("aaa", 10));
	vp.push_back(new Maker("bbb", 20));
	vp.push_back(new Maker("ccc", 30));
	//当容器存储的是对象指针，用mem_fun适配他的成员函数
	for_each(vp.begin(), vp.end(), mem_fun(&Maker::MyprintMaker));
}
```



## 03.空间配置器（了解）

如果申请的内存大小超过128，那么空间配置器就自动调用一级空间配置器。反之调用二级空间配置器。

## 04.算法概念（了解）

1.算法通过迭代器来操作容器中元素

2.算法的头文件:<algorithm><functional><numeric>

## 05.遍历算法（重点）

1.for_each：遍历打印

​	1.for_each(开始迭代器，结束迭代器，函数对象)

2.transform:搬运

​	1.transform（源开始迭代器，源结束迭代器，目标开始迭代器，函数对象）

​	2.transform（源1开始迭代器，源1结束迭代器，源2开始迭代器，目标开始迭代器，函数对象）

## 06.查找算法（重点）

1.find:查找元素

​	find(开始迭代器，结束迭代器，要查找的数值);

​	find_if(开始迭代器，结束迭代器,谓词或函数对象);

2.adjacent_find算法 查找相邻重复元素

​	adjacent_find(开始迭代器，结束迭代器)

​	adjacent_find(开始迭代器，结束迭代器,谓词或函数对象);

3.binary_search算法 二分查找法,注意：数据必须要有序，返回值是bool

​	binary_search(开始迭代器，结束迭代器,数值)；

​	binary_search（开始迭代器，结束迭代器,对象，函数对象）；

​	注意：存储对象，如果使用less，那么数据要是升序,并且要重载<，greater这需要数据是降序，并且要重载>

4.count 统计元素个数

​	count（开始迭代器，结束迭代器,数值）；

​	count（开始迭代器，结束迭代器，谓词或函数对象）；

## 07.排序算法(重点）

1.merge算法 容器元素合并，并存储到另一容器中

​	1.如果数据是升序，那么第六个参数就不用写

​	merge(开始迭代器1，结束迭代器1，开始迭代器2，结束迭代器2，目标开始迭代器)；

​	2.如果数据是降序，那么第六个参数就要写greater<int>()

​	merge(开始迭代器1，结束迭代器1，开始迭代器2，结束迭代器2，目标开始迭代器，greater<int>())；

2.sort算法 容器元素排序

​	1.sort(开始迭代器，结束迭代器)；

​	2.存储的是对象时,sort(开始迭代器，结束迭代器,函数对象)；

3.random_shuffle：洗牌

​	定义随机种子：srand((unsigned int)time(NULL));

​	random_shuffle（开始迭代器，结束迭代器）

4.reverse算法 反转指定范围的元素

​	reverse（开始迭代器，结束迭代器）

## 08.拷贝和替换算法（重点）

1.copy：拷贝

​	copy(源开始迭代器，源结束迭代器，目标开始迭代器)；

2.replace算法 将容器内指定范围的旧元素修改为新元素，replace_if算法 将容器内指定范围满足条件的元素替换为新元素

​	1.replace（开始迭代器，结束迭代器，旧值，新值）；

​	2.replace_if(开始迭代器，结束迭代器,谓词,新值)；

3.swap，交换容器

​	swap(容器1，容器2)；

## 09.算术生成算法（重点）

1.accumulate算法 计算容器元素累计总和

​	1.int ret=accumulate（开始迭代器，结束迭代器，数值）；//第三个参数是在总和上再加上0

​	2.int ret=accumulate(开始迭代器，结束迭代器，数值,函数对象)；//针对存储对象

2.fill算法 向容器中添加元素

​	1.要开辟容器的空间.v.resize(10);

​	2.fill(开始迭代器，结束迭代器,要填充的数值)

## 10.集合算法（重点）

1.注意:两个集合必须是有序序列

2.set_intersection算法 求两个集合的交集

​	set_intersection（源开始迭代器1，源结束迭代器1，源开始迭代器2，源结束迭代器2，,目标开始迭代器）；

3.set_union算法 求两个set集合的并集

​	set_union（源开始迭代器1，源结束迭代器1，源开始迭代器2，源结束迭代器2，,目标开始迭代器）；

4.set_difference算法 求两个set集合的差集
//假如A集合有1,2,3,4,5 B集合有2,3,4,5,6 A集合减B集合的结果就是1

​	set_difference（源开始迭代器1，源结束迭代器1，源开始迭代器2，源结束迭代器2，,目标开始迭代器）；


## 11.综合案例（重点）

1.定义演讲者

```
class Player
{
public:
	string name;
	int age;
	int mScore[3];//最多有三轮比赛成绩
};
```

2.思路：

​	1.用vector存储编号（编号对应选手）

​	2.用map保存选手信息（键值是编号，实值是选手）

​	3.每一轮的结果存储到vector中，只保存选手的编号

3.流程：

​	1.创建选手

​	2.第一轮比赛：抽签，比赛，打印本轮晋级选手名单

​	3.第二轮比赛：抽签，比赛，打印本轮晋级选手名单

​	4.第三轮比赛：抽签，比赛，打印本轮晋级选手名单

4.比赛

​	1.学生成绩存储到deque容器中，计算出分数

​	2.评比:当选手计算出平均分时，把选手放入到multimap中，当该容器达到6位选手时，进行筛选，取前三名，然后清空容器；