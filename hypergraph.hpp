#include <unordered_map>
#include <unordered_set>
#include <vector>

template <class Data, class Weight>
class Hypergraph {
public:
	class Hyperedge {	//undirected
	public:
		Hyperedge() {}

		void addVertex(Data* d) {
			vertices.insert(d);
		}

		std::unordered_set<Data*> getVertices() {
			return vertices;
		}

		void setWeight(Weight* w) {
			weight = w;
		}

		Weight* getWeight() {
			return weight;
		}
	protected:
		std::unordered_set<Data*> vertices;
		Weight* weight;
	};


	Hypergraph(){}

	void addVertex(Data* d) {
		vertices.insert(d);
	}

	void addEdge(Hyperedge e) {
		edges.insert(e);
	}

	Hypergraph subHypergraph(std::unordered_set<Data*> v) { // vertices removed from edges
		vertices = vertices.intersection(v);
	}

	Hypergraph partialHypergraph(std::unordered_set<Hyperedge> e) { // just remove edges
		edges = e.intersection(edges);
	}

	Hypergraph sectionHypergraph(std::unordered_set<Data*> v) { // remove vertices and edges containing those vertices
		vertices = vertices.intersection(v);
		std::unordered_set<Hyperedge> newEdges;
		for(auto edge : edges) {
    		//keys.push_back(kv.first);
    		if (edge.vertices.intersection(vertices).size() == 0) {
    			newEdges.insert(edge);
    		}
		}
		edges = newEdges;
	}

	Hypergraph<Weight, Data> dual() {

	}

protected: 
	std::unordered_set<Data*> vertices; 
	std::unordered_set<Hyperedge> edges;
};
