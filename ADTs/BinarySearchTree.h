/* ====================================================

	Description: Binary Search Tree ADT
	Author: Konstantin Dinev
	Platform: C++11

 ====================================================== */

#ifndef TREEADT_H

#define TREEADT_H

template <class ValueType>
class TreeNode
{
private:
	// Members
	TreeNode *left, *right;
	ValueType value;

public:
	// Constructors and destructors
	TreeNode(ValueType);
	~TreeNode();

	// Accessors and Modifiers

	ValueType GetValue();
	void SetValue(ValueType);
	
	TreeNode* GetLeft();
	void SetLeft(TreeNode*);
	void SetLeft(ValueType);
	
	TreeNode* GetRight();
	void SetRight(TreeNode*);
	void SetRight(ValueType);

	// Public Methods
	void Insert(TreeNode*);
	void Insert(ValueType);
};

template <class ItemType>
class Tree
{
private:
	// Members
	TreeNode<ItemType> *root;

public:
	// Constructors and Destructors
	Tree();
	Tree(TreeNode<ItemType>*);
	Tree(ItemType);
	~Tree();

	// Accessors and Modifiers
	void AddRoot(TreeNode<ItemType>*);
	void AddRoot(ItemType);

	// Public Methods
	void Insert(TreeNode<ItemType>*);
	void Insert(ItemType);
};

/* ======================================================

	Tree Node Definitions

 ====================================================== */

template <class ValueType>
TreeNode<ValueType>::TreeNode(ValueType val)
{
	this->left = nullptr;
	this->right = nullptr;
	this->value = val;
}

template <class ValueType>
TreeNode<ValueType>::~TreeNode()
{
	if (this->left != nullptr)
	{
		delete this->left;
	}
	if (this->right != nullptr)
	{
		delete this->right;
	}
}

template <class ValueType>
ValueType TreeNode<ValueType>::GetValue()
{
	return this->value;
}

template <class ValueType>
void TreeNode<ValueType>::SetValue(ValueType val)
{
	this->value = val;
}

template <class ValueType>
TreeNode<ValueType>* TreeNode<ValueType>::GetLeft()
{
	return this->left;
}

template <class ValueType>
TreeNode<ValueType>* TreeNode<ValueType>::GetRight()
{
	return this->right;
}

template <class ValueType>
void TreeNode<ValueType>::Insert(TreeNode<ValueType> *node)
{
	if (this->value < node->GetValue())
	{
		if (this->right != nullptr)
		{
			this->right->Insert(node);
		}
		else
		{
			this->right = node;
		}
	}
	else
	{
		if (this->left != nullptr)
		{
			this->left->Insert(node);
		}
		else
		{
			this->left = node;
		}
	}
}

template <class ValueType>
void TreeNode<ValueType>::Insert(ValueType value)
{
	if (this->value < value)
	{
		if (this->right != nullptr)
		{
			this->right->Insert(value);
		}
		else
		{
			this->right = new TreeNode<ValueType>(value);
		}
	}
	else
	{
		if (this->left != nullptr)
		{
			this->left->Insert(value);
		}
		else
		{
			this->left = new TreeNode<ValueType>(value);
		}
	}
}

/* ======================================================

	Tree Definitions 
	
 ====================================================== */

template <class ItemType>
Tree<ItemType>::Tree()
{
	this->root = nullptr;
}

template <class ItemType>
Tree<ItemType>::Tree(TreeNode<ItemType> *root)
{
	this->root = root;
}

template <class ItemType>
Tree<ItemType>::Tree(ItemType item)
{
	this->root = new TreeNode<ItemType>(item);
}

template <class ItemType>
Tree<ItemType>::~Tree()
{
	delete this->root;
}

template <class ItemType>
void Tree<ItemType>::AddRoot(TreeNode<ItemType> *node)
{
	this->root = node;
}

template <class ItemType>
void Tree<ItemType>::AddRoot(ItemType value)
{
	if (this->root == nullptr)
	{
		this->Insert(value);
	}
}

template <class ItemType>
void Tree<ItemType>::Insert(TreeNode<ItemType> *node)
{
	if (this->root != nullptr)
	{
		this->root->Insert(node);
	}
	else
	{
		this->root = node;
	}
}

template <class ItemType>
void Tree<ItemType>::Insert(ItemType value)
{
	if (this->root != nullptr)
	{
		this->root->Insert(value);
	}
	else
	{
		this->root = new TreeNode<ItemType>(value);
	}
}

#endif
