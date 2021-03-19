////
////  Graph.cpp
////  Baekjoon_Practice
////
////  Created by kyw on 05/03/2021.
////  Copyright © 2021 kyw. All rights reserved.
////
//
//#include <iostream>
//#include "Graph.h"
//
//using namespace std;
//
//void GraphInit(UALGraph* pg, int nv)
//{
//    pg->numV = nv;
//    pg->numE = 0;
//    pg->adjList = new List[nv];
//    for(int i = 0; i < nv; i++)		{
//        ListInit(&pg->adjList[i]);
//        LInsert(&pg->adjList[i], i);
//    }
//}
//
//void GraphDestroy(UALGraph* pg)
//{
//    delete[] pg->adjList;
//}
//
//void AddEdge(UALGraph* pg, Vertex fromV, Vertex toV)
//{
//    LInsert(&pg->adjList[static_cast<int>(fromV)], static_cast<int>(toV));
//    LInsert(&pg->adjList[static_cast<int>(toV)], static_cast<int>(fromV));
//    (pg->numE)++;
//}
//
//void ShowGraphEdgeInfo(UALGraph* pg)
//{
//    for(int i = 0; i < pg->numV; i++){
//        pg->adjList[i].cur = pg->adjList[i].head->next;
//        cout << ShowVertext(static_cast<Vertex>(pg->adjList[i].head->next->data)) << " 와 연결된 정점: ";
//        for(int j = 1; j < pg->adjList[i].numOfData; j++){
//            cout << ShowVertext(static_cast<Vertex>(pg->adjList[i].cur->next->data)) << ' ';
//            pg->adjList[i].cur = pg->adjList[i].cur->next;
//        }
//        cout << endl;
//    }
//}
//
//char ShowVertext(Vertex v)
//{
//
//    switch(v)	{
//    case Vertex::A:
//        return 'A';
//        break;
//    case Vertex::B:
//        return 'B';
//        break;
//    case Vertex::C:
//        return 'C';
//        break;
//    case Vertex::D:
//        return 'D';
//        break;
//    case Vertex::E:
//        return 'E';
//        break;
//    case Vertex::F:
//        return 'F';
//        break;
//    case Vertex::G:
//        return 'G';
//        break;
//    case Vertex::H:
//        return 'H';
//        break;
//    case Vertex::I:
//        return 'I';
//        break;
//    case Vertex::J:
//        return 'J';
//        break;
//    default:
//        return ' ';
//        break;
//    }
//}
//
////int main()
////{
////    UALGraph graph;
////    GraphInit(&graph, 5);
////
////    AddEdge(&graph, Vertex::A, Vertex::B);
////    AddEdge(&graph, Vertex::A, Vertex::D);
////    AddEdge(&graph, Vertex::B, Vertex::C);
////    AddEdge(&graph, Vertex::C, Vertex::D);
////    AddEdge(&graph, Vertex::D, Vertex::E);
////    AddEdge(&graph, Vertex::E, Vertex::A);
////
////    ShowGraphEdgeInfo(&graph);
////    GraphDestroy(&graph);
////
////
////    cout << "hello world" << endl;
////    return 0;
////}
