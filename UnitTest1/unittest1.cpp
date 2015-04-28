#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Trees.h"
#include "../DList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestAddChild)
		{
			/*
			F-> D
				C
				B
				A

			*/

			Tree<char> t('F');
			t.addChild('A');
			t.addChild('B');
			t.addChild('C');
			t.addChild('D');

			DList<TreeNode<char>*> correct_list;
			TreeNode<char> node_f('F');
			TreeNode<char> node_a('A');
			TreeNode<char> node_b('B');
			TreeNode<char> node_c('C');
			TreeNode<char> node_d('D');
			correct_list.add(&node_f);
			correct_list.add(&node_a);
			correct_list.add(&node_b);
			correct_list.add(&node_c);
			correct_list.add(&node_d);

			DList<TreeNode<char>*> check_list;
			t.preOrderRecursive(&check_list);

			doubleNode<TreeNode<char>*> *correct_item = correct_list.getFirst();
			doubleNode<TreeNode<char>*> *check_item = check_list.getFirst();

			for (; correct_item != NULL && check_item != NULL; correct_item = correct_item->next, check_item = check_item->next)
			{
				Assert::AreEqual(correct_item->data->data, check_item->data->data);
			}
		}

		TEST_METHOD(TestAddChildParent)
		{
			/*

				F-> C-> D
					A-> B
			*/

			Tree<char> t('F');
			TreeNode<char> *a = t.addChild('A');
			t.addChild('B', a);
			TreeNode<char> *d = t.addChild('D');
			t.addChild('C', d);

			DList<TreeNode<char>*> correct_list;
			TreeNode<char> node_f('F');
			TreeNode<char> node_a('A');
			TreeNode<char> node_b('B');
			TreeNode<char> node_d('D');
			TreeNode<char> node_c('C');
			correct_list.add(&node_f);
			correct_list.add(&node_a);
			correct_list.add(&node_b);
			correct_list.add(&node_d);
			correct_list.add(&node_c);

			DList<TreeNode<char>*> check_list;
			t.preOrderRecursive(&check_list);

			doubleNode<TreeNode<char>*> *correct_item = correct_list.getFirst();
			doubleNode<TreeNode<char>*> *check_item = check_list.getFirst();

			for (; correct_item != NULL && check_item != NULL; correct_item = correct_item->next, check_item = check_item->next)
			{
				Assert::AreEqual(correct_item->data->data, check_item->data->data);
			}
		}

		TEST_METHOD(TestPreOrderRecursive)
		{
			/*
			F-> G-> I-> H
				B-> D-> E
					    C
					A
					
			*/

			Tree<char> t('F');
			TreeNode<char> *b = t.addChild('B');
			t.addChild('A', b);
			TreeNode<char> *d = t.addChild('D', b);
			t.addChild('C', d);
			t.addChild('E', d);
			TreeNode<char> *g = t.addChild('G');
			TreeNode<char> *i = t.addChild('I', g);
			TreeNode<char> *h = t.addChild('H', i);

			DList<TreeNode<char>*> correct_list;
			TreeNode<char> node_a('A');
			TreeNode<char> node_b('B');
			TreeNode<char> node_c('C');
			TreeNode<char> node_d('D');
			TreeNode<char> node_e('E');
			TreeNode<char> node_f('F');
			TreeNode<char> node_g('G');
			TreeNode<char> node_h('H');
			TreeNode<char> node_i('I');

			correct_list.add(&node_f);
			correct_list.add(&node_b);
			correct_list.add(&node_a);
			correct_list.add(&node_d);
			correct_list.add(&node_c);
			correct_list.add(&node_e);
			correct_list.add(&node_g);
			correct_list.add(&node_i);
			correct_list.add(&node_h);

			DList<TreeNode<char>*> check_list;
			t.preOrderRecursive(&check_list);

			doubleNode<TreeNode<char>*> *correct_item = correct_list.getFirst();
			doubleNode<TreeNode<char>*> *check_item = check_list.getFirst();

			for (; correct_item != NULL && check_item != NULL; correct_item = correct_item->next, check_item = check_item->next)
			{
				Assert::AreEqual(correct_item->data->data, check_item->data->data);
			}
		}

		TEST_METHOD(TestPreOrderIterative)
		{
			/*
			F-> G-> I-> H
				B-> D-> E
					    C
					A

					*/

			Tree<char> t('F');
			TreeNode<char> *b = t.addChild('B');
			t.addChild('A', b);
			TreeNode<char> *d = t.addChild('D', b);
			t.addChild('C', d);
			t.addChild('E', d);
			TreeNode<char> *g = t.addChild('G');
			TreeNode<char> *i = t.addChild('I', g);
			TreeNode<char> *h = t.addChild('H', i);

			DList<TreeNode<char>*> correct_list;
			TreeNode<char> node_a('A');
			TreeNode<char> node_b('B');
			TreeNode<char> node_c('C');
			TreeNode<char> node_d('D');
			TreeNode<char> node_e('E');
			TreeNode<char> node_f('F');
			TreeNode<char> node_g('G');
			TreeNode<char> node_h('H');
			TreeNode<char> node_i('I');

			correct_list.add(&node_f);
			correct_list.add(&node_b);
			correct_list.add(&node_a);
			correct_list.add(&node_d);
			correct_list.add(&node_c);
			correct_list.add(&node_e);
			correct_list.add(&node_g);
			correct_list.add(&node_i);
			correct_list.add(&node_h);

			DList<TreeNode<char>*> check_list;
			t.preOrderIterative(&check_list);

			doubleNode<TreeNode<char>*> *correct_item = correct_list.getFirst();
			doubleNode<TreeNode<char>*> *check_item = check_list.getFirst();

			for (; correct_item != NULL && check_item != NULL; correct_item = correct_item->next, check_item = check_item->next)
			{
				Assert::AreEqual(correct_item->data->data, check_item->data->data);
			}
		}

		TEST_METHOD(TestPostOrderRecursive)
		{
			/*
			F-> G-> I-> H
				B-> D-> E
					    C
					A

					  */

			Tree<char> t('F');
			TreeNode<char> *b = t.addChild('B');
			t.addChild('A', b);
			TreeNode<char> *d = t.addChild('D', b);
			t.addChild('C', d);
			t.addChild('E', d);
			TreeNode<char> *g = t.addChild('G');
			TreeNode<char> *i = t.addChild('I', g);
			TreeNode<char> *h = t.addChild('H', i);

			DList<TreeNode<char>*> correct_list;
			TreeNode<char> node_a('A');
			TreeNode<char> node_b('B');
			TreeNode<char> node_c('C');
			TreeNode<char> node_d('D');
			TreeNode<char> node_e('E');
			TreeNode<char> node_f('F');
			TreeNode<char> node_g('G');
			TreeNode<char> node_h('H');
			TreeNode<char> node_i('I');

			correct_list.add(&node_a);
			correct_list.add(&node_c);
			correct_list.add(&node_e);
			correct_list.add(&node_d);
			correct_list.add(&node_b);
			correct_list.add(&node_h);
			correct_list.add(&node_i);
			correct_list.add(&node_g);
			correct_list.add(&node_f);

			DList<TreeNode<char>*> check_list;
			t.postOrderRecursive(&check_list);

			doubleNode<TreeNode<char>*> *correct_item = correct_list.getFirst();
			doubleNode<TreeNode<char>*> *check_item = check_list.getFirst();

			for (; correct_item != NULL && check_item != NULL; correct_item = correct_item->next, check_item = check_item->next)
			{
				Assert::AreEqual(correct_item->data->data, check_item->data->data);
			}
		}

		TEST_METHOD(TestPostOrderIterative)
		{
			/*
			F-> G-> I-> H
				B-> D-> E
					    C
					A
					*/

			Tree<char> t('F');
			TreeNode<char> *b = t.addChild('B');
			t.addChild('A', b);
			TreeNode<char> *d = t.addChild('D', b);
			t.addChild('C', d);
			t.addChild('E', d);
			TreeNode<char> *g = t.addChild('G');
			TreeNode<char> *i = t.addChild('I', g);
			TreeNode<char> *h = t.addChild('H', i);

			DList<TreeNode<char>*> correct_list;
			TreeNode<char> node_a('A');
			TreeNode<char> node_b('B');
			TreeNode<char> node_c('C');
			TreeNode<char> node_d('D');
			TreeNode<char> node_e('E');
			TreeNode<char> node_f('F');
			TreeNode<char> node_g('G');
			TreeNode<char> node_h('H');
			TreeNode<char> node_i('I');

			correct_list.add(&node_a);
			correct_list.add(&node_c);
			correct_list.add(&node_e);
			correct_list.add(&node_d);
			correct_list.add(&node_b);
			correct_list.add(&node_h);
			correct_list.add(&node_i);
			correct_list.add(&node_g);
			correct_list.add(&node_f);

			DList<TreeNode<char>*> check_list;
			t.postOrderIterative(&check_list);

			doubleNode<TreeNode<char>*> *correct_item = correct_list.getFirst();
			doubleNode<TreeNode<char>*> *check_item = check_list.getFirst();

			for (; correct_item != NULL && check_item != NULL; correct_item = correct_item->next, check_item = check_item->next)
			{
				Assert::AreEqual(correct_item->data->data, check_item->data->data);
			}
		}

		TEST_METHOD(TestInOrderIterative)
		{
			/*
			F-> G-> I-> H
				B-> D-> E
					    C
					A
					*/

			Tree<char> t('F');
			TreeNode<char> *b = t.addChild('B');
			t.addChild('A', b);
			TreeNode<char> *d = t.addChild('D', b);
			t.addChild('C', d);
			t.addChild('E', d);
			TreeNode<char> *g = t.addChild('G');
			TreeNode<char> *i = t.addChild('I', g);
			TreeNode<char> *h = t.addChild('H', i);

			DList<TreeNode<char>*> correct_list;
			TreeNode<char> node_a('A');
			TreeNode<char> node_b('B');
			TreeNode<char> node_c('C');
			TreeNode<char> node_d('D');
			TreeNode<char> node_e('E');
			TreeNode<char> node_f('F');
			TreeNode<char> node_g('G');
			TreeNode<char> node_h('H');
			TreeNode<char> node_i('I');

			correct_list.add(&node_a);
			correct_list.add(&node_b);
			correct_list.add(&node_c);
			correct_list.add(&node_d);
			correct_list.add(&node_e);
			correct_list.add(&node_f);
			correct_list.add(&node_g);
			correct_list.add(&node_i);
			correct_list.add(&node_h);

			DList<TreeNode<char>*> check_list;
			t.inOrderRecursive(&check_list);

			doubleNode<TreeNode<char>*> *correct_item = correct_list.getFirst();
			doubleNode<TreeNode<char>*> *check_item = check_list.getFirst();

			for (; correct_item != NULL && check_item != NULL; correct_item = correct_item->next, check_item = check_item->next)
			{
				Assert::AreEqual(correct_item->data->data, check_item->data->data);
			}
		}

		TEST_METHOD(TestClear)
		{
			/*
			F-> G-> I-> H
				B-> D-> E
					    C
					A
			*/

			Tree<char> t('F');
			TreeNode<char> *b = t.addChild('B');
			t.addChild('A', b);
			TreeNode<char> *d = t.addChild('D', b);
			t.addChild('C', d);
			t.addChild('E', d);
			TreeNode<char> *g = t.addChild('G');
			TreeNode<char> *i = t.addChild('I', g);
			TreeNode<char> *h = t.addChild('H', i);

			DList<TreeNode<char>*> dummy_list;
			t.preOrderRecursive(&dummy_list);
			Assert::IsTrue(dummy_list.count() == (unsigned)9);
			
			t.clear();
			DList<TreeNode<char>*> dummy_list2;
			t.preOrderRecursive(&dummy_list2);

			Assert::IsTrue(dummy_list2.count() == (unsigned)1);

		}

		TEST_METHOD(TestClearStartingNode)
		{
			/*
			F-> G-> I-> H
				B-> D-> E
					    C
					A
			*/

			Tree<char> t('F');
			TreeNode<char> *b = t.addChild('B');
			t.addChild('A', b);
			TreeNode<char> *d = t.addChild('D', b);
			t.addChild('C', d);
			t.addChild('E', d);
			TreeNode<char> *g = t.addChild('G');
			TreeNode<char> *i = t.addChild('I', g);
			TreeNode<char> *h = t.addChild('H', i);

			DList<TreeNode<char>*> dummy_list;
			t.preOrderRecursive(&dummy_list);
			Assert::IsTrue(dummy_list.count() == (unsigned)9);

			t.clear(i);
			DList<TreeNode<char>*> dummy_list2;
			t.preOrderRecursive(&dummy_list2);
			Assert::IsTrue(dummy_list2.count() == (unsigned)7);

			t.clear(b);
			DList<TreeNode<char>*> dummy_list3;
			t.preOrderRecursive(&dummy_list3);
			Assert::IsTrue(dummy_list3.count() == (unsigned)2);

		}

	};
}