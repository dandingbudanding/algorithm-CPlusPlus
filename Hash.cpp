// HashTree.cpp : 定义控制台应用程序的入口点。  
//选择质数分辨算法构造一棵哈希树:n个不同质数能够分辨的连续整数数目与其乘积相同  
#include <iostream>  
using namespace std;

const int SIZE = 32;//第10个质数为29，余数不可能大于32，所以数组的固定长度设置为32  
const int Prime[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
//哈希结点类型  
template<class T1, class T2>
class HashNode
{
public:
	HashNode();//默认构造函数  
	HashNode(T1 key, T2 value);//一般构造函数  
	~HashNode();

public:
	T1 m_key;  //结点的关键字  
	T2 m_value; //结点的数据对象  
	bool occupied; //结点是否被占据，如果是表示结点的关键字有效  
	HashNode *child[SIZE];  //结点的子结点数组  
};

template<class T1, class T2>
HashNode<T1, T2>::HashNode()
{
	occupied = false;
	memset(child, NULL, SIZE*sizeof(HashNode<T1, T2>*));
}

template<class T1, class T2>
HashNode<T1, T2>::HashNode(T1 key, T2 value)
{
	this->m_key = key;
	this->m_value = value;
	occupied = false;
	memset(child, NULL, SIZE*sizeof(HashNode<T1, T2>*));
}

template<class T1, class T2>
HashNode<T1, T2>::~HashNode()
{

}

//哈希树类型  
template<class T1, class T2>
class HashTree
{
public:
	HashTree();
	~HashTree();
	void InsertNode(T1 key, T2 value);
	bool FindNode(T1 key, T2 &value);
	void DeleteNode(T1 key);


private:
	HashNode<T1, T2> *root;
	void Insert(HashNode<T1, T2> *hashNode, int level, T1 key, T2 value);//插入结点  
	bool Find(HashNode<T1, T2> *hashNode, int level, T1 key, T2 value);//查找  
	void Delete(HashNode<T1, T2> *hashNode, int level, T1 key);//删除结点  
};

template<class T1, class T2>
HashTree<T1, T2>::HashTree()
{
	root = new HashNode<T1, T2>;
}

template<class T1, class T2>
HashTree<T1, T2>::~HashTree()
{

}

template<class T1, class T2>
void HashTree<T1, T2>::InsertNode(T1 key, T2 value)
{
	Insert(root, 0, key, value); 
}

template<class T1, class T2>
void HashTree<T1, T2>::Insert(HashNode<T1, T2> *hashNode, int level, T1 key, T2 value)//插入结点  
{
	if (hashNode->occupied == false)
	{
		hashNode->m_key = key;
		hashNode->m_value = value;
		hashNode->occupied = true;
		return;
	}

	int index = key%Prime[level];

	if (hashNode->child[index] == NULL)
	{
		hashNode->child[index] = new HashNode<T1, T2>;
	}

	level += 1;
	Insert(hashNode->child[index], level, key, value);

}

template<class T1, class T2>
bool HashTree<T1, T2>::FindNode(T1 key, T2 &value)
{
	return Find(root, 0, key, value);
}

template<class T1, class T2>
bool HashTree<T1, T2>::Find(HashNode<T1, T2> *hashNode, int level, T1 key, T2 value)//查找  
{
	if (hashNode->occupied == true)
	{
		if (hashNode->m_key == key)
		{
			value = hashNode->m_value;
			return true;
		}
	}

	int index = key%Prime[level];
	if (hashNode->child[index] == NULL)
	{
		return false;
	}

	level += 1;
	return Find(hashNode->child[index], level, key, value);
}

template<class T1, class T2>
void HashTree<T1, T2>::DeleteNode(T1 key)
{
	Delete(root, 0, key);
}

template<class T1, class T2>
void HashTree<T1, T2>::Delete(HashNode<T1, T2> *hashNode, int level, T1 key)//删除结点  
{
	if (hashNode->occupied == true)
	{
		if (hashNode->m_key == key)
		{
			hashNode->occupied = false;
			cout << "关键字为" << key << "结点已被删除！" << endl;
			return;
		}
	}

	int index = key%Prime[level];
	if (hashNode->child[index] == NULL)
	{
		cout << "该关键字不存在！" << endl;
		return;
	}

	level += 1;
	Delete(hashNode->child[index], level, key);
}

int main()
{
	HashTree<int, int> ht;
	ht.InsertNode(1, 8);
	ht.InsertNode(2, 0);
	ht.InsertNode(3, 4);
	ht.InsertNode(4, 7);
	ht.InsertNode(5, 4);
	ht.InsertNode(6, 3);
	ht.InsertNode(7, 8);

	int nvalue = 0;
	cout << ht.FindNode(5, nvalue) << endl;
	cout << ht.FindNode(9, nvalue) << endl;

	ht.DeleteNode(4);
	ht.DeleteNode(10);

	cout << "baasdfas" << endl;
	system("pause");
	return 0;
}