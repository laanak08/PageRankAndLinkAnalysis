#include <list>

using namespace std;

template <typename T>
class Vertex {
private:
	T label;
	list<T> * edges;
public:
	Vertex() : edges(new list<T>()) {};
	Vertex(T label) : label(label), edges(new list<T>()) {};
	Vertex(T label,int index) : label(label), edges(new list<T>()) { add_edge(index); };
	Vertex(const Vertex<T> &v) : label(v.label) { for(int i = 0; i < v.edges->size(); ++i) edges.push_back(v.edges->at(i)); };
	~Vertex(){ delete edges; };

	T get_label() const { return this->label; };
	bool set_label(T label){ this->label = label; return true; };
	bool add_edge(int index) { edges->push_back(index); return true; };
	int get_outdegree() { return edges->size(); };
	int get_indegree() { };
	bool operator<( const Vertex<T> &v) const { return (label < v.get_label()); };
	bool operator==( const Vertex<T> &v) const { return (label == v.get_label()); };
	Vertex<T>& operator=( const Vertex<T> &v) { label = v.label; for(int i = 0; i < v.edges->size(); ++i) edges->push_back(v.edges->at(i)); return *this; };
};
