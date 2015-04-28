#ifndef __TREES_H__
#define __TREES_H__

#include "DList.h"
#include "Stack.h"
#include "Globals.h"

template <class TREEDATA> 
class TreeNode
{

public:

	TREEDATA data;
	TreeNode<TREEDATA> *parent;
	DList<TreeNode<TREEDATA>*> children;

public:
	
	TreeNode(const TREEDATA &new_data) : parent(NULL), data(new_data)
	{ }

	void clear()
	{
		doubleNode<TreeNode<TREEDATA>*> *item = children.getFirst();
		unsigned int num_children = children.count();
		for (unsigned int i = 0; i < num_children; i++)
		{
			if (item->data->children.getFirst() != NULL)
			{
				item->data->clear();
			}
			doubleNode<TreeNode<TREEDATA>*> *to_delete = item;
			item = item->next;
			children.del(to_delete);
		}
	}

	void clear(TreeNode<TREEDATA> *starting_node)
	{
		doubleNode<TreeNode<TREEDATA>*> *item = children.getFirst();
		doubleNode<TreeNode<TREEDATA>*> *to_delete = NULL;
		for (item; item != NULL; item = item->next)
		{
			if (item->data == starting_node)
			{
				to_delete = item;
				item->data->clear();
			}
			else
				item->data->clear(starting_node);
		}
		if (to_delete != NULL) children.del(to_delete);
	}
	
	void preOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		list->add(this);
		LOG("%c", data);
		
		doubleNode<TreeNode*> *item = children.getFirst();
		for (; item != NULL; item = item->next)
			item->data->preOrderRecursive(list);
	}

	void postOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		doubleNode<TreeNode*> *item = children.getFirst();
		for (; item != NULL; item = item->next)
			item->data->postOrderRecursive(list);

		list->add(this);
		//LOG("%c", data);
	}

	void inOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		// Odd number of sons -> (x left) | (x+1 right)
		unsigned int middle = children.count() / 2;

		doubleNode<TreeNode*> *item = children.getFirst();

		for (unsigned int i = 0; i < middle; i++, item = item->next)
		{
			item->data->inOrderRecursive(list);
		}
			
		list->add(this);
		//LOG("%c", data);

		for (; item != NULL; item = item->next)
			item->data->inOrderRecursive(list);
	}

};

template <class TREEDATA>
class Tree
{

private:

	TreeNode<TREEDATA> root;

public:

	Tree(const TREEDATA &new_data) : root(new_data)
	{ }

	TreeNode<TREEDATA> *addChild(const TREEDATA &new_data)
	{
		TreeNode<TREEDATA> *new_tree_node = new TreeNode<TREEDATA>(new_data);
		new_tree_node->parent = &root;
		root.children.add(new_tree_node);

		return new_tree_node;
	}

	TreeNode<TREEDATA> *addChild(const TREEDATA &new_data, TreeNode<TREEDATA> *parent)
	{
		TreeNode<TREEDATA> *new_tree_node = new TreeNode<TREEDATA>(new_data);
		new_tree_node->parent = parent;
		parent->children.add(new_tree_node);

		return new_tree_node;
	}

	void clear()
	{
		root.clear();
	}

	void clear(TreeNode<TREEDATA> *starting_node)
	{
		root.clear(starting_node);
	}

	void preOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		root.preOrderRecursive(list);
	}

	void postOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		root.postOrderRecursive(list);
	}

	void inOrderRecursive(DList<TreeNode<TREEDATA>*> *list)
	{
		root.inOrderRecursive(list);
	}

	void preOrderIterative(DList<TreeNode<TREEDATA>*> *list)
	{
		Stack<TreeNode<TREEDATA>*> stack;
		TreeNode<TREEDATA> *node = &root;

		while ( node != NULL || stack.pop(node) )
		{
			list->add(node);
			//LOG("%c", node->data);
			doubleNode<TreeNode<TREEDATA>*> *item = node->children.getLast();
			for (; item != NULL; item = item->previous)
				stack.push(item->data);

			node = (item != NULL) ? item->data : NULL;
		}
	}

	void postOrderIterative(DList<TreeNode<TREEDATA>*> *list)
	{
		Stack<TreeNode<TREEDATA>*> stack;
		TreeNode<TREEDATA> *node = &root;
		stack.push(node);

		while ( stack.pop(node) )
		{
			doubleNode<TreeNode<TREEDATA>*> *item = node->children.getLast();

			if (item != NULL && !(list->isOnList(item)) )
			{
				stack.push(node);
				for (; item != NULL; item = item->previous)
					stack.push(item->data);
			}
			else
			{
				list->add(node);
				//LOG("%c", node->data);
			}
		}
	}
};

#endif //__TREES_H__