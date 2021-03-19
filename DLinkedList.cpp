//#include <stdio.h>
//#include <stdlib.h>
//#include "DLinkedList.h"
//
//void ListInit(List * plist)
//{
//	plist->head = new Node();
//	plist->head->next = nullptr;
//	plist->comp = nullptr;
//	plist->numOfData = 0;
//}
//
//void FInsert(List * plist, LData data)
//{
//	Node * newNode = new Node();
//	newNode->data = data;
//
//	newNode->next = nullptr;
//
//	plist->cur = plist->head;
//
//	while(true)	{
//		if(plist->cur->next != nullptr)	{
//			plist->cur = plist->cur->next;
//		}
//		else{
//			plist->cur->next = newNode;
//			plist->cur = plist->head;
//			break;
//		}
//	}
//
//
//	(plist->numOfData)++;
//}
//
//void SInsert(List * plist, LData data)
//{
//	Node * newNode = new Node();
//	Node * pred = plist->head;
//	newNode->data = data;
//
//	while(pred->next != nullptr &&
//		plist->comp(data, pred->next->data) != 0)
//	{
//		pred = pred->next;
//	}
//
//	newNode->next = pred->next;
//	pred->next = newNode;
//
//	(plist->numOfData)++;
//}
//
//
//void LInsert(List * plist, LData data)
//{
//	if(plist->comp == nullptr)
//		FInsert(plist, data);
//	else
//		SInsert(plist, data);
//}
//
//bool LFirst(List * plist, LData * pdata)
//{
//	if(plist->head->next == nullptr)
//		return false;
//
//	plist->before = plist->head;
//	plist->cur = plist->head->next;
//
//	*pdata = plist->cur->data;
//	return true;
//}
//
//bool LNext(List * plist, LData * pdata)
//{
//	if(plist->cur->next == nullptr)
//		return false;
//
//	plist->before = plist->cur;
//	plist->cur = plist->cur->next;
//
//	*pdata = plist->cur->data;
//	return true;
//}
//
//LData LRemove(List * plist)
//{
//	Node * rpos = plist->cur;
//	LData rdata = rpos->data;
//
//	plist->before->next = plist->cur->next;
//	plist->cur = plist->before;
//
//	delete rpos;
//	(plist->numOfData)--;
//	return rdata;
//}
//
//int LCount(List * plist)
//{
//	return plist->numOfData;
//}
//
//void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
//{
//	plist->comp = comp;
//}