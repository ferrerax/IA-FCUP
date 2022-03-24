#include "tabuleiro.hh"
#include "AStar.hh"
#include <utility>

using std::pair;

AStar::AStar(no *node, tabuleiro *fin)
{
    q.push(pair<int, no *>(0, node));
    this->fin = fin;
}

AStar::~AStar()
{
    // TODO Auto-generated destructor stub
}

bool AStar::is_empty()
{
    return q.empty();
}

no *AStar::pullTop()
{
    no *aux = q.top().second;
    q.pop();
    return aux;
}

void AStar::makeAndInsertDescendants(no *node)
{
    no **childs = node->getChilds();
    //visitedNodes[node->getData()->getHash()] = true;
    for (int i = 0; i < 4; i++)
    {
        if (childs[i] != nullptr and !visited(childs[i]))
        {

            // Function g: cost to reach the node
            // We decide that the cost to reach a node is 1 for each step.
            // Therefore, for node n, g(n) is the depth of n
            int g = childs[i]->getDepth();

#if HEURISTIC == 1
            int h = childs[i]->getData()->getNumberPieces(fin);
#else
            int h = childs[i]->getData()->getManhattanDistance(fin);
#endif

			nodesGenerated++;
            q.push(pair<int, no *>( h+g , childs[i]));
        }
    }
}
