//
//  DLinkedList.h
//  Baekjoon_Practice
//
//  Created by kyw on 05/03/2021.
//  Copyright © 2021 kyw. All rights reserved.
//

#ifndef DLinkedList_h
#define DLinkedList_h

typedef int LData;

struct List {
    
};

void ListInit(List* pList);

void LInsert(List* pList, LData data);

int LFirst(List* pList, LData* pData);

int LNext(List* pList, LData* pData);

LData LRemove(List* pList);

int LCount(List* pList);

void SetSortRule(List* pList, int (*comp)(LData d1, LData d2));


#endif /* DLinkedList_h */
