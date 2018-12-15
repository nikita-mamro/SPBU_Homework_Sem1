#include "Graph.hpp"
#include "ReadFromFile.hpp"

struct Node
{
	int city;
	vector<Node*> neighbours;
	bool isVisited = false;
};

Node *createNode(int city)
{
	return new Node{city};
}

void refreshIsVisited(Node *node)
{
	node->isVisited = false;

	for (int i = 0; i < node->neighbours.size(); ++i)
	{
		if (node->neighbours[i]->isVisited)
		{
			refreshIsVisited(node->neighbours[i]);
		}
	}
}

void fillArray(Node *node, vector<Node*> &nodes)
{
	nodes.push_back(node);
	node->isVisited = true;
	for (Node *current : node->neighbours)
	{
		if (!current->isVisited)
		{
			fillArray(current, nodes);
		}
	}
}

Node *findCity(Node *node, int city)
{
	vector<Node*> nodes;
	fillArray(node, nodes);

	for (Node *current : nodes)
	{
		if (current->city == city)
		{
			return current;
		}
	}

	return nullptr;
}

void addNewNeighbour(Node *node, int neighbour)
{
	node->neighbours.push_back(createNode(neighbour));
}

void addExistingNeighbour(Node *node, Node *neighbour)
{
	node->neighbours.push_back(neighbour);
	neighbour->neighbours.push_back(node);
}

void sortTripletsByRoadLength(vector<InputElement*> &triplets)
{
	for (unsigned int i = 0; i < triplets.size() - 1; ++i)
	{
		for (unsigned int j = 0; j < triplets.size() - 1 - i; ++j)
		{
			if (getRoadLength(triplets[j]) > getRoadLength(triplets[j + 1]))
			{
				swap(triplets[j], triplets[j + 1]);
			}
		}
	}
}

bool differentCapitals(vector<Node*> &capitalNodes, int cityA, int cityB)
{
	for (unsigned int i = 0; i < capitalNodes.size(); ++i)
	{
		if (findCity(capitalNodes[i], cityA) != nullptr)
		{
			for (unsigned int j = 0; j < capitalNodes.size(); ++j)
			{
				if (findCity(capitalNodes[j], cityB) != nullptr)
				{
					if (i != j)
					{
						for (unsigned int i = 0; i < capitalNodes.size(); ++i)
						{
							refreshIsVisited(capitalNodes[i]);
						}
						return true;
					}
				}
			}
		}
	}
	for (unsigned int i = 0; i < capitalNodes.size(); ++i)
	{
		refreshIsVisited(capitalNodes[i]);
	}
	return false;
}

vector<Node*> getCapitalNodes(vector<int> &capitals, vector<InputElement*> &triplets)
{
	vector<Node*> capitalNodes;

	for (int capital : capitals)
	{
		capitalNodes.push_back(createNode(capital));
	}

	sortTripletsByRoadLength(triplets);

	const int tripletsCount = triplets.size();

	int i = 0;

	while (!triplets.empty())
	{
		int j = 0;
		Node *current = capitalNodes[i % capitals.size()];

		vector<InputElement*> tmpTriplets = triplets;

		for (InputElement * elem : tmpTriplets)
		{
			int cityFrom = getCityFrom(elem);
			int cityTo = getCityTo(elem);

			if (differentCapitals(capitalNodes, cityFrom, cityTo))
			{
				triplets.erase(triplets.begin() + j);
				continue;
			}

			Node *from = findCity(current, cityFrom);
			refreshIsVisited(current);
			Node *to = findCity(current, cityTo);
			refreshIsVisited(current);

			if (from != nullptr)
			{
				if (to != nullptr)
				{
					addExistingNeighbour(from, to);
					triplets.erase(triplets.begin() + j);
					break;
				}
				addNewNeighbour(from, cityTo);
				triplets.erase(triplets.begin() + j);
				break;
			}

			++j;
		}

		++i;
	}

	return capitalNodes;
}

vector<vector<int>>  solveTask(ifstream & input)
{
	vector<int> capitals;
	vector<InputElement*> triplets;

	readFromFile(capitals, triplets, input);

	vector<Node*> capitalNodes = getCapitalNodes(capitals, triplets);

	vector<vector<int>> res;

	for (Node *capital : capitalNodes)
	{
		vector<Node*> cities;
		fillArray(capital, cities);

		vector<int> tmp;

		for (Node *current : cities)
		{
			tmp.push_back(current->city);
		}

		res.push_back(tmp);
	}

	return res;
}
